#pragma once

#include "Ftp.h"
#include "Funuctions.h"
#include "QuestionDialogWindow.h"
#include "SecurityFile.h" // not for all =)


#define _aditionalPath ""
#define _appDataDir (Environment::GetFolderPath(Environment::SpecialFolder::ApplicationData) + "\\SurveyHelper")
//#define _libraryPath ("C:\\Users\\Ruslan\\Documents\\Visual Studio 2015\\Projects\\SurveyHelper\\Lib\\Addons.lib")
#define _libraryPath (_appDataDir + "\\Addons.lib")


using namespace System;
using namespace System::Collections;
using namespace System::Collections::Generic;
using namespace Microsoft::Win32;
using namespace System::Xml;
using namespace System::Resources;
using namespace System::Reflection;



// предоставляет элементы для работы с шаблонами замены
namespace CustomTemplates
{
	// структура шаблона замены
	[Serializable]
	public ref struct CustomTemplate
	{
		CustomTemplate(bool active, String^ key, String^ value, bool isCustom)
		{
			Active = active;
			Key = key;
			Value = value;
			IsCustom = isCustom;
		}
		
		bool Active;
		String^ Key;
		String^ Value;
		bool IsCustom = false;
	};

	[Serializable]
	public ref class CustomTemplateList: List<CustomTemplate^>
	{
	public:
		CustomTemplateList()
		{};
		~CustomTemplateList()
		{};

		int Add(bool active, String^ key, String^ value, bool isCustom)
		{
			this->Add(gcnew CustomTemplate(active, key, value, isCustom));
			return this->Count;
		}

		CustomTemplateList^ SelectActive()
		{
			CustomTemplateList^ res = gcnew CustomTemplateList();
			for each (CustomTemplate^ tmp in this)
				if ( tmp->Active ) res->Add(tmp);
			return res;
		}

		array<String^>^ ToArray()
		{
			array<String^>^ res = gcnew array<String^>(this->Count);
			int i = 0;
			for each (CustomTemplate^ tmp in this)
				res[i++] = (tmp->Active ? "1" : "0") + "\n" + tmp->Key + "\n" + tmp->Value;

			return res;
		}

		String^ Replace(String^ str)
		{
			String^ res = str;
			try
			{
				for each (CustomTemplate^ item in this)
					if (item->Active) res = Regex::Replace(res, item->Key, item->Value);
			}
			catch ( Exception^ e )
			{
				ShowError(422, "Ошибка замены\n\n" + e->ToString());
			}
			return res;
		}
	};


	static CustomTemplateList^ GetFrom(String^ filePath)
	{
		CustomTemplateList^ res = gcnew CustomTemplateList();
		if ( !File::Exists(filePath) ) return res;
		res = (CustomTemplateList^)StructFileRead(filePath);
		return res;
	}

	static CustomTemplateList^ Get()
	{
		CustomTemplateList^ res = gcnew CustomTemplateList();
		if ( File::Exists(_appDataDir + "\\CustomReplaceList.bin") )
			res = GetFrom(_appDataDir + "\\CustomReplaceList.bin");
		else
			if ( File::Exists(_appDataDir + "\\ReplaceList.bin") )
			{
				res = GetFrom(_appDataDir + "\\ReplaceList.bin");
				for ( int i = 0; i < res->Count; i++ )
					res[i]->IsCustom = false;
			}
		return res;
	}

	static bool SaveAs(CustomTemplateList^ templates, String^ filePath)
	{
		CustomTemplateList^ res = gcnew CustomTemplateList();
		return StructFileWrite(filePath, templates);
	}

	static bool Save(CustomTemplateList^ templates)
	{
		return CustomTemplates::SaveAs(templates, _appDataDir + "\\CustomReplaceList.bin");
	}

}


public ref struct AddonTag
{
	String^ Title;
	String^ Name;
	String^ Boody;
};


public ref struct SHVersion
{
	int Pre;
	int Post;

	public: SHVersion()
	{
	}

	public: SHVersion(int pre, int post)
	{
		Pre = pre;
		Post = post;
	}

	static bool operator > (SHVersion^ v1, SHVersion^ v2)
	{
		if ( v1->Pre > v2->Pre ) return true;
		if ( v1->Pre < v2->Pre ) return false;
		return v1->Post > v2->Post;
	}

	public: SHVersion(String ^v)
	{
		try
		{
			Int32::TryParse(v->Remove(v->IndexOf(".")), Pre);
			Int32::TryParse(v->Remove(0, v->IndexOf(".") + 1), Post);
		}
		catch ( Exception^ e )
		{
			Pre = 0;
			Post = 0;
		}
	}

	// возвращает версию в виде 2.45
	public:  String^ ToString() override
	{
		return this->Pre.ToString() + "." + this->Post.ToString();
	}
};


public ref struct DefaultValue
{
	Object^ Object;
	String^ Value;
	String^ Type;

public:
	DefaultValue()
	{}

	DefaultValue::DefaultValue(System::Object^ object, String^ value)
	{
		Object = object;
		Value = value;
		Type = Object->GetType()->ToString();
	}

	DefaultValue::DefaultValue(System::Object^ object, bool value)
	{
		Object = object;
		Value = value.ToString();
		Type = Object->GetType()->ToString();
	}

	DefaultValue::DefaultValue(System::Object^ object, int value)
	{
		Object = object;
		Value = value.ToString();
		Type = Object->GetType()->ToString();
	}
};


public ref struct DefaultValueList: List<DefaultValue^>
{
	int Add(Object^ Object, String^ Value)
	{
		DefaultValue^ tmp = gcnew DefaultValue(Object, Value);
		this->Add(tmp);
		return this->Count;
	}

	int Add(Object^ Object, bool Value)
	{
		DefaultValue^ tmp = gcnew DefaultValue(Object, Value);
		this->Add(tmp);
		return this->Count;
	}

	int Add(Object^ Object, int Value)
	{
		DefaultValue^ tmp = gcnew DefaultValue(Object, Value);
		this->Add(tmp);
		return this->Count;
	}

	void SetAll()
	{
		try
		{
			for each (DefaultValue^ val in this)
			{
				if ( val->Type == (gcnew CheckBox)->GetType()->ToString() )
					((CheckBox^)val->Object)->Checked = Convert::ToBoolean(val->Value);
				if ( val->Type == (gcnew ToolStripMenuItem)->GetType()->ToString() )
					((ToolStripMenuItem^)val->Object)->Checked = Convert::ToBoolean(val->Value);
				else if ( val->Type == (gcnew TextBox)->GetType()->ToString() )
					((TextBox^)val->Object)->Text = val->Value;
				else if ( val->Type == (gcnew ComboBox)->GetType()->ToString() )
					((ComboBox^)val->Object)->SelectedIndex = StrToInt(val->Value);
				else if ( val->Type == (gcnew ToolStripComboBox)->GetType()->ToString() )
					((ToolStripComboBox^)val->Object)->SelectedIndex = StrToInt(val->Value);
			}
		}
		catch ( Exception^ e )
		{
			ShowError(423, "Ошибка восстановления настроек по умолчанию.\n\nПодробнее:\n"+e->ToString());
		}
	}
};


