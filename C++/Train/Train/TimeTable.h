#pragma once
#include "stdafx.h"

class TimeTable//класс вокзал
{
private:
	deque<Train> Stock;//массив поездов
	void EnterYear(DataTime& Time, DataTime& EtalonTime);//ввод года
	void EnterMonth(DataTime& Time, DataTime& EtalonTime);//ввод мес€ца
	void EnterDay(DataTime& Time, DataTime& EtalonTime);//ввод дн€
	void EnterHours(DataTime& Time, DataTime& EtalonTime);//ввод часов
	void EnterMinuts(DataTime& Time, DataTime& EtalonTime);//ввод минут
	void EnterDataTime(DataTime& Time, DataTime& DefaultTime);//ввести дату
	void EnterData(DataTime& Time, DataTime& EtalonTime, string msg);
	void AddTrain();//добавить поезд
	void SearchShowTrain();//найти и показать информацию о поезде
	void ShowAll();//показать информацию о всех поездах
public:
	TimeTable();//конструктор
	virtual ~TimeTable();//деструктор
	void operator()();//перегруженные ()
};