#include <iostream>
using namespace std;
#pragma warning(disable:4996)

class String//создаём свой класс String
{
private://приватные данные
	char* str;//указатель на строку

public://публичные данные
	String()//конструктор по умолчанию
	{
		str = NULL;
	}

	String(char* str)//Конструктор, который создаёт строку и инициализирует её строкой, полученной от пользователя.
	{
		this->str = NULL;
		setString(str);
	}

	String(const String& orig)//конструктор копирования
	{
		if (orig.str != NULL)//если в строке не ноль, копируем данные
		{
			this->str = new char[strlen(orig.str) + 1];
			strcpy(this->str, orig.str);
		}
		else
		{
			this->str = NULL;
		}
	}

	~String()//деструктор
	{
		if (str != NULL)//если в строке что-то храниться, освобождаем память
		{
			delete[] str;
		}
	}

	void setString(char* str)//метод ввода данных в строку
	{
		if (this->str != NULL)//если в строке что-то храниться, освобождаем память, создаём указатель на ноль
		{
			delete[] this->str;
			this->str = NULL;
		}
		if (str != NULL)
		{
			this->str = new char[strlen(str) + 1];//выделяем память и копируем данные
			strcpy(this->str, str);
		}
		else
		{
			this->str = NULL;
		}
	}

	char* getStr()//геттер, возвращает строку
	{
		return str;
	}

	void show()//метод для вывода строк на экран
	{
		if (str != NULL)//выводим в консоль, если в строке что-то есть
		{
			cout << str << endl;
		}
		else
		{
			cout << "error: the string is empty!" << endl;
		}
	}

	String& operator=(const String& right)//перегрузка =
	{
		if (this->str != NULL)//если в текущей строке есть данные, удаляем их, создаём указатель на ноль
		{
			delete[] str;
			this->str = NULL;
		}
		if (right.str != NULL)//если в правой строке что-то есть, переписываем данные
		{
			this->str = new char[strlen(right.str) + 1];
			strcpy(this->str, right.str);
		}
		return *this;//возвращаем разименнованный указатель
	}

	bool operator<(const String& right)//Перегрузка метода  <
	{
		return strcmp(str, right.str) < 0;//возвращаем результат сравнения
	}

	bool operator<=(const String& right)//Перегрузка метода <=
	{
		return strcmp(str, right.str) <= 0;//возвращаем результат сравнения
	}

	bool operator>(const String& right)//Перегрузка метода  >
	{
		return strcmp(str, right.str) > 0;//возвращаем результат сравнения
	}

	bool operator>=(const String& right)//Перегрузка метода  >=
	{
		return strcmp(str, right.str) >= 0;//возвращаем результат сравнения
	}

	bool operator==(const String& right)//Перегрузка метода  ==
	{
		return strcmp(str, right.str) == 0;//возвращаем результат сравнения
	}

	bool operator!=(const String& right)//Перегрузка метода  !=
	{
		return strcmp(str, right.str) != 0;//возвращаем результат сравнения
	}

	String operator+(const String& right)//Перегрузка метода  + (складываем 2 строки и возвращаем третью)
	{
		String CatString;//создаём новый объект, который мы будем возвращать	
		size_t len1; //определяем длину первой строки
		size_t len2;//определяем длину второй строки
		if (str != NULL)
		{
			len1 = strlen(str);
		}
		else
		{
			len1 = 0;
		}
		if (right.str != NULL)
		{
			len2 = strlen(right.str);
		}
		else
		{
			len2 = 0;
		}
		CatString.str = new char[len1 + len2 + 1];
		if (this->str != NULL)//если в строке что-то есть, переписываем
		{
			strcpy(CatString.str, str);
		}
		if (right.str != NULL)//если вторая строка не пустая, дописываем её в первую
		{
			strcat(CatString.str, right.str);//дописываем в буффер строку со правого объекта
		}
		return CatString;
	}

	String& operator+=(const String& right)//Перегрузка метода  += (дописываем в левую)
	{
		String sub_sum;//результат операции между левой и правой строкой
		sub_sum.setString(this->str);
		String result = sub_sum + right;
		this->setString(result.getStr());
		return *this;//возвращаем результат вычитания
	}

	String operator-(const String& right)//Перегрузка метода  -
	{
		String result_substration;//результирующая строка с выычитом второй строки
		size_t len1 = 0;
		size_t len2 = 0;
		if (str != NULL)
		{
			len1 = strlen(str);
		}
		if (right.str != NULL)
		{
			len2 = strlen(right.str);
		}
		if (len2 > len1)
		{
			result_substration.str = NULL;
			return result_substration;
		}
		size_t new_size = len1 - len2;
		char* new_str = new char[new_size + 1];
		strncpy(new_str, str, new_size);
		new_str[new_size] = '\0';
		result_substration.str = new_str;
		return result_substration;//возвращаем результат вычитания
	}

	String& operator-=(const String& right)//Перегрузка метода  -=
	{
		String sub_copy;//результат операции между левой и правой строкой
		sub_copy.setString(this->str);
		String result = sub_copy - right;
		this->setString(result.getStr());
		return *this;//возвращаем результат вычитания
	}

