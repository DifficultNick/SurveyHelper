#pragma once

#include "Funuctions.h"
#include "Classes.h"

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class VarForm : public System::Windows::Forms::Form
	{
	public:
		VarForm(void)
		{
			InitializeComponent();
			this->KeyPreview = true;
			this->KeyDown += gcnew KeyEventHandler(this, &VarForm::KeyPressed);
		}
	private: System::Windows::Forms::ToolStripMenuItem^  insertRow;

	
	public:	
			ref struct prevCellstr
			{
				String^ Value;
				int Column = -1;
				int Row;
			};


	public: 
			// для передачи в главную форму
			List<List<String^>^>^ vars = gcnew List<List<String^>^>();

			// для хранения предыдущей версии Var (для транслита и заполнения пустых)
			List<List<String^>^>^ prevVars = gcnew List<List<String^>^>();

			// для учёта того, что ячейка не редактируется при вызове очистки таблицы
			bool CurrentChanging = false;

			// для отличия 2 функции: замена пустых или безопасные символы
			bool forSafe;

			prevCellstr^ prevCell = gcnew prevCellstr();

			// для учёта изменения данных при транслите и замене пустот Var туда-обратно
			bool ValueChanged = true;

	public: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::ToolStripMenuItem^  удалитьНумерациюToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  удалитьСтрокуToolStripMenuItem;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Var0;

	public:

			// для сбрасывания флажка безопасных символов
			bool SafeChanged = false;

#pragma region Windows Form Designer generated code
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~VarForm()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::TextBox^  emptyVar;

	private: System::Windows::Forms::CheckBox^  checkBox2;
	public: System::Windows::Forms::CheckBox^  checkBox1;
	private: System::Windows::Forms::CheckBox^  SafeSymbols;
	private: System::Windows::Forms::ToolTip^  toolTip1;
	private: System::Windows::Forms::ContextMenuStrip^  contextMenuStrip1;

	private: System::Windows::Forms::ToolStripMenuItem^  deleteVar;

	private: System::Windows::Forms::Button^  button1;
	private: System::ComponentModel::IContainer^  components;
	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>



		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(VarForm::typeid));
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Var0 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->contextMenuStrip1 = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
			this->удалитьНумерациюToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->deleteVar = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->insertRow = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->удалитьСтрокуToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->emptyVar = (gcnew System::Windows::Forms::TextBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->SafeSymbols = (gcnew System::Windows::Forms::CheckBox());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->contextMenuStrip1->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToOrderColumns = true;
			this->dataGridView1->ClipboardCopyMode = System::Windows::Forms::DataGridViewClipboardCopyMode::EnableWithoutHeaderText;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->Var0 });
			this->dataGridView1->ContextMenuStrip = this->contextMenuStrip1;
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridView1->DefaultCellStyle = dataGridViewCellStyle3;
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView1->Location = System::Drawing::Point(3, 93);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->Size = System::Drawing::Size(572, 314);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellBeginEdit += gcnew System::Windows::Forms::DataGridViewCellCancelEventHandler(this, &VarForm::dataGridView1_CellBeginEdit);
			this->dataGridView1->CellEndEdit += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &VarForm::dataGridView1_CellEndEdit);
			this->dataGridView1->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &VarForm::dataGridView1_CellValueChanged);
			this->dataGridView1->ColumnDisplayIndexChanged += gcnew System::Windows::Forms::DataGridViewColumnEventHandler(this, &VarForm::dataGridView1_ColumnDisplayIndexChanged);
			// 
			// Var0
			// 
			this->Var0->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			this->Var0->ContextMenuStrip = this->contextMenuStrip1;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->Var0->DefaultCellStyle = dataGridViewCellStyle2;
			this->Var0->HeaderText = L"Var(0)";
			this->Var0->MinimumWidth = 150;
			this->Var0->Name = L"Var0";
			this->Var0->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// contextMenuStrip1
			// 
			this->contextMenuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
			this->contextMenuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4)
			{
				this->удалитьНумерациюToolStripMenuItem,
					this->deleteVar, this->insertRow, this->удалитьСтрокуToolStripMenuItem
			});
			this->contextMenuStrip1->Name = L"contextMenuStrip1";
			this->contextMenuStrip1->Size = System::Drawing::Size(189, 92);
			// 
			// удалитьНумерациюToolStripMenuItem
			// 
			this->удалитьНумерациюToolStripMenuItem->Name = L"удалитьНумерациюToolStripMenuItem";
			this->удалитьНумерациюToolStripMenuItem->Size = System::Drawing::Size(188, 22);
			this->удалитьНумерациюToolStripMenuItem->Text = L"Удалить нумерацию";
			this->удалитьНумерациюToolStripMenuItem->Click += gcnew System::EventHandler(this, &VarForm::удалитьНумерациюToolStripMenuItem_Click);
			// 
			// deleteVar
			// 
			this->deleteVar->Name = L"deleteVar";
			this->deleteVar->Size = System::Drawing::Size(188, 22);
			this->deleteVar->Text = L"Удалить текущий Var";
			this->deleteVar->ToolTipText = L"Удалить весь столбец Var";
			this->deleteVar->Click += gcnew System::EventHandler(this, &VarForm::deleteVar_Click);
			// 
			// insertRow
			// 
			this->insertRow->Name = L"insertRow";
			this->insertRow->Size = System::Drawing::Size(188, 22);
			this->insertRow->Text = L"Добавить строку";
			this->insertRow->ToolTipText = L"Вставить строку после текущей";
			this->insertRow->Click += gcnew System::EventHandler(this, &VarForm::insertRow_Click);
			// 
			// удалитьСтрокуToolStripMenuItem
			// 
			this->удалитьСтрокуToolStripMenuItem->Name = L"удалитьСтрокуToolStripMenuItem";
			this->удалитьСтрокуToolStripMenuItem->Size = System::Drawing::Size(188, 22);
			this->удалитьСтрокуToolStripMenuItem->Text = L"Удалить строку";
			this->удалитьСтрокуToolStripMenuItem->Click += gcnew System::EventHandler(this, &VarForm::удалитьСтрокуToolStripMenuItem_Click);
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
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 90)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
			this->tableLayoutPanel1->Size = System::Drawing::Size(578, 410);
			this->tableLayoutPanel1->TabIndex = 1;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->button3);
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->emptyVar);
			this->panel1->Controls->Add(this->checkBox2);
			this->panel1->Controls->Add(this->checkBox1);
			this->panel1->Controls->Add(this->SafeSymbols);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(3, 3);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(572, 84);
			this->panel1->TabIndex = 1;
			// 
			// button3
			// 
			this->button3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.BackgroundImage")));
			this->button3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button3->Location = System::Drawing::Point(533, 50);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(30, 30);
			this->button3->TabIndex = 6;
			this->toolTip1->SetToolTip(this->button3, L"(F8) Добавить Var");
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &VarForm::button3_Click);
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button2.BackgroundImage")));
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button2->Location = System::Drawing::Point(491, 50);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(30, 30);
			this->button2->TabIndex = 5;
			this->toolTip1->SetToolTip(this->button2, L"(F9) Очистить");
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &VarForm::button2_Click);
			// 
			// button1
			// 
			this->button1->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.Image")));
			this->button1->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button1->Location = System::Drawing::Point(471, 6);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(92, 40);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Готово";
			this->button1->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &VarForm::button1_Click);
			// 
			// emptyVar
			// 
			this->emptyVar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->emptyVar->Location = System::Drawing::Point(261, 59);
			this->emptyVar->Name = L"emptyVar";
			this->emptyVar->Size = System::Drawing::Size(113, 21);
			this->emptyVar->TabIndex = 2;
			this->toolTip1->SetToolTip(this->emptyVar, L"Символ для вставки в пустые Var");
			this->emptyVar->WordWrap = false;
			// 
			// checkBox2
			// 
			this->checkBox2->AutoSize = true;
			this->checkBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBox2->Location = System::Drawing::Point(9, 59);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(237, 19);
			this->checkBox2->TabIndex = 1;
			this->checkBox2->Text = L"Заполнить пустые Var строкой:";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox2->CheckedChanged += gcnew System::EventHandler(this, &VarForm::checkBox2_CheckedChanged);
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkBox1->Location = System::Drawing::Point(10, 34);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(227, 19);
			this->checkBox1->TabIndex = 1;
			this->checkBox1->Text = L"Каждый Var отдельным тэгом";
			this->checkBox1->UseVisualStyleBackColor = true;
			// 
			// SafeSymbols
			// 
			this->SafeSymbols->AutoSize = true;
			this->SafeSymbols->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->SafeSymbols->Location = System::Drawing::Point(10, 9);
			this->SafeSymbols->Name = L"SafeSymbols";
			this->SafeSymbols->Size = System::Drawing::Size(170, 19);
			this->SafeSymbols->TabIndex = 1;
			this->SafeSymbols->Text = L"Безопасные символы";
			this->toolTip1->SetToolTip(this->SafeSymbols, L"Преобразовывает текст в символы,\r\nкоторые можно использовать в XML.");
			this->SafeSymbols->UseVisualStyleBackColor = true;
			this->SafeSymbols->Click += gcnew System::EventHandler(this, &VarForm::SafeSymbols_CheckedChanged);
			// 
			// toolTip1
			// 
			this->toolTip1->AutoPopDelay = 8000;
			this->toolTip1->InitialDelay = 300;
			this->toolTip1->IsBalloon = true;
			this->toolTip1->ReshowDelay = 100;
			// 
			// VarForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(578, 410);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(590, 449);
			this->Name = L"VarForm";
			this->ShowInTaskbar = false;
			this->Text = L"Var";
			this->Shown += gcnew System::EventHandler(this, &VarForm::VarForm_Shown);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->contextMenuStrip1->ResumeLayout(false);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion



