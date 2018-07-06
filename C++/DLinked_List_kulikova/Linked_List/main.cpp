
//1. ������� ��������� ������ Node � LinkedList(��.������ LinkedListDemo)
//� ������ LinkedList ����������� ������ deleteHead, deleteTail, delete(int index)
//2. ����������� ��������� ����� ArrayList �������������� ������ �� ���� ������� � ���� �� ��������, ��� � � LinkedList.
//3. �������� ������ ������������������ ArrayList � LinkedList ��������� �������� :
//4. � ����� 500 000 ��� �������� �������� � ������ ������ ArrayList � LinkedList(��� ������ ����� - �� ������	��� ������).
//   -�������� ������������������ �������� ������� ������ � ������ ������ ��������� ������� clock() (http ://cppstudio.com/post/561/)
//5. ���������� ����������� ����� ������������������ ��� ������� � �������� �������(list.insert(list.size() / 2, data))
//6. ���������� ����������� ����� ������������������ ��� ������� � ����� �������(list.addTail(data))
//7. ���������� ����������� ����� ������������������ ��� ������������ ���������� ������ �� ������(��������� ��������[]).
//   ��� ����� 500 000 ��� ����������� ��������� ����� � ��������� 0..list.size() - 1


//� ����������� ���������� ��������� �������.
//�������� � ��������� ������������������� �������� ������ ��������� ������
//���������� ������(������� ������ ����� �� �� ������, ��� � � ArrayList � LinkedList).
//���������������� �������� ������� � ������, ��������, ����� � � ������������ ����� �� ������� ������� �������� 10000 ���������.
//������������� ���������������� �������� ����������������� � ������������� ������� � ������ �� �������.

#include <memory>
#include <ctime>
#include <iostream>
using namespace std;

#define CYCLS 10000//����������� ����� ����������

template<class T>
class ArrayList//����� ������������ ������
{
	unique_ptr<T[]> Array;//����� ��������� �� ������
	int size_list;//���������� ���������� ������
	int size;//��������� ������
	const int Reserve = 100;

public:

	ArrayList()//����������� �� ���������
	{
		size = -1;
		size_list = Reserve;
		Array.reset(new T[size_list]);
	}

	T& operator[](int index)//���������� []
	{
		if (index > size || index < 0)
		{
			abort();
		}
		return Array.get()[index];
	}

	void ResetPtr()//�������������� ���������, ������������� ������
	{
		if (size >= size_list)
		{
			size_list += Reserve;
			T* buff = new T[size_list];
			for (int i = 0; i < size; i++)
			{
				buff[i] = Array.get()[i];
			}
			Array.reset(buff);
		}
	}

	void addHead(T data)//���������� � ������
	{
		size++;
		ResetPtr();
		for (int i = size; i >= 0; i--)
		{
			Array.get()[i] = Array.get()[i - 1];
		}
		Array.get()[0] = data;
	}

	void addTail(T data)//���������� � �����
	{
		size++;
		ResetPtr();
		Array.get()[size] = data;
	}

	void insert(int index, T data)//�������� �� �������
	{
		if (index <0 || index > size)
		{
			abort();
		}
		size++;
		ResetPtr();
		for (int i = size; i > index; i--)
		{
			Array.get()[i] = Array.get()[i - 1];
		}
		Array.get()[index] = data;
	}

	void deleteHead()//�������� ������
	{
		for (int i = 0; i < size; i++)
		{
			Array.get()[i] = Array.get()[i + 1];
		}
		size--;
	}

	void deleteTail()//�������� ������
	{
		size--;
	}

	void deleteElem(int index)//�������� �� �������
	{
		if (size == 0 || index > size + 1 || index < 0)
			// ������ ������  ��� index ������� �� ������� ������� ��� ...
		{
			abort();
		}

		if (index == 0)
		{
			deleteHead();
			return;
		}

		for (int i = index; i < size; i++)
		{
			Array.get()[i] = Array.get()[i + 1];
		}
		size--;
	}

	int Count()//���������� ���������
	{
		return size + 1;
	}

	T* Get(int index)//���������� �� �������
	{
		if (size == 0 || index > size || index < 0)
			// ������ ������  ��� index ������� �� ������� ������� ��� ...
		{
			abort();
		}

		return Array.get()[index];
	}

	friend ostream& operator<<(ostream& stream, ArrayList<T>& Array)
	{
		for (int i = 0; i < Array.Count(); i++)
		{
			stream << Array[i] << " ";
		}
		return stream;
	}
};


template<class T>
class LinkedList;