	String operator*(const String& right)//Перегрузка метода  *
	{
		String result_substration;//результирующая строка с выычитом второй строки
		size_t len1; //определяем длину первой строки
		size_t len2;//определяем длину второй строки
		if (str != NULL)//если в левой строке что-то есть, определяем её длину
		{
			len1 = strlen(str);
		}
		else//иначе возвращаем пустой стринг с указателем на ноль
		{
			result_substration.str = NULL;
			return result_substration;
		}

		if (right.str != NULL)//если в правой строке что-то есть, определяем её длину
		{
			len2 = strlen(right.str);
		}
		else//иначе возвращаем стринг равный левой строке
		{
			result_substration.setString(str);
			return result_substration;
		}
		//в других случаях сравниваем строки посимвольно

		size_t count = 0;
		for (size_t i = 0; i < len1; i++)//перебираем символы левой строки
		{
			bool flag = false;
			for (size_t j = 0; j < len2; j++)//перебираем символы правой строки
			{
				if (str[i] == right.str[j])//несли символы не равны
				{
					flag = true;//найдено совпадение
					break;
				}
			}
			if (flag)//если совпадение не найдено, заносим символ в результирующюю строку
			{
				if (result_substration.str == NULL)//выделяем память, если указатель на ноль
				{
					count++;
					result_substration.str = new char[255];
					result_substration.str[0] = '\0';
					strcat(result_substration.str, &str[i]);
					result_substration.str[1] = '\0';
				}
				else
				{
					count++;
					strcat(result_substration.str, &str[i]);
					result_substration.str[count] = '\0';
				}
			}
		}
		return result_substration;//возвращаем результат вычитания
	}

	String& operator*=(const String& right)//Перегрузка метода  *=
	{
		String result_multy;//результат операции между левой и правой строкой
		result_multy.setString(this->str);
		String result = result_multy*right;
		setString(result.getStr());
		return *this;//возвращаем результат вычитания
	}

	String operator/(const String& right)//Перегрузка метода  /
	{
		String result_substration;//результирующая строка с выычитом второй строки
		size_t len1; //определяем длину первой строки
		size_t len2;//определяем длину второй строки
		if (str != NULL)//если в левой строке что-то есть, определяем её длину
		{
			len1 = strlen(str);
		}
		else//иначе возвращаем пустой стринг с указателем на ноль
		{
			result_substration.str = NULL;
			return result_substration;
		}

		if (right.str != NULL)//если в правой строке что-то есть, определяем её длину
		{
			len2 = strlen(right.str);
		}
		else//иначе возвращаем стринг равный левой строке
		{
			result_substration.setString(str);
			return result_substration;
		}
		//в других случаях сравниваем строки посимвольно

		size_t count = 0;
		for (size_t i = 0; i < len1; i++)//перебираем символы левой строки
		{
			bool flag = false;
			for (size_t j = 0; j < len2; j++)//перебираем символы правой строки
			{
				if (str[i] == right.str[j])//несли символы не равны
				{
					flag = true;//найдено совпадение
					break;
				}
			}
			if (!flag)//если совпадение не найдено, заносим символ в результирующюю строку
			{
				if (result_substration.str == NULL)//выделяем память, если указатель на ноль
				{
					count++;
					result_substration.str = new char[255];
					result_substration.str[0] = '\0';
					strcat(result_substration.str, &str[i]);
					result_substration.str[1] = '\0';
				}
				else
				{
					count++;
					strcat(result_substration.str, &str[i]);
					result_substration.str[count] = '\0';
				}
			}
		}
		return result_substration;//возвращаем результат вычитания
	}
	String& operator/=(const String& right)//Перегрузка метода  /=
	{
		String result_copy;//результат операции между левой и правой строкой
		result_copy.setString(this->str);
		String result = result_copy / right;
		setString(result.getStr());
		return *this;//возвращаем результат вычитания
	}
};

class Variable//класс переменная
{
private:
	enum TYPE { INT, DOUBLE, STRING, UNKNOWN };//объявляем пользовательский тип данных тип, содержит имена переменных
	int ival;//переменная типа int
	double dval;//переменная типа double
	String sval;//переменная типа строка, мой класс String
	TYPE type;//храним тип переменной в этой переменной
	size_t countSym(double num, size_t* count)//метод находит количество знаков после точки в числе типа DOUBLE
	{
		const size_t accuracy = 5;//точность вычислений, принимаем 5
		size_t countCycles = 0;
		do {

			num *= 10;
			if (num == (int)num || countCycles > accuracy) //если чило дабль становится равно себе без дровной части либо превышает необходимую нам точность, возвращаем число циклов
			{
				return *count;
			}
			++(*count);//увеличиваем
			countCycles++;//считаем точность
		} while (true);
	}
public:
	const int DefaultInt = 0;//значение по умолчанию
	const double DefaultDouble = 0.0;//значение по умолчанию
									 //строка sval описана в классе String
	void setVaridble(int i)//сеттер для INT значения
	{
		ival = i;//присваеваем значение в поле с типом данных int
		dval = DefaultDouble;//присваеваем значение в поле с типом данных double по умолчанию 0
							 //строка sval описана в классе String
		type = INT;//присваеваем тип
	}
	void setVaridble(double d)//сеттер для DOUBLE значения
	{
		ival = DefaultInt;//присваеваем значение в поле с типом данных int по умолчанию 0
		dval = d;//присваеваем значение
				 //строка sval описана в классе String
		type = DOUBLE;//присваеваем тип
	}
	void setVaridble(String(s))//сеттер для STRING значения
	{
		ival = DefaultInt;//присваеваем значение в поле с типом данных int по умолчанию 0
		dval = DefaultDouble;//присваеваем значение в поле с типом данных double по умолчанию 0
		sval = s;//присваеваем значение
		type = STRING;//присваеваем тип
	}
	Variable()//конструктор по умолчанию
	{
		ival = DefaultInt;//присваеваем значение в поле с типом данных int по умолчанию 0
		dval = DefaultDouble;//присваеваем значение в поле с типом данных double по умолчанию 0
							 //строка sval описана в классе String
		type = UNKNOWN;
	}
	Variable(int i)//перегруженный конструктор для int
	{
		setVaridble(i);
	}
	Variable(double d)//перегруженный конструктор для double
	{
		setVaridble(d);
	}
	Variable(String s)//перегруженный конструктор для String
	{
		setVaridble(s);
	}
	Variable(const Variable& orig)//конструктор копирования
	{
		this->ival = orig.ival;
		this->dval = orig.dval;
		this->sval = orig.sval;
		this->type = orig.type;
	}
	//-------------------------------METHODS----------------------

