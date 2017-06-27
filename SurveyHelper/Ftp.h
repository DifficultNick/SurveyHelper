#pragma once

#include "Funuctions.h"

using namespace System;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace System::Net;
using namespace System::Text;
using namespace System::Text::RegularExpressions;
//using namespace Microsoft::CSharp;


public ref struct FileStruct
{
	FileStruct() {};
	~FileStruct() {};
	public: String^ Flags;
	public: String^ Owner;
	public: String^ Group;
	public: bool IsDirectory;
	public: DateTime CreateTime;
	public: String^ Name;
};

public enum FileListStyle
{
	UnixStyle,
	WindowsStyle,
	Unknown
};

// Класс для работы с FTP
public ref class FTP
{
private:
	String^ Host;
	String^ Port;
	String^ User;
	String^ Password;
	String^ Error = "Неизвестная ошибка";


		//* Notes: Конструктор класса
		public: FTP(String^ Host, String^ Port, String^ User, String^ Password)
		{
			this->Host = Host;
			this->Port = (String::IsNullOrEmpty(Port)) ? "" : (":" + Port);
			this->User = User;
			this->Password = Password;
			this->Error = "";
		}


		//* Notes: Запись файла на FTP
		public: bool UploadFile(String^ PathFTP, String^ NameFile)
		{
			if ( !File::Exists(NameFile) ) ShowError(501, "Ошибка доступа к файлу.");
			FileInfo ^InfoFile = gcnew FileInfo(NameFile);
			FtpWebRequest ^Request;
			String^ UploadUri = "";

			this->Error = "";
			if ( PathFTP == "" )
				UploadUri = "ftp://" + this->Host +  this->Port + "/" +
				InfoFile->Name;
			else
				UploadUri = "ftp://" + this->Host +  this->Port + "/" +
				PathFTP + "/" + InfoFile->Name;
			Request = dynamic_cast<FtpWebRequest^>(FtpWebRequest::Create(UploadUri));
			Request->Credentials = gcnew NetworkCredential(this->User, this->Password);
			Request->KeepAlive = false;
			Request->Method = WebRequestMethods::Ftp::UploadFile;
			Request->UseBinary = true;
			Request->ContentLength = InfoFile->Length;
			int BuffLength = 2048;
			array<Byte>^Buff = gcnew array<Byte>(BuffLength);
			int ContentLen;
			FileStream ^FS = InfoFile->OpenRead();
			if ( !FS ) ShowError(502, "Ошибка доступа к файлу");
			try
			{
				Stream ^Strm = Request->GetRequestStream();
				ContentLen = FS->Read(Buff, 0, BuffLength);
				while ( ContentLen != 0 )
				{
					Strm->Write(Buff, 0, ContentLen);
					ContentLen = FS->Read(Buff, 0, BuffLength);
				}
				// закрываем все потоки
				Strm->Close();
				FS->Close();
				return true;
			}
			catch ( Exception^ e )
			{
				this->Error = e->Message;
				return false;
			}
		}


		//* Notes: Загружает файл NameFileFTP c сервера  FTP и записывает
		//*        загруженный файл, на локальный компьтер с  именем NameFileLocal->
		public: bool DownloadFile(String^ NameFileFTP, String^ NameFileLocal)
		{
			FtpWebRequest ^Request;
			String^ DownloadUri = "";

			try
			{
				FileStream ^OutputStream = gcnew FileStream(NameFileLocal, FileMode::Create);
				this->Error = "";
				DownloadUri = "ftp://" + this->Host +  this->Port + "/" +
					NameFileFTP;
				Request = dynamic_cast<FtpWebRequest^>(FtpWebRequest::Create(DownloadUri));
				Request->Method = WebRequestMethods::Ftp::DownloadFile;
				Request->UseBinary = true;
				Request->Credentials = gcnew NetworkCredential(this->User, this->Password);
				FtpWebResponse ^Response = dynamic_cast<FtpWebResponse^>(Request->GetResponse());

				Stream ^FtpStream = Response->GetResponseStream();
				long cl = Response->ContentLength;
				int BufferSize = 2048;
				int ReadCount;
				array<Byte>^Buffer = gcnew array<Byte>(BufferSize);

				ReadCount = FtpStream->Read(Buffer, 0, BufferSize);
				while ( ReadCount > 0 )
				{
					OutputStream->Write(Buffer, 0, ReadCount);
					ReadCount = FtpStream->Read(Buffer, 0, BufferSize);
				}
				// закрываем все потоки
				FtpStream->Close();
				OutputStream->Close();
				Response->Close();
				return true;
			}
			catch ( Exception^ e )
			{
				this->Error = e->Message;
				return false;
			}
		}


		//* Notes: Возвращает строковый массив списка файлов и каталогов,
		//*        находящихся в указанном каталоге
		public: array<String^> ^ListDirectory(String^ PathFTP, bool Details)
		{
			array<String^> ^ DownloadFiles;
			StringBuilder ^Result = gcnew StringBuilder();
			FtpWebRequest ^Request;
			String^ UriFTP = "";

			try
			{
				this->Error = "";
				if ( PathFTP == "" )
					UriFTP = "ftp://" + this->Host +  this->Port + "/";
				else
					UriFTP = "ftp://" + this->Host +  this->Port + "/" +
					PathFTP;
				Request = dynamic_cast<FtpWebRequest^>(FtpWebRequest::Create(UriFTP));
				Request->UseBinary = true;
				Request->Credentials = gcnew NetworkCredential(this->User, this->Password);
				if ( Details )
					Request->Method = WebRequestMethods::Ftp::ListDirectoryDetails;
				else
					Request->Method = WebRequestMethods::Ftp::ListDirectory;
				WebResponse ^Response = Request->GetResponse();
				StreamReader ^Reader = gcnew StreamReader(Response->GetResponseStream(),
					Encoding::GetEncoding(1251));
				String^ Line = Reader->ReadLine();
				while ( Line != nullptr )
				{
					Result->Append(Line);
					Result->Append("\n");
					Line = Reader->ReadLine();
				}
				Reader->Close();
				Response->Close();
				if ( Result->Length != 0 )
				{
					Result->Remove(Result->ToString ()->LastIndexOf('\n'), 1);
					return Result->ToString ()->Split('\n');
				}
				else
				{
					return (gcnew array<String^>(0));
				}
			}
			catch ( Exception^ e )
			{
				this->Error = e->Message;
				DownloadFiles = gcnew array<String^>(0);
				return DownloadFiles;
			}
		}


		//* Notes: Возвращает строковый массив списка файлов или каталогов
		//*        находящихся в указанном каталоге
		public: array<String^>^ ListNameFile(String^ PathFTP, bool Files)
		{
			FtpWebRequest ^Request;
			array<String^>^ ListFile;
			String^ UriFTP = "";
			int NumDir = 0;
			int NumFile = 0;

			try
			{
				this->Error = "";
				if ( PathFTP == "" )
					UriFTP = "ftp://" + this->Host +  this->Port + "/";
				else
					UriFTP = "ftp://" + this->Host +  this->Port + "/" +
					PathFTP;
				Request = dynamic_cast<FtpWebRequest^>(FtpWebRequest::Create(UriFTP));
				Request->UseBinary = true;
				Request->Credentials = gcnew NetworkCredential(this->User, this->Password);
				Request->Method = WebRequestMethods::Ftp::ListDirectoryDetails;
				WebResponse ^Response = Request->GetResponse();
				StreamReader ^Reader = gcnew StreamReader(Response->GetResponseStream(),
					Encoding::GetEncoding(1251));
				String^ DataString = Reader->ReadToEnd();
				Reader->Close();
				Response->Close();
				array<FileStruct^>^ List = GetList(DataString);
				for each(FileStruct ^thisstruct in List)
				{
					if ( thisstruct->IsDirectory )
						NumDir++;
					else
						NumFile++;
				}
				if ( Files )
				{
					ListFile = gcnew array<String^>(NumFile);
					if ( NumFile == 0 )
						return ListFile;
				}
				else
				{
					ListFile = gcnew array<String^>(NumFile);
					if ( NumDir == 0 )
						return ListFile;
				}
				int j = 0;
				for ( int i = 0; i < List->Length; i++ )
				{
					if ( Files && !List[i]->IsDirectory )
						ListFile[j++] = List[i]->Name;
					else if ( !Files && List[i]->IsDirectory )
						ListFile[j++] = List[i]->Name;
				}
				return ListFile;
			}
			catch ( Exception^ e )
			{
				this->Error = e->Message;
				return gcnew array<String^>(0);
			}
		}


		private: array<FileStruct^>^ GetList(String^ DataStr)
		{
			Generic::List<FileStruct^> ^ListArray = gcnew Generic::List<FileStruct^>();
			array<String^> ^DataRec = DataStr->Split('\n');
			FileListStyle DirListStyle = GetFileListStyle(DataRec);
			for each(String^ s in DataRec)
			{
				if ( DirListStyle != FileListStyle::Unknown && s != "" )
				{
					FileStruct ^FS = gcnew FileStruct();
					FS->Name = "->->";
					switch ( DirListStyle )
					{
						case FileListStyle::UnixStyle:
							FS = ParseFileStructUnixStyle(s);
							break;
						case FileListStyle::WindowsStyle:
							FS = ParseFileStructWindowsStyle(s);
							break;
					}
					if ( !(FS->Name == "->" || FS->Name == "->->") )
					{
						ListArray->Add(FS);
					}
				}
			}
			return ListArray->ToArray();
		}


		private: FileStruct ^ParseFileStructUnixStyle(String^ Record)
		{
			FileStruct ^FS = gcnew FileStruct();
			String^ ProcStr = Record->Trim();
			if ( ProcStr->ToLower() == "total 0" )
			{
				FS->Name = "";
				return FS;
			}
			FS->Flags = ProcStr->Substring(0, 9);
			FS->IsDirectory = (FS->Flags[0] == 'd');
			ProcStr = (ProcStr->Substring(11))->Trim();
			CutSubstr(ProcStr, ' ', 0);
			FS->Owner = CutSubstr(ProcStr, ' ', 0);
			FS->Group = CutSubstr(ProcStr, ' ', 0);
			CutSubstr(ProcStr, ' ', 0);
			try
			{
				FS->CreateTime = DateTime::Parse(CutSubstr(ProcStr, ' ', 8));
			}
			catch ( UnauthorizedAccessException ^e)
			{
				FS->CreateTime = DateTime::Now;
			}
			if ( ProcStr->IndexOf(" ") > 0 )
				FS->Name = "\"" + ProcStr + "\"";
			else
				FS->Name = ProcStr;
			return FS;
		}


		private: FileStruct ^ParseFileStructWindowsStyle(String^ Record)
		{
			FileStruct ^FS = gcnew FileStruct();
			String^ ProcStr = Record->Trim();
			String^ DateStr = ProcStr->Substring  (0, 8);
			ProcStr = (ProcStr->Substring (8, ProcStr->Length - 8))->Trim();
			String^ TimeStr = ProcStr->Substring (0, 7);
			ProcStr = (ProcStr->Substring (7, ProcStr->Length - 7))->Trim();
			try
			{
				//ShowMessage("\"" + DateStr + " " + TimeStr + "\"");
				//FS->CreateTime = DateTime::Parse(DateStr + " " + TimeStr);
				FS->CreateTime = DateTime::Now;
			}
			catch ( UnauthorizedAccessException ^e )
			{
				//FS->CreateTime = DateTime::Now;
			}
			if ( ProcStr->Substring (0, 5) == "<DIR>" )
			{
				FS->IsDirectory = true;
				ProcStr = (ProcStr->Substring(5, ProcStr->Length - 5))->Trim();
			}
			else
			{
				array<String^>^ StrS = ProcStr->Split(gcnew array<wchar_t> { ' ' }, 	StringSplitOptions::RemoveEmptyEntries);
				// имя файла с пробелами внутри, обрамляем строку двойными кавычками
				if ( StrS->Length > 2 )
				{
					ProcStr = "";
					for ( int i = 1; i < StrS->Length; i++ )
						ProcStr = ProcStr + StrS[i] + " ";
					ProcStr = "\"" + ProcStr->Trim() + "\"";
				}
				else
					ProcStr = StrS[1]->Trim();
				FS->IsDirectory = false;
			}
			FS->Name = ProcStr;
			return FS;
		}


		public: FileListStyle GetFileListStyle(array<String^>^ RecList)
		{
			for each(String^ s in RecList)
			{
				if ( s->Length > 10
					&& Regex::IsMatch(s->Substring(0, 10),
						"(-|d)(-|r)(-|w)(-|x)(-|r)(-|w)(-|x)(-|r)(-|w)(-|x)") )
				{
					return FileListStyle::UnixStyle;
				}
				else if ( s->Length > 8
					&& Regex::IsMatch(s->Substring(0, 8),
						"[0-9][0-9]-[0-9][0-9]-[0-9][0-9]") )
				{
					return FileListStyle::WindowsStyle;
				}
			}
			return FileListStyle::Unknown;
		}


		private: String^ CutSubstr(String^ s, char c, int startIndex)
		{
			int pos1 = s->IndexOf(c, startIndex);
			String^ retString = s->Substring (0, pos1);
			s = (s->Substring (pos1))->Trim();
			return retString;
		}


		// получить сообщение об ошибке
		public: String^ Err()
		{
			return Error;
		}

};