template<class T>
class Node // ���� ������
{
	T  data;
	Node* next;

public:
	Node(T data) : data(data), next(nullptr)
	{}
	friend LinkedList<T>;
	friend ostream& operator<<(ostream& stream, const LinkedList<T>& list);
	friend ostream& operator<<(ostream& stream, const Node<T>* node)
	{
		stream << node->data;
		return stream;
	}
};

template<class T>
class LinkedList
{
	Node<T>* head; // ������ ������
	int size;   // ���-�� ������ � ������

public:
	LinkedList() : head(nullptr), size(0)//����������� �� ���������
	{}

	void addHead(T data)//���������� � ������
	{
		Node<T>* new_node = new Node<T>(data);
		new_node->next = head;
		head = new_node;
		size++;
	}

	void addTail(T data)//���������� � �����
	{
		Node<T>* new_node = new Node<T>(data);
		if (head == NULL) // ���� ������ ����, ��... 
		{
			head = new_node; // ��� ������ ���� ������
		}
		else
		{
			Node<T>* tail = head;
			// ������� �����
			while (tail->next != NULL)
			{
				tail = tail->next;
			}
			// ��������� ������� ����� ������
			tail->next = new_node;
		}
		size++;
	}

	void insert(int index, T data)//���������� � ��������
	{
		if (size == 0 || index >= size || index < 0)
			// ������ ������  ��� index ������� �� ������� ������ ��� ...
		{
			abort();
		}

		if (index == 0) // �������� ����� �������
		{
			addHead(data);
			return;
		}

		Node<T>* cur = head;
		int idx = 0;
		while (cur != NULL && idx != (index - 1))
		{
			cur = cur->next;
			idx++;
		}

		Node<T>* new_node = new Node<T>(data);
		new_node->next = cur->next;
		cur->next = new_node;
		size++;
	}

	void deleteHead()//�������� ������
	{
		Node<T>* del = head;
		head = head->next;
		delete del;
		size--;
	}

	void deleteTail()//�������� ������
	{
		Node<T>* cur = head;
		Node<T>* before_cur = NULL;
		while (cur->next != NULL)
		{
			before_cur = cur;
			cur = cur->next;
		}
		delete cur->next;
		before_cur->next = NULL;
		size--;
	}

	void deleteNode(int index)//�������� �� �������
	{
		if (size == 0 || index >= size || index < 0)
			// ������ ������  ��� index ������� �� ������� ������ ��� ...
		{
			abort();
		}

		if (index == 0)
		{
			deleteHead();
			return;
		}

		Node<T>* cur = head;
		Node<T>* before_cur = NULL;
		int idx = 0;
		while (idx != index)
		{
			before_cur = cur;
			cur = cur->next;
			idx++;
		}
		before_cur->next = cur->next;
		delete cur;
		size--;
	}

	int Count()//���������� ���������
	{
		return size;
	}

	T* Get(int index)//���������� �� �������
	{
		Node<T>* cur = head;
		int idx = 0;
		while (cur)
		{
			if (idx == index)
			{
				return &(cur->data);
			}
			idx++;
			cur = cur->next;
		}
	}

	T& operator[](int index)
	{
		Node<T>* cur = head;
		int idx = 0;
		while (cur)
		{
			if (idx == index)
			{
				return cur->data;
			}
			idx++;
			cur = cur->next;
		}
		abort(); // ������
	}

	~LinkedList()
	{
		Node<T>* cur = head;
		while (cur)
		{
			Node<T>* del = cur;
			cur = cur->next;
			delete del;
		}
	}

	friend ostream& operator<<(ostream& stream, const LinkedList<T>& list)
	{
		Node<T>* cur = list.head;
		while (cur)
		{
			stream << cur << " ";
			cur = cur->next;
		}
		return stream;
	}
};

template<class T>
class DLinkedList;

template<typename T>
class Node_D//���� ������������ ������
{
	T data;			 //������
	Node_D<T>* next; // ��������� �������
	Node_D<T>* prev; // ���������� �������
public:
	Node_D<T>(T data) : data(data), next(nullptr), prev(nullptr)//����������� �� ���������
	{}
	friend DLinkedList<T>;
	friend ostream& operator<<(ostream& stream, const DLinkedList<T>& list);
	friend ostream& operator<<(ostream& stream, const Node_D<T>* node)
	{
		stream << node->data;
		return stream;
	}
};

template<typename T>
class DLinkedList
{
	Node_D<T>* head;  // ������ ������
	Node_D<T>* tail;  // ����� ������
	Node_D<T>* curr;  // ������� ���� (��� ��������� ������ ������ �� �������)
	int idx_curr;     // ������ �������� ��������
	int size;         // ������ ������

	void search(int& min_dis, int& dinstant2, int& dinstant3)//���������� ���������� �� �������� �������
	{
		if (dinstant2 < min_dis)//���������� 2 ������ ��� ����������, �����������=���������� 2
		{
			min_dis = dinstant2;
		}
		if (abs(dinstant3) < min_dis)//���������� 3 ������ ��� ����������, �����������=���������� 3
		{
			min_dis = dinstant3;
		}
	}

	void go_to_tail_side(int idx)//����������� �� �������� � ������� ������
	{
		while (idx != idx_curr)
		{
			curr = curr->next;
			idx_curr++;
		}
	}

	void go_to_head_side(int idx)//�������� � ������� ������ �� ��������
	{
		while (idx != idx_curr)
		{
			curr = curr->prev;
			idx_curr--;
		}
	}

	void CreateLinks(Node_D<T>* node)//����������� ������
	{
		curr->prev->next = node;
		node->prev = curr->prev;
		curr->prev = node;
		node->next = curr;
	}

	void SearchPlaceAndMoveCurr(int idx)//����� ���������� ���������� � ����������� � ��� �������
	{
		int	dinstant1 = idx;//���������� �� ������ �� ��������
		int dinstant2 = size - 1 - idx;//���������� �� ������ �� ��������
		int dinstant3 = idx_curr - idx;//���������� �� �������� �� ��������
		int min_dis = dinstant1;//��������� ���������� � ���������� ������ ������� ����������
		search(min_dis, dinstant2, dinstant3);//���������� ��������� ���������� � ������

		if (min_dis == dinstant1)//���� ������ ���������� �����������
		{
			curr = head;//������ ������� �� ������
			idx_curr = 0;//������ �������� ������ 0
			go_to_tail_side(idx);//������� ������� � ������� ������ �� ��������
		}
		else	if (min_dis == dinstant2)//���� ������ ���������� �����������
		{
			curr = tail;//������ ������� �� �����
			idx_curr = size - 1;//������ �������� ������ ����� ������� ������-1
			go_to_head_side(idx);//������� ������� � ������� ������ �� ��������
			return;
		}
		else if (min_dis == abs(dinstant3))//���� ������ ���������� �����������
		{
			if (dinstant3 > 0)
			{
				go_to_head_side(idx);//������� ������� � ������� ������ �� ��������
			}

			if (dinstant3 < 0)
			{
				go_to_tail_side(idx);//������� ������� � ������� ������ �� ��������
			}
		}
	}

	void insert(int idx, Node_D<T>* node)//������� �������� � �������� ������
	{
		SearchPlaceAndMoveCurr(idx);//���� �������, ���������� �������
		CreateLinks(node);//���������� ����� � ����� ���������
		idx_curr++;//������������ ������ ��������
	}

	void check_curr_del(int idx)//�������� � �������� ��������, ���� ������� ���, ��� �� ��� ������ �������
	{
		if (idx == idx_curr)//���� ������� ���, ��� �� ��� ������ �������
		{
			if (idx <= size - 2)//���� ������ ��� ���� �����, ������� ������
			{
				idx_curr++;
				curr = curr->next;
				cout << idx_curr;
			}
			else//���� ������ ��� �����, ������� �����
			{
				idx_curr--;
				curr = curr->prev;
				cout << idx_curr;
			}
		}
	}

public:

	DLinkedList<T>() : head(nullptr), tail(nullptr), curr(nullptr),//����������� �� ���������
		idx_curr(-1), size(0)
	{}

	T& operator[](int index)//���������� []
	{
		SearchPlaceAndMoveCurr(index);//���� �������, ���������� �������
		return curr->data;//���������� �������
	}

	/*
	���������� �������� � ������.
	data - ������ ������
	idx - ������ ������������ ��������
	���� ����� -1, �� ����������� � �����
	*/
	void add(T data, int idx = -1)
	{
		Node_D<T> *node = new Node_D<T>(data);
		if (head == nullptr) // ��� ������ �������
		{
			head = tail = curr = node;
			idx_curr = 0;
		}
		else // ���������� � ������� ��� �����
		{
			if (idx < 0 || idx >= size) // ���������� � �����
			{
				tail->next = node;
				node->prev = tail;
				tail = node;
			}
			else if (idx == 0) // ���������� ������� ��������
			{
				node->next = head;
				head->prev = node;
				head = node;
				idx_curr++; // ������� ������� ���������
			}
			else // ���������� � ��������
			{
				insert(idx, node);
			}
		}
		size++;
	}

