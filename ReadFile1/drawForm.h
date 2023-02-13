#pragma once

namespace ReadFile1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// drawForm の概要
	/// </summary>
	public ref class drawForm : public System::Windows::Forms::Form
	{
	public:
		drawForm(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクター コードを追加します
			//
			bmp = gcnew Bitmap(pictureBox1->Width, pictureBox1->Height);
			pictureBox1->Image = bmp;
			gr = Graphics::FromImage(pictureBox1->Image);
			//枠線の色と太さを指定
			pn = gcnew Pen(Color::Black, 1);
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~drawForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	protected:

	private:
		/// <summary>
		/// 必要なデザイナー変数です。
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// デザイナー サポートに必要なメソッドです。このメソッドの内容を
		/// コード エディターで変更しないでください。
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(13, 13);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(259, 236);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// drawForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"drawForm";
			this->Text = L"drawForm";
			this->Load += gcnew System::EventHandler(this, &drawForm::drawForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private:
		Bitmap^ bmp;
		Graphics^ gr;
		Pen^ pn;
	private: System::Void drawForm_Load(System::Object^  sender, System::EventArgs^  e) {
		gr->DrawEllipse(pn, 150, 150, 60, 60);
		//System::Drawing::Point^ pt1 = gcnew System::Drawing::Point(150,150);
		//System::Drawing::Point^ pt2 = gcnew System::Drawing::Point(180, 150);
		gr->DrawLine(pn, 180, 180, 150, 180);
		//センターの座標は180,180で半径30
		double sam1=180 - (30*(Math::Sin(45)));//円弧上の座標取得
		double sam2 = 180 - (30*(Math::Cos(45)));//円弧上の座標取得
		//MessageBox::Show(sam1.ToString());
		//gr->DrawLine(pn, 180, 180, sam1, sam2);//円の中心から円弧へのライン
		//sam1,2が矢印の終着点
		gr->DrawLine(pn, sam1, sam2, float(sam1-30), float(sam2-30));//円弧上のポイントから斜めのライン
		gr->DrawLine(pn, float(sam1 - 30), float(sam2 - 30), float(sam1 - 45), float(sam2 - 30));//上記のラインから折れ線
		System::Drawing::Font^ drawFont = gcnew System::Drawing::Font("Arial", 14);
		SolidBrush^ drawBrush = gcnew SolidBrush(Color::Black);
		//記号表示
		gr->DrawString("A", drawFont, drawBrush, float(sam1 - 45), float(sam2 - 50));


		pictureBox1->Image = bmp;
	}
	};
}
