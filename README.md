# Cpp-CLI-FFmpeg

這是參考這篇[文章](https://iter01.com/597880.html)的前半段所完成的小項目  
差異在於 UI 顯示不是用 Win32 API 而是用 CLR WinForm 所完成；FFmpeg 有 x86、x64 兩個版本

- [FFmpeg-Builds-Win32](https://github.com/sudo-nautilus/FFmpeg-Builds-Win32/releases)
- [FFmpeg-Builds-Win64](https://github.com/BtbN/FFmpeg-Builds/releases)

## 從網路上找的測試影片

- [mp4-h264](https://test-videos.co.uk/bigbuckbunny/mp4-h264)
- [mjpeg](https://filesamples.com/formats/mjpeg)

## 出現 deprecated pixel format used, make sure you did set range correctly  
主要是因為顏色轉換時，範圍不相同導致，其實可以忽略，可以參考[這裡](https://segmentfault.com/a/1190000023263016)  
H264、MJPEG 轉成 RGB 程式範例可以參考[這裡](https://superuser.com/questions/1273920/deprecated-pixel-format-used-make-sure-you-did-set-range-correctly)

## FFmpeg command

- Convert MP4 to MJPEG

```
ffmpeg -i test_video.mp4 -c:v mjpeg -q:v 1 -an test_video.mjpeg
```
