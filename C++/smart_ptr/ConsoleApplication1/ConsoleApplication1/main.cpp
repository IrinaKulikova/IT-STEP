#include <iostream>
using namespace std;
#pragma warning(disable:4996)

class Something//любой класс
{
	char* name;//поле имя класса
	size_t count;//поле количества
public:
	Something() //конструктор по умолчанию
	{
		name = NULL;
		count = 0;
	}
	Something(const char* name, size_t count) //конструктор с заданными параметрами
	{
		this->name = new char[strlen(name) + 1];//выделяем память
		strcpy(this->name, name);//переписываем имя
		this->count = count;//переписываем занчение
	}
	void SetZeroCount()//увеличиваем количество
	{
		count = 0;//инкриментируем счётчик
	}
	void SetCount(size_t count)//сеттер для количества
	{
		this->count = count;
	}
	void SetName(char* name)//сеттер для имени
	{
		if (this->name != NULL)//если имя не пустое поле, освобождаем память
		{
			delete[] this->name;
			this->name = NULL;
		}
		if (name != NULL)//если новое имя не пустое, переписываем новое имя
		{
			this->name = new char[strlen(name) + 1];
			strcpy(this->name, name);
		}
	}
	Something(const Something& orig)//конструктор копирования
	{
		if (orig.name != NULL)
		{
			name = new char[strlen(orig.name) + 1];
			strcpy(name, orig.name);
		}
		else
		{
			name = NULL;
		}
		count = orig.count;//переписываем количество
	}
	Something& operator=(const Something& orig)//оператор присвоения
	{
		if (name != NULL)
		{
			delete[] name;
			name = NULL;
		}
		if (orig.name != NULL)
		{
			name = new char[strlen(orig.name) + 1];
			strcpy(name, orig.name);
		}
		count = orig.count;//переписываем количество
		return *this;//возвращаем указатель на самого себя
	}
	~Something()//деструктор
	{
		if (name != NULL)//если в поле имя что-то есть, освобождаем память
		{
			cout << "destructor" << endl;
			delete[] name;
		}
	}
	void show()//выводим информацию в консоль
	{
		cout << "Name" << name << endl;
		cout << "Count: " << count << endl;
		cout << "------------------------------" << endl;
	}
};

class SmartPtr//класс-умный указатель
{
	Something* object;//указатель на объект
	size_t CountPtr;//номер указателя
public:
	SmartPtr(Something* object)//конструктор по умолчанию
	{
		this->object = object;//копируем указатель на объект
		CountPtr = 1;//номер указателя
	}
	Something* operator->()	// перегрузка оператора ->
	{
		return object;//возвращаем указатель на объект
	}
	Something* get()//геттер
	{
		return object;//возвращает указатель на инкапсулированный объект
	}
	SmartPtr& operator=(const SmartPtr& right)//оператор присваивания
	{
		if (object != right.object)//если левый объект не равен правому
		{
			object = right.object;//копируем адрес объекта
			CountPtr = right.CountPtr + 1;//переписываем количество копий
		}
		return *this;//возвращаем указатель на самого себя
	}
	SmartPtr(SmartPtr& orig)//конструктор копирования
	{
		object = orig.object;//копируем адрес объекта
		CountPtr = orig.CountPtr + 1;//копируем количество указателей
	}
	~SmartPtr()//деструктор
	{
		CountPtr--;//уменьшаем счётчик копий
		cout << "count: " << CountPtr << endl;
		if (!CountPtr)//если указатель последний, освобождаем память
		{
			delete object;//удаляем объект
		}
	}
};

int main()
{
	SmartPtr ptr(new Something("one", 12));//создаем объект с заданными параметрами
	ptr->show();//выводим данные в консоль
	SmartPtr ptr2(new Something("two", 15));//создаем объект с заданными параметрами
	ptr2->SetCount(21);//задаём количество
	ptr2->show();//выводим в консоль второй объект
	SmartPtr ptr3 = ptr;//создаём второй указатель на первый объект 
	ptr3->show();//выводим в консоль первый объект
	ptr = ptr3;//присвоение указателей
	ptr->show();//выводим в консоль первый объект
	SmartPtr ptr4 = ptr3;//ещё 1 указатель на 1 объект
	ptr4->show();//выводим в консоль первый объект
	return 0;
}