	Variable getVariable()
	{
		return *this;
	}

	void ConvertToInt()//преобразование данных в INT
	{
		if (type == DOUBLE)
		{
			ival = (int)dval;
			dval = DefaultInt;
		}
		if (type == STRING)
		{
			ival = atoi(sval.getStr());//переписываем значение int-поля
			sval.setString("\0");
		}
		type = INT;//назначаем необходимый тип данных
	}

	void ConverToDouble()//преобразование данных в DOUBLE
	{
		if (type == INT)
		{
			dval = (double)ival;
			ival = DefaultInt;
		}
		if (type == STRING)
		{
			if (sval.getStr() != NULL)
			{
				dval = atof(sval.getStr());
				sval.setString("\0");
			}
			else
			{
				dval = DefaultDouble;
				sval.setString("\0");
			}
		}
		type = DOUBLE;
	}

	void ConvertToString()//преобразование данных в STRING
	{
		if (type == INT)
		{
			char* buff = new char[255];//создаём временный буффер
			buff = _itoa(ival, buff, 10);//преобразовываем число в строку
			sval.setString(buff);//записываем эту строку в значение sval
			delete[] buff;//удаляем буффер
			ival = DefaultInt;
		}
		if (type == DOUBLE)
		{
			int buff_int = (int)dval;//записываем во временную переменную значение до запятой
			char* buff_string = new char[100];//создаём временный буффер для строки
			buff_string = itoa(buff_int, buff_string, 10);//преобразовываем число в строку
			double buff_double = dval - buff_int;//записываем в буфер значения после точки от числа dval
			strcat(buff_string, ".");//дописываем в стоку разделитель
			size_t count = 0;//количество символов после запятой в числе DOUBLE
			size_t count_symbol = countSym(buff_double, &count);//определяем количество знаков после точки в buff_double
			buff_double *= pow(10, count_symbol);//приводим значение к целому числу, путем домножения
			int buff = (int)buff_double;
			char* buff_string2 = new char[255];
			buff_string2 = itoa(buff, buff_string2, 10);//дописываем в строку часть после запятой
			strcat(buff_string, buff_string2);//доклееваем в первую строку вторую
			sval.setString(buff_string);//задаём в стринг строку из буфера
			delete[] buff_string;//освобождаем память
			delete[] buff_string2;//освобождаем память
			dval = DefaultDouble;//задаём значение по умолчанию
		}
		type = STRING;//назначаем необходимый тип данных
	}

	Variable& operator=(const Variable& rhs)//перегрузка операции =
	{
		ival = rhs.ival;//переписываем поле со значением INT
		dval = rhs.dval;//переписываем поле со значением DOUBLE
		sval = rhs.sval;//переписываем поле со значением STRING
		type = rhs.type;//переписываем поле со значением TYPE
		return *this;//возвращаем указатель на самого себя
	}

