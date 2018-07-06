#include <iostream>
using namespace std;
#pragma warning(disable:4996)

class String//������ ���� ����� String
{
private://��������� ������
	char* str;//��������� �� ������

public://��������� ������
	String()//����������� �� ���������
	{
		str = NULL;
	}

	String(char* str)//�����������, ������� ������ ������ � �������������� � �������, ���������� �� ������������.
	{
		this->str = NULL;
		setString(str);
	}

	String(const String& orig)//����������� �����������
	{
		if (orig.str != NULL)//���� � ������ �� ����, �������� ������
		{
			this->str = new char[strlen(orig.str) + 1];
			strcpy(this->str, orig.str);
		}
		else
		{
			this->str = NULL;
		}
	}

	~String()//����������
	{
		if (str != NULL)//���� � ������ ���-�� ���������, ����������� ������
		{
			delete[] str;
		}
	}

	void setString(char* str)//����� ����� ������ � ������
	{
		if (this->str != NULL)//���� � ������ ���-�� ���������, ����������� ������, ������ ��������� �� ����
		{
			delete[] this->str;
			this->str = NULL;
		}
		if (str != NULL)
		{
			this->str = new char[strlen(str) + 1];//�������� ������ � �������� ������
			strcpy(this->str, str);
		}
		else
		{
			this->str = NULL;
		}
	}

	char* getStr()//������, ���������� ������
	{
		return str;
	}

	void show()//����� ��� ������ ����� �� �����
	{
		if (str != NULL)//������� � �������, ���� � ������ ���-�� ����
		{
			cout << str << endl;
		}
		else
		{
			cout << "error: the string is empty!" << endl;
		}
	}

	String& operator=(const String& right)//���������� =
	{
		if (this->str != NULL)//���� � ������� ������ ���� ������, ������� ��, ������ ��������� �� ����
		{
			delete[] str;
			this->str = NULL;
		}
		if (right.str != NULL)//���� � ������ ������ ���-�� ����, ������������ ������
		{
			this->str = new char[strlen(right.str) + 1];
			strcpy(this->str, right.str);
		}
		return *this;//���������� ��������������� ���������
	}

	bool operator<(const String& right)//���������� ������  <
	{
		return strcmp(str, right.str) < 0;//���������� ��������� ���������
	}

	bool operator<=(const String& right)//���������� ������ <=
	{
		return strcmp(str, right.str) <= 0;//���������� ��������� ���������
	}

	bool operator>(const String& right)//���������� ������  >
	{
		return strcmp(str, right.str) > 0;//���������� ��������� ���������
	}

	bool operator>=(const String& right)//���������� ������  >=
	{
		return strcmp(str, right.str) >= 0;//���������� ��������� ���������
	}

	bool operator==(const String& right)//���������� ������  ==
	{
		return strcmp(str, right.str) == 0;//���������� ��������� ���������
	}

	bool operator!=(const String& right)//���������� ������  !=
	{
		return strcmp(str, right.str) != 0;//���������� ��������� ���������
	}

	String operator+(const String& right)//���������� ������  + (���������� 2 ������ � ���������� ������)
	{
		String CatString;//������ ����� ������, ������� �� ����� ����������	
		size_t len1; //���������� ����� ������ ������
		size_t len2;//���������� ����� ������ ������
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
		if (this->str != NULL)//���� � ������ ���-�� ����, ������������
		{
			strcpy(CatString.str, str);
		}
		if (right.str != NULL)//���� ������ ������ �� ������, ���������� � � ������
		{
			strcat(CatString.str, right.str);//���������� � ������ ������ �� ������� �������
		}
		return CatString;
	}

	String& operator+=(const String& right)//���������� ������  += (���������� � �����)
	{
		String sub_sum;//��������� �������� ����� ����� � ������ �������
		sub_sum.setString(this->str);
		String result = sub_sum + right;
		this->setString(result.getStr());
		return *this;//���������� ��������� ���������
	}

	String operator-(const String& right)//���������� ������  -
	{
		String result_substration;//�������������� ������ � �������� ������ ������
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
		return result_substration;//���������� ��������� ���������
	}

	String& operator-=(const String& right)//���������� ������  -=
	{
		String sub_copy;//��������� �������� ����� ����� � ������ �������
		sub_copy.setString(this->str);
		String result = sub_copy - right;
		this->setString(result.getStr());
		return *this;//���������� ��������� ���������
	}

