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

#include <vector>

struct Color_RGB
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
};

struct DecoderParam
{
	AVFormatContext* fmtCtx;
	AVCodecContext* vcodecCtx;
	int width;
	int height;
	int videoStreamIndex;
};

AVFrame* getFirstFrame(const char* filePath);
void InitDecoder(const char* filePath, DecoderParam& param);
AVFrame* RequestFrame(DecoderParam& param);

std::vector<Color_RGB> GetRGBPixels(AVFrame* frame);

extern int set_video_status;