/*
//****************************************
// Пример использования класса FTP
//****************************************

using System;
using SF;

&hellip;

// создаем объект
FTP oSF = new FTP("10.240.3.110", 21, "anonymous", "alex@mail.ru");

// запись файла с локального компьютера на сервер FTP
if ( oSF.UploadFile(@"Program\User", @"d:\temp\alfa.doc"))
	Console.WriteLine("Файл записан");
else
Console.WriteLine("Ошибка! " + oSF.Err);

// загрузка файла с сервера FTP на локальный компьютер
if ( oSF.DownloadFile(@"Program\User\alfa.doc", @"d:\temp\alfa.doc"))
	Console.WriteLine("Файл загружен");
else
Console.WriteLine("Ошибка! " + oSF.Err);

// получить список файлов и каталогов по указанному пути
string [] ListDir = oSF.ListDirectory(@"Program\User", false);
	if ( ListDir.Length > 0 )
	{
		Console.WriteLine("Список файлов:");
		for ( int i = 0; i < ListDir.Length; i++ )
			Console.WriteLine(ListDir[i]);
	}
	else
		Console.WriteLine("Список пуст");

// получить только список файлов
string [] ListFile = oSF.ListNameFile(@"Program\User", true);
	if ( ListFile.Length > 0 )
	{
		Console.WriteLine("Список файлов:");
		for ( int i = 0; i < ListFile.Length; i++ )
			Console.WriteLine(ListFile[i]);
	}
	else
		Console.WriteLine("Список пуст");
		*/