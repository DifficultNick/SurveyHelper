#pragma once

#include "Classes.h"
#include "VarForm.h"
#include "DragItemTypeChooser.h"
#include "Headers.h"
#include "UnionQuestions.h"
#include "HintForm.h"
#include "Problems.h"
#include "SliderType.h"
#include "Converter.h"
#include "FileReplace.h"
#include "PilotSyntax.h"


#define _PageHeader "Заголовок страницы"
#define _QuestionHeader "Вопрос"
#define _QuestionId "Id"



using namespace System;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;



public ref class MainForm: public System::Windows::Forms::Form
{

public:

	MainForm(String^ v)
	{
		InitializeComponent();

		versLabel->Text = "Версия "+v;
		this->pageHeader->Text = _PageHeader;
		this->QuestionHeader->Text = _QuestionHeader;
		this->PageId->Text = _QuestionId;

		curVers = v;
		dataGridView1->Columns[0]->ValueType = Type::GetType("System.Int32");
		dataGridView1->Columns["GotId"]->ValueType = Type::GetType("System.Int32");
		this->KeyPreview = true;
		this->KeyDown += gcnew KeyEventHandler(this, &MainForm::KeyPressed);

		tabs->SelectedIndex = 1;
		ExtendTypes->SelectedIndex = 0;
		features->SelectedIndex = 0;
		spaceCount->SelectedIndex = 0;

		TextMemo2->SelectionTabs = gcnew array<int> {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

		// строки для каждого Extend кроме DragItem
		ExtendUi->Add("ContentOnly", "");
		ExtendUi->Add("DragItem_Card", "Type=\"Card\" SourceContainer = \"0, 0\" TargetContainer=\"0, 0\" FontSizeTarget=\"1rem\" FontSizeSource=\"1rem\" DragItemAllowClick=\"1\"");
		ExtendUi->Add("DragItem_Range", "Type=\"Range\" SourceContainer = \"0, 0\" TargetContainer=\"0, 0\" FontSizeTarget=\"1rem\" FontSizeSource=\"1rem\" DragItemAllowClick=\"1\"");
		ExtendUi->Add("Slider_Continuous", "Type=\"Continuous\" MinVal=\"0\" MaxVal=\"100\" SliderStep=\"1\" LabelBegin=\"\" LabelEnd=\" руб.\" LabelTop=\"1\" ValueShow=\"1\"");
		ExtendUi->Add("Slider_Discrete", "Type=\"Discrete\"");
		ExtendUi->Add("Shape", "Opacity=\"0.3\" OpacitySelected=\"0.6\" WidthBorder=\"1px\" ColorBorder=\"black\" Src=\"@StoreUrl/t/tib_\"");
		ExtendUi->Add("Sortable", "LabelBegin=\"Самый важный\" LabelEnd=\"Наименее важный\"");
		ExtendUi->Add("ClickTest", "Src=\"@StoreUrl/t/tib_\"");
		ExtendUi->Add("Stars", "ClerCaption=\"Оценки нет\" HoverColor=\"#fde16d\" SelectedColor=\"#fde16d\" BackColor=\"#aaa\"");
		ExtendUi->Add("VideoPlayer", "Type=\"Video\" Src=\".mp4,.webm,.ogv\" PauseEnable=\"1\" ButtonLikeEnable=\"0\" ButtonDislikeEnable=\"0\" ButtonBoringEnable=\"\" PlayAuto=\"0\" PlayRedirect=\"0\" SeekEnable=\"0\"");
		ExtendUi->Add("AudioPlayer", "Type=\"Audio\" Src=\".mp3,.ogg\" PauseEnable=\"1\" PlayAuto=\"0\" PlayRedirect=\"0\" SeekEnable=\"0\"");
		//ExtendUi->Add("AutoComplete", "Height=\"200px\" Length=\"0\"");
		ExtendUi->Add("ComboBox", "Search=\"1\" Label=\"Выберите, пожалуйста, один из пунктов\"");
		ExtendUi->Add("Calendar", "");
		//ExtendUi->Add("Mask", "");
		ExtendUi->Add("ClickText", "SelectedFontColor=\"black\" SelectedBackgroundColor=\"orange\"");
		//ExtendUi->Add("Ball", "");
		ExtendUi->Add("Picture", "");
		ExtendUi->Add("Scale", "LabelStart=\"Совершенно не согласен\" LabelEnd=\"Полностью согласен\" Orientation=\"Horizontal\" Gradient=\"1\" GradientReverse=\"0\"");

		// список типов для каждого Extend
		CompTypes->Add("ContentOnly", gcnew List<String^>(gcnew array<String^> {"RadioButton", "CheckBox"}));
		CompTypes->Add("DragItem", gcnew List<String^>(gcnew array<String^> {"RadioButton"}));
		CompTypes->Add("Slider_Continious", gcnew List<String^>(gcnew array<String^> {"Number", "Integer"}));
		CompTypes->Add("Slider_Discrete", gcnew List<String^>(gcnew array<String^> {"RadioButton"}));
		CompTypes->Add("Shape", gcnew List<String^>(gcnew array<String^> {"RadioButton", "CheckBox"}));
		CompTypes->Add("Sortable", gcnew List<String^>(gcnew array<String^> {"Integer"}));
		CompTypes->Add("ClickTest", gcnew List<String^>(gcnew array<String^> {"Text"}));
		CompTypes->Add("Stars", gcnew List<String^>(gcnew array<String^> {"RadioButton"}));
		CompTypes->Add("VideoPlayer", gcnew List<String^>(gcnew array<String^> {"Text"}));
		CompTypes->Add("AudioPlayer", gcnew List<String^>(gcnew array<String^> {"Text"}));
		//CompTypes->Add("AutoComplete", gcnew List<String^>(gcnew array<String^> {"RadioButton"}));
		CompTypes->Add("ComboBox", gcnew List<String^>(gcnew array<String^> {"RadioButton", "CheckBox"}));
		CompTypes->Add("Calendar", gcnew List<String^>(gcnew array<String^> {"Date"}));
		//CompTypes->Add("Mask", gcnew List<String^>(gcnew array<String^> {"Text"}));
		CompTypes->Add("ClickText", gcnew List<String^>(gcnew array<String^> {"Text"}));
		//CompTypes->Add("Ball", gcnew List<String^>(gcnew array<String^> {"RadioButton"}));
		CompTypes->Add("Picture", gcnew List<String^>(gcnew array<String^> {"File"}));
		CompTypes->Add("Scale", gcnew List<String^>(gcnew array<String^> {"RadioButton"}));

		FeatureTypes->Add("CustomText2", 1);
		FeatureTypes->Add("AnswerText", 2);
		//FeatureTypes->Add("Include", 3);
		FeatureTypes->Add("Methods", 4);
		FeatureTypes->Add("Ui", 5);
		FeatureTypes->Add("PageUi", 6);
		FeatureTypes->Add("AnswerUi", 7);

		DontAsk->Add("QuestionHeader", gcnew QuestionDialog::Result());
		DontAsk->Add("PageHeader", gcnew QuestionDialog::Result());
		DontAsk->Add("RepeatName", gcnew QuestionDialog::Result());
		DontAsk->Add("CombineQuestions", gcnew QuestionDialog::Result());
	}




#pragma region Windows Form Designer generated code

protected:
	~MainForm()
	{
		if ( components )
		{
			delete components;
		}
	}

private: System::Windows::Forms::Panel^  panel1;
private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
private: System::Windows::Forms::GroupBox^  groupBox2;
private: System::Windows::Forms::GroupBox^  groupBox1;
private: System::Windows::Forms::RadioButton^  radioUnion;
private: System::Windows::Forms::RadioButton^  radioItem;
private: System::Windows::Forms::RadioButton^  radioAnswer;
public: System::Windows::Forms::CheckBox^  intoList;
private:

private:

private: System::Windows::Forms::RichTextBox^  TextMemo2;
private: System::Windows::Forms::Panel^  StatusBar;
private: System::Windows::Forms::MenuStrip^  menuStrip1;

private: System::Windows::Forms::Button^  VarButton;

private: System::Windows::Forms::Button^  RefreshButton;



private: System::Windows::Forms::ToolStripMenuItem^  MenuParam;

private: System::Windows::Forms::DataGridView^  dataGridView1;
public: System::Windows::Forms::CheckBox^  adVar;
private: System::Windows::Forms::ToolTip^  toolTip1;

private: System::Windows::Forms::ContextMenuStrip^  XMLMenu;
private: System::Windows::Forms::ToolStripMenuItem^  MakeColor;
private: System::Windows::Forms::ToolStripMenuItem^  MakeBold;
private: System::Windows::Forms::Button^  ClearButton;
private: System::Windows::Forms::ContextMenuStrip^  GridMenu;
private: System::Windows::Forms::ToolStripMenuItem^  sortId;
private: System::Windows::Forms::ToolStripMenuItem^  sortText;


private: System::Windows::Forms::ToolStripMenuItem^  delCurrentRow;
private: System::Windows::Forms::ToolStripMenuItem^  addRow;
private: System::Windows::Forms::ComboBox^  ExtendTypes;
private: System::Windows::Forms::CheckBox^  checkBox3;
private: System::Windows::Forms::ComboBox^  QuestionTypes;
public: System::Windows::Forms::TextBox^  QuestionHeader;
public: System::Windows::Forms::TextBox^  PageId;
private: System::Windows::Forms::CheckBox^  adQuestion;
private: System::Windows::Forms::CheckBox^  adParent;
private: System::Windows::Forms::TextBox^  ExtendString;
private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel3;


private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel2;
private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel4;


private: System::Windows::Forms::Button^  SetUnion;
private: System::Windows::Forms::ToolStripMenuItem^  выделитьКурсивомiToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  выделитьДругимЦветомToolStripMenuItem;
private: System::Windows::Forms::ColorDialog^  colorDialog1;








private: System::Windows::Forms::ToolStripMenuItem^  RefreshNums;
private: System::Windows::Forms::ToolStripMenuItem^  добавитьHintToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  customTextToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  устранениеПроблемToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  CleanTxt;
private: System::Windows::Forms::Button^  button2;
private: System::Windows::Forms::Timer^  timer1;
private: System::Windows::Forms::ToolStripMenuItem^  дополнительноToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  DelDileIds;



private: System::Windows::Forms::TextBox^  pageHeader;



private: System::Windows::Forms::Panel^  panel2;
private: System::Windows::Forms::TextBox^  repeatName;
private: System::Windows::Forms::CheckBox^  adRepeat;




private: System::Windows::Forms::Label^  label1;
private: System::Windows::Forms::TextBox^  repeatText;



private: System::Windows::Forms::ComboBox^  features;

public: System::Windows::Forms::CheckBox^  cMixId;
public: System::Windows::Forms::CheckBox^  cMix;
private: System::Windows::Forms::TextBox^  MixIdText;
public: System::Windows::Forms::CheckBox^  Isolate;
private: System::Windows::Forms::Label^  versLabel;
private: System::Windows::Forms::ToolStripMenuItem^  AutoNumId;
private: System::Windows::Forms::ToolStripMenuItem^  FirstUp;
private: System::Windows::Forms::ToolStripMenuItem^  GetPageId;
private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator2;
private: System::Windows::Forms::ToolStripMenuItem^  toolStripMenuItem1;
private: System::Windows::Forms::ToolStripComboBox^  tabs;



private: System::Windows::Forms::ToolStripMenuItem^  CopyBuf;
private: System::Windows::Forms::ToolStripMenuItem^  spaceBefore;
private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
private: System::Windows::Forms::ToolStripMenuItem^  missFirst;

private: System::Windows::Forms::ToolStripComboBox^  spaceCount;
private: System::Windows::Forms::ToolStripMenuItem^  преобразованияToolStripMenuItem;

private: System::Windows::Forms::ToolStripMenuItem^  заменаВФайлеToolStripMenuItem;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  IdItem;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  TextItem;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  GotId;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Counter;
private: System::Windows::Forms::RadioButton^  radioBlock;
private: System::Windows::Forms::ToolStripMenuItem^  сообщитьОбОшибкеToolStripMenuItem;
private: System::Windows::Forms::ToolStripMenuItem^  синтаксисSPSSБазыToolStripMenuItem;














private: System::ComponentModel::IContainer^  components;


private:

	void InitializeComponent(void)
	{
		this->components = (gcnew System::ComponentModel::Container());
		System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
		this->panel1 = (gcnew System::Windows::Forms::Panel());
		this->ClearButton = (gcnew System::Windows::Forms::Button());
		this->RefreshButton = (gcnew System::Windows::Forms::Button());
		this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
		this->Isolate = (gcnew System::Windows::Forms::CheckBox());
		this->MixIdText = (gcnew System::Windows::Forms::TextBox());
		this->cMixId = (gcnew System::Windows::Forms::CheckBox());
		this->cMix = (gcnew System::Windows::Forms::CheckBox());
		this->SetUnion = (gcnew System::Windows::Forms::Button());
		this->adVar = (gcnew System::Windows::Forms::CheckBox());
		this->VarButton = (gcnew System::Windows::Forms::Button());
		this->intoList = (gcnew System::Windows::Forms::CheckBox());
		this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
		this->radioBlock = (gcnew System::Windows::Forms::RadioButton());
		this->radioUnion = (gcnew System::Windows::Forms::RadioButton());
		this->radioItem = (gcnew System::Windows::Forms::RadioButton());
		this->radioAnswer = (gcnew System::Windows::Forms::RadioButton());
		this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
		this->TextMemo2 = (gcnew System::Windows::Forms::RichTextBox());
		this->XMLMenu = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
		this->добавитьHintToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->выделитьКурсивомiToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->MakeBold = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->MakeColor = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->выделитьДругимЦветомToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->customTextToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
		this->IdItem = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->TextItem = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->GotId = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->Counter = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
		this->GridMenu = (gcnew System::Windows::Forms::ContextMenuStrip(this->components));
		this->sortId = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->sortText = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->delCurrentRow = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->addRow = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->RefreshNums = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->CleanTxt = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->StatusBar = (gcnew System::Windows::Forms::Panel());
		this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
		this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
		this->ExtendString = (gcnew System::Windows::Forms::TextBox());
		this->adQuestion = (gcnew System::Windows::Forms::CheckBox());
		this->QuestionHeader = (gcnew System::Windows::Forms::TextBox());
		this->ExtendTypes = (gcnew System::Windows::Forms::ComboBox());
		this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
		this->QuestionTypes = (gcnew System::Windows::Forms::ComboBox());
		this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
		this->PageId = (gcnew System::Windows::Forms::TextBox());
		this->adParent = (gcnew System::Windows::Forms::CheckBox());
		this->pageHeader = (gcnew System::Windows::Forms::TextBox());
		this->button2 = (gcnew System::Windows::Forms::Button());
		this->panel2 = (gcnew System::Windows::Forms::Panel());
		this->features = (gcnew System::Windows::Forms::ComboBox());
		this->label1 = (gcnew System::Windows::Forms::Label());
		this->repeatText = (gcnew System::Windows::Forms::TextBox());
		this->repeatName = (gcnew System::Windows::Forms::TextBox());
		this->adRepeat = (gcnew System::Windows::Forms::CheckBox());
		this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
		this->MenuParam = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->AutoNumId = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->FirstUp = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->GetPageId = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->toolStripSeparator2 = (gcnew System::Windows::Forms::ToolStripSeparator());
		this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->tabs = (gcnew System::Windows::Forms::ToolStripComboBox());
		this->missFirst = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->spaceBefore = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->spaceCount = (gcnew System::Windows::Forms::ToolStripComboBox());
		this->CopyBuf = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
		this->устранениеПроблемToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->дополнительноToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->заменаВФайлеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->DelDileIds = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->преобразованияToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->синтаксисSPSSБазыToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->сообщитьОбОшибкеToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
		this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
		this->colorDialog1 = (gcnew System::Windows::Forms::ColorDialog());
		this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
		this->versLabel = (gcnew System::Windows::Forms::Label());
		this->panel1->SuspendLayout();
		this->groupBox2->SuspendLayout();
		this->groupBox1->SuspendLayout();
		this->tableLayoutPanel1->SuspendLayout();
		this->XMLMenu->SuspendLayout();
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
		this->GridMenu->SuspendLayout();
		this->StatusBar->SuspendLayout();
		this->tableLayoutPanel2->SuspendLayout();
		this->tableLayoutPanel3->SuspendLayout();
		this->tableLayoutPanel4->SuspendLayout();
		this->panel2->SuspendLayout();
		this->menuStrip1->SuspendLayout();
		this->SuspendLayout();
		// 
		// panel1
		// 
		this->panel1->BackColor = System::Drawing::Color::DarkGray;
		this->panel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
		this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
		this->tableLayoutPanel1->SetColumnSpan(this->panel1, 3);
		this->panel1->Controls->Add(this->ClearButton);
		this->panel1->Controls->Add(this->RefreshButton);
		this->panel1->Controls->Add(this->groupBox2);
		this->panel1->Controls->Add(this->groupBox1);
		this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
		this->panel1->Location = System::Drawing::Point(3, 2);
		this->panel1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
		this->panel1->Name = L"panel1";
		this->panel1->Size = System::Drawing::Size(1189, 88);
		this->panel1->TabIndex = 0;
		// 
		// ClearButton
		// 
		this->ClearButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
		this->ClearButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ClearButton.BackgroundImage")));
		this->ClearButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
		this->ClearButton->Location = System::Drawing::Point(1129, 42);
		this->ClearButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
		this->ClearButton->Name = L"ClearButton";
		this->ClearButton->Size = System::Drawing::Size(40, 37);
		this->ClearButton->TabIndex = 0;
		this->toolTip1->SetToolTip(this->ClearButton, L"(F9) Очистить всё");
		this->ClearButton->UseVisualStyleBackColor = true;
		this->ClearButton->Click += gcnew System::EventHandler(this, &MainForm::ClearButton_Click);
		// 
		// RefreshButton
		// 
		this->RefreshButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
		this->RefreshButton->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"RefreshButton.BackgroundImage")));
		this->RefreshButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
		this->RefreshButton->Location = System::Drawing::Point(1129, 5);
		this->RefreshButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
		this->RefreshButton->Name = L"RefreshButton";
		this->RefreshButton->Size = System::Drawing::Size(40, 37);
		this->RefreshButton->TabIndex = 0;
		this->toolTip1->SetToolTip(this->RefreshButton, L"(F5) Сгенерировать (обновить) XML");
		this->RefreshButton->UseVisualStyleBackColor = true;
		this->RefreshButton->Click += gcnew System::EventHandler(this, &MainForm::RefreshButton_Click);
		// 
		// groupBox2
		// 
		this->groupBox2->Controls->Add(this->Isolate);
		this->groupBox2->Controls->Add(this->MixIdText);
		this->groupBox2->Controls->Add(this->cMixId);
		this->groupBox2->Controls->Add(this->cMix);
		this->groupBox2->Controls->Add(this->SetUnion);
		this->groupBox2->Controls->Add(this->adVar);
		this->groupBox2->Controls->Add(this->VarButton);
		this->groupBox2->Controls->Add(this->intoList);
		this->groupBox2->ForeColor = System::Drawing::Color::White;
		this->groupBox2->Location = System::Drawing::Point(357, -1);
		this->groupBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
		this->groupBox2->Name = L"groupBox2";
		this->groupBox2->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
		this->groupBox2->Size = System::Drawing::Size(752, 80);
		this->groupBox2->TabIndex = 2;
		this->groupBox2->TabStop = false;
		this->groupBox2->Text = L"Общие настройки";
		// 
		// Isolate
		// 
		this->Isolate->AutoSize = true;
		this->Isolate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->Isolate->ForeColor = System::Drawing::Color::Black;
		this->Isolate->Location = System::Drawing::Point(557, 21);
		this->Isolate->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
		this->Isolate->Name = L"Isolate";
		this->Isolate->Size = System::Drawing::Size(78, 21);
		this->Isolate->TabIndex = 10;
		this->Isolate->Text = L"Isolate";
		this->toolTip1->SetToolTip(this->Isolate, L"Добавлять Isolate к ответам с Reset=\"true\"");
		this->Isolate->UseVisualStyleBackColor = true;
		this->Isolate->CheckedChanged += gcnew System::EventHandler(this, &MainForm::PerformanceUpdate);
		// 
		// MixIdText
		// 
		this->MixIdText->Enabled = false;
		this->MixIdText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->MixIdText->Location = System::Drawing::Point(557, 47);
		this->MixIdText->Margin = System::Windows::Forms::Padding(4);
		this->MixIdText->Name = L"MixIdText";
		this->MixIdText->Size = System::Drawing::Size(171, 24);
		this->MixIdText->TabIndex = 9;
		// 
		// cMixId
		// 
		this->cMixId->AutoSize = true;
		this->cMixId->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->cMixId->ForeColor = System::Drawing::Color::Black;
		this->cMixId->Location = System::Drawing::Point(476, 50);
		this->cMixId->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
		this->cMixId->Name = L"cMixId";
		this->cMixId->Size = System::Drawing::Size(71, 21);
		this->cMixId->TabIndex = 8;
		this->cMixId->Text = L"MixId:";
		this->cMixId->UseVisualStyleBackColor = true;
		this->cMixId->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cMixId_CheckedChanged);
		// 
		// cMix
		// 
		this->cMix->AutoSize = true;
		this->cMix->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->cMix->ForeColor = System::Drawing::Color::Black;
		this->cMix->Location = System::Drawing::Point(476, 21);
		this->cMix->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
		this->cMix->Name = L"cMix";
		this->cMix->Size = System::Drawing::Size(53, 21);
		this->cMix->TabIndex = 7;
		this->cMix->Text = L"Mix";
		this->cMix->UseVisualStyleBackColor = true;
		this->cMix->CheckedChanged += gcnew System::EventHandler(this, &MainForm::cMix_CheckedChanged);
		// 
		// SetUnion
		// 
		this->SetUnion->BackColor = System::Drawing::Color::Transparent;
		this->SetUnion->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
		this->SetUnion->Enabled = false;
		this->SetUnion->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->SetUnion->ForeColor = System::Drawing::Color::Black;
		this->SetUnion->Location = System::Drawing::Point(15, 47);
		this->SetUnion->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
		this->SetUnion->Name = L"SetUnion";
		this->SetUnion->Size = System::Drawing::Size(167, 27);
		this->SetUnion->TabIndex = 6;
		this->SetUnion->Text = L"Настройка Union";
		this->SetUnion->UseVisualStyleBackColor = false;
		this->SetUnion->Click += gcnew System::EventHandler(this, &MainForm::SetUnion_Click);
		// 
		// adVar
		// 
		this->adVar->AutoSize = true;
		this->adVar->Enabled = false;
		this->adVar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->adVar->ForeColor = System::Drawing::Color::Black;
		this->adVar->Location = System::Drawing::Point(225, 53);
		this->adVar->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
		this->adVar->Name = L"adVar";
		this->adVar->Size = System::Drawing::Size(132, 21);
		this->adVar->TabIndex = 6;
		this->adVar->Text = L"Добавить Var";
		this->adVar->UseVisualStyleBackColor = true;
		this->adVar->CheckedChanged += gcnew System::EventHandler(this, &MainForm::adVar_CheckedChanged);
		// 
		// VarButton
		// 
		this->VarButton->BackColor = System::Drawing::Color::Transparent;
		this->VarButton->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
		this->VarButton->Enabled = false;
		this->VarButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->VarButton->ForeColor = System::Drawing::Color::Black;
		this->VarButton->Location = System::Drawing::Point(15, 17);
		this->VarButton->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
		this->VarButton->Name = L"VarButton";
		this->VarButton->Size = System::Drawing::Size(167, 27);
		this->VarButton->TabIndex = 5;
		this->VarButton->Text = L"Настройка Var";
		this->VarButton->UseVisualStyleBackColor = false;
		this->VarButton->Click += gcnew System::EventHandler(this, &MainForm::VarButton_Click);
		// 
		// intoList
		// 
		this->intoList->AutoSize = true;
		this->intoList->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->intoList->ForeColor = System::Drawing::Color::Black;
		this->intoList->Location = System::Drawing::Point(225, 21);
		this->intoList->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
		this->intoList->Name = L"intoList";
		this->intoList->Size = System::Drawing::Size(205, 21);
		this->intoList->TabIndex = 2;
		this->intoList->Text = L"Выделить ответы в List";
		this->toolTip1->SetToolTip(this->intoList, L"");
		this->intoList->UseVisualStyleBackColor = true;
		this->intoList->CheckedChanged += gcnew System::EventHandler(this, &MainForm::PerformanceUpdate);
		// 
		// groupBox1
		// 
		this->groupBox1->Controls->Add(this->radioBlock);
		this->groupBox1->Controls->Add(this->radioUnion);
		this->groupBox1->Controls->Add(this->radioItem);
		this->groupBox1->Controls->Add(this->radioAnswer);
		this->groupBox1->ForeColor = System::Drawing::Color::White;
		this->groupBox1->Location = System::Drawing::Point(3, -1);
		this->groupBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
		this->groupBox1->Name = L"groupBox1";
		this->groupBox1->Padding = System::Windows::Forms::Padding(3, 2, 3, 2);
		this->groupBox1->Size = System::Drawing::Size(340, 80);
		this->groupBox1->TabIndex = 0;
		this->groupBox1->TabStop = false;
		this->groupBox1->Text = L"Тип элементов";
		// 
		// radioBlock
		// 
		this->radioBlock->AutoSize = true;
		this->radioBlock->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->radioBlock->ForeColor = System::Drawing::Color::Black;
		this->radioBlock->Location = System::Drawing::Point(163, 49);
		this->radioBlock->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
		this->radioBlock->Name = L"radioBlock";
		this->radioBlock->Size = System::Drawing::Size(139, 21);
		this->radioBlock->TabIndex = 4;
		this->radioBlock->Text = L"Блок вопросов";
		this->radioBlock->UseVisualStyleBackColor = true;
		this->radioBlock->CheckedChanged += gcnew System::EventHandler(this, &MainForm::radio_CheckedChanged);
		// 
		// radioUnion
		// 
		this->radioUnion->AutoSize = true;
		this->radioUnion->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->radioUnion->ForeColor = System::Drawing::Color::Black;
		this->radioUnion->Location = System::Drawing::Point(163, 21);
		this->radioUnion->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
		this->radioUnion->Name = L"radioUnion";
		this->radioUnion->Size = System::Drawing::Size(128, 21);
		this->radioUnion->TabIndex = 3;
		this->radioUnion->Text = L"Union вопрос";
		this->radioUnion->UseVisualStyleBackColor = true;
		this->radioUnion->CheckedChanged += gcnew System::EventHandler(this, &MainForm::radio_CheckedChanged);
		// 
		// radioItem
		// 
		this->radioItem->AutoSize = true;
		this->radioItem->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->radioItem->ForeColor = System::Drawing::Color::Black;
		this->radioItem->Location = System::Drawing::Point(19, 49);
		this->radioItem->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
		this->radioItem->Name = L"radioItem";
		this->radioItem->Size = System::Drawing::Size(98, 21);
		this->radioItem->TabIndex = 1;
		this->radioItem->Text = L"List Items";
		this->radioItem->UseVisualStyleBackColor = true;
		this->radioItem->CheckedChanged += gcnew System::EventHandler(this, &MainForm::radio_CheckedChanged);
		// 
		// radioAnswer
		// 
		this->radioAnswer->AutoSize = true;
		this->radioAnswer->Checked = true;
		this->radioAnswer->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->radioAnswer->ForeColor = System::Drawing::Color::Black;
		this->radioAnswer->Location = System::Drawing::Point(19, 21);
		this->radioAnswer->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
		this->radioAnswer->Name = L"radioAnswer";
		this->radioAnswer->Size = System::Drawing::Size(89, 21);
		this->radioAnswer->TabIndex = 0;
		this->radioAnswer->TabStop = true;
		this->radioAnswer->Text = L"Answers";
		this->radioAnswer->UseVisualStyleBackColor = true;
		this->radioAnswer->CheckedChanged += gcnew System::EventHandler(this, &MainForm::radio_CheckedChanged);
		// 
		// tableLayoutPanel1
		// 
		this->tableLayoutPanel1->ColumnCount = 3;
		this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			50)));
		this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
			19)));
		this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			50)));
		this->tableLayoutPanel1->Controls->Add(this->panel1, 0, 0);
		this->tableLayoutPanel1->Controls->Add(this->TextMemo2, 2, 2);
		this->tableLayoutPanel1->Controls->Add(this->dataGridView1, 0, 2);
		this->tableLayoutPanel1->Controls->Add(this->StatusBar, 0, 3);
		this->tableLayoutPanel1->Controls->Add(this->button2, 1, 2);
		this->tableLayoutPanel1->Controls->Add(this->panel2, 0, 1);
		this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
		this->tableLayoutPanel1->Location = System::Drawing::Point(0, 28);
		this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(3, 2, 3, 0);
		this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
		this->tableLayoutPanel1->RowCount = 4;
		this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 92)));
		this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 31)));
		this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
		this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 118)));
		this->tableLayoutPanel1->Size = System::Drawing::Size(1195, 562);
		this->tableLayoutPanel1->TabIndex = 0;
		// 
		// TextMemo2
		// 
		this->TextMemo2->ContextMenuStrip = this->XMLMenu;
		this->TextMemo2->Dock = System::Windows::Forms::DockStyle::Fill;
		this->TextMemo2->Font = (gcnew System::Drawing::Font(L"Bookman Old Style", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->TextMemo2->Location = System::Drawing::Point(610, 125);
		this->TextMemo2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
		this->TextMemo2->Name = L"TextMemo2";
		this->TextMemo2->Size = System::Drawing::Size(582, 317);
		this->TextMemo2->TabIndex = 5;
		this->TextMemo2->Text = L"";
		this->TextMemo2->WordWrap = false;
		this->TextMemo2->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::TextMemo2_KeyDown);
		this->TextMemo2->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MainForm::TextMemo2_MouseUp);
		// 
		// XMLMenu
		// 
		this->XMLMenu->ImageScalingSize = System::Drawing::Size(20, 20);
		this->XMLMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
			this->добавитьHintToolStripMenuItem,
				this->выделитьКурсивомiToolStripMenuItem, this->MakeBold, this->MakeColor, this->выделитьДругимЦветомToolStripMenuItem, this->customTextToolStripMenuItem
		});
		this->XMLMenu->Name = L"XMLMenu";
		this->XMLMenu->Size = System::Drawing::Size(255, 148);
		// 
		// добавитьHintToolStripMenuItem
		// 
		this->добавитьHintToolStripMenuItem->Name = L"добавитьHintToolStripMenuItem";
		this->добавитьHintToolStripMenuItem->Size = System::Drawing::Size(254, 24);
		this->добавитьHintToolStripMenuItem->Text = L"Добавить Hint";
		this->добавитьHintToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::добавитьHintToolStripMenuItem_Click);
		// 
		// выделитьКурсивомiToolStripMenuItem
		// 
		this->выделитьКурсивомiToolStripMenuItem->Name = L"выделитьКурсивомiToolStripMenuItem";
		this->выделитьКурсивомiToolStripMenuItem->Size = System::Drawing::Size(254, 24);
		this->выделитьКурсивомiToolStripMenuItem->Text = L"Выделить курсивом <i>";
		this->выделитьКурсивомiToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::выделитьКурсивомiToolStripMenuItem_Click);
		// 
		// MakeBold
		// 
		this->MakeBold->Name = L"MakeBold";
		this->MakeBold->Size = System::Drawing::Size(254, 24);
		this->MakeBold->Text = L"Выделить жирным <b>";
		this->MakeBold->Click += gcnew System::EventHandler(this, &MainForm::MakeBold_Click);
		// 
		// MakeColor
		// 
		this->MakeColor->Name = L"MakeColor";
		this->MakeColor->Size = System::Drawing::Size(254, 24);
		this->MakeColor->Text = L"Выделить синим <u>";
		this->MakeColor->Click += gcnew System::EventHandler(this, &MainForm::MakeColor_Click);
		// 
		// выделитьДругимЦветомToolStripMenuItem
		// 
		this->выделитьДругимЦветомToolStripMenuItem->Name = L"выделитьДругимЦветомToolStripMenuItem";
		this->выделитьДругимЦветомToolStripMenuItem->Size = System::Drawing::Size(254, 24);
		this->выделитьДругимЦветомToolStripMenuItem->Text = L"Выделить другим цветом";
		this->выделитьДругимЦветомToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::выделитьДругимЦветомToolStripMenuItem_Click);
		// 
		// customTextToolStripMenuItem
		// 
		this->customTextToolStripMenuItem->Name = L"customTextToolStripMenuItem";
		this->customTextToolStripMenuItem->Size = System::Drawing::Size(254, 24);
		this->customTextToolStripMenuItem->Text = L"CustomText";
		this->customTextToolStripMenuItem->ToolTipText = L"Добавляет тег <CustomText2>\r\nс подтегами <style> и <script>";
		this->customTextToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::customTextToolStripMenuItem_Click);
		// 
		// dataGridView1
		// 
		this->dataGridView1->AllowUserToResizeColumns = false;
		this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCellsExceptHeaders;
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
		this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
			this->IdItem,
				this->TextItem, this->GotId, this->Counter
		});
		this->dataGridView1->ContextMenuStrip = this->GridMenu;
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
		this->dataGridView1->Location = System::Drawing::Point(3, 125);
		this->dataGridView1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
		this->dataGridView1->Name = L"dataGridView1";
		this->dataGridView1->RowHeadersVisible = false;
		this->dataGridView1->RowTemplate->Height = 24;
		this->dataGridView1->Size = System::Drawing::Size(582, 317);
		this->dataGridView1->TabIndex = 9;
		this->dataGridView1->CellBeginEdit += gcnew System::Windows::Forms::DataGridViewCellCancelEventHandler(this, &MainForm::dataGridView1_CellBeginEdit);
		this->dataGridView1->CellEndEdit += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainForm::dataGridView1_CellEndEdit);
		this->dataGridView1->CellValueChanged += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &MainForm::WrapCells);
		this->dataGridView1->ColumnHeaderMouseClick += gcnew System::Windows::Forms::DataGridViewCellMouseEventHandler(this, &MainForm::dataGridView1_ColumnHeaderMouseClick);
		this->dataGridView1->DataError += gcnew System::Windows::Forms::DataGridViewDataErrorEventHandler(this, &MainForm::dataGridView1_DataError);
		this->dataGridView1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::dataGridView1_KeyDown);
		// 
		// IdItem
		// 
		this->IdItem->Frozen = true;
		this->IdItem->HeaderText = L"Id";
		this->IdItem->Name = L"IdItem";
		this->IdItem->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Programmatic;
		this->IdItem->Width = 60;
		// 
		// TextItem
		// 
		this->TextItem->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
		dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
		this->TextItem->DefaultCellStyle = dataGridViewCellStyle2;
		this->TextItem->HeaderText = L"Text";
		this->TextItem->Name = L"TextItem";
		this->TextItem->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Programmatic;
		// 
		// GotId
		// 
		this->GotId->FillWeight = 1;
		this->GotId->HeaderText = L"";
		this->GotId->Name = L"GotId";
		this->GotId->Resizable = System::Windows::Forms::DataGridViewTriState::False;
		this->GotId->Visible = false;
		this->GotId->Width = 5;
		// 
		// Counter
		// 
		this->Counter->HeaderText = L"";
		this->Counter->Name = L"Counter";
		this->Counter->Visible = false;
		// 
		// GridMenu
		// 
		this->GridMenu->ImageScalingSize = System::Drawing::Size(20, 20);
		this->GridMenu->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(6) {
			this->sortId, this->sortText,
				this->delCurrentRow, this->addRow, this->RefreshNums, this->CleanTxt
		});
		this->GridMenu->Name = L"GridMenu";
		this->GridMenu->Size = System::Drawing::Size(270, 148);
		// 
		// sortId
		// 
		this->sortId->Name = L"sortId";
		this->sortId->Size = System::Drawing::Size(269, 24);
		this->sortId->Text = L"Сортировать отдельно Id";
		this->sortId->Click += gcnew System::EventHandler(this, &MainForm::sortId_Click);
		// 
		// sortText
		// 
		this->sortText->Name = L"sortText";
		this->sortText->Size = System::Drawing::Size(269, 24);
		this->sortText->Text = L"Сортировать Text отдельно";
		this->sortText->Click += gcnew System::EventHandler(this, &MainForm::sortText_Click);
		// 
		// delCurrentRow
		// 
		this->delCurrentRow->Name = L"delCurrentRow";
		this->delCurrentRow->Size = System::Drawing::Size(269, 24);
		this->delCurrentRow->Text = L"Удалить текущую строку";
		this->delCurrentRow->Click += gcnew System::EventHandler(this, &MainForm::delCurrentRow_Click);
		// 
		// addRow
		// 
		this->addRow->Name = L"addRow";
		this->addRow->Size = System::Drawing::Size(269, 24);
		this->addRow->Text = L"Добавить строку";
		this->addRow->Click += gcnew System::EventHandler(this, &MainForm::addRow_Click);
		// 
		// RefreshNums
		// 
		this->RefreshNums->Name = L"RefreshNums";
		this->RefreshNums->Size = System::Drawing::Size(269, 24);
		this->RefreshNums->Text = L"Обновить нумерацию";
		this->RefreshNums->ToolTipText = L"Пронумеровать все элементы по порядку";
		this->RefreshNums->Click += gcnew System::EventHandler(this, &MainForm::RefreshNums_Click);
		// 
		// CleanTxt
		// 
		this->CleanTxt->Name = L"CleanTxt";
		this->CleanTxt->Size = System::Drawing::Size(269, 24);
		this->CleanTxt->Text = L"Убрать лишнее";
		this->CleanTxt->ToolTipText = L"Очищает текст в в полеXML от лишних \r\nсимволов.\r\nПосле этого действия стоит внима"
			L"тельно \r\nперечитать результат.";
		this->CleanTxt->Click += gcnew System::EventHandler(this, &MainForm::CleanText_Click);
		// 
		// StatusBar
		// 
		this->tableLayoutPanel1->SetColumnSpan(this->StatusBar, 3);
		this->StatusBar->Controls->Add(this->tableLayoutPanel2);
		this->StatusBar->Dock = System::Windows::Forms::DockStyle::Fill;
		this->StatusBar->Location = System::Drawing::Point(3, 446);
		this->StatusBar->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
		this->StatusBar->Name = L"StatusBar";
		this->StatusBar->Size = System::Drawing::Size(1189, 114);
		this->StatusBar->TabIndex = 7;
		// 
		// tableLayoutPanel2
		// 
		this->tableLayoutPanel2->ColumnCount = 1;
		this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
			100)));
		this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel3, 0, 1);
		this->tableLayoutPanel2->Controls->Add(this->tableLayoutPanel4, 0, 0);
		this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
		this->tableLayoutPanel2->Location = System::Drawing::Point(0, 0);
		this->tableLayoutPanel2->Margin = System::Windows::Forms::Padding(4);
		this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
		this->tableLayoutPanel2->RowCount = 2;
		this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 33.34F)));
		this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 66.66F)));
		this->tableLayoutPanel2->Size = System::Drawing::Size(1189, 114);
		this->tableLayoutPanel2->TabIndex = 11;
		// 
		// tableLayoutPanel3
		// 
		this->tableLayoutPanel3->ColumnCount = 4;
		this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
			243)));
		this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
			289)));
		this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
			267)));
		this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
		this->tableLayoutPanel3->Controls->Add(this->ExtendString, 2, 1);
		this->tableLayoutPanel3->Controls->Add(this->adQuestion, 0, 0);
		this->tableLayoutPanel3->Controls->Add(this->QuestionHeader, 2, 0);
		this->tableLayoutPanel3->Controls->Add(this->ExtendTypes, 1, 1);
		this->tableLayoutPanel3->Controls->Add(this->checkBox3, 0, 1);
		this->tableLayoutPanel3->Controls->Add(this->QuestionTypes, 1, 0);
		this->tableLayoutPanel3->Dock = System::Windows::Forms::DockStyle::Fill;
		this->tableLayoutPanel3->Location = System::Drawing::Point(4, 38);
		this->tableLayoutPanel3->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
		this->tableLayoutPanel3->Padding = System::Windows::Forms::Padding(5, 0, 0, 0);
		this->tableLayoutPanel3->RowCount = 2;
		this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
		this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
		this->tableLayoutPanel3->Size = System::Drawing::Size(1181, 76);
		this->tableLayoutPanel3->TabIndex = 9;
		// 
		// ExtendString
		// 
		this->tableLayoutPanel3->SetColumnSpan(this->ExtendString, 2);
		this->ExtendString->Dock = System::Windows::Forms::DockStyle::Fill;
		this->ExtendString->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->ExtendString->Location = System::Drawing::Point(541, 42);
		this->ExtendString->Margin = System::Windows::Forms::Padding(4, 4, 0, 4);
		this->ExtendString->Name = L"ExtendString";
		this->ExtendString->Size = System::Drawing::Size(719, 24);
		this->ExtendString->TabIndex = 8;
		this->ExtendString->WordWrap = false;
		this->ExtendString->TextChanged += gcnew System::EventHandler(this, &MainForm::ExtendString_TextChanged);
		this->ExtendString->DoubleClick += gcnew System::EventHandler(this, &MainForm::TextBox_Click);
		// 
		// adQuestion
		// 
		this->adQuestion->AutoSize = true;
		this->adQuestion->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->adQuestion->ForeColor = System::Drawing::Color::Black;
		this->adQuestion->Location = System::Drawing::Point(8, 2);
		this->adQuestion->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
		this->adQuestion->Name = L"adQuestion";
		this->adQuestion->Padding = System::Windows::Forms::Padding(0, 4, 0, 0);
		this->adQuestion->Size = System::Drawing::Size(172, 25);
		this->adQuestion->TabIndex = 2;
		this->adQuestion->Text = L"Добавить Question";
		this->adQuestion->UseVisualStyleBackColor = true;
		this->adQuestion->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox2_CheckedChanged);
		// 
		// QuestionHeader
		// 
		this->QuestionHeader->AcceptsTab = true;
		this->tableLayoutPanel3->SetColumnSpan(this->QuestionHeader, 2);
		this->QuestionHeader->Dock = System::Windows::Forms::DockStyle::Fill;
		this->QuestionHeader->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->QuestionHeader->Location = System::Drawing::Point(541, 4);
		this->QuestionHeader->Margin = System::Windows::Forms::Padding(4, 4, 0, 4);
		this->QuestionHeader->Multiline = true;
		this->QuestionHeader->Name = L"QuestionHeader";
		this->QuestionHeader->Size = System::Drawing::Size(719, 30);
		this->QuestionHeader->TabIndex = 4;
		this->QuestionHeader->TextChanged += gcnew System::EventHandler(this, &MainForm::QuestionHeader_TextChanged);
		this->QuestionHeader->DoubleClick += gcnew System::EventHandler(this, &MainForm::TextBox_Click);
		this->QuestionHeader->Enter += gcnew System::EventHandler(this, &MainForm::QuestionHeader_Enter);
		this->QuestionHeader->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::TextBox_KeyDown);
		this->QuestionHeader->Leave += gcnew System::EventHandler(this, &MainForm::QuestionHeader_Leave);
		// 
		// ExtendTypes
		// 
		this->ExtendTypes->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
		this->ExtendTypes->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->ExtendTypes->FormattingEnabled = true;
		this->ExtendTypes->Items->AddRange(gcnew cli::array< System::Object^  >(15) {
			L"-------------", L"AudioPlayer", L"Calendar",
				L"ClickTest", L"ClickText", L"ComboBox", L"ContentOnly", L"DragItem", L"Picture", L"Scale", L"Shape", L"Slider", L"Sortable",
				L"Stars", L"VideoPlayer"
		});
		this->ExtendTypes->Location = System::Drawing::Point(252, 42);
		this->ExtendTypes->Margin = System::Windows::Forms::Padding(4);
		this->ExtendTypes->Name = L"ExtendTypes";
		this->ExtendTypes->Size = System::Drawing::Size(224, 25);
		this->ExtendTypes->TabIndex = 7;
		this->ExtendTypes->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::ExtendTypes_SelectedIndexChanged);
		// 
		// checkBox3
		// 
		this->checkBox3->AutoSize = true;
		this->checkBox3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->checkBox3->ForeColor = System::Drawing::Color::Black;
		this->checkBox3->Location = System::Drawing::Point(8, 40);
		this->checkBox3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
		this->checkBox3->Name = L"checkBox3";
		this->checkBox3->Size = System::Drawing::Size(122, 21);
		this->checkBox3->TabIndex = 6;
		this->checkBox3->Text = L"Добавить Ui";
		this->checkBox3->UseVisualStyleBackColor = true;
		this->checkBox3->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox3_CheckedChanged);
		// 
		// QuestionTypes
		// 
		this->QuestionTypes->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
		this->QuestionTypes->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->QuestionTypes->FormattingEnabled = true;
		this->QuestionTypes->Items->AddRange(gcnew cli::array< System::Object^  >(7) {
			L"CheckBox", L"RadioButton", L"Text", L"Memo",
				L"Integer", L"Number", L"File"
		});
		this->QuestionTypes->Location = System::Drawing::Point(252, 4);
		this->QuestionTypes->Margin = System::Windows::Forms::Padding(4);
		this->QuestionTypes->Name = L"QuestionTypes";
		this->QuestionTypes->Size = System::Drawing::Size(224, 25);
		this->QuestionTypes->TabIndex = 5;
		this->QuestionTypes->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::PerformanceUpdate);
		// 
		// tableLayoutPanel4
		// 
		this->tableLayoutPanel4->ColumnCount = 3;
		this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
			249)));
		this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
			288)));
		this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Absolute,
			997)));
		this->tableLayoutPanel4->Controls->Add(this->PageId, 1, 0);
		this->tableLayoutPanel4->Controls->Add(this->adParent, 0, 0);
		this->tableLayoutPanel4->Controls->Add(this->pageHeader, 2, 0);
		this->tableLayoutPanel4->Dock = System::Windows::Forms::DockStyle::Fill;
		this->tableLayoutPanel4->Location = System::Drawing::Point(4, 4);
		this->tableLayoutPanel4->Margin = System::Windows::Forms::Padding(4);
		this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
		this->tableLayoutPanel4->RowCount = 1;
		this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 31)));
		this->tableLayoutPanel4->Size = System::Drawing::Size(1181, 30);
		this->tableLayoutPanel4->TabIndex = 10;
		// 
		// PageId
		// 
		this->PageId->Anchor = System::Windows::Forms::AnchorStyles::Left;
		this->PageId->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
		this->PageId->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::CustomSource;
		this->PageId->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->PageId->Location = System::Drawing::Point(253, 4);
		this->PageId->Margin = System::Windows::Forms::Padding(4);
		this->PageId->Name = L"PageId";
		this->PageId->Size = System::Drawing::Size(145, 24);
		this->PageId->TabIndex = 3;
		this->PageId->Text = L"Id";
		this->PageId->WordWrap = false;
		this->PageId->DoubleClick += gcnew System::EventHandler(this, &MainForm::TextBox_Click);
		this->PageId->Enter += gcnew System::EventHandler(this, &MainForm::PageId_Enter);
		this->PageId->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::pageId_KeyDown);
		this->PageId->Leave += gcnew System::EventHandler(this, &MainForm::PageId_Leave);
		// 
		// adParent
		// 
		this->adParent->Anchor = System::Windows::Forms::AnchorStyles::Left;
		this->adParent->AutoSize = true;
		this->adParent->Checked = true;
		this->adParent->CheckState = System::Windows::Forms::CheckState::Checked;
		this->adParent->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->adParent->ForeColor = System::Drawing::Color::Black;
		this->adParent->Location = System::Drawing::Point(8, 5);
		this->adParent->Margin = System::Windows::Forms::Padding(8, 2, 3, 2);
		this->adParent->Name = L"adParent";
		this->adParent->Size = System::Drawing::Size(144, 21);
		this->adParent->TabIndex = 1;
		this->adParent->Text = L"Добавить Page";
		this->adParent->UseVisualStyleBackColor = true;
		this->adParent->CheckedChanged += gcnew System::EventHandler(this, &MainForm::checkBox1_CheckedChanged);
		// 
		// pageHeader
		// 
		this->pageHeader->AcceptsTab = true;
		this->pageHeader->Dock = System::Windows::Forms::DockStyle::Fill;
		this->pageHeader->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->pageHeader->Location = System::Drawing::Point(541, 0);
		this->pageHeader->Margin = System::Windows::Forms::Padding(4, 0, 0, 0);
		this->pageHeader->Multiline = true;
		this->pageHeader->Name = L"pageHeader";
		this->pageHeader->Size = System::Drawing::Size(993, 31);
		this->pageHeader->TabIndex = 4;
		this->pageHeader->TextChanged += gcnew System::EventHandler(this, &MainForm::pageHeader_TextChanged);
		this->pageHeader->DoubleClick += gcnew System::EventHandler(this, &MainForm::TextBox_Click);
		this->pageHeader->Enter += gcnew System::EventHandler(this, &MainForm::pageHeader_Enter);
		this->pageHeader->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MainForm::TextBox_KeyDown);
		this->pageHeader->Leave += gcnew System::EventHandler(this, &MainForm::pageHeader_Leave);
		// 
		// button2
		// 
		this->button2->Cursor = System::Windows::Forms::Cursors::Hand;
		this->button2->Dock = System::Windows::Forms::DockStyle::Fill;
		this->button2->Location = System::Drawing::Point(588, 123);
		this->button2->Margin = System::Windows::Forms::Padding(0);
		this->button2->Name = L"button2";
		this->button2->Size = System::Drawing::Size(19, 321);
		this->button2->TabIndex = 10;
		this->button2->Text = L"<";
		this->button2->UseVisualStyleBackColor = true;
		this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
		// 
		// panel2
		// 
		this->tableLayoutPanel1->SetColumnSpan(this->panel2, 3);
		this->panel2->Controls->Add(this->features);
		this->panel2->Controls->Add(this->label1);
		this->panel2->Controls->Add(this->repeatText);
		this->panel2->Controls->Add(this->repeatName);
		this->panel2->Controls->Add(this->adRepeat);
		this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
		this->panel2->Location = System::Drawing::Point(4, 92);
		this->panel2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->panel2->Name = L"panel2";
		this->panel2->Size = System::Drawing::Size(1187, 31);
		this->panel2->TabIndex = 11;
		// 
		// features
		// 
		this->features->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
		this->features->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
		this->features->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
		this->features->FormattingEnabled = true;
		this->features->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"Дополнительные возможности" });
		this->features->Location = System::Drawing::Point(784, 2);
		this->features->Margin = System::Windows::Forms::Padding(4);
		this->features->Name = L"features";
		this->features->Size = System::Drawing::Size(396, 24);
		this->features->TabIndex = 4;
		this->features->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::features_SelectedIndexChanged);
		// 
		// label1
		// 
		this->label1->AutoSize = true;
		this->label1->Location = System::Drawing::Point(293, 7);
		this->label1->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->label1->Name = L"label1";
		this->label1->Size = System::Drawing::Size(80, 17);
		this->label1->TabIndex = 3;
		this->label1->Text = L"с текстом :";
		// 
		// repeatText
		// 
		this->repeatText->Enabled = false;
		this->repeatText->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->repeatText->Location = System::Drawing::Point(387, 2);
		this->repeatText->Margin = System::Windows::Forms::Padding(4);
		this->repeatText->Name = L"repeatText";
		this->repeatText->Size = System::Drawing::Size(308, 24);
		this->repeatText->TabIndex = 2;
		// 
		// repeatName
		// 
		this->repeatName->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
		this->repeatName->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::CustomSource;
		this->repeatName->Enabled = false;
		this->repeatName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->repeatName->Location = System::Drawing::Point(115, 2);
		this->repeatName->Margin = System::Windows::Forms::Padding(4);
		this->repeatName->Name = L"repeatName";
		this->repeatName->Size = System::Drawing::Size(171, 24);
		this->repeatName->TabIndex = 1;
		this->repeatName->TextChanged += gcnew System::EventHandler(this, &MainForm::repeatName_TextChanged);
		// 
		// adRepeat
		// 
		this->adRepeat->AutoSize = true;
		this->adRepeat->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->adRepeat->Location = System::Drawing::Point(11, 6);
		this->adRepeat->Margin = System::Windows::Forms::Padding(4);
		this->adRepeat->Name = L"adRepeat";
		this->adRepeat->Size = System::Drawing::Size(102, 21);
		this->adRepeat->TabIndex = 0;
		this->adRepeat->Text = L"Повтор по ";
		this->toolTip1->SetToolTip(this->adRepeat, L"Добавляет элементы из указанного списка или \r\nуказанное количество элементов с ук"
			L"азанным текстом.");
		this->adRepeat->UseVisualStyleBackColor = true;
		this->adRepeat->CheckedChanged += gcnew System::EventHandler(this, &MainForm::adRepeat_CheckedChanged);
		// 
		// menuStrip1
		// 
		this->menuStrip1->BackColor = System::Drawing::SystemColors::MenuBar;
		this->menuStrip1->ImageScalingSize = System::Drawing::Size(20, 20);
		this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->MenuParam, this->дополнительноToolStripMenuItem });
		this->menuStrip1->Location = System::Drawing::Point(0, 0);
		this->menuStrip1->Name = L"menuStrip1";
		this->menuStrip1->Padding = System::Windows::Forms::Padding(5, 2, 0, 2);
		this->menuStrip1->Size = System::Drawing::Size(1195, 28);
		this->menuStrip1->TabIndex = 1;
		this->menuStrip1->Text = L"menuStrip1";
		// 
		// MenuParam
		// 
		this->MenuParam->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(9) {
			this->AutoNumId,
				this->FirstUp, this->GetPageId, this->toolStripSeparator2, this->toolStripMenuItem1, this->spaceBefore, this->CopyBuf, this->toolStripSeparator1,
				this->устранениеПроблемToolStripMenuItem
		});
		this->MenuParam->Name = L"MenuParam";
		this->MenuParam->Size = System::Drawing::Size(102, 24);
		this->MenuParam->Text = L"Параметры";
		// 
		// AutoNumId
		// 
		this->AutoNumId->Checked = true;
		this->AutoNumId->CheckOnClick = true;
		this->AutoNumId->CheckState = System::Windows::Forms::CheckState::Checked;
		this->AutoNumId->Name = L"AutoNumId";
		this->AutoNumId->Size = System::Drawing::Size(297, 26);
		this->AutoNumId->Text = L"Выделение Id";
		this->AutoNumId->ToolTipText = L"Автоматическое выделение номера";
		// 
		// FirstUp
		// 
		this->FirstUp->CheckOnClick = true;
		this->FirstUp->Name = L"FirstUp";
		this->FirstUp->Size = System::Drawing::Size(297, 26);
		this->FirstUp->Text = L"Заглавная первая буква";
		// 
		// GetPageId
		// 
		this->GetPageId->Checked = true;
		this->GetPageId->CheckOnClick = true;
		this->GetPageId->CheckState = System::Windows::Forms::CheckState::Checked;
		this->GetPageId->Name = L"GetPageId";
		this->GetPageId->Size = System::Drawing::Size(297, 26);
		this->GetPageId->Text = L"Заменять PageId на QuestionId";
		this->GetPageId->ToolTipText = L"При изменении текста поля заголовка вопроса";
		// 
		// toolStripSeparator2
		// 
		this->toolStripSeparator2->Name = L"toolStripSeparator2";
		this->toolStripSeparator2->Size = System::Drawing::Size(294, 6);
		// 
		// toolStripMenuItem1
		// 
		this->toolStripMenuItem1->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
			this->tabs,
				this->missFirst
		});
		this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
		this->toolStripMenuItem1->Size = System::Drawing::Size(297, 26);
		this->toolStripMenuItem1->Text = L"Табуляция";
		this->toolStripMenuItem1->ToolTipText = L"Количество символов табуляции,";
		// 
		// tabs
		// 
		this->tabs->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
		this->tabs->Items->AddRange(gcnew cli::array< System::Object^  >(5) { L"0", L"1", L"2", L"3", L"4" });
		this->tabs->Name = L"tabs";
		this->tabs->Size = System::Drawing::Size(121, 28);
		// 
		// missFirst
		// 
		this->missFirst->CheckOnClick = true;
		this->missFirst->Name = L"missFirst";
		this->missFirst->Size = System::Drawing::Size(285, 26);
		this->missFirst->Text = L"Не добавлять перед первым";
		// 
		// spaceBefore
		// 
		this->spaceBefore->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->spaceCount });
		this->spaceBefore->Name = L"spaceBefore";
		this->spaceBefore->Size = System::Drawing::Size(297, 26);
		this->spaceBefore->Text = L"Добавлять отступ в начале";
		// 
		// spaceCount
		// 
		this->spaceCount->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
		this->spaceCount->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"0", L"1", L"2", L"3" });
		this->spaceCount->Name = L"spaceCount";
		this->spaceCount->Size = System::Drawing::Size(121, 28);
		// 
		// CopyBuf
		// 
		this->CopyBuf->Checked = true;
		this->CopyBuf->CheckOnClick = true;
		this->CopyBuf->CheckState = System::Windows::Forms::CheckState::Checked;
		this->CopyBuf->Name = L"CopyBuf";
		this->CopyBuf->Size = System::Drawing::Size(297, 26);
		this->CopyBuf->Text = L"Копировать в буфер";
		this->CopyBuf->ToolTipText = L"Копировать результат генерации XML";
		// 
		// toolStripSeparator1
		// 
		this->toolStripSeparator1->Name = L"toolStripSeparator1";
		this->toolStripSeparator1->Size = System::Drawing::Size(294, 6);
		// 
		// устранениеПроблемToolStripMenuItem
		// 
		this->устранениеПроблемToolStripMenuItem->Name = L"устранениеПроблемToolStripMenuItem";
		this->устранениеПроблемToolStripMenuItem->Size = System::Drawing::Size(297, 26);
		this->устранениеПроблемToolStripMenuItem->Text = L"Остальные настройки";
		this->устранениеПроблемToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::устранениеПроблемToolStripMenuItem_Click);
		// 
		// дополнительноToolStripMenuItem
		// 
		this->дополнительноToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
			this->заменаВФайлеToolStripMenuItem,
				this->DelDileIds, this->преобразованияToolStripMenuItem, this->синтаксисSPSSБазыToolStripMenuItem, this->сообщитьОбОшибкеToolStripMenuItem
		});
		this->дополнительноToolStripMenuItem->Name = L"дополнительноToolStripMenuItem";
		this->дополнительноToolStripMenuItem->Size = System::Drawing::Size(132, 24);
		this->дополнительноToolStripMenuItem->Text = L"Дополнительно";
		// 
		// заменаВФайлеToolStripMenuItem
		// 
		this->заменаВФайлеToolStripMenuItem->Name = L"заменаВФайлеToolStripMenuItem";
		this->заменаВФайлеToolStripMenuItem->Size = System::Drawing::Size(235, 26);
		this->заменаВФайлеToolStripMenuItem->Text = L"Замена в файле";
		this->заменаВФайлеToolStripMenuItem->ToolTipText = L"Построчная замена в файле";
		this->заменаВФайлеToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::заменаВФайлеToolStripMenuItem_Click);
		// 
		// DelDileIds
		// 
		this->DelDileIds->Name = L"DelDileIds";
		this->DelDileIds->Size = System::Drawing::Size(235, 26);
		this->DelDileIds->Text = L"Удалить Id из файла";
		this->DelDileIds->ToolTipText = L"Удалить нумерацию в заголовках вопросов";
		this->DelDileIds->Click += gcnew System::EventHandler(this, &MainForm::DelDileIds_Click);
		// 
		// преобразованияToolStripMenuItem
		// 
		this->преобразованияToolStripMenuItem->Name = L"преобразованияToolStripMenuItem";
		this->преобразованияToolStripMenuItem->Size = System::Drawing::Size(235, 26);
		this->преобразованияToolStripMenuItem->Text = L"Преобразования";
		this->преобразованияToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::преобразованияToolStripMenuItem_Click);
		// 
		// синтаксисSPSSБазыToolStripMenuItem
		// 
		this->синтаксисSPSSБазыToolStripMenuItem->Name = L"синтаксисSPSSБазыToolStripMenuItem";
		this->синтаксисSPSSБазыToolStripMenuItem->Size = System::Drawing::Size(235, 26);
		this->синтаксисSPSSБазыToolStripMenuItem->Text = L"База SPSS";
		this->синтаксисSPSSБазыToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::синтаксисSPSSБазыToolStripMenuItem_Click);
		// 
		// сообщитьОбОшибкеToolStripMenuItem
		// 
		this->сообщитьОбОшибкеToolStripMenuItem->Name = L"сообщитьОбОшибкеToolStripMenuItem";
		this->сообщитьОбОшибкеToolStripMenuItem->Size = System::Drawing::Size(235, 26);
		this->сообщитьОбОшибкеToolStripMenuItem->Text = L"Сообщить об ошибке";
		this->сообщитьОбОшибкеToolStripMenuItem->Click += gcnew System::EventHandler(this, &MainForm::сообщитьОбОшибкеToolStripMenuItem_Click);
		// 
		// toolTip1
		// 
		this->toolTip1->AutoPopDelay = 10000;
		this->toolTip1->InitialDelay = 300;
		this->toolTip1->IsBalloon = true;
		this->toolTip1->ReshowDelay = 100;
		this->toolTip1->ShowAlways = true;
		// 
		// colorDialog1
		// 
		this->colorDialog1->Color = System::Drawing::Color::Red;
		// 
		// timer1
		// 
		this->timer1->Interval = 15;
		this->timer1->Tick += gcnew System::EventHandler(this, &MainForm::timer1_Tick);
		// 
		// versLabel
		// 
		this->versLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
		this->versLabel->AutoSize = true;
		this->versLabel->BackColor = System::Drawing::SystemColors::MenuBar;
		this->versLabel->Location = System::Drawing::Point(1076, 4);
		this->versLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
		this->versLabel->Name = L"versLabel";
		this->versLabel->Size = System::Drawing::Size(56, 17);
		this->versLabel->TabIndex = 2;
		this->versLabel->Text = L"Версия";
		// 
		// MainForm
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->BackColor = System::Drawing::Color::DarkGray;
		this->ClientSize = System::Drawing::Size(1195, 590);
		this->Controls->Add(this->versLabel);
		this->Controls->Add(this->tableLayoutPanel1);
		this->Controls->Add(this->menuStrip1);
		this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
		this->MainMenuStrip = this->menuStrip1;
		this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
		this->MinimumSize = System::Drawing::Size(1210, 457);
		this->Name = L"MainForm";
		this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
		this->Text = L"SurveyHelper";
		this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MainForm::MainForm_FormClosed);
		this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
		this->panel1->ResumeLayout(false);
		this->groupBox2->ResumeLayout(false);
		this->groupBox2->PerformLayout();
		this->groupBox1->ResumeLayout(false);
		this->groupBox1->PerformLayout();
		this->tableLayoutPanel1->ResumeLayout(false);
		this->XMLMenu->ResumeLayout(false);
		(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
		this->GridMenu->ResumeLayout(false);
		this->StatusBar->ResumeLayout(false);
		this->tableLayoutPanel2->ResumeLayout(false);
		this->tableLayoutPanel3->ResumeLayout(false);
		this->tableLayoutPanel3->PerformLayout();
		this->tableLayoutPanel4->ResumeLayout(false);
		this->tableLayoutPanel4->PerformLayout();
		this->panel2->ResumeLayout(false);
		this->panel2->PerformLayout();
		this->menuStrip1->ResumeLayout(false);
		this->menuStrip1->PerformLayout();
		this->ResumeLayout(false);
		this->PerformLayout();

	}

