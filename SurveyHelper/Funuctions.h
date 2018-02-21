#pragma once


using namespace System;
using namespace System::Windows;
using namespace System::Windows::Forms;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace System::ComponentModel;
using namespace System::Text::RegularExpressions;
using namespace Microsoft::Office::Interop;
using namespace System::Runtime::Serialization;
using namespace System::Runtime::Serialization::Formatters::Binary;


static String^ ClearString(String^ str, bool TrimString, bool DelNums, bool ignorSpace, bool afterScreen);
static String^ ClearString(String^ str, bool TrimString, bool DelNums, bool ignorSpace);
static int Min(int a, int b);
static int CountSubStrings(String^ source, String^ sub);
static String^ ListToString(List<String^>^ str, String^ devide);



// Сортировка строк по убыванию длины
public ref class StringLengthDesc : System::Collections::Generic::IComparer<String^>
{
	public:
	// Сортировка строк по убыванию длины
	StringLengthDesc()
	{};

	~StringLengthDesc()
	{};

	virtual int Compare(String^ x, String^ y)
	{
		if (x == nullptr)
			if (y == nullptr)
				return 0;
			else
				return 1;

		if (y == nullptr) return -1;
		return y->Length.CompareTo(x->Length);
	}
};



// Сортировка строк по возрастанию длины
public ref class StringLengthAsc : System::Collections::Generic::IComparer<String^>
{
	public:
	// Сортировка строк по возрастанию длины
	StringLengthAsc()
	{};
	~StringLengthAsc()
	{};

	virtual int Compare(String^ y, String^ x)
	{
		if (x == nullptr)
			if (y == nullptr)
				return 0;
			else
				return 1;

		if (y == nullptr) return -1;
		return y->Length.CompareTo(x->Length);
	}
};



// сортировка строк таблицы по длине строки в ячейке
public ref class DataGridViewColumnSort : System::Collections::IComparer
{
	public:
	DataGridViewColumnSort()
	{ }
	DataGridViewColumnSort(int columnIndex, ListSortDirection direction)
	{
		ColumnIndex = columnIndex;
		Direction = direction;
	}
	~DataGridViewColumnSort()
	{ }

	int ColumnIndex = 0;
	ListSortDirection Direction = ListSortDirection::Descending;

	virtual int Compare(Object^ x, Object^ y)
	{
		DataGridViewRow^ Row1 = (DataGridViewRow^)x;
		DataGridViewRow^ Row2 = (DataGridViewRow^)y;
		if (Direction == ListSortDirection::Ascending)
		{
			Row1 = (DataGridViewRow^)y;
			Row2 = (DataGridViewRow^)x;
		}
		if (Row1->Cells->Count <= ColumnIndex || Row1->Cells[ColumnIndex]->Value == nullptr)
			if (Row2->Cells->Count <= ColumnIndex || Row2->Cells[ColumnIndex]->Value == nullptr)	return 0;
			else return 1;
			if (Row2->Cells->Count <= ColumnIndex || Row2->Cells[ColumnIndex]->Value == nullptr)	return -1;
			return Row2->Cells[ColumnIndex]->Value->ToString()->Length.CompareTo(Row1->Cells[ColumnIndex]->Value->ToString()->Length);
	}
};



public ref struct HeaderList
{
	HeaderList()
	{
		OldHeaders = gcnew List<String^>();
		NewHeaders = gcnew List<String^>();
	}

	~HeaderList()
	{

	}

	int Completed = 0;
	int Count = 0;
	List<String^>^ OldHeaders;
	List<String^>^ NewHeaders;
};


// результаты проверки на недопустимые символы
public ref struct CheckSyntaxResult
{
	public:
	int AddError(String^ text, int line)
	{
		if (!LineNums->Contains(line))
		{
			LineNums->Add(line);
			Count++;
		}
		Errors->Add(text);
		return Count;
	}

	List<String^> ^NewLines = gcnew List<String^>();
	List<String^> ^Errors = gcnew List<String^>();
	List<int> ^LineNums = gcnew List<int>();
	int Count = 0;
};


//возвращает Int32::TryParse 
static bool IsNumber(String^ s)
{
	int a;
	return Int32::TryParse(s, a);
}

