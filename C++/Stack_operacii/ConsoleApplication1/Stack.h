#pragma once

template <typename T>
class Stack//����� ����
{
private:
	unique_ptr<T[]> stack;//����
	int count;//������ ����������� ������
	int stack_size;//������ ���������� ������ ��� ������ stack
	const int grow = 10;//������ �������
public:
	Stack<T>();//����������� �� ���������
	void push(T);//����� ���������� � ����
	T pop();//����� ������� �� �����
	T peek();//����� ��������� ��������� ����������� ������ � ����
	int size();//����� ���������� ������ �����
	bool empty();//����� �������� ������� ������ � �����
};