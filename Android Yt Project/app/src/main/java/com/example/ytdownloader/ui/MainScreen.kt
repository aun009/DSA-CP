package com.example.ytdownloader.ui

import android.widget.Toast
import androidx.compose.foundation.Image
import androidx.compose.foundation.layout.*
import androidx.compose.foundation.lazy.LazyColumn
import androidx.compose.foundation.lazy.items
import androidx.compose.material3.*
import androidx.compose.runtime.*
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.platform.LocalContext
import androidx.compose.ui.unit.dp
import coil.compose.rememberAsyncImagePainter
import com.example.ytdownloader.data.YtDlpRepository
import com.yausername.youtubedl_android.mapper.VideoFormat
import com.yausername.youtubedl_android.mapper.VideoInfo
import kotlinx.coroutines.launch

@Composable
fun MainScreen() {
    val context = LocalContext.current
    val scope = rememberCoroutineScope()
    val repository = remember { YtDlpRepository() }

    var url by remember { mutableStateOf("") }
    var isLoading by remember { mutableStateOf(false) }
    var videoInfo by remember { mutableStateOf<VideoInfo?>(null) }
    var downloadProgress by remember { mutableFloatStateOf(0f) }
    var isDownloading by remember { mutableStateOf(false) }

    Column(
        modifier = Modifier
            .fillMaxSize()
            .padding(16.dp),
        horizontalAlignment = Alignment.CenterHorizontally
    ) {
        TextField(
            value = url,
            onValueChange = { url = it },
            label = { Text("YouTube URL") },
            modifier = Modifier.fillMaxWidth()
        )
        Spacer(modifier = Modifier.height(8.dp))
        Button(
            onClick = {
                if (url.isNotBlank()) {
                    isLoading = true
                    scope.launch {
                        val result = repository.getVideoInfo(url)
                        isLoading = false
                        result.onSuccess { info ->
                            videoInfo = info
                        }.onFailure { e ->
                            Toast.makeText(context, "Error: ${e.message}", Toast.LENGTH_LONG).show()
                        }
                    }
                }
            },
            enabled = !isLoading && !isDownloading
        ) {
            Text("Get Info")
        }

        if (isLoading) {
            LinearProgressIndicator(modifier = Modifier.fillMaxWidth().padding(top = 16.dp))
        }

        if (isDownloading) {
            Spacer(modifier = Modifier.height(16.dp))
            Text("Downloading: ${"%.1f".format(downloadProgress)}%")
            LinearProgressIndicator(
                progress = { downloadProgress / 100f },
                modifier = Modifier.fillMaxWidth()
            )
        }

        videoInfo?.let { info ->
            Spacer(modifier = Modifier.height(16.dp))
            Text(text = info.title ?: "Unknown Title", style = MaterialTheme.typography.titleMedium)
            
            info.thumbnail?.let { thumb ->
                Image(
                    painter = rememberAsyncImagePainter(thumb),
                    contentDescription = null,
                    modifier = Modifier
                        .height(200.dp)
                        .fillMaxWidth()
                )
            }

            Spacer(modifier = Modifier.height(8.dp))
            Text("Formats:", style = MaterialTheme.typography.titleSmall)
            
            LazyColumn {
                val formats = info.formats ?: emptyList()
                // Simple filter to show distinct resolutions or audio
                val meaningfulFormats = formats.distinctBy { it.formatNote ?: it.formatId }
                
                items(meaningfulFormats) { format ->
                    FormatItem(format) {
                        isDownloading = true
                        downloadProgress = 0f
                        scope.launch {
                            repository.startDownload(url, format.formatId, info.title ?: "video")
                                .collect { progress ->
                                    downloadProgress = progress
                                    if (progress >= 100f) {
                                        isDownloading = false
                                        Toast.makeText(context, "Download Complete", Toast.LENGTH_SHORT).show()
                                    }
                                }
                        }
                    }
                }
            }
        }
    }
}

@Composable
fun FormatItem(format: VideoFormat, onDownload: () -> Unit) {
    Card(
        modifier = Modifier
            .fillMaxWidth()
            .padding(vertical = 4.dp),
        onClick = onDownload
    ) {
        Row(
            modifier = Modifier.padding(16.dp),
            horizontalArrangement = Arrangement.SpaceBetween,
            verticalAlignment = Alignment.CenterVertically
        ) {
            Column {
                Text(text = format.formatNote ?: format.ext ?: "Unknown")
                Text(text = "${format.ext} - ${format.fileSizeApprox ?: "Unknown size"}", style = MaterialTheme.typography.bodySmall)
            }
            Icon(imageVector = androidx.compose.material.icons.Icons.Default.ArrowDropDown, contentDescription = "Download")
        }
    }
}