#pragma endregion



#pragma region отслеживание изменений


	private: System::Void QuestionHeader_TextChanged(System::Object^  sender, System::EventArgs^  e)
	{
		if ( QuestionHeader->Text->Contains(Environment::NewLine) )
		{
			String ^s = QuestionHeader->Text;
			s = s->Replace(Environment::NewLine, "");
			QuestionHeader->Clear();
			QuestionHeader->Text = s;
			RefreshButton->Focus();
			if ( !NoDynamic && Generated ) RefreshButton->PerformClick();
		}

		UpdateQuestionId();
	}

	private: System::Void adVar_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
	{
		VarButton->Enabled = adVar->Checked;
		if ( !NoDynamic && Generated && Vars->Count > 0 )	RefreshButton->PerformClick();
	}


	private: System::Void RefreshNums_Click(System::Object^  sender, System::EventArgs^  e)
	{
		ClearIds();
		NumerateId(false);
	}


	private: System::Void TextBox_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
	{
		switch ( e->KeyCode )
		{
			case Keys::Enter:
			case Keys::Escape:
				RefreshButton->Focus();
			break;

			case Keys::A:
				try
				{
					if ( e->Control ) ((TextBox^)sender)->SelectAll();
				}
				catch ( Exception^e )
				{

				};

			default:
			break;
		}
	}

	private: System::Void pageId_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
	{
		QIDManualChanged = true;
	}		


	private: System::Void dataGridView1_CellEndEdit(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
	{
		CheckForNullValue();
	}


	private: System::Void dataGridView1_CellBeginEdit(System::Object^  sender, System::Windows::Forms::DataGridViewCellCancelEventArgs^  e)
	{
		try
		{
			prevCell->Value = Convert::ToString(dataGridView1[e->ColumnIndex, e->RowIndex]->Value);
			prevCell->Row = e->RowIndex;
			prevCell->Column = e->ColumnIndex;
		}
		catch ( Exception^ e )
		{
			ShowError(303, "Ошибка обращения к ячейке таблицы\n\n\nПодробнее:\n" + e->ToString());
		}
	}


	private: System::Void ExtendTypes_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
	{
		if ( ExtendTypes->SelectedIndex < 1 )
		{
			ExtendString->Clear();
			return;
		}
		try
		{
			String^ s = ExtendTypes->SelectedItem->ToString();			
			if ( s == "DragItem" ) s = DragItem::Get();
			if ( s == "Slider" ) s = Slider::Get();
						
			if ( ExtendUi->ContainsKey(s) ) ExtendString->Text = ExtendUi[s];

			// убрать LabelEnd/start для List
			if ( s == "Scale" && !IsNumber(repeatName->Text) ) ExtendString->Text = Regex::Replace(ExtendString->Text, "Label(Start|End)=[\"'][^\"']+[\"']", "");

			// подгон QuestionType под Ui
			if ( CompTypes->ContainsKey(s) )
				QuestionTypes->SelectedIndex = QuestionTypes->Items->IndexOf(List<String^>(CompTypes[s])[0]);
		}
		catch ( Exception^ e )
		{
			ShowError(331, "Ошибка согласования типа с расширением.\n\nПодробнее:\n"+e->ToString());
		}

		checkBox3->Checked = true;
	
		if ( !NoDynamic && Generated ) RefreshButton->PerformClick();
	}
		 

	private: System::Void checkBox2_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
	{
		if ( adQuestion->Checked )
		{
			QuestionTypes->Enabled = true;
			if ( QuestionTypes->SelectedIndex == -1 ) QuestionTypes->SelectedIndex = 1;
			QuestionHeader->Enabled = true;
			checkBox3->Enabled = true;
		}
		else
		{
			checkBox3->Checked = false;
			QuestionTypes->Enabled = false;
			QuestionTypes->SelectedIndex = -1;
			QuestionHeader->Enabled = false;
			checkBox3->Enabled = false;
		}
		if ( !NoDynamic && Generated )	RefreshButton->PerformClick();
	}


	private: System::Void checkBox3_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
	{
		if ( checkBox3->Checked )
		{
			//ExtendTypes->Enabled = true;
			ExtendString->Enabled = true;
		}
		else 
		{
			//ExtendTypes->Enabled = false;
			ExtendString->Enabled = false;
			ExtendTypes->SelectedIndex = 0;
		}
		if ( !NoDynamic && Generated ) RefreshButton->PerformClick();
	}


	private: System::Void checkBox1_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
	{
		PageId->Enabled = adParent->Checked;
		if ( !NoDynamic && Generated )	RefreshButton->PerformClick();
	}
		 

	private: System::Void radio_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
	{
		if ( radioItem->Checked )
		{
			adParent->Text = "Добавить List";
			tableLayoutPanel3->Enabled = false;
			adVar->Enabled = true;
			SetUnion->Enabled = false;
			dataGridView1->Columns[1]->HeaderText = "Text";
		}	
		

		if ( radioAnswer->Checked )
		{
			adVar->Enabled = false;
			adParent->Text = "Добавить Page";
			tableLayoutPanel3->Enabled = true;
			adQuestion->Text = "Добавить Question";
			SetUnion->Enabled = false;
			dataGridView1->Columns[1]->HeaderText = "Text";
			intoList->Enabled = true;
		}
		else intoList->Enabled = false;


		if ( radioUnion->Checked )
		{
			adVar->Enabled = false;
			dataGridView1->Columns[1]->HeaderText = "Answers";
			adParent->Text = "Объединить ответы в List";
			tableLayoutPanel3->Enabled = true;
			adQuestion->Text = "Объединяющий вопрос";
			SetUnion->Text = "Настройка Union";
			SetUnion->Enabled = true;
			adQuestion->Checked = true;
		}


		if ( radioBlock->Checked )
		{
			adVar->Enabled = false;
			dataGridView1->Columns[1]->HeaderText = "Answers";
			adParent->Text = "Добавить Page";
			tableLayoutPanel3->Enabled = true;
			adQuestion->Text = "Добавить Question";
			SetUnion->Enabled = true;
			SetUnion->Text = "Настройка блока";
			adQuestion->Checked = true;
			adQuestion->Enabled = false;
			QuestionHeader->Enabled = false;
			if ( pageHeader->Text == _PageHeader && QuestionHeader->Text != _QuestionHeader )
			{
				pageHeader->Text = QuestionHeader->Text;
				PHChanged = true;
			}
		}
		else
		{
			adQuestion->Enabled = true;
			QuestionHeader->Enabled = true;
			if ( PHChanged )
			{
				pageHeader->Text = _PageHeader;
				PHChanged = false;
			}
		}

		UpdateQuestionId();

		if ( !NoDynamic && Generated && !RadioSpike ) RefreshButton->PerformClick();
		RadioSpike = !RadioSpike;
	}
		 

	private: System::Void MakeColor_Click(System::Object^  sender, System::EventArgs^  e)
	{
		int bef = TextMemo2->SelectionStart;
		int aft = bef + TextMemo2->SelectionLength;

		TextMemo2->Text = (TextMemo2->Text->Insert(aft, "[/u]"))->Insert(bef, "[u]");
		if ( CopyBuf->Checked ) CopyToBuffer(gcnew List<String^>(TextMemo2->Lines));
	}


	private: System::Void MakeBold_Click(System::Object^  sender, System::EventArgs^  e)
	{
		int bef = TextMemo2->SelectionStart;
		int aft = bef + TextMemo2->SelectionLength;

		TextMemo2->Text = (TextMemo2->Text->Insert(aft, "[/b]"))->Insert(bef, "[b]");
		if ( CopyBuf->Checked ) CopyToBuffer(gcnew List<String^>(TextMemo2->Lines));
	}


	private: System::Void TextMemo2_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
	{
		bool sel = !(String::IsNullOrEmpty(TextMemo2->SelectedText));
		if ( e->Button == Forms::MouseButtons::Left ) return;

		MakeBold->Enabled = sel;
		MakeColor->Enabled = sel;
		выделитьКурсивомiToolStripMenuItem->Enabled = sel;
	}


	private: System::Void KeyPressed(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
	{
		switch ( e->KeyCode )
		{
			case Keys::F5: 
				RefreshButton->Focus();
				RefreshButton->PerformClick();
				break;

			case Keys::F9: 
				RefreshButton->Focus();
				ClearButton->PerformClick();
				break;

			case Keys::F4: 
				RefreshButton->Focus();
				CleanTxt->PerformClick();
				break;

			default:
				break;
		}
	}


	private: System::Void TextBox_Click(System::Object^  sender, System::EventArgs^  e)
	{
		((TextBox^)sender)->SelectAll();
	}


	private: System::Void pageHeader_TextChanged(System::Object^  sender, System::EventArgs^  e)
	{
		if ( radioBlock->Checked && pageHeader->Text != nullptr && pageHeader->Text != _PageHeader && !QIDManualChanged )
		{
			String^ tmp = GetQuestionId(pageHeader->Text);
			PageId->Text = tmp == "" ? _QuestionId : tmp;
		}
		if ( pageHeader->Text->Contains(Environment::NewLine) )
		{
			String ^s = pageHeader->Text;
			s = s->Replace(Environment::NewLine, "");
			pageHeader->Clear();
			pageHeader->Text = s;
			RefreshButton->Focus();
			if ( !NoDynamic && Generated ) RefreshButton->PerformClick();
		}
	}


	private: System::Void ExtendString_TextChanged(System::Object^  sender, System::EventArgs^  e)
	{
		if ( ExtendString->Text->Contains(Environment::NewLine) )
		{
			String ^s = ExtendString->Text;
			s = s->Replace(Environment::NewLine, "");
			ExtendString->Clear();
			ExtendString->Text = s;
			RefreshButton->Focus();
			if ( !NoDynamic && Generated ) RefreshButton->PerformClick();
		}
	}


	private: System::Void CleanText_Click(System::Object^  sender, System::EventArgs^  e)
	{
		List<DataGridViewTextBoxCell^>^ rows = gcnew List<DataGridViewTextBoxCell^>();
		DataGridViewRow^ r = gcnew DataGridViewRow();
		for each (DataGridViewTextBoxCell^ c in dataGridView1->SelectedCells)
		{
			if ( !rows->Contains(c) ) rows->Add(c);
		}

		for each (DataGridViewTextBoxCell^ rt in rows)
		{
			if (!!rt->Value ) dataGridView1[rt->ColumnIndex, rt->RowIndex]->Value = CleanText(rt->Value->ToString());
		}
	}


	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e)
	{
		if ( minimized )
			if ( percent < 50 ) percent += 2;
			else
			{
				minimized = false;
				timer1->Stop();
				button2->Text = "<";
			}
		else
			if ( percent > 0 ) percent -= 2;
			else
			{
				minimized = true;
				timer1->Stop();
				button2->Text = ">";
			}

		tableLayoutPanel1->ColumnStyles[0] = gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, percent);
		tableLayoutPanel1->ColumnStyles[2] = gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 100 - percent);
	}


	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e)
	{
		timer1->Start();
	}


	private: System::Void DelDileIds_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (headersForm->IsDisposed) headersForm = gcnew Headers();
		headersForm->Show();
		headersForm->Activate();
	}


	private: System::Void cMix_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
	{
		if ( cMix->Checked ) cMixId->Checked = false;
		if ( !NoDynamic && Generated ) RefreshButton->PerformClick();
	}


	private: System::Void cMixId_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
	{
		if ( cMixId->Checked ) cMix->Checked = false;
		MixIdText->Enabled = cMixId->Checked;
		if ( !NoDynamic && Generated ) RefreshButton->PerformClick();
	}


	private: System::Void QuestionHeader_Leave(System::Object^  sender, System::EventArgs^  e)
	{
		if ( String::IsNullOrEmpty(QuestionHeader->Text) )
		{
			QuestionHeader->Text = _QuestionHeader;
			PageId->Text = _QuestionId;
			return;
		}

		ValidateQuestionID();
	}


	private: System::Void dataGridView1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^  e)
	{
		switch ( e->KeyCode )
		{
			case Keys::Enter:
				if ( dataGridView1->RowCount < dataGridView1->CurrentRow->Index + 2 )
				{
					dataGridView1->Rows->Add();
					NumerateId(false);
				}
				break;

			case Keys::Delete:
				delCurrentRow->PerformClick();
				break;

			default:
				break;
		}
	}


	private: System::Void TextMemo2_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
	{
		if ( !!e->Control )
		{
			int lp = TextMemo2->SelectionStart + TextMemo2->SelectionLength;
			bool a = true;
			switch ( e->KeyCode )
			{
				case Keys::U:
					MakeColor->PerformClick();
					break;
				case Keys::I:
					выделитьКурсивомiToolStripMenuItem->PerformClick();
					break;
				case Keys::B:
					MakeBold->PerformClick();
					break;
				case Keys::D:
					TextMemo2->Text = TextMemo2->Text->Replace(TextMemo2->SelectedText, "[div]" + TextMemo2->SelectedText + "[/div]");
					break;
				case Keys::H:
					добавитьHintToolStripMenuItem->PerformClick();
					break;
				case Keys::S:
					TextMemo2->Text = TextMemo2->Text->Replace(TextMemo2->SelectedText, "[span]" + TextMemo2->SelectedText + "[/span]");
					break;
				default:
					a = false;
					break;
			}
			if ( a ) TextMemo2->SelectionStart = TextMemo2->Text->IndexOf("]", lp) + 1;
		}
	}



