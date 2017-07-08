#pragma once
#include "Classes.h"

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class PilotSyntax: public System::Windows::Forms::Form
	{
		private:
			Settings^ sets = gcnew Settings();
	private: System::Windows::Forms::CheckBox^  autoRun;
			 ProjectResources^ rsc = gcnew ProjectResources();

		public: PilotSyntax()
		{
			InitializeComponent();
			this->panel4->BackgroundImage = rsc->GetImage("waiting_for_file");
			String^ dd = "_";
			sets->Read("SPSS");
			if ( sets->isWritten("Delimeter") ) dd = sets->Get("Delimeter");
			delimeter->Text = dd;
			repl->Checked = sets->Get("Replace", true);
			autoRun->Checked = sets->Get("AutoRun", true);
		}

		protected:
		~PilotSyntax()
		{
			if ( components )
			{
				delete components;
			}
		}
		

#pragma region Windows Form Designer generated code
		private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
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

		private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel6;
	private: System::Windows::Forms::CheckBox^  excelExp;

		private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::RadioButton^  vals;

	private: System::Windows::Forms::RadioButton^  labs;

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
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
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
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->tableLayoutPanel7 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->StatusLabel = (gcnew System::Windows::Forms::Label());
			this->progressBar1 = (gcnew System::Windows::Forms::ProgressBar());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->FilePath = (gcnew System::Windows::Forms::TextBox());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->autoRun = (gcnew System::Windows::Forms::CheckBox());
			this->tableLayoutPanel2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->tableLayoutPanel6->SuspendLayout();
			this->panel1->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->tableLayoutPanel5->SuspendLayout();
			this->tableLayoutPanel8->SuspendLayout();
			this->panel2->SuspendLayout();
			this->tableLayoutPanel7->SuspendLayout();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Location = System::Drawing::Point(860, 139);
			this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(4);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(11, 10);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// tableLayoutPanel2
			// 
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				245)));
			this->tableLayoutPanel2->Controls->Add(this->groupBox1, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->panel2, 0, 3);
			this->tableLayoutPanel2->Controls->Add(this->panel3, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->panel4, 1, 1);
			this->tableLayoutPanel2->Controls->Add(this->button2, 1, 0);
			this->tableLayoutPanel2->Controls->Add(this->autoRun, 0, 2);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel2->Margin = System::Windows::Forms::Padding(4);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 4;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 46)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 203)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 28)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(843, 303);
			this->tableLayoutPanel2->TabIndex = 1;
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->tableLayoutPanel3);
			this->groupBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->Location = System::Drawing::Point(4, 50);
			this->groupBox1->Margin = System::Windows::Forms::Padding(4);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Padding = System::Windows::Forms::Padding(4);
			this->groupBox1->Size = System::Drawing::Size(590, 195);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Настройки";
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->ColumnCount = 1;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel3->Controls->Add(this->tableLayoutPanel6, 0, 4);
			this->tableLayoutPanel3->Controls->Add(this->renvar, 0, 1);
			this->tableLayoutPanel3->Controls->Add(this->tableLayoutPanel4, 0, 2);
			this->tableLayoutPanel3->Controls->Add(this->tableLayoutPanel5, 0, 3);
			this->tableLayoutPanel3->Controls->Add(this->tableLayoutPanel8, 0, 0);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->tableLayoutPanel3->Location = System::Drawing::Point(4, 20);
			this->tableLayoutPanel3->Margin = System::Windows::Forms::Padding(4);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 5;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 34)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 34)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 34)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 34)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 34)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(582, 171);
			this->tableLayoutPanel3->TabIndex = 0;
			// 
			// tableLayoutPanel6
			// 
			this->tableLayoutPanel6->ColumnCount = 2;
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				305)));
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel6->Controls->Add(this->excelExp, 0, 0);
			this->tableLayoutPanel6->Controls->Add(this->panel1, 1, 0);
			this->tableLayoutPanel6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel6->Location = System::Drawing::Point(0, 136);
			this->tableLayoutPanel6->Margin = System::Windows::Forms::Padding(0);
			this->tableLayoutPanel6->Name = L"tableLayoutPanel6";
			this->tableLayoutPanel6->RowCount = 1;
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel6->Size = System::Drawing::Size(582, 35);
			this->tableLayoutPanel6->TabIndex = 6;
			// 
			// excelExp
			// 
			this->excelExp->AutoSize = true;
			this->excelExp->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->excelExp->Location = System::Drawing::Point(4, 10);
			this->excelExp->Margin = System::Windows::Forms::Padding(4);
			this->excelExp->Name = L"excelExp";
			this->excelExp->Size = System::Drawing::Size(297, 21);
			this->excelExp->TabIndex = 6;
			this->excelExp->Text = L"Экспортировать в Excel";
			this->excelExp->UseVisualStyleBackColor = true;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->vals);
			this->panel1->Controls->Add(this->labs);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(305, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(277, 35);
			this->panel1->TabIndex = 7;
			// 
			// vals
			// 
			this->vals->AutoSize = true;
			this->vals->Location = System::Drawing::Point(103, 7);
			this->vals->Margin = System::Windows::Forms::Padding(4);
			this->vals->Name = L"vals";
			this->vals->Size = System::Drawing::Size(94, 21);
			this->vals->TabIndex = 1;
			this->vals->Text = L"Значения";
			this->vals->UseVisualStyleBackColor = true;
			// 
			// labs
			// 
			this->labs->AutoSize = true;
			this->labs->Checked = true;
			this->labs->Location = System::Drawing::Point(4, 7);
			this->labs->Margin = System::Windows::Forms::Padding(4);
			this->labs->Name = L"labs";
			this->labs->Size = System::Drawing::Size(70, 21);
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
			this->renvar->Location = System::Drawing::Point(4, 43);
			this->renvar->Margin = System::Windows::Forms::Padding(4);
			this->renvar->Name = L"renvar";
			this->renvar->Size = System::Drawing::Size(574, 21);
			this->renvar->TabIndex = 3;
			this->renvar->Text = L"Переименовать переменные pre_sex и pre_age_1";
			this->renvar->UseVisualStyleBackColor = true;
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 2;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				305)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				277)));
			this->tableLayoutPanel4->Controls->Add(this->selstat, 0, 0);
			this->tableLayoutPanel4->Controls->Add(this->stats, 1, 0);
			this->tableLayoutPanel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel4->Location = System::Drawing::Point(0, 68);
			this->tableLayoutPanel4->Margin = System::Windows::Forms::Padding(0);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 1;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(582, 34);
			this->tableLayoutPanel4->TabIndex = 4;
			// 
			// selstat
			// 
			this->selstat->AutoSize = true;
			this->selstat->Checked = true;
			this->selstat->CheckState = System::Windows::Forms::CheckState::Checked;
			this->selstat->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->selstat->Location = System::Drawing::Point(4, 9);
			this->selstat->Margin = System::Windows::Forms::Padding(4);
			this->selstat->Name = L"selstat";
			this->selstat->Size = System::Drawing::Size(297, 21);
			this->selstat->TabIndex = 4;
			this->selstat->Text = L"Выбрать статусы:";
			this->selstat->UseVisualStyleBackColor = true;
			// 
			// stats
			// 
			this->stats->Dock = System::Windows::Forms::DockStyle::Left;
			this->stats->Location = System::Drawing::Point(309, 4);
			this->stats->Margin = System::Windows::Forms::Padding(4);
			this->stats->Name = L"stats";
			this->stats->Size = System::Drawing::Size(209, 23);
			this->stats->TabIndex = 5;
			this->stats->Text = L"18";
			this->toolTip1->SetToolTip(this->stats, L"Список статусов через запятую");
			// 
			// tableLayoutPanel5
			// 
			this->tableLayoutPanel5->ColumnCount = 2;
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				305)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel5->Controls->Add(this->saveTime, 0, 0);
			this->tableLayoutPanel5->Controls->Add(this->cutvars, 0, 0);
			this->tableLayoutPanel5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel5->Location = System::Drawing::Point(0, 102);
			this->tableLayoutPanel5->Margin = System::Windows::Forms::Padding(0);
			this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
			this->tableLayoutPanel5->RowCount = 1;
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel5->Size = System::Drawing::Size(582, 34);
			this->tableLayoutPanel5->TabIndex = 5;
			// 
			// saveTime
			// 
			this->saveTime->AutoSize = true;
			this->saveTime->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->saveTime->Location = System::Drawing::Point(309, 9);
			this->saveTime->Margin = System::Windows::Forms::Padding(4);
			this->saveTime->Name = L"saveTime";
			this->saveTime->Size = System::Drawing::Size(269, 21);
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
			this->cutvars->Location = System::Drawing::Point(4, 9);
			this->cutvars->Margin = System::Windows::Forms::Padding(4);
			this->cutvars->Name = L"cutvars";
			this->cutvars->Size = System::Drawing::Size(297, 21);
			this->cutvars->TabIndex = 6;
			this->cutvars->Text = L"Отрезать технические переменные";
			this->cutvars->UseVisualStyleBackColor = true;
			// 
			// tableLayoutPanel8
			// 
			this->tableLayoutPanel8->ColumnCount = 2;
			this->tableLayoutPanel8->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				305)));
			this->tableLayoutPanel8->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				273)));
			this->tableLayoutPanel8->Controls->Add(this->delimeter, 1, 0);
			this->tableLayoutPanel8->Controls->Add(this->repl, 0, 0);
			this->tableLayoutPanel8->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel8->Location = System::Drawing::Point(3, 0);
			this->tableLayoutPanel8->Margin = System::Windows::Forms::Padding(3, 0, 3, 0);
			this->tableLayoutPanel8->Name = L"tableLayoutPanel8";
			this->tableLayoutPanel8->RowCount = 1;
			this->tableLayoutPanel8->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel8->Size = System::Drawing::Size(576, 34);
			this->tableLayoutPanel8->TabIndex = 7;
			// 
			// delimeter
			// 
			this->delimeter->Location = System::Drawing::Point(308, 3);
			this->delimeter->MaxLength = 1;
			this->delimeter->Name = L"delimeter";
			this->delimeter->Size = System::Drawing::Size(35, 23);
			this->delimeter->TabIndex = 0;
			this->delimeter->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->toolTip1->SetToolTip(this->delimeter, L"Разделитель");
			// 
			// repl
			// 
			this->repl->AutoSize = true;
			this->repl->Checked = true;
			this->repl->CheckState = System::Windows::Forms::CheckState::Checked;
			this->repl->Location = System::Drawing::Point(4, 4);
			this->repl->Margin = System::Windows::Forms::Padding(4);
			this->repl->Name = L"repl";
			this->repl->Size = System::Drawing::Size(142, 21);
			this->repl->TabIndex = 0;
			this->repl->Text = L"Заменить \"@\" на";
			this->repl->UseVisualStyleBackColor = true;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->tableLayoutPanel2->SetColumnSpan(this->panel2, 2);
			this->panel2->Controls->Add(this->tableLayoutPanel7);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(0, 277);
			this->panel2->Margin = System::Windows::Forms::Padding(0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(843, 26);
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
			this->tableLayoutPanel7->Margin = System::Windows::Forms::Padding(4);
			this->tableLayoutPanel7->Name = L"tableLayoutPanel7";
			this->tableLayoutPanel7->RowCount = 1;
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel7->Size = System::Drawing::Size(843, 26);
			this->tableLayoutPanel7->TabIndex = 0;
			// 
			// StatusLabel
			// 
			this->StatusLabel->AutoSize = true;
			this->StatusLabel->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->StatusLabel->ForeColor = System::Drawing::Color::Gray;
			this->StatusLabel->Location = System::Drawing::Point(4, 5);
			this->StatusLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 4);
			this->StatusLabel->Name = L"StatusLabel";
			this->StatusLabel->Size = System::Drawing::Size(423, 17);
			this->StatusLabel->TabIndex = 0;
			this->StatusLabel->Text = L"Выберите файл";
			// 
			// progressBar1
			// 
			this->progressBar1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->progressBar1->Location = System::Drawing::Point(435, 4);
			this->progressBar1->Margin = System::Windows::Forms::Padding(4);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(404, 18);
			this->progressBar1->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
			this->progressBar1->TabIndex = 1;
			this->toolTip1->SetToolTip(this->progressBar1, L"Процесс выполнения");
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->button1);
			this->panel3->Controls->Add(this->FilePath);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel3->Location = System::Drawing::Point(4, 4);
			this->panel3->Margin = System::Windows::Forms::Padding(4);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(590, 38);
			this->panel3->TabIndex = 2;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(449, 6);
			this->button1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 25);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Обзор";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &PilotSyntax::button1_Click);
			// 
			// FilePath
			// 
			this->FilePath->Location = System::Drawing::Point(4, 7);
			this->FilePath->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->FilePath->Name = L"FilePath";
			this->FilePath->Size = System::Drawing::Size(439, 22);
			this->FilePath->TabIndex = 0;
			this->FilePath->TextChanged += gcnew System::EventHandler(this, &PilotSyntax::FilePath_TextChanged);
			this->FilePath->DoubleClick += gcnew System::EventHandler(this, &PilotSyntax::FilePath_DoubleClick);
			// 
			// panel4
			// 
			this->panel4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->panel4->BackColor = System::Drawing::Color::White;
			this->panel4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel4->Location = System::Drawing::Point(611, 54);
			this->panel4->Margin = System::Windows::Forms::Padding(4);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(219, 186);
			this->panel4->TabIndex = 4;
			// 
			// button2
			// 
			this->button2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button2->Enabled = false;
			this->button2->Location = System::Drawing::Point(652, 7);
			this->button2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(136, 31);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Создать!";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &PilotSyntax::button2_Click);
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
			// autoRun
			// 
			this->autoRun->AutoSize = true;
			this->autoRun->Checked = true;
			this->autoRun->CheckState = System::Windows::Forms::CheckState::Checked;
			this->autoRun->Location = System::Drawing::Point(12, 252);
			this->autoRun->Margin = System::Windows::Forms::Padding(12, 3, 3, 3);
			this->autoRun->Name = L"autoRun";
			this->autoRun->Size = System::Drawing::Size(192, 21);
			this->autoRun->TabIndex = 6;
			this->autoRun->Text = L"Открыть по завершении";
			this->toolTip1->SetToolTip(this->autoRun, L"Открыть файл .sps при успешном выполнении");
			this->autoRun->UseVisualStyleBackColor = true;
			// 
			// PilotSyntax
			// 
			this->AllowDrop = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(843, 303);
			this->Controls->Add(this->tableLayoutPanel2);
			this->Controls->Add(this->tableLayoutPanel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"PilotSyntax";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
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

		if ( !File::Exists(FilePath->Text) )
		{
			ShowMessage("Сначала выберите файл!", Forms::MessageBoxIcon::Exclamation);
			ResetAll(true);
			return;
		}

		if ( selstat->Checked && !Regex::IsMatch(stats->Text, "^(\\d{1,3}\\s*,?\\s*)*(\\d{1,3}\\s*)+$") )
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

			if ( s->IndexOf("val lab") < 0 || vrInd < 0 )
			{
				ShowWarning("Содержимое файла не распознано, как SPSS синтаксис!");
				ResetAll(false);
				return;
			}

			String^ del = repl->Checked ? delimeter->Text : "@";
			String^ vars = s->Remove(vrInd);
			String^ add = "";
			String^ fp = Regex::Replace(FilePath->Text, "\\.sps$", "");
			String^ dv = "";
			String^ load = Regex::IsMatch(Path::GetFileName(fp), "load", RegexOptions::IgnoreCase) ? "" : "_load";

			progressBar1->Value = 40;
			StatusLabel->Text = "Добавление команд...";
			Update();

			//путь в GET DATA
			s = Regex::Replace(s, "GET DATA\\s*/TYPE\\s*=\\s*TXT\\s*\n/FILE\\s*=\\s*['\"][^'\"]+['\"]", "GET DATA  /TYPE = TXT\n/FILE = \"" + fp + ".txt\"");

			int eof = s->IndexOf("val lab");
			eof = s->IndexOf("\n.\n", eof) + 3;
			String^ res = s->Remove(eof);

			// промежуточное сохранение
			add += "\n\nsave outfile \"" + fp + ".sav\" /zcompressed.";
			add += "\nget file \"" + fp + ".sav\".";

			// переименование
			if ( renvar->Checked ) add += "\n\nrename variables(pre_sex pre_age" + del + "1 = sex age).";

			//выбор статусов
			if ( selstat->Checked )
			{
				String^ statuses = Regex::Replace(stats->Text, "[^\\d,]", "");
				if (CountSubStrings(statuses, ",") > 0)
					add += "\n\nselect if any(Status, " + statuses->Replace(",", ", ") + ").";
				else add += "\n\nselect if Status = " + statuses + ".";
			}

			// drop
			if ( cutvars->Checked )
			{
				String^ lastTech = vars->Remove(0, vars->LastIndexOf("\npre_data") + 1);
				lastTech = lastTech->Remove(lastTech->IndexOf(" "));
				dv = " /drop GlobalID to " + ( saveTime->Checked ? "Page Status to " : "" ) + lastTech;
				lastTech = Regex::Match(vars, "(?<name>srt[_@][^\\s]+)\\s+F\\d")->Result("${name}") + " to " + Regex::Match(vars, "(?<name>crt[_@][^\\s]+)\\s+F\\d[^(crt)]*$")->Result("${name}");
				dv += " " + lastTech;
			}

			// финальное сохранение
			add += "\n\nsave outfile \"" + fp + "_Client.sav\"" + dv + ".";
			add += "\nget file \"" + fp + "_Client.sav\".";

			// export
			if ( excelExp->Checked )
			{
				add += "\n\nSAVE TRANSLATE OUTFILE=\"" + fp + "_Client.xlsx\"\n";
				add += "/TYPE = XLS\n";
				add += "/VERSION = 12\n";
				add += "/MAP\n";
				add += "/REPLACE\n";
				add += "/FIELDNAMES\n";
				add += "/CELLS = " + ( labs->Checked ? "LABELS" : "VALUES") + ".";
			}

			res += add + "\n\n" + s->Remove(0, eof + 1);

			progressBar1->Value = 60;

			// замена @
			if ( repl )
			{
				StatusLabel->Text = "Замена @...";
				Update();
				res = res->Replace("@", del);
			}

			progressBar1->Value = 80;
			StatusLabel->Text = "Сохранение файла...";
			Update();

			WriteFile(fp + load + ".sps", res->Split('\n'), ".bak");

			progressBar1->Value = 100;
			StatusLabel->Text = "Готово!";
			Update();
			ShowMessage("Готово!", MessageBoxIcon::Asterisk);
			this->Close();
			if ( autoRun->Checked ) Run(fp + load + ".sps");
		}
		catch ( Exception^ e )
		{
			ShowError(429, "Ошибка обработки файла.\n\nПодробнее:\n" + e->ToString());
		}
	}
	
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

	private: System::Void FormDragLeave(System::Object^  sender, System::EventArgs^  e)
	{
		if ( !File::Exists(FilePath->Text) ) ResetAll(true);
		else UpdateAll();
	}

	private: System::Void FilePath_DoubleClick(System::Object^  sender, System::EventArgs^  e)
	{
		FilePath->SelectAll();
	}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if ( openFileDialog1->ShowDialog() == Forms::DialogResult::OK )
		{
			FilePath->Text = openFileDialog1->FileName;
			UpdateAll();
		}
	}

	private: System::Void FilePath_TextChanged(System::Object^  sender, System::EventArgs^  e)
	{
		FilePath->Text = Regex::Replace(FilePath->Text, "^[\"'](?<path>.+)[\"']$", "${path}");
		if ( File::Exists(FilePath->Text) )
			UpdateAll();
		else ResetAll(false);
	}




	private: void SelectImage(String^ ex)
	{
		try
		{
			if ( ex == nullptr || String::IsNullOrEmpty(ex) )
			{
				panel4->BackgroundImage = rsc->GetImage("unknown_file");
				return;
			}

			String^ ext = Path::GetExtension(ex)->ToUpper();

			if ( ext->Contains("XML") )
				panel4->BackgroundImage = rsc->GetImage("xml_file");
			else if ( ext->Contains("BAK") )
				panel4->BackgroundImage = rsc->GetImage("bak_file");
			else if ( ext->Contains("TXT") )
				panel4->BackgroundImage = rsc->GetImage("txt_file");
			else if ( ext->Contains("SPS") )
				panel4->BackgroundImage = rsc->GetImage("spss_file");
			else
				panel4->BackgroundImage = rsc->GetImage("unknown_file");
		}
		catch ( Exception^ e )
		{
			ShowError(335, "Ошибка в ресурсах приложения");

		}
	}

	private: System::Void ResetAll(bool clearPath)
	{
		if ( clearPath )
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
		StatusLabel->Text = "Нажмитt \"Создать\"";
		Update();
	}

	private: System::Void PilotSyntax_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e)
	{
		sets->Clear();
		sets->Set("Delimeter", delimeter->Text);
		sets->Set("Replace", repl->Checked);
		sets->Set("AutoRun", autoRun->Checked);
		sets->Save("SPSS");
	}

	private: System::Void PilotSyntax_Shown(System::Object^  sender, System::EventArgs^  e)
	{
		ResetAll(true);
	}
};