public ref struct ProjectResources
{
	public: ProjectResources()
	{
		Assembly^ assembly = Assembly::GetExecutingAssembly();
		ResourceManager ^rm = gcnew ResourceManager(assembly->GetName()->Name + ".Resources", assembly);
		Res = gcnew Dictionary<String^, System::Object^>();
		Resources::ResXResourceReader^ rsxr = gcnew ResXResourceReader("Resources.resx");
		System::Collections::IEnumerator^ myEnum = rsxr->GetEnumerator();
		while ( myEnum->MoveNext() )
		{
			DictionaryEntry^ d = safe_cast<DictionaryEntry^>(myEnum->Current);
			Res->Add(d->Key->ToString(), d->Value);
		}
	}

	public: System::Object^ Get(String^ ResName)
	{
		if ( !Res->ContainsKey(ResName) ) return nullptr;
		return Res[ResName];
	}

	public: Drawing::Image^ GetImage(String^ ResName)
	{
		return cli::safe_cast<Drawing::Image^>(this->Get(ResName));
	}

	private:

		Dictionary<String^, System::Object^>^ Res;
};


// структура для работы с выражениями
// рассматривается только выражжение a+b*#
ref struct IteraTemplate
{
private:
	String^ Templ = "";

public:
	IteraTemplate(String^ body)
	{
		Templ = body;
		Valid = Regex::IsMatch(Templ, "^(\\d+\\+)?(\\d+\\*)?#$");
		if ( Valid ) SetExpression();
	}

	int a = 0;
	int b = 1;
	bool Valid = false;

	void SetExpression()
	{
		String^s = Templ;
		if ( Templ->Contains("+") )
		{
			a = StrToInt(Templ->Remove(Templ->IndexOf("+")));
			s = Templ->Remove(0, Templ->IndexOf("+") + 1);
		}

		if ( s->Contains("*") )
			b = StrToInt(s->Remove(s->IndexOf("*")));
	}

	int Evaluate(int i)
	{
		return a + b * i;
	}

};


// структура для работы с диапазоном
ref struct RangeTemplate
{
public:
	bool Valid = false;
	int Min = 1;
	int Max = 10;

	RangeTemplate(String^ templ)
	{
		Valid = Regex::IsMatch(templ, "^\\d+to\\d+$");
		if ( Valid )
		{
			Min = StrToInt(templ->Remove(templ->IndexOf("to")));
			Max = StrToInt(templ->Remove(0, templ->IndexOf("to") + 2));
		}
	}
};

// структура для работы с исключёнными элементами
ref struct ExcludeTemplate
{
public:
	bool Valid = false;
	List<int>^ Items = gcnew List<int>();

	ExcludeTemplate(String^ templ)
	{
		Valid = Regex::IsMatch(templ, "^e\\{(\\d+,?)*\\}$");
		if ( Valid )
		{
			String^ s = templ;
			int j = s->IndexOf(",");
			while ( j > -1 )
			{
				Items->Add(StrToInt(s->Remove(j)));
				s = s->Remove(0, j + 1);
				j = s->IndexOf(",");
			}
			if ( !String::IsNullOrEmpty(s) ) Items->Add(StrToInt(s));
		}
	}
};


ref struct AgeRange
{
public:

	AgeRange(String^ str)
	{
		Input = str;
		String^ pattern = "\\d\\d";
		MatchCollection^ matches = Regex::Matches(str, pattern);
		Count = matches->Count;
		if ( Count == 0 ) return;
		Values[0] = StrToInt(matches[0]->Value);
		Vars = Values[0].ToString();
		Text = Values[0].ToString();
		if ( Count > 1 )
		{
			Values[1] = StrToInt(matches[1]->Value);
			Vars += "," + Values[1];
			Text += "_" + Values[1];
		}
		IsValid = true;
	}

	Void Set(int a, int b)
	{
		Text = a.ToString() + "_" + b.ToString();
		Vars = a.ToString() + "," + b.ToString();
		Values[0] = a;
		Values[1] = b;
		Count = 2;
		Input = "";
		IsValid = true;
	}

	int Count = 0;
	static array<int>^ Values = gcnew array<int> {0, 0};
	bool IsValid = false;
	String^ Vars = "";
	String^ Text = "";

	virtual String^ ToString() override
	{
		String^ res = "";
		if ( this->Values->Length > 0 ) res += this->Values[0].ToString();
		if ( this->Values->Length > 1 ) res += "-" + this->Values[1].ToString();
		return res;
	}

	int ToNumber()
	{
		int res = 0;
		if ( this->Values->Length > 0 ) res = this->Values[0];
		if ( this->Values->Length > 1 ) res = res * 100 + this->Values[1];
		return res;
	}

private:
	String^ Input = "";
};





public enum MixType : int { None, Mix, MixId };
public enum UnionMixType: int { UnionNone, UnionMix, UnionMixId };

/*

В А Ж Н О  !

порядок действий:
1) конструктор;
2)
2.1) AddAtributes: если разделение тэгов не требуется, то
в параметрах передаются все атрибуты и тэг имеет вид
<Answer Id="1" Var="456,3"/>
2.2) если какие-то атрибуты необходимо выделить в отдельные
теги, то они не передаются в параметрах. Для этого есть
AddVars и AddText
3) результат получается на выходе ConvertToItems

*/




// структура для хранения значения предыдущей ячейки
ref struct prevCellstr
{
	public:
		String^ Value;
		int Column = -1;
		int Row;
};









