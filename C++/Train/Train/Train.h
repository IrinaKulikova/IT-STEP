#pragma once
#include "stdafx.h"

class Train//класс поезд
{
private:
	string Number;//номер поезда
	string StartStation;//пункт отправления
	string FinishStation;//пункт назначения
	DataTime StartTime;//время отправления
	DataTime FinishTime;//время прибытия
public:
	Train();//конструктор
	virtual ~Train();//деструктор
	void SetStartTime(DataTime StartTime);//сеттер времени отправления
	void SetFinishTime(DataTime FinishTime);//сеттер времени прибытия
	void SetNuber(string Number);//сеттер номера поезда
	void SetStartStation(string StartStation);//сеттер станции отправления
	void SetFinishStation(string FinishStation);//сеттер станции прибытия
	DataTime GetStartTime();//геттер времени отправления
	DataTime GetFinishTime();//геттер времени прибытия
	string GetNuber();//геттер номера поезда
	string GetStartStation();//геттер станции отправления
	string GetFinishStation();//геттер станции прибытия
	friend ostream& operator<<(ostream& stream, Train& train);//перегрузка оператора вывода
};