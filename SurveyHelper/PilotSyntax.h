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
		public:
			ProjectResources^ rsc = gcnew ProjectResources();

		PilotSyntax(void)
		{
			InitializeComponent();
			this->panel4->BackgroundImage = rsc->GetImage("waiting_for_file");
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
			this->repl = (gcnew System::Windows::Forms::CheckBox());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->selstat = (gcnew System::Windows::Forms::CheckBox());
			this->stats = (gcnew System::Windows::Forms::TextBox());
			this->tableLayoutPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->saveTime = (gcnew System::Windows::Forms::CheckBox());
			this->cutvars = (gcnew System::Windows::Forms::CheckBox());
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
			this->tableLayoutPanel2->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			this->tableLayoutPanel6->SuspendLayout();
			this->panel1->SuspendLayout();
			this->tableLayoutPanel4->SuspendLayout();
			this->tableLayoutPanel5->SuspendLayout();
			this->panel2->SuspendLayout();
			this->tableLayoutPanel7->SuspendLayout();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Location = System::Drawing::Point(645, 113);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(8, 8);
			this->tableLayoutPanel1->TabIndex = 0;
			this->tableLayoutPanel2->ColumnCount = 2;
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				184)));
			this->tableLayoutPanel2->Controls->Add(this->groupBox1, 0, 1);
			this->tableLayoutPanel2->Controls->Add(this->panel2, 0, 2);
			this->tableLayoutPanel2->Controls->Add(this->panel3, 0, 0);
			this->tableLayoutPanel2->Controls->Add(this->panel4, 1, 1);
			this->tableLayoutPanel2->Controls->Add(this->button2, 1, 0);
			this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel2->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
			this->tableLayoutPanel2->RowCount = 3;
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 37)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 165)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 16)));
			this->tableLayoutPanel2->Size = System::Drawing::Size(632, 223);
			this->tableLayoutPanel2->TabIndex = 1;
			this->groupBox1->Controls->Add(this->tableLayoutPanel3);
			this->groupBox1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->groupBox1->Location = System::Drawing::Point(3, 40);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(442, 159);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Настройки";
			this->tableLayoutPanel3->ColumnCount = 1;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				100)));
			this->tableLayoutPanel3->Controls->Add(this->tableLayoutPanel6, 0, 4);
			this->tableLayoutPanel3->Controls->Add(this->renvar, 0, 1);
			this->tableLayoutPanel3->Controls->Add(this->repl, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->tableLayoutPanel4, 0, 2);
			this->tableLayoutPanel3->Controls->Add(this->tableLayoutPanel5, 0, 3);
			this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->tableLayoutPanel3->Location = System::Drawing::Point(3, 16);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 5;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 28)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 28)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 28)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 28)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 28)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(436, 140);
			this->tableLayoutPanel3->TabIndex = 0;
			this->tableLayoutPanel6->ColumnCount = 2;
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				229)));
			this->tableLayoutPanel6->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel6->Controls->Add(this->excelExp, 0, 0);
			this->tableLayoutPanel6->Controls->Add(this->panel1, 1, 0);
			this->tableLayoutPanel6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel6->Location = System::Drawing::Point(0, 112);
			this->tableLayoutPanel6->Margin = System::Windows::Forms::Padding(0);
			this->tableLayoutPanel6->Name = L"tableLayoutPanel6";
			this->tableLayoutPanel6->RowCount = 1;
			this->tableLayoutPanel6->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel6->Size = System::Drawing::Size(436, 28);
			this->tableLayoutPanel6->TabIndex = 6;
			this->excelExp->AutoSize = true;
			this->excelExp->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->excelExp->Location = System::Drawing::Point(3, 8);
			this->excelExp->Name = L"excelExp";
			this->excelExp->Size = System::Drawing::Size(223, 17);
			this->excelExp->TabIndex = 6;
			this->excelExp->Text = L"Экспортировать в Excel";
			this->excelExp->UseVisualStyleBackColor = true;
			this->panel1->Controls->Add(this->vals);
			this->panel1->Controls->Add(this->labs);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(229, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(207, 28);
			this->panel1->TabIndex = 7;
			this->vals->AutoSize = true;
			this->vals->Location = System::Drawing::Point(77, 6);
			this->vals->Name = L"vals";
			this->vals->Size = System::Drawing::Size(73, 17);
			this->vals->TabIndex = 1;
			this->vals->Text = L"Значения";
			this->vals->UseVisualStyleBackColor = true;
			this->labs->AutoSize = true;
			this->labs->Checked = true;
			this->labs->Location = System::Drawing::Point(3, 6);
			this->labs->Name = L"labs";
			this->labs->Size = System::Drawing::Size(57, 17);
			this->labs->TabIndex = 0;
			this->labs->TabStop = true;
			this->labs->Text = L"Метки";
			this->labs->UseVisualStyleBackColor = true;
			this->renvar->AutoSize = true;
			this->renvar->Checked = true;
			this->renvar->CheckState = System::Windows::Forms::CheckState::Checked;
			this->renvar->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->renvar->Location = System::Drawing::Point(3, 36);
			this->renvar->Name = L"renvar";
			this->renvar->Size = System::Drawing::Size(430, 17);
			this->renvar->TabIndex = 3;
			this->renvar->Text = L"Переименовать переменные pre_sex и pre_age_1";
			this->renvar->UseVisualStyleBackColor = true;
			this->repl->AutoSize = true;
			this->repl->Checked = true;
			this->repl->CheckState = System::Windows::Forms::CheckState::Checked;
			this->repl->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->repl->Location = System::Drawing::Point(3, 8);
			this->repl->Name = L"repl";
			this->repl->Size = System::Drawing::Size(430, 17);
			this->repl->TabIndex = 0;
			this->repl->Text = L"Заменить \"@\" на \"_\"";
			this->repl->UseVisualStyleBackColor = true;
			this->tableLayoutPanel4->ColumnCount = 2;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				229)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
				207)));
			this->tableLayoutPanel4->Controls->Add(this->selstat, 0, 0);
			this->tableLayoutPanel4->Controls->Add(this->stats, 1, 0);
			this->tableLayoutPanel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel4->Location = System::Drawing::Point(0, 56);
			this->tableLayoutPanel4->Margin = System::Windows::Forms::Padding(0);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 1;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(436, 28);
			this->tableLayoutPanel4->TabIndex = 4;
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
			this->stats->Dock = System::Windows::Forms::DockStyle::Left;
			this->stats->Location = System::Drawing::Point(232, 3);
			this->stats->Name = L"stats";
			this->stats->Size = System::Drawing::Size(158, 20);
			this->stats->TabIndex = 5;
			this->stats->Text = L"18";
			this->toolTip1->SetToolTip(this->stats, L"Список статусов через запятую");
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
			this->tableLayoutPanel5->Size = System::Drawing::Size(436, 28);
			this->tableLayoutPanel5->TabIndex = 5;
			this->saveTime->AutoSize = true;
			this->saveTime->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->saveTime->Location = System::Drawing::Point(232, 8);
			this->saveTime->Name = L"saveTime";
			this->saveTime->Size = System::Drawing::Size(201, 17);
			this->saveTime->TabIndex = 7;
			this->saveTime->Text = L"Оставить Start и End";
			this->saveTime->UseVisualStyleBackColor = true;
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
			this->panel2->BackColor = System::Drawing::SystemColors::AppWorkspace;
			this->tableLayoutPanel2->SetColumnSpan(this->panel2, 2);
			this->panel2->Controls->Add(this->tableLayoutPanel7);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(0, 202);
			this->panel2->Margin = System::Windows::Forms::Padding(0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(632, 21);
			this->panel2->TabIndex = 1;
			this->tableLayoutPanel7->BackColor = System::Drawing::Color::White;
			this->tableLayoutPanel7->ColumnCount = 2;
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				51.20148)));
			this->tableLayoutPanel7->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				48.79852)));
			this->tableLayoutPanel7->Controls->Add(this->StatusLabel, 0, 0);
			this->tableLayoutPanel7->Controls->Add(this->progressBar1, 1, 0);
			this->tableLayoutPanel7->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel7->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel7->Name = L"tableLayoutPanel7";
			this->tableLayoutPanel7->RowCount = 1;
			this->tableLayoutPanel7->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel7->Size = System::Drawing::Size(632, 21);
			this->tableLayoutPanel7->TabIndex = 0;
			this->StatusLabel->AutoSize = true;
			this->StatusLabel->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->StatusLabel->ForeColor = System::Drawing::Color::Gray;
			this->StatusLabel->Location = System::Drawing::Point(3, 5);
			this->StatusLabel->Margin = System::Windows::Forms::Padding(3, 0, 3, 3);
			this->StatusLabel->Name = L"StatusLabel";
			this->StatusLabel->Size = System::Drawing::Size(317, 13);
			this->StatusLabel->TabIndex = 0;
			this->StatusLabel->Text = L"Выберите файл";
			this->progressBar1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->progressBar1->Location = System::Drawing::Point(326, 3);
			this->progressBar1->Name = L"progressBar1";
			this->progressBar1->Size = System::Drawing::Size(303, 15);
			this->progressBar1->TabIndex = 1;
			this->panel3->Controls->Add(this->button1);
			this->panel3->Controls->Add(this->FilePath);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel3->Location = System::Drawing::Point(3, 3);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(442, 31);
			this->panel3->TabIndex = 2;
			this->button1->Location = System::Drawing::Point(337, 5);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(56, 20);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Обзор";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &PilotSyntax::button1_Click);
			this->FilePath->Location = System::Drawing::Point(3, 6);
			this->FilePath->Margin = System::Windows::Forms::Padding(2);
			this->FilePath->Name = L"FilePath";
			this->FilePath->Size = System::Drawing::Size(330, 20);
			this->FilePath->TabIndex = 0;
			this->FilePath->DoubleClick += gcnew System::EventHandler(this, &PilotSyntax::FilePath_DoubleClick);
			this->panel4->AllowDrop = true;
			this->panel4->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->panel4->BackColor = System::Drawing::Color::White;
			this->panel4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->panel4->Location = System::Drawing::Point(458, 44);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(164, 151);
			this->panel4->TabIndex = 4;
			this->panel4->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &PilotSyntax::panel4_DragDrop);
			this->panel4->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &PilotSyntax::panel4_DragEnter);
			this->panel4->DragLeave += gcnew System::EventHandler(this, &PilotSyntax::panel4_DragLeave);
			this->button2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button2->Location = System::Drawing::Point(489, 6);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(102, 25);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Создать!";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &PilotSyntax::button2_Click);
			this->toolTip1->IsBalloon = true;
			this->openFileDialog1->DefaultExt = L"sps";
			this->openFileDialog1->Filter = L"Файл spss-синтаксиса|*.sps";
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(632, 223);
			this->Controls->Add(this->tableLayoutPanel2);
			this->Controls->Add(this->tableLayoutPanel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"PilotSyntax";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Синтаксис для SPSS базы";
			this->tableLayoutPanel2->ResumeLayout(false);
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
			return;
		}

		if ( selstat->Checked && !Regex::IsMatch(stats->Text, "^(\\d{1,3}\\s*,?\\s*)*(\\d{1,3}\\s*)+$") )
		{
			ShowWarning("Неверно указан список статусов!");
			return;
		}

		try
		{
			StatusLabel->Text = "Загрузка файла...";
			Update();
		
			List<String^>^ fStr = gcnew List<String^>(ReadFile(FilePath->Text));

			progressBar1->Value = 30;
			StatusLabel->Text = "Сбор сведений...";
			Update();

			String^ s = ListToString(fStr, "\n");
			int vrInd = s->IndexOf("var lab");

			if ( s->IndexOf("val lab") < 0 || vrInd < 0 )
			{
				ShowWarning("Содержимое файла не распознано, как SPSS синтаксис!");
				return;
			}

			String^ delimiter = repl->Checked ? "_" : ( s->Contains("@") ? "@" : "_");
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
			if ( renvar->Checked ) add += "\n\nrename variables(pre_sex pre_age" + delimiter + "1 = sex age).";

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

			if ( repl )
			{
				StatusLabel->Text = "Замена @...";
				Update();
				res = res->Replace("@", "_");
			}

			progressBar1->Value = 80;
			StatusLabel->Text = "Сохранение файла...";
			Update();

			WriteFile(fp + load + ".sps", res->Split('\n'), ".bak");

			progressBar1->Value = 100;
			StatusLabel->Text = "Готово!";
			Update();
		}
		catch ( Exception^ e )
		{
			ShowError(429, "Ошибка обработки файла.\n\nПодробнее:\n" + e->ToString());
		}
	}



	private: System::Void panel4_DragEnter(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e)
	{
		if ( e->Data->GetDataPresent(DataFormats::FileDrop) )
		{
			e->Effect = DragDropEffects::All;
			String^ ext = ((array<String^>^)e->Data->GetData(DataFormats::FileDrop))[0];
			SelectImage(ext);
		}
	}

	private: System::Void panel4_DragDrop(System::Object^  sender, System::Windows::Forms::DragEventArgs^  e)
	{
		if ( e->Data->GetDataPresent(DataFormats::FileDrop) ) FilePath->Text = ((array<String^>^)e->Data->GetData(DataFormats::FileDrop))[0];
	}

	private: System::Void panel4_DragLeave(System::Object^  sender, System::EventArgs^  e)
	{
		if ( !File::Exists(FilePath->Text) ) panel4->BackgroundImage = rsc->GetImage("waiting_for_file");
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
				panel4->BackgroundImage = rsc->GetImage("xml_file");
			else if ( ext->Contains("BAK") )
				panel4->BackgroundImage = rsc->GetImage("bak_file");
			else if ( ext->Contains("TXT") )
				panel4->BackgroundImage = rsc->GetImage("txt_file");
			else if(ext->Contains("SPS"))
				panel4->BackgroundImage = rsc->GetImage("spss_file");
			else 
				panel4->BackgroundImage = rsc->GetImage("unknown_file");
		}
		catch ( Exception^ e )
		{
			ShowError(335, "Ошибка в ресурсах приложения");
		}
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
			SelectImage(FilePath->Text);
		}
	}

};