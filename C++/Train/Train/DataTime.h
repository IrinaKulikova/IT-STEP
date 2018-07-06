#pragma once
#pragma once
#include "stdafx.h"

class DataTime//класс дата и время
{
private:
	int Year;//год
	MONTH Month;//месяц
	int Day;//число месяца
	int Hours;//часы 
	int Minuts;//минуты
public:
	DataTime();//конструктор
	virtual ~DataTime();//деструктор
	void SetYear(int Year);//сеттер года
	void SetMonth(MONTH Month);//сеттер месяца
	void SetDay(int Day);//сеттер дня
	void SetHours(int Hours);//сеттер часа
	void SetMinuts(int Minuts);	//сеттер минут
	int GetYear();//геттер года
	MONTH GetMonth();//геттер месяца
	int GetDay();//геттер дня
	int GetHours();//геттер часов
	int GetMinuts();//геттер минут
	friend ostream& operator<<(ostream& stream, DataTime& data);//оператор вывода
};