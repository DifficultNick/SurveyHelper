#pragma once
#include "Classes.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

public ref class PilotSyntax : public System::Windows::Forms::Form
{
	private:
	Settings ^ sets = gcnew Settings();
	private: System::Windows::Forms::CheckBox^  autoRun;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel6;
	private: System::Windows::Forms::CheckBox^  excelExp;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::RadioButton^  vals;
	private: System::Windows::Forms::RadioButton^  labs;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::CheckBox^  saveLength;
	private: System::Windows::Forms::CheckBox^  saveResp;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel9;
	private: System::Windows::Forms::CheckBox^  replaceOther;

	private: System::Windows::Forms::TextBox^  other;


			 ProjectResources^ rsc = gcnew ProjectResources();

	public: PilotSyntax()
	{
		InitializeComponent();
		this->panel4->BackgroundImage = rsc->GetImage("waiting_for_file");
		String^ dd = "_";
		sets->Read("SPSS");
		if (sets->isWritten("Delimiter")) dd = sets->Get("Delimiter");
		delimeter->Text = dd;
		repl->Checked = sets->Get("ReplaceDelimiter", true);
		autoRun->Checked = sets->Get("AutoRun", true);
		replaceOther->Checked = sets->Get("ReplaceCS", true);
	}




			#pragma region Windows Form Designer generated code
	protected:
	~PilotSyntax()
	{
		if (components)
		{
			delete components;
		}
	}


	protected:
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
	private: System::Windows::Forms::CheckBox^  renvar;
	private: System::Windows::Forms::CheckBox^  repl;


	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel4;
	private: System::Windows::Forms::CheckBox^  selstat;
	private: System::Windows::Forms::TextBox^  stats;


	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel5;
	private: System::Windows::Forms::CheckBox^  saveTime;

	private: System::Windows::Forms::CheckBox^  cutvars;









	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel7;
	private: System::Windows::Forms::Label^  StatusLabel;

	private: System::Windows::Forms::ProgressBar^  progressBar1;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::ToolTip^  toolTip1;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::TextBox^  FilePath;

	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel8;
	private: System::Windows::Forms::TextBox^  delimeter;

	private: System::ComponentModel::IContainer^  components;





			 void InitializeComponent(void)
			 {
				 this->components = (gcnew System::ComponentModel::Container());
				 System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(PilotSyntax::typeid));
				 this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
				 this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
				 this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
				 this->tableLayoutPanel9 = (gcnew System::Windows::Forms::TableLayoutPanel());
				 this->replaceOther = (gcnew System::Windows::Forms::CheckBox());
				 this->other = (gcnew System::Windows::Forms::TextBox());
				 this->tableLayoutPanel6 = (gcnew System::Windows::Forms::TableLayoutPanel());
				 this->excelExp = (gcnew System::Windows::Forms::CheckBox());
				 this->panel1 = (gcnew System::Windows::Forms::Panel());
				 this->vals = (gcnew System::Windows::Forms::RadioButton());
				 this->labs = (gcnew System::Windows::Forms::RadioButton());
				 this->renvar = (gcnew System::Windows::Forms::CheckBox());
				 this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
				 this->selstat = (gcnew System::Windows::Forms::CheckBox());
				 this->stats = (gcnew System::Windows::Forms::TextBox());
				 this->tableLayoutPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
				 this->saveTime = (gcnew System::Windows::Forms::CheckBox());
				 this->cutvars = (gcnew System::Windows::Forms::CheckBox());
				 this->tableLayoutPanel8 = (gcnew System::Windows::Forms::TableLayoutPanel());
				 this->delimeter = (gcnew System::Windows::Forms::TextBox());
				 this->repl = (gcnew System::Windows::Forms::CheckBox());
				 this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
				 this->saveLength = (gcnew System::Windows::Forms::CheckBox());
				 this->saveResp = (gcnew System::Windows::Forms::CheckBox());
				 this->panel2 = (gcnew System::Windows::Forms::Panel());
				 this->tableLayoutPanel7 = (gcnew System::Windows::Forms::TableLayoutPanel());
				 this->StatusLabel = (gcnew System::Windows::Forms::Label());
				 this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
				 this->panel3 = (gcnew System::Windows::Forms::Panel());
				 this->button1 = (gcnew System::Windows::Forms::Button());
				 this->FilePath = (gcnew System::Windows::Forms::TextBox());
				 this->panel4 = (gcnew System::Windows::Forms::Panel());
				 this->button2 = (gcnew System::Windows::Forms::Button());
				 this->autoRun = (gcnew System::Windows::Forms::CheckBox());
				 this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
				 this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
				 this->tableLayoutPanel2->SuspendLayout();
				 this->groupBox1->SuspendLayout();
				 this->tableLayoutPanel3->SuspendLayout();
				 this->tableLayoutPanel9->SuspendLayout();
				 this->tableLayoutPanel6->SuspendLayout();
				 this->panel1->SuspendLayout();
				 this->tableLayoutPanel4->SuspendLayout();
				 this->tableLayoutPanel5->SuspendLayout();
				 this->tableLayoutPanel8->SuspendLayout();
				 this->tableLayoutPanel1->SuspendLayout();
				 this->panel2->SuspendLayout();
				 this->tableLayoutPanel7->SuspendLayout();
				 this->panel3->SuspendLayout();
				 this->SuspendLayout();
				 // 
				 // tableLayoutPanel2
				 // 
				 this->tableLayoutPanel2->ColumnCount = 2;
				 this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
					 100)));
				 this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
					 184)));
				 this->tableLayoutPanel2->Controls->Add(this->groupBox1, 0, 1);
				 this->tableLayoutPanel2->Controls->Add(this->panel2, 0, 3);
				 this->tableLayoutPanel2->Controls->Add(this->panel3, 0, 0);
				 this->tableLayoutPanel2->Controls->Add(this->panel4, 1, 1);
				 this->tableLayoutPanel2->Controls->Add(this->button2, 1, 0);
				 this->tableLayoutPanel2->Controls->Add(this->autoRun, 0, 2);
				 this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
				 this->tableLayoutPanel2->Location = System::Drawing::Point(0, 0);
				 this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
				 this->tableLayoutPanel2->RowCount = 4;
				 this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 37)));
				 this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
				 this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 25)));
				 this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 22)));
				 this->tableLayoutPanel2->Size = System::Drawing::Size(635, 304);
				 this->tableLayoutPanel2->TabIndex = 1;
				 // 
				 // groupBox1
				 // 
				 this->groupBox1->Controls->Add(this->tableLayoutPanel3);
				 this->groupBox1->Dock = System::Windows::Forms::DockStyle::Fill;
				 this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(204)));
				 this->groupBox1->Location = System::Drawing::Point(3, 40);
				 this->groupBox1->Name = L"groupBox1";
				 this->groupBox1->Size = System::Drawing::Size(445, 214);
				 this->groupBox1->TabIndex = 0;
				 this->groupBox1->TabStop = false;
				 this->groupBox1->Text = L"Настройки";
				 // 
				 // tableLayoutPanel3
				 // 
				 this->tableLayoutPanel3->ColumnCount = 1;
				 this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
					 100)));
				 this->tableLayoutPanel3->Controls->Add(this->tableLayoutPanel9, 0, 6);
				 this->tableLayoutPanel3->Controls->Add(this->tableLayoutPanel6, 0, 5);
				 this->tableLayoutPanel3->Controls->Add(this->renvar, 0, 1);
				 this->tableLayoutPanel3->Controls->Add(this->tableLayoutPanel4, 0, 2);
				 this->tableLayoutPanel3->Controls->Add(this->tableLayoutPanel5, 0, 3);
				 this->tableLayoutPanel3->Controls->Add(this->tableLayoutPanel8, 0, 0);
				 this->tableLayoutPanel3->Controls->Add(this->tableLayoutPanel1, 0, 4);
				 this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
				 this->tableLayoutPanel3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
					 System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
				 this->tableLayoutPanel3->Location = System::Drawing::Point(3, 16);
				 this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
				 this->tableLayoutPanel3->RowCount = 7;
				 this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 28)));
				 this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 28)));
				 this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 28)));
				 this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 28)));
				 this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 26)));
				 this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 28)));
				 this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 28)));
				 this->tableLayoutPanel3->Size = System::Drawing::Size(439, 195);
				 this->tableLayoutPanel3->TabIndex = 0;
				 // 
				 // tableLayoutPanel9
				 // 
				 this->tableLayoutPanel9->ColumnCount = 2;
				 this->tableLayoutPanel9->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
					 229)));
				 this->tableLayoutPanel9->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
					 210)));
				 this->tableLayoutPanel9->Controls->Add(this->replaceOther, 0, 0);
				 this->tableLayoutPanel9->Controls->Add(this->other, 1, 0);
				 this->tableLayoutPanel9->Dock = System::Windows::Forms::DockStyle::Fill;
				 this->tableLayoutPanel9->Location = System::Drawing::Point(0, 166);
				 this->tableLayoutPanel9->Margin = System::Windows::Forms::Padding(0);
				 this->tableLayoutPanel9->Name = L"tableLayoutPanel9";
				 this->tableLayoutPanel9->RowCount = 1;
				 this->tableLayoutPanel9->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
				 this->tableLayoutPanel9->Size = System::Drawing::Size(439, 29);
				 this->tableLayoutPanel9->TabIndex = 10;
				 // 
				 // replaceOther
				 // 
				 this->replaceOther->AutoSize = true;
				 this->replaceOther->Dock = System::Windows::Forms::DockStyle::Bottom;
				 this->replaceOther->Location = System::Drawing::Point(3, 9);
				 this->replaceOther->Name = L"replaceOther";
				 this->replaceOther->Size = System::Drawing::Size(223, 17);
				 this->replaceOther->TabIndex = 4;
				 this->replaceOther->Text = L"Заменить \"{c#}\" на:";
				 this->replaceOther->UseVisualStyleBackColor = true;
				 // 
				 // other
				 // 
				 this->other->Dock = System::Windows::Forms::DockStyle::Left;
				 this->other->Location = System::Drawing::Point(232, 3);
				 this->other->Name = L"other";
				 this->other->Size = System::Drawing::Size(158, 20);
				 this->other->TabIndex = 5;
				 this->other->Text = L"Другое";
				 this->toolTip1->SetToolTip(this->other, L"Список статусов через запятую");
				 // 
				 // tableLayoutPanel6
				 // 
				 this->tableLayoutPanel6->ColumnCount = 2;
				 this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
					 229)));
				 this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
					 50)));
				 this->tableLayoutPanel6->Controls->Add(this->excelExp, 0, 0);
				 this->tableLayoutPanel6->Controls->Add(this->panel1, 1, 0);
				 this->tableLayoutPanel6->Dock = System::Windows::Forms::DockStyle::Fill;
				 this->tableLayoutPanel6->Location = System::Drawing::Point(0, 138);
				 this->tableLayoutPanel6->Margin = System::Windows::Forms::Padding(0);
				 this->tableLayoutPanel6->Name = L"tableLayoutPanel6";
				 this->tableLayoutPanel6->RowCount = 1;
				 this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
				 this->tableLayoutPanel6->Size = System::Drawing::Size(439, 28);
				 this->tableLayoutPanel6->TabIndex = 8;
				 // 
				 // excelExp
				 // 
				 this->excelExp->AutoSize = true;
				 this->excelExp->Dock = System::Windows::Forms::DockStyle::Bottom;
				 this->excelExp->Location = System::Drawing::Point(3, 8);
				 this->excelExp->Name = L"excelExp";
				 this->excelExp->Size = System::Drawing::Size(223, 17);
				 this->excelExp->TabIndex = 6;
				 this->excelExp->Text = L"Экспортировать в Excel";
				 this->excelExp->UseVisualStyleBackColor = true;
				 // 
				 // panel1
				 // 
				 this->panel1->Controls->Add(this->vals);
				 this->panel1->Controls->Add(this->labs);
				 this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
				 this->panel1->Location = System::Drawing::Point(229, 0);
				 this->panel1->Margin = System::Windows::Forms::Padding(0);
				 this->panel1->Name = L"panel1";
				 this->panel1->Size = System::Drawing::Size(210, 28);
				 this->panel1->TabIndex = 7;
				 // 
				 // vals
				 // 
				 this->vals->AutoSize = true;
				 this->vals->Location = System::Drawing::Point(77, 6);
				 this->vals->Name = L"vals";
				 this->vals->Size = System::Drawing::Size(73, 17);
				 this->vals->TabIndex = 1;
				 this->vals->Text = L"Значения";
				 this->vals->UseVisualStyleBackColor = true;
				 // 
				 // labs
				 // 
				 this->labs->AutoSize = true;
				 this->labs->Checked = true;
				 this->labs->Location = System::Drawing::Point(3, 6);
				 this->labs->Name = L"labs";
				 this->labs->Size = System::Drawing::Size(57, 17);
				 this->labs->TabIndex = 0;
				 this->labs->TabStop = true;
				 this->labs->Text = L"Метки";
				 this->labs->UseVisualStyleBackColor = true;
				 // 
				 // renvar
				 // 
				 this->renvar->AutoSize = true;
				 this->renvar->Checked = true;
				 this->renvar->CheckState = System::Windows::Forms::CheckState::Checked;
				 this->renvar->Dock = System::Windows::Forms::DockStyle::Bottom;
				 this->renvar->Location = System::Drawing::Point(3, 36);
				 this->renvar->Name = L"renvar";
				 this->renvar->Size = System::Drawing::Size(433, 17);
				 this->renvar->TabIndex = 3;
				 this->renvar->Text = L"Переименовать переменные pre_sex и pre_age_1";
				 this->renvar->UseVisualStyleBackColor = true;
				 // 
				 // tableLayoutPanel4
				 // 
				 this->tableLayoutPanel4->ColumnCount = 2;
				 this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
					 229)));
				 this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
					 210)));
				 this->tableLayoutPanel4->Controls->Add(this->selstat, 0, 0);
				 this->tableLayoutPanel4->Controls->Add(this->stats, 1, 0);
				 this->tableLayoutPanel4->Dock = System::Windows::Forms::DockStyle::Fill;
				 this->tableLayoutPanel4->Location = System::Drawing::Point(0, 56);
				 this->tableLayoutPanel4->Margin = System::Windows::Forms::Padding(0);
				 this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
				 this->tableLayoutPanel4->RowCount = 1;
				 this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
				 this->tableLayoutPanel4->Size = System::Drawing::Size(439, 28);
				 this->tableLayoutPanel4->TabIndex = 4;
				 // 
				 // selstat
				 // 
				 this->selstat->AutoSize = true;
				 this->selstat->Checked = true;
				 this->selstat->CheckState = System::Windows::Forms::CheckState::Checked;
				 this->selstat->Dock = System::Windows::Forms::DockStyle::Bottom;
				 this->selstat->Location = System::Drawing::Point(3, 8);
				 this->selstat->Name = L"selstat";
				 this->selstat->Size = System::Drawing::Size(223, 17);
				 this->selstat->TabIndex = 4;
				 this->selstat->Text = L"Выбрать статусы:";
				 this->selstat->UseVisualStyleBackColor = true;
				 // 
				 // stats
				 // 
				 this->stats->Dock = System::Windows::Forms::DockStyle::Left;
				 this->stats->Location = System::Drawing::Point(232, 3);
				 this->stats->Name = L"stats";
				 this->stats->Size = System::Drawing::Size(158, 20);
				 this->stats->TabIndex = 5;
				 this->stats->Text = L"18";
				 this->toolTip1->SetToolTip(this->stats, L"Список статусов через запятую");
				 // 
				 // tableLayoutPanel5
				 // 
				 this->tableLayoutPanel5->ColumnCount = 2;
				 this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
					 229)));
				 this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
					 100)));
				 this->tableLayoutPanel5->Controls->Add(this->saveTime, 0, 0);
				 this->tableLayoutPanel5->Controls->Add(this->cutvars, 0, 0);
				 this->tableLayoutPanel5->Dock = System::Windows::Forms::DockStyle::Fill;
				 this->tableLayoutPanel5->Location = System::Drawing::Point(0, 84);
				 this->tableLayoutPanel5->Margin = System::Windows::Forms::Padding(0);
				 this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
				 this->tableLayoutPanel5->RowCount = 1;
				 this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
				 this->tableLayoutPanel5->Size = System::Drawing::Size(439, 28);
				 this->tableLayoutPanel5->TabIndex = 5;
				 // 
				 // saveTime
				 // 
				 this->saveTime->AutoSize = true;
				 this->saveTime->Dock = System::Windows::Forms::DockStyle::Bottom;
				 this->saveTime->Location = System::Drawing::Point(232, 8);
				 this->saveTime->Name = L"saveTime";
				 this->saveTime->Size = System::Drawing::Size(204, 17);
				 this->saveTime->TabIndex = 7;
				 this->saveTime->Text = L"Оставить Start и End";
				 this->saveTime->UseVisualStyleBackColor = true;
				 // 
				 // cutvars
				 // 
				 this->cutvars->AutoSize = true;
				 this->cutvars->Checked = true;
				 this->cutvars->CheckState = System::Windows::Forms::CheckState::Checked;
				 this->cutvars->Dock = System::Windows::Forms::DockStyle::Bottom;
				 this->cutvars->Location = System::Drawing::Point(3, 8);
				 this->cutvars->Name = L"cutvars";
				 this->cutvars->Size = System::Drawing::Size(223, 17);
				 this->cutvars->TabIndex = 6;
				 this->cutvars->Text = L"Отрезать технические переменные";
				 this->cutvars->UseVisualStyleBackColor = true;
				 // 
				 // tableLayoutPanel8
				 // 
				 this->tableLayoutPanel8->ColumnCount = 2;
				 this->tableLayoutPanel8->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
					 229)));
				 this->tableLayoutPanel8->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
					 206)));
				 this->tableLayoutPanel8->Controls->Add(this->delimeter, 1, 0);
				 this->tableLayoutPanel8->Controls->Add(this->repl, 0, 0);
				 this->tableLayoutPanel8->Dock = System::Windows::Forms::DockStyle::Fill;
				 this->tableLayoutPanel8->Location = System::Drawing::Point(2, 0);
				 this->tableLayoutPanel8->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
				 this->tableLayoutPanel8->Name = L"tableLayoutPanel8";
				 this->tableLayoutPanel8->RowCount = 1;
				 this->tableLayoutPanel8->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
				 this->tableLayoutPanel8->Size = System::Drawing::Size(435, 28);
				 this->tableLayoutPanel8->TabIndex = 7;
				 // 
				 // delimeter
				 // 
				 this->delimeter->Location = System::Drawing::Point(231, 2);
				 this->delimeter->Margin = System::Windows::Forms::Padding(2);
				 this->delimeter->MaxLength = 1;
				 this->delimeter->Name = L"delimeter";
				 this->delimeter->Size = System::Drawing::Size(27, 20);
				 this->delimeter->TabIndex = 0;
				 this->delimeter->Text = L"_";
				 this->delimeter->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
				 this->toolTip1->SetToolTip(this->delimeter, L"Разделитель");
				 // 
				 // repl
				 // 
				 this->repl->AutoSize = true;
				 this->repl->Checked = true;
				 this->repl->CheckState = System::Windows::Forms::CheckState::Checked;
				 this->repl->Location = System::Drawing::Point(3, 3);
				 this->repl->Name = L"repl";
				 this->repl->Size = System::Drawing::Size(115, 17);
				 this->repl->TabIndex = 0;
				 this->repl->Text = L"Заменить \"@\" на";
				 this->repl->UseVisualStyleBackColor = true;
				 // 
				 // tableLayoutPanel1
				 // 
				 this->tableLayoutPanel1->ColumnCount = 2;
				 this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
					 229)));
				 this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
					 100)));
				 this->tableLayoutPanel1->Controls->Add(this->saveLength, 1, 0);
				 this->tableLayoutPanel1->Controls->Add(this->saveResp, 0, 0);
				 this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
				 this->tableLayoutPanel1->Location = System::Drawing::Point(0, 112);
				 this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(0);
				 this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
				 this->tableLayoutPanel1->RowCount = 1;
				 this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
				 this->tableLayoutPanel1->Size = System::Drawing::Size(439, 26);
				 this->tableLayoutPanel1->TabIndex = 9;
				 // 
				 // saveLength
				 // 
				 this->saveLength->AutoSize = true;
				 this->saveLength->Dock = System::Windows::Forms::DockStyle::Bottom;
				 this->saveLength->Location = System::Drawing::Point(232, 6);
				 this->saveLength->Name = L"saveLength";
				 this->saveLength->Size = System::Drawing::Size(204, 17);
				 this->saveLength->TabIndex = 1;
				 this->saveLength->Text = L"Оставить Length";
				 this->saveLength->UseVisualStyleBackColor = true;
				 // 
				 // saveResp
				 // 
				 this->saveResp->AutoSize = true;
				 this->saveResp->Dock = System::Windows::Forms::DockStyle::Bottom;
				 this->saveResp->Location = System::Drawing::Point(3, 6);
				 this->saveResp->Name = L"saveResp";
				 this->saveResp->Size = System::Drawing::Size(223, 17);
				 this->saveResp->TabIndex = 0;
				 this->saveResp->Text = L"Оставить Respondent";
				 this->saveResp->UseVisualStyleBackColor = true;
				 // 
				 // panel2
				 // 
				 this->panel2->BackColor = System::Drawing::SystemColors::AppWorkspace;
				 this->tableLayoutPanel2->SetColumnSpan(this->panel2, 2);
				 this->panel2->Controls->Add(this->tableLayoutPanel7);
				 this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
				 this->panel2->Location = System::Drawing::Point(0, 282);
				 this->panel2->Margin = System::Windows::Forms::Padding(0);
				 this->panel2->Name = L"panel2";
				 this->panel2->Size = System::Drawing::Size(635, 22);
				 this->panel2->TabIndex = 1;
				 // 
				 // tableLayoutPanel7
				 // 
				 this->tableLayoutPanel7->BackColor = System::Drawing::Color::White;
				 this->tableLayoutPanel7->ColumnCount = 2;
				 this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
					 51.20148F)));
				 this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
					 48.79852F)));
				 this->tableLayoutPanel7->Controls->Add(this->StatusLabel, 0, 0);
				 this->tableLayoutPanel7->Controls->Add(this->progressBar1, 1, 0);
				 this->tableLayoutPanel7->Dock = System::Windows::Forms::DockStyle::Fill;
				 this->tableLayoutPanel7->Location = System::Drawing::Point(0, 0);
				 this->tableLayoutPanel7->Name = L"tableLayoutPanel7";
				 this->tableLayoutPanel7->RowCount = 1;
				 this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
				 this->tableLayoutPanel7->Size = System::Drawing::Size(635, 22);
				 this->tableLayoutPanel7->TabIndex = 0;
				 // 
				 // StatusLabel
				 // 
				 this->StatusLabel->AutoSize = true;
				 this->StatusLabel->Dock = System::Windows::Forms::DockStyle::Bottom;
				 this->StatusLabel->ForeColor = System::Drawing::Color::Gray;
				 this->StatusLabel->Location = System::Drawing::Point(3, 6);
				 this->StatusLabel->Margin = System::Windows::Forms::Padding(3, 0, 3, 3);
				 this->StatusLabel->Name = L"StatusLabel";
				 this->StatusLabel->Size = System::Drawing::Size(319, 13);
				 this->StatusLabel->TabIndex = 0;
				 this->StatusLabel->Text = L"Выберите файл";
				 // 
				 // progressBar1
				 // 
				 this->progressBar1->Dock = System::Windows::Forms::DockStyle::Fill;
				 this->progressBar1->Location = System::Drawing::Point(328, 3);
				 this->progressBar1->Name = L"progressBar1";
				 this->progressBar1->Size = System::Drawing::Size(304, 16);
				 this->progressBar1->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
				 this->progressBar1->TabIndex = 1;
				 this->toolTip1->SetToolTip(this->progressBar1, L"Процесс выполнения");
				 // 
				 // panel3
				 // 
				 this->panel3->Controls->Add(this->button1);
				 this->panel3->Controls->Add(this->FilePath);
				 this->panel3->Dock = System::Windows::Forms::DockStyle::Fill;
				 this->panel3->Location = System::Drawing::Point(3, 3);
				 this->panel3->Name = L"panel3";
				 this->panel3->Size = System::Drawing::Size(445, 31);
				 this->panel3->TabIndex = 2;
				 // 
				 // button1
				 // 
				 this->button1->Location = System::Drawing::Point(337, 5);
				 this->button1->Margin = System::Windows::Forms::Padding(2);
				 this->button1->Name = L"button1";
				 this->button1->Size = System::Drawing::Size(56, 20);
				 this->button1->TabIndex = 1;
				 this->button1->Text = L"Обзор";
				 this->button1->UseVisualStyleBackColor = true;
				 this->button1->Click += gcnew System::EventHandler(this, &PilotSyntax::button1_Click);
				 // 
				 // FilePath
				 // 
				 this->FilePath->Location = System::Drawing::Point(3, 6);
				 this->FilePath->Margin = System::Windows::Forms::Padding(2);
				 this->FilePath->Name = L"FilePath";
				 this->FilePath->Size = System::Drawing::Size(330, 20);
				 this->FilePath->TabIndex = 0;
				 this->FilePath->TextChanged += gcnew System::EventHandler(this, &PilotSyntax::FilePath_TextChanged);
				 this->FilePath->DoubleClick += gcnew System::EventHandler(this, &PilotSyntax::FilePath_DoubleClick);
				 // 
				 // panel4
				 // 
				 this->panel4->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->panel4->BackColor = System::Drawing::Color::White;
				 this->panel4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
				 this->panel4->Location = System::Drawing::Point(461, 71);
				 this->panel4->Name = L"panel4";
				 this->panel4->Size = System::Drawing::Size(164, 151);
				 this->panel4->TabIndex = 4;
				 // 
				 // button2
				 // 
				 this->button2->Anchor = System::Windows::Forms::AnchorStyles::None;
				 this->button2->Enabled = false;
				 this->button2->Location = System::Drawing::Point(492, 6);
				 this->button2->Margin = System::Windows::Forms::Padding(2);
				 this->button2->Name = L"button2";
				 this->button2->Size = System::Drawing::Size(102, 25);
				 this->button2->TabIndex = 5;
				 this->button2->Text = L"Создать!";
				 this->button2->UseVisualStyleBackColor = true;
				 this->button2->Click += gcnew System::EventHandler(this, &PilotSyntax::button2_Click);
				 // 
				 // autoRun
				 // 
				 this->autoRun->AutoSize = true;
				 this->autoRun->Checked = true;
				 this->autoRun->CheckState = System::Windows::Forms::CheckState::Checked;
				 this->autoRun->Location = System::Drawing::Point(9, 259);
				 this->autoRun->Margin = System::Windows::Forms::Padding(9, 2, 2, 2);
				 this->autoRun->Name = L"autoRun";
				 this->autoRun->Size = System::Drawing::Size(150, 17);
				 this->autoRun->TabIndex = 6;
				 this->autoRun->Text = L"Открыть по завершении";
				 this->toolTip1->SetToolTip(this->autoRun, L"Открыть файл .sps при успешном выполнении");
				 this->autoRun->UseVisualStyleBackColor = true;
				 // 
				 // toolTip1
				 // 
				 this->toolTip1->IsBalloon = true;
				 // 
				 // openFileDialog1
				 // 
				 this->openFileDialog1->DefaultExt = L"sps";
				 this->openFileDialog1->Filter = L"Файл spss-синтаксиса|*.sps";
				 // 
				 // PilotSyntax
				 // 
				 this->AllowDrop = true;
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(635, 304);
				 this->Controls->Add(this->tableLayoutPanel2);
				 this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
				 this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
				 this->MaximizeBox = false;
				 this->MinimizeBox = false;
				 this->Name = L"PilotSyntax";
				 this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
				 this->Text = L"Синтаксис для SPSS базы";
				 this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &PilotSyntax::PilotSyntax_FormClosing);
				 this->Shown += gcnew System::EventHandler(this, &PilotSyntax::PilotSyntax_Shown);
				 this->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &PilotSyntax::FormDragDrop);
				 this->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &PilotSyntax::FormDragEnter);
				 this->DragLeave += gcnew System::EventHandler(this, &PilotSyntax::FormDragLeave);
				 this->tableLayoutPanel2->ResumeLayout(false);
				 this->tableLayoutPanel2->PerformLayout();
				 this->groupBox1->ResumeLayout(false);
				 this->tableLayoutPanel3->ResumeLayout(false);
				 this->tableLayoutPanel3->PerformLayout();
				 this->tableLayoutPanel9->ResumeLayout(false);
				 this->tableLayoutPanel9->PerformLayout();
				 this->tableLayoutPanel6->ResumeLayout(false);
				 this->tableLayoutPanel6->PerformLayout();
				 this->panel1->ResumeLayout(false);
				 this->panel1->PerformLayout();
				 this->tableLayoutPanel4->ResumeLayout(false);
				 this->tableLayoutPanel4->PerformLayout();
				 this->tableLayoutPanel5->ResumeLayout(false);
				 this->tableLayoutPanel5->PerformLayout();
				 this->tableLayoutPanel8->ResumeLayout(false);
				 this->tableLayoutPanel8->PerformLayout();
				 this->tableLayoutPanel1->ResumeLayout(false);
				 this->tableLayoutPanel1->PerformLayout();
				 this->panel2->ResumeLayout(false);
				 this->tableLayoutPanel7->ResumeLayout(false);
				 this->tableLayoutPanel7->PerformLayout();
				 this->panel3->ResumeLayout(false);
				 this->panel3->PerformLayout();
				 this->ResumeLayout(false);

			 }
			 #pragma endregion




	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e)
	{
		progressBar1->Value = 0;
		StatusLabel->Text = "Выберите файл";

		if (!File::Exists(FilePath->Text))
		{
			ShowMessage("Сначала выберите файл!", Forms::MessageBoxIcon::Exclamation);
			ResetAll(true);
			return;
		}

		if (selstat->Checked && !Regex::IsMatch(stats->Text, "^(\\d{1,3}\\s*,?\\s*)*(\\d{1,3}\\s*)+$"))
		{
			ShowWarning("Неверно указан список статусов!");
			progressBar1->Value = 0;
			StatusLabel->Text = "Укажите список статусов";
			Update();
			return;
		}

		try
		{
			StatusLabel->Text = "Загрузка файла...";
			Update();

			array<String^>^ ar = File::ReadAllLines(FilePath->Text, System::Text::Encoding::GetEncoding(1251));

			progressBar1->Value = 30;
			StatusLabel->Text = "Сбор сведений...";
			Update();

			String^ s = String::Join("\n", ar);
			int vrInd = s->IndexOf("var lab");

			if (s->IndexOf("val lab") < 0 || vrInd < 0)
			{
				ShowWarning("Содержимое файла не распознано, как SPSS синтаксис!");
				ResetAll(false);
				return;
			}

			String^ del;
			auto delRes = Regex::Match(s, "\npre_age(.)1");
			// ищем настоящий разделитель
			if (!!delRes && delRes->Length > 0)
				del = delRes->Groups[1]->Value;
			else del = repl->Checked ? delimeter->Text : "@";
			String^ vars = s->Remove(vrInd);
			String^ fp = Regex::Replace(FilePath->Text, "\\.sps$", "");
			String^ fn = Regex::Replace(Path::GetFileName(FilePath->Text), "\\.sps", "");
			String^ dv = "";
			String^ load = Regex::IsMatch(Path::GetFileName(fp), "load", RegexOptions::IgnoreCase) ? "" : "_load";

			progressBar1->Value = 40;
			StatusLabel->Text = "Добавление команд...";
			Update();

			//путь в FILE HANDLE
			String^ txtP = Path::GetDirectoryName(fp);
			if (txtP == "")
			{
				ResetAll(false);
				return;
			}
			s = Regex::Replace(s, "(?<pre>FILE HANDLE\\s*[^'\"]*NAME\\s*=\\s*['\"])([^'\"]*)(?<post>['\"][^\n]*\n)", "${pre}" + txtP + "${post}");

			int eof = s->IndexOf("\n**** OPENS.");
			String^ res = s;
			if (eof > -1) res = res->Remove(eof);

			// переименование
			if (renvar->Checked)
			{
				int sel = res->IndexOf("select if");
				if (sel >= 0)
				{
					sel = res->IndexOf("\n", sel) + 1;
					res = res->Insert(sel, "rename variables(pre_sex pre_age" + del + "1 = sex age).\n");
				}
			}

			//выбор статусов
			if (selstat->Checked)
			{
				String^ statuses = Regex::Replace(stats->Text, "[^\\d,]", "");
				if (statuses != "18")
					res = Regex::Replace(res, "\nselect\\s+if\\s+status\\s*=[^\\.]+",
					(CountSubStrings(statuses, ",") > 0) ? ("\nselect if any(status, " + statuses + ")") : ("\nselect if status = " + statuses + ""),
										 RegularExpressions::RegexOptions::IgnoreCase);
			}

			// drop
			if (cutvars->Checked)
			{
				String^ lastTech = vars->Remove(0, vars->LastIndexOf("\npre_data") + 1);
				lastTech = lastTech->Remove(lastTech->IndexOf(" "));
				dv = " /drop GlobalID ";
				if (saveResp->Checked) dv += "PanelResp ";
				dv += "to ";
				if (saveTime->Checked) dv += "Page Status to ";
				if (saveLength->Checked) dv += "DeviceType Version to ";
				dv += lastTech;
				lastTech = Regex::Match(vars, "(?<name>srt" + del + "[^\\s]+)\\s+F\\d")->Result("${name}") + " to " + Regex::Match(vars, "(?<name>crt" + del + "[^\\s]+)\\s+F\\d[^(crt)]*$")->Result("${name}");
				dv += " " + lastTech + " ";
				dv += Regex::Match(vars, "(?<name>srt" + del + "[^\\s]+)\\s+[A-Z]\\d")->Result("${name}") + " to " + Regex::Match(vars, "(?<name>crt" + del + "[^\\s]+)\\s+[A-Z]\\d[^(crt)]*$")->Result("${name}");
			}

			// финальное сохранение
			res += "\n\nsave outfile \"currentPath/" + fn + "_Client.sav\"" + dv + ".";
			res += "\nget file \"currentPath/" + fn + "_Client.sav\".";

			// export
			if (excelExp->Checked)
			{
				res += "\n";
				res += "\n\nSAVE TRANSLATE OUTFILE=\"currentPath/" + fn + "_Client.xlsx\"\n";
				res += "/TYPE = XLS\n";
				res += "/VERSION = 12\n";
				res += "/MAP\n";
				res += "/REPLACE\n";
				res += "/FIELDNAMES\n";
				res += "/CELLS = " + (labs->Checked ? "LABELS" : "VALUES") + ".";
			}
			res += "\n\n" + s->Remove(0, eof + 1);

			progressBar1->Value = 55;

			// замена @
			if (repl)
			{
				StatusLabel->Text = "Замена @...";
				Update();
				res = res->Replace("@", delimeter->Text);
			}

			// замена {c#}
			if (replaceOther->Checked)
			{
				StatusLabel->Text = "Замена {c#}...";
				Update();
				res = res->Replace("{c#}", other->Text);
			}

			progressBar1->Value = 65;
			StatusLabel->Text = "Проверка списка переменных...";
			Update();

			List<String^>^ nvalidVarList = GetDuplicated(GetVarList(res));
			if (nvalidVarList->Count > 0)
			{
				CopyToBuffer(ListToString(nvalidVarList, "\n"));
				ShowWarning("В файле найдено " + nvalidVarList->Count + " повторяющихся переменных.\nПовторяющиеся имена скопированы в буфер обмена.");
			}



			progressBar1->Value = 75;
			StatusLabel->Text = "Сохранение файла...";
			Update();

			WriteFile(fp + load + ".sps", res->Split('\n'), ".bak");

			progressBar1->Value = 100;
			StatusLabel->Text = "Готово!";
			Update();
			ShowMessage("Готово!" + (autoRun->Checked ? "\nПосле продолжения файл синтаксиса будет открыт" : ""), MessageBoxIcon::Asterisk);
			StatusLabel->Text = "Запуск файла...";
			Update();
			this->Close();
			if (autoRun->Checked) Run(fp + load + ".sps");
			StatusLabel->Text = "Готово!";
			Update();
		}
		catch ( Exception^ e )
		{
			ShowError(429, "Ошибка обработки файла.\n\nПодробнее:\n" + e->ToString());
			ResetAll(false);
		}
	}

	private: System::Void FormDragEnter(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e)
	{
		if (e->Data->GetDataPresent(DataFormats::FileDrop))
		{
			e->Effect = DragDropEffects::All;
			String^ ext = ((array<String^>^)e->Data->GetData(DataFormats::FileDrop))[0];
			SelectImage(ext);
		}
	}

	private: System::Void FormDragDrop(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e)
	{
		if (e->Data->GetDataPresent(DataFormats::FileDrop)) FilePath->Text = ((array<String^>^)e->Data->GetData(DataFormats::FileDrop))[0];
	}

	private: System::Void FormDragLeave(System::Object^  sender, System::EventArgs^  e)
	{
		if (!File::Exists(FilePath->Text)) ResetAll(true);
		else UpdateAll();
	}

	private: System::Void FilePath_DoubleClick(System::Object^  sender, System::EventArgs^  e)
	{
		FilePath->SelectAll();
	}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (openFileDialog1->ShowDialog() == Forms::DialogResult::OK)
		{
			FilePath->Text = openFileDialog1->FileName;
			UpdateAll();
		}
	}

	private: System::Void FilePath_TextChanged(System::Object^  sender, System::EventArgs^  e)
	{
		FilePath->Text = Regex::Replace(FilePath->Text, "^[\"'](?<path>.+)[\"']$", "${path}");
		if (File::Exists(FilePath->Text))
			UpdateAll();
		else ResetAll(false);
	}




	private: void SelectImage(String^ ex)
	{
		try
		{
			if (ex == nullptr || String::IsNullOrEmpty(ex))
			{
				panel4->BackgroundImage = rsc->GetImage("unknown_file");
				return;
			}

			String^ ext = Path::GetExtension(ex)->ToUpper();

			if (ext->Contains("XML"))
				panel4->BackgroundImage = rsc->GetImage("xml_file");
			else if (ext->Contains("BAK"))
				panel4->BackgroundImage = rsc->GetImage("bak_file");
			else if (ext->Contains("TXT"))
				panel4->BackgroundImage = rsc->GetImage("txt_file");
			else if (ext->Contains("SPS"))
				panel4->BackgroundImage = rsc->GetImage("spss_file");
			else
				panel4->BackgroundImage = rsc->GetImage("unknown_file");
		}
		catch (Exception^ e)
		{
			ShowError(335, "Ошибка в ресурсах приложения");

		}
	}

	private: System::Void ResetAll(bool clearPath)
	{
		if (clearPath)
		{
			FilePath->Text = "";
			panel4->BackgroundImage = rsc->GetImage("waiting_for_file");
		}
		button2->Enabled = false;
		progressBar1->Value = 0;
		StatusLabel->Text = "Выберите файл";
		Update();
	}

	private: System::Void UpdateAll()
	{
		SelectImage(FilePath->Text);
		button2->Enabled = true;
		StatusLabel->Text = "Нажмите \"Создать\"";
		Update();
	}

	private: System::Void PilotSyntax_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)
	{
		sets->Clear();
		sets->Set("Delimiter", delimeter->Text);
		sets->Set("ReplaceDelimiter", repl->Checked);
		sets->Set("AutoRun", autoRun->Checked);
		sets->Set("ReplaceCS", replaceOther->Checked);
		sets->Save("SPSS");
	}

	private: System::Void PilotSyntax_Shown(System::Object^  sender, System::EventArgs^  e)
	{
		ResetAll(true);
	}

	private: List<String^>^ GetVarList(String^ s)
	{
		List<String^>^ res = gcnew List<String^>();
		if (!s->Contains("/VARIABLES")) return res;
		String^ str = s->Remove(0, s->IndexOf("/VARIABLES"));
		str = str->Remove(0, str->IndexOf("\n") + 1);
		str = str->Remove(0, str->IndexOf("\n") + 1);
		str = str->Remove(str->IndexOf("\n."));
		str = str->Replace("\n\n", "");
		str = Regex::Replace(str, "\n?(?<name>[^\\s\n]+)\\s(?<type>[^\n]+)\n?", "${name},");
		str = str->Remove(str->LastIndexOf(","));
		return StringToList(str, ',');
	}

	private: List<String^>^ GetDuplicated(List<String^>^ vars)
	{
		CopyToBuffer(ListToString(vars, "\n"));
		List<String^>^ res = gcnew List<String^>();
		for (int i = 0; i < vars->Count - 1; i++)
			for (int j = i + 1; j < vars->Count; j++)
			{
				if (vars[i]->ToLower() == vars[j]->ToLower() && !res->Contains(vars[i])) res->Add(vars[i]);
			}
		return res;
	}

};