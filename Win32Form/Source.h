#pragma once

extern "C" {
#include <libavcodec/avcodec.h>
#pragma comment(lib, "avcodec.lib")

#include <libavformat/avformat.h>
#pragma comment(lib, "avformat.lib")

#include <libavutil/imgutils.h>
#pragma comment(lib, "avutil.lib")

#include <libswscale/swscale.h>
#pragma comment(lib, "swscale.lib")
}

struct DecoderParam
{
	AVFormatContext* fmtCtx;
	AVCodecContext* vcodecCtx;
	int width;
	int height;
	int videoStreamIndex;
};

extern int set_video_status;

AVFrame* getFirstFrame(const char* filePath);
void InitDecoder(const char* filePath, DecoderParam& param);
AVFrame* RequestFrame(DecoderParam& param);
void GetRGBPixels(AVFrame* src_frame, AVFrame* dst_frame, uint8_t* buf, DecoderParam& param);