#pragma region Menu

	private: System::Void преобразованияToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (convForm->IsDisposed) convForm = gcnew SurveyConverter(curVers);
		convForm->Show();
		convForm->Activate();
	}


	private: System::Void заменаВФайлеToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (fRepForm->IsDisposed) fRepForm = gcnew FileReplace();
		fRepForm->Show();
		fRepForm->Activate();
	}


	private: System::Void sortText_Click(System::Object^  sender, System::EventArgs^  e)
	{
		SortColumn(1);
	}


	// меню - сортировать Id
	private: System::Void sortId_Click(System::Object^  sender, System::EventArgs^  e)
	{
		SortColumn(0);
	}


	// удаление Item/Answer
	private: System::Void delCurrentRow_Click(System::Object^  sender, System::EventArgs^  e)
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

			//dataGridView1->Rows->RemoveAt(dataGridView1->CurrentCell->RowIndex);
			if ( dataGridView1->RowCount > 1 && MessageBox::Show("Обновить нумерацию?", "", Forms::MessageBoxButtons::YesNo, Forms::MessageBoxIcon::Question) == Forms::DialogResult::Yes )
			{
				ClearIds();
				NumerateId(false);
			}
		}
		catch ( Exception^ e )
		{
			ShowError(330, "Ошибка удаления строки. \n\nПодробнее:\n" + e->ToString());
		}	
	}

	// добавление Item/Answer
	private: System::Void addRow_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if ( dataGridView1->SelectedCells->Count < 1 )
		{
			ShowWarning("Сначала выделите ячейку, после которой нужно вставить строку!");
			return;
		}
		if ( dataGridView1->CurrentRow->Index + 1 < dataGridView1->RowCount ) dataGridView1->Rows->Insert(dataGridView1->CurrentRow->Index + 1, 1);
		else dataGridView1->Rows->Add();
	}


	private: System::Void QuestionHeader_Enter(System::Object^  sender, System::EventArgs^  e)
	{
		if ( QuestionHeader->Text == _QuestionHeader )
			QuestionHeader->Clear();
	}


	private: System::Void PageId_Enter(System::Object^  sender, System::EventArgs^  e)
	{
		if ( PageId->Text == _QuestionId ) PageId->Clear();
	}

	private: System::Void PageId_Leave(System::Object^  sender, System::EventArgs^  e)
	{
		if ( String::IsNullOrEmpty(PageId->Text) ) PageId->Text = _QuestionId;
		else
		{
			String ^str = PageId->Text;
			String ^Qtr = ImprovePropertyLanguage(str);
			if ( Qtr->Length > 0 && IsNumber(Qtr[0].ToString()) ) Qtr = "Q" + Qtr;
			if ( str != Qtr )
			{
				QuestionDialog::Result^ res = DontAsk["QuestionHeader"];
				if ( !DontAsk["QuestionHeader"]->CheckBoxChecked )
				{
					res = QuestionDialog::Show(
						"Id страницы содержит недопустимые символы\nЗаменить \"" + str + "\" на \"" + Qtr + "\"",
						"Проверка корректности",
						QuestionDialog::Buttons::YesNo,
						true);
					DontAsk["QuestionHeader"] = res;
				}

				if ( res->DialogResult == QuestionDialog::Results::Yes )
					PageId->Text = Qtr;
			}
		}
	}


	private: System::Void pageHeader_Enter(System::Object^  sender, System::EventArgs^  e)
	{
		if ( pageHeader->Text == _PageHeader ) pageHeader->Clear();
	}


	private: System::Void pageHeader_Leave(System::Object^  sender, System::EventArgs^  e)
	{
		if ( String::IsNullOrEmpty(pageHeader->Text) ) pageHeader->Text = _PageHeader;
		else if (GetPageId->Checked && radioBlock->Checked) ValidateQuestionID();
	}


	private: System::Void adRepeat_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
	{
		repeatName->Enabled = adRepeat->Checked;
		repeatText->Enabled = !String::IsNullOrEmpty(repeatName->Text) && IsNumber(repeatName->Text) && repeatName->Enabled;
		if ( !NoDynamic && Generated )	RefreshButton->PerformClick();
	}


	private: System::Void repeatName_TextChanged(System::Object^  sender, System::EventArgs^  e)
	{
		if (String::IsNullOrEmpty(repeatName->Text)) return;
		repeatText->Enabled = true;
		if (repeatText->Text == "") repeatText->Text = IsNumber(repeatName->Text) ? "@Itera" : "@Text";
	}

	//добавление Hint
	private: System::Void добавитьHintToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		String^ newText = TextMemo2->Text;
		try
		{
			if ( !newText->Contains("<Question") )
			{
				ShowWarning("Не найден тег <Question>");
				return;
			}
			hintForm->ShowDialog();
			String^ hint = hintForm->richTextBox1->Text->Replace("\n", "[br]");
			int from = newText->IndexOf(">", newText->IndexOf("<Question") + 8);

			if ( radioUnion->Checked )
			{
				//newText = newText->Remove(from) + " Hint=\"" + hint + "\"" + newText->Remove(0, from);
				newText = newText->Remove(newText->IndexOf("</Repeat>"))->Replace("<Question", "<Question Hint=\"\"") +
					newText->Remove(0, newText->IndexOf("</Repeat>"))->Replace("<Question", "<Question Hint=\"" + hint + "\"");
			}
			else
			{
				if ( radioBlock->Checked )
				{
					String^ hnt = "[div class=\"question-hint\"]" + hint + "[/div]";
					if ( Regex::IsMatch(newText, "<Page[^(<Repeat))]+<Header") )
					{
						from = newText->IndexOf("</", newText->IndexOf("<Header"));
					}
					else
					{
						hnt = "\n" + gcnew String('\t', StrToInt(tabs->SelectedItem->ToString()) + 1) + "<Header>" + hnt + "</Header>";
						from = newText->IndexOf(">", newText->IndexOf("<Page")) + 1;
					}
					newText = newText->Insert(from, hnt);
				}
				else
					newText = newText->Insert(from, " Hint=\"" + hint + "\"");
			}
			TextMemo2->Text = newText;
			if ( CopyBuf->Checked ) CopyToBuffer(gcnew List<String^>(TextMemo2->Lines));
		}
		catch ( Exception^ e )
		{
			ShowError(317, "Ошибка при добавлении элемента Hint\n\nПодробнее:\n" + e->ToString());
		}
	}

	// добавление CustomText2
	private: System::Void customTextToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		String^ newText = TextMemo2->Text;
		try
		{
			if ( !newText->Contains("<Page") && TextMemo2->Text->Length > 1 )
			{
				ShowWarning("Не найден тег <Page>");
				return;
			}
			String^ tab;
			for ( int i = 0; i <= StrToInt(tabs->SelectedItem->ToString()); i++ )
				tab += "\t";
			newText = ((TextMemo2->Text->Length > 1) ? (newText->Remove(newText->IndexOf(">") + 1)) : "") +
				"\n" + tab + "\t<CustomText2>" +
				"\n" + tab + "\t\t<![CDATA[" +
				"\n" + tab + "\t\t\t<script>" +
				"\n" + tab + "\t\t\t\t$(document).ready(function(){" +
				"\n" + tab + "\t\t\t\t\t" +
				"\n" + tab + "\t\t\t\t});" +
				"\n" + tab + "\t\t\t</script>" +
				"\n" +
				"\n" + tab + "\t\t\t<style>" +
				"\n" + tab + "\t\t\t\t" +
				"\n" + tab + "\t\t\t</style>" +
				"\n" + tab + "\t\t]]>" +
				"\n" + tab + "\t</CustomText2>" +
				((TextMemo2->Text->Length > 1) ? (newText->Remove(0, newText->IndexOf(">") + 1)) : "");
			TextMemo2->Text = newText;
			if ( CopyBuf->Checked ) CopyToBuffer(gcnew List<String^>(TextMemo2->Lines));
		}
		catch ( Exception^ e )
		{
			ShowError(318, "Ошибка при добавлении элемента CustomText2\n\nПодробнее:\n" + e->ToString());
		}
	}

	// форма настроек
	private: System::Void устранениеПроблемToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		pForm->ignorSpaces->Checked = IgnorSpaces;
		pForm->dontClear->Checked = DontClear;
		pForm->Clearatonce->Checked = ClearAtOnce;
		pForm->UpdateCheck->Checked = !DontUpdate;
		pForm->noDyn->Checked = !NoDynamic;
		pForm->alwaysSep->Checked = TextAlwaysSep;
		pForm->allBack->Checked = ReturnBack;
		pForm->clearHeader->Checked = !ClearHeader;
		pForm->checkCorrect->Checked = CheckCorrect;
		pForm->minimize->Checked = MinimizeAfter;
		pForm->autoReplace->Checked = CustomRepalce;
		pForm->autoScreen->Checked = !NoAutoTag;
		pForm->curVers = curVers;
		pForm->ShowDialog();

		IgnorSpaces = pForm->ignorSpaces->Checked;
		ClearHeader = !pForm->clearHeader->Checked;
		ReturnBack = pForm->allBack->Checked;
		DontClear = pForm->dontClear->Checked;
		ClearAtOnce = pForm->Clearatonce->Checked;
		DontUpdate = !pForm->UpdateCheck->Checked;
		NoDynamic = !pForm->noDyn->Checked;
		TextAlwaysSep = pForm->alwaysSep->Checked;
		CheckCorrect = pForm->checkCorrect->Checked;
		MinimizeAfter = pForm->minimize->Checked;
		CustomRepalce = pForm->autoReplace->Checked;
		if (pForm->TemplatesChanged) CustomTemplates = pForm->Templates;
		NoAutoTag = !pForm->autoScreen->Checked;
		/*if ( TextAlwaysSep )
		{
			SepText->Checked = true;
			SepText->Enabled = false;
		}
		else SepText->Enabled = true;*/
	}


	private: System::Void выделитьКурсивомiToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		int bef = TextMemo2->SelectionStart;
		int aft = bef + TextMemo2->SelectionLength;

		TextMemo2->Text = (TextMemo2->Text->Insert(aft, "[/i]"))->Insert(bef, "[i]");
		if ( CopyBuf->Checked ) CopyToBuffer(gcnew List<String^>(TextMemo2->Lines));
	}


	private: System::Void выделитьДругимЦветомToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if ( colorDialog1->ShowDialog() != Forms::DialogResult::OK ) return;

		String^ color = Drawing::ColorTranslator::ToHtml(colorDialog1->Color);

		int bef = TextMemo2->SelectionStart;
		int aft = bef + TextMemo2->SelectionLength;

		TextMemo2->Text = (TextMemo2->Text->Insert(aft, "[/span]"))->Insert(bef, "[span style=\"color: " + color->ToLower() + "\"]");
		if ( CopyBuf->Checked ) CopyToBuffer(gcnew List<String^>(TextMemo2->Lines));
	}


