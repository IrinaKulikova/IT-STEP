#pragma once

class MathEval//����� �������� ����������
{
private:
	double result;//��������� ����������
	void next_var(char**, Stack<double>*, int*);
	void MathEval::next_oper(char**, Stack<char>*, int*);
	void calculator(Stack<double>*, Stack<char>*);//����� ������������ ���������
	void ChekStringOperators(char*);//�������� �� ���������� ���������� � ������
	bool DoubleOperators(char, char);//������� ����������
public:
	double eval();//����� ���������� ���������
	MathEval(char*);//����� ������� ������ ������ � ������� ���������
};

