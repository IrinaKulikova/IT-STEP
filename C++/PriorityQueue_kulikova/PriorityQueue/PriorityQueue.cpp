// PriorityQueue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#pragma warning(disable: 4996)

class Task//класс заметка
{
	static int count_task;//количество объектов
	int id;//текущий номер объекта
	unique_ptr<char[]>title;//название
	unique_ptr<char[]>descr;//описание
	int priority;//приоритет задачи
public:
	Task()//конструктор по умолчанию
	{
		count_task++;
		id = count_task;
		title.reset(nullptr);
		descr.reset(nullptr);
		priority = 0;
	}

	Task(char* title, char* descr, int priority)//конструктор с заданными параметрами
	{
		setTitle(title);
		setDescr(descr);
		this->priority = priority;
	}

	Task(const Task& task)//конструктор копирования
	{
		this->id = task.id;
		this->priority = task.priority;
		setTitle(task.title.get());
		setDescr(task.descr.get());
	}

	void setTitle(char* title)//сеттер названия
	{
		if (title != NULL)
		{
			this->title.reset(new char[strlen(title) + 1]);
			strcpy(this->title.get(), title);
		}
		else
		{
			this->title.reset(NULL);
		}
	}

	void setDescr(char* descr)//сеттер описания
	{
		if (descr != NULL)
		{
			this->descr.reset(new char[strlen(descr) + 1]);
			strcpy(this->descr.get(), descr);
		}
		else
		{
			this->descr.reset(NULL);
		}
	}

	void setPriority(int priority)//сеттер приоритета
	{
		this->priority = priority;
	}

	int getId()//геттер id
	{
		return id;
	}

	int getPriority()//геттер приоритета
	{
		return priority;
	}

	char* getTitle()//геттер названия
	{
		return title.get();
	}

	char* getDescr()//геттер описания
	{
		return descr.get();
	}

	Task& operator=(const Task& right)//перегрузка =
	{
		this->id = right.id;
		this->priority = right.priority;
		setTitle(right.title.get());
		setDescr(right.descr.get());
		return *this;
	}

	bool operator>(const Task& right)//оператор сравнения >
	{
		if (priority > right.priority)
		{
			return true;
		}
		return false;
	}

	bool operator<(const Task& right)//оператор сравнения <
	{
		if (priority < right.priority)
		{
			return true;
		}
		return false;
	}

	bool operator==(const Task& right)//оператор сравнения ==
	{
		if (priority == right.priority)
		{
			return true;
		}
		return false;
	}

	bool operator!=(const Task& right)//оператор сравнения !=
	{
		if (priority != right.priority)
		{
			return true;
		}
		return false;
	}

	friend ostream& operator<<(ostream& ostream, const Task& task);
};

ostream& operator<<(ostream& stream, const Task& task)//перегрузка вывода в косоль
{

	stream << task.id << "\n" << task.title.get() << "\n" << task.descr.get() << "\n" << task.priority << "\n";
	return stream;
}

int Task::count_task = 0;


class PrioritQueue // очередь с приоритетом
{
	unique_ptr<Task[]> tasks;
	int size; // размер выделенной памяти под массив задач
	int count; // индекс последнего элемента очереди
	const int Reserve = 10;//резерв
	int MaxPriority()//ищим запись с максимальным приоритетом
	{
		int max_priority = -1;
		int max_task;
		for (int i = count - 1; i >= 0; i--)//с хвоста в начало, что выбрать задачу с большим приоритетом вначале очереди. 
		{
			if (tasks.get()[i].getPriority() > max_priority)
			{
				max_task = i;
				max_priority = tasks.get()[i].getPriority();
			}
		}
		return max_task;
	}
public:
	PrioritQueue()//конструктор по умолчанию
	{
		size = Reserve;
		tasks.reset(new Task[size]);
	}

	int getCount()//геттер количества записей
	{
		return count;
	}

	void add(Task& new_task)//добавление записи
	{

		if (count >= size)
		{
			Task* new_list_task = new Task[size + Reserve];
			for (int i = 0; i < count; i++)
			{
				new_list_task[i] = tasks.get()[i];
			}
			size += Reserve;
			tasks.reset(new_list_task);
		}
		tasks.get()[count].setTitle(new_task.getTitle());
		tasks.get()[count].setDescr(new_task.getDescr());
		tasks.get()[count].setPriority(new_task.getPriority());
		count++;
	}


	Task see()//просматриваем первый добавленный
	{
		if (!empty())
		{
			return tasks.get()[MaxPriority()];
		}
		cout << "empty tasks!" << endl;
		abort();
	}

	Task get()//изъятия записи
	{
		if (!empty())
		{
			int del = MaxPriority();
			Task Max = tasks.get()[del];
			for (int i = del; i < count + 1; i++)
			{
				tasks.get()[i] = tasks.get()[i + 1];
			}
			count--;
			return Max;
		}
		cout << "empty tasks!" << endl;
		abort();
	}

	bool empty()//проверка на пустоту
	{
		if (count < 0)
		{
			return true;
		}
		return false;
	}
	friend ostream& operator<<(ostream&, const PrioritQueue&);
};

ostream& operator<<(ostream& stream, PrioritQueue& task)//вывод в консоль 
{
	for (int i = 0; i < task.getCount(); i++)
	{
		stream << task.get();
	}
	return stream;
}

void test()
{
	PrioritQueue todoList;//создаём блокнот записей

	todoList.add(Task("Watch TV", "Home", 3));//добавление записи
	todoList.add(Task("Check homework", "Work", 8));//добавление записи
	todoList.add(Task("Do homework in english", "Work", 5));//добавление записи
	todoList.add(Task("Play game", "Enjoy", 1));//добавление записи

	Task MaxTask = todoList.get();

	if (strcmp(MaxTask.getTitle(), "Check homework") != 0)
	{
		cerr << "Error check Title" << endl;
	}

	if (MaxTask.getPriority() != 8)
	{
		cerr << "Error check Priority" << endl;
	}

	if (strcmp(MaxTask.getDescr(), "Work") != 0)
	{
		cerr << "Error check Description" << endl;
	}

	if (MaxTask.getId() != 2)
	{
		cerr << "Error check Id 1" << endl;
	}

	if (strcmp(todoList.see().getTitle(), "Do homework in english") != 0)
	{
		cerr << "Error see new task" << endl;
	}

	if (todoList.see().getId() != 3)
	{
		cerr << "Error check Id 2" << endl;
		cout << todoList.see().getId() << endl;
	}

	if (strcmp(todoList.get().getTitle(), "Do homework in english") != 0)
	{
		cerr << "Error 3" << endl;
	}

	if (todoList.get().getPriority() != 3)
	{
		cerr << "Error check priority" << endl;
	}

	if (todoList.get().getPriority() != 1)
	{
		cerr << "Error check priority" << endl;
	}
}

int main()
{
	test();
	return 0;
}

