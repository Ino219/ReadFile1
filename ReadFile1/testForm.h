#pragma once

namespace ReadFile1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// testForm の概要
	/// </summary>
	public ref class testForm : public System::Windows::Forms::Form
	{
	public:
		testForm(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクター コードを追加します
			//
			f = 10;
			s = 20;
		}
	public:
		testForm(int first, int second)
		{
			InitializeComponent();
			f = first;
			s = second;
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
		/// </summary>
		~testForm()
		{
			if (components)
			{
				delete components;
			}
		}

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
			this->SuspendLayout();
			// 
			// testForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Name = L"testForm";
			this->Text = L"testForm";
			this->Load += gcnew System::EventHandler(this, &testForm::testForm_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private:
		int f;
		int s;
	private: System::Void testForm_Load(System::Object^  sender, System::EventArgs^  e) {
		MessageBox::Show(f.ToString() + ":" + s.ToString());
	}
	};
}
