
//1. Создать шаблонные классы Node и LinkedList(см.проект LinkedListDemo)
//В классе LinkedList реализовать методы deleteHead, deleteTail, delete(int index)
//2. Реализовать шаблонный класс ArrayList представляющий список на базе массива с теми же методами, что и в LinkedList.
//3. Провести анализ производительности ArrayList и LinkedList следюущим способом :
//4. В цикле 500 000 раз добавить элементы в начало списка ArrayList и LinkedList(два разных цикла - на каждый	тип данных).
//   -Замерить производительность операции вставки данных в начало списка используя функцию clock() (http ://cppstudio.com/post/561/)
//5. Произвести аналогичный замер производительности при вставке в середину списков(list.insert(list.size() / 2, data))
//6. Произвести аналогичный замер производительности при вставке в конец списков(list.addTail(data))
//7. Произвести аналогичный замер производительности при произвольном извлечении данных из списка(используя оператор[]).
//   Для этого 500 000 раз генерируете случайное число в диапазоне 0..list.size() - 1


//В продолжение последнего домашнего задания.
//Добавить к сравнению производительсности структур данных стурктуру данных
//двусвязный список(который должен иметь те же методы, что и у ArrayList и LinkedList).
//Проанализировать скорость вставки в начало, середину, конец и в произвольное место на примере списков размером 10000 элементов.
//Дополнительно проанализировать скорость последовательного и произвольного доступа к данным по индексу.

#include <memory>
#include <ctime>
#include <iostream>
using namespace std;

#define CYCLS 10000//тестируемое число добавлений

template<class T>
class ArrayList//класс динамический массив
{
	unique_ptr<T[]> Array;//умный указатель на массив
	int size_list;//фактически выделенная память
	int size;//последний индекс
	const int Reserve = 100;

public:

	ArrayList()//конструктор по умолчанию
	{
		size = -1;
		size_list = Reserve;
		Array.reset(new T[size_list]);
	}

	T& operator[](int index)//перегрузка []
	{
		if (index > size || index < 0)
		{
			abort();
		}
		return Array.get()[index];
	}

	void ResetPtr()//переназначение указателя, перевыделение памяти
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

	void addHead(T data)//добавление в голову
	{
		size++;
		ResetPtr();
		for (int i = size; i >= 0; i--)
		{
			Array.get()[i] = Array.get()[i - 1];
		}
		Array.get()[0] = data;
	}

	void addTail(T data)//добавление в звост
	{
		size++;
		ResetPtr();
		Array.get()[size] = data;
	}

	void insert(int index, T data)//вставить по индексу
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

	void deleteHead()//удаление головы
	{
		for (int i = 0; i < size; i++)
		{
			Array.get()[i] = Array.get()[i + 1];
		}
		size--;
	}

	void deleteTail()//удаление хвоста
	{
		size--;
	}

