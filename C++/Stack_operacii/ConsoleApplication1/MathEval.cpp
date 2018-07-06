#include "stdafx.h"
#pragma warning(disable:4996)

void MathEval::next_var(char** equation, Stack<double>* Arguments, int* size_str)//��������� ���������� ���������
{
	double buff = NULL;//���������� �����, ������� ����� ���������� � ����
	buff = atof(*equation);

	char add = '+';
	char subt = '-';
	char multy = '*';
	char divi = '/';
	char separ = '.';

	(*Arguments).push(buff);
	int all_move = 0;//���������� �� ������� ������ �����������
	int i = 0;//������� �������� ������
	for (; i < (*size_str); i++)//���������� ������, ���� ��� ����� �������������, ���� �����, �� ���� �������� �����
								//��������� �������� �������� ����� - 1 ���� ����� �������
								//����� ������ ����� � �����������
	{
		if ((*equation)[i] == separ)//���� ��������� ������� �����
		{
			all_move = i;
			for (int j = i + 2; j < (*size_str) + 1; j++)//������������ ������
			{
				(*equation)[j - i - 2] = (*equation)[j];
			}
			(*size_str) -= all_move;
			if ((*equation)[i - 2] == '\0')//���� ����� ������
			{
				(*size_str) = 0;
			}
			return;
		}
		if ((*equation)[i] == multy || (*equation)[i] == divi || (*equation)[i] == add || (*equation)[i] == subt)//���� ��������� ��������
		{
			all_move = i;
			for (int j = i; j < (*size_str) + 1; j++)//������������ ������ 
			{
				(*equation)[j - i] = (*equation)[j];
			}
			(*size_str) -= all_move;
			/*if ((*equation)[i] == '\0')//���� ����� ������
			{
				(*size_str) = 0;
			}*/
			return;
		}
		if ((*equation)[i] == '\0')//���� ����� ������
		{
			(*size_str) = 0;
		}
	}
}

void MathEval::next_oper(char** equation, Stack<char>* Operators, int* size_str)//���������� ��������� �������� � ����
{
	(*Operators).push((*equation)[0]);
	*size_str = strlen(*equation);
	for (int i = 0; i < (*size_str); i++)//gthtgbcsdftv cnhjre
	{
		(*equation)[i] = (*equation)[i + 1];
	}
}

bool MathEval::DoubleOperators(char x, char y)//������� ����������
{
	const int size_str = 5;//����� ����������� ������ � �����������
	char numbers[size_str] = "*/-+";//����� � ��������
	bool check_x = false;
	bool check_y = false;
	for (int j = 0; j < size_str - 1; j++)//���������� ������ � ����������
	{
		if (x == numbers[j])//���� � ������ operator
		{
			check_x = true;//���������� �������
		}
		if (y == numbers[j])
		{
			check_y = true;
		}
	}

	if (check_x && check_y)
	{
		return true;
	}
	return false;
}

void MathEval::ChekStringOperators(char* equation)
{
	int size = strlen(equation);
	char buf;
	char before_buf;

	char add = '+';
	char subt = '-';
	char multy = '*';
	char divi = '/';


	for (int i = 0; i < size - 1; i++)
	{
		if (DoubleOperators(equation[i], equation[i + 1]))//���������� ������, ���� 2 �������� ������, � � ������ ����������, ���������� ������
		{
			if ((equation[i] == subt && equation[i + 1] == add) || (equation[i] == add && equation[i + 1] == subt))
			{
				equation[i] = subt;//�������� ��������
				int j = i + 1;
				for (; j < size; j++)//������������ ������
				{
					equation[j] = equation[j + 1];
				}
			}
			if (equation[i] == subt && equation[i + 1] == subt || (equation[i] == add && equation[i + 1] == add))
			{
				equation[i] = add;//�������� ��������
				int j = i + 1;
				for (; j < size; j++)
				{
					equation[j] = equation[j + 1];
				}
			}
			if ((equation[i] == multy && equation[i + 1] == add) || (equation[i] == add && equation[i + 1] == multy))
			{
				equation[i] = multy;//�������� ��������
				int j = i + 1;
				for (; j < size; j++)
				{
					equation[j] = equation[j + 1];
				}
			}
			if ((equation[i] == divi && equation[i + 1] == add) || (equation[i] == add && equation[i + 1] == divi))
			{
				equation[i] = divi;//�������� ��������
				int j = i + 1;
				for (; j < size; j++)
				{
					equation[j] = equation[j + 1];
				}
			}
			if ((equation[i] == divi && equation[i + 1] == subt) || (equation[i] == subt && equation[i + 1] == divi))
			{
				equation[i] = divi;//�������� ��������
				for (int k = i; k > 0; k--)
				{
					if (equation[k] == subt)
					{
						equation[k] = add;
						break;
					}
					if (equation[k] == add)
					{
						equation[k] = subt;
						break;
					}
				}
				int j = i + 1;
				for (; j < size; j++)
				{
					equation[j] = equation[j + 1];
				}
			}
			if (equation[i] == multy && equation[i + 1] == divi || (equation[i] == divi && equation[i + 1] == multy))
			{
				equation[i] = multy;//�������� ��������
				int j = i + 1;
				for (; j < size; j++)
				{
					equation[j] = equation[j + 1];
				}
			}
		}
	}
}