#pragma region доп функции
	
	// работа с именами Var
	void SetColumnName(int columnIndex, int varIndex)
	{
		dataGridView1->Columns[columnIndex]->Name = "Var" + varIndex.ToString();
	}

	int GetColumnIndex(String^ colName)
	{
		return (dataGridView1->Columns->Contains(colName)) ? dataGridView1->Columns[colName]->Index : -1;
	}

	int GetColumnIndex(int varIndex)
	{
		return (dataGridView1->Columns->Contains("Var" + varIndex.ToString())) ? dataGridView1->Columns["Var" + varIndex.ToString()]->Index : -1;
	}

	bool ColumnExists(int varIndex)
	{
		return dataGridView1->Columns->Contains("Var" + varIndex.ToString());
	}

	
	// перестановка столбцов
	void ReorderColumns()
	{
		for ( int i = 0; i < dataGridView1->ColumnCount; i++ )
		{
			String^ newName = "Var" + dataGridView1->Columns[i]->DisplayIndex.ToString();
			dataGridView1->Columns[i]->Name = newName;
			dataGridView1->Columns[i]->HeaderText = newName;
		}
	}


	// добавление столбца в таблицу
	private: void AddColumn()
	{
		try
		{
			String^ ColName = "Var" + dataGridView1->Columns->Count.ToString();
			int index = dataGridView1->Columns->Add(ColName, ColName);
			dataGridView1->Columns[index]->SortMode = DataGridViewColumnSortMode::NotSortable;
			dataGridView1->Columns[index]->AutoSizeMode = DataGridViewAutoSizeColumnMode::Fill;
			dataGridView1->Columns[index]->MinimumWidth = 150;
			dataGridView1->Columns[index]->ContextMenuStrip = contextMenuStrip1;
			dataGridView1->Columns[index]->DefaultCellStyle->WrapMode = DataGridViewTriState::True;
			dataGridView1->CurrentCell = dataGridView1[index, 0];
			dataGridView1->FirstDisplayedScrollingColumnIndex = index;
		}
		catch ( Exception^ e )
		{
			ShowError(322, "Ошибка добавления столбца\nПодробнее:\n" + e->ToString());
		}
	}

	// загрузка Var
	private: void LoadToTable(List<List<String^>^>^ varsList)
	{
		CurrentChanging = true;
		try
		{
			for ( int i = 0; i < varsList->Count; i++ )
			{
				List<String^>^ lst = gcnew List<String^>(varsList[i]);
				for ( int j = 0; j < lst->Count; j++ )
					dataGridView1["Var" + i.ToString(), j]->Value = lst[j];
			}
		}
		catch ( Exception^ e )
		{
			ShowError(323, "Ошибка загрузки списка Var\nПодробнее:\n" + e->ToString());
		}

		CurrentChanging = false;
	}

	private: List<List<String^>^>^ LoadFromTable()
	{
		List<String^>^ col;
		List<List<String^>^>^ tmp = gcnew List<List<String^>^>();
		try
		{
			for ( int i = 0; i < dataGridView1->ColumnCount; i++ )
			{
				col = gcnew List<String^>();
				for ( int j = 0; j < dataGridView1->RowCount; j++ )
					col->Add(Convert::ToString(dataGridView1["Var" + i.ToString(), j]->Value));

				tmp->Add(col);
			}
		}
		catch ( Exception^ e )
		{
			ShowError(324, "Ошибка загрузки списка Var\nПодробнее:\n" + e->ToString());
		}

		return tmp;
	}


	//перенос строк
	private: System::Void WrapCells()
	{
		String^ restStr = Convert::ToString(dataGridView1->CurrentCell->Value);
		char separator;
		if ( restStr->Contains(Environment::NewLine) ) separator = '\n';
		else
		{
			separator = '\t';
			if ( CountSubStrings(restStr, "\t") < 2 )
			{
				return;
			}
		}

		int nPos = restStr->IndexOf(separator);
		if ( (nPos <= 0) ) return;

		int CurrentColumn = dataGridView1->CurrentCell->ColumnIndex,
			CurrentRow = dataGridView1->CurrentCell->RowIndex;

		String  ^newStr;
		DataGridViewRow^ r;
		DataGridViewCell^ c;
		bool reWrite = true;

		// проверка: перезапись или вставка
		for ( int i = CurrentRow+1; i < dataGridView1->RowCount; i++ )
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
			while ( (nPos > -1) )
			{
				newStr = restStr->Remove(nPos - 1);
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
		}
		catch ( Exception^ e )
		{
			ShowError(325, "Ошибка переноса текста на следующую строку таблицы\nПодробнее:\n" + e->ToString());
		}
		
	}


	// обработка клавиш
	private: System::Void KeyPressed(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
	{
		switch ( e->KeyCode )
		{
			case Keys::F8: AddColumn();
				break;

			case Keys::F9: button2->PerformClick();
				break;

			default:
				break;
		}
	}


	//заполнение пустых Var
	private: void FillEmptyVars(String^ str)
	{
		for ( int i = 0; i < dataGridView1->RowCount - 1; i++ )
			for ( int j = 0; j < dataGridView1->ColumnCount; j++ )
			{
				if ( dataGridView1->Rows[i]->Cells[j]->Value == nullptr || String::IsNullOrEmpty(dataGridView1->Rows[i]->Cells[j]->Value->ToString()) )
					dataGridView1->Rows[i]->Cells[j]->Value = str;
			}
	}



	private: void ExchangeVars()
	{
		List<List<String^>^>^ tmp = gcnew List<List<String^>^>(prevVars);
		prevVars = gcnew List<List<String^>^>(LoadFromTable());
		LoadToTable(tmp);
	}


	public: void Clear()
	{
		SafeSymbols->Checked = false;
		CurrentChanging = true;
		dataGridView1->Rows->Clear();
		while ( dataGridView1->ColumnCount > 0 )
		{
			dataGridView1->Columns->RemoveAt(0);
		}

		if ( dataGridView1->ColumnCount < 1 ) AddColumn();
		CurrentChanging = false;
	}

#pragma endregion

	
	// запомнить Vars
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
	{		
		SaveSettings();
		this->Hide();
		saveVars();
	}


	public: void saveVars()
	{
		List<String^>^ tmp;
		vars->Clear();
		try
		{
			for (int i = 0; i < dataGridView1->RowCount - 1; i++)
			{
				tmp = gcnew List<String^>();
				for (int j = 0; j < dataGridView1->ColumnCount; j++)
					tmp->Add(Convert::ToString(dataGridView1["Var" + j.ToString(), i]->Value));
				vars->Add(tmp);
			}
		}
		catch (Exception^ e)
		{
			ShowError(326, "Ошибка при сохранении списка Var\nПодробнее:\n" + e->ToString());
		}
	}
	
	// удаление стобца
	private: System::Void deleteVar_Click(System::Object^  sender, System::EventArgs^  e)
	{
		SafeSymbols->Checked = false;
		CurrentChanging = true;
		dataGridView1->Columns->RemoveAt(dataGridView1->CurrentCell->ColumnIndex);
		ReorderColumns();
		CurrentChanging = false;
	}


	// перемещение
	private: System::Void dataGridView1_ColumnDisplayIndexChanged(System::Object^  sender, System::Windows::Forms::DataGridViewColumnEventArgs^  e)
	{
		SafeSymbols->Checked = false;
		ReorderColumns();
	}

	
	// сохранение предыдущего значения редактируемой ячейки
	private: System::Void dataGridView1_CellBeginEdit(System::Object^  sender, System::Windows::Forms::DataGridViewCellCancelEventArgs^  e)
	{
		dataGridView1[e->ColumnIndex, e->RowIndex]->Style->BackColor = Color::LightYellow;

		prevCell->Value = Convert::ToString(dataGridView1[e->ColumnIndex, e->RowIndex]->Value);
		prevCell->Row = e->RowIndex;
		prevCell->Column = e->ColumnIndex;
	}


	private: System::Void dataGridView1_CellEndEdit(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
	{
		dataGridView1[e->ColumnIndex, e->RowIndex]->Style->BackColor = SystemColors::Window;

		if ( (e->RowIndex < 0) || CurrentChanging ) return;
		WrapCells();
	}


	private: System::Void insertRow_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if ( dataGridView1->CurrentRow->Index + 1 < dataGridView1->RowCount) dataGridView1->Rows->Insert(dataGridView1->CurrentRow->Index+1, 1);
		else dataGridView1->Rows->Add();
	}


	// безопасные символы Var
	private: System::Void SafeSymbols_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
	{
		if ( SafeChanged )
		{
			SafeChanged = false;
			return;
		}

		CurrentChanging = true;

		try
		{
			if ( !ValueChanged && forSafe )
			{
				// заменить таблицу на prevVars и наоборот
				ExchangeVars();
				return;
			}

			// записать таблицу в prevVars и заменить символы в таблице
			forSafe = true;
			prevVars = gcnew List<List<String^>^>(LoadFromTable());
			for ( int i = 0; i < dataGridView1->RowCount - 1; i++ )
				for ( int j = 0; j < dataGridView1->ColumnCount; j++ )
					if ( dataGridView1->Rows[i]->Cells[j]->Value != nullptr )
						dataGridView1->Rows[i]->Cells[j]->Value = Translate(dataGridView1->Rows[i]->Cells[j]->Value->ToString());
		}
		catch ( Exception^ e )
		{
			ShowError(327, "Ошибка при обработке данных таблицы\nПодробнее:\n" + e->ToString());
		}

		ValueChanged = false;
		CurrentChanging = false;
	}


	private: System::Void dataGridView1_CellValueChanged(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
	{
		ValueChanged = !CurrentChanging;
		if ( !CurrentChanging ) SafeSymbols->Checked = false;
	}

	private: System::Void checkBox2_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
	{
		if ( !ValueChanged && !forSafe ) ExchangeVars();
		else
			if ( checkBox2->Checked )
			{
				forSafe = false;
				CurrentChanging = true;
				prevVars = gcnew List<List<String^>^>(LoadFromTable());
				FillEmptyVars(emptyVar->Text);
				ValueChanged = false;
				CurrentChanging = false;
			}
		SafeChanged = false;
	}


	void SaveSettings()
	{
		Settings^ settings = gcnew Settings();

		settings->Set("Height", this->Height);
		settings->Set("Width", this->Width);
		settings->Set("Left", this->DesktopLocation.X);
		settings->Set("Top", this->DesktopLocation.Y);
		if ( this->WindowState == Forms::FormWindowState::Maximized ) settings->Set("State", 2); else settings->Set("State", 0);
		settings->Set("SeparateVars", checkBox1->Checked);
		settings->Set("ReplaceEmptyVars", checkBox2->Checked);
		settings->Set("EmptyVarsString", emptyVar->Text);

		if ( !settings->Save("VarForm") ) ShowWarning("Ошибка. Настройки не были сохранены.");
	}


	// загрузка настроек
	private: System::Void VarForm_Shown(System::Object^  sender, System::EventArgs^  e)
	{
		Settings^ settings = gcnew Settings();
		if ( !settings->Exist("VarForm") ) return;

		if ( settings->Read("VarForm") > 0 )
		{
			try
			{
				this->Height = settings->Get("Height", true);
				this->Width = settings->Get("Width", true);
				this->DesktopLocation = Point(settings->Get("Left", true), settings->Get("Top", true));
				this->WindowState = (Forms::FormWindowState)settings->Get("State", true);
				checkBox1->Checked = settings->Get("SeparateVars", true);
				checkBox2->Checked = settings->Get("ReplaceEmptyVars", true);
				emptyVar->Text = settings->Get("EmptyVarsString");
			}
			catch ( Exception^ e )
			{
				ShowWarning("Ошибка загрузки настроек");
			}
		}
	}


	// очистка таблицы
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e)
	{
		Clear();
	}

	
	// добавить столбец
	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e)
	{
		CurrentChanging = true;
		AddColumn();
		SafeSymbols->Checked = false;
		CurrentChanging = false;
	}


	private: System::Void удалитьНумерациюToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if ( !ValueChanged ) return;
		for ( int i = 0; i < dataGridView1->RowCount - 1; i++ )
			for ( int j = 0; j < dataGridView1->ColumnCount; j++ )
				if ( dataGridView1->Rows[i]->Cells[j]->Value != nullptr )
					dataGridView1->Rows[i]->Cells[j]->Value = ClearString(dataGridView1->Rows[i]->Cells[j]->Value->ToString(), true, true, false);
	}


	private: System::Void удалитьСтрокуToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if ( dataGridView1->Rows->Count < 2 ) return;
		try
		{
			List<DataGridViewRow^>^ rows = gcnew List<DataGridViewRow^>();
			DataGridViewRow^ r = gcnew DataGridViewRow();
			for each (DataGridViewTextBoxCell^ c in dataGridView1->SelectedCells)
			{
				r = dataGridView1->Rows[c->RowIndex];
				if ( !rows->Contains(r) ) rows->Add(r);
			}

			for each (DataGridViewRow^ rt in rows)
			{
				dataGridView1->Rows->Remove(rt);
			}
		}
		catch ( Exception^ e )
		{
			ShowError(332, "Ошибка удаления строки. \n\nПодробнее:\n" + e->ToString());
		}
	}


	


};