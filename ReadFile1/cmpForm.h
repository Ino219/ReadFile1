#pragma once

namespace ReadFile1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// cmpForm �̊T�v
	/// </summary>
	public ref class cmpForm : public System::Windows::Forms::Form
	{
	private:
		cmpForm(void)
		{
			InitializeComponent();
			//
			//TODO: �����ɃR���X�g���N�^�[ �R�[�h��ǉ����܂�
			//
		}
	public:
		cmpForm(System::Collections::Generic::List<System::Collections::Generic::List<String^>^>^ list) 
		{
			InitializeComponent();
			dList = gcnew System::Collections::Generic::List<System::Collections::Generic::List<String^>^>;
			dList = list;
		}

	protected:
		/// <summary>
		/// �g�p���̃��\�[�X�����ׂăN���[���A�b�v���܂��B
		/// </summary>
		~cmpForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^  cmpDGV;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  xValue;
	protected:

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
			this->cmpDGV = (gcnew System::Windows::Forms::DataGridView());
			this->name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->xValue = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cmpDGV))->BeginInit();
			this->SuspendLayout();
			// 
			// cmpDGV
			// 
			this->cmpDGV->AllowUserToAddRows = false;
			this->cmpDGV->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->cmpDGV->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) { this->name, this->xValue });
			this->cmpDGV->Location = System::Drawing::Point(23, 30);
			this->cmpDGV->Name = L"cmpDGV";
			this->cmpDGV->RowTemplate->Height = 21;
			this->cmpDGV->Size = System::Drawing::Size(240, 150);
			this->cmpDGV->TabIndex = 0;
			// 
			// name
			// 
			this->name->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->name->HeaderText = L"name";
			this->name->Name = L"name";
			// 
			// xValue
			// 
			this->xValue->HeaderText = L"xValue";
			this->xValue->Name = L"xValue";
			// 
			// cmpForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->cmpDGV);
			this->Name = L"cmpForm";
			this->Text = L"cmpForm";
			this->Load += gcnew System::EventHandler(this, &cmpForm::cmpForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->cmpDGV))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private:
		System::Collections::Generic::List<System::Collections::Generic::List<String^>^>^ dList;
	private: System::Void cmpForm_Load(System::Object^  sender, System::EventArgs^  e) {
		System::Collections::Generic::List<String^>^ temp = dList[0];
		for (int n = 0; n < temp->Count; n++) {
			cmpDGV->Rows->Add(1);
			MessageBox::Show("::" + cmpDGV->RowCount);
			for (int i = 0; i < dList->Count; i++) {
				System::Collections::Generic::List<String^>^ temp1 = dList[i];
				cmpDGV->Rows[n]->Cells[i]->Value = temp1[n];
			}
		}
	}
	};
}