	//-----------------------------------++++++++++++++++++++++++++++++++++-----------------------------
	Variable operator+(Variable& rhs)//перегрузка операции +
	{
		Variable result;//результат операции
		if (type == INT)//если слева INT
		{
			if (rhs.type == INT)//если справа INT
			{
				result.ival = ival + rhs.ival;//складываем поля с INT значениями
			}
			else if (rhs.type == UNKNOWN)
			{
				cout << "Unknow type of datas... Operation impossible" << endl;
				result.type = UNKNOWN;
				return result;
			}
			else//если справа любой другой тип данных
			{
				Variable rhs_convert = rhs.getVariable();//копируем правое слагаемое
				rhs_convert.ConvertToInt();//конвертируем в тип INT
				result.ival = ival + rhs_convert.ival;//складываем поля INT
			}
			result.type = INT;//назначаем результату типа данных INT
		}

		if (type == DOUBLE)//если слева DOUBLE
		{
			if (rhs.type == DOUBLE)//если справа DOUBLE
			{
				result.dval = dval + rhs.dval;//складываем поля с DOUBLE значениями
			}
			else if (rhs.type == UNKNOWN)
			{
				cout << "Unknow type of datas... Operation impossible" << endl;
				result.type = UNKNOWN;
				return result;
			}
			else//если справа любой другой тип данных
			{
				Variable rhs_convert = rhs.getVariable();//копируем правое слагаемое
				rhs_convert.ConverToDouble();//конвертируем в тип DOUBLE
				result.dval = dval + rhs_convert.dval;//складываем поля DOUBLE
			}
			result.type = DOUBLE;//назначаем результату типа данных DOUBLE
		}

		if (type == STRING)//если слева STRING
		{
			if (rhs.type == STRING)//если справа STRING
			{
				result.sval = sval + rhs.sval;//складываем поля STRING данными
			}
			else if (rhs.type == UNKNOWN)
			{
				cout << "Unknow type of datas... Operation impossible" << endl;
				result.type = UNKNOWN;
				return result;
			}
			else//если справа любой другой тип данных
			{
				Variable rhs_convert = rhs.getVariable();//копируем правое слагаемое
				rhs_convert.ConvertToString();//конвертируем в тип DOUBLE
				result.sval = sval + rhs_convert.sval;//складываем поля DOUBLE
			}
			result.type = STRING;//назначаем результату типа данных STRING
		}
		return result;
	}

	//-------------------------------------------------------------------------------------------------------
	Variable operator-(Variable& rhs)//перегрузка операции -
	{
		Variable result;//результат операции
		if (type == INT)//если слева INT
		{
			if (rhs.type == INT)//если справа INT
			{
				result.ival = ival - rhs.ival;//складываем поля с INT значениями
			}
			else if (rhs.type == UNKNOWN)
			{
				cout << "Unknow type of datas... Operation impossible" << endl;
				result.type = UNKNOWN;
				return result;
			}
			else//если справа любой другой тип данных
			{
				Variable rhs_convert = rhs.getVariable();//копируем правое слагаемое
				rhs_convert.ConvertToInt();//конвертируем в тип INT
				result.ival = ival - rhs_convert.ival;//складываем поля INT
			}
			result.type = INT;//назначаем результату типа данных INT
		}

		if (type == DOUBLE)//если слева DOUBLE
		{
			if (rhs.type == DOUBLE)//если справа DOUBLE
			{
				result.dval = dval - rhs.dval;//складываем поля с DOUBLE значениями
			}
			else if (rhs.type == UNKNOWN)
			{
				cout << "Unknow type of datas... Operation impossible" << endl;
				result.type = UNKNOWN;
				return result;
			}
			else//если справа любой другой тип данных
			{
				Variable rhs_convert = rhs.getVariable();//копируем правое слагаемое
				rhs_convert.ConverToDouble();//конвертируем в тип DOUBLE
				result.dval = dval - rhs_convert.dval;//складываем поля DOUBLE
			}
			result.type = DOUBLE;//назначаем результату типа данных DOUBLE
		}

		if (type == STRING)//если слева STRING
		{
			if (rhs.type == STRING)//если справа STRING
			{
				result.sval = sval - rhs.sval;//отнимаем поля STRING данными
			}
			else if (rhs.type == UNKNOWN)
			{
				cout << "Unknow type of datas... Operation impossible" << endl;
				result.type = UNKNOWN;
				return result;
			}
			else//если справа любой другой тип данных
			{
				Variable rhs_convert = rhs.getVariable();//копируем правое слагаемое
				rhs_convert.ConvertToString();//конвертируем в тип DOUBLE
				result.sval = sval - rhs_convert.sval;//складываем поля DOUBLE
			}
			result.type = STRING;//назначаем результату типа данных STRING
		}
		return result;
	}
	//--------------------******************************---------------------------------------------------
	Variable operator*(Variable& rhs)//перегрузка операции *
	{
		Variable result;//результат операции
		if (type == INT)//если слева INT
		{
			if (rhs.type == INT)//если справа INT
			{
				result.ival = ival * rhs.ival;//складываем поля с INT значениями
			}
			else if (rhs.type == UNKNOWN)
			{
				cout << "Unknow type of datas... Operation impossible" << endl;
				result.type = UNKNOWN;
				return result;
			}
			else//если справа любой другой тип данных
			{
				Variable rhs_convert = rhs.getVariable();//копируем правое слагаемое
				rhs_convert.ConvertToInt();//конвертируем в тип INT
				result.ival = ival * rhs_convert.ival;//складываем поля INT
			}
			result.type = INT;//назначаем результату типа данных INT
		}

		if (type == DOUBLE)//если слева DOUBLE
		{
			if (rhs.type == DOUBLE)//если справа DOUBLE
			{
				result.dval = dval * rhs.dval;//складываем поля с DOUBLE значениями
			}
			else if (rhs.type == UNKNOWN)
			{
				cout << "Unknow type of datas... Operation impossible" << endl;
				result.type = UNKNOWN;
				return result;
			}
			else//если справа любой другой тип данных
			{
				Variable rhs_convert = rhs.getVariable();//копируем правое слагаемое
				rhs_convert.ConverToDouble();//конвертируем в тип DOUBLE
				result.dval = dval * rhs_convert.dval;//складываем поля DOUBLE
			}
			result.type = DOUBLE;//назначаем результату типа данных DOUBLE
		}

		if (type == STRING)//если слева STRING
		{
			if (rhs.type == STRING)//если справа STRING
			{
				result.sval = sval * rhs.sval;//отнимаем поля STRING данными
			}
			else if (rhs.type == UNKNOWN)
			{
				cout << "Unknow type of datas... Operation impossible" << endl;
				result.type = UNKNOWN;
				return result;
			}
			else//если справа любой другой тип данных
			{
				Variable rhs_convert = rhs.getVariable();//копируем правое слагаемое
				rhs_convert.ConvertToString();//конвертируем в тип DOUBLE
				result.sval = sval * rhs_convert.sval;//складываем поля DOUBLE
			}
			result.type = STRING;//назначаем результату типа данных STRING
		}
		return result;
	}
	//--------------------//////////////////////////////////--------------------------------------------------
	Variable operator/(Variable& rhs)//перегрузка операции /
	{
		Variable result;//результат операции
		if (type == INT)//если слева INT
		{
			if (rhs.type == INT)//если справа INT
			{
				result.ival = ival / rhs.ival;//складываем поля с INT значениями
			}
			else if (rhs.type == UNKNOWN)
			{
				cout << "Unknow type of datas... Operation impossible" << endl;
				result.type = UNKNOWN;
				return result;
			}
			else//если справа любой другой тип данных
			{
				Variable rhs_convert = rhs.getVariable();//копируем правое слагаемое
				rhs_convert.ConvertToInt();//конвертируем в тип INT
				result.ival = ival / rhs_convert.ival;//складываем поля INT
			}
			result.type = INT;//назначаем результату типа данных INT
		}

		if (type == DOUBLE)//если слева DOUBLE
		{
			if (rhs.type == DOUBLE)//если справа DOUBLE
			{
				result.dval = dval / rhs.dval;//складываем поля с DOUBLE значениями
			}
			else if (rhs.type == UNKNOWN)
			{
				cout << "Unknow type of datas... Operation impossible" << endl;
				result.type = UNKNOWN;
				return result;
			}
			else//если справа любой другой тип данных
			{
				Variable rhs_convert = rhs.getVariable();//копируем правое слагаемое
				rhs_convert.ConverToDouble();//конвертируем в тип DOUBLE
				result.dval = dval / rhs_convert.dval;//складываем поля DOUBLE
			}
			result.type = DOUBLE;//назначаем результату типа данных DOUBLE
		}

		if (type == STRING)//если слева STRING
		{
			if (rhs.type == STRING)//если справа STRING
			{
				result.sval = sval / rhs.sval;//отнимаем поля STRING данными
			}
			else if (rhs.type == UNKNOWN)
			{
				cout << "Unknow type of datas... Operation impossible" << endl;
				result.type = UNKNOWN;
				return result;
			}
			else//если справа любой другой тип данных
			{
				Variable rhs_convert = rhs.getVariable();//копируем правое слагаемое
				rhs_convert.ConvertToString();//конвертируем в тип DOUBLE
				result.sval = sval / rhs_convert.sval;//складываем поля DOUBLE
			}
			result.type = STRING;//назначаем результату типа данных STRING
		}
		return result;
	}
	//--------------------+=+=+=+=+=+=+=+=+=+=+=+=+=+=---------------------------------------------------

