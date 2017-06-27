#pragma once

#include "Funuctions.h"

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class DragItemTypeChooser : public System::Windows::Forms::Form
	{
	public:
		DragItemTypeChooser(void)
		{
			InitializeComponent();
			DragItemTypes->SelectedIndex = 0;
		}

	protected:
		~DragItemTypeChooser()
		{
			if (components)
			{
				delete components;
			}
		}


#pragma region Windows Form Designer generated code

	public:
		System::Windows::Forms::ComboBox^  DragItemTypes;
	private:
		System::Windows::Forms::Button^  button1;
		System::ComponentModel::Container ^components;

		void InitializeComponent(void)
		{
			this->DragItemTypes = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// DragItemTypes
			// 
			this->DragItemTypes->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->DragItemTypes->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->DragItemTypes->FormattingEnabled = true;
			this->DragItemTypes->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Card", L"Range" });
			this->DragItemTypes->Location = System::Drawing::Point(12, 25);
			this->DragItemTypes->Name = L"DragItemTypes";
			this->DragItemTypes->Size = System::Drawing::Size(121, 23);
			this->DragItemTypes->TabIndex = 0;
			this->DragItemTypes->SelectedIndexChanged += gcnew System::EventHandler(this, &DragItemTypeChooser::DragItemTypes_SelectedIndexChanged);
			// 
			// button1
			// 
			this->button1->Enabled = false;
			this->button1->Location = System::Drawing::Point(159, 25);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(89, 24);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Готово";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &DragItemTypeChooser::button1_Click);
			// 
			// DragItemTypeChooser
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(271, 191);
			this->ControlBox = false;
			this->Controls->Add(this->button1);
			this->Controls->Add(this->DragItemTypes);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"DragItemTypeChooser";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Выберите Type для DragItem";
			this->ResumeLayout(false);

		}
#pragma endregion
	
	
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		this->Hide();
	}


	public: String^ GetString()
	{
		return "DragItem_" + DragItemTypes->SelectedItem->ToString();
	}


	private: System::Void DragItemTypes_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
	{
		button1->Enabled = DragItemTypes->SelectedIndex != -1;
	}
};



	public ref class DragItem
	{
	public:
		DragItem::DragItem()
		{
		}

		DragItem::~DragItem()
		{
		}

		static String^ Get()
		{
			try
			{
				DragItemTypeChooser^ form = gcnew DragItemTypeChooser();
				form->ShowDialog();
				return form->GetString();
			}
			catch ( Exception^ e )
			{
				ShowError(301, "Ошибка формирования строки DragItemType");
			}
			return "";
		}

	};

	