static void ShowMessage(String^ cap, String^ txt)
{
	System::Windows::Forms::MessageBox::Show(txt, cap, System::Windows::Forms::MessageBoxButtons::OK,
		System::Windows::Forms::MessageBoxIcon::Information);
}

static void ShowMessage(String^ txt)
{
	System::Windows::Forms::MessageBox::Show(txt, "", System::Windows::Forms::MessageBoxButtons::OK,
		System::Windows::Forms::MessageBoxIcon::Information);
}

static void ShowMessage(int num)
{
	ShowMessage(num.ToString());
}

static void ShowMessage(bool b)
{
	ShowMessage(b.ToString());
}

static void ShowMessage(String^ txt, System::Windows::Forms::MessageBoxIcon icon)
{
	System::Windows::Forms::MessageBox::Show(txt, "", System::Windows::Forms::MessageBoxButtons::OK,
		icon);
}


static void ShowMessage(String^ cap, String^ txt, System::Windows::Forms::MessageBoxIcon icon)
{
	System::Windows::Forms::MessageBox::Show(txt, cap, System::Windows::Forms::MessageBoxButtons::OK,
		icon);
}

static void ShowError(int num, String^ txt)
{
	System::Windows::Forms::MessageBox::Show(txt, "Ошибка №" + num.ToString(), System::Windows::Forms::MessageBoxButtons::OK,
		System::Windows::Forms::MessageBoxIcon::Error);
}

static void ShowWarning(String^ txt)
{
	System::Windows::Forms::MessageBox::Show(txt, "", System::Windows::Forms::MessageBoxButtons::OK,
		System::Windows::Forms::MessageBoxIcon::Warning);
}


// наличие цифры в строке
static bool ContainsNumber(String^str)
{
	for (int i = 0; i <= 9; i++)
		if (str->Contains(i.ToString())) return true;
	return false;
}


// поиск начала строки, не являющегося номером
static bool FakeFound(String^ str)
{
	String^ s = str->Trim();

	if (s->Contains("\t")) return false;

	int i = Min(s->IndexOf("."), s->IndexOf(")"));
	i = Min(i, s->IndexOf(" "));

	if (i < 0 || i >= s->Length - 1) return true;
	if (IsNumber(s[i + 1].ToString())) return true;
	s = s->Remove(i);
	if (!ContainsNumber(s)) return true;

	System::Text::RegularExpressions::Regex^  r = gcnew System::Text::RegularExpressions::Regex("^\\W*\\d+\\s?[-–]?\\s?\\d+.*");
	System::Text::RegularExpressions::Regex^ rv = gcnew System::Text::RegularExpressions::Regex("^\\W*\\d+\\s?\\W*\\w+");
	return r->Match(str)->Success && !rv->Match(str)->Success;
}


// возвращает меньшее из двух положительных, или большее, если хотя бы одно отрицательное
static int Min(int a, int b)
{
	if (a == b) return a;

	int c = (a < b) ? a : b;

	if (c >= 0) return c;
	else return (a > b) ? a : b;
}

// проверка на недопустимые символы
static CheckSyntaxResult^ CheckSyntax(List<String^>^ Strings)
{
	CheckSyntaxResult^ res = gcnew CheckSyntaxResult();

	Dictionary<String^, String^>^ ValidateChars = gcnew Dictionary<String^, String^>();
	ValidateChars->Add("<", "lt;");
	ValidateChars->Add(">", "gt;");
	ValidateChars->Add("&", "amp;");

	String^ tmp;
	int i, n = 0;
	try
	{
		for each (String^ str in Strings)
		{
			n++;
			tmp = "";
			i = 0;
			while (i < str->Length)
			{
				if (ValidateChars->ContainsKey(str[i].ToString()))
				{
					tmp += ValidateChars[str[i].ToString()];
					res->AddError("В строке " + n.ToString() + " найден недопустимый символ \"" + str[i] + "\"", n);
					i++;
				}
				else
				{
					tmp += str[i];
					i++;
				}
			}
			res->NewLines->Add(tmp);
		}
	}
	catch (Exception^ e)
	{
		ShowError(401, "Ошибка разбора строки.\n\nПодробнее\n" + e->ToString());
	}
	return res;
}

