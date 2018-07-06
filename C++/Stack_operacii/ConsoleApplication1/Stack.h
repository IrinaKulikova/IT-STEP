#pragma once

template <typename T>
class Stack//класс стек
{
private:
	unique_ptr<T[]> stack;//стек
	int count;//размер фактических данных
	int stack_size;//размер выделенной памяти под массив stack
	const int grow = 10;//конста резерва
public:
	Stack<T>();//конструктор по умолчанию
	void push(T);//метод добавления в стек
	T pop();//метод изъятия из стека
	T peek();//метод простотра последних добавленных данных в стек
	int size();//метод возвращает размер стека
	bool empty();//метод проверки наличия данных в стеке
};