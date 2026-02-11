package com.example.ytdownloader

import android.app.Application
import android.util.Log
import android.widget.Toast
import com.yausername.youtubedl_android.YoutubeDL
import com.yausername.youtubedl_android.YoutubeDLException

class YtApp : Application() {
    override fun onCreate() {
        super.onCreate()
        try {
            YoutubeDL.getInstance().init(this)
            YoutubeDL.getInstance().updateYoutubeDL(this, YoutubeDL.UpdateChannel.STABLE)
        } catch (e: YoutubeDLException) {
            Log.e("YtApp", "failed to initialize youtubedl-android", e)
            Toast.makeText(this, "Failed to init yt-dlp", Toast.LENGTH_LONG).show()
        }
    }
}
