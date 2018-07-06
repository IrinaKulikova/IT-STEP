#pragma once

class MathEval//класс подсчёта результата
{
private:
	double result;//результат вычислений
	void next_var(char**, Stack<double>*, int*);
	void MathEval::next_oper(char**, Stack<char>*, int*);
	void calculator(Stack<double>*, Stack<char>*);//метод подсчитывает результат
	void ChekStringOperators(char*);//проверка на повторение операторов в строке
	bool DoubleOperators(char, char);//наличие совпадения
public:
	double eval();//вывод результаты уравнения
	MathEval(char*);//метод который парсит строку и считает результат
};

