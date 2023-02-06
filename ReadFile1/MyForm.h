#pragma once
#include "cmpForm.h"
#include <string>
#include <regex>
#include <msclr/marshal_cppstd.h>

namespace ReadFile1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace Microsoft::Office::Core;
	using namespace Microsoft::Office::Interop::Excel;
	using namespace Microsoft::Office::Interop::PowerPoint;

	using namespace System::IO;
	using namespace System::IO::Compression;
	using namespace System::Xml;

	using namespace System::Threading;

	using namespace System::Threading::Tasks;

	using namespace System::Text::RegularExpressions;

	using namespace System::Collections::Generic;

	using namespace System::Diagnostics;


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
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button6;
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
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
			// button1
			// 
			this->button1->Location = System::Drawing::Point(32, 94);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"正規表現";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(32, 123);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"PowerPoint";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(32, 152);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 3;
			this->button3->Text = L"フォルダ管理";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(32, 181);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 4;
			this->button4->Text = L"Zip解凍";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(32, 210);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(75, 23);
			this->button5->TabIndex = 5;
			this->button5->Text = L"Xml";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(140, 94);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(75, 23);
			this->button6->TabIndex = 6;
			this->button6->Text = L"スレッド";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// MyForm
			// 
			this->AllowDrop = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 261);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
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

		//interopの初期化宣言
		Microsoft::Office::Interop::Excel::Application^ app_ = nullptr;
		Microsoft::Office::Interop::Excel::Workbook^ workbook = nullptr;
		Microsoft::Office::Interop::Excel::Worksheet^ worksheet = nullptr;
		Microsoft::Office::Interop::Excel::Range^ samRange = nullptr;
		Microsoft::Office::Interop::Excel::Range^ workcells = nullptr;
		Microsoft::Office::Interop::Excel::Range^ allcells = nullptr;
		Microsoft::Office::Interop::Excel::Range^ targetCell = nullptr;

		//MessageBox::Show(file[0]);
		//MessageBox::Show(title);
		//MessageBox::Show(extension);
		//MessageBox::Show(directory);
		//extension==".xlsx","xls","xlw"という記述だとコードは通るが、if文がきかなくなる。
		//例えば、指定したファイル形式でなくても、if文を通るようになってしまう
		if (extension == ".xlsx" || extension == "xls" || extension == "xlw") {
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
				String^ pad = "パッド中心座標(原点中心)";

				Microsoft::Office::Interop::Excel::Range^ samcell = (Microsoft::Office::Interop::Excel::Range^)worksheet->Cells[2, 2];
				//Findという検索メソッドを使用
				/*samRange = workcells->Find(
					pad,
					Type::Missing,
					Microsoft::Office::Interop::Excel::XlFindLookIn::xlValues,
					Microsoft::Office::Interop::Excel::XlLookAt::xlPart,
					Microsoft::Office::Interop::Excel::XlSearchOrder::xlByRows,
					Microsoft::Office::Interop::Excel::XlSearchDirection::xlNext,
					false,
					Type::Missing,
					Type::Missing
				);
				MessageBox::Show("該当セルです:" + samRange->Text->ToString()+":"+samRange->Row+":"+samRange->Column);
				//結合セルの最終行を取得
				workcells = samRange->MergeArea;
				workcells = (Microsoft::Office::Interop::Excel::Range^)workcells->Cells[workcells->Rows->Count, 1];
				MessageBox::Show("ワークセル最終行です:" + workcells->Row);
				workcells = (Microsoft::Office::Interop::Excel::Range^)workcells->Cells[workcells->Rows->Count+1, 1];
				MessageBox::Show("ワークセル最終行の一つ下です:" + workcells->Row+":"+workcells->Text->ToString());
				if (workcells->Text->ToString()->Contains("X")) {
					MessageBox::Show("このセルはパッド座標の中心座標のx座標です");
					workcells= (Microsoft::Office::Interop::Excel::Range^)workcells->Cells->Next;
					if (workcells->Text->ToString()->Contains("Y")) {
						MessageBox::Show("このセルはパッド座標の中心座標のy座標です");
					}
				}

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


				String^ target = "ターゲット";
				samRange = nullptr;
				//allcellsをrange範囲に指定しないと、findは回ってもfindnextが回らない
				samRange = allcells->Find(
					target,
					Type::Missing,
					Microsoft::Office::Interop::Excel::XlFindLookIn::xlValues,
					Microsoft::Office::Interop::Excel::XlLookAt::xlPart,
					Microsoft::Office::Interop::Excel::XlSearchOrder::xlByRows,
					Microsoft::Office::Interop::Excel::XlSearchDirection::xlNext,
					false,
					Type::Missing,
					Type::Missing
				);

				if (samRange != nullptr) {
					MessageBox::Show(samRange->Row + "行目の" + samRange->Column + "列目で" + "最初のターゲットは見つかりました");
					//最初のセルをターゲットセルに代入
					targetCell = samRange;
					do {
						samRange = allcells->FindNext(samRange);
						if (targetCell->Row == samRange->Row&&targetCell->Column == samRange->Column) {
							break;
						}
						else {
							MessageBox::Show(samRange->Row + "行目の" + samRange->Column + "列目で" + "次のターゲットは見つかりました");
							//ここに処理を記述
						}
					} while (true);

				}*/
				while (true) {
					//処理を記述
					Microsoft::Office::Interop::Excel::WorksheetFunction^ works = app_->WorksheetFunction;
					try {

						works->Match(samcell, allcells, 0);
					}
					catch (Exception^ e) {
						MessageBox::Show(e->ToString());
					}
					finally{
					System::Runtime::InteropServices::Marshal::ReleaseComObject(works);
					}
					break;
					//samRange = worksheet->Cells(WorksheetFunction::Match(pad, allcells, 0), 1);
				}
			}
			catch (Exception^ e) {
				MessageBox::Show(e->ToString());
			}
			finally{
				//COM解放
				app_->Workbooks->Close();

			//System::Runtime::InteropServices::Marshal::ReleaseComObject(targetCell);
			//System::Runtime::InteropServices::Marshal::ReleaseComObject(samRange);

			System::Runtime::InteropServices::Marshal::ReleaseComObject(workcells);
			System::Runtime::InteropServices::Marshal::ReleaseComObject(allcells);
			System::Runtime::InteropServices::Marshal::ReleaseComObject(worksheet);
			System::Runtime::InteropServices::Marshal::ReleaseComObject(workbook);
			System::Runtime::InteropServices::Marshal::ReleaseComObject(app_);

			}
		}
		else if (extension == "txt", ".txt") {
			StreamReader^ sr = gcnew StreamReader(file[0]);
			String^ line;
			System::Collections::Generic::List<String^> strList;
			cli::array<String^>^ arrays;
			try {
				while ((line = sr->ReadLine()) != nullptr) {
					if (line->Contains("VVV")) {
						//ラベルの取得.arrayで受ける
						arrays = line->Split(' ');
					}
				}
				for each (String^ var in arrays)
				{
					MessageBox::Show(var);
				}
			}
			catch (Exception^ e) {
				MessageBox::Show(e->ToString());
			}
			finally{
				sr->Close();
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
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		//String^ path = "sample.txt";
		String^ path = "C:\\Users\\chach\\Desktop\\regex.txt";
		//cli::array<System::Collections::Generic::List<String^>^> dlists = gcnew array<System::Collections::Generic::List<String^>^>{};
		//このリストだけを基板フォームに渡すか、グローバル的に使えるように配置する
		System::Collections::Generic::List<System::Collections::Generic::List<String^>^>^ DList = gcnew System::Collections::Generic::List<System::Collections::Generic::List<String^>^>;
		System::Collections::Generic::List<String^>^ cmpNamelist = gcnew System::Collections::Generic::List<String^>;
		System::Collections::Generic::List<String^>^ cmpX = gcnew System::Collections::Generic::List<String^>;

		//System::Text::RegularExpressions::Regex^ regex = gcnew System::Text::RegularExpressions::Regex("[A-Z][0-9]{2}[)] ");
		//日時を判定
		System::Text::RegularExpressions::Regex^ regex = gcnew System::Text::RegularExpressions::Regex("[0-9]{4}[/][0-9]+[/][0-9]+ [0-9:]{8}");
		//日付を判定
		System::Text::RegularExpressions::Regex^ part_regex = gcnew System::Text::RegularExpressions::Regex("[0-9]{4}[/][0-9]+[/][0-9]+");
		//英数字、記号のファイル名と拡張子を判定
		System::Text::RegularExpressions::Regex^ extension_regex = gcnew System::Text::RegularExpressions::Regex("[0-9a-zA-Z.,:;_-]+[.][a-zA-Z]{3,4}");
		//末尾の拡張子を判定
		System::Text::RegularExpressions::Regex^ end_regex = gcnew System::Text::RegularExpressions::Regex("[.][a-zA-Z]{3,4}$");
		//拡張子部分に名前を付けて、グループとして扱えるように改良
		System::Text::RegularExpressions::Regex^ end2_regex = gcnew System::Text::RegularExpressions::Regex("(?<extension>[.][a-zA-Z]{3,4}$)");


		System::Text::RegularExpressions::Regex^ regexX = gcnew System::Text::RegularExpressions::Regex("x=[0-9]+");
		std::regex re("[A-Z][0-9]{2}[)]$");
		StreamReader^ sr;
		try {
			sr = gcnew StreamReader(path);
			String^ line;
			String^ val = "";

			while ((line = sr->ReadLine()) != nullptr) {

				Match^ match2 = end2_regex->Match(line);
				if (match2->Success) {
					//MessageBox::Show("拡張子:"+line);
					MessageBox::Show("拡張子"+match2->Groups["extension"]->Value->ToString());
				}

				cli::array<String^>^ linelist = line->Split('"');
				for each (String^ var in linelist)
				{
					System::Text::RegularExpressions::Match^ match = regex->Match(var);
					if (match->Success) {
						MessageBox::Show(var + "一致");
						MessageBox::Show("test" + match->Value);
					}
					if (part_regex->IsMatch(var, 0)) {
						MessageBox::Show("先頭一致"+var);
					}

				}

				std::string str = msclr::interop::marshal_as<std::string>(line);
				std::smatch m;
				if (std::regex_match(str, m, std::regex("[A-Z][0-9]{2}[)]"))) {
					std::string tmp = m[0].str();
					String^ cpp = msclr::interop::marshal_as<System::String^>(tmp);
					MessageBox::Show("++" + cpp);
				}

				for (System::Text::RegularExpressions::Match^ match = regex->Match(line);
					match->Success; match = match->NextMatch())
				{
					if (match->Value->Length > 0)
					{
						String^ cName = match->Value;
						//一致する文字列(line)があったときに"x="で始まる部分を検索し、値を取得する
						if (regexX->Match(line)->Success) {
							val = regexX->Match(line)->Value->ToString();
							cmpNamelist->Add(cName);
							cmpX->Add(val);

						}
						else {
							val = "";

						}
						MessageBox::Show(match->Value + "::" + val);
					}
				}
			}
			for (int i = 0; i < cmpNamelist->Count; i++) {
				//MessageBox::Show("部品名:" + cmpNamelist[i] + ":x:" + cmpX[i]);
			}
			DList->Add(cmpNamelist);
			DList->Add(cmpX);
		}
		catch (Exception^ e) {
			MessageBox::Show(e->ToString());
		}
		finally{
			MessageBox::Show("検索終了");
			sr->Close();
			cmpForm^ c1 = gcnew cmpForm(DList);
			c1->ShowDialog();
		}

	}
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ path = "C:\\Users\\chach\\Desktop\\ppt2.pptx";
		String^ path2 = "C:\\Users\\chach\\Desktop\\pptest2";
		String^ picturePath = "C:\\Users\\chach\\Desktop\\56.jpg";
		String^ picturePath1 = "C:\\Users\\chach\\Desktop\\msd.png";
		int slide_Index = 1;
		int shapesIndex = 1;
		Microsoft::Office::Interop::PowerPoint::Application^ apt = gcnew Microsoft::Office::Interop::PowerPoint::ApplicationClass();
		Microsoft::Office::Interop::PowerPoint::Presentations^ presen = apt->Presentations;
		//プレゼンテーション新規作成
		Microsoft::Office::Interop::PowerPoint::Presentation^ presense1 = presen->Add(MsoTriState::msoFalse);
		//スライド追加
		presense1->Slides->Add(slide_Index, Microsoft::Office::Interop::PowerPoint::PpSlideLayout::ppLayoutBlank);
		//画像追加1
		Microsoft::Office::Interop::PowerPoint::Shape^ shape = presense1->Slides[slide_Index]->Shapes->AddPicture(picturePath, MsoTriState::msoFalse, MsoTriState::msoTrue, 100, 100, 500, 500);
		shape->Name = "gazou1";
		//画像追加2
		Microsoft::Office::Interop::PowerPoint::Shape^ shape1 = presense1->Slides[slide_Index]->Shapes->AddPicture(picturePath1, MsoTriState::msoFalse, MsoTriState::msoTrue, 600, 100, 500, 500);
		shape1->Name = "gazou2";
		//セーブ
		presense1->SaveAs(path2, Microsoft::Office::Interop::PowerPoint::PpSaveAsFileType::ppSaveAsDefault, MsoTriState::msoTrue);
		//閉じる
		presense1->Close();
		apt->Quit();
		/*
		Microsoft::Office::Interop::PowerPoint::Presentation^ presense = presen->Open(
			path2,
			MsoTriState::msoFalse,
			MsoTriState::msoFalse,
			MsoTriState::msoFalse
		);
		
		
		/*Microsoft::Office::Interop::PowerPoint::Shape^ shape = presense->Slides[slide_Index]->Shapes[shapesIndex];

		if (shape->TextFrame->HasText == MsoTriState::msoTrue) {
			MessageBox::Show(shape->TextFrame->TextRange->Text);
		}
		else {
			MessageBox::Show(shape->Name + "テキストはありません");
		}
		//以下のコードで[1,1]セルのテキストが取得できる
		//取得した図形がテーブルであれば処理をする
		if (shape->HasTable == MsoTriState::msoTrue) {
			String^ text = shape->Table->Cell(1, 1)->Shape->TextFrame->TextRange->Text;
			MessageBox::Show(text);
		}
		//presense1->Save();
			try {
				presense->Close();
				
			}
			catch (Exception^ e) {
				MessageBox::Show(e->ToString());
			}*/
		
		
	}
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ sampleDirectory = "C:\\Users\\chach\\Desktop\\py2";
		if (Directory::Exists(sampleDirectory)) {
			cli::array<String^>^ filelist = Directory::GetFiles(sampleDirectory);
			String^ sample = "debag1";
			for each (String^ var in filelist)
			{
				if (var->Contains(sample)) {
					MessageBox::Show(var);
				}
			}
		}
		else {
			//フォルダーを新規作成
			Directory::CreateDirectory(sampleDirectory);

		}
	}
	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
		String^ path = "C:\\Users\\chach\\Desktop\\py.zip";
		ZipArchive^ za = ZipFile::OpenRead(path);
		for each (ZipArchiveEntry^ val in za->Entries)
		{
			MessageBox::Show(val->FullName);
		}
	}
	private: static System::String^ sleep_(String^ Message) {
		System::Threading::Thread::Sleep(300);
		MessageBox::Show(Message+"実行中");
		return Message;
	}
	private: static void SampleProc()
		{
			MessageBox::Show("SampleProc実行中");
			sleep_("sleep_実行中");
			ThreadMethod();
		}

	private: static void ThreadMethod()
		{
			MessageBox::Show("ThreadMethod実行中");
		}
	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {

		//出力先を指定
		XmlWriter^ writer = XmlWriter::Create("C:\\Users\\chach\\Desktop\\test.xml");
		//ルートノードを一つにしないと、エラー発生
		writer->WriteStartElement("root");
		//見出しを指定
		writer->WriteStartElement("targetA");
		//見出しから空白あけて値を指定
		writer->WriteAttributeString("value", "data");
		writer->WriteStartElement("targetA-1");
		writer->WriteAttributeString("size", "0.5");
		writer->WriteAttributeString("color", "red");
		writer->WriteEndElement();
		writer->WriteStartElement("targetA-2");
		writer->WriteAttributeString("size", "7.4");
		writer->WriteAttributeString("color", "white");
		writer->WriteEndElement();
		writer->WriteEndElement();

		writer->WriteStartElement("targetB");
		//見出しから空白あけて値を指定
		writer->WriteAttributeString("value", "data");
		writer->WriteStartElement("targetB-1");
		writer->WriteAttributeString("size", "0.5");
		writer->WriteAttributeString("color", "red");
		writer->WriteEndElement();
		writer->WriteStartElement("targetB-2");
		writer->WriteAttributeString("size", "7.4");
		writer->WriteAttributeString("color", "white");
		writer->WriteEndElement();
		writer->WriteEndElement();

		writer->WriteEndElement();
		
		writer->Close();
		MessageBox::Show("出力完了");
	}
	private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
		Thread^ t = gcnew Thread(gcnew Threading::ThreadStart(SampleProc));
		//Thread^ t1 = gcnew Thread(gcnew Threading::ThreadStart(sleep_("msg")));
		//Thread^ threadA = gcnew Thread(gcnew ThreadStart(ThreadMethod));
		t->Start();
		
	}
};
	}
