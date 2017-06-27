#pragma once

#include "Funuctions.h"

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class SliderType : public System::Windows::Forms::Form
	{
	public:
		SliderType(void)
		{
			InitializeComponent();

		}

	protected:

		~SliderType()
		{
			if (components)
			{
				delete components;
			}
		}


#pragma region Windows Form Designer generated code
	private: 
		System::Windows::Forms::GroupBox^  groupBox1;
		System::Windows::Forms::RadioButton^  Contin;
		System::Windows::Forms::RadioButton^  Discr;
		System::Windows::Forms::Button^  button1;
		System::ComponentModel::Container ^components;

		void InitializeComponent(void)
		{
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->Contin = (gcnew System::Windows::Forms::RadioButton());
			this->Discr = (gcnew System::Windows::Forms::RadioButton());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox1->SuspendLayout();
			this->SuspendLayout();
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->Contin);
			this->groupBox1->Controls->Add(this->Discr);
			this->groupBox1->Location = System::Drawing::Point(12, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(128, 82);
			this->groupBox1->TabIndex = 0;
			this->groupBox1->TabStop = false;
			// 
			// Contin
			// 
			this->Contin->AutoSize = true;
			this->Contin->Location = System::Drawing::Point(19, 51);
			this->Contin->Name = L"Contin";
			this->Contin->Size = System::Drawing::Size(97, 17);
			this->Contin->TabIndex = 1;
			this->Contin->Text = L"Непрерывный";
			this->Contin->UseVisualStyleBackColor = true;
			// 
			// Discr
			// 
			this->Discr->AutoSize = true;
			this->Discr->Checked = true;
			this->Discr->Location = System::Drawing::Point(19, 19);
			this->Discr->Name = L"Discr";
			this->Discr->Size = System::Drawing::Size(89, 17);
			this->Discr->TabIndex = 0;
			this->Discr->TabStop = true;
			this->Discr->Text = L"Дискретный";
			this->Discr->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(169, 43);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(84, 27);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Готово";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &SliderType::button1_Click);
			// 
			// SliderType
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(289, 122);
			this->ControlBox = false;
			this->Controls->Add(this->button1);
			this->Controls->Add(this->groupBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"SliderType";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Выберите тип для Slider";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion


	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->Hide();
	}

	
	public: String^ GetString()
	{
		return "Slider_" + (Discr->Checked ? "Discrete" : "Continuous");
	}
};





public ref class Slider
{
public:
	Slider::Slider()
	{
	}

	Slider::~Slider()
	{
	}

	static String^ Get()
	{
		try
		{
			SliderType^ form = gcnew SliderType();
			form->ShowDialog();
			return form->GetString();
		}
		catch ( Exception^ e )
		{
			ShowError(333, "Ошибка формирования строки SliderType");
			return "";
		}

	}

};