// проверка на недопустимые символы
static CheckSyntaxResult^ CheckSyntax(String^ str)
{
	CheckSyntaxResult^ res = gcnew CheckSyntaxResult();

	Dictionary<String^, String^>^ ValidateChars = gcnew Dictionary<String^, String^>();
	ValidateChars->Add("<", "lt;");
	ValidateChars->Add(">", "gt;");
	ValidateChars->Add("&", "amp;");

	String^ tmp = "";
	int i = 0, n = 1;

	try
	{
		while (i < str->Length)
		{
			if (ValidateChars->ContainsKey(str[i].ToString()))
			{
				tmp += ValidateChars[str[i].ToString()];
				res->AddError("В строке " + n.ToString() + " найден недопустимый символ \"" + str[i] + "\"", n);
				i++;
			}
			else
			{
				tmp += str[i];
				i++;
			}
		}
	}

	catch (Exception^ e)
	{
		ShowError(402, "Ошибка разбора строки.\n\nПодробнее\n" + e->ToString());
	}
	res->NewLines->Add(tmp);

	return res;
}


// безопасные символы
static String^ Translate(String^ str)
{
	if (String::IsNullOrEmpty(str)) return str;
	String^ rus = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
	rus += rus->ToLower();
	String^ ValidChars = "qwertyuiopasdfghjklzxcvbnm";
	ValidChars += ValidChars->ToUpper() + "@_0123456789";
	String^ res = "";

	array<String^>^ eng = {
		"A", "B", "V", "G", "D", "E", "Yo", "Zh", "Z", "I", "Y", "K", "L", "M", "N", "O", "P",
		"R", "S", "T", "U", "F", "H", "Ts", "Ch", "Sh", "Shch", "", "I", "", "E", "Yu", "Ya" };

	try
	{
		for (int i = 0; i < str->Length; i++)
		{
			if (ValidChars->Contains(str[i].ToString()))
			{
				res += str[i];
				continue;
			}

			int p = rus->IndexOf(str[i]);
			if (p > -1)
				if (p > 32)
					res += eng[p - 33]->ToLower();
				else
					res += eng[p];
			else
				res += "_";
		}
	}
	catch (Exception^ e)
	{
		ShowError(403, "Ошибка разбора строки.\n\nПодробнее\n" + e->ToString());
	}


	// очистка лишних _
	int i = 0;
	try
	{
		while (i < res->Length - 1)
		{
			if ((res[i] == '_') && (res[i + 1] == '_'))
				res = res->Remove(i, 1);
			else
				i++;
		}
		if (res[res->Length - 1] == '_') res = res->Remove(res->Length - 1);
		if (res[0] == '_') res = res->Remove(0, 1);
	}
	catch (Exception^ e)
	{
		ShowError(404, "Ошибка разбора строки.\n\nПодробнее\n" + e->ToString());
	}

	return res;
}


// транслит-замена символов
static String^ ImprovePropertyLanguage(String^ s)
{
	String^ rus = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
	rus += rus->ToLower();
	String^ eng = "ABBGDEEZZIYKLMHOPPCTYFXCCSSQQQAUA";
	eng += eng->ToLower();
	String^ res = "";
	String^ tmp = "";
	for (int i = 0; i < s->Length; i++)
	{
		tmp = s[i].ToString();
		if (rus->Contains(tmp))
			res += eng[rus->IndexOf(tmp)];
		else
			if (!Regex::IsMatch(tmp, "^[\\d_A-Za-z@]$")) res += "_";
			else res += s[i];
	}

	return res;
}