MathEval::MathEval(char* equation)//����� ��������� ������ � ������ �
{
	ChekStringOperators(equation);//��������� ���� �������� �� �������������, ������������ ������

	Stack<double> Arguments;//���� ���������� ���������
	Stack<char> Operators;//���� ���������

	if (equation == NULL)//���� ������ ������
	{
		return;
	}

	int size_str = strlen(equation);
	char* Equation = new char[size_str + 1];
	strcpy(Equation, equation);

	char multy = '*';
	char divi = '/';

	size_str = strlen(Equation);

	while (size_str != 0)
	{
		if (isdigit(Equation[0]))
		{
			next_var(&Equation, &Arguments, &size_str);//���������� � ���� ���������� ���������� ���������
		}
		else
		{
			if (Equation[0] == multy || Equation[0] == divi)//����������� ������ ������ � ������
															//* � / ��������� �� �����
			{
				double buff = Arguments.pop();
				next_oper(&Equation, &Operators, &size_str);
				next_var(&Equation, &Arguments, &size_str);
				double buff_2 = Arguments.pop();
				char del = Operators.pop();
				if (del == multy)
				{
					buff *= buff_2;
				}
				if (del == divi)
				{
					buff /= buff_2;
				}
				Arguments.push(buff);
			}
			else// + ��� - ���������� � ����
			{
				next_oper(&Equation, &Operators, &size_str);
			}
		}

		if (!size_str)
		{
			delete[] Equation;
			Equation = NULL;
			size_str = 0;
		}
	}

	calculator(&Arguments, &Operators);//���������� ���������� ����������
}

void MathEval::calculator(Stack<double>* Arguments, Stack<char>* Operators)//����� ���������� ��������� ����������
{
	int count = (*Operators).size();//���������� ������ ����� ��������
	int count_arg = (*Arguments).size();//���������� ������ ����� ����������
	result = (*Arguments).pop();//����������� ������ ��������

	char add = '+';//��������� ��������
	char subt = '-';//��������� ���������

	double arg;//��������
	char operat;//��������
	char oper_before;//���������� ��������
	for (int i = 0; i < count; i++)
	{
		arg = (*Arguments).pop();//����������� ��������� ��������
		operat = (*Operators).pop();//����������� ��������� ��������
		oper_before = (*Operators).peek();//������������� ������� ��������
		if (count >= count_arg && i == count - 1)//���� ���������� �������� ������ ��� ����������, ��������� �������� ������ 0
												//(��� ��� �� ��������� ������������� �������� � ������������ � ������������ � ������
												// ChekStringOperators(char*), �� � ���� �� �� �������, ���� � ��� ������
												// ���������� � ������ � �� ����������� ����� ������� �������� ������ 0)
		{
			arg = 0;
		}

		if (oper_before == subt && operat == add)//���� �� ������� �����, � ������� ����
		{
			arg *= (-1);
			char buf = (*Operators).pop();
			buf = '+';
			(*Operators).push(buf);
		}

		if (oper_before == subt && operat == subt)//���� �� ������� �����, � ������� �����
		{
			operat = add;
		}

		if (operat == add)//���� �� ������� ����
		{
			arg += result;
		}
		if (operat == subt)//���� �� ������� �����
		{
			arg -= result;
		}
		result = arg;
	}
}

double MathEval::eval()//����� ���������� ��������� ����������
{
	return result;
}