#pragma once

namespace ReadFile1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// testForm �̊T�v
	/// </summary>
	public ref class testForm : public System::Windows::Forms::Form
	{
	public:
		testForm(void)
		{
			InitializeComponent();
			//
			//TODO: �����ɃR���X�g���N�^�[ �R�[�h��ǉ����܂�
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
		/// �g�p���̃��\�[�X�����ׂăN���[���A�b�v���܂��B
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
		/// �K�v�ȃf�U�C�i�[�ϐ��ł��B
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// �f�U�C�i�[ �T�|�[�g�ɕK�v�ȃ��\�b�h�ł��B���̃��\�b�h�̓��e��
		/// �R�[�h �G�f�B�^�[�ŕύX���Ȃ��ł��������B
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
