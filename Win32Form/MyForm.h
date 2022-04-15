#pragma once

#include <msclr/marshal.h>
#include "Source.h"

DecoderParam decoderParam;

namespace Win32Form {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// MyForm 的摘要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO:  在此加入建構函式程式碼
			//
		}

	protected:
		/// <summary>
		/// 清除任何使用中的資源。
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Button^ button_play;
	private: System::Windows::Forms::GroupBox^ groupBox_video_file;
	private: System::Windows::Forms::RadioButton^ radioButton_file_2;


	private: System::Windows::Forms::RadioButton^ radioButton_file_1;

	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// 設計工具所需的變數。
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// 此為設計工具支援所需的方法 - 請勿使用程式碼編輯器修改
		/// 這個方法的內容。
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->groupBox_video_file = (gcnew System::Windows::Forms::GroupBox());
			this->radioButton_file_2 = (gcnew System::Windows::Forms::RadioButton());
			this->radioButton_file_1 = (gcnew System::Windows::Forms::RadioButton());
			this->button_play = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel1->SuspendLayout();
			this->groupBox_video_file->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Black;
			this->pictureBox1->Location = System::Drawing::Point(0, 70);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(240, 240);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::Control;
			this->panel1->Controls->Add(this->groupBox_video_file);
			this->panel1->Controls->Add(this->button_play);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(380, 70);
			this->panel1->TabIndex = 1;
			// 
			// groupBox_video_file
			// 
			this->groupBox_video_file->Controls->Add(this->radioButton_file_2);
			this->groupBox_video_file->Controls->Add(this->radioButton_file_1);
			this->groupBox_video_file->Location = System::Drawing::Point(122, 3);
			this->groupBox_video_file->Name = L"groupBox_video_file";
			this->groupBox_video_file->Size = System::Drawing::Size(175, 61);
			this->groupBox_video_file->TabIndex = 1;
			this->groupBox_video_file->TabStop = false;
			this->groupBox_video_file->Text = L"Video File";
			// 
			// radioButton_file_2
			// 
			this->radioButton_file_2->AutoSize = true;
			this->radioButton_file_2->Checked = true;
			this->radioButton_file_2->Location = System::Drawing::Point(7, 38);
			this->radioButton_file_2->Name = L"radioButton_file_2";
			this->radioButton_file_2->Size = System::Drawing::Size(119, 16);
			this->radioButton_file_2->TabIndex = 1;
			this->radioButton_file_2->TabStop = true;
			this->radioButton_file_2->Text = L"test_video.mjpeg.avi";
			this->radioButton_file_2->UseVisualStyleBackColor = true;
			// 
			// radioButton_file_1
			// 
			this->radioButton_file_1->AutoSize = true;
			this->radioButton_file_1->Location = System::Drawing::Point(7, 16);
			this->radioButton_file_1->Name = L"radioButton_file_1";
			this->radioButton_file_1->Size = System::Drawing::Size(121, 16);
			this->radioButton_file_1->TabIndex = 0;
			this->radioButton_file_1->Text = L"test_video.h264.mp4";
			this->radioButton_file_1->UseVisualStyleBackColor = true;
			// 
			// button_play
			// 
			this->button_play->Location = System::Drawing::Point(12, 12);
			this->button_play->Name = L"button_play";
			this->button_play->Size = System::Drawing::Size(87, 52);
			this->button_play->TabIndex = 0;
			this->button_play->Text = L"Play";
			this->button_play->UseVisualStyleBackColor = true;
			this->button_play->Click += gcnew System::EventHandler(this, &MyForm::button_play_Click);
			// 
			// timer1
			// 
			this->timer1->Interval = 16;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(380, 310);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->groupBox_video_file->ResumeLayout(false);
			this->groupBox_video_file->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	public:
		Bitmap^ vo_bmp1;
		Graphics^ vo_gra1;
		Pen^ vo_pen1;
		SolidBrush^ vo_brush;
		int encode_mode = 0;  // 0:h264(mp4)  1:mjpeg

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

		//AVFrame* firstframe = getFirstFrame("..\\test_video.mp4");
		AVFrame* frameOld = RequestFrame(decoderParam);

		if (frameOld != nullptr) {
			int width = frameOld->width;
			int height = frameOld->height;

			//// Create `pictureBox` image
			if (this->pictureBox1->Image == nullptr)
			{
				this->Width = this->Width + (width - this->panel1->Width);
				this->Height = this->Height + (height - this->pictureBox1->Height);
				this->pictureBox1->Width = width;
				this->pictureBox1->Height = height;
				vo_bmp1 = gcnew Bitmap(width, height);
				vo_gra1 = Graphics::FromImage(vo_bmp1);
				vo_gra1->Clear(Color::Black);
				this->pictureBox1->Image = vo_bmp1;
			}

			//// Get frame pixel data
			AVFrame* frame = GetRGBPixels(frameOld);  //TODO: 記憶體會膨脹=.=

			//// Lock the bitmap's bits.
			System::Drawing::Rectangle rect = System::Drawing::Rectangle(0, 0, vo_bmp1->Width, vo_bmp1->Height);
			System::Drawing::Imaging::BitmapData^ bmpData = vo_bmp1->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, vo_bmp1->PixelFormat);

			//// Get the address of the first line.
			IntPtr ptr = bmpData->Scan0;

			//// Declare an array to hold the bytes of the bitmap.
			int bytes = bmpData->Stride * vo_bmp1->Height;
			array<byte>^ destination = gcnew array<byte>(bytes);
			System::Runtime::InteropServices::Marshal::Copy(ptr, destination, 0, bytes);
			int nOffset = bmpData->Stride - bmpData->Width * 4;  //通道位移，正常為BGRA。確保後面loc獲得正確像素位置
			int pb = 0; int pg = 0; int pr = 0; int loc = 0; int off = 0;
			for (int j = 0; j < height; j++) {
				for (int i = 0; i < width; i++) {
					loc = i * 3 + j * frame->linesize[0];
					pr = frame->data[0][loc];
					pg = frame->data[0][loc + 1];
					pb = frame->data[0][loc + 2];

					loc = (i + j * width) * 4 + off;
					destination[loc + 0] = pb;
					destination[loc + 1] = pg;
					destination[loc + 2] = pr;
					destination[loc + 3] = 0xff;
				}
				off += nOffset;
			}

			//// Unlock the bits.
			System::Runtime::InteropServices::Marshal::Copy(destination, 0, ptr, bytes);
			vo_bmp1->UnlockBits(bmpData);
			this->pictureBox1->Image = vo_bmp1;
			this->pictureBox1->Refresh();
			destination->Clear;

			av_frame_free(&frame);
		}
		av_frame_free(&frameOld);
	}
	private: System::Void button_play_Click(System::Object^ sender, System::EventArgs^ e) {
		if (set_video_status == 0) {
			if (this->radioButton_file_1->Checked) {
				encode_mode = 0;
				InitDecoder("..\\test_video.h264.mp4", decoderParam);
			}
			if (this->radioButton_file_2->Checked) {
				encode_mode = 1;
				InitDecoder("..\\test_video.mjpeg.avi", decoderParam);
			}
			auto& width = decoderParam.width;
			auto& height = decoderParam.height;
			//auto& fmtCtx = decoderParam.fmtCtx;
			//auto& vcodecCtx = decoderParam.vcodecCtx;

			printf("Width:  %d\n", width);
			printf("Height: %d\n", height);
			printf("\n");

			this->timer1->Enabled = true;
		}
	}
};
}