	void deleteElem(int index)//удаление по индексу
	{
		if (size == 0 || index > size + 1 || index < 0)
			// пустой список  или index выходит за пределы массива или ...
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

	int Count()//количество элементов
	{
		return size + 1;
	}

	T* Get(int index)//посмотреть по индексу
	{
		if (size == 0 || index > size || index < 0)
			// пустой список  или index выходит за пределы массива или ...
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
class Node // узел списка
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
	Node<T>* head; // голова списка
	int size;   // кол-во данных в списке

public:
	LinkedList() : head(nullptr), size(0)//конструктор по умолчанию
	{}

	void addHead(T data)//добавление в голову
	{
		Node<T>* new_node = new Node<T>(data);
		new_node->next = head;
		head = new_node;
		size++;
	}

	void addTail(T data)//добавление в хвост
	{
		Node<T>* new_node = new Node<T>(data);
		if (head == NULL) // если список пуст, то... 
		{
			head = new_node; // это должна быть голова
		}
		else
		{
			Node<T>* tail = head;
			// находим хвост
			while (tail->next != NULL)
			{
				tail = tail->next;
			}
			// добавляем элемент после хвоста
			tail->next = new_node;
		}
		size++;
	}

	void insert(int index, T data)//добавление в середину
	{
		if (size == 0 || index >= size || index < 0)
			// пустой список  или index выходит за пределы списка или ...
		{
			abort();
		}

		if (index == 0) // добавить перед головой
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

	void deleteHead()//удаление головы
	{
		Node<T>* del = head;
		head = head->next;
		delete del;
		size--;
	}

	void deleteTail()//удаление хвоста
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

	void deleteNode(int index)//удаление по индексу
	{
		if (size == 0 || index >= size || index < 0)
			// пустой список  или index выходит за пределы списка или ...
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

	int Count()//количество элементов
	{
		return size;
	}

	T* Get(int index)//посмотреть по индексу
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
		abort(); // ошибка
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
class Node_D//узел двухсвязного списка
{
	T data;			 //данные
	Node_D<T>* next; // следующий элемент
	Node_D<T>* prev; // предыдущий элемент
public:
	Node_D<T>(T data) : data(data), next(nullptr), prev(nullptr)//конструктор по умолчанию
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
	Node_D<T>* head;  // голова списка
	Node_D<T>* tail;  // хвост списка
	Node_D<T>* curr;  // текущий узел (для ускорения поиска данных по индексу)
	int idx_curr;     // индекс текущего элемента
	int size;         // размер списка

	void search(int& min_dis, int& dinstant2, int& dinstant3)//сравниваем расстояния до искомого объекта
	{
		if (dinstant2 < min_dis)//расстояние 2 меньше чем минимально, минимальное=расстояние 2
		{
			min_dis = dinstant2;
		}
		if (abs(dinstant3) < min_dis)//расстояние 3 меньше чем минимально, минимальное=расстояние 3
		{
			min_dis = dinstant3;
		}
	}

	void go_to_tail_side(int idx)//перемещение до искомого в сторону хвоста
	{
		while (idx != idx_curr)
		{
			curr = curr->next;
			idx_curr++;
		}
	}

	void go_to_head_side(int idx)//движение в сторону головы до искомого
	{
		while (idx != idx_curr)
		{
			curr = curr->prev;
			idx_curr--;
		}
	}

	void CreateLinks(Node_D<T>* node)//налаживание связей
	{
		curr->prev->next = node;
		node->prev = curr->prev;
		curr->prev = node;
		node->next = curr;
	}

	void SearchPlaceAndMoveCurr(int idx)//поиск минимально расстояния и перемещение в его сторону
	{
		int	dinstant1 = idx;//расстояние от головы до искомого
		int dinstant2 = size - 1 - idx;//расстояние от хвоста до искомого
		int dinstant3 = idx_curr - idx;//расстояние от текущего до искомого
		int min_dis = dinstant1;//принимаем минимально е расстояние равное первому расстоянию
		search(min_dis, dinstant2, dinstant3);//правниваем остальные расстояния с первым

		if (min_dis == dinstant1)//если первое расстояние минимальное
		{
			curr = head;//ставим текущий на голову
			idx_curr = 0;//индекс текущкго теперь 0
			go_to_tail_side(idx);//двигаем текущий в сторону хвоста до искомого
		}
		else	if (min_dis == dinstant2)//если второе расстояние минимальное
		{
			curr = tail;//ставим текущий на хвост
			idx_curr = size - 1;//индекс текущкго теперь равен размеру списка-1
			go_to_head_side(idx);//двигаем текущий в сторону ноловы до искомого
			return;
		}
		else if (min_dis == abs(dinstant3))//если третье расстояние минимальное
		{
			if (dinstant3 > 0)
			{
				go_to_head_side(idx);//двигаем текущий в сторону ноловы до искомого
			}

			if (dinstant3 < 0)
			{
				go_to_tail_side(idx);//двигаем текущий в сторону хвоста до искомого
			}
		}
	}

	void insert(int idx, Node_D<T>* node)//вставка элемента в середину списка
	{
		SearchPlaceAndMoveCurr(idx);//ищем элемент, перемещаем текущий
		CreateLinks(node);//налаживаем связи с новым элементом
		idx_curr++;//переписываем индекс текущего
	}

	void check_curr_del(int idx)//проверка и смещение текущего, если совпало так, что мы его должны удалить
	{
		if (idx == idx_curr)//если совпало так, что мы его должны удалить
		{
			if (idx <= size - 2)//если справо еще есть место, двигаем вправо
			{
				idx_curr++;
				curr = curr->next;
				cout << idx_curr;
			}
			else//если справа нет место, двигаем влево
			{
				idx_curr--;
				curr = curr->prev;
				cout << idx_curr;
			}
		}
	}

public:

	DLinkedList<T>() : head(nullptr), tail(nullptr), curr(nullptr),//конструктор по умолчанию
		idx_curr(-1), size(0)
	{}

	T& operator[](int index)//перегрузка []
	{
		SearchPlaceAndMoveCurr(index);//ищем элемент, перемещаем текущий
		return curr->data;//возвращаем текущий
	}

	/*
	Добавление элемента в список.
	data - данные списка
	idx - индекс добавляемого элемента
	если равен -1, то добавляется в конец
	*/
	void add(T data, int idx = -1)
	{
		Node_D<T> *node = new Node_D<T>(data);
		if (head == nullptr) // это первый элемент
		{
			head = tail = curr = node;
			idx_curr = 0;
		}
		else // добавление в сердину или конец
		{
			if (idx < 0 || idx >= size) // добавление в конец
			{
				tail->next = node;
				node->prev = tail;
				tail = node;
			}
			else if (idx == 0) // добавление первого элемента
			{
				node->next = head;
				head->prev = node;
				head = node;
				idx_curr++; // текущий элемент сместился
			}
			else // добавление в середину
			{
				insert(idx, node);
			}
		}
		size++;
	}

	void del(int idx = -1)//удаление объекта из списка
	{
		check_curr_del(idx);//проверка текущего на удаление

		if (idx >= size || idx < 0)//если индекс выходит за пределы списка
		{
			abort();
		}
		else if (idx == 0)//если индекс ==0
		{
			if (size == 1)//если это единственный элемент
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
		else if (idx == size - 1)//если индекс равен индексу хвоста
		{
			Node_D<T>* del = tail;
			tail = tail->prev;
			tail->next = NULL;
			delete del;
		}
		else
		{
			SearchPlaceAndMoveCurr(idx);//ищим удаляемый объект
			curr->prev->next = curr->next;
			curr->next->prev = curr->prev;
			Node_D<T>* del_node = curr;//запоминаем то что нужно удалить
			check_curr_del(idx);//передвигаем текущий
			delete del_node;//удаляем искомый
		}
		size--;//уменьшаем размер списка
	}

	int Count()//возвращает размер списка
	{
		return size;
	}

	~DLinkedList()//деструктор
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
	int t2 = clock();//засекаем время
	for (int i = 0; i < CYCLS; i++)
	{
		Test_list2.addHead(1);
	}
	cout << "Linked List: " << clock() - t2 << endl;//пройденно тиков времени

	//-------------------------------------------
	DLinkedList<int> Test_list3;
	int t3 = clock();//засекаем время
	for (int i = 0; i < CYCLS; i++)
	{
		Test_list3.add(1, 0);
	}
	cout << "Double Linked List: " << clock() - t3 << endl;//пройденно тиков времени
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
void Sequential_and_random_access(DLinkedList<int>* Test_list3)//последовательное и произвольное получение данных
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
	test_add_to_head(); //добовление в голову для типов данных INT для  Array List, Linked List и Double Linked List
						//с подсчётов времени выполнения
	test_insert();		//добовление в середину для типов данных INT для  Array List, Linked List и Double Linked List
						//с подсчётов времени выполнения

	ArrayList<int> Test_list1;//объект динамический массив с данными типа INT
	LinkedList<int> Test_list2;//объект односвязанный список с данными типа INT
	DLinkedList<int> Test_list3;//объект двухсвязанный список с данными типа INT

	test_add_to_tail(&Test_list1, &Test_list2, &Test_list3);//добовление в хвост для типов данных INT
															//для Array List, Linked List и Double Linked List
															//с подсчётов времени выполнения

	test_get<int>(&Test_list1, &Test_list2, &Test_list3);//произвольное извлечение данных типа INT
														 //для  Array List, Linked List и Double Linked List
														 //с подсчётов времени выполнения


	Sequential_and_random_access<int>(&Test_list3);//сравнение последовательной и произвольной выборки данных

	return 0;
}