	void del(int idx = -1)//�������� ������� �� ������
	{
		check_curr_del(idx);//�������� �������� �� ��������

		if (idx >= size || idx < 0)//���� ������ ������� �� ������� ������
		{
			abort();
		}
		else if (idx == 0)//���� ������ ==0
		{
			if (size == 1)//���� ��� ������������ �������
			{
				delete head;
				head = NULL;
				return;
			}
			Node_D<T>* del = head;
			head = head->next;
			head->prev = NULL;
			delete del;
		}
		else if (idx == size - 1)//���� ������ ����� ������� ������
		{
			Node_D<T>* del = tail;
			tail = tail->prev;
			tail->next = NULL;
			delete del;
		}
		else
		{
			SearchPlaceAndMoveCurr(idx);//���� ��������� ������
			curr->prev->next = curr->next;
			curr->next->prev = curr->prev;
			Node_D<T>* del_node = curr;//���������� �� ��� ����� �������
			check_curr_del(idx);//����������� �������
			delete del_node;//������� �������
		}
		size--;//��������� ������ ������
	}

	int Count()//���������� ������ ������
	{
		return size;
	}

	~DLinkedList()//����������
	{
		Node_D<T>* curr = head;
		while (curr)
		{
			Node_D<T>* del = curr;
			curr = curr->next;
			delete del;
		}
	}

	friend Node_D<T>;
	friend ostream& operator<<(ostream& stream, const DLinkedList<T>& list)
	{

		Node_D<T>* curr = list.head;
		if (curr == NULL)
		{
			stream << "double linked list empty!";
			return stream;
		}
		while (curr)
		{
			stream << curr << " ";
			curr = curr->next;
		}
		return stream;
	}
};

void test_add_to_head()
{
	//-------------------------------------------
	cout << "\n       ADD TO HEAD(" << CYCLS << ")" << endl;

	ArrayList<int> Test_list1;
	int t1 = clock();
	for (int i = 0; i < CYCLS; i++)
	{
		Test_list1.addHead(1);
	}
	cout << "Array List: " << clock() - t1 << endl;

	//-------------------------------------------
	LinkedList<int> Test_list2;
	int t2 = clock();//�������� �����
	for (int i = 0; i < CYCLS; i++)
	{
		Test_list2.addHead(1);
	}
	cout << "Linked List: " << clock() - t2 << endl;//��������� ����� �������

	//-------------------------------------------
	DLinkedList<int> Test_list3;
	int t3 = clock();//�������� �����
	for (int i = 0; i < CYCLS; i++)
	{
		Test_list3.add(1, 0);
	}
	cout << "Double Linked List: " << clock() - t3 << endl;//��������� ����� �������
	cout << "------------------------------------" << endl;

}

void test_insert()
{
	//-------------------------------------------
	cout << "\n         INSERT(" << CYCLS << ")\n" << endl;
	ArrayList<int> Test_list1;
	int t1 = clock();
	Test_list1.addHead(1);
	Test_list1.addHead(1);
	for (int i = 0; i < CYCLS; i++)
	{
		Test_list1.insert(Test_list1.Count() / 2, 1);
	}
	cout << "Array List: " << clock() - t1 << endl;

	//-------------------------------------------
	LinkedList<int> Test_list2;
	int t2 = clock();
	Test_list2.addHead(1);
	Test_list2.addHead(1);
	for (int i = 0; i < CYCLS; i++)
	{
		Test_list2.insert(Test_list2.Count() / 2, 1);
	}
	cout << "Linked List: " << clock() - t2 << endl;

	//-------------------------------------------
	DLinkedList<int> Test_list3;
	int t3 = clock();
	Test_list3.add(1, 0);
	Test_list3.add(1, 0);
	for (int i = 0; i < CYCLS; i++)
	{
		Test_list3.add(1, Test_list3.Count() / 2);
	}
	cout << "Double Linked List: " << clock() - t3 << endl;
	cout << "------------------------------------" << endl;
}

void test_add_to_tail(ArrayList<int>* Test_list1, LinkedList<int>* Test_list2, DLinkedList<int>* Test_list3)
{
	//-------------------------------------------
	cout << "------------------------------------" << endl;
	cout << "\n        ADD TO TAIL(" << CYCLS << ")\n" << endl;
	int t1 = clock();
	for (int i = 0; i < CYCLS; i++)
	{
		(*Test_list1).addTail(i);
	}
	cout << "Array List: " << clock() - t1 << endl;

	//-------------------------------------------
	int t2 = clock();
	for (int i = 0; i < CYCLS; i++)
	{
		(*Test_list2).addTail(i);
	}
	cout << "Linked List: " << clock() - t2 << endl;

	int t3 = clock();
	for (int i = 0; i < CYCLS; i++)
	{
		(*Test_list3).add(i, 0);
	}
	cout << "Double Linked List: " << clock() - t3 << endl;
	cout << "------------------------------------" << endl;
}

