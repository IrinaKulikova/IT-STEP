#include "stdafx.h"
#include "Stack.h"
#pragma warning(disable:4996)

template <typename T>
Stack<T>::Stack<T>()
{
	count = -1;//индекс отсутствия данных в стеке
	stack_size = grow;//изначальный размер стека
	stack.reset(new T[stack_size]);
}

template <typename T>
void Stack<T>::push(T item)
{
	count++;// индекс нового элемента
	if (count >= stack_size)
	{
		T* tmp = new T[stack_size + grow];
		for (int i = 0; i < stack_size; i++)
		{
			tmp[i] = stack[i];
		}
		stack.reset(tmp);
		stack_size += grow;
	}
	stack[count] = item;
}

template <typename T>
T Stack<T>::pop()
{
	return stack[count--];
}

template <typename T>
T Stack<T>::peek()
{
	return stack[count];
}

template <typename T>
int Stack<T>::size()
{
	return count + 1;
}

template <typename T>
bool Stack<T>::empty()
{
	return count < 0;
}

template class Stack<double>;
template class Stack<char>;