#include "Updater.h"
#define _currentVersion "4.6"


using namespace System;
using namespace System::Windows::Forms;



[STAThread]
void Main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Settings^ sets = gcnew Settings();
	SHVersion ^Vers = gcnew SHVersion(_currentVersion);

	sets->Set("PreVersion", Vers->Pre);
	sets->Set("PostVersion", Vers->Post);
	sets->Save("");

	Updater ^Upd = gcnew Updater(Vers);
	Application::Run(Upd);
}