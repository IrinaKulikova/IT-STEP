#include <iostream>
using namespace std;
#pragma warning(disable:4996)

class Something//����� �����
{
	char* name;//���� ��� ������
	size_t count;//���� ����������
public:
	Something() //����������� �� ���������
	{
		name = NULL;
		count = 0;
	}
	Something(const char* name, size_t count) //����������� � ��������� �����������
	{
		this->name = new char[strlen(name) + 1];//�������� ������
		strcpy(this->name, name);//������������ ���
		this->count = count;//������������ ��������
	}
	void SetZeroCount()//����������� ����������
	{
		count = 0;//�������������� �������
	}
	void SetCount(size_t count)//������ ��� ����������
	{
		this->count = count;
	}
	void SetName(char* name)//������ ��� �����
	{
		if (this->name != NULL)//���� ��� �� ������ ����, ����������� ������
		{
			delete[] this->name;
			this->name = NULL;
		}
		if (name != NULL)//���� ����� ��� �� ������, ������������ ����� ���
		{
			this->name = new char[strlen(name) + 1];
			strcpy(this->name, name);
		}
	}
	Something(const Something& orig)//����������� �����������
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
		count = orig.count;//������������ ����������
	}
	Something& operator=(const Something& orig)//�������� ����������
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
		count = orig.count;//������������ ����������
		return *this;//���������� ��������� �� ������ ����
	}
	~Something()//����������
	{
		if (name != NULL)//���� � ���� ��� ���-�� ����, ����������� ������
		{
			cout << "destructor" << endl;
			delete[] name;
		}
	}
	void show()//������� ���������� � �������
	{
		cout << "Name" << name << endl;
		cout << "Count: " << count << endl;
		cout << "------------------------------" << endl;
	}
};

class SmartPtr//�����-����� ���������
{
	Something* object;//��������� �� ������
	size_t CountPtr;//����� ���������
public:
	SmartPtr(Something* object)//����������� �� ���������
	{
		this->object = object;//�������� ��������� �� ������
		CountPtr = 1;//����� ���������
	}
	Something* operator->()	// ���������� ��������� ->
	{
		return object;//���������� ��������� �� ������
	}
	Something* get()//������
	{
		return object;//���������� ��������� �� ����������������� ������
	}
	SmartPtr& operator=(const SmartPtr& right)//�������� ������������
	{
		if (object != right.object)//���� ����� ������ �� ����� �������
		{
			object = right.object;//�������� ����� �������
			CountPtr = right.CountPtr + 1;//������������ ���������� �����
		}
		return *this;//���������� ��������� �� ������ ����
	}
	SmartPtr(SmartPtr& orig)//����������� �����������
	{
		object = orig.object;//�������� ����� �������
		CountPtr = orig.CountPtr + 1;//�������� ���������� ����������
	}
	~SmartPtr()//����������
	{
		CountPtr--;//��������� ������� �����
		cout << "count: " << CountPtr << endl;
		if (!CountPtr)//���� ��������� ���������, ����������� ������
		{
			delete object;//������� ������
		}
	}
};

int main()
{
	SmartPtr ptr(new Something("one", 12));//������� ������ � ��������� �����������
	ptr->show();//������� ������ � �������
	SmartPtr ptr2(new Something("two", 15));//������� ������ � ��������� �����������
	ptr2->SetCount(21);//����� ����������
	ptr2->show();//������� � ������� ������ ������
	SmartPtr ptr3 = ptr;//������ ������ ��������� �� ������ ������ 
	ptr3->show();//������� � ������� ������ ������
	ptr = ptr3;//���������� ����������
	ptr->show();//������� � ������� ������ ������
	SmartPtr ptr4 = ptr3;//��� 1 ��������� �� 1 ������
	ptr4->show();//������� � ������� ������ ������
	return 0;
}

