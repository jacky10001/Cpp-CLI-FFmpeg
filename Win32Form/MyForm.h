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
			this->button_play = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel1->SuspendLayout();
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
			this->panel1->BackColor = System::Drawing::SystemColors::ButtonShadow;
			this->panel1->Controls->Add(this->button_play);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(240, 70);
			this->panel1->TabIndex = 1;
			// 
			// button_play
			// 
			this->button_play->Location = System::Drawing::Point(12, 24);
			this->button_play->Name = L"button_play";
			this->button_play->Size = System::Drawing::Size(75, 23);
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
			this->ClientSize = System::Drawing::Size(240, 310);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	public:
		Bitmap^ vo_bmp1;
		Graphics^ vo_gra1;
		Pen^ vo_pen1;
		SolidBrush^ vo_brush;

	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {

		//AVFrame* firstframe = getFirstFrame("..\\test_video.mp4");
		AVFrame* frame = RequestFrame(decoderParam);

		if (frame != nullptr) {
			std::vector<Color_RGB> pixels = GetRGBPixels(frame);

			int width = frame->width;
			int height = frame->height;

			if (this->pictureBox1->Image == nullptr)
			{
				this->pictureBox1->Width = width;
				this->pictureBox1->Height = height;
				vo_bmp1 = gcnew Bitmap(width, height);
				vo_gra1 = Graphics::FromImage(vo_bmp1);
				vo_gra1->Clear(Color::Black);
				this->pictureBox1->Image = vo_bmp1;
			}

			// Lock the bitmap's bits.
			System::Drawing::Rectangle rect = System::Drawing::Rectangle(0, 0, vo_bmp1->Width, vo_bmp1->Height);
			System::Drawing::Imaging::BitmapData^ bmpData = vo_bmp1->LockBits(rect, System::Drawing::Imaging::ImageLockMode::ReadWrite, vo_bmp1->PixelFormat);

			// Get the address of the first line.
			IntPtr ptr = bmpData->Scan0;

			// Declare an array to hold the bytes of the bitmap.
			int bytes = bmpData->Stride * vo_bmp1->Height;
			array<byte>^ destination = gcnew array<byte>(bytes);
			System::Runtime::InteropServices::Marshal::Copy(ptr, destination, 0, bytes);
			int nOffset = bmpData->Stride - bmpData->Width * 4;  //通道位移，正常為BGRA。確保後面loc獲得正確像素位置
			int pb = 0; int pg = 0; int pr = 0; int loc = 0; int off = 0;
			unsigned int ut1;
			for (int j = 0; j < 240; j++) {
				for (int i = 0; i < 240; i++) {
					loc = (i + j * width) * 4 + off;

					//ut1 = frame->data[0][i + j * width];
					//pr = ut1;
					//pg = ut1;
					//pb = ut1;

					pr = pixels[i + j * width].r;
					pg = pixels[i + j * width].g;
					pb = pixels[i + j * width].b;

					destination[loc + 0] = pr;
					destination[loc + 1] = pg;
					destination[loc + 2] = pb;
					//if (pr == 0 && pg == 0 && pb == 0) destination[loc + 3] = 0x0;
					if (pr == 0xff && pg == 0xff && pb == 0xff) destination[loc + 3] = 0x0;
					else destination[loc + 3] = 0xff;
				}
				off += nOffset;
			}

			System::Runtime::InteropServices::Marshal::Copy(destination, 0, ptr, bytes);
			// Unlock the bits.
			vo_bmp1->UnlockBits(bmpData);
			this->pictureBox1->Image = vo_bmp1;
			this->pictureBox1->Refresh();
			destination->Clear;

			av_frame_free(&frame);
		}

		if (set_video_status == 0) {
			vo_bmp1 = gcnew Bitmap(this->pictureBox1->Width, this->pictureBox1->Height);
			vo_gra1 = Graphics::FromImage(vo_bmp1);
			vo_gra1->Clear(Color::Black);
			this->pictureBox1->Image = vo_bmp1;
		}
	}
	private: System::Void button_play_Click(System::Object^ sender, System::EventArgs^ e) {
		if (set_video_status == 0) {
			InitDecoder("..\\test_video.mp4", decoderParam);
			//InitDecoder("..\\test_video2.mjpeg", decoderParam);
			auto& width = decoderParam.width;
			auto& height = decoderParam.height;
			auto& fmtCtx = decoderParam.fmtCtx;
			auto& vcodecCtx = decoderParam.vcodecCtx;

			printf("Width:  %d\n", width);
			printf("Height: %d\n", height);
			printf("\n");

			this->timer1->Enabled = true;
		}
	}
};
}
