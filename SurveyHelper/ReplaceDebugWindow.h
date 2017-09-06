#pragma once

#include "Funuctions.h"
#include "Classes.h"


	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace CustomTemplates;

	public ref class ReplaceDebugWindow : public System::Windows::Forms::Form
	{
	public:
		ReplaceDebugWindow(CustomTemplateList^ Templates)
		{
			InitializeComponent();
			templates = Templates;
		}

	protected:
		~ReplaceDebugWindow()
		{
			if (components)
			{
				delete components;
			}
		}

		CustomTemplateList^ templates = gcnew CustomTemplateList();

	private:
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::RichTextBox^  result;
	private: System::Windows::Forms::Button^  Debug;
	private: System::Windows::Forms::Button^  clear;
	private: System::Windows::Forms::RichTextBox^  source;

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(ReplaceDebugWindow::typeid));
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->result = (gcnew System::Windows::Forms::RichTextBox());
			this->Debug = (gcnew System::Windows::Forms::Button());
			this->clear = (gcnew System::Windows::Forms::Button());
			this->source = (gcnew System::Windows::Forms::RichTextBox());
			this->tableLayoutPanel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->result, 1, 1);
			this->tableLayoutPanel1->Controls->Add(this->Debug, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->clear, 1, 0);
			this->tableLayoutPanel1->Controls->Add(this->source, 0, 1);
			this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel1->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 2;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 32)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 100)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(626, 250);
			this->tableLayoutPanel1->TabIndex = 0;
			// 
			// result
			// 
			this->result->Dock = System::Windows::Forms::DockStyle::Fill;
			this->result->Location = System::Drawing::Point(316, 35);
			this->result->Name = L"result";
			this->result->Size = System::Drawing::Size(307, 212);
			this->result->TabIndex = 3;
			this->result->Text = L"";
			// 
			// Debug
			// 
			this->Debug->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left));
			this->Debug->Location = System::Drawing::Point(3, 3);
			this->Debug->Name = L"Debug";
			this->Debug->Size = System::Drawing::Size(100, 26);
			this->Debug->TabIndex = 1;
			this->Debug->Text = L"Замена";
			this->Debug->UseVisualStyleBackColor = true;
			this->Debug->Click += gcnew System::EventHandler(this, &ReplaceDebugWindow::Debug_Click);
			// 
			// clear
			// 
			this->clear->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->clear->Location = System::Drawing::Point(515, 3);
			this->clear->Name = L"clear";
			this->clear->Size = System::Drawing::Size(108, 26);
			this->clear->TabIndex = 0;
			this->clear->Text = L"Очистить всё";
			this->clear->UseVisualStyleBackColor = true;
			this->clear->Click += gcnew System::EventHandler(this, &ReplaceDebugWindow::clear_Click);
			// 
			// source
			// 
			this->source->Dock = System::Windows::Forms::DockStyle::Fill;
			this->source->Location = System::Drawing::Point(3, 35);
			this->source->Name = L"source";
			this->source->Size = System::Drawing::Size(307, 212);
			this->source->TabIndex = 2;
			this->source->Text = L"";
			// 
			// ReplaceDebugWindow
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(626, 250);
			this->Controls->Add(this->tableLayoutPanel1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->MinimumSize = System::Drawing::Size(500, 200);
			this->Name = L"ReplaceDebugWindow";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Отладчик автозамены";
			this->tableLayoutPanel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	
	private: System::Void clear_Click(System::Object^  sender, System::EventArgs^  e)
	{
		source->Clear();
		result->Clear();
	}


	private: System::Void Debug_Click(System::Object^  sender, System::EventArgs^  e)
	{
		List<String^>^ src = StringToList(source->Text, '\n');
		result->Clear();
		source->Clear();
		for (int i = 0; i < src->Count; i++)
		{
			source->Text += src[i] + "\n";
			result->Text += templates->Replace(src[i]) + "\n";
		}
	}
};