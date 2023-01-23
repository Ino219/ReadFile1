#pragma once


namespace ReadFile1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace Microsoft::Office::Core;
	using namespace Microsoft::Office::Interop::Excel;

	using namespace System::IO;
	

	/// <summary>
	/// MyForm �̊T�v
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: �����ɃR���X�g���N�^�[ �R�[�h��ǉ����܂�
			//
		}

	protected:
		/// <summary>
		/// �g�p���̃��\�[�X�����ׂăN���[���A�b�v���܂��B
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^  textBox1;
	protected:

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->AllowDrop = true;
			this->textBox1->Location = System::Drawing::Point(32, 32);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(212, 40);
			this->textBox1->TabIndex = 0;
			this->textBox1->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &MyForm::textBox1_DragDrop);
			this->textBox1->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &MyForm::textBox1_DragEnter);
			// 
			// MyForm
			// 
			this->AllowDrop = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->textBox1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_DragDrop(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e) {
		//���X�g�Ƃ��ăt�@�C���p�X�擾
		array<String^>^ file = (array<String^>^)e->Data->GetData(DataFormats::FileDrop, false);
		//�g���q�擾
		String^	extension = System::IO::Path::GetExtension(file[0]);
		//�t�@�C�����擾
		String^ title = System::IO::Path::GetFileName(file[0]);
		//�f�B���N�g�����擾
		String^ directory = System::IO::Path::GetDirectoryName(file[0]);
		//interop�̐錾
		Microsoft::Office::Interop::Excel::Application^ app_=nullptr;
		Microsoft::Office::Interop::Excel::Workbook^ workbook=nullptr;
		Microsoft::Office::Interop::Excel::Worksheet^ worksheet=nullptr;
		Microsoft::Office::Interop::Excel::Range^ samRange=nullptr;
		Microsoft::Office::Interop::Excel::Range^ workcells=nullptr;
		Microsoft::Office::Interop::Excel::Range^ allcells=nullptr;
		//MessageBox::Show(file[0]);
		//MessageBox::Show(title);
		//MessageBox::Show(extension);
		//MessageBox::Show(directory);
		if (extension == ".xlsx", "xls", "xlw") {
			try {
				app_ = gcnew Microsoft::Office::Interop::Excel::ApplicationClass();
				//Excel�u�b�N�̕\���͂��Ȃ�
				app_->Visible = false;
				//�t�@�C���p�X����u�b�N���J��
				workbook = (Microsoft::Office::Interop::Excel::Workbook^)(app_->Workbooks->Open(
					file[0],
					Type::Missing,
					Type::Missing,
					Type::Missing,
					Type::Missing,
					Type::Missing,
					Type::Missing,
					Type::Missing,
					Type::Missing,
					Type::Missing,
					Type::Missing,
					Type::Missing,
					Type::Missing,
					Type::Missing,
					Type::Missing));
				//�ꖇ�ڂ̃��[�N�V�[�g���J��
				worksheet = (Microsoft::Office::Interop::Excel::Worksheet^)workbook->Worksheets[1];
				
				allcells = (Microsoft::Office::Interop::Excel::Range^)worksheet->Cells;
				//worksheet->Cells[1,1]�̋L�q�ɂ�worksheet->Cells(�S�Z��)��[1,1]�̗�����range���܂ނ̂ŁAallcells�ϐ����쐬���A��ŉ������K�v������
				workcells = (Microsoft::Office::Interop::Excel::Range^)worksheet->Cells[1, 1];
				//�������郏�[�h
				String^ key = "sample";
				//Find�Ƃ����������\�b�h���g�p
				samRange = workcells->Find(
					key,
					Type::Missing,
					Microsoft::Office::Interop::Excel::XlFindLookIn::xlValues,
					Microsoft::Office::Interop::Excel::XlLookAt::xlPart,
					Microsoft::Office::Interop::Excel::XlSearchOrder::xlByRows,
					Microsoft::Office::Interop::Excel::XlSearchDirection::xlNext,
					false,
					Type::Missing,
					Type::Missing
				);
				//�ׂ̃Z����range���ڂ�
				workcells = (Microsoft::Office::Interop::Excel::Range^)worksheet->Cells[samRange->Row, samRange->Column+1];
				//�Y���Z���������Z�����ǂ����̔���
				if (workcells->MergeCells) {
					//��������Ă���͈͂�range�Ƃ��Ď擾
					workcells=workcells->MergeArea;
					//��������Ă���Z���̐擪�Z����range�Ƃ��Ď擾�B�e�L�X�g�Ȃǂ��擾�ł���
					workcells = (Microsoft::Office::Interop::Excel::Range^)workcells->Cells[1, 1];
					MessageBox::Show("�����Z���ł�:"+workcells->Text->ToString());
				}
				
			}
			catch (Exception^ e) {
				MessageBox::Show(e->ToString());
			}
			finally{
				//COM���
				app_->Workbooks->Close();

				System::Runtime::InteropServices::Marshal::ReleaseComObject(samRange);;
				System::Runtime::InteropServices::Marshal::ReleaseComObject(workcells);
				System::Runtime::InteropServices::Marshal::ReleaseComObject(allcells);
				System::Runtime::InteropServices::Marshal::ReleaseComObject(worksheet);
				System::Runtime::InteropServices::Marshal::ReleaseComObject(workbook);
				System::Runtime::InteropServices::Marshal::ReleaseComObject(app_);
			}
		}
		
	}
	private: System::Void textBox1_DragEnter(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e) {
		if (e->Data->GetDataPresent(DataFormats::FileDrop)) {
			e->Effect = DragDropEffects::All;
		}
		else {
			e->Effect = DragDropEffects::None;
		}
	}
	};
}
