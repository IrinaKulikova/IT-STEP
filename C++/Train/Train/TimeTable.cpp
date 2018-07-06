#pragma once
#include "stdafx.h"
#include "DataTime.h"

TimeTable::TimeTable()//конструктор
{}


TimeTable::~TimeTable()//деструктор
{}


void TimeTable::EnterYear(DataTime& Time, DataTime& EtalonTime)//ввод года
{
	char answer[SIZEANSWER];//считываем ввод пользователя
	cout << "Yaer: ";
	cin >> answer;
	answer[SIZEANSWER - 1] = '\0';
	int YearUser = CheckInputs(answer, MINYEAR);

	range_error err("Invalid data: year");
	if (YearUser < EtalonTime.GetYear())//проверяет для времени прибытия, чтоб год прибытия не был меньше года отправления
	{
		throw err;
	}
	if (YearUser < MINYEAR || YearUser > MAXYEAR)//данные выходят за диапозон допустимых значений
	{
		throw err;
	}
	Time.SetYear(YearUser);//устанавливаем год
}


void TimeTable::EnterMonth(DataTime& Time, DataTime& EtalonTime)//ввод месяца
{
	char answer[SIZEANSWER];
	cout << "Month: ";
	cin >> answer;
	answer[SIZEANSWER - 1] = '\0';
	int MonthUser = CheckInputs(answer, JANUARY);

	range_error err("Invalid data: month");
	if (Time.GetYear() == EtalonTime.GetYear() && MonthUser < EtalonTime.GetMonth())//проверяет сототставления даты, чтоб дата прибытия была больше даты отправки
	{
		throw err;
	}
	if (MonthUser < JANUARY || MonthUser > DECEMBER)
	{
		throw err;
	}
	Time.SetMonth((MONTH)MonthUser);//устанавливаем месяц
}


void TimeTable::EnterDay(DataTime& Time, DataTime& EtalonTime)//ввод дня
{
	char answer[SIZEANSWER];
	cout << "Day: ";
	cin >> answer;
	answer[SIZEANSWER - 1] = '\0';
	int DayUser = CheckInputs(answer, 0);
	MONTH MonthThisTrain = Time.GetMonth();

	range_error err("Invalid data: day");
	if (FEBRUARY == MonthThisTrain)//если введен февраль
	{
		if ((Time.GetYear() % 4 == 0 && Time.GetYear() % 100 != 0) || Time.GetYear() % 400 == 0)
		{
			if (DayUser < FIRSTDAYMONTH || DayUser > LASTLONGFEBRUARY)//проверка на длину месяца и ссответствия числа
			{
				throw err;
			}
		}
		else
		{
			if (DayUser < FIRSTDAYMONTH || DayUser > LASTSHOTFEBRUARY)//проверка на длину месяца и ссответствия числа
			{
				throw err;
			}
		}
	}
	else if (APRIL == MonthThisTrain || JUNE == MonthThisTrain || SEPTEMBER == MonthThisTrain || NOVEMBER == MonthThisTrain)//если месяц короткий
	{
		if (DayUser > LASTDAYSHOTMONTH || DayUser < FIRSTDAYMONTH)//проверка на длину месяца и ссответствия числа
		{
			throw err;
		}
	}
	else//если месяц длинный
	{
		if (DayUser > LASTDAYLONGMONTH || DayUser < FIRSTDAYMONTH)//проверка на длину месяца и ссответствия числа
		{
			throw err;
		}
	}

	if (Time.GetYear() == EtalonTime.GetYear() && Time.GetMonth() == EtalonTime.GetMonth() && DayUser < EtalonTime.GetDay())//проверяет сототставления даты, чтоб дата прибытия была больше даты отправки
	{
		throw err;
	}
	Time.SetDay(DayUser);
}


void TimeTable::EnterHours(DataTime& Time, DataTime& EtalonTime)//ввод часов
{
	char answer[SIZEANSWER];
	cout << "Hours: ";
	cin >> answer;
	answer[SIZEANSWER - 1] = '\0';
	int	HoursUser = CheckInputs(answer, MINHOUR);

	range_error err("Invalid data: hours");
	if (EtalonTime.GetYear() == Time.GetYear() && EtalonTime.GetMonth() == Time.GetMonth()
		&& EtalonTime.GetDay() == Time.GetDay() && HoursUser < EtalonTime.GetHours())//проверяет сототставления даты, чтоб дата прибытия была больше даты отправки
	{
		throw err;
	}
	if (HoursUser<MINHOUR || HoursUser>MAXHOUR)
	{
		throw err;
	}
	Time.SetHours(HoursUser);
}