#pragma endregion



#pragma endregion



#pragma region Переменные


		 prevCellstr^ prevCell = gcnew prevCellstr();

		 //формы
		 VarForm^ VForm = gcnew VarForm();
		 Problems^ pForm = gcnew Problems();
		 UnionQuestions^ Unionform;
		 HintForm^ hintForm = gcnew HintForm();
		 PilotSyntax^ spssForm = gcnew PilotSyntax();
		 Headers^ headersForm = gcnew Headers();
		 SurveyConverter^ convForm = gcnew SurveyConverter(curVers);
		 FileReplace^ fRepForm = gcnew FileReplace();

		 AutoCompleteStringCollection^ lists = gcnew AutoCompleteStringCollection();

		 bool IgnorSpaces = false;
		 bool DontClear = false;
		 bool ClearAtOnce = false;
		 bool DontUpdate = false;
		 bool TextAlwaysSep = false;
		 bool NoDynamic = false;
		 bool NoAutoTag = false;
		 bool ReturnBack = true;
		 bool ClearHeader = true;
		 bool CheckCorrect = true;
		 bool MinimizeAfter = false;
		 bool CustomRepalce = false;

		 bool CurrentAction = false;
		 bool WarningOccured;
		 bool Generated = false;
		 bool minimized = false;
		 int percent = 50;
		 bool RadioSpike = false;
		 bool includeDone = false;
		 bool PHChanged = false;
		 bool QIDManualChanged = false;
		 
		 Dictionary<String^, QuestionDialog::Result^>^ DontAsk = gcnew Dictionary<String^, QuestionDialog::Result^>();

		 // Настройки по умолчанию
		 DefaultValueList^ Defaults = gcnew DefaultValueList();


		 // для Union
		 String^ QuestionListId;
		 //String^ UnionQuestionType;
		 List<String^>^ Questions = gcnew List<String^>();
		 bool CombineQuestions;
		 UnionMixType unionMix;
		 MixType mix;
		 String^ unionMixIdText;
		 List<AddonTag^>^ addonTags = gcnew List<AddonTag^>();
		 Addon^ addons = gcnew Addon(_libraryPath);
		 Dictionary<String^, int>^ FeatureTypes = gcnew  Dictionary<String^, int>();
		 String ^prevCustText = "", ^prevAnsText = "", ^prevMeth = "";

		 String^ curVers = "";
		 //String^ lasVers = "";

		 // пользовательские шаблоны для замены
		 CustomTemplateList^ CustomTemplates = gcnew CustomTemplateList();

		public: 
			static List<List<String^>^>^ Vars = gcnew List<List<String^>^>();
			static bool varSeparate;

			// строки для Extend = ....
			static Dictionary<String^, String^>^ ExtendUi = gcnew Dictionary<String^, String^>();

			// список подходящих типов для Extend
			static Dictionary<String^, List<String^>^>^ CompTypes = gcnew Dictionary<String^, List<String^>^>();

			// список вариантов Type для DragItem
			static List<String^>^ DragItems = gcnew List<String^>();