template<typename T>
void test_get(ArrayList<int>* Test_list1, LinkedList<int>* Test_list2, DLinkedList<int>* Test_list3)
{

	//-------------------------------------------
	cout << "------------------------------------" << endl;
	cout << "\n          Get(" << CYCLS << ")\n" << endl;
	int t1 = clock();
	for (int i = 0; i < CYCLS; i++)
	{
		int rand_index = rand() % CYCLS;
		T test_get = (*Test_list1)[rand_index];
	}
	cout << "Array List: " << clock() - t1 << endl;

	//-------------------------------------------
	int t2 = clock();
	for (int i = 0; i < CYCLS; i++)
	{
		int rand_index = rand() % CYCLS;
		T test_get = (*Test_list2)[rand_index];
	}
	cout << "Linked List: " << clock() - t2 << endl;

	//-------------------------------------------
	int t3 = clock();
	for (int i = 0; i < CYCLS; i++)
	{
		int rand_index = rand() % CYCLS;
		T test_get = (*Test_list3)[rand_index];
	}
	cout << "Double Linked List: " << clock() - t3 << endl;
	cout << "------------------------------------" << endl;
}

template<typename T>
void Sequential_and_random_access(DLinkedList<int>* Test_list3)//���������������� � ������������ ��������� ������
{

	cout << "------------------------------------\n" << endl;
	cout << "Comparison " << endl;
	cout << "Sequential access: ";

	int t1 = clock();
	for (int i = 0; i < CYCLS; i++)
	{
		T test_get = (*Test_list3)[i];
	}
	cout << "Result: " << clock() - t1 << endl;


	cout << "Random access: ";

	int t2 = clock();
	for (int i = 0; i < CYCLS; i++)
	{
		int rand_index = rand() % CYCLS;
		T test_get = (*Test_list3)[rand_index];
	}
	cout << "Result: " << clock() - t2 << endl;
}

void test1()
{
	cout << "--------------INT-----------------\n" << endl;
	DLinkedList<int> list;
	list.add(0, 0);
	list.add(1, 0);
	list.add(2, 0);

	cout << list << endl;
	list[0] = 100;
	cout << list[0] << endl;

	list.add(-100, 1);
	cout << "Insert into head" << endl;
	cout << list << endl;

	list.add(1, 200);
	cout << "Insert after first" << endl;
	cout << list << endl;

	cout << "Count: " << list.Count() << endl;

	cout << "Insert after last" << endl;
	list.add(1000, list.Count());
	cout << list << endl;

	cout << "Count: " << list.Count() << endl;

	cout << "Delete head" << endl;
	list.del(0);
	cout << list << endl;

	cout << "Count: " << list.Count() << endl;

	cout << "del tail" << endl;
	list.del(4);
	cout << list << endl;

	cout << "Count: " << list.Count() << endl;

	list.del(1);
	cout << "del node 1" << endl;
	cout << list << endl;

	cout << "Count: " << list.Count() << endl;


	cout << "-----" << endl;
	list.del(2);
	cout << "del  tail" << endl;
	cout << list << endl;
	list.del(0);
	cout << "del head" << endl;
	cout << list << endl;
	list.del(0);
	cout << "del head" << endl;
	cout << list << endl;
	cout << "-------------------------------\n" << endl;

}
int main()
{
	srand(time(0));
	//test1();
	test_add_to_head(); //���������� � ������ ��� ����� ������ INT ���  Array List, Linked List � Double Linked List
						//� ��������� ������� ����������
	test_insert();		//���������� � �������� ��� ����� ������ INT ���  Array List, Linked List � Double Linked List
						//� ��������� ������� ����������

	ArrayList<int> Test_list1;//������ ������������ ������ � ������� ���� INT
	LinkedList<int> Test_list2;//������ ������������� ������ � ������� ���� INT
	DLinkedList<int> Test_list3;//������ ������������� ������ � ������� ���� INT

	test_add_to_tail(&Test_list1, &Test_list2, &Test_list3);//���������� � ����� ��� ����� ������ INT
															//��� Array List, Linked List � Double Linked List
															//� ��������� ������� ����������

	test_get<int>(&Test_list1, &Test_list2, &Test_list3);//������������ ���������� ������ ���� INT
														 //���  Array List, Linked List � Double Linked List
														 //� ��������� ������� ����������


	Sequential_and_random_access<int>(&Test_list3);//��������� ���������������� � ������������ ������� ������

	return 0;
}