// поиск Redirect
static List<int>^ GetScreenIds(List<String^>^ strl)
{
	array<String^>^ screen = { "закончить", "окончание", "конец", "завершить", "скрин", "screen", "close" };
	array<String^>^ separator = { " ", "_", ".", "-" };
	String^ s;
	List<int>^ res = gcnew List<int>();
	bool a = false;
	int i = 0;

	String^ lst = ListToString(strl, " ")->ToLower();
	if (CountSubStrings(lst, "продолжить") > 1 || CountSubStrings(lst, "\tпродолжить") > 0 || CountSubStrings(lst, "continue") > 1 || CountSubStrings(lst, "\tcontinue") > 0)
	{
		for (int i = 0; i < strl->Count; i++)
			if (!strl[i]->ToLower()->Contains("продолжить"))
				res->Add(i);
		return res;
	}
	for each (String^ str in strl)
	{
		// если есть табуляция
		if (CountSubStrings(str, "\t") > 0)
		{
			int k = str->LastIndexOf("\t");
			s = str->Remove(0, k + 1)->ToLower();
			a = false;
			for (int j = 0; j < screen->Length; j++)
				if (s->Contains(screen[j])) a = true;
		}
		else
		{
			for (int j = 0; j < separator->Length; j++)
			{
				s = separator[j] + separator[j];
				if (str->Contains(s))
				{
					for (int k = 0; k < screen->Length; k++)
						if (s->Contains(screen[k]))
						{
							a = true;
							break;
						}
				}
			}
		}
		if (a) res->Add(i);
		i++;
		a = false;
	}

	return res;
}

// очистка слов типа "ЗАКОНЧИТЬ" (только пост)
static List<String^>^ ClearScreenWords(List<String^>^ strl/*, List<int>^ screenIds*/)
{
	List<String^>^ res = gcnew List<String^>();
	try
	{
		for (int i = 0; i < strl->Count; i++)
			res->Add(ClearString(strl[i], true, false, true, true));
	}
	catch (Exception^ e)
	{
		ShowError(417, "Ошибка при очистке текста элементов от ключевых слов для скринаута.\n\nПодробнее:\n" + e->ToString());
	}
	return res;
}



// удаляет начальные и конечные пробелы и нумерацию
static String^ ClearString(String^ str, bool TrimString, bool DelNums, bool ignorSpace, bool afterScreen)
{
	String^ res = str;

	/*if ( TrimString )
		while ( CountSubStrings(res, "\t") > 1 )
			res = res->Remove(res->LastIndexOf("\t"));*/

	if (TrimString) res = res->Trim();

	if (DelNums)
	{
		if (!FakeFound(res))
		{
			String^ l = res;
			try
			{

				int i = res->IndexOf('\t');

				// если есть табуляция
				if (i > 0 && i < res->Length - 1)
				{
					String
						^prev = res->Remove(i),
						^post = res->Remove(0, i + 1);
					if (IsNumber(prev) || !IsNumber(post) && ContainsNumber(prev) && Regex::IsMatch(post, "\\w")) res = post;
					else if (IsNumber(post) || !IsNumber(prev) && ContainsNumber(post) && Regex::IsMatch(prev, "\\w")) res = prev;
				}
				else
					// остальное только при преднумерации
				{
					i = res->IndexOf('.');
					if (i < res->Length - 1 && i > 0) l = res->Remove(i);
					if (!l->Contains(" ") && ContainsNumber(l))
					{
						res = res->Remove(0, i + 1);
						goto found;
					}

					i = res->IndexOf(')');
					if (i > 0) l = res->Remove(i);
					if (!l->Contains(" ") && ContainsNumber(l))
					{
						res = res->Remove(0, i + 1);
						goto found;
					}

					if (!ignorSpace)
					{
						i = res->IndexOf(' ');
						if (i > 0) l = res->Remove(i);
						if (ContainsNumber(l) && !FakeFound(str))
							res = res->Remove(0, i + 1);
					}

				}
			}
			catch (Exception^ e)
			{
				ShowError(405, "Ошибка разбора строки.\n\nПодробнее\n" + e->ToString());
			}
		}
		/*else
		{
			if ( str->Contains(")") )
			{
				String^ a = str->Remove(str->IndexOf(")"));
				if ( !a->Contains("(") && a->Length < 8 )
					res = str->Remove(0, str->IndexOf(")")+1);
			}
		}*/
	}
	else if (afterScreen)
	{
		// очистка всего после первого \t
		int i = str->IndexOf('\t');
		if (i > 0)
		{
			res = str->Remove(i);
		}
	}

found:
	if (TrimString) res = res->Trim();
	return res;
}

static String^ ClearString(String^ str, bool TrimString, bool DelNums, bool ignorSpace)
{
	return ClearString(str, TrimString, DelNums, ignorSpace, false);
}

