// PriorityQueue.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#pragma warning(disable: 4996)

class Task//����� �������
{
	static int count_task;//���������� ��������
	int id;//������� ����� �������
	unique_ptr<char[]>title;//��������
	unique_ptr<char[]>descr;//��������
	int priority;//��������� ������
public:
	Task()//����������� �� ���������
	{
		count_task++;
		id = count_task;
		title.reset(nullptr);
		descr.reset(nullptr);
		priority = 0;
	}

	Task(char* title, char* descr, int priority)//����������� � ��������� �����������
	{
		setTitle(title);
		setDescr(descr);
		this->priority = priority;
	}

	Task(const Task& task)//����������� �����������
	{
		this->id = task.id;
		this->priority = task.priority;
		setTitle(task.title.get());
		setDescr(task.descr.get());
	}

	void setTitle(char* title)//������ ��������
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

	void setDescr(char* descr)//������ ��������
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

	void setPriority(int priority)//������ ����������
	{
		this->priority = priority;
	}

	int getId()//������ id
	{
		return id;
	}

	int getPriority()//������ ����������
	{
		return priority;
	}

	char* getTitle()//������ ��������
	{
		return title.get();
	}

	char* getDescr()//������ ��������
	{
		return descr.get();
	}

	Task& operator=(const Task& right)//���������� =
	{
		this->id = right.id;
		this->priority = right.priority;
		setTitle(right.title.get());
		setDescr(right.descr.get());
		return *this;
	}

	bool operator>(const Task& right)//�������� ��������� >
	{
		if (priority > right.priority)
		{
			return true;
		}
		return false;
	}

	bool operator<(const Task& right)//�������� ��������� <
	{
		if (priority < right.priority)
		{
			return true;
		}
		return false;
	}

	bool operator==(const Task& right)//�������� ��������� ==
	{
		if (priority == right.priority)
		{
			return true;
		}
		return false;
	}

	bool operator!=(const Task& right)//�������� ��������� !=
	{
		if (priority != right.priority)
		{
			return true;
		}
		return false;
	}

	friend ostream& operator<<(ostream& ostream, const Task& task);
};

ostream& operator<<(ostream& stream, const Task& task)//���������� ������ � ������
{

	stream << task.id << "\n" << task.title.get() << "\n" << task.descr.get() << "\n" << task.priority << "\n";
	return stream;
}

int Task::count_task = 0;


class PrioritQueue // ������� � �����������
{
	unique_ptr<Task[]> tasks;
	int size; // ������ ���������� ������ ��� ������ �����
	int count; // ������ ���������� �������� �������
	const int Reserve = 10;//������
	int MaxPriority()//���� ������ � ������������ �����������
	{
		int max_priority = -1;
		int max_task;
		for (int i = count - 1; i >= 0; i--)//� ������ � ������, ��� ������� ������ � ������� ����������� ������� �������. 
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
	PrioritQueue()//����������� �� ���������
	{
		size = Reserve;
		tasks.reset(new Task[size]);
	}

	int getCount()//������ ���������� �������
	{
		return count;
	}

	void add(Task& new_task)//���������� ������
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


	Task see()//������������� ������ �����������
	{
		if (!empty())
		{
			return tasks.get()[MaxPriority()];
		}
		cout << "empty tasks!" << endl;
		abort();
	}

	Task get()//������� ������
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

	bool empty()//�������� �� �������
	{
		if (count < 0)
		{
			return true;
		}
		return false;
	}
	friend ostream& operator<<(ostream&, const PrioritQueue&);
};

ostream& operator<<(ostream& stream, PrioritQueue& task)//����� � ������� 
{
	for (int i = 0; i < task.getCount(); i++)
	{
		stream << task.get();
	}
	return stream;
}

void test()
{
	PrioritQueue todoList;//������ ������� �������

	todoList.add(Task("Watch TV", "Home", 3));//���������� ������
	todoList.add(Task("Check homework", "Work", 8));//���������� ������
	todoList.add(Task("Do homework in english", "Work", 5));//���������� ������
	todoList.add(Task("Play game", "Enjoy", 1));//���������� ������

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

