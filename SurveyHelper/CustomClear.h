#pragma once

#include "Funuctions.h"
#include "Classes.h"
#include "ReplaceDebugWindow.h"


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Text;
using namespace System::Text::RegularExpressions;
using namespace System::Web;
using namespace System::ComponentModel;
using namespace CustomTemplates;


public ref class CustomClear : public System::Windows::Forms::Form
{
	public:
		CustomClear(void)
		{
			InitializeComponent();
			dataGridView1->Columns["IsCustom"]->ValueType = Type::GetType("System.Boolean");
		}


public:	
	CustomTemplateList^  templates = gcnew CustomTemplateList();
	int rowIndexFromMouseDown;
	ReplaceDebugWindow^ ReplaceForm;
	DataGridViewRow^ rw;
	bool updateNeed = false;
	bool drag = false;
	String^ curVers = "";
 


private:

	~CustomClear()
		{
			if (components)
			{
				delete components;
			}
		}
	 System::ComponentModel::IContainer^  components;



#pragma region Windows Form Designer generated code



private: System::Windows::Forms::Label^  label2;
private: System::Windows::Forms::DataGridViewCheckBoxColumn^  On;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  from;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  to;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  IsCustom;
private: System::Windows::Forms::Label^  label3;
private: System::Windows::Forms::Label^  label1;
private: System::Windows::Forms::ToolTip^  toolTip1;
private: System::Windows::Forms::Button^  button4;
private: System::Windows::Forms::Button^  button5;
private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
private: System::Windows::Forms::CheckBox^  selectAll;
private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
private: System::Windows::Forms::Button^  button1;
private: System::Windows::Forms::Button^  button2;
private: System::Windows::Forms::Button^  button3;



public: System::Windows::Forms::DataGridView^  dataGridView1;




		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(CustomClear::typeid));
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->selectAll = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->On = (gcnew System::Windows::Forms::DataGridViewCheckBoxColumn());
			this->from = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->to = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->IsCustom = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->tableLayoutPanel1->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->tableLayoutPanel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				120)));
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel3, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->dataGridView1, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->label3, 1, 0);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 9.556314F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 90.44369F)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(674, 304);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 1;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel3->Controls->Add(this->button1, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->button2, 0, 1);
			this->tableLayoutPanel3->Controls->Add(this->button3, 0, 2);
			this->tableLayoutPanel3->Controls->Add(this->button5, 0, 5);
			this->tableLayoutPanel3->Controls->Add(this->button4, 0, 4);
			this->tableLayoutPanel3->Controls->Add(this->label2, 0, 3);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Location = System::Drawing::Point(557, 32);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 6;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 32)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 32)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 32)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 32)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 32)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(114, 269);
			this->tableLayoutPanel3->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->button1->Location = System::Drawing::Point(3, 4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(108, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Добавить";
			this->toolTip1->SetToolTip(this->button1, L"Добавить строку");
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &CustomClear::button1_Click);
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->button2->Location = System::Drawing::Point(3, 36);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(108, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Удалить";
			this->toolTip1->SetToolTip(this->button2, L"Удалить выделенную строку");
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &CustomClear::button2_Click);
			// 
			// button3
			// 
			this->button3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->button3->Location = System::Drawing::Point(3, 68);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(108, 23);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Отладка";
			this->toolTip1->SetToolTip(this->button3, L"Проверка работы текущего\r\nнабора автозамен");
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &CustomClear::button3_Click);
			// 
			// button5
			// 
			this->button5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->button5->Location = System::Drawing::Point(3, 241);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(108, 23);
			this->button5->TabIndex = 4;
			this->button5->Text = L"Импорт";
			this->toolTip1->SetToolTip(this->button5, L"Загрузить из файла");
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &CustomClear::button5_Click);
			// 
			// button4
			// 
			this->button4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->button4->Location = System::Drawing::Point(3, 209);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(108, 23);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Экспорт";
			this->toolTip1->SetToolTip(this->button4, L"Сохранить в файл");
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &CustomClear::button4_Click);
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->ForeColor = System::Drawing::Color::Red;
			this->label2->Location = System::Drawing::Point(3, 96);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(108, 109);
			this->label2->TabIndex = 6;
			this->label2->Text = L"Подождите,\r\nидёт\r\nобновление...";
			this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label2->Visible = false;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				42.69231F)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				57.30769F)));
			this->tableLayoutPanel2->Controls->Add(this->selectAll, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->label1, 1, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(3, 3);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 1;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(548, 23);
			this->tableLayoutPanel2->TabIndex = 1;
			// 
			// selectAll
			// 
			this->selectAll->AutoSize = true;
			this->selectAll->Location = System::Drawing::Point(3, 3);
			this->selectAll->Name = L"selectAll";
			this->selectAll->Size = System::Drawing::Size(131, 17);
			this->selectAll->TabIndex = 0;
			this->selectAll->Text = L"Выделить/снять все";
			this->selectAll->UseVisualStyleBackColor = true;
			this->selectAll->CheckedChanged += gcnew System::EventHandler(this, &CustomClear::selectAll_CheckedChanged);
			// 
			// label1
			// 
			this->label1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(236, 3);
			this->label1->Margin = System::Windows::Forms::Padding(3);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(154, 17);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Перетаскивание: ALT + ЛКМ";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->toolTip1->SetToolTip(this->label1, L"Перетаскивание строк возможно \r\nпри зажатой клавише ALT");
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowDrop = true;
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dataGridView1->ClipboardCopyMode = System::Windows::Forms::DataGridViewClipboardCopyMode::Disable;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4)
			{
				this->On, this->from,
					this->to, this->IsCustom
			});
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView1->Location = System::Drawing::Point(3, 32);
			this->dataGridView1->MultiSelect = false;
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->Size = System::Drawing::Size(548, 269);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellEndEdit += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &CustomClear::dataGridView1_CellEndEdit);
			this->dataGridView1->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &CustomClear::dataGridView1_DragDrop);
			this->dataGridView1->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &CustomClear::dataGridView1_DragEnter);
			this->dataGridView1->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &CustomClear::dataGridView1_MouseClick);
			// 
			// On
			// 
			this->On->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::None;
			this->On->FalseValue = L"False";
			this->On->FillWeight = 20;
			this->On->Frozen = true;
			this->On->HeaderText = L"Вкл";
			this->On->Name = L"On";
			this->On->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->On->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			this->On->ToolTipText = L"Включение/выключение автозамены";
			this->On->TrueValue = L"True";
			this->On->Width = 30;
			// 
			// from
			// 
			this->from->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->from->DefaultCellStyle = dataGridViewCellStyle1;
			this->from->FillWeight = 40;
			this->from->HeaderText = L"Заменить";
			this->from->Name = L"from";
			this->from->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// to
			// 
			this->to->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->to->DefaultCellStyle = dataGridViewCellStyle2;
			this->to->FillWeight = 40;
			this->to->HeaderText = L"На";
			this->to->Name = L"to";
			this->to->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// IsCustom
			// 
			dataGridViewCellStyle3->Format = L"Boolean";
			dataGridViewCellStyle3->NullValue = L"True";
			this->IsCustom->DefaultCellStyle = dataGridViewCellStyle3;
			this->IsCustom->HeaderText = L"IsCustom";
			this->IsCustom->Name = L"IsCustom";
			this->IsCustom->ReadOnly = true;
			this->IsCustom->Visible = false;
			this->IsCustom->Width = 75;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Cursor = System::Windows::Forms::Cursors::Hand;
			this->label3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Underline, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->ForeColor = System::Drawing::Color::SteelBlue;
			this->label3->Location = System::Drawing::Point(589, 7);
			this->label3->Margin = System::Windows::Forms::Padding(35, 7, 35, 7);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(50, 15);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Справка";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			this->label3->Click += gcnew System::EventHandler(this, &CustomClear::label3_Click);
			// 
			// toolTip1
			// 
			this->toolTip1->IsBalloon = true;
			this->toolTip1->ShowAlways = true;
			// 
			// CustomClear
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(674, 304);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(659, 343);
			this->Name = L"CustomClear";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Настройка очистки текста";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &CustomClear::CustomClear_FormClosing);
			this->Load += gcnew System::EventHandler(this, &CustomClear::CustomClear_Load);
			this->Shown += gcnew System::EventHandler(this, &CustomClear::CustomClear_Shown);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel3->PerformLayout();
			this->tableLayoutPanel2->ResumeLayout(false);
			this->tableLayoutPanel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	
	void SaveValues()
	{
		try
		{
			dataGridView1->EndEdit();
			//dataGridView1->Sort(gcnew DataGridViewColumnSort(1, ListSortDirection::Descending));
			templates->Clear();
			for ( int i = 0; i < dataGridView1->RowCount; i++ )
			{
				if ( !dataGridView1->Rows[i]->Cells["from"]->Value ) continue;
				if ( !dataGridView1->Rows[i]->Cells["to"]->Value ) dataGridView1->Rows[i]->Cells[2]->Value = "";
				templates->Add(
					Convert::ToBoolean(dataGridView1->Rows[i]->Cells["on"]->Value),
					dataGridView1->Rows[i]->Cells["from"]->Value->ToString(),
					dataGridView1->Rows[i]->Cells["to"]->Value->ToString(),
					(bool)Convert::ToBoolean(dataGridView1->Rows[i]->Cells["IsCustom"]->Value));
			}
		}
		catch ( Exception^ e )
		{
			ShowError(426, "Ошибка сохранения шаблонов автозамены.\nПодробнее:\n\n"+e->ToString());
		}
		
	}

	void LoadToTable()
	{
		int n = 0;
		try
		{
			for each (CustomTemplate^ tmpl in templates)
			{
				n = dataGridView1->Rows->Add();
				dataGridView1->Rows[n]->Cells[0]->Value = tmpl->Active;
				dataGridView1->Rows[n]->Cells[1]->Value = tmpl->Key;
				dataGridView1->Rows[n]->Cells[2]->Value = tmpl->Value;
				dataGridView1->Rows[n]->Cells[3]->Value = tmpl->IsCustom;
			}
		}
		catch ( Exception^ e )
		{
			ShowError(427, "Ошибка загрузке шаблонов автозамены.\nПодробнее:\n\n" + e->ToString());
		}
	}

	private: System::Void CustomClear_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)
	{
		SaveValues();
		if (!CustomTemplates::Save(templates)) ShowError(212, "Ошибка сохранения настроек.");
		/*Settings^ sets = gcnew Settings();
		sets->Set("UpdateReplaceFile", updateNeed);
		sets->Save("MainForm");*/
	}

	private: System::Void selectAll_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
	{
		for each (DataGridViewRow^ row in dataGridView1->Rows)
			row->Cells[0]->Value = selectAll->Checked;
	}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		dataGridView1->Rows->Add();
		dataGridView1->Rows[dataGridView1->RowCount - 1]->Cells["on"]->Value = true;
		dataGridView1->Rows[dataGridView1->RowCount - 1]->Cells["IsCustom"]->Value = true;
	}

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e)
	{
		int n = dataGridView1->SelectedRows->Count;
		if ( n == 0 )
		{
			ShowMessage("Сначала выделите строки, которые надо удалить", MessageBoxIcon::Information);
			return;
		}

		if ( QuestionDialog::Show("Вы уверены, что хотите удалить " + n.ToString() + " строк?", "Подтвердите удаление", QuestionDialog::Buttons::YesNo, false)->DialogResult == QuestionDialog::Results::Yes )
			for each (DataGridViewRow^ row in dataGridView1->SelectedRows)
				dataGridView1->Rows->Remove(row);
	}

	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e)
	{
		SaveValues();
		ReplaceForm = gcnew ReplaceDebugWindow(templates);
		ReplaceForm->ShowDialog();
	}
	
	private: System::Void CustomClear_Load(System::Object^  sender, System::EventArgs^  e)
	{
		templates = CustomTemplates::Get();
		LoadToTable();
	}

	private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e)
	{
		SaveValues();
		SaveFileDialog^ saveFileDialog1 = gcnew SaveFileDialog;
		saveFileDialog1->DefaultExt = ".bin";
		saveFileDialog1->RestoreDirectory = true;
		if ( saveFileDialog1->ShowDialog() == Forms::DialogResult::OK )
			CustomTemplates::SaveAs(templates, saveFileDialog1->FileName);
	}

	private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e)
	{
		OpenFileDialog^ openDlg = gcnew OpenFileDialog();
		openDlg->Filter = "Бинарный файл|*.bin";
		if ( openDlg->ShowDialog() == Forms::DialogResult::OK )
		{
			dataGridView1->Rows->Clear();
			templates = CustomTemplates::GetFrom(openDlg->FileName);
			int n = 0;
			for each (CustomTemplate^ tmpl in templates)
			{
				n = dataGridView1->Rows->Add();
				dataGridView1->Rows[n]->Cells[0]->Value = tmpl->Active;
				dataGridView1->Rows[n]->Cells[1]->Value = tmpl->Key;
				dataGridView1->Rows[n]->Cells[2]->Value = tmpl->Value;
			}
		}
	}

	