// копирование в буфер обмена
static void CopyToBuffer(List<String^>^ lst)
{
	String^ txt = "";
	try
	{
		for each (String^ s in lst)
			txt += s + "\n";

		if (String::IsNullOrEmpty(txt)) return;
		Clipboard::SetText(txt);
	}
	catch (Exception^ e)
	{
		ShowError(406, "Ошибка копирования в буфер обмена.\n\nПодробнее\n" + e->ToString());
	}
}


// копирование в буфер обмена
static void CopyToBuffer(String^ lst)
{
	try
	{
		if (String::IsNullOrEmpty(lst)) return;
		Clipboard::SetText(lst);
	}
	catch (Exception^ e)
	{
		ShowError(406, "Ошибка копирования в буфер обмена.\n\nПодробнее\n" + e->ToString());
	}
}


// возвращает из строки только [\d-]
static int StrToInt(String^ str)
{
	int res;
	String^ tmp = "";
	try
	{
		for (int i = 0; i < str->Length; i++)
			if (((char)str[i] <= '9' && (char)str[i] >= '0') || str[i] == '-') tmp += str[i];
		if (!Int32::TryParse(tmp, res)) res = -1;
	}
	catch (Exception^ e)
	{
		ShowError(407, "Ошибка разбора строки.\n\nПодробнее\n" + e->ToString());
	}

	return res;
}


// выделение нумерации Answer/Item
static int GetId(String^ s, bool ignorSpace)
{
	if (s == nullptr || String::IsNullOrEmpty(s) || FakeFound(s)) return -1;
	String^ res = s;
	String^ l = res;
	try
	{
		// если есть табуляция
		int i = res->IndexOf('\t');
		if (i > 0 && i < res->Length - 1)
		{
			/*if ( i <= Math::Round(res->Length / 2) ) res = res->Remove(i);
			else res = res->Remove(0, i + 1);
			*/
			String
				^prev = res->Remove(i),
				^post = res->Remove(0, i + 1);
			if (IsNumber(prev) || !IsNumber(post) && ContainsNumber(prev) && !FakeFound(prev)) res = prev;
			else if (IsNumber(post) || !IsNumber(prev) && ContainsNumber(post) && !FakeFound(post)) res = post;
			goto found;
		}
		else
			// остальное только при преднумерации
		{
			i = res->IndexOf(".");
			if (i < res->Length - 1 && i > 0)
			{
				l = res->Remove(i);
				if (ContainsNumber(l))
				{
					res = l;
					goto found;
				}
			}

			i = res->IndexOf(")");
			if (i > 0)
			{
				l = res->Remove(i);
				if (ContainsNumber(l))
				{
					res = l;
					goto found;
				}
			}

			if (ignorSpace) return -1;
			i = res->IndexOf(' ');
			if (i > 0)
			{
				l = res->Remove(i);
				if (ContainsNumber(l))
				{
					res = l;
					goto found;
				}
			}

		}
		return -1;
	}
	catch (Exception^ e)
	{
		ShowError(408, "Ошибка при выделении нумерации элемента.\n\nПодробнее\n" + e->ToString());
	}

found:
	res = ClearString(res, true, false, false);
	return StrToInt(res);
}


// выделение нумерации Question
static String^ GetQuestionId(String^ s)
{
	if (s == nullptr || String::IsNullOrEmpty(s)) return "";
	String^ res = ClearString(s, true, false, false);

	try
	{
		int i = Min(res->IndexOf('\t'), res->IndexOf(' '));

		i = Min(i, res->IndexOf('.'));

		if (i > 0) res = res->Remove(i);
		else return "";

		if (!ContainsNumber(res)) return "";

		if (res[res->Length - 1] == '.') res = res->Remove(res->Length - 1);
	}
	catch (Exception^ e)
	{
		ShowError(409, "Ошибка при выделении нумерации вопроса.\n\nПодробнее\n" + e->ToString());
	}

	return res;
}


// возвращает строку с первой заглавной буквой
static String^ RiseFirstLetter(String^ s)
{
	if (s == nullptr || s->Length < 2) return s;
	String^ str = s;
	String ^res;
	str = str->ToUpper();
	try
	{
		res = str->Remove(1, str->Length - 1) + s->Remove(0, 1);
	}
	catch (Exception^ e)
	{
		ShowError(410, "Ошибка при разборе строки.\n\nПодробнее\n" + e->ToString());
	}

	return res;
}



