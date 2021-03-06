#pragma once


#include "Classes.h"


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::Text::RegularExpressions;

public ref class SurveyConverter : public System::Windows::Forms::Form
{
	public:
	String ^ curVers = "";
	String^ lasVers = "";
	private: System::Windows::Forms::ToolStripTextBox^  customSep;
	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	private: System::Windows::Forms::Button^  button3;


	public:	Dictionary<int, String^>^ Separators = gcnew Dictionary<int, String^>();


	public: SurveyConverter(String^ cv)
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

		String^ FileFilter = "������� Excel|*.xls;*.xlsx|���� CSV(;)|*.csv|��������� ����|*.txt|All files|*.*";

		saveFileDialog1 = gcnew SaveFileDialog();
		saveFileDialog1->Filter = FileFilter;
		saveFileDialog1->FilterIndex = 1;
		saveFileDialog1->FileName = "data";
		saveFileDialog1->RestoreDirectory = true;

		openFileDialog1 = gcnew OpenFileDialog();
		openFileDialog1->Filter = FileFilter;
		openFileDialog1->FilterIndex = 1;
		openFileDialog1->Multiselect = false;
	}


#pragma region Windows Form Designer generated code
	protected:

	~SurveyConverter()
	{
		if (components)
		{
			delete components;
		}
	}

	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^  ���������ToolStripMenuItem;
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
			 /// ��������� ����� ��� ��������� ������������ � �� ��������� 
			 /// ���������� ����� ������ � ������� ��������� ����.
			 /// </summary>
	private: void InitializeComponent(void)
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
		this->button3 = (gcnew System::Windows::Forms::Button());
		this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
		this->���������ToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
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
		this->tableLayoutPanel1->Location = System::Drawing::Point(0, 24);
		this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
		this->tableLayoutPanel1->RowCount = 2;
		this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
		this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
		this->tableLayoutPanel1->Size = System::Drawing::Size(776, 318);
		this->tableLayoutPanel1->TabIndex = 0;
		// 
		// sourceText
		// 
		this->sourceText->Dock = System::Windows::Forms::DockStyle::Fill;
		this->sourceText->Location = System::Drawing::Point(3, 33);
		this->sourceText->Margin = System::Windows::Forms::Padding(3, 3, 7, 3);
		this->sourceText->Name = L"sourceText";
		this->sourceText->Size = System::Drawing::Size(378, 282);
		this->sourceText->TabIndex = 0;
		this->sourceText->Text = L"";
		// 
		// resultTex
		// 
		this->resultTex->Dock = System::Windows::Forms::DockStyle::Fill;
		this->resultTex->Location = System::Drawing::Point(395, 33);
		this->resultTex->Margin = System::Windows::Forms::Padding(7, 3, 3, 3);
		this->resultTex->Name = L"resultTex";
		this->resultTex->Size = System::Drawing::Size(378, 282);
		this->resultTex->TabIndex = 2;
		this->resultTex->Text = L"";
		// 
		// tableLayoutPanel2
		// 
		this->tableLayoutPanel2->ColumnCount = 2;
		this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
			144)));
		this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			100)));
		this->tableLayoutPanel2->Controls->Add(this->convertType, 1, 0);
		this->tableLayoutPanel2->Controls->Add(this->label1, 0, 0);
		this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
		this->tableLayoutPanel2->Location = System::Drawing::Point(3, 3);
		this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
		this->tableLayoutPanel2->RowCount = 1;
		this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
		this->tableLayoutPanel2->Size = System::Drawing::Size(382, 24);
		this->tableLayoutPanel2->TabIndex = 3;
		// 
		// convertType
		// 
		this->convertType->BackColor = System::Drawing::SystemColors::Window;
		this->convertType->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
		this->convertType->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
		this->convertType->FormattingEnabled = true;
		this->convertType->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
			L"Val lab �� Answer / Item", L"Val lab �� �������",
				L"������� �� Answer / Item", L"�������� ����������", L"������ ���������� �����", L"Val lab �� ���������� �����", L"������ ������"
		});
		this->convertType->Location = System::Drawing::Point(147, 3);
		this->convertType->Name = L"convertType";
		this->convertType->Size = System::Drawing::Size(232, 21);
		this->convertType->TabIndex = 0;
		this->toolTip1->SetToolTip(this->convertType, L"�������� ������ ��������");
		// 
		// label1
		// 
		this->label1->AutoSize = true;
		this->label1->Dock = System::Windows::Forms::DockStyle::Left;
		this->label1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
		this->label1->Location = System::Drawing::Point(3, 3);
		this->label1->Margin = System::Windows::Forms::Padding(3);
		this->label1->Name = L"label1";
		this->label1->Size = System::Drawing::Size(116, 18);
		this->label1->TabIndex = 1;
		this->label1->Text = L"��� ��������������:";
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
		this->tableLayoutPanel3->Location = System::Drawing::Point(391, 3);
		this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
		this->tableLayoutPanel3->RowCount = 1;
		this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
		this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 24)));
		this->tableLayoutPanel3->Size = System::Drawing::Size(382, 24);
		this->tableLayoutPanel3->TabIndex = 4;
		// 
		// genButton
		// 
		this->genButton->Location = System::Drawing::Point(3, 0);
		this->genButton->Margin = System::Windows::Forms::Padding(3, 0, 0, 0);
		this->genButton->Name = L"genButton";
		this->genButton->Size = System::Drawing::Size(109, 24);
		this->genButton->TabIndex = 1;
		this->genButton->Text = L"�������������";
		this->genButton->UseVisualStyleBackColor = true;
		this->genButton->Click += gcnew System::EventHandler(this, &SurveyConverter::genButton_Click);
		// 
		// button2
		// 
		this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
		this->button2->Location = System::Drawing::Point(271, 0);
		this->button2->Margin = System::Windows::Forms::Padding(0);
		this->button2->Name = L"button2";
		this->button2->Size = System::Drawing::Size(111, 24);
		this->button2->TabIndex = 1;
		this->button2->Text = L"�������";
		this->button2->UseVisualStyleBackColor = true;
		this->button2->Click += gcnew System::EventHandler(this, &SurveyConverter::button2_Click);
		// 
		// button1
		// 
		this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
		this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
		this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
		this->button1->Location = System::Drawing::Point(745, -1);
		this->button1->Margin = System::Windows::Forms::Padding(0);
		this->button1->Name = L"button1";
		this->button1->Size = System::Drawing::Size(28, 25);
		this->button1->TabIndex = 2;
		this->toolTip1->SetToolTip(this->button1, L"��������� ���������");
		this->button1->UseVisualStyleBackColor = true;
		this->button1->Click += gcnew System::EventHandler(this, &SurveyConverter::button1_Click);
		// 
		// button3
		// 
		this->button3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
		this->button3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button3.BackgroundImage")));
		this->button3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
		this->button3->Location = System::Drawing::Point(713, -1);
		this->button3->Margin = System::Windows::Forms::Padding(0);
		this->button3->Name = L"button3";
		this->button3->Size = System::Drawing::Size(28, 25);
		this->button3->TabIndex = 3;
		this->toolTip1->SetToolTip(this->button3, L"��������� ������ �� �����");
		this->button3->UseVisualStyleBackColor = true;
		this->button3->Click += gcnew System::EventHandler(this, &SurveyConverter::button3_Click);
		// 
		// menuStrip1
		// 
		this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
		this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->���������ToolStripMenuItem });
		this->menuStrip1->Location = System::Drawing::Point(0, 0);
		this->menuStrip1->Name = L"menuStrip1";
		this->menuStrip1->Size = System::Drawing::Size(776, 24);
		this->menuStrip1->TabIndex = 1;
		this->menuStrip1->Text = L"menuStrip1";
		// 
		// ���������ToolStripMenuItem
		// 
		this->���������ToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
			this->bufToolStripMenuItem,
				this->separatorToolStripMenuItem
		});
		this->���������ToolStripMenuItem->Name = L"���������ToolStripMenuItem";
		this->���������ToolStripMenuItem->Size = System::Drawing::Size(83, 20);
		this->���������ToolStripMenuItem->Text = L"���������";
		// 
		// bufToolStripMenuItem
		// 
		this->bufToolStripMenuItem->Checked = true;
		this->bufToolStripMenuItem->CheckOnClick = true;
		this->bufToolStripMenuItem->CheckState = System::Windows::Forms::CheckState::Checked;
		this->bufToolStripMenuItem->Name = L"bufToolStripMenuItem";
		this->bufToolStripMenuItem->Size = System::Drawing::Size(186, 22);
		this->bufToolStripMenuItem->Text = L"���������� � �����";
		this->bufToolStripMenuItem->ToolTipText = L"���������� ��������� � ����� ������ ����� ����� ���������� ��������������";
		// 
		// separatorToolStripMenuItem
		// 
		this->separatorToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
			this->separatorsItem,
				this->customSep
		});
		this->separatorToolStripMenuItem->Name = L"separatorToolStripMenuItem";
		this->separatorToolStripMenuItem->Size = System::Drawing::Size(186, 22);
		this->separatorToolStripMenuItem->Text = L"�����������";
		// 
		// separatorsItem
		// 
		this->separatorsItem->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
		this->separatorsItem->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
			L"�������", L"���������", L"������", L"����� � �������",
				L"�������"
		});
		this->separatorsItem->Name = L"separatorsItem";
		this->separatorsItem->Size = System::Drawing::Size(121, 23);
		this->separatorsItem->SelectedIndexChanged += gcnew System::EventHandler(this, &SurveyConverter::separatorsItem_SelectedIndexChanged);
		// 
		// customSep
		// 
		this->customSep->Name = L"customSep";
		this->customSep->Size = System::Drawing::Size(120, 23);
		this->customSep->Text = L"������ �����������";
		this->customSep->Click += gcnew System::EventHandler(this, &SurveyConverter::customSep_Click);
		// 
		// SurveyConverter
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->BackColor = System::Drawing::SystemColors::AppWorkspace;
		this->ClientSize = System::Drawing::Size(776, 342);
		this->Controls->Add(this->button3);
		this->Controls->Add(this->button1);
		this->Controls->Add(this->tableLayoutPanel1);
		this->Controls->Add(this->menuStrip1);
		this->MinimumSize = System::Drawing::Size(600, 298);
		this->Name = L"SurveyConverter";
		this->ShowIcon = false;
		this->ShowInTaskbar = false;
		this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
		this->Text = L"��������������";
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



