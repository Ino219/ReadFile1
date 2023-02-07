#include "PictureForm.h"

System::Void ReadFile1::PictureForm::PictureForm_Load(System::Object ^ sender, System::EventArgs ^ e)
{
	this->MouseWheel += gcnew MouseEventHandler(this, &PictureForm::Picture_MouseWheel);
	//倍率定義
	magni = 1.00;

	filePath = "C:\\Users\\chach\\Desktop\\56.jpg";
	
	pictureBox1->Image = Image::FromFile(filePath);
	bitmap = gcnew Bitmap(pictureBox1->Image,pictureBox1->Width,pictureBox1->Height);
	pictureBox1->Image = bitmap;

	
	//pictureBox1->ImageLocation = filePath;
	//pictureBox1->SizeMode = PictureBoxSizeMode::StretchImage;
	//pictureBox1->Image = Image::FromFile(filePath);
	
}
System::Void ReadFile1::PictureForm::Picture_MouseWheel(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
{
	//スクロール行数の取得
	int movement = e->Delta;

	if (movement > 0) {
		magni *= 1.05;
	}
	else {
		magni *= 0.95;
	}

	pictureBox1->Image = Image::FromFile(filePath);
	bitmap = gcnew Bitmap(pictureBox1->Image, pictureBox1->Width*magni, pictureBox1->Height*magni);
	pictureBox1->Image = bitmap;
}

System::Void ReadFile1::PictureForm::pictureBox1_MouseEnter(System::Object ^ sender, System::EventArgs ^ e)
{
	//this->pictureBox1->Select();
	//this->pictureBox1->Focus();

	//this->MouseWheel += gcnew MouseEventHandler(this, &PictureForm::Picture_MouseWheel);
}