void TimeTable::EnterMinuts(DataTime& Time, DataTime& EtalonTime)//ввод минут
{
	char answer[SIZEANSWER];
	cout << "Minuts: ";
	cin >> answer;
	answer[SIZEANSWER - 1] = '\0';
	int	MinutsUser = CheckInputs(answer, MINMINUTS);

	range_error err("Invalid data: hours");
	if (EtalonTime.GetYear() == Time.GetYear() && EtalonTime.GetMonth() == Time.GetMonth()
		&& EtalonTime.GetDay() == Time.GetDay() && Time.GetHours() < EtalonTime.GetHours()
		&& MinutsUser <= EtalonTime.GetMinuts())//проверяет сототставления даты, чтоб дата прибытия была больше даты отправки
	{
		throw err;
	}
	if (MinutsUser < MINMINUTS || MinutsUser > MAXMINUTS)
	{
		throw err;
	}
	Time.SetMinuts(MinutsUser);
}


void TimeTable::EnterDataTime(DataTime& Time, DataTime& EtalonTime)//ввести дату
{
	EnterYear(Time, EtalonTime);//вводим год
	EnterMonth(Time, EtalonTime);//вводим месяц
	EnterDay(Time, EtalonTime);//вводим день
	EnterHours(Time, EtalonTime);//вводим часы
	EnterMinuts(Time, EtalonTime);//вводим минуты
}


void TimeTable::EnterData(DataTime& Time, DataTime& EtalonTime, string msg)
{
	while (true)
	{
		try
		{
			cout << msg << endl;
			EnterDataTime(Time, EtalonTime);//задаём время учитывая эталонное
			break;
		}
		catch (range_error& err)
		{
			cout << red << err.what() << " Try again" << white << endl;
		}
	}
}


void TimeTable::AddTrain()//добавление поезда в расписание
{
	string line(LINE, '-');
	cout << line << endl;

	Train NewTrain;//создаём новый поезд

	string buff;//стринговый буфер для хранения ввода
	cout << "Enter number of train: ";
	cin >> buff;
	NewTrain.SetNuber(buff);//устанавливаем номер поезда

	cout << "Enter the start station: ";
	cin >> buff;
	NewTrain.SetStartStation(buff);//устанавливаем время отправления

	cout << "Enter the finish station: ";
	cin >> buff;
	NewTrain.SetFinishStation(buff);//устанавливаем время прибытия

	DataTime EtalonTime;//задаём эталонное время для старта
						//ведем расписание за 10 лет с 1.1.2012-1.1.2022
	DataTime StartTime;//время отправления поезда
	DataTime FinishTime;//время прибытия

	EnterData(StartTime, EtalonTime, "\nEnter the start data and the start time:");//try ... catch ввод время отправления
	EnterData(FinishTime, StartTime, "\nEnter the finish data and the finish time:");//try ... catch ввод время прибытия

	NewTrain.SetStartTime(StartTime);//устанавливаем время отправки для нового поезда
	NewTrain.SetFinishTime(FinishTime);//устанавливаем время прибытия нового поезда

	Stock.push_back(NewTrain);//добавляем поезд в конец расписания
}


void TimeTable::SearchShowTrain()//поиск и получение информации о поезде
{
	if (Stock.empty())
	{
		cout << "TimeTable is empty!" << endl;
		return;
	}

	string NumberTrain;
	cout << "Enter Number train to search: ";
	cin >> NumberTrain;
	bool flag = false;
	int size = Stock.size();
	cout << endl;
	for (int i = 0; i < size; i++)
	{
		if (Stock[i].GetNuber() == NumberTrain)//выводим информацию, если номер совпал
		{
			flag = true;
			cout << Stock[i] << endl;
		}
	}
	if (!flag)
	{
		cout << "Not find!" << endl;
	}
}


void TimeTable::ShowAll()//показать информацию о всех поездах
{
	if (Stock.empty())
	{
		cout << "TimeTable is empty!" << endl;
		return;
	}

	int size = Stock.size();
	for (int i = 0; i < size; i++)
	{
		cout << i << endl;
		cout << Stock[i] << endl;
		cout << endl;
	}
}

void TimeTable::operator()()//перегрузка ()
{
	cout << white;
	int choice;
	do {
		do {
			char answer[SIZEANSWER];
			cout << ADD << "- Add new train" << endl;
			cout << SHOW << "- Show timetable" << endl;
			cout << SEARCH << "- Search train" << endl;
			cout << EXIT << "- Exit\n" << endl;
			cout << "Your choice:";
			cin >> answer;
			answer[SIZEANSWER - 1] = '\0';
			choice = CheckInputs(answer, ADD);
		} while (choice < ADD || choice > EXIT);

		string line(LINE, '-');
		cout << line << endl;

		switch (menu(choice))
		{
		case ADD:
			AddTrain();//добавить поезд в расписание
			break;
		case SHOW:
			ShowAll();//показать все поезда в расписании
			break;
		case SEARCH:
			SearchShowTrain();//найти поезд в расписании по номеру
			break;
		case EXIT:
			cout << "Good bay!" << endl;
			exit(0);//выход с программы
			break;
		}

		system("pause");
		system("cls");
	} while (true);
}