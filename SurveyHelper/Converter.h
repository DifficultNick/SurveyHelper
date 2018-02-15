#pragma once


#include "Classes.h"


	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Text::RegularExpressions;

public ref class SurveyConverter: public System::Windows::Forms::Form
{
	public:
		String^ curVers = "";
		String^ lasVers = "";
private: System::Windows::Forms::ToolStripTextBox^  customSep;
private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;


public:
		
	Dictionary<int, String^>^ Separators = gcnew Dictionary<int, String^>();
	
	
	SurveyConverter(String^ cv)
		{
			InitializeComponent();
							
			Separators->Add(0, "\n");
			Separators->Add(1, "\t");
			Separators->Add(2, " ");
			Separators->Add(3, ";");
			Separators->Add(4, ",");
			
			curVers = cv;
			convertType->SelectedIndex = 0;
			separatorsItem->SelectedIndex = 0;
			this->KeyPreview = true;
			this->KeyDown += gcnew KeyEventHandler(this, &SurveyConverter::KeyPressed);
		}


#pragma region Windows Form Designer generated code
	protected:

		~SurveyConverter()
		{
			if ( components )
			{
				delete components;
			}
		}

	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  параметрыToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  bufToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  separatorToolStripMenuItem;
	private: System::Windows::Forms::ToolStripComboBox^  separatorsItem;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::RichTextBox^  sourceText;
	private: System::Windows::Forms::RichTextBox^  resultTex;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::ToolTip^  toolTip1;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
	private: System::Windows::Forms::ComboBox^  convertType;

	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;
	private: System::Windows::Forms::Button^  genButton;

	private: System::Windows::Forms::Button^  button2;
	private: System::ComponentModel::IContainer^  components;





	/// <summary>
	/// Требуемый метод для поддержки конструктора — не изменяйте 
	/// содержимое этого метода с помощью редактора кода.
	/// </summary>
			 void InitializeComponent(void)
			 {
				 this->components = (gcnew System::ComponentModel::Container());
				 System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(SurveyConverter::typeid));
				 this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
				 this->sourceText = (gcnew System::Windows::Forms::RichTextBox());
				 this->resultTex = (gcnew System::Windows::Forms::RichTextBox());
				 this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
				 this->convertType = (gcnew System::Windows::Forms::ComboBox());
				 this->label1 = (gcnew System::Windows::Forms::Label());
				 this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
				 this->genButton = (gcnew System::Windows::Forms::Button());
				 this->button2 = (gcnew System::Windows::Forms::Button());
				 this->button1 = (gcnew System::Windows::Forms::Button());
				 this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
				 this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
				 this->параметрыToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->bufToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->separatorToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
				 this->separatorsItem = (gcnew System::Windows::Forms::ToolStripComboBox());
				 this->customSep = (gcnew System::Windows::Forms::ToolStripTextBox());
				 this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
				 this->tableLayoutPanel1->SuspendLayout();
				 this->tableLayoutPanel2->SuspendLayout();
				 this->tableLayoutPanel3->SuspendLayout();
				 this->menuStrip1->SuspendLayout();
				 this->SuspendLayout();
				 // 
				 // tableLayoutPanel1
				 // 
				 this->tableLayoutPanel1->ColumnCount = 2;
				 this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
					 50)));
				 this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
					 50)));
				 this->tableLayoutPanel1->Controls->Add(this->sourceText, 0, 1);
				 this->tableLayoutPanel1->Controls->Add(this->resultTex, 1, 1);
				 this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel2, 0, 0);
				 this->tableLayoutPanel1->Controls->Add(this->tableLayoutPanel3, 1, 0);
				 this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
				 this->tableLayoutPanel1->Location = System::Drawing::Point(0, 28);
				 this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(4);
				 this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
				 this->tableLayoutPanel1->RowCount = 2;
				 this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 37)));
				 this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
				 this->tableLayoutPanel1->Size = System::Drawing::Size(1035, 393);
				 this->tableLayoutPanel1->TabIndex = 0;
				 // 
				 // sourceText
				 // 
				 this->sourceText->Dock = System::Windows::Forms::DockStyle::Fill;
				 this->sourceText->Location = System::Drawing::Point(4, 41);
				 this->sourceText->Margin = System::Windows::Forms::Padding(4, 4, 9, 4);
				 this->sourceText->Name = L"sourceText";
				 this->sourceText->Size = System::Drawing::Size(504, 348);
				 this->sourceText->TabIndex = 0;
				 this->sourceText->Text = L"";
				 // 
				 // resultTex
				 // 
				 this->resultTex->Dock = System::Windows::Forms::DockStyle::Fill;
				 this->resultTex->Location = System::Drawing::Point(526, 41);
				 this->resultTex->Margin = System::Windows::Forms::Padding(9, 4, 4, 4);
				 this->resultTex->Name = L"resultTex";
				 this->resultTex->Size = System::Drawing::Size(505, 348);
				 this->resultTex->TabIndex = 2;
				 this->resultTex->Text = L"";
				 // 
				 // tableLayoutPanel2
				 // 
				 this->tableLayoutPanel2->ColumnCount = 2;
				 this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
					 192)));
				 this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
					 100)));
				 this->tableLayoutPanel2->Controls->Add(this->convertType, 1, 0);
				 this->tableLayoutPanel2->Controls->Add(this->label1, 0, 0);
				 this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
				 this->tableLayoutPanel2->Location = System::Drawing::Point(4, 4);
				 this->tableLayoutPanel2->Margin = System::Windows::Forms::Padding(4);
				 this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
				 this->tableLayoutPanel2->RowCount = 1;
				 this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
				 this->tableLayoutPanel2->Size = System::Drawing::Size(509, 29);
				 this->tableLayoutPanel2->TabIndex = 3;
				 // 
				 // convertType
				 // 
				 this->convertType->BackColor = System::Drawing::SystemColors::Window;
				 this->convertType->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
				 this->convertType->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
				 this->convertType->FormattingEnabled = true;
				 this->convertType->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
					 L"Val lab из Answer / Item", L"Val lab из таблицы",
						 L"Таблица из Answer / Item", L"Диапазон переменных", L"Список возрастных групп", L"Val lab из возрастных групп", L"Списки данных"
				 });
				 this->convertType->Location = System::Drawing::Point(196, 4);
				 this->convertType->Margin = System::Windows::Forms::Padding(4);
				 this->convertType->Name = L"convertType";
				 this->convertType->Size = System::Drawing::Size(308, 24);
				 this->convertType->TabIndex = 0;
				 this->toolTip1->SetToolTip(this->convertType, L"Выберите нужное действие");
				 // 
				 // label1
				 // 
				 this->label1->AutoSize = true;
				 this->label1->Dock = System::Windows::Forms::DockStyle::Left;
				 this->label1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
				 this->label1->Location = System::Drawing::Point(4, 4);
				 this->label1->Margin = System::Windows::Forms::Padding(4);
				 this->label1->Name = L"label1";
				 this->label1->Size = System::Drawing::Size(151, 21);
				 this->label1->TabIndex = 1;
				 this->label1->Text = L"Тип преобразования:";
				 this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
				 // 
				 // tableLayoutPanel3
				 // 
				 this->tableLayoutPanel3->ColumnCount = 2;
				 this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
					 50)));
				 this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
					 50)));
				 this->tableLayoutPanel3->Controls->Add(this->genButton, 0, 0);
				 this->tableLayoutPanel3->Controls->Add(this->button2, 1, 0);
				 this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
				 this->tableLayoutPanel3->Location = System::Drawing::Point(521, 4);
				 this->tableLayoutPanel3->Margin = System::Windows::Forms::Padding(4);
				 this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
				 this->tableLayoutPanel3->RowCount = 1;
				 this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
				 this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 29)));
				 this->tableLayoutPanel3->Size = System::Drawing::Size(510, 29);
				 this->tableLayoutPanel3->TabIndex = 4;
				 // 
				 // genButton
				 // 
				 this->genButton->Location = System::Drawing::Point(4, 0);
				 this->genButton->Margin = System::Windows::Forms::Padding(4, 0, 0, 0);
				 this->genButton->Name = L"genButton";
				 this->genButton->Size = System::Drawing::Size(145, 29);
				 this->genButton->TabIndex = 1;
				 this->genButton->Text = L"Преобразовать";
				 this->genButton->UseVisualStyleBackColor = true;
				 this->genButton->Click += gcnew System::EventHandler(this, &SurveyConverter::genButton_Click);
				 // 
				 // button2
				 // 
				 this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
				 this->button2->Location = System::Drawing::Point(362, 0);
				 this->button2->Margin = System::Windows::Forms::Padding(0);
				 this->button2->Name = L"button2";
				 this->button2->Size = System::Drawing::Size(148, 29);
				 this->button2->TabIndex = 1;
				 this->button2->Text = L"Справка";
				 this->button2->UseVisualStyleBackColor = true;
				 this->button2->Click += gcnew System::EventHandler(this, &SurveyConverter::button2_Click);
				 // 
				 // button1
				 // 
				 this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
				 this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
				 this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
				 this->button1->Location = System::Drawing::Point(993, -1);
				 this->button1->Margin = System::Windows::Forms::Padding(0);
				 this->button1->Name = L"button1";
				 this->button1->Size = System::Drawing::Size(37, 31);
				 this->button1->TabIndex = 2;
				 this->toolTip1->SetToolTip(this->button1, L"Сохранить результат");
				 this->button1->UseVisualStyleBackColor = true;
				 this->button1->Click += gcnew System::EventHandler(this, &SurveyConverter::button1_Click);
				 // 
				 // menuStrip1
				 // 
				 this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
				 this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->параметрыToolStripMenuItem });
				 this->menuStrip1->Location = System::Drawing::Point(0, 0);
				 this->menuStrip1->Name = L"menuStrip1";
				 this->menuStrip1->Padding = System::Windows::Forms::Padding(8, 2, 0, 2);
				 this->menuStrip1->Size = System::Drawing::Size(1035, 28);
				 this->menuStrip1->TabIndex = 1;
				 this->menuStrip1->Text = L"menuStrip1";
				 // 
				 // параметрыToolStripMenuItem
				 // 
				 this->параметрыToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
					 this->bufToolStripMenuItem,
						 this->separatorToolStripMenuItem
				 });
				 this->параметрыToolStripMenuItem->Name = L"параметрыToolStripMenuItem";
				 this->параметрыToolStripMenuItem->Size = System::Drawing::Size(102, 24);
				 this->параметрыToolStripMenuItem->Text = L"Параметры";
				 // 
				 // bufToolStripMenuItem
				 // 
				 this->bufToolStripMenuItem->Checked = true;
				 this->bufToolStripMenuItem->CheckOnClick = true;
				 this->bufToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
				 this->bufToolStripMenuItem->Name = L"bufToolStripMenuItem";
				 this->bufToolStripMenuItem->Size = System::Drawing::Size(227, 26);
				 this->bufToolStripMenuItem->Text = L"Копировать в буфер";
				 this->bufToolStripMenuItem->ToolTipText = L"Копировать результат в буфер обмена сразу после выполнения преобразования";
				 // 
				 // separatorToolStripMenuItem
				 // 
				 this->separatorToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
					 this->separatorsItem,
						 this->customSep
				 });
				 this->separatorToolStripMenuItem->Name = L"separatorToolStripMenuItem";
				 this->separatorToolStripMenuItem->Size = System::Drawing::Size(227, 26);
				 this->separatorToolStripMenuItem->Text = L"Разделитель";
				 // 
				 // separatorsItem
				 // 
				 this->separatorsItem->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
				 this->separatorsItem->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
					 L"Перенос", L"Табуляция", L"Пробел", L"Точка с запятой",
						 L"Запятая"
				 });
				 this->separatorsItem->Name = L"separatorsItem";
				 this->separatorsItem->Size = System::Drawing::Size(121, 28);
				 this->separatorsItem->SelectedIndexChanged += gcnew System::EventHandler(this, &SurveyConverter::separatorsItem_SelectedIndexChanged);
				 // 
				 // customSep
				 // 
				 this->customSep->Name = L"customSep";
				 this->customSep->Size = System::Drawing::Size(120, 27);
				 this->customSep->Text = L"Другой разделитель";
				 this->customSep->Click += gcnew System::EventHandler(this, &SurveyConverter::customSep_Click);
				 // 
				 // SurveyConverter
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->BackColor = System::Drawing::SystemColors::AppWorkspace;
				 this->ClientSize = System::Drawing::Size(1035, 421);
				 this->Controls->Add(this->button1);
				 this->Controls->Add(this->tableLayoutPanel1);
				 this->Controls->Add(this->menuStrip1);
				 this->Margin = System::Windows::Forms::Padding(4);
				 this->MinimumSize = System::Drawing::Size(794, 358);
				 this->Name = L"SurveyConverter";
				 this->ShowIcon = false;
				 this->ShowInTaskbar = false;
				 this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
				 this->Text = L"Преобразования";
				 this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &SurveyConverter::SurveyConverter_FormClosed);
				 this->Shown += gcnew System::EventHandler(this, &SurveyConverter::SurveyConverter_Shown);
				 this->tableLayoutPanel1->ResumeLayout(false);
				 this->tableLayoutPanel2->ResumeLayout(false);
				 this->tableLayoutPanel2->PerformLayout();
				 this->tableLayoutPanel3->ResumeLayout(false);
				 this->menuStrip1->ResumeLayout(false);
				 this->menuStrip1->PerformLayout();
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }
#pragma endregion