#pragma endregion





#pragma region доп функции

		// проверка QuestionId
		private: System::Void ValidateQuestionID()
		{
			String ^str = GetQuestionId(radioBlock->Checked ? pageHeader->Text : QuestionHeader->Text);
			String ^Qtr = ImprovePropertyLanguage(str);
			if ( Qtr->Length > 0 && IsNumber(Qtr[0].ToString()) ) Qtr = "Q" + Qtr;
			if ( str != Qtr )
			{
				QuestionDialog::Result^ res = DontAsk["QuestionHeader"];
				if ( !DontAsk["QuestionHeader"]->CheckBoxChecked )
				{
					res = QuestionDialog::Show(
						"Id вопроса содержит недопустимые символы\nЗаменить \"" + str + "\" на \"" + Qtr + "\"?",
						"Проверка корректности",
						QuestionDialog::Buttons::YesNo,
						true);
					DontAsk["QuestionHeader"] = res;
				}

				if ( res->DialogResult == QuestionDialog::Results::Yes )
				{
					if ( radioBlock->Checked )
						pageHeader->Text = pageHeader->Text->Replace(str, Qtr);
					else
						QuestionHeader->Text = QuestionHeader->Text->Replace(str, Qtr);
					if ( GetPageId->Checked && !QIDManualChanged )
						PageId->Text = Qtr;
				}
			}
		}


		// обновляет поле PageId
		private: System::Void UpdateQuestionId()
		{
			if ( !GetPageId->Checked || QIDManualChanged ) return;
			String^ s = GetQuestionId(QuestionHeader->Text);

			if ( radioUnion->Checked && s != "" )
				s += "_AList";

			if ( radioBlock->Checked  )
				s = GetQuestionId(pageHeader->Text);

			if ( radioItem->Checked && s != "" )
				s += "_List";

			if ( s != "" ) PageId->Text = s;
		}


		private: System::Void PerformanceUpdate(System::Object^  sender, System::EventArgs^  e)
		{
			if ( !NoDynamic && Generated ) RefreshButton->PerformClick();
		}
		

		// добавление Ui Isolate
		private: Void MakeIsolate()
		{
			if ( !TextMemo2->Text->Contains("Reset=\"true\"") ) return;
			String^ res = "";
			int ind = TextMemo2->Text->IndexOf(">", TextMemo2->Text->IndexOf("Reset=\"true\"")) + 1;
			res = TextMemo2->Text->Remove( ind );
			res += "<Ui Isolate=\"1\"/>";
			res += TextMemo2->Text->Remove(0, ind);
			TextMemo2->Text = res;
		}


		// обновление списка листов (<List Id=...>)
		void UpdateLists()
	{
		if ( !String::IsNullOrEmpty(repeatName->Text) && !lists->Contains(repeatName->Text) ) lists->Add(repeatName->Text);
		if ( radioItem->Checked && !String::IsNullOrEmpty(PageId->Text) && !lists->Contains(PageId->Text) ) lists->Add(PageId->Text);
	}
		
		
		void AddFalseFilter()
		{
			String^ newText = TextMemo2->Text;
			try
			{
				if ( !newText->Contains("<Page") ) return;

				String^ tab;
				for ( int i = 0; i <= StrToInt(tabs->SelectedItem->ToString()); i++ )
					tab += "\t";
				newText = newText->Remove(newText->IndexOf(">") + 1) +
					"\n" + tab + "\t<Filter>false;</Filter>" +
					newText->Remove(0, newText->IndexOf(">") + 1);

				TextMemo2->Text = newText;
			}
			catch ( Exception^ e )
			{
				ShowError(319, "Ошибка при добавлении элемента Filter\n\nПодробнее:\n" + e->ToString());
			}
		}


		private: void ClearIds()
		{
			CurrentAction = true;
			try
			{
				for ( int i = 0; i < dataGridView1->RowCount - 1; i++ )
					dataGridView1->Rows[i]->Cells[0]->Value = -1;
			}
			catch ( Exception^ e )
			{
				ShowError(304, "Ошибка обращения к ячейке таблицы\n\nПодробнее:\n" + e->ToString());
			}
			CurrentAction = false;
		}


		 // проверка Id на непустое значение
		void CheckForNullValue()
		 {
			 if ( CurrentAction ) return;
			 bool nullValue = false;
			 try
			 {
				 for ( int i = 0; i < dataGridView1->RowCount - 1; i++ )
					 if (
						 dataGridView1->Rows[i]->Cells[0]->Value == nullptr ||
						 String::IsNullOrEmpty(dataGridView1->Rows[i]->Cells[0]->Value->ToString())
						 )
					 {
						 dataGridView1->Rows[i]->Cells[0]->Value = 0;
						 nullValue = true;
					 }
			 }
			 catch ( Exception^ e )
			 {
				 ShowError(305, "Ошибка обращения к ячейке таблицы\n\nПодробнее:\n" + e->ToString());
			 }

			 if ( nullValue )
				 ShowWarning("Ошибка ввода данных.\nЗначение в стобце Id не может быть пустым.\n Пустые значения будут заменены на 0.");
		 }


		 // завершение ввода данных
		 void EndUserEdit()
		 {
			 dataGridView1->EditMode = DataGridViewEditMode::EditProgrammatically;
			 dataGridView1->EndEdit();
			 dataGridView1->Update();
			 CurrentAction = true;
		 }


		 // разрешение ввода данных
		 void StartUserEdit()
		 {
			 CurrentAction = false;
			 dataGridView1->EndEdit();
			 dataGridView1->Update();
			 dataGridView1->EditMode = DataGridViewEditMode::EditOnKeystrokeOrF2;
		 }


		 List<String^>^ ColumnToList(int colNum)
		 {
			 List<String^>^ res = gcnew List<String^>();

			 try
			 {
				 for each (DataGridViewRow^ row in dataGridView1->Rows)
					 res->Add(Convert::ToString(row->Cells[colNum]->Value));
			 }
			 catch ( Exception^ e )
			 {
				 ShowError(306, "Ошибка обращения к ячейке таблицы\n\nПодробнее:\n" + e->ToString());
			 }

			 res->RemoveAt(res->Count - 1);

			 return res;
		 }


		 void ListToColumn(List<String^>^ list, int colNum)
		 {
			 if ( list == nullptr || list->Count < 1 ) return;

			 try
			 {
				 for ( int i = 0; i < list->Count; i++ )
				 {
					 if ( i > dataGridView1->RowCount - 1 )
					 {
						 dataGridView1->Rows->Add();
						 NumerateId(false);
					 }
					 dataGridView1->Rows[i]->Cells[colNum]->Value = list[i];
				 }
			 }
			 catch ( Exception ^e )
			 {
				 ShowError(328, "Ошибка обновления списка элементов. \n\nПодробнее:\n" + e->ToString());
			 }
		 }


		 // нумерация Id и очистка текста
		 void NumerateId(bool forced)
		 {
			 CurrentAction = true;
			 int k = 1;
			 try
			 {
				 for ( int i = 0; i < dataGridView1->RowCount - 1; i++ )
					 if ( dataGridView1->Rows[i]->Cells[2]->Value == nullptr || String::IsNullOrEmpty(dataGridView1->Rows[i]->Cells[2]->Value->ToString()) )
					 {
						 if ( dataGridView1->Rows[i]->Cells[1]->Value == nullptr ) dataGridView1->Rows[i]->Cells[1]->Value = "";
						 dataGridView1->Rows[i]->Cells[2]->Value = (AutoNumId->Checked) ? GetId(dataGridView1->Rows[i]->Cells[1]->Value->ToString(), IgnorSpaces) : -1;
						 dataGridView1->Rows[i]->Cells[1]->Value = ClearString(dataGridView1->Rows[i]->Cells[1]->Value->ToString(), false, !DontClear, IgnorSpaces);
					 }
			 }
			 catch ( Exception^ e )
			 {
				 ShowError(307, "Ошибка при автонумерации Id\n\nПодробнее:\n" + e->ToString());
			 }
			 
			 try
			 {
				 int k = (IsNumber(repeatName->Text) && adRepeat->Checked) ? (StrToInt(repeatName->Text)+1) : 1;
				 List<String^>^ ids = gcnew List<String^>();
				 int sn = 0;
				 for ( int i = 0; i < dataGridView1->RowCount - 1; i++ )
				 {
					 if ( dataGridView1->Rows[i]->Cells[2]->Value == nullptr || String::IsNullOrEmpty(dataGridView1->Rows[i]->Cells[2]->Value->ToString()) )
						 dataGridView1->Rows[i]->Cells[2]->Value = "-1";
					 if ( dataGridView1->Rows[i]->Cells[2]->Value->ToString() == "-1" )
					 {
						 while ( ids->Contains(k.ToString()) ) k++;
						 dataGridView1->Rows[i]->Cells[0]->Value = k;
						 ids->Add(k.ToString());
					 }
					 else
					 {
						 sn = (int)dataGridView1->Rows[i]->Cells[2]->Value;
						 /*if ( forced )
						 {*/
							 while ( ids->Contains(sn.ToString()) ) sn++;
							 ids->Add(sn.ToString());
							 //ShowMessage(sn);
						 //}
						 dataGridView1->Rows[i]->Cells[0]->Value = sn;
					 }
				 }
			 }
			 catch ( Exception^ e )
			 {
				 ShowError(308, "Ошибка при автонумерации Id\n\nПодробнее:\n" + e->ToString());
			 }
			CurrentAction = false;
		 }


		 void SortColumn(int Column)
		 {
			 List<String^>^ tmpS = gcnew List<String^>();
			 List<int>^ tmpI = gcnew List<int>();
			 int i, k;
			 bool nullValue = false;

			 EndUserEdit();
			 if ( dataGridView1->Rows[1]->Cells[Column]->Value->GetType()->ToString() != "System.Int32" )
			 {
				 try
				 {
					 for ( i = 0; i < dataGridView1->RowCount - 1; i++ )
						 if ( dataGridView1->Rows[i]->Cells[Column]->Value != nullptr )
							 tmpS->Add(dataGridView1->Rows[i]->Cells[Column]->Value->ToString());
						 else tmpS->Add("");

						 tmpS->Sort();

						 for ( i = 0; i < tmpS->Count; i++ )
							 dataGridView1->Rows[i]->Cells[Column]->Value = tmpS[i];
				 }
				 catch ( Exception^ e )
				 {
					 ShowError(309, "Ошибка при сортировке столбца типа Int\n\nПодробнее:\n" + e->ToString());
				 }
			 }
			 else
			 {
				 try
				 {
					 for ( i = 0; i < dataGridView1->RowCount - 1; i++ )
					 {
						 Int32::TryParse(dataGridView1->Rows[i]->Cells[Column]->Value->ToString(), k);
						 tmpI->Add(k);
					 }

					 tmpI->Sort();
					 for ( i = 0; i < tmpI->Count; i++ )
						 dataGridView1->Rows[i]->Cells[Column]->Value = tmpI[i];
				 }
				 catch ( Exception^ e )
				 {
					 ShowError(310, "Ошибка при сортировке столбца типа String\n\nПодробнее:\n" + e->ToString());
				 }
			 }
			 StartUserEdit();
		 }

		 
		 // размещение дополнительного тега в нужном месте
		 void PlaceAddon(AddonTag^ t)
		 {
			 Dictionary<String^, String^>^ res = gcnew Dictionary<String^, String^>(Addon::FindAddons(t));
			 int after;
			 int tabCount;
			 //int pos;
			 String^ s = "", ^str = "";
			 for each (KeyValuePair<String^, String^>^ p in res)
			 {
				 if ( !FeatureTypes->ContainsKey(p->Key) ) continue;
				 after = 0;
				 tabCount = StrToInt(tabs->SelectedItem->ToString());
				 s = "";
				 str = "";
				 after = 0;

				 switch ( FeatureTypes[p->Key] )
				 {
					 /*
					 case 1:
						 // CustomText2
						 for ( int i = 0; i < tabCount + 1; i++ )
							 s += "\t";
						 str = "\n" + s + p->Value;
						 str = str->Replace(Environment::NewLine, Environment::NewLine + s);

						 if ( prevCustText->Contains(str) ) // без этого костыля почему-то не работает
						 {
							 str = "";
							 break;
						 }

						 prevCustText += str;

						 if ( !TextMemo2->Text->Contains("<Page") ) break;
						 after = TextMemo2->Text->IndexOf(">", TextMemo2->Text->IndexOf("<Page")) + 1;

						 if ( TextMemo2->Text->Contains("CustomText2") )
						 {
							 str = str->Remove(0, str->IndexOf(">", str->IndexOf("<CustomText2")) + 1);
							 str = str->Remove(str->IndexOf("</CustomText2"));
							 if ( TextMemo2->Text->Contains("CDATA") && str->Contains("CDATA") )
							 {
								 str = str->Remove(0, str->IndexOf("[", str->IndexOf("CDATA")) + 1);
								 str = str->Remove(str->IndexOf("]]>"));
								 after = TextMemo2->Text->IndexOf("]]>");
								 str = "\t" + s + str;
							 }
							 else
							 {
								 after = TextMemo2->Text->IndexOf("</CustomText2");
							 }
							 str = s + str;
						 }

						 break;
						 
					 case 2:
						 // AnswerText
						 if ( !TextMemo2->Text->Contains("<Answer") ) break;

						 str = p->Value->Replace(Environment::NewLine, "");
						 str = str->Replace("<AnswerText>", "");
						 str = str->Replace("</AnswerText>", "");

						 pos = TextMemo2->Text->IndexOf("<Answer");
						 pos = TextMemo2->Text->IndexOf(">", pos);

						 str = "<Text>" + str + "</Text>";

						 if ( TextMemo2->Text->IndexOf("Text=") < 0 && ( TextMemo2->Text->IndexOf("/", TextMemo2->Text->IndexOf("<Answer")) < 0 || pos < TextMemo2->Text->IndexOf("/", TextMemo2->Text->IndexOf("<Answer")) ) )
						 {
							 pos = TextMemo2->Text->IndexOf("<Answer");
							 pos = TextMemo2->Text->IndexOf(">", pos);
							 TextMemo2->Text = TextMemo2->Text->Remove(TextMemo2->Text->IndexOf("<Answer") + 7, pos - TextMemo2->Text->IndexOf("<Answer") - 7);
						 }
						 else
						 {
							 str += "</Answer>";
							 pos = TextMemo2->Text->IndexOf("<Answer");
							 pos = TextMemo2->Text->IndexOf("/", pos);
							 if ( pos > -1 )
								 TextMemo2->Text = TextMemo2->Text->Remove(pos, 1);
						 }
								 
						 after = TextMemo2->Text->IndexOf(">", TextMemo2->Text->IndexOf("<Answer")) + 1;

						 // for Gradient()
						 if ( !IsNumber(repeatName->Text) )
						 {
							 str = str->Replace("ответ @Itera", "@Text");
							 str = str->Replace("@Itera", "@ID");
						 }


						 if ( prevAnsText->Contains(str) ) // без этого костыля почему-то не работает
							 str = "";
						 else
							 prevAnsText += str;

						 TextMemo2->Text = TextMemo2->Text->Replace(">@Text<", "><");

						 break;

					 case 3:
						 // Include
						 if ( includeDone ) break;
						 for ( int i = 0; i < tabCount; i++ )
							 s += "\t";
						 str = s + p->Value + "\n";
						 str = str->Replace(Environment::NewLine, Environment::NewLine + s) + "\n" + s;
						 if ( TextMemo2->Text->Contains(str->Trim()) ) str = "";
						 includeDone = true;

						 break;
						 
					 case 4:
						 // Methods
						 for ( int i = 0; i < tabCount; i++ )
							 s += "\t";
						 str = s + p->Value;
						 str = str->Replace(Environment::NewLine, Environment::NewLine + s) + "\n\n" + s;

						 if ( prevMeth->Contains(str) ) // без этого костыля почему-то не работает
							 str = "";
						 else
							 prevMeth += str;

						 break;
						 */
					 case 5:
						 // Ui
						 for ( int i = 0; i < tabCount + 1; i++ )
							 s += "\t";
						 str = "\n\t\t" + s + p->Value;

						 if ( TextMemo2->Text->Contains(str) ) str = "";

						 if ( !TextMemo2->Text->Contains("<Question") ) break;
						 after = TextMemo2->Text->IndexOf(">", TextMemo2->Text->IndexOf("<Question")) + 1;

						 break;
					 case 6:
						 //PageUI
						 for ( int i = 0; i < tabCount + 1; i++ )
							 s += "\t";
						 str = "\n\t" + s + p->Value->Replace("PageUi", "Ui");
						 if ( TextMemo2->Text->Contains(str) ) str = "";

						 if ( !TextMemo2->Text->Contains("<Page") ) break;
						 after = TextMemo2->Text->IndexOf(">", TextMemo2->Text->IndexOf("<Page")) + 1;

						 break;
					 case 7: 
						 //AnswerUi
						 for ( int i = 0; i < tabCount + 1; i++ )
							 s += "\t";
						 str = "\n\t\t\t" + s + p->Value->Replace("AnswerUi", "Ui") + "\n";
						 if ( TextMemo2->Text->Contains(str) ) str = "";

						 if ( !TextMemo2->Text->Contains("<Answer") ) break;
						 after = TextMemo2->Text->IndexOf(">", TextMemo2->Text->IndexOf("<Answer")) + 1;

						 break;
				 }

				 if ( String::IsNullOrEmpty(str) && p->Key != "Include" )
				 {
					 ShowWarning("Невозможно добавить элемент.\n"
						 + "Возможно, элемент (" + p->Key + ") уже был добавлен.\n\n");
					 continue;
				 }

				 TextMemo2->Text = TextMemo2->Text->Insert(after, str);
				 TextMemo2->Text = TextMemo2->Text->Replace("***QID***", PageId->Text);
				 TextMemo2->Text = TextMemo2->Text->Replace( "***AC***", ( IsNumber(repeatName->Text) ? repeatName->Text : (dataGridView1->RowCount - 1).ToString() ) );
				 if ( CopyBuf->Checked ) CopyToBuffer(gcnew List<String^>(TextMemo2->Lines));
			 }
		 }


		 private: void AddFeature(System::Object^  sender, System::EventArgs^  e)
		 {
			 if ( QuestionTypes->SelectedIndex < 0 || !adQuestion->Checked && !checkBox3->Checked ) return;
			 addons->GetTags(gcnew List<String^>(gcnew array<String^> {"Specials"}));
			 if ( addons->Count < 1 ) return;

			 features->Items->Clear();
			 features->Items->Add("Дополнительные возможности");
			 features->SelectedIndex = 0;

			 addonTags->Clear();

			 addons->GetTags(gcnew List<String^>(gcnew array<String^> {"Specials", "Common"}));
			 addonTags->AddRange(addons->GetTagList());

			 if ( addons->Contains(QuestionTypes->SelectedItem->ToString()) )
			 {
				 addons->GetTags(gcnew List<String^>(gcnew array<String^> {"Specials", QuestionTypes->SelectedItem->ToString()}));
				 if ( addons->Count > 0 )
					 addonTags->AddRange(addons->GetTagList());
			 }

			 if ( ExtendTypes->SelectedIndex > 0 && checkBox3->Checked )
			 {
				 addons->GetTags(gcnew List<String^>(gcnew array<String^> {"Specials"}));

				 if ( addons->Contains(ExtendTypes->SelectedItem->ToString()) )
				 {
					 addons->GetTags(gcnew List<String^>(gcnew array<String^> {"Specials", ExtendTypes->SelectedItem->ToString()}));
					 if ( addons->Count > 0 )
						 addonTags->AddRange(addons->GetTagList());
				 }
			 }

			 for each (AddonTag^ t in addonTags)
			 {
				 features->Items->Add(t->Title);
			 }
		 }






		 void CreateXML(String^ ElementType)
		 {
			#pragma region переменные

			 int Count = dataGridView1->RowCount - 1;
			 Answers^ answers;
			 Items^ items;
			 // общие настройки
			 String ^parentIdText = GetQuestionId(QuestionHeader->Text);
			 String^ type;
			 //bool delSpaces;
			 //bool addTag;
			 List<String^>^ ids = gcnew List<String^>();
			 Dictionary<String^, List<String^>^>^ Atributes = gcnew Dictionary<String^, List<String^>^>(); // список атрибутов для Answer/Item


			 // Items/Answers
			 List<String^>^ texts;

			#pragma endregion

			type = ElementType->ToLower();

			#pragma region общие настройки
			
			int i = 0;

			int tabCount = StrToInt(tabs->SelectedItem->ToString());

			ids = ColumnToList(0);
			Atributes->Add("Id", ids);
			texts = ColumnToList(1);

			for ( i = 0; i < texts->Count; i++ )
			{
				texts[i] = ClearString(texts[i], true, false, true);
				if ( FirstUp->Checked ) texts[i] = RiseFirstLetter(texts[i]);
				if (CustomRepalce) texts[i] = CustomTemplates->Replace(texts[i]);
			}

			if ( FirstUp->Checked ) parentIdText = RiseFirstLetter(parentIdText);
						
			#pragma region проверка корректности

			WarningOccured = false;
			if ( CheckCorrect )
			{
				// проверка количества Var
				if ( Vars != nullptr )
				if ( radioItem->Checked && adVar->Checked && (Vars->Count != texts->Count) )
				{
					ShowWarning("Длины списков Var и Items отличаются!");
					WarningOccured = true;
				}
				
				// проверка символов текста
				CheckSyntaxResult^ er = gcnew CheckSyntaxResult();
				er = CheckSyntax(ColumnToList(1));
				if ( er->Count > 0 )
				{
					for ( i = 0; i < er->Count; i++ )
						dataGridView1->Rows[i]->Cells[1]->Value = er->NewLines[i];

					texts = gcnew List<String^>(ColumnToList(1));
					for ( int i = 0; i < texts->Count; i++)
					{
						texts[i] = ClearString(texts[i], true, false, IgnorSpaces);
					}
					if ( FirstUp->Checked )
						for ( i = 0; i < texts->Count; i++ )
							texts[i] = RiseFirstLetter(texts[i]);

					WarningOccured = true;
				}

				// проверка вопросов Union
				er = CheckSyntax(Questions);
				if ( er->Count > 0 )
					for ( i = 0; i < er->Count; i++ )
					{
						Questions[i] = er->NewLines[i];
						WarningOccured = true;
					}
				
				//проверка нумерации ID
				List<String^> ^strs = gcnew List<String^>(ColumnToList(0));
				for ( i = 0; i < strs->Count; i++ )
				{
					if ( strs->IndexOf(strs[i], i + 1) > -1 )
					{
						if ( MessageBox::Show("Найдены повторяющиеся Id\nОбновить нумерацию?", "",
							System::Windows::Forms::MessageBoxButtons::YesNo, System::Windows::Forms::MessageBoxIcon::Question) ==
							Forms::DialogResult::Yes
							)
						{
							ClearIds();
							NumerateId(true);
							ids->Clear();
							ids = gcnew List<String^>(ColumnToList(0));
							Atributes["Id"] = ids;
							break;
						}
						else break;
						WarningOccured = true;
					}
				}

				// проверка Question Header
				if ( adQuestion->Checked && QuestionHeader->Text != _QuestionHeader )
				{
					er = CheckSyntax(QuestionHeader->Text);
					if ( er->Count > 0 )
					{
						QuestionHeader->Text = er->NewLines[0];
						WarningOccured = true;
					}
				}

				// проверка Page ID
				if ( PageId->Text == _QuestionId )
					if ( adParent->Checked )
					{
						if (radioAnswer->Checked || radioBlock->Checked)
							ShowWarning("Заполните поле Id страницы!");
						else 
							ShowWarning("Заполните поле Id листа!");
						WarningOccured = true;
					}

				// проверка Repeat
				if ( adRepeat->Checked )
				{
					String ^Qtr = ImprovePropertyLanguage(repeatName->Text);
					if ( repeatName->Text != Qtr )
					{
						QuestionDialog::Result^ res = DontAsk["RepeatName"];
						if ( !DontAsk["RepeatName"]->CheckBoxChecked )
						{
							res = QuestionDialog::Show(
								"Поле повтора элементов содержит недопустимые символы\nЗаменить \"" + repeatName->Text + "\" на \"" + Qtr + "\"?",
								"Проверка корректности",
								QuestionDialog::Buttons::YesNo,
								true);
							DontAsk["RepeatName"] = res;
						}

						if ( res->DialogResult == QuestionDialog::Results::Yes )
						{
							repeatName->Text = Qtr;
							WarningOccured = true;
						}
					}

					er = CheckSyntax(repeatText->Text);
					if (er->Count > 0)
					{				
						QuestionDialog::Result^ res = DontAsk["RepeatName"];
						if ( !DontAsk["RepeatName"]->CheckBoxChecked )
						{
							res = QuestionDialog::Show(
								"Поле текста повтора элементов содержит недопустимые символы\nЗаменить \"" + repeatText->Text + "\" на \"" + er->NewLines[0] + "\"?",
								"Проверка корректности",
								QuestionDialog::Buttons::YesNo,
								true);
							DontAsk["RepeatName"] = res;
						}

						if ( res->DialogResult == QuestionDialog::Results::Yes )
						{
							repeatText->Text = er->NewLines[0];
							WarningOccured = true;
						}
					}
				}

				// проверка QuestionListId
				if ( CombineQuestions )
				{
					if ( QuestionListId != "" )
					{
						String ^Qtr = ImprovePropertyLanguage(QuestionListId);
						if ( QuestionListId != Qtr )
						{
							QuestionDialog::Result^ res = DontAsk["CombineQuestions"];
							if ( !DontAsk["CombineQuestions"]->CheckBoxChecked )
							{
								res = QuestionDialog::Show(
									"Id листа повтора вопросов содержит недопустмые символы.\nЗаменить \"" + QuestionListId + "\" на \"" + Qtr + "\"?",
									"Проверка корректности",
									QuestionDialog::Buttons::YesNo,
									true);
								DontAsk["CombineQuestions"] = res;
							}

							if ( res->DialogResult == QuestionDialog::Results::Yes )
							{
								er = CheckSyntax(QuestionListId);
								QuestionListId = Qtr;
								WarningOccured = true;
							}
						}
					}
					else
					{
						ShowWarning("Заполните поле Id листа вопросов!");
						WarningOccured = true;
					}
				}
			}
			#pragma endregion

			#pragma endregion
			
			#pragma region Items
			 if ( type == "item" )
			 {
				 CombineQuestions = false;
				 try
				 {
					 items = gcnew Items(Count);

					 items->TabCount = tabCount;
					 items->MissFirstTab = missFirst->Checked;
					 if ( PageId->Text != _QuestionId ) items->ParentId = PageId->Text;
					 items->AddParentTag = adParent->Checked;

					 items->AddAttributes(Atributes);

					 items->VarsEnabled = adVar->Checked;

					 if ( items->VarsEnabled )
						 items->AddVars(Vars, varSeparate);

					 items->AddText(texts, true, !DontClear, IgnorSpaces);

					 items->AddRepeat = adRepeat->Checked;
					 items->RepeatName = repeatName->Text;
					 items->RepeatText = repeatText->Text;

					 TextMemo2->Text = String::Join("\n", items->MakeXML()->ToArray());
				 }
				 catch ( Exception^ e )
				 {
					 ShowError(311, "Ошибка при формировании элементов Item\n\nПодробнее:\n"+e->ToString());
				 }
			 }
			#pragma endregion

			#pragma region Answers
			 if ( type == "answer" )
			 {
				 CombineQuestions = false;
				 try
				 {
					 String^ atrs = "";
					 String ^QType = (QuestionTypes->Enabled && QuestionTypes->SelectedIndex != -1) ? QuestionTypes->SelectedItem->ToString() : "";

					 // добавление единственного ответа
					 if ( !adRepeat->Checked && adQuestion->Checked && texts->Count == 0 && ids->Count == 0 )
					 {
						 texts->Add("");
						 ids->Add("1");
						 Atributes["Id"] = ids;
						 Count++;
					 }

					 answers = gcnew Answers(Count);

					 answers->AutoTags = !NoAutoTag;

					 answers->Combine = intoList->Checked;

					 answers->TabCount = tabCount;
					 answers->MissFirstTab = missFirst->Checked;

					 if ( PageId->Text != _QuestionId ) answers->ParentId = PageId->Text;
					 answers->AddPageTag = adParent->Checked;
					 if (pageHeader->Text != _PageHeader) answers->PageHeader = FirstUp->Checked ? RiseFirstLetter(pageHeader->Text) : pageHeader->Text;

					 if ( QuestionHeader->Text != _QuestionHeader ) answers->Header = (ClearHeader) ? ClearString(QuestionHeader->Text, true, true, false) : QuestionHeader->Text;
					 atrs += " Id=\"";
					 if ( !String::IsNullOrEmpty(parentIdText) ) atrs += parentIdText;
					 else
						 if ( PageId->Text != nullptr && !String::IsNullOrEmpty(PageId->Text) && PageId->Text != _QuestionId ) atrs += PageId->Text;
					 atrs += "\"";

					 if ( QType != "" ) atrs += " Type=\"" + QType + "\"";

					 if ( cMix->Checked ) atrs += " Mix=\"true\"";
					 else if ( cMixId->Checked ) atrs += " MixId=\"" + MixIdText->Text + "\"";

					 answers->ExtendAdd = checkBox3->Checked;

					 if ( checkBox3->Checked )
					 {
						 answers->Extend = ( (ExtendTypes->SelectedIndex > 0) ? (" Extend=\"" + ExtendTypes->SelectedItem->ToString()) + "\"" : "" )
						 + " " + ExtendString->Text;
					 }

					 answers->AddQuestionAttributes(atrs);
					 answers->AddParentTag = adQuestion->Checked; // порядок важен
					 answers->AddAttributes(Atributes);
					 answers->AddText(texts, true, !DontClear, IgnorSpaces);

					 answers->AddRepeat = adRepeat->Checked;
					 answers->RepeatName = repeatName->Text;
					 answers->RepeatText = repeatText->Text;

					 TextMemo2->Text = String::Join("\n", answers->MakeXML()->ToArray());
				 }
				 catch ( Exception^ e )
				 {
					 ShowError(312, "Ошибка при формировании элементов Answer\n\nПодробнее:\n" + e->ToString());
				 }
			 }
			#pragma endregion

			#pragma region Union
			 if ( type == "union" )
			 {
				 try
				 {
					 String ^QType = (QuestionTypes->Enabled && QuestionTypes->SelectedIndex != -1) ? QuestionTypes->SelectedItem->ToString() : "";
					 Union^ uni = gcnew Union();
					 String^ atrs;
					 uni->AutoTags = !NoAutoTag;

					 uni->UnionMixIdText = unionMixIdText;
					 uni->MixIdText = MixIdText->Text;

					 if ( cMix->Checked ) mix = MixType::Mix;
					 else if ( cMixId->Checked ) mix = MixType::MixId;
					 else mix = MixType::None;

					 uni->mix = mix;
					 uni->unionMix = unionMix;

					 uni->AddQuestions(Questions, CombineQuestions);
					 uni->AddAnswers(texts, Atributes["Id"], adParent->Checked);
					 uni->QuestionListId = QuestionListId;
					 uni->QuestionId = GetQuestionId(QuestionHeader->Text);
					 uni->QuestionType = QType;
					 uni->TextSeparate = true;
					 uni->DummyExtend = checkBox3->Checked;
					 uni->IgnoreSpases = IgnorSpaces;
					 uni->DontClear = DontClear;
					 if ( pageHeader->Text != _PageHeader ) uni->PageHeader = pageHeader->Text;
					 if ( checkBox3->Checked )
					 {
						 uni->Extend = ((ExtendTypes->SelectedIndex > 0) ? (" Extend=\"" + ExtendTypes->SelectedItem->ToString()) + "\"" : "")
							 + " " + ExtendString->Text;
					 }

					 if ( PageId->Text != nullptr && PageId->Text != _QuestionId ) uni->AnswerListId = PageId->Text;
					 if ( QuestionHeader->Text != _QuestionHeader ) uni->DummyHeader = (ClearHeader) ? ClearString(QuestionHeader->Text, true, true, false) : QuestionHeader->Text;
					 if ( QuestionTypes->Enabled && QuestionTypes->SelectedIndex != -1 )  atrs = " Type=\"" + QuestionTypes->SelectedItem->ToString() + "\"";

					 uni->DummyAtributes = atrs;
					 uni->TabCount = tabCount;
					 uni->MissFirstTab = missFirst->Checked;

					 uni->AddRepeat = adRepeat->Checked;
					 uni->RepeatName = repeatName->Text;
					 uni->RepeatText = repeatText->Text;

					 TextMemo2->Text = String::Join("\n", uni->MakeXML()->ToArray());
				 }
				 catch ( Exception^ e )
				 {
					 ShowError(313, "Ошибка при формировании элементов Union\n\nПодробнее:\n" + e->ToString());
				 }
			 }
			#pragma endregion

			#pragma region Block
			 if ( type == "block" )
			 {
				 CombineQuestions = true;
				 try
				 {
					 String^ atrs = "";
					 String ^QType = (QuestionTypes->Enabled && QuestionTypes->SelectedIndex != -1) ? QuestionTypes->SelectedItem->ToString() : "";

					 // добавление единственного ответа
					 if ( Count == 0 && !adRepeat->Checked )
					 {
						 texts->Add("");
						 ids->Add("1");
						 Atributes["Id"] = ids;
						 Count++;
					 }

					 QuestionBlock^ block = gcnew QuestionBlock(Count);

					 if ( PageId->Text != nullptr && PageId->Text != _QuestionId ) block->QuestionId += PageId->Text;
					 else
						 if ( !String::IsNullOrEmpty(parentIdText) ) block->QuestionId = parentIdText;

					 // Answers

					 block->AnswerBlock->AutoTags = !NoAutoTag;
					 block->TabCount = tabCount;
					 block->MissFirstTab = missFirst->Checked;
					 if ( PageId->Text != _QuestionId ) block->AnswerBlock->ParentId = PageId->Text;
					 block->AnswerBlock->AddPageTag = adParent->Checked;
					 if ( pageHeader->Text != _PageHeader )
					 {
						 String^ tmp = ClearHeader ? ClearString(pageHeader->Text, true, true, false) : pageHeader->Text;
						 block->AnswerBlock->PageHeader = FirstUp->Checked ? RiseFirstLetter(tmp) : tmp;
					 }
					 if ( QType != "" ) atrs += " Type=\"" + QType + "\"";

					 if ( cMix->Checked ) atrs += " Mix=\"true\"";
					 else if ( cMixId->Checked ) atrs += " MixId=\"" + MixIdText->Text + "\"";
					 block->AnswerBlock->ExtendAdd = checkBox3->Checked;
					 if ( checkBox3->Checked )
					 {
						 block->AnswerBlock->Extend = ((ExtendTypes->SelectedIndex > 0) ? (" Extend=\"" + ExtendTypes->SelectedItem->ToString()) + "\"" : "")
							 + " " + ExtendString->Text;
					 }
					 block->AnswerBlock->AddParentTag = true;
					 block->AnswerBlock->AddText(texts, true, !DontClear, IgnorSpaces);
					 block->AnswerBlock->AddRepeat = adRepeat->Checked;
					 block->AnswerBlock->RepeatName = repeatName->Text;
					 block->AnswerBlock->RepeatText = repeatText->Text;

					 // Questions

					 block->QuestionListId = QuestionListId;
					 block->UnionMix = unionMix;
					 block->UnionMixIdText = unionMixIdText;


					 block->AnswerBlock->AddAttributes(Atributes);
					 block->AddQuestionAttributes(atrs);
					 block->AddQuestions(Questions, true, !DontClear, IgnorSpaces);

					 TextMemo2->Text = String::Join("\n", block->MakeXML()->ToArray());
				 }
				 catch ( Exception^ e )
				 {
					 ShowError(334, "Ошибка при формировании элементов Block\n\nПодробнее:\n" + e->ToString());
				 }
			 }

			#pragma endregion

		 }


		