	Variable& operator+=(Variable& rhs)//перегрузка операции +=
	{
		if (type == INT)//если слева INT
		{
			if (rhs.type == INT)//если справа INT
			{
				ival += rhs.ival;//складываем поля с INT значениями
			}
			else if (rhs.type == UNKNOWN)
			{
				cout << "Unknow type of datas... Operation impossible" << endl;
			}
			else//если справа любой другой тип данных
			{
				Variable rhs_convert = rhs.getVariable();//копируем правое слагаемое
				rhs_convert.ConvertToInt();//конвертируем в тип INT
				ival += rhs_convert.ival;//складываем поля INT
			}
		}

		if (type == DOUBLE)//если слева DOUBLE
		{
			if (rhs.type == DOUBLE)//если справа DOUBLE
			{
				dval += rhs.dval;//складываем поля с DOUBLE значениями
			}
			else if (rhs.type == UNKNOWN)
			{
				cout << "Unknow type of datas... Operation impossible" << endl;
			}
			else//если справа любой другой тип данных
			{
				Variable rhs_convert = rhs.getVariable();//копируем правое слагаемое
				rhs_convert.ConverToDouble();//конвертируем в тип DOUBLE
				dval += rhs_convert.dval;//складываем поля DOUBLE
			}
		}

		if (type == STRING)//если слева STRING
		{
			if (rhs.type == STRING)//если справа STRING
			{
				sval += rhs.sval;//складываем поля STRING данными
			}
			else if (rhs.type == UNKNOWN)
			{
				cout << "Unknow type of datas... Operation impossible" << endl;
			}
			else//если справа любой другой тип данных
			{
				Variable rhs_convert = rhs.getVariable();//копируем правое слагаемое
				rhs_convert.ConvertToString();//конвертируем в тип DOUBLE
				sval += rhs_convert.sval;//складываем поля DOUBLE
			}
		}
		return *this;
	}
	//---------------------=-=-=-=-=-=-=-=-=-=-=-=---------------------------------------------------
	Variable& operator-=(Variable& rhs)//перегрузка операции -=
	{
		if (type == INT)//если слева INT
		{
			if (rhs.type == INT)//если справа INT
			{
				ival -= rhs.ival;//складываем поля с INT значениями
			}
			else if (rhs.type == UNKNOWN)
			{
				cout << "Unknow type of datas... Operation impossible" << endl;
			}
			else//если справа любой другой тип данных
			{
				Variable rhs_convert = rhs.getVariable();//копируем правое слагаемое
				rhs_convert.ConvertToInt();//конвертируем в тип INT
				ival -= rhs_convert.ival;//складываем поля INT
			}
		}

		if (type == DOUBLE)//если слева DOUBLE
		{
			if (rhs.type == DOUBLE)//если справа DOUBLE
			{
				dval -= rhs.dval;//складываем поля с DOUBLE значениями
			}
			else if (rhs.type == UNKNOWN)
			{
				cout << "Unknow type of datas... Operation impossible" << endl;
			}
			else//если справа любой другой тип данных
			{
				Variable rhs_convert = rhs.getVariable();//копируем правое слагаемое
				rhs_convert.ConverToDouble();//конвертируем в тип DOUBLE
				dval -= rhs_convert.dval;//складываем поля DOUBLE
			}
		}

		if (type == STRING)//если слева STRING
		{
			if (rhs.type == STRING)//если справа STRING
			{
				sval -= rhs.sval;//складываем поля STRING данными
			}
			else if (rhs.type == UNKNOWN)
			{
				cout << "Unknow type of datas... Operation impossible" << endl;
			}
			else//если справа любой другой тип данных
			{
				Variable rhs_convert = rhs.getVariable();//копируем правое слагаемое
				rhs_convert.ConvertToString();//конвертируем в тип DOUBLE
				sval -= rhs_convert.sval;//складываем поля DOUBLE
			}
		}
		return *this;
	}
	//---------------------*=*=*=*=*=*=*=*=*=*=*=*=*=*=*---------------------------------------------------
	Variable& operator*=(Variable& rhs)//перегрузка операции *=
	{
		if (type == INT)//если слева INT
		{
			if (rhs.type == INT)//если справа INT
			{
				ival *= rhs.ival;//складываем поля с INT значениями
			}
			else if (rhs.type == UNKNOWN)
			{
				cout << "Unknow type of datas... Operation impossible" << endl;
			}
			else//если справа любой другой тип данных
			{
				Variable rhs_convert = rhs.getVariable();//копируем правое слагаемое
				rhs_convert.ConvertToInt();//конвертируем в тип INT
				ival *= rhs_convert.ival;//складываем поля INT
			}
		}

		if (type == DOUBLE)//если слева DOUBLE
		{
			if (rhs.type == DOUBLE)//если справа DOUBLE
			{
				dval *= rhs.dval;//складываем поля с DOUBLE значениями
			}
			else if (rhs.type == UNKNOWN)
			{
				cout << "Unknow type of datas... Operation impossible" << endl;
			}
			else//если справа любой другой тип данных
			{
				Variable rhs_convert = rhs.getVariable();//копируем правое слагаемое
				rhs_convert.ConverToDouble();//конвертируем в тип DOUBLE
				dval *= rhs_convert.dval;//складываем поля DOUBLE
			}
		}

		if (type == STRING)//если слева STRING
		{
			if (rhs.type == STRING)//если справа STRING
			{
				sval *= rhs.sval;//складываем поля STRING данными
			}
			else if (rhs.type == UNKNOWN)
			{
				cout << "Unknow type of datas... Operation impossible" << endl;
			}
			else//если справа любой другой тип данных
			{
				Variable rhs_convert = rhs.getVariable();//копируем правое слагаемое
				rhs_convert.ConvertToString();//конвертируем в тип DOUBLE
				sval *= rhs_convert.sval;//складываем поля DOUBLE
			}
		}
		return *this;
	}
	//---------------------/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=---------------------------------------------------
	Variable& operator/=(Variable& rhs)//перегрузка операции /=
	{
		if (type == INT)//если слева INT
		{
			if (rhs.type == INT)//если справа INT
			{
				ival /= rhs.ival;//складываем поля с INT значениями
			}
			else if (rhs.type == UNKNOWN)
			{
				cout << "Unknow type of datas... Operation impossible" << endl;
			}
			else//если справа любой другой тип данных
			{
				Variable rhs_convert = rhs.getVariable();//копируем правое слагаемое
				rhs_convert.ConvertToInt();//конвертируем в тип INT
				ival /= rhs_convert.ival;//складываем поля INT
			}
		}

		if (type == DOUBLE)//если слева DOUBLE
		{
			if (rhs.type == DOUBLE)//если справа DOUBLE
			{
				dval /= rhs.dval;//складываем поля с DOUBLE значениями
			}
			else if (rhs.type == UNKNOWN)
			{
				cout << "Unknow type of datas... Operation impossible" << endl;
			}
			else//если справа любой другой тип данных
			{
				Variable rhs_convert = rhs.getVariable();//копируем правое слагаемое
				rhs_convert.ConverToDouble();//конвертируем в тип DOUBLE
				dval /= rhs_convert.dval;//складываем поля DOUBLE
			}
		}

		if (type == STRING)//если слева STRING
		{
			if (rhs.type == STRING)//если справа STRING
			{
				sval /= rhs.sval;//складываем поля STRING данными
			}
			else if (rhs.type == UNKNOWN)
			{
				cout << "Unknow type of datas... Operation impossible" << endl;
			}
			else//если справа любой другой тип данных
			{
				Variable rhs_convert = rhs.getVariable();//копируем правое слагаемое
				rhs_convert.ConvertToString();//конвертируем в тип DOUBLE
				sval /= rhs_convert.sval;//складываем поля DOUBLE
			}
		}
		return *this;
	}
	void show()//метод выводит в консоль результат
	{
		if (type == INT)//если тип INT
		{
			cout << ival << endl;
		}
		if (type == DOUBLE)//если тип DOUBLE
		{
			cout << dval << endl;
		}
		if (type == STRING)//если тип STRING
		{
			sval.show();
		}
		if (type == UNKNOWN)//если тип неизвестен
		{
			cout << "ERROR TYPE" << endl;
		}
	}
};