#pragma region Перетаскивание строк

	private: System::Void dataGridView1_MouseClick(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		drag = this->ModifierKeys == Keys::Alt && dataGridView1->SelectedRows->Count == 1 && e->Button == Forms::MouseButtons::Left;
		if ( drag )
		{
			rw = dataGridView1->SelectedRows[0];
			rowIndexFromMouseDown = dataGridView1->SelectedRows[0]->Index;
			dataGridView1->DoDragDrop(rw, DragDropEffects::Move);
		}
	}


	private: System::Void dataGridView1_DragEnter(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e)
	{
		if ( drag )
		{
			e->Effect = DragDropEffects::Move;
		}
	}


	private: System::Void dataGridView1_DragDrop(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e)
	{
		if ( !drag ) return;
		Point clientPoint = dataGridView1->PointToClient(Point(e->X, e->Y));
		int rowIndexOfItemUnderMouseToDrop = dataGridView1->HitTest(clientPoint.X, clientPoint.Y)->RowIndex;
		if ( clientPoint.Y >= dataGridView1->GetCellDisplayRectangle(0, dataGridView1->RowCount - 1, false).Top + dataGridView1->GetCellDisplayRectangle(0, dataGridView1->RowCount - 1, false).Height )
			rowIndexOfItemUnderMouseToDrop = dataGridView1->RowCount - 1;

		if ( e->Effect == DragDropEffects::Move && rowIndexOfItemUnderMouseToDrop >= 0 )
		{
			dataGridView1->Rows->RemoveAt(rowIndexFromMouseDown);
			dataGridView1->Rows->Insert(rowIndexOfItemUnderMouseToDrop, rw);
		}
	}

