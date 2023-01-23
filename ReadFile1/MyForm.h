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
	/// MyForm の概要
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: ここにコンストラクター コードを追加します
			//
		}

	protected:
		/// <summary>
		/// 使用中のリソースをすべてクリーンアップします。
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
		//リストとしてファイルパス取得
		array<String^>^ file = (array<String^>^)e->Data->GetData(DataFormats::FileDrop, false);
		//拡張子取得
		String^	extension = System::IO::Path::GetExtension(file[0]);
		//ファイル名取得
		String^ title = System::IO::Path::GetFileName(file[0]);
		//ディレクトリ名取得
		String^ directory = System::IO::Path::GetDirectoryName(file[0]);
		//interopの宣言
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
				//Excelブックの表示はしない
				app_->Visible = false;
				//ファイルパスからブックを開く
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
				//一枚目のワークシートを開く
				worksheet = (Microsoft::Office::Interop::Excel::Worksheet^)workbook->Worksheets[1];
				
				allcells = (Microsoft::Office::Interop::Excel::Range^)worksheet->Cells;
				//worksheet->Cells[1,1]の記述にはworksheet->Cells(全セル)と[1,1]の両方のrangeを含むので、allcells変数を作成し、後で解放する必要がある
				workcells = (Microsoft::Office::Interop::Excel::Range^)worksheet->Cells[1, 1];
				//検索するワード
				String^ key = "sample";
				//Findという検索メソッドを使用
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
				//隣のセルにrangeを移す
				workcells = (Microsoft::Office::Interop::Excel::Range^)worksheet->Cells[samRange->Row, samRange->Column+1];
				//該当セルが結合セルかどうかの判定
				if (workcells->MergeCells) {
					//結合されている範囲をrangeとして取得
					workcells=workcells->MergeArea;
					//結合されているセルの先頭セルをrangeとして取得。テキストなどを取得できる
					workcells = (Microsoft::Office::Interop::Excel::Range^)workcells->Cells[1, 1];
					MessageBox::Show("結合セルです:"+workcells->Text->ToString());
				}
				
			}
			catch (Exception^ e) {
				MessageBox::Show(e->ToString());
			}
			finally{
				//COM解放
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