static array<String^>^ ReadFile(String^ FilePath)
{
	array<String^>^ ar;
	try
	{
		ar = File::ReadAllLines(FilePath, System::Text::Encoding::GetEncoding(1251));
	}
	catch (Exception^ e)
	{
		ShowError(215, "Ошибка при чтении файла.\n\nПодробнее\n" + e->ToString());
	}
	return ar;
}


static bool WriteFile(String^ FileName, array<String^>^ Str)
{
	try
	{
		File::WriteAllLines(FileName, Str, System::Text::Encoding::GetEncoding(1251));
	}
	catch (Exception^ e)
	{
		ShowError(216, "Ошибка при записи файла.\n\nПодробнее\n" + e->ToString());
		return false;
	}

	return true;
}


static bool WriteFile(String^ FileName, array<String^>^ Str, System::Text::Encoding^ enc)
{
	try
	{
		File::WriteAllLines(FileName, Str, enc);
	}
	catch (Exception^ e)
	{
		ShowError(216, "Ошибка при записи файла.\n\nПодробнее\n" + e->ToString());
		return false;
	}

	return true;
}


// если файл с именем FileName уже существует, то он перемещается в FileName + bactxt (старый заменяется)
static bool WriteFile(String^ FileName, array<String^>^ Str, String^ bactxt)
{
	if (File::Exists(FileName)) File::Copy(FileName, FileName + bactxt, true);
	return WriteFile(FileName, Str);
}




// возвращает количество вхождений
static int CountSubStrings(String^ source, String^ sub)
{
	int i = source->IndexOf(sub), k = 0;
	while (i >= 0)
	{
		i += sub->Length;
		i = source->IndexOf(sub, i);
		k++;
	}
	return k;
}



static String^ ListToString(List<String^>^ str, String^ devide)
{
	if (str == nullptr || str->Count < 1) return "";
	String^ res = "";
	for each (String^ s in str)
	{
		res += s;
		res += devide;
	}
	try
	{
		res = res->Remove(res->LastIndexOf(devide));
	}
	catch (Exception^ e)
	{
		ShowError(411, "Ошибка при разборе строки.\n\nПодробнее\n" + e->ToString());
	}

	return res;
}


static String^ ListToString(List<int>^ str, String^ devide)
{
	if (str == nullptr || str->Count < 1) return "";
	String^ res = "";
	for each (int s in str)
	{
		res += s.ToString();
		res += devide;
	}
	try
	{
		res = res->Remove(res->LastIndexOf(devide));
	}
	catch (Exception^ e)
	{
		ShowError(411, "Ошибка при разборе строки.\n\nПодробнее\n" + e->ToString());
	}

	return res;
}


static List<String^>^ StringToList(String^ str, Char separator)
{
	return gcnew List<String^>(str->Split(separator));
}

//выделение части строки
static String^ TakePart(String^ s, int from, int to)
{
	if (from > to || s == nullptr) return "";
	/*array<wchar_t>^ destination = gcnew array<wchar_t>(to - from+1);
	s->CopyTo(from, destination, 0, to - from);
	return gcnew String(destination);*/
	return s->Remove(to)->Remove(0, from);
}


