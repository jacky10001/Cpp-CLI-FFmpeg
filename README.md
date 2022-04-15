# Cpp-CLI-FFmpeg
 
[https://github.com/jacky10001/FFmpeg-Builds-Win32](https://github.com/jacky10001/FFmpeg-Builds-Win32)

[https://iter01.com/597880.html](https://iter01.com/597880.html)

[https://filesamples.com/formats/mjpeg](https://filesamples.com/formats/mjpeg)

[https://test-videos.co.uk/bigbuckbunny/mp4-h264](https://test-videos.co.uk/bigbuckbunny/mp4-h264)

[https://segmentfault.com/a/1190000023263016](https://segmentfault.com/a/1190000023263016)

## FFmpeg command

- Convert MP4 to MJPEG

```
ffmpeg -i test_video.mp4 -c:v mjpeg -q:v 1 -an test_video.mjpeg
```