// базовый класс построения XML без преобразований
public ref class Elements
{
public:
	Elements(String^ elementName, int count)
	{
		ElemName = elementName;
		Count = count;
		Atributes = gcnew Dictionary<String^, List<String^>^>();
	};

	~Elements() {};



	void AddVars(List<List<String^>^>^ vars, bool separated)
	{
		//if 
		VarsEnabled = true;
		VarSeparate = separated;
		Vars = gcnew List<List<String^>^>(vars);

		if ( !VarSeparate )
		{
			List<String^>^ s = gcnew List<String^>();
			for each (List<String^>^ strlst in vars)
			{
				s->Add(ListToString(strlst, ","));
			}

			Atributes->Add("Var", s);
		}
	}


	void AddText(List<String^>^ text, bool separated, bool mustClear, bool sp, bool contScr)
	{
		TextSeparate = separated;
		List<String^>^ CleanText = gcnew List<String^>();
		for ( int i = 0; i < text->Count; i++ )
			CleanText->Add(ClearString(text[i],true,mustClear,sp, contScr));

		Texts = gcnew List<String^>(CleanText);
		if (!TextSeparate)
			Atributes->Add("Text", CleanText);

	}


	void AddText(List<String^>^ text, bool separated, bool mustClear, bool sp)
	{
		return AddText(text, separated, mustClear, sp, false);
	}

	// коллекция атрибутов для каждого элемента
	void AddAttributes(Dictionary<String^, List<String^>^>^ atr)
	{
		for each (KeyValuePair<String^, List<String^>^>^ a in atr)
		{
			Atributes->Add(a->Key, a->Value);
		}
	}


	List<String^>^ MakeXML()
	{
		List<String^>^ res = gcnew List<String^>();
		String^ str = "";

		for ( int i = 0; i < Count; i++ )
		{
			str = "<" + ElemName + AtributesToString(i) + GetAditionalAtribs(i);
			if ( !TextSeparate && (!VarSeparate || !VarsEnabled) )
			{
				str += "/>";
				res->Add(str);
				continue;
			}

			str += ">";

			if ( TextSeparate )
				if ( Texts[i] != nullptr && !String::IsNullOrEmpty(Texts[i]) ) str += "<Text>" + Texts[i] + "</Text>";

			try
			{
				if ( VarSeparate && VarsEnabled )
					if ( i < Vars->Count)
						for each (String^ var in Vars[i])
							str += "<Var>" + var + "</Var>";
					else if (Vars->Count>0) 
						for each (String^ var in Vars[0])
							str += "<Var></Var>";
			}
			catch ( Exception^ e )
			{
				ShowError(101, "Ошибка разбора списка Vars.\nПодробнее:\n"+e->ToString());
			}

			
			str += "</" + ElemName + ">";

			res->Add(str);
		}

		
		if ( AddRepeat )
		{
			String^ rtxt = (IsNumber(RepeatName)) ? RepeatText : "@Text";

			String^ txt = "\t<" + ElemName + " Id=\"" + ( (IsNumber(RepeatName)) ? "@Itera\"" : "@ID\"" );
			if ( TextSeparate )
				if ( !String::IsNullOrEmpty(rtxt) ) txt += "><Text>" + rtxt + "</Text>" + "</" + ElemName + ">";
				else txt += "/>";
			else
				if ( !String::IsNullOrEmpty(rtxt) ) txt += " Text=\"" + rtxt + "\"/>";
				else txt += "/>";

			res->Insert(0, "</Repeat>");
			res->Insert(0,  txt);
			res->Insert(0, "<Repeat " + ((IsNumber(RepeatName)) ? "Length" : "List") + "=\"" + RepeatName + "\">");
		}

		AllElements = gcnew List<String^>(res);
		return res;
	}


	// возвращает строку с атрибутами
	String^ AtributesToString(Dictionary<String^, String^>^ atrs)
	{
		String^ res = "";

		try
		{
			for each (KeyValuePair<String^, String^> atr in atrs)
				if ( atr.Value != nullptr && !String::IsNullOrEmpty(atr.Value) && atr.Key != "Var" && atr.Key != "Id" )
					res += " " + atr.Key + "=\"" + atr.Value + "\"";

		}
		catch (Exception^ e)
		{
			ShowError(102, "Ошибка создания атрибутов элемента.\nПодробнее:\n"+e->ToString());
		}
		
		return res;
	}


	// возвращает элемент num
	String^ Get(int num)
	{
		if ( num >= AllElements->Count ) return "NoElement";

		return AllElements[num];
	}


	String^ ElemName = "";
	int TabCount; // количество tab
	bool MissFirstTab = true; // пропуск первой табуляции
	List<String^>^ AllElements;	// содержит все преобразованные элементы
	bool AddParentTag = true;
	
	String^ ParentId = ""; // Page/List Id

	bool VarsEnabled = false;
	bool AddRepeat = false;
	String^ RepeatName = "";
	String^ RepeatText = "";
	bool AutoTags = true;
	int Count = 0;

	static String^ GetTabs(int c)
	{
		return gcnew String('\t', c);
	}

protected:
	// возвращает строку с атрибутами элемента num
	String^ AtributesToString(int num)
	{
		if ( Atributes == nullptr)
		{
			ShowError(103, "Ошибка получения атрибутов элемента.");
			return "";
		}

		if ( Atributes->Count < 1 ) return "";
		String^ res = "";

		try
		{
			for each (KeyValuePair<String^, List<String^>^> atr in Atributes)
			{
				if ( num < atr.Value->Count  && !String::IsNullOrEmpty(atr.Value[num]) )
					res += " " + atr.Key + "=\"" + atr.Value[num] + "\"";
				else if ( atr.Key == "Var" )
					res += " Var=\"\"";
				else if ( atr.Key == "Id" )
					res += " Id=\"\"";
			}
		}
		catch ( Exception^ e )
		{
			ShowError(104, "Ошибка получения атрибутов элемента.");
		}

		return res;
	}



	String^ GetAditionalAtribs(int num)
	{
		if ( !AditionalAtribs->ContainsKey(num) ) return "";
		return AditionalAtribs[num];
	}

	bool TextSeparate = true,
		VarSeparate = false;

	List<List<String^>^>^ Vars = gcnew List<List<String^>^>();
	List<String^>^Texts = gcnew List<String^>();
	Dictionary<String^, List<String^>^>^ Atributes;
	Dictionary<int, String^>^ AditionalAtribs = gcnew Dictionary<int, String^>();
};