// удаление Id из заголовков вопрсов
static HeaderList^ RemoveHeaders(String^ FilePath)
{
	List<String^>^ fStr = gcnew List<String^>(ReadFile(FilePath));
	String^ s = ListToString(fStr, "\n");
	HeaderList^ res = gcnew HeaderList();
	String^ CompStr;

	if (s == nullptr || s->Length < 10) return res;

	int i = 0;
	int j;

	try
	{
		while ((i = s->IndexOf("<Header>", i)) > -1)
		{
			res->Count = res->Count + 1;

			i += 8;
			j = 0;
			while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
				i++;

			j = Min(s->IndexOf(" ", i + 1), s->IndexOf("\t", i + 1));
			j = Min(j, s->IndexOf(".", i + 1));

			while (s[j + 1] == ' ' || s[j + 1] == '\t')
				j++;


			if (j - i > 10 || !ContainsNumber(TakePart(s, i, j)) || TakePart(s, i, j)->Contains("@")) continue;

			// сохранение от <Header> до </Header>
			CompStr = s->Remove(s->IndexOf("</Header>", i));
			CompStr = CompStr->Remove(0, i);
			res->OldHeaders->Add(CompStr);

			// сохранение нового <Header>
			CompStr = s->Remove(0, j + 1);
			CompStr = CompStr->Remove(CompStr->IndexOf("</Header>"));
			res->NewHeaders->Add(CompStr);
			s = s->Remove(i, j - i + 1);
			res->Completed = res->Completed + 1;
		}
	}
	catch (Exception^ e)
	{
		ShowError(412, "Ошибка при разборе строки.\n\nПодробнее\n" + e->ToString());
	}

	if (res->Completed > 0)
	{
		array<wchar_t>^ a = { '\n' };
		if (s->Split(a)->Length < fStr->Count - 1)
			ShowWarning("В ходе проверки целостности файла была обнаружена ошибка.\nФайл остался в исходном состоянии.");
		else
			WriteFile(FilePath, s->Split(a), ".Headers.bak");
	}

	return res;
}


static void setExcelRange(array<String^>^ data, Excel::Worksheet^ sheet, wchar_t delimiter)
{
	int rows = data->Length;
	int columns = data[0]->Split(delimiter)->Length;
	array<Object^, 2>^ objData = gcnew array<Object^, 2>(rows, columns);
	array<String^>^ line;
	for (int row = 0; row < rows; row++)
	{
		line = data[row]->Split(delimiter);
		for (int column = 0; column < columns; column++)
		{
			objData[row, column] = line[column];
		}
	}

	Excel::Range^ startCell = (Excel::Range^)sheet->Cells[1, 1];
	Excel::Range^ endCell = (Excel::Range^)sheet->Cells[rows, columns];
	Excel::Range^ writeRange = sheet->Range[startCell, endCell];

	writeRange->Value2 = objData;
}


static bool ExportToExcel(array<String^>^ lines, String^ FilePath)
{
	try
	{
		Excel::Application^ exApp = gcnew Excel::ApplicationClass();
		Excel::Workbook^ book = exApp->Workbooks->Add(Type::Missing);
		Excel::Worksheet^ sheet = (Excel::Worksheet^)book->Sheets[1];
		Object^ misValue = System::Reflection::Missing::Value;
		array<String^>^ cells;

		setExcelRange(lines, sheet, '\t');
		book->SaveAs(FilePath, Excel::XlFileFormat::xlExcel12, misValue, misValue, misValue, misValue, Excel::XlSaveAsAccessMode::xlShared, misValue, misValue, misValue, misValue, misValue);
		book->Close(false, FilePath, false);
	}
	catch (Exception^ e)
	{
		ShowError(424, "Ошибка сохранения файла в формате xls\nПодробнее:\n\n" + e->ToString());
		return false;
	}
	return true;
}


static String^ ReadExcelFile(String^ filePath)
{
	String^ res = "";

	try
	{
		Excel::Application^ exApp = gcnew Excel::ApplicationClass();
		Excel::Workbook^ book = exApp->Workbooks->Open(filePath, Type::Missing, Type::Missing, Type::Missing, Type::Missing, Type::Missing, Type::Missing, Type::Missing, Type::Missing, Type::Missing, Type::Missing, Type::Missing, Type::Missing, Type::Missing, Type::Missing);
		Excel::Worksheet^ sheet = (Excel::Worksheet^)book->Sheets[1];
		Excel::Range^ range = (Excel::Range^)sheet->UsedRange;
		auto values = safe_cast<array<Object^, 2>^>(range->Value2);
		int NumRow = values->GetLength(0);
		int NumCols = values->GetLength(1);
		array<String^>^ tmpC = gcnew array<String^>(NumCols);
		array<String^>^ tmpR = gcnew array<String^>(NumRow);
		int r = 1;
		while (r <= NumRow)
		{
			for (int c = 1; c <= NumCols; c++)
			{
				tmpC[c - 1] = values[r, c] == nullptr ? "" : values[r, c]->ToString();
			}
			tmpR[r - 1] = String::Join("\t", tmpC);
			r++;
		}
		res = String::Join("\n", tmpR);
		book->Close(false, filePath, Type::Missing);
	}
	catch (Exception^ e)
	{
		ShowError(430, "Ошибка при чтении файла\nПодробнее:\n\n" + e->ToString());
	}
	return res;
}


