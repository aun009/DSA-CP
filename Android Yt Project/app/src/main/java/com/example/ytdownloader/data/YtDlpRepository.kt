package com.example.ytdownloader.data

import android.os.Environment
import com.yausername.youtubedl_android.YoutubeDL
import com.yausername.youtubedl_android.YoutubeDLRequest
import com.yausername.youtubedl_android.mapper.VideoInfo
import kotlinx.coroutines.Dispatchers
import kotlinx.coroutines.channels.awaitClose
import kotlinx.coroutines.flow.Flow
import kotlinx.coroutines.flow.callbackFlow
import kotlinx.coroutines.flow.flowOn
import kotlinx.coroutines.withContext
import java.io.File

class YtDlpRepository {

    suspend fun getVideoInfo(url: String): Result<VideoInfo> = withContext(Dispatchers.IO) {
        try {
            val request = YoutubeDLRequest(url)
            request.addOption("--no-playlist")
            val info = YoutubeDL.getInstance().getInfo(request)
            Result.success(info)
        } catch (e: Exception) {
            Result.failure(e)
        }
    }

    fun startDownload(url: String, formatId: String?, title: String): Flow<Float> = callbackFlow {
        val downloadDir = File(
            Environment.getExternalStoragePublicDirectory(Environment.DIRECTORY_DOWNLOADS),
            "YtDownloader"
        )
        if (!downloadDir.exists()) downloadDir.mkdirs()

        val cleanTitle = title.replace("[^a-zA-Z0-9.-]".toRegex(), "_")
        val request = YoutubeDLRequest(url)
        request.addOption("-o", "${downloadDir.absolutePath}/$cleanTitle.%(ext)s")
        if (formatId != null) {
            request.addOption("-f", formatId)
        }
        
        // Add ffmpeg location if needed, though library usually handles it if init correctly
        
        val disposable = YoutubeDL.getInstance().execute(request, callback = { progress, _ ->
            trySend(progress)
        })

        awaitClose {
            // Cancellation logic if supported by library (Process killer)
            // YoutubeDL.getInstance().destroyProcessById(processId) - simplistic view
        }
    }.flowOn(Dispatchers.IO)
}