public ref class Items: public Elements
{
public:
	Items(int count): Elements("Item", count)
	{
	}

	~Items()
	{
	}

	List<String^>^ MakeXML()
	{
		Elements::MakeXML();
		if ( AddParentTag )
		{
			try
			{
				for ( int i = 0; i < AllElements->Count; i++ )
					AllElements[i] = "\t" + AllElements[i];

				if ( AllElements->Count > 0 )
				{
					AllElements->Insert(0, "<List Id=\"" + ParentId + "\">");
					AllElements->Add("</List>");
				}
			}
			catch ( Exception^ e )
			{
				ShowError(105, "Ошибка обработки табуляции XML.\nПодробнее:\n" + e->ToString());
			}
			
		}

		for ( int i = (MissFirstTab) ? 1 : 0; i < AllElements->Count; i++ )
			AllElements[i] = GetTabs(TabCount) + AllElements[i];

		return AllElements;
	}

	// Var через ,
	static List<String^>^ VarsToStringList(List<List<String^>^>^ vars)
	{
		List<String^>^ res = gcnew List<String^>();
		String^ str;
		
		try
		{
			for each (List<String^>^ var in vars)
			{
				str = "";
				for each (String^ s in var)
				{
					str += s + ",";
				}
				str->Remove(str->LastIndexOf(","));
				res->Add(str);
			}
		}
		catch ( Exception^ e )
		{
			ShowError(106, "Ошибка обработки Vars\nПодробнее:\n" + e->ToString());
		}
		
		return res;
	}
};





public ref class Answers: public Elements
{
public:
	Answers(int count): Elements("Answer", count)
	{
	}

	~Answers()
	{
	}


	String^ QuestionAttributes = "";
	String^ Extend = "";
	bool ExtendAdd = false;;
	String^ Header = "";
	String^ PageHeader = "";
	bool AddPageTag = true;


	/*void AddQuestionAttributes(Dictionary<String^, String^>^ atrs)
	{
		try
		{
			QuestionAttributes = AtributesToString(atrs);
			AddParentTag = true;
			if ( atrs->ContainsKey("Type") ) QType = atrs["Type"];
		}
		catch ( Exception^ e )
		{
			ShowError(107, "Ошибка создания атрибутов\nПодробнее:\n" + e->ToString());
		}
		
	}*/

	// атрибуты через пробел в виде Mix="true" Type="Text"
	void AddQuestionAttributes(String^ atrs)
	{
		if ( String::IsNullOrEmpty(atrs) ) return;

		if ( atrs[0] != ' ' ) atrs = " " + atrs;
		QuestionAttributes = atrs;
		AddParentTag = true;
	}


	List<String^>^ MakeXML()
	{
		Elements::MakeXML();

		
		if ( AddParentTag )
		{
			try
			{
				for ( int i = 0; i < AllElements->Count; i++ )
					AllElements[i] = "\t\t" + AllElements[i];

				if ( ExtendAdd ) AllElements->Insert(0, "\t<Ui" + Extend + "/>");
				if ( !String::IsNullOrEmpty(Header) ) AllElements->Insert(0, "  <Header>" + Header + "</Header>");
				if ( !String::IsNullOrEmpty(QuestionAttributes) ) AllElements->Insert(0, "<Question" + QuestionAttributes + ">");
				if ( !String::IsNullOrEmpty(QuestionAttributes) ) AllElements->Add("</Question>");
			}
			catch ( Exception^ e )
			{
				ShowError(108, "Ошибка обработки табуляции XML\n\nПодробнее:\n" + e->ToString());
			}
		}
		if ( AddPageTag )
		{
			for ( int i = 0; i < AllElements->Count; i++ )
				AllElements[i] = "\t\t" + AllElements[i];

			if (!String::IsNullOrEmpty(PageHeader)) AllElements->Insert(0, "\t<Header>" + PageHeader + "</Header>");
			AllElements->Insert(0, "<Page Id=\"" + ParentId + "\">");
			// добавление Redirect
			if ( AutoTags && Screens->Count > 0 )
			{
				try
				{
					// получение QuestionId
					String^ Qid = "";
					if ( QuestionAttributes->Contains("Id") )
					{
						Qid = QuestionAttributes->Remove(0, QuestionAttributes->IndexOf("Id") + 4);
						Qid = Qid->Remove(Qid->IndexOf("\""));
					}

					String^ redirect = "<Redirect Status=\"19\">return ";

					List<String^>^ lst = gcnew List<String^>();
					if ( Atributes->ContainsKey("Id") ) lst = Atributes["Id"];
					String^ rt = "", ^cb = "";

					// получение списка ответов
					for ( int i = 0; i < lst->Count; i++ )
					{
						if ( Screens->Contains(i) ) rt += lst[i] + ",";
						else cb += lst[i] + ",";
					}
					cb = cb->Remove(cb->LastIndexOf(","));
					rt = rt->Remove(rt->LastIndexOf(","));

					// добавление списка ответов
					if ( QuestionAttributes->Contains("CheckBox") )
					{
						redirect += "AnswerExists" + ((Screens->Count > 1) ? "Any" : "") + "(\"" + Qid + "\", \"" + rt;
					}
					else
					{
						if (lst->Count/2 < Screens->Count) 
							redirect += "!AnswerExists" + ((lst->Count - Screens->Count > 1) ? "Any" : "") + "(\"" + Qid + "\", \"" + cb;
						else 
							redirect += "AnswerExists" + ((Screens->Count > 1) ? "Any" : "") + "(\"" + Qid + "\", \"" + rt;
					}

					redirect += "\");</Redirect>";
					AllElements->Add("\t"+redirect);
				}
				catch ( Exception^ e )
				{
					ShowError(414, "Ошибка обработки Redirect\n\nПодробнее:\n" + e->ToString());
				}
			}
			AllElements->Add("</Page>");
		}

		for ( int i = (MissFirstTab) ? 1 : 0; i < AllElements->Count; i++ )
			AllElements[i] = GetTabs(TabCount) + AllElements[i];

		return AllElements;
	}


	void AddText(List<String^>^ text, bool separated, bool mustClear, bool sp)
	{
		bool a = false;
		List<String^>^ t = text;
		// выделение screenOut
		if ( AutoTags )
		{
			Screens = GetScreenIds(text);
			t = ClearScreenWords(text);
			if ( Screens->Count > 0 ) a = true;
		}
		Elements::AddText(t, separated, mustClear, sp, a);
		// доп атрибуты Answer
		if ( AutoTags ) AditionalAtribs = InvokeAditionalAtribs(text);
	}


	// например, Type="Text"
	Dictionary<int, String^>^ InvokeAditionalAtribs(List<String^>^ txt)
	{
		Dictionary<int, String^>^ res = gcnew Dictionary<int, String^>();
		if ( txt == nullptr || txt->Count < 1 ) return res;
		String^ s, ^tmp = "";
		try
		{
			for ( int i = 0; i < txt->Count; i++ )
			{
				tmp = "";
				s = txt[i]->ToLower();
				//ShowMessage(GetProp(QuestionAttributes, "Mix"));
				List<String^>^ found = gcnew List<String^>(gcnew array<String^> {"уточните", "укажите", "впишите", "запишите", "открытое поле", "поле для ввода", "где именно", "какая именно", "какой именно", "что именно", "open"});
				for each (String^ str in found)
					if ( s->Contains(str) )
					{
						tmp += " Type=\"Text\" Fix=\"true\"";
						break;
					}

				if ( (gcnew String("RadioButton CheckBox Text Integer Memo Number"))->Contains(GetProp(QuestionAttributes, "Type")) )
				{
					found = gcnew List<String^>(gcnew array<String^> {"отказ", "затрудняюсь", "ничего", "ни один", "ни одного", "ни одной", "ни одну", "ни одно", "ни в одном", "ни в одной", "никогда", "исключающий", "exclude", "exclusive", "нет ответа", "не отвечать", "никакой", "никакую", "никакое"});
					for each (String^ str in found)
						if ( s->Contains(str) )
						{
							tmp += " Reset=\"true\" Fix=\"true\"";
							break;
						}
				}
				if ( tmp != "" ) res->Add(i, tmp);
			}
		}
		catch ( Exception^ e )
		{
			ShowError(414, "Ошибка генерации дополнительных элементов\n\nПодробнее\n" + e->ToString());
		}

		return res;
	}



protected: 

	List<int>^ Screens = gcnew List<int>();

	String^ GetProp(String^ atrs, String^ prop)
	{
		if ( !atrs->Contains(prop) ) return "";
		String^ res = atrs;
		res = atrs->Remove(0, atrs->IndexOf("\"", atrs->IndexOf(prop)) + 1);
		res = res->Remove(res->IndexOf("\""));
		return res;
	}

};





