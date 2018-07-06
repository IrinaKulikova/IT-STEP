#include "stdafx.h"
#pragma warning(disable:4996)

void MathEval::next_var(char** equation, Stack<double>* Arguments, int* size_str)//получение следующего аргумента
{
	double buff = NULL;//запоминуем число, которое будем вталкивать в стек
	buff = atof(*equation);

	char add = '+';
	char subt = '-';
	char multy = '*';
	char divi = '/';
	char separ = '.';

	(*Arguments).push(buff);
	int all_move = 0;//запоминаем на сколько строка уменьшилась
	int i = 0;//счётчик символов строки
	for (; i < (*size_str); i++)//перебираем строку, ищем где число заканчивается, либо точку, то есть дрорбное число
								//принимаем точность дробного числа - 1 знак после запятой
								//иначе ошибка будет в вычислениях
	{
		if ((*equation)[i] == separ)//если встретили дробное число
		{
			all_move = i;
			for (int j = i + 2; j < (*size_str) + 1; j++)//переписываем строку
			{
				(*equation)[j - i - 2] = (*equation)[j];
			}
			(*size_str) -= all_move;
			if ((*equation)[i - 2] == '\0')//если конец строки
			{
				(*size_str) = 0;
			}
			return;
		}
		if ((*equation)[i] == multy || (*equation)[i] == divi || (*equation)[i] == add || (*equation)[i] == subt)//если встретили операцию
		{
			all_move = i;
			for (int j = i; j < (*size_str) + 1; j++)//переписываем строку 
			{
				(*equation)[j - i] = (*equation)[j];
			}
			(*size_str) -= all_move;
			/*if ((*equation)[i] == '\0')//если конец строки
			{
				(*size_str) = 0;
			}*/
			return;
		}
		if ((*equation)[i] == '\0')//если конец строки
		{
			(*size_str) = 0;
		}
	}
}

void MathEval::next_oper(char** equation, Stack<char>* Operators, int* size_str)//добавление следующей операции в стек
{
	(*Operators).push((*equation)[0]);
	*size_str = strlen(*equation);
	for (int i = 0; i < (*size_str); i++)//gthtgbcsdftv cnhjre
	{
		(*equation)[i] = (*equation)[i + 1];
	}
}

bool MathEval::DoubleOperators(char x, char y)//наличие совпадения
{
	const int size_str = 5;//длина статической строки с опервторами
	char numbers[size_str] = "*/-+";//цифры и операции
	bool check_x = false;
	bool check_y = false;
	for (int j = 0; j < size_str - 1; j++)//перебираем строку с выражением
	{
		if (x == numbers[j])//если в строке operator
		{
			check_x = true;//совпадение найдено
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
		if (DoubleOperators(equation[i], equation[i + 1]))//перебираем строку, ищем 2 операции подряд, и с учетом математики, исправляем строку
		{
			if ((equation[i] == subt && equation[i + 1] == add) || (equation[i] == add && equation[i + 1] == subt))
			{
				equation[i] = subt;//заменяем операцию
				int j = i + 1;
				for (; j < size; j++)//переписываем строку
				{
					equation[j] = equation[j + 1];
				}
			}
			if (equation[i] == subt && equation[i + 1] == subt || (equation[i] == add && equation[i + 1] == add))
			{
				equation[i] = add;//заменяем операцию
				int j = i + 1;
				for (; j < size; j++)
				{
					equation[j] = equation[j + 1];
				}
			}
			if ((equation[i] == multy && equation[i + 1] == add) || (equation[i] == add && equation[i + 1] == multy))
			{
				equation[i] = multy;//заменяем операцию
				int j = i + 1;
				for (; j < size; j++)
				{
					equation[j] = equation[j + 1];
				}
			}
			if ((equation[i] == divi && equation[i + 1] == add) || (equation[i] == add && equation[i + 1] == divi))
			{
				equation[i] = divi;//заменяем операцию
				int j = i + 1;
				for (; j < size; j++)
				{
					equation[j] = equation[j + 1];
				}
			}
			if ((equation[i] == divi && equation[i + 1] == subt) || (equation[i] == subt && equation[i + 1] == divi))
			{
				equation[i] = divi;//заменяем операцию
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
				equation[i] = multy;//заменяем операцию
				int j = i + 1;
				for (; j < size; j++)
				{
					equation[j] = equation[j + 1];
				}
			}
		}
	}
}

MathEval::MathEval(char* equation)//метод принимает строку и парсит её
{
	ChekStringOperators(equation);//проверяем чтоб операции не дублировались, корректируем строку

	Stack<double> Arguments;//стек аргументов выражения
	Stack<char> Operators;//стек опереаций

	if (equation == NULL)//если строка пустая
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
			next_var(&Equation, &Arguments, &size_str);//добавление в стек аргументов следующего аргумента
		}
		else
		{
			if (Equation[0] == multy || Equation[0] == divi)//анализируем первый символ в строке
															//* и / выполняем на месте
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
			else// + или - отправляем в стек
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

	calculator(&Arguments, &Operators);//производим вычисление результата
}

void MathEval::calculator(Stack<double>* Arguments, Stack<char>* Operators)//метод возвращает результат вычислений
{
	int count = (*Operators).size();//определяем размер стека операций
	int count_arg = (*Arguments).size();//определяем размер стека аргументов
	result = (*Arguments).pop();//выталкиваем первый аргумент

	char add = '+';//опереация сложения
	char subt = '-';//опереация вычитания

	double arg;//аргумент
	char operat;//оператор
	char oper_before;//предидущий оператор
	for (int i = 0; i < count; i++)
	{
		arg = (*Arguments).pop();//выталкиваем следующий аргумент
		operat = (*Operators).pop();//выталкиваем следующюю операция
		oper_before = (*Operators).peek();//подсматриваем вершину операций
		if (count >= count_arg && i == count - 1)//если количество операций больше чем аргументов, принимаем аргумент равный 0
												//(так как вы пофиксили дублирующиеся операции в соответствии с приоритетами в методе
												// ChekStringOperators(char*), то в этот иф мы заходим, если у нас строка
												// начинается с минуся и мы предполаеме перед минусом аргумент равный 0)
		{
			arg = 0;
		}

		if (oper_before == subt && operat == add)//если на вершине минус, и текущий плюс
		{
			arg *= (-1);
			char buf = (*Operators).pop();
			buf = '+';
			(*Operators).push(buf);
		}

		if (oper_before == subt && operat == subt)//если на вершине минус, и текущий минус
		{
			operat = add;
		}

		if (operat == add)//если на вершине плюс
		{
			arg += result;
		}
		if (operat == subt)//если на вершине минус
		{
			arg -= result;
		}
		result = arg;
	}
}

double MathEval::eval()//метод возвращает результат вычислений
{
	return result;
}