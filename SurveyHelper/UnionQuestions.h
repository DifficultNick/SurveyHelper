#pragma once

#include "Classes.h"
#include "Funuctions.h"

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class UnionQuestions : public System::Windows::Forms::Form
	{
	public:

		prevCellstr^ prevCell = gcnew prevCellstr();
		List<String^>^ QList = gcnew List<String^>();
		bool IgnorSpaces = false;
		//AdditionalAnswer^ NothingAnswer;


	public:
		UnionQuestions(bool ignorSpaces)
		{
			InitializeComponent();
			IgnorSpaces = ignorSpaces;
		}

	protected:
		~UnionQuestions()
		{
			if (components)
			{
				delete components;
			}
		}

#pragma region Windows Form Designer generated code

	private: System::Windows::Forms::Label^  label3;
	public: System::Windows::Forms::Label^  label4;
	public: System::Windows::Forms::TextBox^  QId;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  DelNums;
	public: System::Windows::Forms::Button^  button2;
	public: System::Windows::Forms::TextBox^  UnionMixIdText;
	public: System::Windows::Forms::CheckBox^  cUnionMixId;
	public: System::Windows::Forms::CheckBox^  cUnionMix;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
	private: System::Windows::Forms::Panel^  panel1;
	public: System::Windows::Forms::CheckBox^  ToList;
	private: System::Windows::Forms::Button^  button1;
	public: System::Windows::Forms::TextBox^  ListIdBox;
	private: System::Windows::Forms::ToolTip^  toolTip1;
	private: System::ComponentModel::IContainer^  components;

	private:
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(UnionQuestions::typeid));
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->DelNums = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->UnionMixIdText = (gcnew System::Windows::Forms::TextBox());
			this->cUnionMixId = (gcnew System::Windows::Forms::CheckBox());
			this->cUnionMix = (gcnew System::Windows::Forms::CheckBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->QId = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->ListIdBox = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->ToList = (gcnew System::Windows::Forms::CheckBox());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->tableLayoutPanel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->contextMenuStrip1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel1->Controls->Add(this->dataGridView1, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->panel1, 0, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 94)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->Size = System::Drawing::Size(642, 361);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->Column1 });
			this->dataGridView1->ContextMenuStrip = this->contextMenuStrip1;
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView1->Location = System::Drawing::Point(3, 97);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->RowsDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->Size = System::Drawing::Size(636, 364);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellBeginEdit += gcnew System::Windows::Forms::DataGridViewCellCancelEventHandler(this, &UnionQuestions::dataGridView1_CellBeginEdit);
			this->dataGridView1->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &UnionQuestions::WrapCells);
			this->dataGridView1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &UnionQuestions::dataGridView1_KeyDown);
			// 
			// Column1
			// 
			this->Column1->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Column1->HeaderText = L"Question Text";
			this->Column1->Name = L"Column1";
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->DelNums });
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(187, 26);
			// 
			// DelNums
			// 
			this->DelNums->Name = L"DelNums";
			this->DelNums->Size = System::Drawing::Size(186, 22);
			this->DelNums->Text = L"Удалить нумерацию";
			this->DelNums->Click += gcnew System::EventHandler(this, &UnionQuestions::DelNums_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->UnionMixIdText);
			this->panel1->Controls->Add(this->cUnionMixId);
			this->panel1->Controls->Add(this->cUnionMix);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->QId);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->ListIdBox);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->ToList);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(642, 94);
			this->panel1->TabIndex = 1;
			// 
			// UnionMixIdText
			// 
			this->UnionMixIdText->Enabled = false;
			this->UnionMixIdText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->UnionMixIdText->Location = System::Drawing::Point(379, 13);
			this->UnionMixIdText->Name = L"UnionMixIdText";
			this->UnionMixIdText->Size = System::Drawing::Size(110, 22);
			this->UnionMixIdText->TabIndex = 15;
			this->toolTip1->SetToolTip(this->UnionMixIdText, L"ListID");
			this->UnionMixIdText->WordWrap = false;
			// 
			// cUnionMixId
			// 
			this->cUnionMixId->AutoSize = true;
			this->cUnionMixId->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->cUnionMixId->Location = System::Drawing::Point(307, 15);
			this->cUnionMixId->Name = L"cUnionMixId";
			this->cUnionMixId->Size = System::Drawing::Size(61, 19);
			this->cUnionMixId->TabIndex = 13;
			this->cUnionMixId->Text = L"MixId";
			this->cUnionMixId->UseVisualStyleBackColor = true;
			this->cUnionMixId->CheckedChanged += gcnew System::EventHandler(this, &UnionQuestions::cUnionMixId_CheckedChanged);
			// 
			// cUnionMix
			// 
			this->cUnionMix->AutoSize = true;
			this->cUnionMix->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->cUnionMix->Location = System::Drawing::Point(307, 43);
			this->cUnionMix->Name = L"cUnionMix";
			this->cUnionMix->Size = System::Drawing::Size(49, 19);
			this->cUnionMix->TabIndex = 12;
			this->cUnionMix->Text = L"Mix";
			this->cUnionMix->UseVisualStyleBackColor = true;
			this->cUnionMix->CheckStateChanged += gcnew System::EventHandler(this, &UnionQuestions::cUnionMix_CheckStateChanged);
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button2->Location = System::Drawing::Point(600, 58);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(30, 30);
			this->button2->TabIndex = 9;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &UnionQuestions::button2_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(28, 40);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(109, 15);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Обобщённый Id";
			// 
			// QId
			// 
			this->QId->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->QId->Location = System::Drawing::Point(163, 38);
			this->QId->Name = L"QId";
			this->QId->Size = System::Drawing::Size(121, 22);
			this->QId->TabIndex = 7;
			this->toolTip1->SetToolTip(this->QId, L"ListID");
			this->QId->WordWrap = false;
			this->QId->TextChanged += gcnew System::EventHandler(this, &UnionQuestions::QId_TextChanged);
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(3, 69);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(137, 19);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Список вопросов:";
			// 
			// ListIdBox
			// 
			this->ListIdBox->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
			this->ListIdBox->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::CustomSource;
			this->ListIdBox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ListIdBox->Location = System::Drawing::Point(163, 10);
			this->ListIdBox->Name = L"ListIdBox";
			this->ListIdBox->Size = System::Drawing::Size(121, 22);
			this->ListIdBox->TabIndex = 5;
			this->toolTip1->SetToolTip(this->ListIdBox, L"ListID");
			this->ListIdBox->WordWrap = false;
			this->ListIdBox->DoubleClick += gcnew System::EventHandler(this, &UnionQuestions::ListIdBox_Click);
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
			this->button1->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button1->Location = System::Drawing::Point(532, 12);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(98, 38);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Готово";
			this->button1->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &UnionQuestions::button1_Click);
			// 
			// ToList
			// 
			this->ToList->AutoSize = true;
			this->ToList->Checked = true;
			this->ToList->CheckState = System::Windows::Forms::CheckState::Checked;
			this->ToList->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ToList->Location = System::Drawing::Point(12, 12);
			this->ToList->Name = L"ToList";
			this->ToList->Size = System::Drawing::Size(147, 19);
			this->ToList->TabIndex = 0;
			this->ToList->Text = L"Объединить в List";
			this->ToList->UseVisualStyleBackColor = true;
			// 
			// toolTip1
			// 
			this->toolTip1->IsBalloon = true;
			// 
			// UnionQuestions
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(642, 361);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(1137, 671);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(658, 400);
			this->Name = L"UnionQuestions";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Настройки для Union";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &UnionQuestions::UnionQuestions_FormClosing);
			this->Load += gcnew System::EventHandler(this, &UnionQuestions::UnionQuestions_Load);
			this->tableLayoutPanel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->contextMenuStrip1->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion


	private: System::Void cUnionMixId_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
	{
		UnionMixIdText->Enabled = cUnionMixId->Checked;
		if ( cUnionMixId->Checked ) cUnionMix->Checked = false;
	}


	public: void Clear()
	{
		dataGridView1->Rows->Clear();
	}


	private: System::Void cUnionMix_CheckStateChanged(System::Object^  sender, System::EventArgs^  e)
	{
		if ( cUnionMix->Checked ) cUnionMixId->Checked = false;
	}
	
	// разбивание на отдельные строки
	private: System::Void WrapCells(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
	{
		if ( e->RowIndex < 0 ) return;
		String^ restStr = Convert::ToString(dataGridView1->CurrentCell->Value);
		String^ separator = Environment::NewLine;

		if ( !restStr->Contains(separator) && CountSubStrings(restStr, "\t") > 2 )
			separator = "\t";

		int nPos = restStr->IndexOf(separator);
		if ( (nPos <= 0) ) return;

		int CurrentColumn = dataGridView1->CurrentCell->ColumnIndex,
			CurrentRow = dataGridView1->CurrentCell->RowIndex;

		String  ^newStr;
		DataGridViewRow^ r;
		DataGridViewCell^ c;
		bool reWrite = true;

		// проверка: перезапись или вставка
		for ( int i = CurrentRow + 1; i < dataGridView1->RowCount; i++ )
			if ( !String::IsNullOrEmpty(Convert::ToString(dataGridView1->Rows[i]->Cells[CurrentColumn]->Value)) )
			{
				Forms::DialogResult res = MessageBox::Show(
					"Презаписать уже имеющиеся данные?\n\"Нет\" - чтобы вставить,\n\"Да\" - чтобы перезаписать.",
					"", System::Windows::Forms::MessageBoxButtons::YesNoCancel,
					System::Windows::Forms::MessageBoxIcon::Question);
				if ( res == Forms::DialogResult::Cancel )
				{
					dataGridView1->CurrentCell->Value = prevCell->Value;
					return;
				}
				else reWrite = (res == Forms::DialogResult::OK);
				break;
			}

		int next = 0;
		nPos = restStr->IndexOf(separator);

		try
		{
			// цикл по количеству \n
			while ( (nPos > 0) )
			{
				newStr = restStr->Remove(nPos);
				restStr = restStr->Remove(0, nPos + 1);

				// обновление данных в нужной ячейке текущей строки
				for ( int i = 0; i < dataGridView1->ColumnCount; i++ )
					if ( i == CurrentColumn ) dataGridView1->Rows[CurrentRow + next]->Cells[i]->Value = newStr;

				next++;

				// не выводить пустую
				if ( String::IsNullOrEmpty(restStr) ) break;

				// формирование следующей строки
				r = gcnew DataGridViewRow();
				for ( int i = 0; i < dataGridView1->ColumnCount; i++ )
				{
					c = gcnew DataGridViewTextBoxCell();
					if ( i == CurrentColumn ) c->Value = restStr;
					else
						if ( reWrite ) c->Value = Convert::ToString(dataGridView1->Rows[CurrentRow + next]->Cells[i]->Value);
						else c->Value = "";
						r->Cells->Add(c);
				}

				//вставка следующей строки
				if ( CurrentRow + next + 1 >= dataGridView1->RowCount )
					dataGridView1->Rows->Add(r);
				else
					if ( reWrite )
						for ( int i = 0; i < dataGridView1->ColumnCount; i++ )
							dataGridView1->Rows[CurrentRow + next]->Cells[i]->Value = r->Cells[i]->Value->ToString();
					else
						dataGridView1->Rows->Insert(CurrentRow + next, r);
				nPos = restStr->IndexOf(separator);
			}

			// костыль для удаления хз откуда появляющейся доп строки
			if ( dataGridView1->RowCount > 2 && String::IsNullOrEmpty(dataGridView1->Rows[dataGridView1->RowCount - 2]->Cells[0]->Value->ToString()->Trim()) )
				dataGridView1->Rows->RemoveAt(dataGridView1->RowCount - 2);
		}
		catch ( Exception^ e )
		{
			ShowError(320, "Ошибка при переносе текста в следующую строку таблицы\nПодробнее:\n" + e->ToString());
		}
		
		DelNums->PerformClick();
	}


	private: System::Void dataGridView1_CellBeginEdit(System::Object^  sender, System::Windows::Forms::DataGridViewCellCancelEventArgs^  e)
	{
		prevCell->Value = Convert::ToString(dataGridView1[e->ColumnIndex, e->RowIndex]->Value);
		prevCell->Row = e->RowIndex;
		prevCell->Column = e->ColumnIndex;
	}


	// сохранение настроек
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		QList = gcnew List<String^>();
		
		try
		{
			for each (DataGridViewRow^ row in dataGridView1->Rows)
				if ( row->Cells[0]->Value != nullptr ) QList->Add(Convert::ToString(row->Cells[0]->Value));
		}
		catch ( Exception^ e )
		{
			ShowError(321, "Ошибка создания элементов Union\nПодробнее:\n" + e->ToString());
		}

		SaveSettings();

		this->Hide();
	}

	// загрузка настроек
	private: System::Void UnionQuestions_Load(System::Object^  sender, System::EventArgs^  e)
	{
		Settings^ settings = gcnew Settings();
		if ( !settings->Exist("UnionForm") ) return;
		if ( settings->Read("UnionForm") > 0 )
		{
			try
			{
				this->Height = settings->Get("Height", true);
				this->Width = settings->Get("Width", true);
				this->DesktopLocation = Point(settings->Get("Left", true), settings->Get("Top", true));
				this->WindowState = (Forms::FormWindowState)settings->Get("State", true);
				ToList->Checked = settings->Get("CombineQuestions", true);
			}
			catch ( Exception^ e )
			{
				ShowWarning("Ошибка загрузки настроек");
			}
		}
	}

	private: System::Void ListIdBox_Click(System::Object^  sender, System::EventArgs^  e)
	{
		ListIdBox->SelectAll();
	}

	void SaveSettings()
	{
		Settings^ settings = gcnew Settings();

		settings->Set("Height", this->Height);
		settings->Set("Width", this->Width);
		settings->Set("Left", this->DesktopLocation.X);
		settings->Set("Top", this->DesktopLocation.Y);
		if ( this->WindowState == Forms::FormWindowState::Maximized ) settings->Set("State", 2); else settings->Set("State", 0);
		settings->Set("CombineQuestions", ToList->Checked);

		if ( !settings->Save("UnionForm") ) ShowMessage("Ошибка. Настройки не были сохранены.", Forms::MessageBoxIcon::Warning);
	}


	private: System::Void UnionQuestions_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)
	{
		SaveSettings();
	}


	private: System::Void dataGridView1_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
	{
		if ( e->KeyCode == Keys::F9 ) button2->PerformClick();
	}


	private: System::Void QId_TextChanged(System::Object^  sender, System::EventArgs^  e)
	{
		ListIdBox->Text = QId->Text + "_QList";
	}

	private: System::Void DelNums_Click(System::Object^  sender, System::EventArgs^  e)
	{
		for (int i = 0; i < dataGridView1->RowCount - 1; i++)
				if ( dataGridView1->Rows[i]->Cells[0]->Value != nullptr )
					dataGridView1->Rows[i]->Cells[0]->Value = ClearString(dataGridView1->Rows[i]->Cells[0]->Value->ToString(), true, true, IgnorSpaces);
	}


	// очистка таблицы
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e)
	{
		Clear();
	}
	
};