#pragma endregion

		 
	// разбивка строк, сохранение номера
	System::Void WrapCells(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e)
	{
		// возможность нажать на меню
		sortId->Enabled = dataGridView1->RowCount > 2;
		sortText->Enabled = sortId->Enabled;

		if ( (e->RowIndex < 0) || CurrentAction )	return;
		
		// сохранение номера
		if ( e->ColumnIndex == 0 )
		{
			if ( IsNumber(dataGridView1->Rows[e->RowIndex]->Cells[0]->Value->ToString()) )
				dataGridView1->Rows[e->RowIndex]->Cells[2]->Value = dataGridView1->Rows[e->RowIndex]->Cells[0]->Value;
		}

		if ( e->ColumnIndex > 1 ) return;

		String^ restStr = Convert::ToString(dataGridView1->CurrentCell->Value);
		
		// разбивка строк
		#pragma region выбор разделителя
		String^ separator = Environment::NewLine;
		if ( CountSubStrings(restStr, "\t") > 2 && !restStr->Contains(separator) )
			separator = "\t";
		
		if ( separator == "\t" ) restStr = restStr->Replace("\n", "");
		
		int nPos = restStr->IndexOf(separator);
		if ( (nPos <= 0) )
		{
			NumerateId(false);
			return;
		}

		#pragma endregion

		int CurrentColumn = dataGridView1->CurrentCell->ColumnIndex,
			CurrentRow = dataGridView1->CurrentCell->RowIndex;

		try
		{
			#pragma region Создание листа
			int i = 1;
			String^ newStr;
			DataGridViewTextBoxCell^ c1, ^c2, ^c3;
			DataGridViewRow^ r;
			List<DataGridViewRow^>^ rows = gcnew List<DataGridViewRow^>();
			while ( nPos > -1 )
			{
				newStr = restStr->Remove(nPos);
				//ShowMessage(newStr);
				c1 = gcnew DataGridViewTextBoxCell();
				c2 = gcnew DataGridViewTextBoxCell();
				c3 = gcnew DataGridViewTextBoxCell();
				r = gcnew DataGridViewRow();
				c1->Value = "-1";
				c2->Value = newStr;
				r->Cells->Add(c1);
				r->Cells->Add(c2);
				r->Cells->Add(c3);
				rows->Add(r);
				restStr = restStr->Remove(0, nPos + 1)->Trim();
				nPos = restStr->IndexOf(separator);
				i++;
			}
			
			// добавление последнего
			if ( !String::IsNullOrEmpty(restStr) && restStr->Length > 1 )
			{
				r = gcnew DataGridViewRow();
				c1 = gcnew DataGridViewTextBoxCell();
				c2 = gcnew DataGridViewTextBoxCell();
				c3 = gcnew DataGridViewTextBoxCell();
				c1->Value = "-1";
				c2->Value = restStr;
				r->Cells->Add(c1);
				r->Cells->Add(c2);
				r->Cells->Add(c3);
				rows->Add(r);
			}

			#pragma endregion
			
			CurrentAction = true;

			#pragma region вывод

			bool reWrite = false;
			// вставка/перезапись
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
					else reWrite = (res == Forms::DialogResult::Yes);
					break;
				}

			// цикл добавления
			if ( reWrite )
			{
				int a = Min(rows->Count, dataGridView1->Rows->Count - CurrentRow - 1);
				for ( int i = 0; i < a; i++ )
				{
					if ( dataGridView1->Rows[CurrentRow] != nullptr ) dataGridView1->Rows->RemoveAt(CurrentRow);
				}
					
				dataGridView1->Rows->InsertRange(CurrentRow, rows->ToArray());
			}				
			else
			{
				dataGridView1->Rows->RemoveAt(CurrentRow);
				dataGridView1->Rows->InsertRange(CurrentRow, rows->ToArray());
 					
			}
				
			#pragma endregion

			CurrentAction = false;

		}
		catch ( Exception^ e )
		{
			ShowError(314, "Ошибка при разделении текста на строки\n\nПодробнее:\n" + e->ToString());
		}

		NumerateId(false);
	}


	// обновить (кнопка)
	private: System::Void RefreshButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		EndUserEdit();

		if ( radioAnswer->Checked && PageId->Text->ToLower()->Contains("list") && MessageBox::Show("Возможно, вместо Answers нужно сгенерировать Items?", "", Forms::MessageBoxButtons::YesNo, Forms::MessageBoxIcon::Question) == Forms::DialogResult::Yes )
			radioItem->Checked = true;

		bool answerTextDone = false;
		bool uiDone = false;
		bool customText2Done = false;
		bool methodsDone = false;
		Generated = true;
		prevCustText = "";
		prevAnsText = "";
		prevMeth = "";

		String^ type;

		array<bool>^ vals = {radioItem->Checked, radioAnswer->Checked, radioUnion->Checked, radioBlock->Checked};
		array<String^>^ tps = {"Item", "Answer", "Union", "Block"};
		
		for (int i = 0; i < vals->Length; i++)
			if (vals[i])
			{
				type = tps[i];
				break;
			}

		CreateXML(type);

		// добавление фильтра
		if ( !NoAutoTag && adParent->Checked && PageId->Text->ToLower() == "respinfo" ) AddFalseFilter();

		// добавление Ui Isolate
		if ( !NoAutoTag && Isolate->Checked && radioAnswer->Checked && ExtendTypes->SelectedItem->ToString() != "Scale" && !(gcnew String("Memo Text Integer Number"))->Contains(QuestionTypes->SelectedItem->ToString())) MakeIsolate();

		// добавление отступа
		if ( spaceCount->SelectedIndex > -1) TextMemo2->Text = gcnew String('\n', spaceCount->SelectedIndex) + TextMemo2->Text;

		// сохранение списка листов
		UpdateLists();

		if (CopyBuf->Checked) CopyToBuffer(gcnew List<String^>(TextMemo2->Lines));

		// Очистка
		if ( ClearAtOnce && !WarningOccured )
		{
			CurrentAction = true;
			dataGridView1->Rows->Clear();
			CurrentAction = false;
			Generated = false;
		}

		StartUserEdit();

		if ( MinimizeAfter ) this->WindowState = FormWindowState::Minimized;

	}


	// очистка
	private: System::Void ClearButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		CurrentAction = true;
		dataGridView1->Rows->Clear();
		TextMemo2->Clear();
		Generated = false;
		CurrentAction = false;
		if ( minimized ) button2->PerformClick();
		Unionform->Clear();
		VForm->Clear();
		adVar->Checked = false;
		prevCustText = "";
		prevAnsText = "";
		prevMeth = "";
		pageHeader->Text = _PageHeader;
		QuestionHeader->Text = _QuestionHeader;
		PageId->Text = _QuestionId;
		QIDManualChanged = false;
		PHChanged = false;

		if ( ReturnBack ) Defaults->SetAll();
		dataGridView1->Focus();
	}


	// форма добавления Var
	private: System::Void VarButton_Click(System::Object^  sender, System::EventArgs^  e)
	{
		try
		{
			VForm->ShowDialog();
			Vars = gcnew List<List<String^>^>(VForm->vars);
			varSeparate = VForm->checkBox1->Checked;
		}
		catch ( Exception^ e )
		{
			ShowError(315, "Ошибка при добавлении списка Var\n\nПодробнее:\n" + e->ToString());
		}
		if ( !NoDynamic && Generated ) RefreshButton->PerformClick();
	}


	// обработка неправильных данных
	private: System::Void dataGridView1_DataError(System::Object^  sender, System::Windows::Forms::DataGridViewDataErrorEventArgs^  e)
	{
		if ( dataGridView1->CurrentCell->ColumnIndex == 0 )
		{
			dataGridView1->Columns[0]->ValueType = Type::GetType("System.String");
			EndUserEdit();
			dataGridView1->CurrentCell->Value = "0";
			dataGridView1->Columns[0]->ValueType = Type::GetType("System.Int32");
			StartUserEdit();
		}
		else
		{
			dataGridView1->CurrentCell->Value = "";
			EndUserEdit();
		}
		
		StartUserEdit();
		ShowWarning("Ошибка ввода данных.\nОбратите внимание, что стобец Id может содержать только числовые символы.\n\n\nПодробнее:\n"+e->Exception->ToString());
	}


	// получение настроек для Union
	private: System::Void SetUnion_Click(System::Object^  sender, System::EventArgs^  e)
	{
		//try
		{
			if ( GetPageId->Checked && PageId->Text != _QuestionId ) Unionform->QId->Text = PageId->Text->Replace("_AList", "");
			Unionform->Text = radioUnion->Checked ? "Настройки для Union" : "Настройки для блока вопросов";
			Unionform->QId->Enabled = radioUnion->Checked;
			Unionform->label4->Enabled = radioUnion->Checked;
			Unionform->ShowDialog();
			Questions = gcnew List<String^>(Unionform->QList);

			QuestionListId = Unionform->ListIdBox->Text;
			CombineQuestions = Unionform->ToList->Checked;
			//UnionQuestionType = Unionform->comboBox1->SelectedItem->ToString();
			
			if ( Unionform->cUnionMix->Checked ) unionMix = UnionMixType::UnionMix;
			else if ( Unionform->cUnionMixId->Checked ) unionMix = UnionMixType::UnionMixId;
			else unionMix = UnionMixType::UnionNone;

			unionMixIdText = Unionform->UnionMixIdText->Text;
			MixIdText->Text = MixIdText->Text;
		}
		/*catch ( Exception^ e )
		{
			ShowError(316, "Ошибка при создании элементов Union\n\nПодробнее:\n" + e->ToString());
		}*/
		if ( !NoDynamic && Generated ) RefreshButton->PerformClick();
	}


	//загрузка настроек
	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^  e)
	{
		Settings^ settings = gcnew Settings();
		//if ( !settings->Exist("MainForm") ) return;

		if ( settings->Read("MainForm") > 0 )
		{
			try
			{
				this->Height = settings->Get("Height", true);
				this->Width = settings->Get("Width", true);
				this->DesktopLocation = Point(settings->Get("Left", true), settings->Get("Top", true));
				this->WindowState = (Forms::FormWindowState)settings->Get("State", true);
				FirstUp->Checked = settings->Get("FirstLetterUp", true);
				Defaults->Add(FirstUp, FirstUp->Checked);
				CopyBuf->Checked = settings->Get("CopyToClipboard", true);
				Defaults->Add(CopyBuf, CopyBuf->Checked);
				GetPageId->Checked = settings->Get("GetPageId", true);
				Defaults->Add(GetPageId, GetPageId->Checked);
				adQuestion->Checked = settings->Get("AddQuestionTag", true);
				Defaults->Add(adQuestion, adQuestion->Checked);
				adParent->Checked = settings->Get("AddPageTag", true);
				Defaults->Add(adParent, adParent->Checked);
				tabs->SelectedIndex = settings->Get("TabCountIndex", true);
				Defaults->Add(tabs, tabs->SelectedIndex);
				missFirst->Checked = settings->Get("MissFirstTab", true);
				Defaults->Add(missFirst, missFirst->Checked);
				/*SepText->Checked = settings->Get("TextSeparate", true);
				Defaults->Add(SepText, SepText->Checked);*/
				spaceCount->SelectedIndex = settings->Get("NewLineCount", true);
				Defaults->Add(spaceCount, spaceCount->SelectedIndex);
				Isolate->Checked = settings->Get("Isolate", true);

				Defaults->Add(Isolate, Isolate->Checked);

				TextAlwaysSep = settings->Get("TextAlwaysSeparate", true);
				/*if ( TextAlwaysSep )
				{
					SepText->Checked = true;
					SepText->Enabled = false;
				}
				else SepText->Enabled = true;*/
				CheckCorrect = settings->Get("SyntaxCheck", true);
				ClearHeader = settings->Get("ClearHeader", true);
				DontClear = settings->Get("DontClearText", true);
				IgnorSpaces = settings->Get("IgnorSpaces", true);
				ClearAtOnce = settings->Get("ClearAtOnce", true);
				DontUpdate = settings->Get("DontUpdate", true);
				NoDynamic = settings->Get("NoDynamic", true);
				ReturnBack = settings->Get("Return", true);
				MinimizeAfter = settings->Get("Minimize", true);
				CustomRepalce = settings->Get("CustomRepalce", true);
				NoAutoTag = settings->Get("NoAutoTag", true);

				Defaults->Add(adRepeat, false);
			}
			catch ( Exception^ e )
			{
				ShowWarning("Ошибка загрузки настроек");
			}
		}
		Unionform = gcnew UnionQuestions(IgnorSpaces);
		this->QuestionTypes->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::AddFeature);
		this->ExtendTypes->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::AddFeature);
		this->adQuestion->CheckStateChanged += gcnew System::EventHandler(this, &MainForm::AddFeature);
		this->checkBox3->CheckStateChanged += gcnew System::EventHandler(this, &MainForm::AddFeature);
		this->AddFeature(this, nullptr);
		this->repeatName->AutoCompleteCustomSource = lists;
		this->PageId->AutoCompleteCustomSource = lists;
		Unionform->ListIdBox->AutoCompleteCustomSource = lists;
		lists->AddRange(gcnew array<String^>
		{
			"cityList",
			"brandList",
			"conceptList",
			"regionList",
			"strataList",
			"ageList",
			"sexList",
			"quotaList",
			"priceList",
			"estimList",
			"phraseList",
			"propertyList"
			"productList",
			"categoryList",
			"blockList",
			"typeList",
			"selList",
			"problemList",
			"profList"
		});
		CustomTemplates = CustomTemplates::Get()->SelectActive();
	}


	// закрытие формы и сохранение настроек
	private: System::Void MainForm_FormClosed(System::Object^  sender, System::Windows::Forms::FormClosedEventArgs^  e)
	{
		Settings^ settings = gcnew Settings();
		/*bool updateCustomReplace = false;
		settings->Read("MainForm");
		updateCustomReplace = settings->Get("UpdateReplaceFile", true);
		settings = gcnew Settings();
		settings->Set("UpdateReplaceFile", updateCustomReplace);*/

		if ( this->Height > 300 ) settings->Set("Height", this->Height);
		if ( this->Width > 500 ) settings->Set("Width", this->Width);
		if ( this->WindowState != Forms::FormWindowState::Minimized )
		{
			settings->Set("Left", this->DesktopLocation.X);
			settings->Set("Top", this->DesktopLocation.Y);
		}
		if ( this->WindowState == Forms::FormWindowState::Maximized ) settings->Set("State", 2); else settings->Set("State", 0);
		settings->Set("FirstLetterUp", FirstUp->Checked);
		settings->Set("CopyToClipboard", CopyBuf->Checked);
		settings->Set("AddQuestionTag", adQuestion->Checked);
		settings->Set("AddPageTag", adParent->Checked);
		settings->Set("GetPageId", GetPageId->Checked);
		settings->Set("TabCountIndex", tabs->SelectedIndex);
		settings->Set("MissFirstTab", missFirst->Checked);
		settings->Set("TextAlwaysSeparate", TextAlwaysSep);
		//settings->Set("TextSeparate", SepText->Checked);
		settings->Set("SyntaxCheck", CheckCorrect);
		settings->Set("ClearHeader", ClearHeader);
		settings->Set("DontClearText", DontClear);
		settings->Set("IgnorSpaces", IgnorSpaces);
		settings->Set("ClearAtOnce", ClearAtOnce);
		settings->Set("DontUpdate", DontUpdate);
		settings->Set("NoDynamic", NoDynamic);
		settings->Set("NewLineCount", spaceCount->SelectedIndex);
		settings->Set("Return", ReturnBack);
		settings->Set("Minimize", MinimizeAfter);
		settings->Set("Isolate", Isolate->Checked);
		settings->Set("CustomRepalce", CustomRepalce);
		settings->Set("NoAutoTag", NoAutoTag);

		if ( !settings->Save("MainForm") ) ShowWarning("Ошибка. Настройки не были сохранены.");

		Application::Exit();
	}


	private: System::Void features_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
	{
		if ( features->SelectedIndex < 1 ) return;
		PlaceAddon(addonTags[features->SelectedIndex - 1]);
		features->SelectedIndex = 0;
	}


	// сортировка вместе с Var
	private: System::Void dataGridView1_ColumnHeaderMouseClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellMouseEventArgs^  e)
	{
		for ( int i = 0; i < dataGridView1->RowCount; i++ )
			if ( !!dataGridView1->Rows[i]->Cells[0]->Value )
				dataGridView1->Rows[i]->Cells[3]->Value = i;
		
		SortOrder GlOrd = dataGridView1->Columns[e->ColumnIndex]->HeaderCell->SortGlyphDirection;
		if ( GlOrd == SortOrder::None ) GlOrd = SortOrder::Descending;
		ListSortDirection dir = ListSortDirection::Ascending;

		if ( GlOrd == SortOrder::Ascending )
		{
			GlOrd = SortOrder::Descending;
			dir = ListSortDirection::Descending;
		}
		else
			GlOrd = SortOrder::Ascending;

		dataGridView1->Sort(dataGridView1->Columns[e->ColumnIndex], dir);
		dataGridView1->Columns[e->ColumnIndex]->HeaderCell->SortGlyphDirection = GlOrd;
				
		if ( !radioItem->Checked || VForm->dataGridView1->RowCount < 3 )  return;
		if ( VForm->dataGridView1->RowCount != dataGridView1->RowCount )
		{
			ShowWarning("Сортировка Var не может быть выполнена, поскольку их колчество не соответствует количеству элементов");
			return;
		}
		
		int newCol = VForm->dataGridView1->Columns->Add(gcnew DataGridViewColumn(VForm->dataGridView1->Rows[0]->Cells[0]));
		VForm->dataGridView1->Columns[newCol]->ValueType = Type::GetType("System.Int32");
		for ( int i = 0; i < dataGridView1->RowCount; i++ )
			if ( dataGridView1->Rows[i]->Cells[3]->Value )
				VForm->dataGridView1->Rows[(int)dataGridView1->Rows[i]->Cells[3]->Value]->Cells[newCol]->Value = i;
				
		VForm->dataGridView1->Sort(VForm->dataGridView1->Columns[newCol], ListSortDirection::Ascending);
		
		VForm->dataGridView1->Columns->RemoveAt(newCol);
		VForm->saveVars();
		Vars = gcnew List<List<String^>^>(VForm->vars);
	}

	private: System::Void сообщитьОбОшибкеToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		OpenUrl("https://github.com/DifficultNick/SurveyHelper/issues", false);
	}

	private: System::Void синтаксисSPSSБазыToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (spssForm->IsDisposed) spssForm = gcnew PilotSyntax();
		spssForm->Show();
		spssForm->Activate();
	}
};