// очищает текст от лишних символов
static String^ CleanText(String^ str)
{
	if (String::IsNullOrEmpty(str)) return "";

	String^ validu = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯQWERTYUIOPASDFGHJKLZXCVBNM";
	String^ valid = validu + validu->ToLower() + "*()@.,:;–-№?!\"/'+ 1234567890\t\n";
	String^ res, ^s;
	String^ noRepeat = "/\\-–";

	try
	{
		for (int i = 0; i < str->Length; i++)
		{
			s = str[i].ToString();

			// исправление повторов
			if (i > 0 && noRepeat->Contains(s) && str[i - 1].ToString() == s)
			{
				s = "";
				goto ok;
			}

			if (!valid->Contains(s)) s = "";
		ok:
			res += s;
		}

		// исправление UPCASE
		if (Regex::IsMatch(res, "^[A_ZА_Я\\W]$"))
			res = RiseFirstLetter(res->ToLower());
	}
	catch (Exception^ e)
	{
		ShowError(413, "Ошибка удаления символов\n\nПодробнее\n" + e->ToString());
	}

	return res;
}


// очищает текст от лишних символов
static List<String^>^ CleanText(List<String^>^ strs)
{
	if (strs == nullptr || strs->Count < 1) return gcnew List<String^>();
	List<String^>^ res = gcnew List<String^>();
	for each (String^ s in strs)
	{
		res->Add(CleanText(s));
	}
	return res;
	//res->Sort();
}


static void Run(String^ Path, String^ args)
{
	if (File::Exists(Path))
		Diagnostics::Process::Start(Path, args);
}

static void Run(String^ Path)
{
	if (File::Exists(Path))
		Diagnostics::Process::Start(Path);
}

static String^ GetDefaultBrowserPath()
{
	try
	{
		String^ pId = Microsoft::Win32::Registry::CurrentUser->OpenSubKey("Software\\Microsoft\\Windows\\Shell\\Associations\\UrlAssociations\\http\\UserChoice", false)->GetValue("ProgId")->ToString();
		return Microsoft::Win32::Registry::ClassesRoot->OpenSubKey(pId + "\\shell\\open\\command", false)->GetValue("")->ToString()->Split(gcnew array<wchar_t> { '"' })[1];
	}
	catch (Exception^ e)
	{
		return Microsoft::Win32::Registry::ClassesRoot->OpenSubKey("http\\shell\\open\\command", false)->GetValue("")->ToString()->Split(gcnew array<wchar_t> { '"' })[1];
	}
}

static void OpenUrl(String^ url, bool isFile = true)
{
	String^ s = isFile ? "file:///" : "";
	ShowMessage(GetDefaultBrowserPath());
	Run(GetDefaultBrowserPath(), s + url);
}


// сортировка по убыванию длины строки
static List<String^>^ SortListByLength(List<String^>^ list)
{
	List<String^>^ res = list;
	res->Sort(gcnew StringLengthDesc());
	return res;
}


// запись bin файлов
static bool StructFileWrite(String^ filePath, Object^ data)
{
	try
	{
		FileStream^ fs = gcnew FileStream(filePath, FileMode::Create);
		BinaryFormatter^ formatter = gcnew BinaryFormatter;
		formatter->Serialize(fs, data);
		fs->Close();
	}
	catch (Exception^ e)
	{
		ShowError(213, "Ошибка доступа к данным\n\nПодробнее:\n" + e->ToString());
		return false;
	}
	return true;
}


// чтение bin файлов
static Object^ StructFileRead(String^ filePath)
{
	Object^ res = gcnew Object();
	if (!File::Exists(filePath)) return nullptr;
	try
	{
		FileStream^ fs = gcnew FileStream(filePath, FileMode::Open);
		BinaryFormatter^ formatter = gcnew BinaryFormatter;
		res = dynamic_cast<Object^>(formatter->Deserialize(fs));
		fs->Close();
	}
	catch (Exception^ e)
	{
		ShowError(428, "Ошибка при чтении структуры файла.\nПодробнее:\n\n" + e->ToString());
	}
	return res;
}