public ref class Union
{
#pragma region Variables
public:
	String^ QuestionType;
	String^ QuestionListId;
	String^ AnswerListId;
	String^ DummyHeader;
	String^ Extend;
	String^ PageHeader;
	String^ DummyAtributes;
	String^ QuestionId; // маска Id Вопросов
	//AdditionalAnswer^ NothingAnswer;
	//AdditionalAnswer^ RefuseAnswer;

	bool TextSeparate;
	bool DummyExtend;
	bool AutoTags;
	bool DontClear;
	bool IgnoreSpases;

	int TabCount = 1;
	bool MissFirstTab = true;

	MixType mix = MixType::None;
	UnionMixType unionMix = UnionMixType::UnionNone;;
	String^ MixIdText = "";
	String^ UnionMixIdText = "";

	bool AddRepeat = false;
	String^ RepeatName = "";
	String^ RepeatText = "";

private:
	List<String^>^ AnswerIds = gcnew List<String^>(); // список ID Ответов 
	Items^ QuestionList;
	Items^ AnswerList;
	Answers^ answers;
	List<String^>^ QuestionText;
	List<String^>^ AnswerText;
	int QuestionCount;
	int AnswerCount;
	bool CombineQuestions;
	bool CombineAnswers;
#pragma endregion

public:
	Union::Union()
	{
	}

	Union::~Union()
	{
	}


	void AddQuestions(List<String^>^ questions, bool combQuestions)
	{
		QuestionText = gcnew List<String^>(questions);
		QuestionCount = QuestionText->Count;
		CombineQuestions = combQuestions;
	}

	void AddAnswers(List<String^>^ Answers, List<String^>^ answerIds, bool combAnswers)
	{
		AnswerText = gcnew List<String^>(Answers);
		AnswerIds = gcnew List<String^>(answerIds);
		AnswerCount = AnswerText->Count;
		CombineAnswers = combAnswers;
	}

	List<String^>^ MakeXML()
	{
		List<String^>^ resA = gcnew List<String^>();
		List<String^>^ resQ = gcnew List<String^>();
		List<String^>^ resD = gcnew List<String^>();
		List<String^>^ res = gcnew List<String^>();
		Dictionary<String^, List<String^>^>^ Atributes = gcnew Dictionary<String^, List<String^>^>();

		#pragma region Answers
		Atributes->Add("Id", AnswerIds);
		if ( CombineAnswers )
		{
			try
			{
				AnswerList = gcnew Items(AnswerCount);

				AnswerList->TabCount = 0;
				AnswerList->MissFirstTab = MissFirstTab;
				AnswerList->ParentId = AnswerListId;
				AnswerList->AddParentTag = CombineAnswers;

				AnswerList->AddAttributes(Atributes);

				AnswerList->AddText(AnswerText, TextSeparate, !DontClear, IgnoreSpases);
				AnswerList->AddRepeat = AddRepeat;
				AnswerList->RepeatName = RepeatName;
				AnswerList->RepeatText = RepeatText;
				AnswerList->AutoTags = AutoTags;
			}
			catch ( Exception^ e )
			{
				ShowError(109, "Ошибка обработки ответов в Union\nПодробнее:\n" + e->ToString());
			}

			resA = AnswerList->MakeXML();

		}
		else
		{
			try
			{
				answers = gcnew Answers(AnswerCount);

				answers->AddRepeat = AddRepeat;
				answers->RepeatName = RepeatName;
				answers->RepeatText = RepeatText;
				answers->AddPageTag = false;
				answers->AddParentTag = false;
				answers->AddAttributes(Atributes);
				answers->AddText(AnswerText, TextSeparate, !DontClear, IgnoreSpases);
			}
			catch ( Exception^ e )
			{
				ShowError(110, "Ошибка обработки ответов в Union\nПодробнее:\n" + e->ToString());
			}

			resA = answers->MakeXML();
		}

		#pragma endregion

		#pragma region Questions
		List<String^>^ ids = gcnew List<String^>();
		for ( int i = 1; i <= QuestionCount; i++ )
			ids->Add( ((!CombineQuestions) ? (QuestionId + "_") : "") + i.ToString() );
		Atributes = gcnew Dictionary<String^, List<String^>^>();
		Atributes->Add("Id", ids);
		if ( CombineQuestions )
		{
			try
			{
				QuestionList = gcnew Items(QuestionCount);

				QuestionList->TabCount = 0;
				QuestionList->ParentId = QuestionListId;
				QuestionList->AddParentTag = CombineQuestions;

				QuestionList->AddAttributes(Atributes);

				QuestionList->AddText(QuestionText, TextSeparate, !DontClear, IgnoreSpases);
			}
			catch ( Exception^ e )
			{
				ShowError(111, "Ошибка обработки вопросов в Union\nПодробнее:\n" + e->ToString());
			}

			resQ = QuestionList->MakeXML();
		}
		else
		{
			Elements^ questions = gcnew Elements("Question", QuestionCount);
			try
			{
				questions->AddParentTag = false;
				questions->AddAttributes(Atributes);
				questions->AddText(QuestionText, TextSeparate, !DontClear, IgnoreSpases);
			}
			catch ( Exception^ e )
			{
				ShowError(112, "Ошибка обработки вопросов в Union\nПодробнее:\n" + e->ToString());
			}
			
			resQ = questions->MakeXML();
		}
		#pragma endregion

		resD->Add("");

		#pragma region Page
		resD->Add("<Page Id=\"" + QuestionId + "\">");

		if (!String::IsNullOrEmpty(PageHeader)) resD->Add("\t<Header>" + PageHeader + "</Header>");

		// добавление вопросов
		if ( CombineQuestions )
		{
			resD->Add("\t<Repeat List=\"" + QuestionListId + "\">");
			resD->Add("\t\t<Question Id=\"" + QuestionId + "_@ID\" Type=\"" + QuestionType + "\"><Text>@Text</Text></Question>");
			resD->Add("\t</Repeat>");
		}
		else
		{
			for ( int i = 1; i <= QuestionCount; i++)
				resD->Add("\t<Question Id=\"" + QuestionId + "_" + i.ToString() +"\" Type=\"" + QuestionType + "\"><Text>" + QuestionText[i-1] + "</Text></Question>");
		}
		
		// dummy
		String^ qString = "\t<Question Id=\"" + QuestionId + "_dummy\" TextWidth=\"30\"" + DummyAtributes;
		try
		{
			if ( mix == MixType::Mix ) qString += " Mix=\"true\"";
			else if ( mix == MixType::MixId ) qString += " MixId=\"" + MixIdText + "\"";

			if ( unionMix == UnionMixType::UnionMix ) qString += " UnionMix=\"true\"";
			else if ( unionMix == UnionMixType::UnionMixId ) qString += " UnionMixId=\"" + UnionMixIdText + "\"";

			qString += " Union=\"$repeat(" + ((CombineQuestions) ? QuestionListId : QuestionCount.ToString()) + "){" + QuestionId + "_@" + ((CombineQuestions) ? "ID" : "Itera") + "[,]}\">";
			resD->Add(qString);
			if ( DummyExtend ) resD->Add("\t\t<Ui " + Extend + "/>");
		}
		catch ( Exception^ e )
		{
			ShowError(113, "Ошибка обработки dummy вопроса в Union\nПодробнее:\n" + e->ToString());
		}
		
		

		if ( !String::IsNullOrEmpty(DummyHeader) ) resD->Add("\t\t<Header>" + DummyHeader + "</Header>");
		
		// ответы
		try
		{
			if ( CombineAnswers )
			{
				resD->Add("\t\t<Repeat List=\"" + AnswerListId + "\">");
				if ( TextSeparate ) qString = "\t\t\t<Answer Id=\"@ID\"><Text>@Text</Text></Answer>";
				else qString = "\t\t\t<Answer Id=\"@ID\" Text=\"@Text\"/>";
				resD->Add(qString);
				resD->Add("\t\t</Repeat>");
			}
			else
			{
				for ( int i = 0; i < resA->Count; i++ )
					resA[i] = "\t\t" + resA[i];
				resD->AddRange(resA);
			}
		}
		catch ( Exception^ e )
		{
			ShowError(114, "Ошибка обработки ответов в Union\nПодробнее:\n" + e->ToString());
		}

		resD->Add("\t</Question>");
		resD->Add("</Page>");
		#pragma endregion

		try
		{
			if ( CombineQuestions ) res->AddRange(resQ);
			if ( CombineAnswers ) res->AddRange(resA);

			res->AddRange(resD);

			for ( int i = (MissFirstTab) ? 1 : 0; i < res->Count; i++ )
				res[i] = Elements::GetTabs(TabCount) + res[i];
		}
		catch ( Exception^ e )
		{
			ShowError(115, "Ошибка обработки XML\nПодробнее:\n" + e->ToString());
		}

		return res;
	}

};