#pragma region доп функции



	List<String^>^ MakeRange(List<String^>^ store, String^ prefix, Dictionary<String^, String^>^ options)
	{
		List<String^>^ res = gcnew List<String^>();
		RangeTemplate^ range = gcnew RangeTemplate(options["range"]);
		IteraTemplate^ itera = gcnew IteraTemplate(options["expr"]);
		ExcludeTemplate^ excl = gcnew ExcludeTemplate(options["excl"]);

		if ( !range->Valid || !itera->Valid || !excl->Valid )
		{
			ShowMessage("Синтаксис не распознан как верный шаблон");
			return res;
		}
		
		if ( store->Count == 0 ) store->Add("");

		for each (String^ s in store)
		{
			for ( int i = range->Min; i <= range->Max; i++)
				if (!excl->Items->Contains(i)) res->Add(s+prefix+itera->Evaluate(i));
		}
		return res;
	}


	String^ GetSeparator()
	{
		if ( customSep->Text != "Другой разделитель" ) return customSep->Text;
		return Separators[separatorsItem->SelectedIndex];
	}

	void Report(String^ str)
	{
		resultTex->Text += str + "\n";
		resultTex->Update();
	}


#pragma endregion


	// выделение val lab из XML
	String^ LabsFromXml(String^ xmlBody)
	{
		String^ res = "";
		try
		{
			if ( !(xmlBody->Contains("<Item") || xmlBody->Contains("<Answer")) ) return "Содержимое не распознано как XML";

			XmlDocument^ xml = gcnew XmlDocument();
			String^ vn = "";
			String^ txt = "";

			xml->LoadXml("<root>" + xmlBody + "</root>");

			XmlNodeList^ childs = xml->SelectNodes("root")[0]->ChildNodes;
			XmlNodeList^ items;
			array<String^>^ its = { "Page", "Question", "Answer", "Item", "List" };

			for each (XmlNode^ child in childs)
			{
				txt = "";
				// Page		
				if ( child->Name == "Page" || child->Name == "Question" )
				{
					if ( child["Question"] )
					{
						vn = child["Question"]->Attributes["Id"]->Value;
						items = child["Question"]->SelectNodes("Answer");
					}
					else if ( child->SelectNodes("Text")[0] ) txt = child->SelectNodes("Text")[0]->InnerText;
					vn = child->Attributes["Id"]->Value;
					res += "val lab " + vn + "\n";
				}
				//List
				else if ( child->Name == "List" )
				{
					items = child->SelectNodes("Item");
					vn = Regex::Replace(child->Attributes["Id"]->Value, "_?Li?st_?", "", System::Text::RegularExpressions::RegexOptions::IgnoreCase);
					res += "val lab " + vn + "\n";
				}
				// Answer/Item
				else if ( child->Name == "Answer" || child->Name == "Item" )
				{
					if ( !!child->Attributes["Text"] )
						txt = child->Attributes["Text"]->Value;
					else if ( child->SelectNodes("Text")[0] ) txt = child->SelectNodes("Text")[0]->InnerText;
					if ( !child->Attributes["Id"] ) return "Не удалось определить Id элемента";
					if ( txt == "" ) return "Не удалось определить метку для элемента " + child->Attributes["Id"]->Value + " переменной " + vn;
					if ( !child->PreviousSibling || child->PreviousSibling->Name != "Answer" && child->PreviousSibling->Name != "Item" ) res += "val lab \n";
					res += child->Attributes["Id"]->Value + " '" + txt->Replace("'", "\"")->Trim() + "'\n";
					continue;
				}
				else
				{
					return "Элемент <" + child->Name + "> не должен быть родительским!";
				}

				// Parsing
				for each (XmlNode^ item in items)
				{
					txt = "";
					if ( !!item->Attributes["Text"] )
						txt = item->Attributes["Text"]->Value;
					else if ( item->SelectNodes("Text")[0] ) txt = item->SelectNodes("Text")[0]->InnerText;
					if ( !item->Attributes["Id"] ) return "Не удалось определить Id элемента";
					if ( txt == "" ) return "Не удалось определить метку для элемента " + item->Attributes["Id"]->Value + " переменной " + vn;
					res += item->Attributes["Id"]->Value + " '" + txt->Replace("'", "\"")->Trim() + "'\n";
				}
				res += ".\n";
			}

			if ( res[res->Length - 1] != '.' ) res += ".";

			if ( res->Contains("val") ) res = res->Remove(0, res->IndexOf("val")); else res = "val lab \n" + res;
		}
		catch ( Exception^ e )
		{
			ShowError(419, "Ошибка преобразования\n\n"+e->ToString());
		}
		return res;
	}


	// создаёт список переменных по указанному шаблону имени
	String^ GenerateVarList(String^ templ)
	{
		List<String^>^ res = gcnew List<String^>();
		try
		{
			String^ prefix = "";
			String^ s = templ;
			array<wchar_t>^ div = { ';' };
			array<String^>^ opts = gcnew array<String^>(3);
			int j = 0;
			Dictionary<String^, String^>^ options = gcnew Dictionary<String^, String^>();
			int i = s->IndexOf("[");

			options->Add("expr", "#");
			options->Add("range", "1to10");
			options->Add("excl", "e{}");

			while ( i > -1 )
			{
				prefix = s->Remove(i);
				prefix = prefix->Remove(0, prefix->IndexOf("]") + 1);
				s = s->Remove(0, i + 1);
				if ( !Regex::IsMatch(s->Remove(s->IndexOf("]")), "^(((\\d+to\\d+)|((\\d+\\+)?(\\d+\\*)?#)|(\\d+)|(e\\{(\\d+,?)*\\}));?)+|\\d+$") )
				{
					ShowMessage("Синтаксис не распознан как верный шаблон");
					return "";
				}
				opts = s->Remove(s->IndexOf("]"))->Split(div);
				options["expr"] = "#";
				options["range"] = "1to10";
				options["excl"] = "e{}";
				for ( j = 0; j < opts->Length; j++ )
					if ( opts[j] )
					{
						if ( IsNumber(opts[j]) )
						{
							options["range"] = "1to" + opts[j];
							options["expr"] = "#";
						}
						if ( opts[j]->Contains("#") ) options["expr"] = opts[j];
						if ( opts[j]->Contains("to") ) options["range"] = opts[j];
						if ( opts[j]->Contains("e{") ) options["excl"] = opts[j];
					}
				i = s->IndexOf("[");
				res = MakeRange(res, prefix, options);
			}

			s = s->Remove(0, s->IndexOf("]") + 1);

			if ( s->Length > 0 )
			{
				for ( i = 0; i < res->Count; i++ )
					res[i] = res[i] + s;
			}
		}
		catch ( Exception^ e )
		{
			ShowError(420, "Ошибка преобразования\n\n" + e->ToString());
		}

		return ListToString(res, GetSeparator());
	}


	String^ TableFromXml(String^ xmlBody)
	{
		String^ res = "";
		try
		{
			if ( !(xmlBody->Contains("<Item") || xmlBody->Contains("<Answer")) ) return "Содержимое не распознано как XML";

			XmlDocument^ xml = gcnew XmlDocument();
			String^ txt = "";
			String^ vars = "";
			bool containsVars = false;

			xml->LoadXml("<root>" + xmlBody + "</root>");

			XmlNodeList^ childs = xml->SelectNodes("root")[0]->ChildNodes;
			XmlNodeList^ items;
			array<String^>^ its = { "Page", "Question", "Answer", "Item", "List" };

			for each (XmlNode^ child in childs)
			{
				// Page		
				if ( child->Name == "Page" || child->Name == "Question" )
				{
					if ( child["Question"] )
						items = child["Question"]->SelectNodes("Answer");
					else if ( child->SelectNodes("Text")[0] ) txt = child->SelectNodes("Text")[0]->InnerText;
				}
				//List
				else if ( child->Name == "List" )
				{
					items = child->SelectNodes("Item");
				}
				// Answer/Item
				else if ( child->Name == "Answer" || child->Name == "Item" )
				{
					vars = "";
					txt = "";
					containsVars = false;
					if ( !!child->Attributes["Text"] )
						txt = child->Attributes["Text"]->Value;
					else if ( child->SelectNodes("Text")[0] ) txt = child->SelectNodes("Text")[0]->InnerText;

					if ( !!child->Attributes["Var"] )
						vars = child->Attributes["Var"]->Value->Replace(",", "\t");
					else
					{
						XmlNodeList^ lst = child->SelectNodes("Var");
						if ( lst->Count > 0 )
						{
							for each (XmlNode^ var in lst)
								vars += var->InnerText + "\t";
							vars = vars->Remove(vars->LastIndexOf("\t"));
						}
					}

					if ( !child->Attributes["Id"] ) return "Не удалось определить Id элемента";
					res += child->Attributes["Id"]->Value + "\t" + txt + "\t" + vars + "\n";
					if ( vars != "" ) containsVars = true;
					continue;
				}
				else
				{
					return "Элемент " + child->Name + " не должен быть родительским!";
				}

				// Parsing
				for each (XmlNode^ item in items)
				{
					vars = "";
					txt = "";
					if ( !!item->Attributes["Text"] )
						txt = item->Attributes["Text"]->Value;
					else
						if ( item->SelectNodes("Text")[0] )	txt = item->SelectNodes("Text")[0]->InnerText;

					if ( !!item->Attributes["Var"] )
						vars = item->Attributes["Var"]->Value->Replace(",", "\t");
					else
					{
						XmlNodeList^ lst = item->SelectNodes("Var");
						if ( lst->Count > 0 )
						{
							for each (XmlNode^ var in lst)
								vars += var->InnerText + "\t";
							vars = vars->Remove(vars->LastIndexOf("\t"));
						}
					}

					if ( !item->Attributes["Id"] ) return "Не удалось определить Id элемента";
					res += item->Attributes["Id"]->Value + "\t" + txt + "\t" + vars + "\n";
					if ( vars != "" ) containsVars = true;
				}

				res += "\n";
			}
			res = "Id\tText" + (containsVars ? "\tVars" : "") + "\n" + res;
		}
		catch ( Exception^ e )
		{
			ShowError(421, "Ошибка преобразования\n\n" + e->ToString());
		}
		return res;
	}


	String^ CreateAgeList(String^ xmlBody)
	{
		List<String^>^ res = gcnew List<String^>();
		try
		{
			List<String^>^ txt = StringToList(xmlBody, '\n');
			AgeRange^ a;
			List<int>^ indexes = gcnew List<int>();
			String^ var = "", ^text = "";
			int i = 0;
			for each (String^ s in txt)
			{
				a = gcnew AgeRange(s);
				if ( !a->IsValid ) continue;
				i++;
				if ( a->Count == 1 )
				{
					if ( indexes->Count > 0 ) a->Set(a->Values[0], 99);
					else a->Set(14, a->Values[0]);
					indexes->Add(i);
				}
				res->Add("\t\t<Item Id=\"" + i + "\" Var=\"" + a->Vars + "\"><Text>" + a->Text + "</Text></Item>");
			}

			res->Insert(0, "\t<List Id=\"ageList\">");
			res->Add("\t</List>");
		}
		catch ( Exception^ e )
		{
			ShowError(422, "Ошибка преобразования\n\n" + e->ToString());
		}
		return ListToString(res, "\n");
	}


	String^ AgeLabs(String^ xmlBody)
	{
		List<String^>^ res = gcnew List<String^>();
		try
		{
			wchar_t sep = '\n';
			if ( CountSubStrings(xmlBody, "\t") > CountSubStrings(xmlBody, "\n") ) sep = '\t';
			List<String^>^ txt = StringToList(xmlBody, sep);
			AgeRange^ a;
			String^ recode = "recode age ";
			int i = 0;
			for each (String^ s in txt)
			{
				a = gcnew AgeRange(s);
				if ( !a->IsValid ) continue;
				if ( a->Count == 1 )
				{
					if ( i == 0 ) a->Set(a->Values[0], 99);
					else a->Set(14, a->Values[0]);
				}
				recode += "(" + a->Values[0].ToString() + " thru " + a->Values[1].ToString() + " = " + a->ToNumber().ToString() + ")";
				res->Add(a->ToNumber() + " \"" + a->ToString() + "\"");
				i++;
			}

			res->Insert(0, "val lab age");
			res->Add(".");
			res->Insert(0, recode + ".");
		}
		catch ( Exception^ e )
		{
			ShowError(425, "Ошибка преобразования\n\n" + e->ToString());
		}
		return ListToString(res, "\n");
	}


	String^ ValLabFromTable(String^ xmlBody)
	{
		List<String^>^ data = StringToList(xmlBody, '\n');
		List<String^>^ res = gcnew List<String^>();
		for ( int i = 0; i < data->Count; i++ )
		{
			if ( Regex::IsMatch(data[i], "^\\s*$") ) continue;
			data[i] = data[i]->Replace("'", "\"")->Trim();
			data[i] = Regex::Replace(data[i], "((?<num>\\d+)((\\.\\s*)|(\\t+))(?<text>.+))|((?<text>.+[^\\t\\n])\\t+(?<num>\\d+))", "${num} '${text}'");
			res->Add(data[i]);
		}
		return "val lab\n" + ListToString(res, "\n") + ".";
	}


	String^ DataFromTable(String^ table)
	{
		Report("Проверка формата файла");
		List<String^>^ data = StringToList(table, '\n');
		if (data->Count < 2) return "Нет данных\nВ первой строке должны быть имена переменных";
		wchar_t delimiter = '\t';//CountSubStrings(data[0], "\t") >= CountSubStrings(data[0], ";") ? '\t' : ';';
		array<String^>^ names = data[0]->Split(delimiter);
		if (names->Length == 0) return "Нет данных\nВ первой строке должны быть имена переменных";
		array<String^>^ newAr = gcnew array<String^>(data->Count - 1); // тут будем хранить новое
		
		Report("Очистка пустых данных");
		// берём только правильное
		List<int>^ empty = gcnew List<int>();
		List<int>^ ends = gcnew List<int>();
		for (int i = 0; i < data->Count; i++)
		{
			if (Regex::IsMatch(data[i], "^\\s*$")) empty->Add(i); // номера пустых строк
			if (Regex::IsMatch(data[i], "^(.*\\s+)?$")) ends->Add(i);
		}

		int length = names->Length; // количество столбцов
		/*
			при вставке из Excel почему-то каждая строка кончается на \t\n
			в ends считаем все такие строки
		*/
		if (ends->Count == data->Count) length = length - 1;

		for (int i = empty->Count - 1; i >= 0; i--)
			data->RemoveAt(empty[i]);

		Report("Данные содержат " + data->Count.ToString() +  " строк");

		Dictionary<String^, List<String^>^>^ fullData = gcnew Dictionary<String^, List<String^>^>();

		Report("Выделение переменных");

		// собираем имена переменных
		for (int i = 0; i < length; i++)
		{
			if (String::IsNullOrEmpty(names[i])) return "Не задано имя " + (i + 1).ToString() + " переменной";
			if (!fullData->ContainsKey(names[i])) fullData->Add(names[i], gcnew List<String^>());
			else return "Имена переменных не должны повторяться: '" + names[i] + "'";
		}

		Report("Переменные:\t" + String::Join(", ", names));

		array<String^>^ line;
		bool emptyFound = false;

		List<String^>^ ids = gcnew List<String^>();
		// проверяем уникальность первого столбца
		for (int i = 1; i < data->Count; i++)
		{
			line = data[i]->Split(delimiter);
			if (!ids->Contains(line[0])) ids->Add(line[0]);
			else return "Первый столбец содержит повторяющиеся значения";
		}

		Report("Все значения первого столбца уникальны");

		// получаем путь
		saveFileDialog1 = gcnew SaveFileDialog;
		saveFileDialog1->Filter = "Файл CSV(;)|*.csv|Таблица Excel|*.xls|Текстовый файл|*.txt|All files|*.*";
		saveFileDialog1->FilterIndex = 1;
		saveFileDialog1->FileName = "data.csv";
		bool fw = saveFileDialog1->ShowDialog() == Forms::DialogResult::OK;
		String^ sep = fw && Path::GetExtension(saveFileDialog1->FileName) == ".csv" ? ";" : "\t";

		if (fw)
		{
			Report("Файл будет сохранён: " + saveFileDialog1->FileName);
			Report("Сбор уникальных значений переменных и замена исходных данных");
		}
		else
		{
			Report("Сохранение файла отменено");
			Report("Сбор уникальных значений переменных");
		}

		// собираем список возможных значений
		// и сразу сохраняем intовый List
		for (int i = 1; i < data->Count; i++)
		{
			line = data[i]->Split(delimiter);
			if (line->Length < length) return "Строка " + i.ToString() + " содержит количество значений, отличное от предыдущих.";
			if (System::Array::IndexOf(line, "") > -1) emptyFound = true;
			for (int j = 1; j < length; j++)
			{
				if (!fullData[names[j]]->Contains(line[j])) fullData[names[j]]->Add(line[j]); // сохраняем новые значения
				if (fw) line[j] = (fullData[names[j]]->IndexOf(line[j]) + 1).ToString(); // заменяем значение на индекс из листа
			}
			if (fw) newAr[i - 1] = String::Join(sep, line);
		}

		if (emptyFound) ShowWarning("В данных найдены пустые значения");

		if (fw && newAr->Length != data->Count - 1)
		{
			ShowWarning("Ошибка при проверке результатов: не сходится количество строк");
			return "Ошибка при проверке результатов: не сходится количество строк";
		}

		Report("Проверка данных прошла успешно");

		// сохраняем таблицу данных в файл
		if (fw)
		{
			Report("Сохранение файла");
			if (Path::GetExtension(saveFileDialog1->FileName) == ".xls")
				ExportToExcel(newAr, saveFileDialog1->FileName);
			else
				WriteFile(saveFileDialog1->FileName, newAr);
		}

		Report("Файл успешно сохранён");
		Report("Формирование листов");

		// сохраняем XML листы
		List<Items^>^ listList = gcnew List<Items^>();
		String^ res = "";
		for each (KeyValuePair<String^, List<String^>^> element in fullData)
		{
			if (element.Value->Count == data->Count - 1) continue;
			res += "\t<List Id=\"" + element.Key + "_List\">\n";
			for (int i = 0; i < element.Value->Count; i++)
			{
				res += "\t\t<Item Id=\"" + (i + 1).ToString() + "\"><Text>" + element.Value[i] + "</Text></Item>\n";
			}
			res += "\t</List>\n\n";
		}

		return res;
	}


	private: System::Void genButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		resultTex->Clear();

		switch ( convertType->SelectedIndex )
		{
			case 0:
				resultTex->Text = LabsFromXml(sourceText->Text);
				break;

			case 1:
				resultTex->Text = ValLabFromTable(sourceText->Text);
				break;

			case 2:
				resultTex->Text = TableFromXml(sourceText->Text);
				break;

			case 3: 
				resultTex->Text = GenerateVarList(sourceText->Text);
				break;

			case 4:
				resultTex->Text = CreateAgeList(sourceText->Text);
				break;

			case 5:
				resultTex->Text = AgeLabs(sourceText->Text);
				break;

			case 6:
				resultTex->Text = DataFromTable(sourceText->Text);
				break;

			default:
				break;
		}
		if ( bufToolStripMenuItem->Checked ) CopyToBuffer(resultTex->Text);
		//sourceText->Text = sourceText->Text->Replace("\t", "")->Trim();
	}


	private: System::Void KeyPressed(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
	{
		switch ( e->KeyCode )
		{
			case Keys::F5: genButton->PerformClick();
				break;

			case Keys::F9: 
			{
				resultTex->Clear();
				sourceText->Clear();
				break;
			}

			default:
				break;
		}
	}
	

	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e)
	{
		OpenUrl(_appDataDir + L"\\Help.html?t=help&vers="+ curVers +"&t2=conv");
	}
			 

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		saveFileDialog1 = gcnew SaveFileDialog;
		saveFileDialog1->Filter = "Файл MS Excel|*.xls|Текстовый файл|*.txt|All files|*.*";
		saveFileDialog1->FilterIndex = 1;
		saveFileDialog1->RestoreDirectory = true;
		if ( saveFileDialog1->ShowDialog() == Forms::DialogResult::OK )
			if ( saveFileDialog1->FilterIndex == 0 )
				ExportToExcel(resultTex->Text->Split('\n'), saveFileDialog1->FileName);
			else
				WriteFile(saveFileDialog1->FileName, resultTex->Text->Split('\n'));
	}


	private: System::Void SurveyConverter_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e)
	{
		Settings^ settings = gcnew Settings();

		settings->Set("Separator", separatorsItem->SelectedIndex);
		settings->Set("ConvertIndex", convertType->SelectedIndex);
		settings->Set("CopyToBuffer", bufToolStripMenuItem->Checked);
		settings->Set("Left", this->DesktopLocation.X);
		settings->Set("Top", this->DesktopLocation.Y);
		settings->Set("Width", this->Width);
		settings->Set("Height", this->Height);
		if ( this->WindowState == Forms::FormWindowState::Maximized ) settings->Set("State", 2); else settings->Set("State", 0);

		if ( !settings->Save("ConverterForm") ) ShowWarning("Ошибка. Настройки не были сохранены.");
	}


	private: System::Void SurveyConverter_Shown(System::Object^  sender, System::EventArgs^  e)
	{
		Settings^ settings = gcnew Settings();
		if ( !settings->Exist("ConverterForm") ) return;
		if ( settings->Read("ConverterForm") > 0 )
		{
			try
			{
				this->Height = settings->Get("Height", true);
				this->Width = settings->Get("Width", true);
				this->DesktopLocation = Point(settings->Get("Left", true), settings->Get("Top", true));
				bufToolStripMenuItem->Checked = settings->Get("CopyToBuffer", true);
				separatorsItem->SelectedIndex = settings->Get("Separator", true);
				convertType->SelectedIndex = settings->Get("ConvertIndex", true);
				this->WindowState = (Forms::FormWindowState)settings->Get("State", true);
			}
			catch ( Exception^ e )
			{
				ShowWarning("Ошибка загрузки настроек");
			}
		}
	}

	private: System::Void separatorsItem_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
	{
		customSep->Text = "Другой разделитель";
	}

	private: System::Void customSep_Click(System::Object^  sender, System::EventArgs^  e)
	{
		customSep->SelectAll();
	}

};