int main()
{
	Variable InT = 555;//объявляем INT переменную
	cout << endl;
	cout << "int: ";
	InT.show();
	cout << endl;
	Variable DoU = 10.258;//объявляем DOUBLE переменную
	cout << "Double: ";
	DoU.show();
	cout << endl;
	Variable StR = "25454 test!!! ";//объявляем STRING переменную
	Variable StR2 = "2test";//для умонжения и деления стринг
	cout << "String: ";
	StR.show();
	cout << endl;
	cout << "--------------------------------------" << endl;
	cout << "************ operator + **************" << endl;
	cout << "--------------------------------------" << endl;
	Variable result = InT + InT;
	cout << "int + int: ";
	result.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	result = InT + DoU;
	cout << "int + double: ";
	result.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	result = InT + StR;
	cout << "int + string: ";
	result.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	cout << "--------------------------------------" << endl;
	cout << "double + double: ";
	result = DoU + DoU;
	result.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	cout << "double + int: ";
	result = DoU + InT;
	result.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	cout << "double + string: ";
	result = DoU + StR;
	result.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	cout << "--------------------------------------" << endl;
	cout << "string + int: ";
	result = StR + InT;
	result.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	cout << "string + double: ";
	result = StR + DoU;
	result.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	cout << "string + string: ";
	result = StR + StR;
	result.show();//выводим результат в консоль

	cout << "--------------------------------------" << endl;
	cout << "************ operator - **************" << endl;
	cout << "--------------------------------------" << endl;
	result = InT - InT;
	cout << "int - int: ";
	result.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	result = InT - DoU;
	cout << "int - double: ";
	result.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	result = InT - StR;
	cout << "int - string: ";
	result.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	cout << "--------------------------------------" << endl;
	cout << "double - double: ";
	result = DoU - DoU;
	result.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	cout << "double - int: ";
	result = DoU - InT;
	result.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	cout << "double - string: ";
	result = DoU - StR;
	result.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	cout << "--------------------------------------" << endl;
	cout << "string - int: ";
	result = StR - InT;
	result.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	cout << "string - double: ";
	result = StR - DoU;
	result.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	cout << "string - string: ";
	result = StR - StR;
	result.show();//выводим результат в консоль

	cout << "--------------------------------------" << endl;
	cout << "*********** operator *  **************" << endl;
	cout << "--------------------------------------" << endl;
	result = InT * InT;
	cout << "int * int: ";
	result.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	result = InT * DoU;
	cout << "int * double: ";
	result.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	result = InT * StR;
	cout << "int * string: ";
	result.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	cout << "--------------------------------------" << endl;
	cout << "double * double: ";
	result = DoU * DoU;
	result.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	cout << "double * int: ";
	result = DoU * InT;
	result.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	cout << "double * string: ";
	result = DoU * StR;
	result.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	cout << "--------------------------------------" << endl;
	cout << "string * int: ";
	result = StR * InT;
	result.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	cout << "string * double: ";
	result = StR * DoU;
	result.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	cout << "string * string: ";
	result = StR * StR2;
	result.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	cout << "*********** operator /  **************" << endl;
	cout << "--------------------------------------" << endl;
	result = InT / InT;
	cout << "int / int: ";
	result.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	result = InT / DoU;
	cout << "int / double: ";
	result.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	result = InT / StR;
	cout << "int / string: ";
	result.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	cout << "--------------------------------------" << endl;
	cout << "double / double: ";
	result = DoU / DoU;
	result.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	cout << "double / int: ";
	result = DoU / InT;
	result.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	cout << "double / string: ";
	result = DoU / StR;
	result.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	cout << "--------------------------------------" << endl;
	cout << "string / int: ";
	result = StR / InT;
	result.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	cout << "string / double: ";
	result = StR / DoU;
	result.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	cout << "string / string: ";
	result = StR / StR2;
	result.show();//выводим результат в консоль


	cout << "--------------------------------------" << endl;
	cout << "************ operator += **************" << endl;
	cout << "--------------------------------------" << endl;
	InT += InT;
	cout << "int += int: ";
	InT.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	InT += DoU;
	cout << "int += double: ";
	InT.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	InT += StR;
	cout << "int += string: ";
	InT.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	cout << "--------------------------------------" << endl;
	cout << "double += double: ";
	DoU += DoU;
	DoU.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	cout << "double += int: ";
	DoU += InT;
	DoU.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	cout << "double += string: ";
	DoU += StR;
	DoU.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	Variable InT2 = 45;
	Variable DoU2 = 12.36;
	Variable StR22 = "1no";
	cout << "--------------------------------------" << endl;
	cout << "string += int: ";
	StR2 += InT2;
	StR2.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	Variable StR6 = "25454 test!!! ";
	Variable DoU6 = 10.236;
	Variable InT6 = 555;
	cout << "string += double: ";
	StR6 += DoU6;
	StR6.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	cout << "string += string: ";
	StR2 += StR6;
	StR2.show();//выводим результат в консоль


	cout << "--------------------------------------" << endl;
	cout << "*********** operator -= **************" << endl;
	cout << "--------------------------------------" << endl;
	Variable StR3 = "25454 test!!! ";
	Variable DoU3 = 10.236;
	Variable InT3 = 555;
	InT3 -= InT3;
	cout << "int -= int: ";
	InT3.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	InT3 -= DoU3;
	cout << "int -= double: ";
	InT3.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	InT3 -= StR3;
	cout << "int -= string: ";
	InT3.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	cout << "--------------------------------------" << endl;
	cout << "double -= double: ";
	DoU3 -= DoU3;
	DoU3.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	cout << "double -= int: ";
	DoU3 -= InT3;
	DoU3.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	cout << "double -= string: ";
	DoU3 -= StR3;
	DoU3.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	cout << "--------------------------------------" << endl;
	cout << "string -= int: ";
	StR3 -= InT3;
	StR3.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	Variable StR4 = "25454 test!!! ";
	Variable DoU4 = 10.236;
	Variable InT4 = 555;
	cout << "string -= double: ";
	StR4 -= DoU4;
	StR4.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	Variable StR5 = "25454 test!!! ";
	Variable DoU5 = 10.236;
	Variable InT5 = 555;
	cout << "string -= string: ";
	StR5 -= StR5;
	StR5.show();//выводим результат в консоль

	cout << "--------------------------------------" << endl;
	cout << "********** operator *=  **************" << endl;
	cout << "--------------------------------------" << endl;
	InT5 *= InT5;
	cout << "int *= int: ";
	InT5.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	InT5 *= DoU5;
	cout << "int *= double: ";
	InT5.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	InT5 *= StR5;
	cout << "int *= string: ";
	InT5.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	cout << "--------------------------------------" << endl;
	cout << "double *= double: ";
	DoU5 *= DoU5;
	InT5.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	cout << "double *= int: ";
	DoU5 *= InT5;
	InT5.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	Variable StR7 = "25454 test!!! ";
	Variable DoU7 = 10.236;
	Variable InT7 = 555;
	cout << "double *= string: ";
	DoU7 *= StR7;
	DoU7.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	cout << "--------------------------------------" << endl;
	cout << "string *= int: ";
	StR7 *= InT7;
	StR7.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	cout << "string *= double: ";
	StR7 *= DoU7;
	StR7.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	Variable StR8 = "25454 test";
	cout << "string *= string: ";
	StR8 *= StR8;
	StR8.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	cout << "*********** operator /=  **************" << endl;
	cout << "--------------------------------------" << endl;
	InT /= InT;
	cout << "int /= int: ";
	InT.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	InT /= DoU;
	cout << "int /= double: ";
	InT.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	InT /= StR;
	cout << "int /= string: ";
	InT.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	cout << "--------------------------------------" << endl;
	cout << "double /= double: ";
	DoU /= DoU;
	DoU.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	cout << "double /= int: ";
	DoU /= InT;
	DoU.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	cout << "double /= string: ";
	DoU /= StR;
	DoU.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	cout << "--------------------------------------" << endl;
	cout << "string /= int: ";
	StR /= InT;
	StR.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	cout << "string /= double: ";
	StR /= DoU;
	StR.show();//выводим результат в консоль
	cout << "--------------------------------------" << endl;
	cout << "string /= string: ";
	StR /= StR2;
	StR.show();//выводим результат в консоль


	Variable a = 15;//int
	cout << "int: ";
	a.show();
	Variable b = "Hello";//string
	cout << "string: ";
	b.show();
	Variable c = 7.8;//double
	cout << "double: ";
	c.show();
	Variable d = "50";
	cout << "string: ";
	d.show();
	cout << "int (15) + string ('50'): ";
	b = a + c;
	b.show();
	cout << "------------------------------" << endl;
	Variable a2 = 10, b2 = "120", c2;
	cout << "int (10) + string ('120'): ";
	c2 = a2 + b2;
	c2.show();
	cout << "string ('120') + int (10) : ";
	c2 = b2 + a2;
	c2.show();
	cout << "------------------------------" << endl;
	//-------------------------------
	Variable a3 = "Microsoft";
	Variable b3 = "Windows";
	a3.show();
	b3.show();
	Variable c3 = a3 * b3;
	cout << "string * string : ";
	c3.show();
	c3 = a3 / b3;
	cout << "string / string : ";
	c3.show();
	Variable c4;
	a3 *= b3;
	cout << "string *= string, left= ";
	a3.show();
	Variable a4 = "Microsoft";
	a4 /= b3;
	cout << "string /= string, left= ";
	a4.show();
	return 0;
}

