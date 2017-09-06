#pragma once
#include "Classes.h"

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections;

	public ref class Headers : public System::Windows::Forms::Form
	{
	public:
		HeaderList^ h;
		ProjectResources^ rsc = gcnew ProjectResources();
	public:
		bool IsNew;

		Headers(void)
		{
			InitializeComponent();
			this->panel1->BackgroundImage = rsc->GetImage("waiting_for_file");
		}

	protected:
		~Headers()
		{
			if (components)
			{
				delete components;
			}
		}

#pragma region Windows Form Designer generated code

	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::RichTextBox^  richTextBox1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  FilePath;

	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  StatusLabel;

	private: System::Windows::Forms::Button^  button3;
	private: System::ComponentModel::IContainer^  components;

	private:

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Headers::typeid));
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->FilePath = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->StatusLabel = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->Filter = L"XML-файлы|*.xml|Все файлы|*.*";
			this->openFileDialog1->SupportMultiDottedExtensions = true;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				280)));
			this->tableLayoutPanel1->Controls->Add(this->richTextBox1, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 1, 3);
			this->tableLayoutPanel1->Controls->Add(this->label2, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->FilePath, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->button2, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->button1, 0, 4);
			this->tableLayoutPanel1->Controls->Add(this->StatusLabel, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->button3, 1, 2);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(4);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 5;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 79)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 39)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 43)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 44)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(987, 604);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// richTextBox1
			// 
			this->richTextBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->richTextBox1->Enabled = false;
			this->richTextBox1->Location = System::Drawing::Point(4, 122);
			this->richTextBox1->Margin = System::Windows::Forms::Padding(4);
			this->richTextBox1->Name = L"richTextBox1";
			this->tableLayoutPanel1->SetRowSpan(this->richTextBox1, 2);
			this->richTextBox1->Size = System::Drawing::Size(699, 434);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = L"";
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 1;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel2->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->panel1, 0, 1);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(711, 165);
			this->tableLayoutPanel2->Margin = System::Windows::Forms::Padding(4);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 2;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 148)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 25)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(272, 391);
			this->tableLayoutPanel2->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(43, 26);
			this->label1->Margin = System::Windows::Forms::Padding(0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(185, 95);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Файл будет заменён \r\nна новый.\r\nИсходный файл будет \r\nсохранён, как\r\n\"[имя файла]"
				L".Headers.bak\".";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::White;
			this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->panel1->Location = System::Drawing::Point(4, 152);
			this->panel1->Margin = System::Windows::Forms::Padding(4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(264, 218);
			this->panel1->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(4, 23);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(670, 32);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Введите полный путь к фалу, или нажмите \"Обзор\" для поиска файла, или перетащите "
				L"файл на поле внизу справа.";
			// 
			// FilePath
			// 
			this->FilePath->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->FilePath->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->FilePath->Location = System::Drawing::Point(4, 88);
			this->FilePath->Margin = System::Windows::Forms::Padding(4);
			this->FilePath->Name = L"FilePath";
			this->FilePath->Size = System::Drawing::Size(699, 21);
			this->FilePath->TabIndex = 5;
			this->FilePath->TextChanged += gcnew System::EventHandler(this, &Headers::FilePath_TextChanged);
			this->FilePath->DoubleClick += gcnew System::EventHandler(this, &Headers::FilePath_DoubleClick);
			// 
			// button2
			// 
			this->button2->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->button2->Location = System::Drawing::Point(720, 84);
			this->button2->Margin = System::Windows::Forms::Padding(13, 4, 4, 4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(116, 28);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Обзор";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Headers::button2_Click);
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button1->Enabled = false;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(232, 566);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(243, 32);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Показать исходные";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Headers::button1_Click);
			// 
			// StatusLabel
			// 
			this->StatusLabel->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->StatusLabel->AutoSize = true;
			this->StatusLabel->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->StatusLabel->ForeColor = System::Drawing::Color::Red;
			this->StatusLabel->Location = System::Drawing::Point(785, 30);
			this->StatusLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->StatusLabel->Name = L"StatusLabel";
			this->StatusLabel->Size = System::Drawing::Size(124, 19);
			this->StatusLabel->TabIndex = 7;
			this->StatusLabel->Text = L"Выберите файл";
			// 
			// button3
			// 
			this->button3->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button3->Location = System::Drawing::Point(720, 125);
			this->button3->Margin = System::Windows::Forms::Padding(13, 4, 4, 4);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(249, 28);
			this->button3->TabIndex = 8;
			this->button3->Text = L"Обработать";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Headers::button3_Click);
			// 
			// Headers
			// 
			this->AllowDrop = true;
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(987, 604);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(849, 626);
			this->Name = L"Headers";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Удаление нумерации вопросов";
			this->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &Headers::FormDragDrop);
			this->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &Headers::FormDragEnter);
			this->DragLeave += gcnew System::EventHandler(this, &Headers::FormDragLeave);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion


private: System::Void FormDragEnter(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e)
{
	if ( e->Data->GetDataPresent(DataFormats::FileDrop) )
	{
		e->Effect = DragDropEffects::All;
		String^ ext = ((array<String^>^)e->Data->GetData(DataFormats::FileDrop))[0];
		SelectImage(ext);
	}
}


private: System::Void FormDragDrop(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e)
{
	if ( e->Data->GetDataPresent(DataFormats::FileDrop) ) FilePath->Text = ((array<String^>^)e->Data->GetData(DataFormats::FileDrop))[0];
}


private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e)
{
	if ( openFileDialog1->ShowDialog() == Forms::DialogResult::OK ) FilePath->Text = openFileDialog1->FileName;
}


private: System::Void FilePath_TextChanged(System::Object^  sender, System::EventArgs^  e)
{
	FilePath->Text = Regex::Replace(FilePath->Text, "^[\"'](?<path>.+)[\"']$", "${path}");
	if (File::Exists(FilePath->Text)) StatusLabel->Text = "Нажмите \"Обработать\"";
}


private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e)
{
	if ( !File::Exists(FilePath->Text) )
	{
		ShowMessage("Сначала выберите файл!", Forms::MessageBoxIcon::Exclamation);
		return;
	}
	richTextBox1->Clear();
	StatusLabel->Text = "Идёт обработка...";

	h = RemoveHeaders(FilePath->Text);
	if ( h->Completed == 0 )
	{
		if ( h->Count == 0) ShowMessage("В файле не было найдено ни одного заголовка.", Forms::MessageBoxIcon::Information);
		else ShowMessage("В файле не было найдено ни одного номера\nв заголовках вопросов.", Forms::MessageBoxIcon::Information);
	}
	else
	{
		for each (String^ s in h->NewHeaders)
			richTextBox1->Text += s + "\n\n";
		button1->Enabled = true;
		IsNew = true;
		ShowMessage("Обработано " + h->Completed.ToString() + "\nиз " + h->Count.ToString() + " заголовков.");
	}

	StatusLabel->Text = "Обработано " + h->Completed.ToString() + "\nиз " + h->Count.ToString() + " заголовков.";
}


private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	richTextBox1->Clear();
 
	for each (String^ s in ( (IsNew) ? h->OldHeaders : h->NewHeaders) )
		richTextBox1->Text += s + "\n\n";
	button1->Text = (IsNew) ? "Показать новые" : "Показать исходные";
	IsNew = !IsNew;
}


private: System::Void FilePath_DoubleClick(System::Object^  sender, System::EventArgs^  e)
{
	FilePath->SelectAll();
}


private: System::Void FormDragLeave(System::Object^  sender, System::EventArgs^  e)
{
	if ( !File::Exists(FilePath->Text) ) this->panel1->BackgroundImage = rsc->GetImage("waiting_for_file");
	else SelectImage(FilePath->Text);
}
		 

void SelectImage(String^ ex)
{
	try
	{
		if ( ex == nullptr || String::IsNullOrEmpty(ex) )
		{
			panel1->BackgroundImage = rsc->GetImage("unknown_file");
			return;
		}

		String^ ext = Path::GetExtension(ex)->ToUpper();

		if ( ext->Contains("XML") )
			panel1->BackgroundImage = rsc->GetImage("xml_file");
		else if ( ext->Contains("BAK") )
			panel1->BackgroundImage = rsc->GetImage("bak_file");
		else if ( ext->Contains("TXT") )
			panel1->BackgroundImage = rsc->GetImage("txt_file");
		else
			panel1->BackgroundImage = rsc->GetImage("unknown_file");
	}
	catch ( Exception^ e )
	{
		ShowError(302, "Ошибка в ресурсах приложения");
	}
	
}

};