public ref class QuestionBlock
{
public:
	QuestionBlock(int count)
	{
		AnswerBlock = gcnew Answers(count);
	};
	~QuestionBlock()
	{
	};

	Answers^ AnswerBlock;
	int TabCount = 0;
	String^ QuestionListId = "";
	String^ QuestionId = "";
	UnionMixType UnionMix;
	String^ UnionMixIdText = "";
	Items^ Questions;
	bool MissFirstTab = false;


	List<String^>^ MakeXML()
	{
		AnswerBlock->TabCount = TabCount;
		AnswerBlock->Header = "@Text";
		AnswerBlock->MissFirstTab = Questions->Count == 0 ? MissFirstTab : false;
		String^ res = ListToString(AnswerBlock->MakeXML(), "\n");

		if ( UnionMix == UnionMixType::UnionMix ) um += " Mix=\"true\"";
		else if ( UnionMix == UnionMixType::UnionMixId ) um += " MixId=\"" + UnionMixIdText + "\"";

		int i = res->IndexOf("<Question");
		int k = res->IndexOf("</Question");
		k = res->IndexOf(">", k) + 1;
		String^ tmp = res->Substring(i, k-i);

		res = res->Insert(k, "\n"+ Elements::GetTabs(TabCount + 2) +"</Repeat>");
		res = res->Insert(i, "<Ui Step=\"1\" HeaderFix=\"1\"/>\n" + Elements::GetTabs(TabCount + 2) + "<Repeat List=\"" + QuestionListId + "\""+um+">\n" + Elements::GetTabs(TabCount+3));
		res = res->Replace(tmp, tmp->Replace("\n", "\n\t"));
		QuestionsRes->Add("");
		QuestionsRes->AddRange(StringToList(res, '\n'));
		return QuestionsRes;
	}


	void AddQuestions(List<String^>^ questions, bool SepText, bool clear, bool IgnorSpaces)
	{
		Questions = gcnew Items(questions->Count);
		Dictionary<String^, List<String^>^>^ Atributes = gcnew Dictionary<String^, List<String^>^>;
		List<String^>^ ids = gcnew List<String^>();
		for ( int i = 0; i < questions->Count; i++ )
			ids->Add((i+1).ToString());
		Atributes->Add("Id", ids);
		Questions->AddAttributes(Atributes);
		Questions->TabCount = TabCount;
		Questions->MissFirstTab = MissFirstTab;
		Questions->ParentId = QuestionId + "_QList";
		Questions->AddParentTag = true;
		Questions->VarsEnabled = false;
		Questions->AddText(questions, SepText, clear, IgnorSpaces);
		Questions->AddRepeat = false;
		QuestionsRes = Questions->MakeXML();
	}


	void AddQuestionAttributes(String^ atrs)
	{
		AnswerBlock->AddQuestionAttributes("Id=\"" + QuestionId + "_@ID\"" + atrs + " Hint=\"\"" + (UnionMix == UnionMixType::UnionMixId ? " SyncId=\"@ID\"" : ""));
	}

private:
	List<String^>^ QuestionsRes = gcnew List<String^>();
	String^ um = "";

};