#pragma region ��� �������

	private: List<String^>^ MakeRange(List<String^>^ store, String^ prefix, Dictionary<String^, String^>^ options)
	{
		List<String^>^ res = gcnew List<String^>();
		RangeTemplate^ range = gcnew RangeTemplate(options["range"]);
		IteraTemplate^ itera = gcnew IteraTemplate(options["expr"]);
		ExcludeTemplate^ excl = gcnew ExcludeTemplate(options["excl"]);

		if (!range->Valid || !itera->Valid || !excl->Valid)
		{
			ShowMessage("��������� �� ��������� ��� ������ ������");
			return res;
		}

		if (store->Count == 0) store->Add("");

		for each (String^ s in store)
		{
			for (int i = range->Min; i <= range->Max; i++)
				if (!excl->Items->Contains(i)) res->Add(s + prefix + itera->Evaluate(i));
		}
		return res;
	}

	private: String ^ GetSeparator()
	{
		if (customSep->Text != "������ �����������") return customSep->Text;
		return Separators[separatorsItem->SelectedIndex];
	}

	private: void Report(String^ str)
	{
		resultTex->Text += str + "\n";
		resultTex->Update();
	}


#pragma endregion


			 // ��������� val lab �� XML
	private: String ^ LabsFromXml(String^ xmlBody)
	{
		String^ res = "";
		try
		{
			if (!(xmlBody->Contains("<Item") || xmlBody->Contains("<Answer"))) return "���������� �� ���������� ��� XML";

			XmlDocument^ xml = gcnew XmlDocument();
			String^ vn = "";
			String^ txt = "";

			xml->LoadXml("<root>" + xmlBody + "</root>");

			XmlNodeList^ childs = xml->SelectNodes("root")[0]->ChildNodes;
			XmlNodeList^ items;
			array<String^>^ its = { "Page", "Question", "Answer", "Item", "List" };

			for each (XmlNode^ child in childs)
			{
				if (child->NodeType == XmlNodeType::Comment) continue;
				txt = "";
				// Page		
				if (child->Name == "Page" || child->Name == "Question")
				{
					if (child["Question"])
					{
						vn = child["Question"]->Attributes["Id"]->Value;
						items = child["Question"]->SelectNodes("Answer");
					}
					else if (child->SelectNodes("Text")[0]) txt = child->SelectNodes("Text")[0]->InnerText;
					vn = child->Attributes["Id"]->Value;
					res += "val lab " + vn + "\n";
				}
				//List
				else if (child->Name == "List")
				{
					items = child->SelectNodes("Item");
					vn = Regex::Replace(child->Attributes["Id"]->Value, "_?Li?st_?", "", System::Text::RegularExpressions::RegexOptions::IgnoreCase);
					res += "val lab " + vn + "\n";
				}
				// Answer/Item
				else if (child->Name == "Answer" || child->Name == "Item")
				{
					if (!!child->Attributes["Text"])
						txt = child->Attributes["Text"]->Value;
					else if (child->SelectNodes("Text")[0]) txt = child->SelectNodes("Text")[0]->InnerText;
					if (!child->Attributes["Id"]) return "�� ������� ���������� Id ��������";
					if (txt == "") return "�� ������� ���������� ����� ��� �������� " + child->Attributes["Id"]->Value + " ���������� " + vn;
					if (!child->PreviousSibling || child->PreviousSibling->Name != "Answer" && child->PreviousSibling->Name != "Item" && child->PreviousSibling->NodeType != XmlNodeType::Comment) res += "val lab \n";
					res += child->Attributes["Id"]->Value + " '" + txt->Replace("'", "\"")->Trim() + "'\n";
					continue;
				}
				else
				{
					return "������� <" + child->Name + "> �� ������ ���� ������������!";
				}

				// Parsing
				for each (XmlNode^ item in items)
				{
					txt = "";
					if (!!item->Attributes["Text"])
						txt = item->Attributes["Text"]->Value;
					else if (item->SelectNodes("Text")[0]) txt = item->SelectNodes("Text")[0]->InnerText;
					if (!item->Attributes["Id"]) return "�� ������� ���������� Id ��������";
					if (txt == "") return "�� ������� ���������� ����� ��� �������� " + item->Attributes["Id"]->Value + " ���������� " + vn;
					res += item->Attributes["Id"]->Value + " '" + txt->Replace("'", "\"")->Trim() + "'\n";
				}
				res += ".\n";
			}

			if (res[res->Length - 1] != '.') res += ".";

			if (res->Contains("val")) res = res->Remove(0, res->IndexOf("val")); else res = "val lab \n" + res;
		}
		catch (Exception^ e)
		{
			ShowError(419, "������ ��������������\n\n" + e->ToString());
		}
		return res;
	}


			 // ������ ������ ���������� �� ���������� ������� �����
	private:String ^ GenerateVarList(String^ templ)
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

			while (i > -1)
			{
				prefix = s->Remove(i);
				prefix = prefix->Remove(0, prefix->IndexOf("]") + 1);
				s = s->Remove(0, i + 1);
				if (!Regex::IsMatch(s->Remove(s->IndexOf("]")), "^(((\\d+to\\d+)|((\\d+\\+)?(\\d+\\*)?#)|(\\d+)|(e\\{(\\d+,?)*\\}));?)+|\\d+$"))
				{
					ShowMessage("��������� �� ��������� ��� ������ ������");
					return "";
				}
				opts = s->Remove(s->IndexOf("]"))->Split(div);
				options["expr"] = "#";
				options["range"] = "1to10";
				options["excl"] = "e{}";
				for (j = 0; j < opts->Length; j++)
					if (opts[j])
					{
						if (IsNumber(opts[j]))
						{
							options["range"] = "1to" + opts[j];
							options["expr"] = "#";
						}
						if (opts[j]->Contains("#")) options["expr"] = opts[j];
						if (opts[j]->Contains("to")) options["range"] = opts[j];
						if (opts[j]->Contains("e{")) options["excl"] = opts[j];
					}
				i = s->IndexOf("[");
				res = MakeRange(res, prefix, options);
			}

			s = s->Remove(0, s->IndexOf("]") + 1);

			if (s->Length > 0)
			{
				for (i = 0; i < res->Count; i++)
					res[i] = res[i] + s;
			}
		}
		catch (Exception^ e)
		{
			ShowError(420, "������ ��������������\n\n" + e->ToString());
		}

		return ListToString(res, GetSeparator());
	}


	private: String ^ TableFromXml(String^ xmlBody)
	{
		String^ res = "";
		try
		{
			if (!(xmlBody->Contains("<Item") || xmlBody->Contains("<Answer"))) return "���������� �� ���������� ��� XML";

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
				if (child->NodeType == XmlNodeType::Comment) continue;
				// Page		
				if (child->Name == "Page" || child->Name == "Question")
				{
					if (child["Question"])
						items = child["Question"]->SelectNodes("Answer");
					else if (child->SelectNodes("Text")[0]) txt = child->SelectNodes("Text")[0]->InnerText;
				}
				//List
				else if (child->Name == "List")
				{
					items = child->SelectNodes("Item");
				}
				// Answer/Item
				else if (child->Name == "Answer" || child->Name == "Item")
				{
					vars = "";
					txt = "";
					containsVars = false;
					if (!!child->Attributes["Text"])
						txt = child->Attributes["Text"]->Value;
					else if (child->SelectNodes("Text")[0]) txt = child->SelectNodes("Text")[0]->InnerText;

					if (!!child->Attributes["Var"])
						vars = child->Attributes["Var"]->Value->Replace(",", "\t");
					else
					{
						XmlNodeList^ lst = child->SelectNodes("Var");
						if (lst->Count > 0)
						{
							for each (XmlNode^ var in lst)
								vars += var->InnerText + "\t";
							vars = vars->Remove(vars->LastIndexOf("\t"));
						}
					}

					if (!child->Attributes["Id"]) return "�� ������� ���������� Id ��������";
					res += child->Attributes["Id"]->Value + "\t" + txt + "\t" + vars + "\n";
					if (vars != "") containsVars = true;
					continue;
				}
				else
				{
					return "������� " + child->Name + " �� ������ ���� ������������!";
				}

				// Parsing
				for each (XmlNode^ item in items)
				{
					vars = "";
					txt = "";
					if (!!item->Attributes["Text"])
						txt = item->Attributes["Text"]->Value;
					else
						if (item->SelectNodes("Text")[0])	txt = item->SelectNodes("Text")[0]->InnerText;

					if (!!item->Attributes["Var"])
						vars = item->Attributes["Var"]->Value->Replace(",", "\t");
					else
					{
						XmlNodeList^ lst = item->SelectNodes("Var");
						if (lst->Count > 0)
						{
							for each (XmlNode^ var in lst)
								vars += var->InnerText + "\t";
							vars = vars->Remove(vars->LastIndexOf("\t"));
						}
					}

					if (!item->Attributes["Id"]) return "�� ������� ���������� Id ��������";
					res += item->Attributes["Id"]->Value + "\t" + txt + "\t" + vars + "\n";
					if (vars != "") containsVars = true;
				}

				res += "\n";
			}
			res = "Id\tText" + (containsVars ? "\tVars" : "") + "\n" + res;
		}
		catch (Exception^ e)
		{
			ShowError(421, "������ ��������������\n\n" + e->ToString());
		}
		return res;
	}


	private: String ^ CreateAgeList(String^ xmlBody)
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
				if (!a->IsValid) continue;
				i++;
				if (a->Count == 1)
				{
					if (indexes->Count > 0) a->Set(a->Values[0], 99);
					else a->Set(14, a->Values[0]);
					indexes->Add(i);
				}
				res->Add("\t\t<Item Id=\"" + i + "\" Var=\"" + a->Vars + "\"><Text>" + a->Text + "</Text></Item>");
			}

			res->Insert(0, "\t<List Id=\"ageList\">");
			res->Add("\t</List>");
		}
		catch (Exception^ e)
		{
			ShowError(422, "������ ��������������\n\n" + e->ToString());
		}
		return ListToString(res, "\n");
	}


	private: String ^ AgeLabs(String^ xmlBody)
	{
		List<String^>^ res = gcnew List<String^>();
		try
		{
			wchar_t sep = '\n';
			if (CountSubStrings(xmlBody, "\t") > CountSubStrings(xmlBody, "\n")) sep = '\t';
			List<String^>^ txt = StringToList(xmlBody, sep);
			AgeRange^ a;
			String^ recode = "recode age ";
			int i = 0;
			for each (String^ s in txt)
			{
				a = gcnew AgeRange(s);
				if (!a->IsValid) continue;
				if (a->Count == 1)
				{
					if (i == 0) a->Set(a->Values[0], 99);
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
		catch (Exception^ e)
		{
			ShowError(425, "������ ��������������\n\n" + e->ToString());
		}
		return ListToString(res, "\n");
	}


	private: String ^ ValLabFromTable(String^ xmlBody)
	{
		List<String^>^ data = StringToList(xmlBody, '\n');
		List<String^>^ res = gcnew List<String^>();
		for (int i = 0; i < data->Count; i++)
		{
			if (Regex::IsMatch(data[i], "^\\s*$")) continue;
			data[i] = data[i]->Replace("'", "\"")->Trim();
			data[i] = Regex::Replace(data[i], "((?<num>\\d+)((\\.\\s*)|(\\t+))(?<text>.+))|((?<text>.+[^\\t\\n])\\t+(?<num>\\d+))", "${num} '${text}'");
			res->Add(data[i]);
		}
		return "val lab\n" + ListToString(res, "\n") + ".";
	}


	private: String ^ DataFromTable(String^ table)
	{
		Report("> �������� ������� ������...");

		List<String^>^ data = StringToList(table, '\n');
		if (data->Count < 2) return "��� ������";
		wchar_t delimiter = '\t';//CountSubStrings(data[0], "\t") >= CountSubStrings(data[0], ";") ? '\t' : ';';
		array<String^>^ names = data[0]->Split(delimiter);

		if (names->Length < 2) return "��� ������";

		List<int>^ ends = gcnew List<int>();
		List<int>^ empty = gcnew List<int>();
		array<String^>^ line;
		List<String^>^ ids = gcnew List<String^>();
		Dictionary<String^, List<String^>^>^ fullData = gcnew Dictionary<String^, List<String^>^>();
		bool emptyFound = false;
		List<String^>^ longVars = gcnew List<String^>();
		String^ separator = ""; // ����������� ��� ����������
		FileType tp;

		/*
			������ ������ �� data:
				- ��� ������� �� Excel ������-�� ������ ������ ��������� �� \t\n. � ends ������� ��� ����� ������
				- ������� ������, ����� �� ������ �� � ��� � �� �������������� (������� ��� � �����)
		*/
		for (int i = data->Count - 1; i >= 0; i--)
		{
			if (Regex::IsMatch(data[i], "^\\s*$"))
			{
				data->RemoveAt(i);
				continue;
			}
			if (Regex::IsMatch(data[i], "^(.*\\s+)?$")) ends->Add(i);
		}

		array<String^>^ newAr = gcnew array<String^>(data->Count - 1); // ��� ����� ������� �����

		int length = names->Length; // ���������� ��������
		if (ends->Count == data->Count) length = length - 1; // ���� ��� \t\n$, �� ��������� �� �������

		Report("������ �������� " + (data->Count - 1).ToString() + " �����");
		Report("> ��������� ����������...");

		// ��������, ������� � ��������� ����� ����������
		for (int i = 1; i < length; i++)
		{
			names[i] = names[i]->Trim();
			if (!Regex::IsMatch(names[i], "^\\w+$")) return "������ ������ ������ ��������� ������ ���������� ����� ����������";
			if (!fullData->ContainsKey(names[i])) fullData->Add(names[i], gcnew List<String^>());
			else return "����� ���������� �� ������ �����������: '" + names[i] + "'";
		}

		bool needSeparate = false;
		if (names->Length > 5)
		{
			needSeparate = MessageBox::Show((length - 1).ToString() + " ���������� � ��� �����, ���������� ��� ���������� � ������?",
				"", System::Windows::Forms::MessageBoxButtons::YesNoCancel,
				System::Windows::Forms::MessageBoxIcon::Information) == Forms::DialogResult::Yes;
			Report("> ����� ����������� �����������...");
			if (needSeparate)
			{
				// �������� ������������
				List<String^>^ separators = gcnew List<String^>(gcnew array<String^>{"#", "*", "/", ","});
				for (int k = separators->Count - 1; k >= 0; k--)
				{
					if (table->IndexOf(separators[k]) > -1) separators->RemoveAt(k);
					else
					{
						separator = separators[k];
						break;
					}
				}
				if (separator != "") Report("������ ����������� '" + separator + "'");
				else
				{
					needSeparate = false;
					ShowWarning("���������� ����������� �� ������, �������� �� ����� ���������� � ������");
				}
			}
		}

		Report("����������:\t" + String::Join(", ", names));

		// �������� ����
		saveFileDialog1->FilterIndex = 2;
		bool fw = saveFileDialog1->ShowDialog() == Forms::DialogResult::OK;

		tp = GetFileType(saveFileDialog1->FileName);
		String^ sep = fw && tp == FileType::CSV ? ";" : "\t"; // ����������� ��� �����

		if (fw)
		{
			Report("���� ����� ��������: " + saveFileDialog1->FileName);
			Report("> ���� ���������� �������� ���������� � ����������� ������...");
		}
		else
		{
			Report("���������� ����� ��������");
			Report("> ���� ���������� �������� ����������...");
		}

		// �������� ������ ��������� ��������
		// � ����� ��������� int���� List
		for (int i = 1; i < data->Count; i++)
		{
			if (empty->Contains(i)) continue; // ���������� ������
			line = data[i]->Split(delimiter);
			if (!ids->Contains(line[0])) ids->Add(line[0]); // ��������� ������������
			else return "������ ������� �������� ������������� ��������";
			if (line->Length < length) return "������ " + i.ToString() + " �������� ���������� ��������, �������� �� ����������.";
			if (System::Array::IndexOf(line, "") > -1) emptyFound = true;
			for (int j = 1; j < length; j++)
			{
				if (!fullData[names[j]]->Contains(line[j])) fullData[names[j]]->Add(line[j]); // ��������� ����� ��������
				if (fw) line[j] = (fullData[names[j]]->IndexOf(line[j]) + 1).ToString(); // �������� �������� �� ������ �� �����
			}
			if (fw)
			{
				if (needSeparate)
				{
					// ��������� Id � ������������ ���������� ����� ��� ����� �������
					newAr[i - 1] = line[0] + sep;
					Array::Reverse(line);
					Array::Resize(line, line->Length - 1);
					Array::Reverse(line);
					newAr[i - 1] = newAr[i - 1] + String::Join(separator, line);
				}
				else newAr[i - 1] = String::Join(sep, line);
			}
		}

		// �������� ������ ��������
		if (fw && newAr->Length != data->Count - 1) return "������ ��� �������� �����������: �� �������� ���������� �����";
		Report("> ����� ��������� ��������� ����������...");
		for (int j = 1; j < length; j++)
			if (fullData[names[j]]->Count > 0.7 * data->Count) longVars->Add(names[j]);
		if (longVars->Count > 0)
			ShowWarning("���������� " + String::Join(", ", longVars) + " �������� ������������ ������� ����� ���������� ��������.\n��������, �� �� ����� ����������");
		if (emptyFound) ShowWarning("� ������ ������� ������ ��������.\n��� �� �������, ������ � ����� ����� �������� � ������ �������");

		Report("�������� ������ ������ �������");

		// ��������� ������� ������ � ����
		if (fw)
		{
			Report("> ���������� �����...");
			if (tp == FileType::Excel)
			{
				if (!ExportToExcel(newAr, saveFileDialog1->FileName)) return "������ ���������� ������. ���������� CSV";
			}
			else
			{
				if (!WriteFile(saveFileDialog1->FileName, newAr)) return "������ ���������� ������";
			}
			Report("���� ������� ��������");
		}

		// ��������� XML �����
		Report("> ������������ ������...");
		List<Items^>^ listList = gcnew List<Items^>();
		String^ res = "";
		for each (KeyValuePair<String^, List<String^>^> element in fullData)
		{
			if (element.Key == names[0]) continue; // ������� Id
			res += "\t<List Id=\"" + element.Key + "_List\">\n";
			for (int i = 0; i < element.Value->Count; i++)
			{
				res += "\t\t<Item Id=\"" + (i + 1).ToString() + "\"><Text>" + element.Value[i] + "</Text></Item>\n";
			}
			res += "\t</List>\n\n";
		}

		res += "\t<List Id=\"dataList\">\n";
		for (int i = 1; i < length; i++)
		{
			res += "\t\t<Item Id=\"" + (i - 1).ToString() + "\"><Var>" + names[i] + "</Var><Text>" + names[i] + "</Text></Item>\n";
		}
		res += "\t</List>\n\n";

		Report("������������ XML+C# ����������");

		res += "\t<Page Id=\"RespInfo\">\n\t\t<Filter>false;</Filter>\n";
		res += "\t\t\<Repeat List=\"dataList\">\n\t\t\t<Question Id=\"@Pure\" Imperative=\"false\">\n\t\t\t\t<Filter>false;</Filter>\n\t\t\t\t<Header>@Var(0)</Header>\n\t\t\t\t<Repeat List=\"@Pure_List\">\n\t\t\t\t\t<Answer Id=\"@ID\"><Text>@Text</Text></Answer>\n\t\t\t\t</Repeat>\n\t\t\t</Question>\n\t\t</Repeat>\n";
		res += "\t\t<Redirect>\n\t\t\tstring[][] data = DataGetCustoms(0/*�����!*/, InterviewPars.RespID);\n\t\t\tif (data.Length == 0) return false;\n\t\t\t";
		if (needSeparate)
			res += "string[] vals = data[0][0].Split('" + separator + "');";
		else
			res += "string[] vals = data[0];";
		res += "\n\t\t\tif (CurrentSurvey.Lists[\"dataList\"].Items.Count != vals.Length) return false;\n\t\t\tforeach (SurveyListItem item in CurrentSurvey.Lists[\"dataList\"].Items)\n\t\t\t\tAnswerUpdateP(\"RespInfo\", item.Text, vals[int.Parse(item.ID)]);\n\t\t\treturn false;\n\t\t</Redirect>\n\t</Page>\n";


		Report("�� ������!");

		// �������� �����
		if (fw && MessageBox::Show(
			"�� ������!\n������� ���� � ��������������� �������?",
			"", System::Windows::Forms::MessageBoxButtons::YesNoCancel,
			System::Windows::Forms::MessageBoxIcon::Information) == Forms::DialogResult::Yes)
			Run(saveFileDialog1->FileName);

		return res;
	}


	private: System::Void genButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		resultTex->Clear();

		switch (convertType->SelectedIndex)
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
		if (bufToolStripMenuItem->Checked) CopyToBuffer(resultTex->Text);
		//sourceText->Text = sourceText->Text->Replace("\t", "")->Trim();
	}


	private: System::Void KeyPressed(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
	{
		switch (e->KeyCode)
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
		OpenUrl(_appDataDir + L"\\Help.html?t=help&vers=" + curVers + "&t2=conv");
	}


	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (saveFileDialog1->ShowDialog() == Forms::DialogResult::OK)
		{
			if (GetFileType(saveFileDialog1->FileName) == FileType::Excel)
				ExportToExcel(resultTex->Text->Split('\n'), saveFileDialog1->FileName);
			else
				WriteFile(saveFileDialog1->FileName, resultTex->Text->Split('\n'));
		}
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
		if (this->WindowState == Forms::FormWindowState::Maximized) settings->Set("State", 2); else settings->Set("State", 0);

		if (!settings->Save("ConverterForm")) ShowWarning("������. ��������� �� ���� ���������.");
	}


	private: System::Void SurveyConverter_Shown(System::Object^  sender, System::EventArgs^  e)
	{
		Settings^ settings = gcnew Settings();
		if (!settings->Exist("ConverterForm")) return;
		if (settings->Read("ConverterForm") > 0)
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
			catch (Exception^ e)
			{
				ShowWarning("������ �������� ��������");
			}
		}
	}


	private: System::Void separatorsItem_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
	{
		customSep->Text = "������ �����������";
	}


	private: System::Void customSep_Click(System::Object^  sender, System::EventArgs^  e)
	{
		customSep->SelectAll();
	}


	private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e)
	{
		resultTex->Clear();

		if (openFileDialog1->ShowDialog() == Forms::DialogResult::OK)
		{
			FileType tp = GetFileType(openFileDialog1->FileName);
			Report("> �������� ������ �� �����...");
			if (tp != FileType::Excel)
			{
				array<String^>^ ar = ReadFile(openFileDialog1->FileName);
				if (ar != nullptr) sourceText->Text = String::Join(Environment::NewLine, ar);
			}
			else
			{
				sourceText->Text = ReadExcelFile(openFileDialog1->FileName);
			}
			Report("������ ���������");
		}
	}
};