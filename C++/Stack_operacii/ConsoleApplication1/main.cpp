// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#pragma warning(disable:4996)

//1. ������� �������� ������� ������ ������� ��������������� ��������� https ://habrahabr.ru/post/50196/
//2. ����������� ����� MathEval ��� ������� �������������� ���������. �������� ������ ����������

void test()
{
	auto string1 = unique_ptr<char[]>(new char[50]);
	strcpy(string1.get(), "1+-9");
	cout << "Expression: " << string1.get() << endl;
	MathEval Result_Exp_test1(string1.get());
	cout << "Result of calculation: " << Result_Exp_test1.eval() << endl;//��������� ���������
	cout << "---------------------------------------\n" << endl;

	strcpy(string1.get(), "-1+-9");
	cout << "Expression: " << string1.get() << endl;
	MathEval Result_Exp_test2(string1.get());
	cout << "Result of calculation: " << Result_Exp_test2.eval() << endl;//��������� ���������
	cout << "---------------------------------------\n" << endl;

	strcpy(string1.get(), "-2/2+3");
	cout << "Expression: " << string1.get() << endl;
	MathEval Result_Exp_test3(string1.get());
	cout << "Result of calculation: " << Result_Exp_test3.eval() << endl;//��������� ���������
	cout << "---------------------------------------\n" << endl;

	strcpy(string1.get(), "-6/4+-1");
	cout << "Expression: " << string1.get() << endl;
	MathEval Result_Exp_test4(string1.get());
	cout << "Result of calculation: " << Result_Exp_test4.eval() << endl;//��������� ���������
	cout << "---------------------------------------\n" << endl;

	strcpy(string1.get(), "2+3*-8");
	cout << "Expression: " << string1.get() << endl;
	MathEval Result_Exp_test5(string1.get());
	cout << "Result of calculation: " << Result_Exp_test5.eval() << endl;//��������� ���������
	cout << "---------------------------------------\n" << endl;

	strcpy(string1.get(), "8+3/-4");
	cout << "Expression: " << string1.get() << endl;
	MathEval Result_Exp_test6(string1.get());
	cout << "Result of calculation: " << Result_Exp_test6.eval() << endl;//��������� ���������
	cout << "---------------------------------------\n" << endl;

	strcpy(string1.get(), "-10.2/2-4");
	cout << "Expression: " << string1.get() << endl;
	MathEval Result_Exp_test7(string1.get());
	cout << "Result of calculation: " << Result_Exp_test7.eval() << endl;//��������� ���������
	cout << "---------------------------------------\n" << endl;

	strcpy(string1.get(), "-10-+10-10.2");
	cout << "Expression: " << string1.get() << endl;
	MathEval Result_Exp_test8(string1.get());
	cout << "Result of calculation: " << Result_Exp_test8.eval() << endl;//��������� ���������
	cout << "---------------------------------------\n" << endl;

}


int main()
{
	test();

	char answer;
	do {
		const int size = 255;//������ ������ ���������
		char* Expression = new char[size];
		do {
			cout << "Enter mathematical expression: ";
			cin >> Expression;
		} while (!CheckInputs(Expression));//�������� ���� � ��������� �� ���� ���������
		MathEval Result_Expression(Expression);//������ �����, ��� ���������� ���������� ���������
		cout << "Result of calculation: " << Result_Expression.eval() << endl;//��������� ���������	
		delete[] Expression;
		cout << "-----------------------------------\n" << endl;
		cout << "more test? yes - y, no - n:";
		cin >> answer;
	} while (answer != 'n');
	cout << "Good bay!" << endl;
	return 0;
}