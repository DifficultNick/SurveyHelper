#pragma once

#include "CustomClear.h"

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Problems : public System::Windows::Forms::Form
	{
	public:
		Problems(void)
		{
			InitializeComponent();
		}

	protected:
		~Problems()
		{
			if (components)
			{
				delete components;
			}
		}
	
		CustomClear^ CustomClearForm = gcnew CustomClear();

	public: CustomTemplateList^ Templates;
			String^ curVers;
			bool TemplatesChanged = false;

#pragma region Windows Form Designer generated code

	public: System::Windows::Forms::CheckBox^  ignorSpaces;
	private: System::Windows::Forms::ToolTip^  toolTip1;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  label1;
	public: System::Windows::Forms::CheckBox^  dontClear;
	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Label^  label2;
	public: System::Windows::Forms::CheckBox^  Clearatonce;
	public: System::Windows::Forms::CheckBox^  noDyn;
	public: System::Windows::Forms::CheckBox^  alwaysSep;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Label^  label3;
	public: System::Windows::Forms::CheckBox^  UpdateCheck;
	public: System::Windows::Forms::CheckBox^  autoScreen;
	public: System::Windows::Forms::CheckBox^  allBack;
	public: System::Windows::Forms::CheckBox^  clearHeader;
	public: System::Windows::Forms::CheckBox^  checkCorrect;
	public: System::Windows::Forms::CheckBox^  minimize;
	private: System::Windows::Forms::Button^  button1;
	public: System::Windows::Forms::CheckBox^  autoReplace;
	private: System::Windows::Forms::Panel^  panel4;
	public:
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  button2;
	private: System::ComponentModel::IContainer^  components;

	private:
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Problems::typeid));
			this->ignorSpaces = (gcnew System::Windows::Forms::CheckBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->autoReplace = (gcnew System::Windows::Forms::CheckBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->checkCorrect = (gcnew System::Windows::Forms::CheckBox());
			this->clearHeader = (gcnew System::Windows::Forms::CheckBox());
			this->dontClear = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			this->Clearatonce = (gcnew System::Windows::Forms::CheckBox());
			this->noDyn = (gcnew System::Windows::Forms::CheckBox());
			this->UpdateCheck = (gcnew System::Windows::Forms::CheckBox());
			this->autoScreen = (gcnew System::Windows::Forms::CheckBox());
			this->allBack = (gcnew System::Windows::Forms::CheckBox());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->alwaysSep = (gcnew System::Windows::Forms::CheckBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->minimize = (gcnew System::Windows::Forms::CheckBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			this->SuspendLayout();
			// 
			// ignorSpaces
			// 
			this->ignorSpaces->AutoSize = true;
			this->ignorSpaces->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->ignorSpaces->Location = System::Drawing::Point(36, 29);
			this->ignorSpaces->Name = L"ignorSpaces";
			this->ignorSpaces->Size = System::Drawing::Size(323, 19);
			this->ignorSpaces->TabIndex = 0;
			this->ignorSpaces->Text = L"Не учитывать нумерацию элементов через пробел";
			this->toolTip1->SetToolTip(this->ignorSpaces, L"Не считать номером Answer/Item \r\nчисло, стоящее в начале текста, и \r\nотделённое о"
				L"т него пробелом.");
			this->ignorSpaces->UseVisualStyleBackColor = true;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::White;
			this->panel1->Controls->Add(this->autoReplace);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->checkCorrect);
			this->panel1->Controls->Add(this->clearHeader);
			this->panel1->Controls->Add(this->dontClear);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->ignorSpaces);
			this->panel1->Location = System::Drawing::Point(12, 12);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(468, 157);
			this->panel1->TabIndex = 1;
			// 
			// autoReplace
			// 
			this->autoReplace->AutoSize = true;
			this->autoReplace->Checked = true;
			this->autoReplace->CheckState = System::Windows::Forms::CheckState::Checked;
			this->autoReplace->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->autoReplace->Location = System::Drawing::Point(36, 129);
			this->autoReplace->Name = L"autoReplace";
			this->autoReplace->Size = System::Drawing::Size(185, 19);
			this->autoReplace->TabIndex = 6;
			this->autoReplace->Text = L"Автозамена при генерации";
			this->toolTip1->SetToolTip(this->autoReplace, L"Выполнять автозамену сразу при генерации\r\n(аналогичео пункту \"Убрать лишнее\" конт"
				L"екстного меню)");
			this->autoReplace->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(305, 125);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(152, 23);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Настроить";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Problems::button1_Click);
			// 
			// checkCorrect
			// 
			this->checkCorrect->AutoSize = true;
			this->checkCorrect->Checked = true;
			this->checkCorrect->CheckState = System::Windows::Forms::CheckState::Checked;
			this->checkCorrect->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->checkCorrect->Location = System::Drawing::Point(36, 104);
			this->checkCorrect->Name = L"checkCorrect";
			this->checkCorrect->Size = System::Drawing::Size(175, 19);
			this->checkCorrect->TabIndex = 4;
			this->checkCorrect->Text = L"Проверять корректность";
			this->toolTip1->SetToolTip(this->checkCorrect, L"- проверка текста и Id на недопустимые символы\r\n- проверка Id на уникальность\r\n- "
				L"проверка количества Var и Items");
			this->checkCorrect->UseVisualStyleBackColor = true;
			// 
			// clearHeader
			// 
			this->clearHeader->AutoSize = true;
			this->clearHeader->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->clearHeader->Location = System::Drawing::Point(36, 79);
			this->clearHeader->Name = L"clearHeader";
			this->clearHeader->Size = System::Drawing::Size(226, 19);
			this->clearHeader->TabIndex = 3;
			this->clearHeader->Text = L"Оставлять Id в заголовке вопроса";
			this->clearHeader->UseVisualStyleBackColor = true;
			// 
			// dontClear
			// 
			this->dontClear->AutoSize = true;
			this->dontClear->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->dontClear->Location = System::Drawing::Point(36, 54);
			this->dontClear->Name = L"dontClear";
			this->dontClear->Size = System::Drawing::Size(223, 19);
			this->dontClear->TabIndex = 2;
			this->dontClear->Text = L"Оставлять Id в тексте элементов";
			this->dontClear->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(2, 2);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(250, 15);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Параметры преобразований текста";
			// 
			// toolTip1
			// 
			this->toolTip1->IsBalloon = true;
			// 
			// Clearatonce
			// 
			this->Clearatonce->AutoSize = true;
			this->Clearatonce->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Clearatonce->Location = System::Drawing::Point(36, 32);
			this->Clearatonce->Name = L"Clearatonce";
			this->Clearatonce->Size = System::Drawing::Size(229, 19);
			this->Clearatonce->TabIndex = 0;
			this->Clearatonce->Text = L"Очищать таблицу после генерации";
			this->toolTip1->SetToolTip(this->Clearatonce, L"Очищать таблицу с текстом Answers/Items\r\nсразу после генерации XML.\r\nЕсли включен"
				L"а проверка корректности,\r\nто при возникновении ошибок таблица \r\nочищена не будет"
				L".");
			this->Clearatonce->UseVisualStyleBackColor = true;
			// 
			// noDyn
			// 
			this->noDyn->AutoSize = true;
			this->noDyn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->noDyn->Location = System::Drawing::Point(36, 33);
			this->noDyn->Name = L"noDyn";
			this->noDyn->Size = System::Drawing::Size(175, 19);
			this->noDyn->TabIndex = 3;
			this->noDyn->Text = L"Динамическая генерация";
			this->toolTip1->SetToolTip(this->noDyn, L"Обновлять поле XML кода при\r\nкаждом изменении");
			this->noDyn->UseVisualStyleBackColor = true;
			// 
			// UpdateCheck
			// 
			this->UpdateCheck->AutoSize = true;
			this->UpdateCheck->Checked = true;
			this->UpdateCheck->CheckState = System::Windows::Forms::CheckState::Checked;
			this->UpdateCheck->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->UpdateCheck->Location = System::Drawing::Point(36, 60);
			this->UpdateCheck->Name = L"UpdateCheck";
			this->UpdateCheck->Size = System::Drawing::Size(164, 19);
			this->UpdateCheck->TabIndex = 2;
			this->UpdateCheck->Text = L"Проверять обновления";
			this->toolTip1->SetToolTip(this->UpdateCheck, L"Проверять обновления приложения и библиотек");
			this->UpdateCheck->UseVisualStyleBackColor = true;
			this->UpdateCheck->Click += gcnew System::EventHandler(this, &Problems::UpdateCheck_Click);
			// 
			// autoScreen
			// 
			this->autoScreen->AutoSize = true;
			this->autoScreen->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->autoScreen->Location = System::Drawing::Point(36, 89);
			this->autoScreen->Name = L"autoScreen";
			this->autoScreen->Size = System::Drawing::Size(178, 19);
			this->autoScreen->TabIndex = 5;
			this->autoScreen->Text = L"Дополнительные вставки";
			this->toolTip1->SetToolTip(this->autoScreen, L"Генерировать такие теги, как\r\nRedirect, Filter и т.п.");
			this->autoScreen->UseVisualStyleBackColor = true;
			// 
			// allBack
			// 
			this->allBack->AutoSize = true;
			this->allBack->Checked = true;
			this->allBack->CheckState = System::Windows::Forms::CheckState::Checked;
			this->allBack->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->allBack->Location = System::Drawing::Point(36, 60);
			this->allBack->Name = L"allBack";
			this->allBack->Size = System::Drawing::Size(251, 19);
			this->allBack->TabIndex = 6;
			this->allBack->Text = L"Возвращать настройки  после очистки";
			this->toolTip1->SetToolTip(this->allBack, L"Возвращать после очистки исходные настройки");
			this->allBack->UseVisualStyleBackColor = true;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::White;
			this->panel2->Controls->Add(this->autoScreen);
			this->panel2->Controls->Add(this->alwaysSep);
			this->panel2->Controls->Add(this->noDyn);
			this->panel2->Controls->Add(this->label2);
			this->panel2->Location = System::Drawing::Point(12, 185);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(468, 118);
			this->panel2->TabIndex = 2;
			// 
			// alwaysSep
			// 
			this->alwaysSep->AutoSize = true;
			this->alwaysSep->Checked = true;
			this->alwaysSep->CheckState = System::Windows::Forms::CheckState::Checked;
			this->alwaysSep->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->alwaysSep->Location = System::Drawing::Point(36, 61);
			this->alwaysSep->Name = L"alwaysSep";
			this->alwaysSep->Size = System::Drawing::Size(208, 19);
			this->alwaysSep->TabIndex = 4;
			this->alwaysSep->Text = L"Текст всегда отдельным тэгом";
			this->alwaysSep->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(2, 2);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(153, 15);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Настройки генерации";
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::White;
			this->panel3->Controls->Add(this->minimize);
			this->panel3->Controls->Add(this->label3);
			this->panel3->Controls->Add(this->UpdateCheck);
			this->panel3->Location = System::Drawing::Point(12, 427);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(468, 90);
			this->panel3->TabIndex = 3;
			// 
			// minimize
			// 
			this->minimize->AutoSize = true;
			this->minimize->Checked = true;
			this->minimize->CheckState = System::Windows::Forms::CheckState::Checked;
			this->minimize->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->minimize->Location = System::Drawing::Point(36, 32);
			this->minimize->Name = L"minimize";
			this->minimize->Size = System::Drawing::Size(204, 19);
			this->minimize->TabIndex = 3;
			this->minimize->Text = L"Сворачивать после генерации";
			this->minimize->UseVisualStyleBackColor = true;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(2, 2);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(125, 15);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Общие настройки";
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::White;
			this->panel4->Controls->Add(this->button2);
			this->panel4->Controls->Add(this->allBack);
			this->panel4->Controls->Add(this->label4);
			this->panel4->Controls->Add(this->Clearatonce);
			this->panel4->Location = System::Drawing::Point(12, 320);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(468, 90);
			this->panel4->TabIndex = 4;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(305, 56);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(152, 23);
			this->button2->TabIndex = 7;
			this->button2->Text = L"Настроить";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Visible = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(2, 2);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(136, 15);
			this->label4->TabIndex = 1;
			this->label4->Text = L"Настройки очистки";
			// 
			// Problems
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoScroll = true;
			this->ClientSize = System::Drawing::Size(510, 338);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MaximumSize = System::Drawing::Size(526, 575);
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(526, 350);
			this->Name = L"Problems";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Настройки";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void UpdateCheck_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if ( !UpdateCheck->Checked )
			if ( Forms::MessageBox::Show("Точно?", "", Forms::MessageBoxButtons::YesNo, Forms::MessageBoxIcon::Question) == Forms::DialogResult::Yes )
				UpdateCheck->Checked = false;
			else UpdateCheck->Checked = true;
	}


	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		TemplatesChanged = true;
		Templates = gcnew CustomTemplateList();
		Templates = GetActiveTemplates(curVers);
	}

};