public ref class Settings
{
public:

	Settings::Settings()
	{
	}

	Settings::~Settings()
	{
	}

	void Set(String^ PropName, String^ PropValue)
	{
		if ( reading )
		{
			SettingsList->Clear();
			reading = false;
		}
		SettingsList->Add(PropName, PropValue);
	}

	void Set(String^ PropName, int PropValue)
	{
		if ( reading )
		{
			SettingsList->Clear();
			reading = false;
		}
		SettingsList->Add(PropName, PropValue.ToString());
	}

	bool Save(String^ subKey)
	{
		if ( reading )
		{
			SettingsList->Clear();
			reading = false;
		}
		RegistryKey^ rk;
		try
		{
			rk = Registry::CurrentUser->OpenSubKey("Software", true);
		}
		catch ( Exception^ e )
		{
			if ( !rk ) ShowError(201, "Ошибка доступа к реестру\nПодробнее:\n" + e->ToString());
			return false;
		}

		try
		{
			rk = rk->CreateSubKey("SurveyHelper"); // создаёт или открывает
			if (!String::IsNullOrEmpty(subKey)) rk = rk->CreateSubKey(subKey);
		}
		catch ( Exception^ e )
		{
			if ( !rk )
			{
				ShowError(202, "Ошибка доступа к реестру\nПодробнее:\n" + e->ToString());
				return false;
			}
		}

		try
		{
			for each (KeyValuePair<String^, String^>^ set in SettingsList)
				rk->SetValue(set->Key, set->Value);
		}
		catch (Exception^ e )
		{
			ShowError(203, "Ошибка записи в реестр\nПодробнее:\n" + e->ToString());
			return false;
		}
		rk->Close();
		return true;
	}


	void Clear()
	{
		SettingsList->Clear();
	}

	int Read(String^ subKey)
	{
		if ( !reading )
		{
			SettingsList->Clear();
			reading = true;
		}
		SettingsList = gcnew Dictionary<String^, String^>();
		RegistryKey^ rk = Registry::CurrentUser;
		try
		{
			rk = rk->OpenSubKey("Software", true);
		}
		catch ( Exception^ e )
		{
			if ( !rk )
			{
				ShowError(204, "Ошибка доступа к реестру\nПодробнее:\n" + e->ToString());
				return -1;
			}
		}
		
		try
		{
			rk = rk->CreateSubKey("SurveyHelper");
			if (!String::IsNullOrEmpty(subKey)) rk = rk->OpenSubKey(subKey);
		}
		catch ( Exception^ e )
		{
			if ( !rk )
			{
				ShowError(205, "Ошибка доступа к реестру\nПодробнее:\n" + e->ToString());
				return -1;
			}
		}
		
		if ( !!rk )
			try
			{
				{
					array<String^>^ names = rk->GetValueNames();
					for each (String^ set in names)
						SettingsList->Add(set, rk->GetValue(set)->ToString());
				}
		
			array<String^>^ names = gcnew array<String^>(rk->ValueCount);
			
			}
			catch ( Exception^ e )
			{
				ShowError(206, "Ошибка чтения данных реестра\nПодробнее:\n" + e->ToString());
				return -1;
			}

		return SettingsList->Count;
	}

	//проверяет существование в реестре
	static bool Exist(String^ subKey)
	{
		RegistryKey^ rk;
		try
		{
			rk = Registry::CurrentUser->OpenSubKey("Software");
			rk = rk->OpenSubKey("SurveyHelper");
			rk = rk->OpenSubKey(subKey);
		}
		finally
		{}
		return !!rk;
	}

	// удаляет параметр
	static bool Remove(String^ subKey, String^ setName)
	{
		RegistryKey^ rk = Registry::CurrentUser;
		try
		{
			rk = rk->OpenSubKey("Software", true);
		}
		catch ( Exception^ e )
		{
			if ( !rk )
			{
				ShowError(208, "Ошибка доступа к реестру\nПодробнее:\n" + e->ToString());
				return false;
			}
		}

		try
		{
			rk = rk->CreateSubKey("SurveyHelper");
			if ( !String::IsNullOrEmpty(subKey) ) rk = rk->OpenSubKey(subKey);
		}
		catch ( Exception^ e )
		{
			if ( !rk )
			{
				ShowError(209, "Ошибка доступа к реестру\nПодробнее:\n" + e->ToString());
				return false;
			}
		}

		try
		{
			if ( !(gcnew List<String^>(rk->GetValueNames()))->Contains(setName) ) return true;
			rk->DeleteValue(setName);
		}
		catch ( Exception^ e )
		{
			ShowError(209, "Ошибка доступа к реестру\nПодробнее:\n" + e->ToString());
			return false;
		}
		return true;
	}

	// проверяет настроен ли параметр s
	bool isWritten(String^ s)
	{
		return SettingsList->ContainsKey(s);
	}

	void StartWithWindows(bool st)
	{
		RegistryKey^ rk;
		int i = 0;
		try
		{
			rk = Registry::CurrentUser->OpenSubKey(L"Software", true); i += !!rk;
			rk = rk->OpenSubKey(L"Microsoft", true); i += !!rk;
			rk = rk->OpenSubKey(L"Windows", true); i += !!rk;
			rk = rk->OpenSubKey(L"CurrentVersion", true); i += !!rk;
			rk = rk->OpenSubKey(L"Run", true); i += !!rk;
			if ( st )
			{
				rk->SetValue("SurveyHelper", "\"" + Application::ExecutablePath + "\"");
				i += !!rk;
			}
			else
			{
				i += !!rk;
				rk->DeleteValue("SurveyHelper", false);
			}
		}
		catch ( Exception^ e )
		{
			ShowError(207+i, "Ошибка доступа к реестру\nПодробнее:\n" + e->ToString()); // 207 ... 214
		}
	}

	String^ Get(String^ ValName)
	{
		if ( !reading )
		{
			SettingsList->Clear();
			reading = true;
		}
		if ( !SettingsList->ContainsKey(ValName) ) return "";
		return SettingsList[ValName];
	}

	int Get(String^ ValName, bool toInt)
	{
		if ( !reading )
		{
			SettingsList->Clear();
			reading = true;
		}
		if ( toInt ) return StrToInt(Get(ValName));
		else return -1;
	}

private:
	Dictionary<String^, String^>^ SettingsList = gcnew Dictionary<String^, String^>();
	bool reading;
};








