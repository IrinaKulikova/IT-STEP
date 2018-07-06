// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "student.h"

//Задание 1. Сколько студентов старше 40 ? count_if
//Задание 2. Сколько студентов мужского пола ? count_if
//Задание 3. Найти студента с максимальным возрастом max_element
//Задание 4. Найти студента с минимальным возрастом min_element
//Задание 5. Отсортировать студентов по возрасту sort


bool is_yonger(student& stud)
{
	return stud.getAge() < 18;
}

// предикат в виде класса
class IsPred
{
	int pre;
public:
	IsPred(int pre)
	{
		this->pre = pre;
	}
	bool operator()(student& stud)
	{
		return stud.getAge() > pre;
	}
};


class CountGenderPred
{
	gender _gen;
public:
	CountGenderPred(gender _gen)
	{
		this->_gen = _gen;
	}
	bool operator()(student& stud)
	{
		return stud.getGender() == _gen;
	}
};

class AgePred
{
public:
	bool operator()(student& first, student& second)
	{
		return first.getAge() < second.getAge();
	}
};

class ShowStud
{
public:
	void operator()(student& stud)
	{
		cout << stud << endl;
	}
};

int main()
{
	vector<student> students;
	students.emplace_back("Vasja", 16, gender::MAN);
	students.emplace_back("Petja", 23, gender::MAN);
	students.emplace_back("Sonja", 18, gender::WOMEN);
	students.emplace_back("Victor Ptrovitch", 65, gender::MAN);
	students.emplace_back("Dima", 25, gender::MAN);
	students.emplace_back("Katja", 21, gender::WOMEN);
	students.emplace_back("Semen", 33, gender::MAN);
	students.emplace_back("Elena", 42, gender::WOMEN);
	students.emplace_back("Ivan Ivanovitch", 69, gender::MAN);

	//Есть ли студенты младше 18?
	bool any_yonger = any_of(students.begin(), students.end(), is_yonger);
	cout << "yonger < 18 " << boolalpha << any_yonger << endl;

	// Есть ли студенты старше 60?
	IsPred MyPred(60);
	bool any_older = any_of(students.begin(), students.end(), MyPred);
	cout << "older > 60 " << boolalpha << any_older << endl;

	// Задание 1. Сколько студентов старше 40? count_if
	IsPred MyPred2(40);
	int CountOld = count_if(students.begin(), students.end(), MyPred2);
	cout << "count older of 40: " << CountOld << endl;

	// Задание 2. Сколько студентов мужского пола? count_if
	CountGenderPred CountGen(MAN);
	int CountMen = count_if(students.begin(), students.end(), CountGen);
	cout << "count men: " << CountMen << endl;

	// Задание 3. Найти студента с максимальным возрастом max_element
	AgePred Older;
	auto MaxAge = max_element(students.begin(), students.end(), Older);
	cout << "Max Age: " << *MaxAge << endl;

	// Задание 4. Найти студента с минимальным возрастом min_element
	auto MinAge = min_element(students.begin(), students.end(), Older);
	cout << "Min Age: " << *MinAge << endl;

	// Задание 5. Отсортировать студентов по возрасту sort

	ShowStud Show;
	cout << "\n--------------not-sort--------------------\n";
	for_each(students.begin(), students.end(), Show);
	cout << "----------------sort--------------------\n";
	sort(students.begin(), students.end(), Older);
	for_each(students.begin(), students.end(), Show);

	return 0;
}





