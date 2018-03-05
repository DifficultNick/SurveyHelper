#pragma once

#include "Classes.h"
#include "Funuctions.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


public ref class FileReplace : public System::Windows::Forms::Form
{
	public:
		FileReplace(void)
		{
			InitializeComponent();
		}

	protected:

		~FileReplace()
		{
			if (components)
			{
				delete components;
			}
		}





	private:

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
private: System::Windows::Forms::Button^  go;
private: System::Windows::Forms::Label^  label1;
private: System::Windows::Forms::TextBox^  filePath;
private: System::Windows::Forms::Button^  search;
private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
private: System::Windows::Forms::Label^  label3;
private: System::Windows::Forms::RichTextBox^  from;

private: System::Windows::Forms::RichTextBox^  to;


private: System::Windows::Forms::Label^  label2;


		void InitializeComponent(void)
		{	
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(FileReplace::typeid));
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->from = (gcnew System::Windows::Forms::RichTextBox());
			this->to = (gcnew System::Windows::Forms::RichTextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->go = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->filePath = (gcnew System::Windows::Forms::TextBox());
			this->search = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel3, 0, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 35)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(836, 386);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel2->Controls->Add(this->label3, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->from, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->to, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->label2, 1, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 38);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 2;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 14)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(830, 345);
			this->tableLayoutPanel2->TabIndex = 0;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label3->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label3->Location = System::Drawing::Point(3, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(409, 14);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Строки для замены:";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// from
			// 
			this->from->Dock = System::Windows::Forms::DockStyle::Fill;
			this->from->Location = System::Drawing::Point(3, 17);
			this->from->Name = L"from";
			this->from->Size = System::Drawing::Size(409, 325);
			this->from->TabIndex = 3;
			this->from->Text = L"";
			// 
			// to
			// 
			this->to->Dock = System::Windows::Forms::DockStyle::Fill;
			this->to->Location = System::Drawing::Point(418, 17);
			this->to->Name = L"to";
			this->to->Size = System::Drawing::Size(409, 325);
			this->to->TabIndex = 2;
			this->to->Text = L"";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label2->Location = System::Drawing::Point(418, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(409, 14);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Новые значения:";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 4;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				8.585055F)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				91.41495F)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				95)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				114)));
			this->tableLayoutPanel3->Controls->Add(this->go, 3, 0);
			this->tableLayoutPanel3->Controls->Add(this->label1, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->filePath, 1, 0);
			this->tableLayoutPanel3->Controls->Add(this->search, 2, 0);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 1;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(830, 29);
			this->tableLayoutPanel3->TabIndex = 1;
			// 
			// go
			// 
			this->go->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->go->Location = System::Drawing::Point(718, 3);
			this->go->Name = L"go";
			this->go->Size = System::Drawing::Size(109, 23);
			this->go->TabIndex = 3;
			this->go->Text = L"Заменить";
			this->go->UseVisualStyleBackColor = true;
			this->go->Click += gcnew System::EventHandler(this, &FileReplace::button2_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label1->Location = System::Drawing::Point(3, 8);
			this->label1->Margin = System::Windows::Forms::Padding(3, 0, 3, 8);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(47, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Файл:";
			// 
			// filePath
			// 
			this->filePath->Dock = System::Windows::Forms::DockStyle::Fill;
			this->filePath->Location = System::Drawing::Point(56, 3);
			this->filePath->Name = L"filePath";
			this->filePath->Size = System::Drawing::Size(561, 20);
			this->filePath->TabIndex = 1;
			// 
			// search
			// 
			this->search->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->search->Location = System::Drawing::Point(623, 3);
			this->search->Name = L"search";
			this->search->Size = System::Drawing::Size(89, 23);
			this->search->TabIndex = 2;
			this->search->Text = L"Обзор";
			this->search->UseVisualStyleBackColor = true;
			this->search->Click += gcnew System::EventHandler(this, &FileReplace::search_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->Filter = L"XML-файлы|*.xml|Все файлы|*.*";
			this->openFileDialog1->SupportMultiDottedExtensions = true;
			// 
			// FileReplace
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->ClientSize = System::Drawing::Size(836, 386);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"FileReplace";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Построчная замена в файле";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->PerformLayout();
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel3->PerformLayout();
			this->ResumeLayout(false);

		}
	#pragma endregion


	// возвращает List Id
	private: List<int>^ SortByLength(List<String^>^ lstSort)
	{
		List<int>^ res = gcnew List<int>();
		try
		{
			if ( lstSort->Count < 2 )
			{
				res->Add(0);
				return res;
			}
			List<String^>^ source = gcnew List<String^>(lstSort);
			int max = 0, j = 0;

			while ( source->Count > 0 )
			{
				max = source[0]->Length;
				j = 0;
				for ( int i = 0; source->Count > i; i++ )
				{
					if ( max < source[i]->Length )
					{
						max = source[i]->Length;
						j = i;
					}
				}
				res->Add(j);
				source->RemoveAt(j);
			}
		}
		catch ( Exception^ e )
		{
			ShowError(417, "Ошибка сортировки строк по увеличению длины\n\n"+e->ToString());
		}

		
		return res;
	}

	private: List<String^>^ SetOrder(List<String^>^ lst, List<int>^ order)
	{
		List<String^>^ res = gcnew List<String^>();
		try
		{
			for each (int i in order)
				res->Add(lst[i]);
		}
		catch ( Exception^ e )
		{
			ShowError(418, "Ошибка сортировки строк по увеличению длины\n\n" + e->ToString());
		}
		
		return res;
	}

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if ( !File::Exists(filePath->Text) )
		{
			ShowMessage("Выберите файл!");
			return;
		}

		//List<String^>^ file = gcnew List<String^>(ReadFile(filePath->Text));
		String^ file = File::ReadAllText(filePath->Text, System::Text::Encoding::Default);
		List<String^>^ oldV = StringToList(from->Text, '\n');
		List<String^>^ newV = StringToList(to->Text, '\n');
		List<int>^ order = SortByLength(oldV);
		oldV = SetOrder(oldV, order);
		newV = SetOrder(newV, order);
		int c = 0;

		try
		{

			if ( oldV->Count != newV->Count )
			{
				ShowMessage("Разное количество строк!");
				return;
			}

			for (int j = 0; oldV->Count > j; j++)
			{
				String^ tmp = oldV[j]->Trim();
				if (file->Contains(tmp))
				{
					c += CountSubStrings(file, tmp);
					file = file->Replace(tmp, newV[j]->Trim());
				}
			}
			if ( c == 0 )
			{
				ShowMessage("Совпадений не найдено");
				return;
			}
			WriteFile(filePath->Text, file->Split('\n'), ".bak");
			ShowMessage("Файл сохранён, выполнено " + c.ToString() + " замен.");
		}
		catch ( Exception^ e )
		{
			ShowError(211, "Ошибка доступа к файлу\n\n" + e->ToString());
		}
	}

	private: System::Void search_Click(System::Object^  sender, System::EventArgs^ e)
	{
		if ( openFileDialog1->ShowDialog() == Forms::DialogResult::OK ) filePath->Text = openFileDialog1->FileName;
	}

};