// класс для добавления фишек из библиотеки кода
public ref class Addon
{
public:
	Addon::Addon(String^ filePath)
	{
		FileContent = ListToString(ReadFile(filePath), Environment::NewLine);
	}

	Addon::~Addon()
	{
	}

	bool GetTags(List<String^>^ tree)
	{
		List<AddonTag^>^ res = gcnew List<AddonTag^>();
		AddonTag^ t;
		if ( tree == nullptr || tree->Count < 1 ) return false;
		
		String^ cont = FileContent;
		String^ tp = "";
		int i = 0;
		try
		{
			// содержание тэга tree
			for each (String^ s in tree)
			{
				if ( cont->Contains("<" + s) && cont->Contains("</" + s) )
				{
					cont = cont->Remove(0, cont->IndexOf("<" + s));
					cont = cont->Remove(0, cont->IndexOf(">") + 1);
					cont = cont->Remove(cont->IndexOf("</" + s));
				}
				else break;
			}

			if ( cont == FileContent || String::IsNullOrEmpty(cont) ) return false;

			// получение данных
			int pos = cont->IndexOf("<");
			String^ tag = cont->Remove(0, pos + 1);
			tag = tag->Remove(Min(tag->IndexOf(">"), tag->IndexOf(" ")));
			String^ tmp;
			int k;
			while ( pos > -1 )
			{
				t = gcnew AddonTag();
				t->Name = tag;
				// body1
				tmp = cont->Remove(0, pos);
				tmp = tmp->Remove(tmp->IndexOf(">", tmp->IndexOf("</" + tag)) + 1);
				t->Boody = tmp->Remove(0, tmp->IndexOf(">"));
				t->Boody = t->Boody->Remove(0, t->Boody->IndexOf("<"));
				t->Boody = t->Boody->Remove(t->Boody->LastIndexOf("<"));
				//title

				if ( tmp->IndexOf(" Title") <  tmp->IndexOf(">") )
				{
					tmp = tmp->Remove(0, tmp->IndexOf(" ") + 1);
					tmp = tmp->Remove(0, tmp->IndexOf("\"") + 1);
					tmp = tmp->Remove(tmp->IndexOf("\""));
				}
				else tmp = "";
				t->Title = tmp;

				res->Add(t);

				k = cont->IndexOf("</" + tag);
				pos = cont->IndexOf("<", k + 1);
				if ( pos < 0 ) break;
				tag = cont->Remove(0, pos + 1);
				tag = tag->Remove(Min(tag->IndexOf(">"), tag->IndexOf(" ")));
			}
		}
		catch ( Exception^ e )
		{
			ShowError(416, "Ошибка при работе с библиотекой дополнительных возможностей\n\nПодробнее:\n" + e->ToString());
			return false;
		}

		CurrentTags = res;
		Count = CurrentTags->Count;
		return true;
	}




	bool Contains(String^ tag)
	{
		if ( CurrentTags->Count < 1 ) return false;

		for each (AddonTag^ a in CurrentTags)
			if ( a->Name == tag ) return true;

		return false;
	}


	/*List<String^>^ GetTagNames()
	{
		List<String^>^ res = gcnew List<String^>();
		if ( CurrentTags == nullptr || CurrentTags->Count < 1 ) return res;
		for each (AddonTag^ a in CurrentTags)
			res->Add(a->Name);
		return res;
	}
	

	String^ GetBody(String^ s)
	{
		String^ res = "";

		for each (AddonTag^ a in CurrentTags)
			if ( a->Name == s ) return a->Boody;

		return res;
	}


	String^ GetBodyByTitle(String^ title)
	{
		String^ res = "";

		for each (AddonTag^ a in CurrentTags)
			if ( a->Title == title ) return a->Boody;

		return res;
	}
	

	String^ GetTitle(String^ s)
	{
		String^ res = "";
		for each (AddonTag^ a in CurrentTags)
			if ( a->Name == s ) return a->Title; 

		return res;
	}*/


	List<AddonTag^>^ GetTagList()
	{
		return gcnew List<AddonTag^>(CurrentTags);
	}


	static Dictionary<String^, String^>^ FindAddons(AddonTag^ t)
	{
		Dictionary<String^, String^>^ res = gcnew Dictionary<String^, String^>();

		if ( String::IsNullOrEmpty(t->Boody) ) return res;
		try
		{
			String^ tmp = t->Boody;
			String^ name = "";
			String^ body = "";
			tmp = tmp->Remove(0, tmp->IndexOf("<"));
			tmp = tmp->Remove(tmp->LastIndexOf(">") + 1);
			int Pos = tmp->IndexOf("<");
			int a;
			while ( Pos > -1 )
			{
				body = tmp->Remove(0, Pos);
				tmp = tmp->Remove(0, Pos + 1);
				name = tmp->Remove(Min(tmp->IndexOf(">"), tmp->IndexOf(" ")));
				a = body->IndexOf(">", body->IndexOf("</" + name));
				if ( a < body->Length - 1 )
					body = body->Remove(a + 1);
				res->Add(name, body);
				tmp = tmp->Remove(0, tmp->IndexOf(">") + 1);
				a = tmp->IndexOf(">", tmp->IndexOf("</" + name));
				if ( a < tmp->Length - 1 ) tmp = tmp->Remove(0, a + 1);
				else tmp = "";
				Pos = tmp->IndexOf("<");
			}
		}
		catch ( Exception ^e )
		{
			ShowError(415, "Ошибка при работе с библиотекой дополнительных возможностей\n\nПодробнее:\n" + e->ToString());
		}
		
		return res;
	}


public: 
	int Count = 0;

private:
	String^ FileContent = "";
	List<AddonTag^>^ CurrentTags = gcnew List<AddonTag^>();
};
