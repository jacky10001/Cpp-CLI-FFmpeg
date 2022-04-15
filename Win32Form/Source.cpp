
#include "Source.h"

int set_video_status = 0;

AVFrame* getFirstFrame(const char* filePath) {
	AVFormatContext* fmtCtx = nullptr;
	avformat_open_input(&fmtCtx, filePath, NULL, NULL);
	avformat_find_stream_info(fmtCtx, NULL);

	int videoStreamIndex;
	AVCodecContext* vcodecCtx = nullptr;
	for (int i = 0; i < fmtCtx->nb_streams; i++) {
		AVStream* stream = fmtCtx->streams[i];
		if (stream->codecpar->codec_type == AVMEDIA_TYPE_VIDEO) {
			const AVCodec* codec = avcodec_find_decoder(stream->codecpar->codec_id);
			videoStreamIndex = i;
			vcodecCtx = avcodec_alloc_context3(codec);
			avcodec_parameters_to_context(vcodecCtx, fmtCtx->streams[i]->codecpar);
			avcodec_open2(vcodecCtx, codec, NULL);
		}
	}

	while (1) {
		AVPacket* packet = av_packet_alloc();
		int ret = av_read_frame(fmtCtx, packet);
		if (ret == 0 && packet->stream_index == videoStreamIndex) {
			ret = avcodec_send_packet(vcodecCtx, packet);
			if (ret == 0) {
				AVFrame* frame = av_frame_alloc();
				ret = avcodec_receive_frame(vcodecCtx, frame);
				if (ret == 0) {
					av_packet_unref(packet);
					avcodec_free_context(&vcodecCtx);
					avformat_close_input(&fmtCtx);
					return frame;
				}
				else if (ret == AVERROR(EAGAIN)) {
					av_frame_unref(frame);
					continue;
				}
			}
		}

		av_packet_unref(packet);
	}
}

void InitDecoder(const char* filePath, DecoderParam& param) {
	AVFormatContext* fmtCtx = nullptr;
	avformat_open_input(&fmtCtx, filePath, NULL, NULL);
	avformat_find_stream_info(fmtCtx, NULL);

	AVCodecContext* vcodecCtx = nullptr;
	for (int i = 0; i < fmtCtx->nb_streams; i++) {
		const AVCodec* codec = avcodec_find_decoder(fmtCtx->streams[i]->codecpar->codec_id);
		if (codec->type == AVMEDIA_TYPE_VIDEO) {
			param.videoStreamIndex = i;
			vcodecCtx = avcodec_alloc_context3(codec);
			avcodec_parameters_to_context(vcodecCtx, fmtCtx->streams[i]->codecpar);
			avcodec_open2(vcodecCtx, codec, NULL);
		}
	}

	param.fmtCtx = fmtCtx;
	param.vcodecCtx = vcodecCtx;
	param.width = vcodecCtx->width;
	param.height = vcodecCtx->height;
}

AVFrame* RequestFrame(DecoderParam& param) {
	auto& fmtCtx = param.fmtCtx;
	auto& vcodecCtx = param.vcodecCtx;
	auto& videoStreamIndex = param.videoStreamIndex;

	while (1) {
		AVPacket* packet = av_packet_alloc();
		int ret = av_read_frame(fmtCtx, packet);
		if (ret == 0 && packet->stream_index == videoStreamIndex) {
			ret = avcodec_send_packet(vcodecCtx, packet);
			if (ret == 0) {
				AVFrame* frame = av_frame_alloc();
				ret = avcodec_receive_frame(vcodecCtx, frame);
				if (ret == 0) {
					av_packet_unref(packet);
					return frame;
				}
				else if (ret == AVERROR(EAGAIN)) {
					av_frame_unref(frame);
				}
			}
			set_video_status = 1;
		}
		else {
			set_video_status = 0;
			return nullptr;
		}

		av_packet_unref(packet);
	}

	return nullptr;
}


AVFrame* GetRGBPixels(AVFrame* frame) {
	static SwsContext* swsctx = nullptr;
	swsctx = sws_getCachedContext(
		swsctx,
		frame->width, frame->height, AVPixelFormat::AV_PIX_FMT_YUV420P,
		frame->width, frame->height, AVPixelFormat::AV_PIX_FMT_RGB24, NULL, NULL, NULL, NULL);

	int bufSize = av_image_get_buffer_size(AV_PIX_FMT_RGB24, frame->width, frame->height, 1);
	uint8_t* buf = (uint8_t*)av_malloc(bufSize);
	AVFrame* RGB24Frame = av_frame_alloc();
	av_image_fill_arrays(
		RGB24Frame->data, RGB24Frame->linesize, buf,
		AV_PIX_FMT_RGB24, frame->width, frame->height,
		1
	);

	sws_scale(swsctx, frame->data, frame->linesize, 0, frame->height, RGB24Frame->data, RGB24Frame->linesize);
	return RGB24Frame;
}