#pragma endregion


	private: System::Void dataGridView1_CellEndEdit(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
	{
		updateNeed = true;
	}

	private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e)
	{
		OpenUrl(_appDataDir + L"\\Help.html?t=help&vers=" + curVers + "&t2=regex");
	}


	private: void UpdateTemplates()
	{
		label2->Visible = true;
		this->Update();
		SaveValues();

		CustomTemplateList^ tmp = gcnew CustomTemplateList();
		for each(CustomTemplate^ t in templates)
			if ( t->IsCustom ) tmp->Add(t);
		CustomTemplates::Save(tmp);
		templates->Clear();
		if ( File::Exists(_appDataDir + "\\CustomReplaceList.bin") )
			templates = GetFrom(_appDataDir + "\\CustomReplaceList.bin");
		if ( File::Exists(_appDataDir + "\\ReplaceList.bin") )
			templates->AddRange(GetFrom(_appDataDir + "\\ReplaceList.bin"));

		dataGridView1->Rows->Clear();
		LoadToTable();
		label2->Visible = false;
	}


	private: System::Void CustomClear_Shown(System::Object^  sender, System::EventArgs^  e)
	{
		Settings^ sets = gcnew Settings();
		sets->Read("");
		if ( sets->isWritten("TemplatesUpdated") && MessageBox::Show("Доступно обновление шаблонов!\nПри обновлении все стандартные шаблоны будут замены на новые, пользовательские останутся нетронутыми.\nОбновить сейчас?", "", Forms::MessageBoxButtons::YesNo, Forms::MessageBoxIcon::Question) == Forms::DialogResult::Yes )
		{
			UpdateTemplates();
			Settings::Remove("", "TemplatesUpdated");
			ShowMessage("", "Готово!", MessageBoxIcon::Information);
		}
	}

};




static CustomTemplateList^ GetActiveTemplates(String^ cv)
{
	CustomClear^ f = gcnew CustomClear();
	f->curVers = cv;
	f->ShowDialog();
	return f->templates->SelectActive();
}
