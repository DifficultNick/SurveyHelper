#pragma once

#include "Funuctions.h"
#include "Classes.h"
#include "MainForm.h"


	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;


public ref class Updater : public System::Windows::Forms::Form
{

	public:
		Updater(SHVersion^ v)
		{
			InitializeComponent();
			label2->Text = "Версия: " + v->ToString();
			label2->Left = this->Width - label2->Width - 5;
			Vers = v;
		}

		;
		String^ FTPPath;
		SHVersion^ Vers = gcnew SHVersion();
		SHVersion^ lastVers = gcnew SHVersion();
		MainForm^ MForm;
		bool LateToExit = false;
private: System::Windows::Forms::Button^  button1;

public:
	System::ComponentModel::ComponentResourceManager^  Resources = (gcnew System::ComponentModel::ComponentResourceManager(Updater::typeid));

#pragma region Windows Form Designer generated code

private:
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Updater::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 241);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(0, 13);
			this->label1->TabIndex = 0;
			// 
			// timer1
			// 
			this->timer1->Interval = 50;
			this->timer1->Tick += gcnew System::EventHandler(this, &Updater::timer1_Tick);
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(492, 239);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(47, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Версия:";
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->button1->BackColor = System::Drawing::Color::SteelBlue;
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->ImageAlign = System::Drawing::ContentAlignment::BottomCenter;
			this->button1->Location = System::Drawing::Point(529, -1);
			this->button1->Margin = System::Windows::Forms::Padding(0);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(22, 22);
			this->button1->TabIndex = 2;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Updater::button1_Click);
			// 
			// Updater
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::SteelBlue;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->ClientSize = System::Drawing::Size(551, 261);
			this->ControlBox = false;
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"Updater";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Updater";
			this->TransparencyKey = System::Drawing::Color::Aqua;
			this->Shown += gcnew System::EventHandler(this, &Updater::Updater_Shown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	private: System::ComponentModel::IContainer^  components;
	public: System::Windows::Forms::Label^  label1;
	public: System::Windows::Forms::Timer^  timer1;
	private: System::Windows::Forms::Label^  label2;


private:


	protected:

		~Updater()
		{
			if ( components )
			{
				delete components;
			}
		}
#pragma endregion

	private: SHVersion^ GetLatestVersion(List<String^>^ files)
	{
		int Pre = 0;
		int Post = 0;
		for each (String^ s in files)
		{
			if ( s->Contains("SH_v") )
			{
				String^ newVers = s->Remove(s->LastIndexOf("."));
				newVers = newVers->Remove(0, 4);
				int pre = StrToInt(newVers->Remove(newVers->IndexOf(".")));
				int post = StrToInt(newVers->Remove(0, newVers->IndexOf(".") + 1));
				if ( pre > Pre || pre == Pre && post > Post )
				{
					Post = post;
					Pre = pre;
				}
			}
		}
		return gcnew SHVersion(Pre, Post);
	}


	private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e)
	{
		List<String^>^ files = gcnew List<String^>();
		// исчезновение формы
		if (timer1->Interval == 50)
			if ( this->Opacity > 0 )
			{
				this->Opacity -= 0.1;
				if ( button1->Visible )
				{
					button1->Visible = false;
					Refresh();
				}
			}
			else
			{
				MForm->Show();
				timer1->Stop();
				LateToExit = true;
				this->Hide();
			}
		else
		// проверка статуса
		{
			timer1->Stop();
			try
			{
				if ( !Directory::Exists(_appDataDir) )
					Directory::CreateDirectory(_appDataDir);
			}
			catch ( Exception^ e )
			{
				ShowError(210, "Ошибка доступа. Невозможно создать папку.\n\nПодробнее:\n" + e->ToString());
				goto fail;
			}
			
			Settings^ sets = gcnew Settings();

			if ( sets->Read("MainForm") > 0 && sets->Get("DontUpdate", true) ) goto fail;

			sets->Read("");
			
			FTP^ c = gcnew FTP(_host, "", _user, _password);

			if ( sets->isWritten("JustUpdated") )
			{
				lastVers = Vers;
				goto run;
			}

			// Проверка обновлений
			try
			{
				label1->Text = "Проверка обновлений...";
				this->Update();

				files = gcnew List<String^>(c->ListNameFile("Content/SurveyHelper/" + _aditionalPath , true));
				if ( files->Count < 1 )
				{
					ShowError(503, "Ошибка поиска обновлений\n\nПодробнее:\n" + c->Err());
					goto fail;
				}

				lastVers = GetLatestVersion(files);

				if ( lastVers > Vers)
				{
					sets->Read("");
					if ( sets->isWritten("JustUpdated") ) goto run;

					if (
						MessageBox::Show("Найдена новая версия программы ("+lastVers->ToString()+")!\nОбновить сейчас?", "Обновление", Forms::MessageBoxButtons::YesNo, Forms::MessageBoxIcon::Question)
						== Forms::DialogResult::Yes
						)
					{
						String ^bat = Update(c, lastVers);

						if ( bat == "" )
						{
							ShowWarning("Обновление отменено");
							goto run;
						}

						if ( bat == "1" )
							ShowWarning("Произошла ошибка при замене версии.\nНовая версия приложения находится в папке со старой версией.\nРекомендуется переименовать новую версию в \"SurveyHelper.exe\"");
						else
						{
							Process::Start(bat);
							sets->Clear();
							sets->Set("JustUpdated", 1);
							sets->Save("");
						}

						goto exit;
					}
				}

			}
			catch ( Exception^ e )
			{
				ShowError(329, "Ошибка при запуске приложения\n\nПодробнее\n" + e->ToString());
				goto fail;
			}

		run:
			try
			{
				files = gcnew List<String^>(c->ListNameFile("Content/SurveyHelper/" + _aditionalPath, true));

				// библиотеки
				label1->Text = "Обновление библиотек...";
				this->Update();

				if ( files->Contains("Addons.lib") )
					c->DownloadFile("Content/SurveyHelper/" + _aditionalPath + "Addons.lib", _appDataDir + "\\Addons.lib");
				
				UpdateTemplates(c, files);

				// помощь
				label1->Text = "Обновление файла информации...";
				this->Update();

				if ( files->Contains("Help.html") )
					c->DownloadFile("Content/SurveyHelper/" + _aditionalPath + "Help.html", _appDataDir + "\\Help.html");

				// changelog
				sets->Read("");
				if ( sets->isWritten("JustUpdated") )
				{
					SaveUserInfo(c);
					if (
						MessageBox::Show("Открыть список изменений?", "Что нового", Forms::MessageBoxButtons::YesNo, Forms::MessageBoxIcon::Question)
						== Forms::DialogResult::Yes
						) OpenUrl(_appDataDir + "\\Help.html?t=changes&vers=" + Vers->ToString() + "&t2=v"+ lastVers->ToString());
					sets->Remove("", "JustUpdated");
				}
			}
			catch ( Exception ^e )
			{
				ShowError(504, "Ошибка загрузки дополнительных файлов\n\nПодробнее:\n" + c->Err());
			}
fail:
			// запуск
			label1->Text = "Загрузка приложения...";
			this->Update();
			MForm = gcnew MainForm(Vers->ToString());
			timer1->Interval = 50;
			timer1->Start();
			label1->Text = "Приложение готово к работе!";
			this->Update();
		}
		return;
exit: 
		this->Close();
	}


	// обновление Regex шаблонов замены
	void UpdateTemplates(FTP^ c, List<String^>^ fileList)
	{
		try
		{
			int cvI = 0;
			Settings^ sets = gcnew Settings();
			sets->Read("");
			if ( sets->isWritten("TemplatesVersion") ) cvI = StrToInt(sets->Get("TemplatesVersion"));
			for each (String^ s in fileList)
				if ( s->Contains("ReplaceList_v") )
				{
					int v = StrToInt(s->Replace("ReplaceList_v", "")->Replace(".bin", ""));
					if ( v < 0 ) return;
					if ( v <= cvI ) continue;
					sets->Clear();
					sets->Set("TemplatesVersion", v);
					if (File::Exists(_appDataDir + "\\ReplaceList.bin")) sets->Set("TemplatesUpdated", "1");
					sets->Save("");
					c->DownloadFile("Content/SurveyHelper/" + _aditionalPath + s, _appDataDir + "\\ReplaceList.bin");
					break;
				}
		}
		catch ( Exception^ e )
		{
			ShowError(428, "Ошибка при обновлении библиотеки шаблонов замены.\n\nПодробнее:\n" + e->ToString());
		}
	}


	// Возвращает 1, если скачалось, но не заменилось, пусто, если не скачалось и имя Bat, если всё ок
	public: String^ Update(FTP^ c, SHVersion^ v)
	{
		//progressBar1->Visible = true;
		label1->Text = "Скачивание новой версии...";
		label1->Update();

		String^ path = Application::ExecutablePath;
		path = path->Remove(path->LastIndexOf(".")) + ".new";

		if ( !c->DownloadFile("Content/SurveyHelper/" + _aditionalPath + "SH_v"+v->ToString()+".exe", path) )
		{
			ShowError(209, "Ошибка при скачивании файла");
			return "";
		}

		return CreateBat(FileInfo(path).Directory->FullName);
	}


	private: void SaveUserInfo(FTP^ c)
	{
		String^ path = _appDataDir + "\\";
		path = path + Environment::UserName + ".txt";

		List<String^>^ Str = gcnew List<String^>();

		if ( (gcnew List<String^>(c->ListNameFile("Content/SurveyHelper/report/", true)))->Contains(Environment::UserName + ".txt") )
		{
			c->DownloadFile("Content/SurveyHelper/report/" + Environment::UserName + ".txt", path);
			Str = gcnew List<String^>(ReadFile(path));
		}

		Str->Add(Vers->ToString());
		Str->Add(DateTime::Now.ToString());
		WriteFile(path, Str->ToArray(), System::Text::Encoding::GetEncoding(1251));
		c->UploadFile("Content/SurveyHelper/report/", path);

		File::Delete(path);
	}


	private: String^ CreateBat(String^ dir)
	{
		if ( dir[dir->Length - 1] == '\\' ) dir = dir->Remove(dir->Length - 1);
		array<String^>^ Str = 
		{
			"@echo off",
			"cd \"" + dir + "\"",
			":retry",
			"DEL \"" + Application::ExecutablePath + "\"",
			"IF EXIST \"" + Application::ExecutablePath + "\" goto retry",
			"RENAME \"" + Application::ExecutablePath->Remove(Application::ExecutablePath->LastIndexOf(".")) + ".new" + "\" \"" + Path::GetFileName(Application::ExecutablePath) + "\"",
			"START \"\" \"" + Path::GetFileName(Application::ExecutablePath) + "\"",
			"DEL \"Updater.bat\"",
			"EXIT"
		};

		if ( WriteFile(dir + "\\Updater.bat", Str, System::Text::Encoding::GetEncoding(866)) )
			return dir + "\\Updater.bat";
		else
			ShowError(208, "Ошибка при замене версии");
		return "1";
	}
	

	private: System::Void Updater_Shown(System::Object^  sender, System::EventArgs^  e)
	{
		timer1->Interval = 800;
		timer1->Start();
	}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if ( !LateToExit ) Application::Exit();
	}
};
