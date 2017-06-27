#pragma once
#include "Classes.h"


using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;




namespace QuestionDialog
{
	public enum Results { Yes, No, Cancel };
	public enum Buttons { None, YesNo, YesNoCancel };
	
	public ref struct Result
	{
	public:
		Result()
		{
		}

		bool CheckBoxChecked;
		QuestionDialog::Results DialogResult;
	};

}






public ref class QuestionDialogWindow: public System::Windows::Forms::Form
{
public:
	QuestionDialogWindow()
	{
		InitializeComponent();
	}

public:


	QuestionDialog::Results res;

protected:
	~QuestionDialogWindow()
	{
		if ( components )
		{
			delete components;
		}
	}
public: 
	System::Windows::Forms::Button^  button1;
	System::Windows::Forms::Button^  button2;
	System::Windows::Forms::CheckBox^  checkBox1;
	System::Windows::Forms::Label^  label1;
	System::Windows::Forms::Button^  button3;

private:

	System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

	void InitializeComponent(void)
	{
		this->button1 = (gcnew System::Windows::Forms::Button());
		this->button2 = (gcnew System::Windows::Forms::Button());
		this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
		this->label1 = (gcnew System::Windows::Forms::Label());
		this->button3 = (gcnew System::Windows::Forms::Button());
		this->SuspendLayout();
		// 
		// button1
		// 
		this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->button1->Location = System::Drawing::Point(316, 16);
		this->button1->Name = L"button1";
		this->button1->Size = System::Drawing::Size(75, 28);
		this->button1->TabIndex = 0;
		this->button1->Text = L"Да";
		this->button1->UseVisualStyleBackColor = true;
		this->button1->Click += gcnew System::EventHandler(this, &QuestionDialogWindow::button1_Click);
		// 
		// button2
		// 
		this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->button2->Location = System::Drawing::Point(316, 50);
		this->button2->Name = L"button2";
		this->button2->Size = System::Drawing::Size(75, 29);
		this->button2->TabIndex = 1;
		this->button2->Text = L"Нет";
		this->button2->UseVisualStyleBackColor = true;
		this->button2->Click += gcnew System::EventHandler(this, &QuestionDialogWindow::button2_Click);
		// 
		// checkBox1
		// 
		this->checkBox1->AutoSize = true;
		this->checkBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->checkBox1->Location = System::Drawing::Point(21, 116);
		this->checkBox1->Name = L"checkBox1";
		this->checkBox1->Size = System::Drawing::Size(162, 19);
		this->checkBox1->TabIndex = 2;
		this->checkBox1->Text = L"Больше не спрашивать";
		this->checkBox1->UseVisualStyleBackColor = true;
		// 
		// label1
		// 
		this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->label1->Location = System::Drawing::Point(18, 23);
		this->label1->Name = L"label1";
		this->label1->Size = System::Drawing::Size(292, 81);
		this->label1->TabIndex = 3;
		// 
		// button3
		// 
		this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			static_cast<System::Byte>(204)));
		this->button3->Location = System::Drawing::Point(316, 85);
		this->button3->Name = L"button3";
		this->button3->Size = System::Drawing::Size(75, 29);
		this->button3->TabIndex = 4;
		this->button3->Text = L"Отмена";
		this->button3->UseVisualStyleBackColor = true;
		this->button3->Click += gcnew System::EventHandler(this, &QuestionDialogWindow::button3_Click);
		// 
		// QuestionDialogWindow
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->AutoSize = true;
		this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
		this->ClientSize = System::Drawing::Size(395, 141);
		this->ControlBox = false;
		this->Controls->Add(this->button3);
		this->Controls->Add(this->label1);
		this->Controls->Add(this->checkBox1);
		this->Controls->Add(this->button2);
		this->Controls->Add(this->button1);
		this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
		this->Name = L"QuestionDialogWindow";
		this->ShowIcon = false;
		this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
		this->ResumeLayout(false);
		this->PerformLayout();

	}
#pragma endregion

	public: void button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		res = QuestionDialog::Results::Yes;
		this->Hide();
	}

	public: void button2_Click(System::Object^  sender, System::EventArgs^  e)
	{
		res = QuestionDialog::Results::No;
		this->Hide();
	}
			

	public: void button3_Click(System::Object^  sender, System::EventArgs^  e)
	{
		res = QuestionDialog::Results::Cancel;
		this->Hide();
	}
};








namespace QuestionDialog
{

	static Result^ Show(String^ text, String^ caption, Buttons buttons, bool showCheckBox)
	{
		QuestionDialogWindow^ d = gcnew QuestionDialogWindow();
		Result^ res = gcnew Result();
		d->checkBox1->Visible = showCheckBox;
		d->label1->Text = text;
		d->Text = caption;
		d->button1->Visible = buttons > 0;
		d->button2->Visible = buttons > 0;
		d->button3->Visible = buttons > 1;
		d->ShowDialog();
		res->CheckBoxChecked = d->checkBox1->Checked;
		res->DialogResult = d->res;
		d->Close();
		return res;
	}

}