	String operator*(const String& right)//���������� ������  *
	{
		String result_substration;//�������������� ������ � �������� ������ ������
		size_t len1; //���������� ����� ������ ������
		size_t len2;//���������� ����� ������ ������
		if (str != NULL)//���� � ����� ������ ���-�� ����, ���������� � �����
		{
			len1 = strlen(str);
		}
		else//����� ���������� ������ ������ � ���������� �� ����
		{
			result_substration.str = NULL;
			return result_substration;
		}

		if (right.str != NULL)//���� � ������ ������ ���-�� ����, ���������� � �����
		{
			len2 = strlen(right.str);
		}
		else//����� ���������� ������ ������ ����� ������
		{
			result_substration.setString(str);
			return result_substration;
		}
		//� ������ ������� ���������� ������ �����������

		size_t count = 0;
		for (size_t i = 0; i < len1; i++)//���������� ������� ����� ������
		{
			bool flag = false;
			for (size_t j = 0; j < len2; j++)//���������� ������� ������ ������
			{
				if (str[i] == right.str[j])//����� ������� �� �����
				{
					flag = true;//������� ����������
					break;
				}
			}
			if (flag)//���� ���������� �� �������, ������� ������ � �������������� ������
			{
				if (result_substration.str == NULL)//�������� ������, ���� ��������� �� ����
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
		return result_substration;//���������� ��������� ���������
	}

	String& operator*=(const String& right)//���������� ������  *=
	{
		String result_multy;//��������� �������� ����� ����� � ������ �������
		result_multy.setString(this->str);
		String result = result_multy*right;
		setString(result.getStr());
		return *this;//���������� ��������� ���������
	}

	String operator/(const String& right)//���������� ������  /
	{
		String result_substration;//�������������� ������ � �������� ������ ������
		size_t len1; //���������� ����� ������ ������
		size_t len2;//���������� ����� ������ ������
		if (str != NULL)//���� � ����� ������ ���-�� ����, ���������� � �����
		{
			len1 = strlen(str);
		}
		else//����� ���������� ������ ������ � ���������� �� ����
		{
			result_substration.str = NULL;
			return result_substration;
		}

		if (right.str != NULL)//���� � ������ ������ ���-�� ����, ���������� � �����
		{
			len2 = strlen(right.str);
		}
		else//����� ���������� ������ ������ ����� ������
		{
			result_substration.setString(str);
			return result_substration;
		}
		//� ������ ������� ���������� ������ �����������

		size_t count = 0;
		for (size_t i = 0; i < len1; i++)//���������� ������� ����� ������
		{
			bool flag = false;
			for (size_t j = 0; j < len2; j++)//���������� ������� ������ ������
			{
				if (str[i] == right.str[j])//����� ������� �� �����
				{
					flag = true;//������� ����������
					break;
				}
			}
			if (!flag)//���� ���������� �� �������, ������� ������ � �������������� ������
			{
				if (result_substration.str == NULL)//�������� ������, ���� ��������� �� ����
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
		return result_substration;//���������� ��������� ���������
	}
	String& operator/=(const String& right)//���������� ������  /=
	{
		String result_copy;//��������� �������� ����� ����� � ������ �������
		result_copy.setString(this->str);
		String result = result_copy / right;
		setString(result.getStr());
		return *this;//���������� ��������� ���������
	}
};

class Variable//����� ����������
{
private:
	enum TYPE { INT, DOUBLE, STRING, UNKNOWN };//��������� ���������������� ��� ������ ���, �������� ����� ����������
	int ival;//���������� ���� int
	double dval;//���������� ���� double
	String sval;//���������� ���� ������, ��� ����� String
	TYPE type;//������ ��� ���������� � ���� ����������
	size_t countSym(double num, size_t* count)//����� ������� ���������� ������ ����� ����� � ����� ���� DOUBLE
	{
		const size_t accuracy = 5;//�������� ����������, ��������� 5
		size_t countCycles = 0;
		do {

			num *= 10;
			if (num == (int)num || countCycles > accuracy) //���� ���� ����� ���������� ����� ���� ��� ������� ����� ���� ��������� ����������� ��� ��������, ���������� ����� ������
			{
				return *count;
			}
			++(*count);//�����������
			countCycles++;//������� ��������
		} while (true);
	}
public:
	const int DefaultInt = 0;//�������� �� ���������
	const double DefaultDouble = 0.0;//�������� �� ���������
									 //������ sval ������� � ������ String
	void setVaridble(int i)//������ ��� INT ��������
	{
		ival = i;//����������� �������� � ���� � ����� ������ int
		dval = DefaultDouble;//����������� �������� � ���� � ����� ������ double �� ��������� 0
							 //������ sval ������� � ������ String
		type = INT;//����������� ���
	}
	void setVaridble(double d)//������ ��� DOUBLE ��������
	{
		ival = DefaultInt;//����������� �������� � ���� � ����� ������ int �� ��������� 0
		dval = d;//����������� ��������
				 //������ sval ������� � ������ String
		type = DOUBLE;//����������� ���
	}
	void setVaridble(String(s))//������ ��� STRING ��������
	{
		ival = DefaultInt;//����������� �������� � ���� � ����� ������ int �� ��������� 0
		dval = DefaultDouble;//����������� �������� � ���� � ����� ������ double �� ��������� 0
		sval = s;//����������� ��������
		type = STRING;//����������� ���
	}
	Variable()//����������� �� ���������
	{
		ival = DefaultInt;//����������� �������� � ���� � ����� ������ int �� ��������� 0
		dval = DefaultDouble;//����������� �������� � ���� � ����� ������ double �� ��������� 0
							 //������ sval ������� � ������ String
		type = UNKNOWN;
	}
	Variable(int i)//������������� ����������� ��� int
	{
		setVaridble(i);
	}
	Variable(double d)//������������� ����������� ��� double
	{
		setVaridble(d);
	}
	Variable(String s)//������������� ����������� ��� String
	{
		setVaridble(s);
	}
	Variable(const Variable& orig)//����������� �����������
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

	void ConvertToInt()//�������������� ������ � INT
	{
		if (type == DOUBLE)
		{
			ival = (int)dval;
			dval = DefaultInt;
		}
		if (type == STRING)
		{
			ival = atoi(sval.getStr());//������������ �������� int-����
			sval.setString("\0");
		}
		type = INT;//��������� ����������� ��� ������
	}

	void ConverToDouble()//�������������� ������ � DOUBLE
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

	void ConvertToString()//�������������� ������ � STRING
	{
		if (type == INT)
		{
			char* buff = new char[255];//������ ��������� ������
			buff = _itoa(ival, buff, 10);//��������������� ����� � ������
			sval.setString(buff);//���������� ��� ������ � �������� sval
			delete[] buff;//������� ������
			ival = DefaultInt;
		}
		if (type == DOUBLE)
		{
			int buff_int = (int)dval;//���������� �� ��������� ���������� �������� �� �������
			char* buff_string = new char[100];//������ ��������� ������ ��� ������
			buff_string = itoa(buff_int, buff_string, 10);//��������������� ����� � ������
			double buff_double = dval - buff_int;//���������� � ����� �������� ����� ����� �� ����� dval
			strcat(buff_string, ".");//���������� � ����� �����������
			size_t count = 0;//���������� �������� ����� ������� � ����� DOUBLE
			size_t count_symbol = countSym(buff_double, &count);//���������� ���������� ������ ����� ����� � buff_double
			buff_double *= pow(10, count_symbol);//�������� �������� � ������ �����, ����� ����������
			int buff = (int)buff_double;
			char* buff_string2 = new char[255];
			buff_string2 = itoa(buff, buff_string2, 10);//���������� � ������ ����� ����� �������
			strcat(buff_string, buff_string2);//���������� � ������ ������ ������
			sval.setString(buff_string);//����� � ������ ������ �� ������
			delete[] buff_string;//����������� ������
			delete[] buff_string2;//����������� ������
			dval = DefaultDouble;//����� �������� �� ���������
		}
		type = STRING;//��������� ����������� ��� ������
	}

	Variable& operator=(const Variable& rhs)//���������� �������� =
	{
		ival = rhs.ival;//������������ ���� �� ��������� INT
		dval = rhs.dval;//������������ ���� �� ��������� DOUBLE
		sval = rhs.sval;//������������ ���� �� ��������� STRING
		type = rhs.type;//������������ ���� �� ��������� TYPE
		return *this;//���������� ��������� �� ������ ����
	}

	//-----------------------------------++++++++++++++++++++++++++++++++++-----------------------------
	Variable operator+(Variable& rhs)//���������� �������� +
	{
		Variable result;//��������� ��������
		if (type == INT)//���� ����� INT
		{
			if (rhs.type == INT)//���� ������ INT
			{
				result.ival = ival + rhs.ival;//���������� ���� � INT ����������
			}
			else if (rhs.type == UNKNOWN)
			{
				cout << "Unknow type of datas... Operation impossible" << endl;
				result.type = UNKNOWN;
				return result;
			}
			else//���� ������ ����� ������ ��� ������
			{
				Variable rhs_convert = rhs.getVariable();//�������� ������ ���������
				rhs_convert.ConvertToInt();//������������ � ��� INT
				result.ival = ival + rhs_convert.ival;//���������� ���� INT
			}
			result.type = INT;//��������� ���������� ���� ������ INT
		}

		if (type == DOUBLE)//���� ����� DOUBLE
		{
			if (rhs.type == DOUBLE)//���� ������ DOUBLE
			{
				result.dval = dval + rhs.dval;//���������� ���� � DOUBLE ����������
			}
			else if (rhs.type == UNKNOWN)
			{
				cout << "Unknow type of datas... Operation impossible" << endl;
				result.type = UNKNOWN;
				return result;
			}
			else//���� ������ ����� ������ ��� ������
			{
				Variable rhs_convert = rhs.getVariable();//�������� ������ ���������
				rhs_convert.ConverToDouble();//������������ � ��� DOUBLE
				result.dval = dval + rhs_convert.dval;//���������� ���� DOUBLE
			}
			result.type = DOUBLE;//��������� ���������� ���� ������ DOUBLE
		}

		if (type == STRING)//���� ����� STRING
		{
			if (rhs.type == STRING)//���� ������ STRING
			{
				result.sval = sval + rhs.sval;//���������� ���� STRING �������
			}
			else if (rhs.type == UNKNOWN)
			{
				cout << "Unknow type of datas... Operation impossible" << endl;
				result.type = UNKNOWN;
				return result;
			}
			else//���� ������ ����� ������ ��� ������
			{
				Variable rhs_convert = rhs.getVariable();//�������� ������ ���������
				rhs_convert.ConvertToString();//������������ � ��� DOUBLE
				result.sval = sval + rhs_convert.sval;//���������� ���� DOUBLE
			}
			result.type = STRING;//��������� ���������� ���� ������ STRING
		}
		return result;
	}

	//-------------------------------------------------------------------------------------------------------
	Variable operator-(Variable& rhs)//���������� �������� -
	{
		Variable result;//��������� ��������
		if (type == INT)//���� ����� INT
		{
			if (rhs.type == INT)//���� ������ INT
			{
				result.ival = ival - rhs.ival;//���������� ���� � INT ����������
			}
			else if (rhs.type == UNKNOWN)
			{
				cout << "Unknow type of datas... Operation impossible" << endl;
				result.type = UNKNOWN;
				return result;
			}
			else//���� ������ ����� ������ ��� ������
			{
				Variable rhs_convert = rhs.getVariable();//�������� ������ ���������
				rhs_convert.ConvertToInt();//������������ � ��� INT
				result.ival = ival - rhs_convert.ival;//���������� ���� INT
			}
			result.type = INT;//��������� ���������� ���� ������ INT
		}

		if (type == DOUBLE)//���� ����� DOUBLE
		{
			if (rhs.type == DOUBLE)//���� ������ DOUBLE
			{
				result.dval = dval - rhs.dval;//���������� ���� � DOUBLE ����������
			}
			else if (rhs.type == UNKNOWN)
			{
				cout << "Unknow type of datas... Operation impossible" << endl;
				result.type = UNKNOWN;
				return result;
			}
			else//���� ������ ����� ������ ��� ������
			{
				Variable rhs_convert = rhs.getVariable();//�������� ������ ���������
				rhs_convert.ConverToDouble();//������������ � ��� DOUBLE
				result.dval = dval - rhs_convert.dval;//���������� ���� DOUBLE
			}
			result.type = DOUBLE;//��������� ���������� ���� ������ DOUBLE
		}

		if (type == STRING)//���� ����� STRING
		{
			if (rhs.type == STRING)//���� ������ STRING
			{
				result.sval = sval - rhs.sval;//�������� ���� STRING �������
			}
			else if (rhs.type == UNKNOWN)
			{
				cout << "Unknow type of datas... Operation impossible" << endl;
				result.type = UNKNOWN;
				return result;
			}
			else//���� ������ ����� ������ ��� ������
			{
				Variable rhs_convert = rhs.getVariable();//�������� ������ ���������
				rhs_convert.ConvertToString();//������������ � ��� DOUBLE
				result.sval = sval - rhs_convert.sval;//���������� ���� DOUBLE
			}
			result.type = STRING;//��������� ���������� ���� ������ STRING
		}
		return result;
	}
	//--------------------******************************---------------------------------------------------
	Variable operator*(Variable& rhs)//���������� �������� *
	{
		Variable result;//��������� ��������
		if (type == INT)//���� ����� INT
		{
			if (rhs.type == INT)//���� ������ INT
			{
				result.ival = ival * rhs.ival;//���������� ���� � INT ����������
			}
			else if (rhs.type == UNKNOWN)
			{
				cout << "Unknow type of datas... Operation impossible" << endl;
				result.type = UNKNOWN;
				return result;
			}
			else//���� ������ ����� ������ ��� ������
			{
				Variable rhs_convert = rhs.getVariable();//�������� ������ ���������
				rhs_convert.ConvertToInt();//������������ � ��� INT
				result.ival = ival * rhs_convert.ival;//���������� ���� INT
			}
			result.type = INT;//��������� ���������� ���� ������ INT
		}

		if (type == DOUBLE)//���� ����� DOUBLE
		{
			if (rhs.type == DOUBLE)//���� ������ DOUBLE
			{
				result.dval = dval * rhs.dval;//���������� ���� � DOUBLE ����������
			}
			else if (rhs.type == UNKNOWN)
			{
				cout << "Unknow type of datas... Operation impossible" << endl;
				result.type = UNKNOWN;
				return result;
			}
			else//���� ������ ����� ������ ��� ������
			{
				Variable rhs_convert = rhs.getVariable();//�������� ������ ���������
				rhs_convert.ConverToDouble();//������������ � ��� DOUBLE
				result.dval = dval * rhs_convert.dval;//���������� ���� DOUBLE
			}
			result.type = DOUBLE;//��������� ���������� ���� ������ DOUBLE
		}

		if (type == STRING)//���� ����� STRING
		{
			if (rhs.type == STRING)//���� ������ STRING
			{
				result.sval = sval * rhs.sval;//�������� ���� STRING �������
			}
			else if (rhs.type == UNKNOWN)
			{
				cout << "Unknow type of datas... Operation impossible" << endl;
				result.type = UNKNOWN;
				return result;
			}
			else//���� ������ ����� ������ ��� ������
			{
				Variable rhs_convert = rhs.getVariable();//�������� ������ ���������
				rhs_convert.ConvertToString();//������������ � ��� DOUBLE
				result.sval = sval * rhs_convert.sval;//���������� ���� DOUBLE
			}
			result.type = STRING;//��������� ���������� ���� ������ STRING
		}
		return result;
	}
	//--------------------//////////////////////////////////--------------------------------------------------
	Variable operator/(Variable& rhs)//���������� �������� /
	{
		Variable result;//��������� ��������
		if (type == INT)//���� ����� INT
		{
			if (rhs.type == INT)//���� ������ INT
			{
				result.ival = ival / rhs.ival;//���������� ���� � INT ����������
			}
			else if (rhs.type == UNKNOWN)
			{
				cout << "Unknow type of datas... Operation impossible" << endl;
				result.type = UNKNOWN;
				return result;
			}
			else//���� ������ ����� ������ ��� ������
			{
				Variable rhs_convert = rhs.getVariable();//�������� ������ ���������
				rhs_convert.ConvertToInt();//������������ � ��� INT
				result.ival = ival / rhs_convert.ival;//���������� ���� INT
			}
			result.type = INT;//��������� ���������� ���� ������ INT
		}

		if (type == DOUBLE)//���� ����� DOUBLE
		{
			if (rhs.type == DOUBLE)//���� ������ DOUBLE
			{
				result.dval = dval / rhs.dval;//���������� ���� � DOUBLE ����������
			}
			else if (rhs.type == UNKNOWN)
			{
				cout << "Unknow type of datas... Operation impossible" << endl;
				result.type = UNKNOWN;
				return result;
			}
			else//���� ������ ����� ������ ��� ������
			{
				Variable rhs_convert = rhs.getVariable();//�������� ������ ���������
				rhs_convert.ConverToDouble();//������������ � ��� DOUBLE
				result.dval = dval / rhs_convert.dval;//���������� ���� DOUBLE
			}
			result.type = DOUBLE;//��������� ���������� ���� ������ DOUBLE
		}

		if (type == STRING)//���� ����� STRING
		{
			if (rhs.type == STRING)//���� ������ STRING
			{
				result.sval = sval / rhs.sval;//�������� ���� STRING �������
			}
			else if (rhs.type == UNKNOWN)
			{
				cout << "Unknow type of datas... Operation impossible" << endl;
				result.type = UNKNOWN;
				return result;
			}
			else//���� ������ ����� ������ ��� ������
			{
				Variable rhs_convert = rhs.getVariable();//�������� ������ ���������
				rhs_convert.ConvertToString();//������������ � ��� DOUBLE
				result.sval = sval / rhs_convert.sval;//���������� ���� DOUBLE
			}
			result.type = STRING;//��������� ���������� ���� ������ STRING
		}
		return result;
	}
	//--------------------+=+=+=+=+=+=+=+=+=+=+=+=+=+=---------------------------------------------------

	Variable& operator+=(Variable& rhs)//���������� �������� +=
	{
		if (type == INT)//���� ����� INT
		{
			if (rhs.type == INT)//���� ������ INT
			{
				ival += rhs.ival;//���������� ���� � INT ����������
			}
			else if (rhs.type == UNKNOWN)
			{
				cout << "Unknow type of datas... Operation impossible" << endl;
			}
			else//���� ������ ����� ������ ��� ������
			{
				Variable rhs_convert = rhs.getVariable();//�������� ������ ���������
				rhs_convert.ConvertToInt();//������������ � ��� INT
				ival += rhs_convert.ival;//���������� ���� INT
			}
		}

		if (type == DOUBLE)//���� ����� DOUBLE
		{
			if (rhs.type == DOUBLE)//���� ������ DOUBLE
			{
				dval += rhs.dval;//���������� ���� � DOUBLE ����������
			}
			else if (rhs.type == UNKNOWN)
			{
				cout << "Unknow type of datas... Operation impossible" << endl;
			}
			else//���� ������ ����� ������ ��� ������
			{
				Variable rhs_convert = rhs.getVariable();//�������� ������ ���������
				rhs_convert.ConverToDouble();//������������ � ��� DOUBLE
				dval += rhs_convert.dval;//���������� ���� DOUBLE
			}
		}

		if (type == STRING)//���� ����� STRING
		{
			if (rhs.type == STRING)//���� ������ STRING
			{
				sval += rhs.sval;//���������� ���� STRING �������
			}
			else if (rhs.type == UNKNOWN)
			{
				cout << "Unknow type of datas... Operation impossible" << endl;
			}
			else//���� ������ ����� ������ ��� ������
			{
				Variable rhs_convert = rhs.getVariable();//�������� ������ ���������
				rhs_convert.ConvertToString();//������������ � ��� DOUBLE
				sval += rhs_convert.sval;//���������� ���� DOUBLE
			}
		}
		return *this;
	}
	//---------------------=-=-=-=-=-=-=-=-=-=-=-=---------------------------------------------------
	Variable& operator-=(Variable& rhs)//���������� �������� -=
	{
		if (type == INT)//���� ����� INT
		{
			if (rhs.type == INT)//���� ������ INT
			{
				ival -= rhs.ival;//���������� ���� � INT ����������
			}
			else if (rhs.type == UNKNOWN)
			{
				cout << "Unknow type of datas... Operation impossible" << endl;
			}
			else//���� ������ ����� ������ ��� ������
			{
				Variable rhs_convert = rhs.getVariable();//�������� ������ ���������
				rhs_convert.ConvertToInt();//������������ � ��� INT
				ival -= rhs_convert.ival;//���������� ���� INT
			}
		}

		if (type == DOUBLE)//���� ����� DOUBLE
		{
			if (rhs.type == DOUBLE)//���� ������ DOUBLE
			{
				dval -= rhs.dval;//���������� ���� � DOUBLE ����������
			}
			else if (rhs.type == UNKNOWN)
			{
				cout << "Unknow type of datas... Operation impossible" << endl;
			}
			else//���� ������ ����� ������ ��� ������
			{
				Variable rhs_convert = rhs.getVariable();//�������� ������ ���������
				rhs_convert.ConverToDouble();//������������ � ��� DOUBLE
				dval -= rhs_convert.dval;//���������� ���� DOUBLE
			}
		}

		if (type == STRING)//���� ����� STRING
		{
			if (rhs.type == STRING)//���� ������ STRING
			{
				sval -= rhs.sval;//���������� ���� STRING �������
			}
			else if (rhs.type == UNKNOWN)
			{
				cout << "Unknow type of datas... Operation impossible" << endl;
			}
			else//���� ������ ����� ������ ��� ������
			{
				Variable rhs_convert = rhs.getVariable();//�������� ������ ���������
				rhs_convert.ConvertToString();//������������ � ��� DOUBLE
				sval -= rhs_convert.sval;//���������� ���� DOUBLE
			}
		}
		return *this;
	}
	//---------------------*=*=*=*=*=*=*=*=*=*=*=*=*=*=*---------------------------------------------------
	Variable& operator*=(Variable& rhs)//���������� �������� *=
	{
		if (type == INT)//���� ����� INT
		{
			if (rhs.type == INT)//���� ������ INT
			{
				ival *= rhs.ival;//���������� ���� � INT ����������
			}
			else if (rhs.type == UNKNOWN)
			{
				cout << "Unknow type of datas... Operation impossible" << endl;
			}
			else//���� ������ ����� ������ ��� ������
			{
				Variable rhs_convert = rhs.getVariable();//�������� ������ ���������
				rhs_convert.ConvertToInt();//������������ � ��� INT
				ival *= rhs_convert.ival;//���������� ���� INT
			}
		}

		if (type == DOUBLE)//���� ����� DOUBLE
		{
			if (rhs.type == DOUBLE)//���� ������ DOUBLE
			{
				dval *= rhs.dval;//���������� ���� � DOUBLE ����������
			}
			else if (rhs.type == UNKNOWN)
			{
				cout << "Unknow type of datas... Operation impossible" << endl;
			}
			else//���� ������ ����� ������ ��� ������
			{
				Variable rhs_convert = rhs.getVariable();//�������� ������ ���������
				rhs_convert.ConverToDouble();//������������ � ��� DOUBLE
				dval *= rhs_convert.dval;//���������� ���� DOUBLE
			}
		}

		if (type == STRING)//���� ����� STRING
		{
			if (rhs.type == STRING)//���� ������ STRING
			{
				sval *= rhs.sval;//���������� ���� STRING �������
			}
			else if (rhs.type == UNKNOWN)
			{
				cout << "Unknow type of datas... Operation impossible" << endl;
			}
			else//���� ������ ����� ������ ��� ������
			{
				Variable rhs_convert = rhs.getVariable();//�������� ������ ���������
				rhs_convert.ConvertToString();//������������ � ��� DOUBLE
				sval *= rhs_convert.sval;//���������� ���� DOUBLE
			}
		}
		return *this;
	}
	//---------------------/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=/=---------------------------------------------------
	Variable& operator/=(Variable& rhs)//���������� �������� /=
	{
		if (type == INT)//���� ����� INT
		{
			if (rhs.type == INT)//���� ������ INT
			{
				ival /= rhs.ival;//���������� ���� � INT ����������
			}
			else if (rhs.type == UNKNOWN)
			{
				cout << "Unknow type of datas... Operation impossible" << endl;
			}
			else//���� ������ ����� ������ ��� ������
			{
				Variable rhs_convert = rhs.getVariable();//�������� ������ ���������
				rhs_convert.ConvertToInt();//������������ � ��� INT
				ival /= rhs_convert.ival;//���������� ���� INT
			}
		}

		if (type == DOUBLE)//���� ����� DOUBLE
		{
			if (rhs.type == DOUBLE)//���� ������ DOUBLE
			{
				dval /= rhs.dval;//���������� ���� � DOUBLE ����������
			}
			else if (rhs.type == UNKNOWN)
			{
				cout << "Unknow type of datas... Operation impossible" << endl;
			}
			else//���� ������ ����� ������ ��� ������
			{
				Variable rhs_convert = rhs.getVariable();//�������� ������ ���������
				rhs_convert.ConverToDouble();//������������ � ��� DOUBLE
				dval /= rhs_convert.dval;//���������� ���� DOUBLE
			}
		}

		if (type == STRING)//���� ����� STRING
		{
			if (rhs.type == STRING)//���� ������ STRING
			{
				sval /= rhs.sval;//���������� ���� STRING �������
			}
			else if (rhs.type == UNKNOWN)
			{
				cout << "Unknow type of datas... Operation impossible" << endl;
			}
			else//���� ������ ����� ������ ��� ������
			{
				Variable rhs_convert = rhs.getVariable();//�������� ������ ���������
				rhs_convert.ConvertToString();//������������ � ��� DOUBLE
				sval /= rhs_convert.sval;//���������� ���� DOUBLE
			}
		}
		return *this;
	}
	void show()//����� ������� � ������� ���������
	{
		if (type == INT)//���� ��� INT
		{
			cout << ival << endl;
		}
		if (type == DOUBLE)//���� ��� DOUBLE
		{
			cout << dval << endl;
		}
		if (type == STRING)//���� ��� STRING
		{
			sval.show();
		}
		if (type == UNKNOWN)//���� ��� ����������
		{
			cout << "ERROR TYPE" << endl;
		}
	}
};

int main()
{
	Variable InT = 555;//��������� INT ����������
	cout << endl;
	cout << "int: ";
	InT.show();
	cout << endl;
	Variable DoU = 10.258;//��������� DOUBLE ����������
	cout << "Double: ";
	DoU.show();
	cout << endl;
	Variable StR = "25454 test!!! ";//��������� STRING ����������
	Variable StR2 = "2test";//��� ��������� � ������� ������
	cout << "String: ";
	StR.show();
	cout << endl;
	cout << "--------------------------------------" << endl;
	cout << "************ operator + **************" << endl;
	cout << "--------------------------------------" << endl;
	Variable result = InT + InT;
	cout << "int + int: ";
	result.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	result = InT + DoU;
	cout << "int + double: ";
	result.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	result = InT + StR;
	cout << "int + string: ";
	result.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	cout << "--------------------------------------" << endl;
	cout << "double + double: ";
	result = DoU + DoU;
	result.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	cout << "double + int: ";
	result = DoU + InT;
	result.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	cout << "double + string: ";
	result = DoU + StR;
	result.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	cout << "--------------------------------------" << endl;
	cout << "string + int: ";
	result = StR + InT;
	result.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	cout << "string + double: ";
	result = StR + DoU;
	result.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	cout << "string + string: ";
	result = StR + StR;
	result.show();//������� ��������� � �������

	cout << "--------------------------------------" << endl;
	cout << "************ operator - **************" << endl;
	cout << "--------------------------------------" << endl;
	result = InT - InT;
	cout << "int - int: ";
	result.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	result = InT - DoU;
	cout << "int - double: ";
	result.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	result = InT - StR;
	cout << "int - string: ";
	result.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	cout << "--------------------------------------" << endl;
	cout << "double - double: ";
	result = DoU - DoU;
	result.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	cout << "double - int: ";
	result = DoU - InT;
	result.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	cout << "double - string: ";
	result = DoU - StR;
	result.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	cout << "--------------------------------------" << endl;
	cout << "string - int: ";
	result = StR - InT;
	result.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	cout << "string - double: ";
	result = StR - DoU;
	result.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	cout << "string - string: ";
	result = StR - StR;
	result.show();//������� ��������� � �������

	cout << "--------------------------------------" << endl;
	cout << "*********** operator *  **************" << endl;
	cout << "--------------------------------------" << endl;
	result = InT * InT;
	cout << "int * int: ";
	result.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	result = InT * DoU;
	cout << "int * double: ";
	result.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	result = InT * StR;
	cout << "int * string: ";
	result.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	cout << "--------------------------------------" << endl;
	cout << "double * double: ";
	result = DoU * DoU;
	result.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	cout << "double * int: ";
	result = DoU * InT;
	result.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	cout << "double * string: ";
	result = DoU * StR;
	result.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	cout << "--------------------------------------" << endl;
	cout << "string * int: ";
	result = StR * InT;
	result.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	cout << "string * double: ";
	result = StR * DoU;
	result.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	cout << "string * string: ";
	result = StR * StR2;
	result.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	cout << "*********** operator /  **************" << endl;
	cout << "--------------------------------------" << endl;
	result = InT / InT;
	cout << "int / int: ";
	result.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	result = InT / DoU;
	cout << "int / double: ";
	result.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	result = InT / StR;
	cout << "int / string: ";
	result.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	cout << "--------------------------------------" << endl;
	cout << "double / double: ";
	result = DoU / DoU;
	result.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	cout << "double / int: ";
	result = DoU / InT;
	result.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	cout << "double / string: ";
	result = DoU / StR;
	result.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	cout << "--------------------------------------" << endl;
	cout << "string / int: ";
	result = StR / InT;
	result.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	cout << "string / double: ";
	result = StR / DoU;
	result.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	cout << "string / string: ";
	result = StR / StR2;
	result.show();//������� ��������� � �������


	cout << "--------------------------------------" << endl;
	cout << "************ operator += **************" << endl;
	cout << "--------------------------------------" << endl;
	InT += InT;
	cout << "int += int: ";
	InT.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	InT += DoU;
	cout << "int += double: ";
	InT.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	InT += StR;
	cout << "int += string: ";
	InT.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	cout << "--------------------------------------" << endl;
	cout << "double += double: ";
	DoU += DoU;
	DoU.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	cout << "double += int: ";
	DoU += InT;
	DoU.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	cout << "double += string: ";
	DoU += StR;
	DoU.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	Variable InT2 = 45;
	Variable DoU2 = 12.36;
	Variable StR22 = "1no";
	cout << "--------------------------------------" << endl;
	cout << "string += int: ";
	StR2 += InT2;
	StR2.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	Variable StR6 = "25454 test!!! ";
	Variable DoU6 = 10.236;
	Variable InT6 = 555;
	cout << "string += double: ";
	StR6 += DoU6;
	StR6.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	cout << "string += string: ";
	StR2 += StR6;
	StR2.show();//������� ��������� � �������


	cout << "--------------------------------------" << endl;
	cout << "*********** operator -= **************" << endl;
	cout << "--------------------------------------" << endl;
	Variable StR3 = "25454 test!!! ";
	Variable DoU3 = 10.236;
	Variable InT3 = 555;
	InT3 -= InT3;
	cout << "int -= int: ";
	InT3.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	InT3 -= DoU3;
	cout << "int -= double: ";
	InT3.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	InT3 -= StR3;
	cout << "int -= string: ";
	InT3.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	cout << "--------------------------------------" << endl;
	cout << "double -= double: ";
	DoU3 -= DoU3;
	DoU3.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	cout << "double -= int: ";
	DoU3 -= InT3;
	DoU3.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	cout << "double -= string: ";
	DoU3 -= StR3;
	DoU3.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	cout << "--------------------------------------" << endl;
	cout << "string -= int: ";
	StR3 -= InT3;
	StR3.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	Variable StR4 = "25454 test!!! ";
	Variable DoU4 = 10.236;
	Variable InT4 = 555;
	cout << "string -= double: ";
	StR4 -= DoU4;
	StR4.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	Variable StR5 = "25454 test!!! ";
	Variable DoU5 = 10.236;
	Variable InT5 = 555;
	cout << "string -= string: ";
	StR5 -= StR5;
	StR5.show();//������� ��������� � �������

	cout << "--------------------------------------" << endl;
	cout << "********** operator *=  **************" << endl;
	cout << "--------------------------------------" << endl;
	InT5 *= InT5;
	cout << "int *= int: ";
	InT5.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	InT5 *= DoU5;
	cout << "int *= double: ";
	InT5.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	InT5 *= StR5;
	cout << "int *= string: ";
	InT5.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	cout << "--------------------------------------" << endl;
	cout << "double *= double: ";
	DoU5 *= DoU5;
	InT5.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	cout << "double *= int: ";
	DoU5 *= InT5;
	InT5.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	Variable StR7 = "25454 test!!! ";
	Variable DoU7 = 10.236;
	Variable InT7 = 555;
	cout << "double *= string: ";
	DoU7 *= StR7;
	DoU7.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	cout << "--------------------------------------" << endl;
	cout << "string *= int: ";
	StR7 *= InT7;
	StR7.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	cout << "string *= double: ";
	StR7 *= DoU7;
	StR7.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	Variable StR8 = "25454 test";
	cout << "string *= string: ";
	StR8 *= StR8;
	StR8.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	cout << "*********** operator /=  **************" << endl;
	cout << "--------------------------------------" << endl;
	InT /= InT;
	cout << "int /= int: ";
	InT.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	InT /= DoU;
	cout << "int /= double: ";
	InT.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	InT /= StR;
	cout << "int /= string: ";
	InT.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	cout << "--------------------------------------" << endl;
	cout << "double /= double: ";
	DoU /= DoU;
	DoU.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	cout << "double /= int: ";
	DoU /= InT;
	DoU.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	cout << "double /= string: ";
	DoU /= StR;
	DoU.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	cout << "--------------------------------------" << endl;
	cout << "string /= int: ";
	StR /= InT;
	StR.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	cout << "string /= double: ";
	StR /= DoU;
	StR.show();//������� ��������� � �������
	cout << "--------------------------------------" << endl;
	cout << "string /= string: ";
	StR /= StR2;
	StR.show();//������� ��������� � �������


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

