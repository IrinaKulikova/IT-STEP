#pragma once
#include "stdafx.h"
#include "DataTime.h"

TimeTable::TimeTable()//�����������
{}


TimeTable::~TimeTable()//����������
{}


void TimeTable::EnterYear(DataTime& Time, DataTime& EtalonTime)//���� ����
{
	char answer[SIZEANSWER];//��������� ���� ������������
	cout << "Yaer: ";
	cin >> answer;
	answer[SIZEANSWER - 1] = '\0';
	int YearUser = CheckInputs(answer, MINYEAR);

	range_error err("Invalid data: year");
	if (YearUser < EtalonTime.GetYear())//��������� ��� ������� ��������, ���� ��� �������� �� ��� ������ ���� �����������
	{
		throw err;
	}
	if (YearUser < MINYEAR || YearUser > MAXYEAR)//������ ������� �� �������� ���������� ��������
	{
		throw err;
	}
	Time.SetYear(YearUser);//������������� ���
}


void TimeTable::EnterMonth(DataTime& Time, DataTime& EtalonTime)//���� ������
{
	char answer[SIZEANSWER];
	cout << "Month: ";
	cin >> answer;
	answer[SIZEANSWER - 1] = '\0';
	int MonthUser = CheckInputs(answer, JANUARY);

	range_error err("Invalid data: month");
	if (Time.GetYear() == EtalonTime.GetYear() && MonthUser < EtalonTime.GetMonth())//��������� �������������� ����, ���� ���� �������� ���� ������ ���� ��������
	{
		throw err;
	}
	if (MonthUser < JANUARY || MonthUser > DECEMBER)
	{
		throw err;
	}
	Time.SetMonth((MONTH)MonthUser);//������������� �����
}


void TimeTable::EnterDay(DataTime& Time, DataTime& EtalonTime)//���� ���
{
	char answer[SIZEANSWER];
	cout << "Day: ";
	cin >> answer;
	answer[SIZEANSWER - 1] = '\0';
	int DayUser = CheckInputs(answer, 0);
	MONTH MonthThisTrain = Time.GetMonth();

	range_error err("Invalid data: day");
	if (FEBRUARY == MonthThisTrain)//���� ������ �������
	{
		if ((Time.GetYear() % 4 == 0 && Time.GetYear() % 100 != 0) || Time.GetYear() % 400 == 0)
		{
			if (DayUser < FIRSTDAYMONTH || DayUser > LASTLONGFEBRUARY)//�������� �� ����� ������ � ������������ �����
			{
				throw err;
			}
		}
		else
		{
			if (DayUser < FIRSTDAYMONTH || DayUser > LASTSHOTFEBRUARY)//�������� �� ����� ������ � ������������ �����
			{
				throw err;
			}
		}
	}
	else if (APRIL == MonthThisTrain || JUNE == MonthThisTrain || SEPTEMBER == MonthThisTrain || NOVEMBER == MonthThisTrain)//���� ����� ��������
	{
		if (DayUser > LASTDAYSHOTMONTH || DayUser < FIRSTDAYMONTH)//�������� �� ����� ������ � ������������ �����
		{
			throw err;
		}
	}
	else//���� ����� �������
	{
		if (DayUser > LASTDAYLONGMONTH || DayUser < FIRSTDAYMONTH)//�������� �� ����� ������ � ������������ �����
		{
			throw err;
		}
	}

	if (Time.GetYear() == EtalonTime.GetYear() && Time.GetMonth() == EtalonTime.GetMonth() && DayUser < EtalonTime.GetDay())//��������� �������������� ����, ���� ���� �������� ���� ������ ���� ��������
	{
		throw err;
	}
	Time.SetDay(DayUser);
}


void TimeTable::EnterHours(DataTime& Time, DataTime& EtalonTime)//���� �����
{
	char answer[SIZEANSWER];
	cout << "Hours: ";
	cin >> answer;
	answer[SIZEANSWER - 1] = '\0';
	int	HoursUser = CheckInputs(answer, MINHOUR);

	range_error err("Invalid data: hours");
	if (EtalonTime.GetYear() == Time.GetYear() && EtalonTime.GetMonth() == Time.GetMonth()
		&& EtalonTime.GetDay() == Time.GetDay() && HoursUser < EtalonTime.GetHours())//��������� �������������� ����, ���� ���� �������� ���� ������ ���� ��������
	{
		throw err;
	}
	if (HoursUser<MINHOUR || HoursUser>MAXHOUR)
	{
		throw err;
	}
	Time.SetHours(HoursUser);
}


void TimeTable::EnterMinuts(DataTime& Time, DataTime& EtalonTime)//���� �����
{
	char answer[SIZEANSWER];
	cout << "Minuts: ";
	cin >> answer;
	answer[SIZEANSWER - 1] = '\0';
	int	MinutsUser = CheckInputs(answer, MINMINUTS);

	range_error err("Invalid data: hours");
	if (EtalonTime.GetYear() == Time.GetYear() && EtalonTime.GetMonth() == Time.GetMonth()
		&& EtalonTime.GetDay() == Time.GetDay() && Time.GetHours() < EtalonTime.GetHours()
		&& MinutsUser <= EtalonTime.GetMinuts())//��������� �������������� ����, ���� ���� �������� ���� ������ ���� ��������
	{
		throw err;
	}
	if (MinutsUser < MINMINUTS || MinutsUser > MAXMINUTS)
	{
		throw err;
	}
	Time.SetMinuts(MinutsUser);
}


void TimeTable::EnterDataTime(DataTime& Time, DataTime& EtalonTime)//������ ����
{
	EnterYear(Time, EtalonTime);//������ ���
	EnterMonth(Time, EtalonTime);//������ �����
	EnterDay(Time, EtalonTime);//������ ����
	EnterHours(Time, EtalonTime);//������ ����
	EnterMinuts(Time, EtalonTime);//������ ������
}


void TimeTable::EnterData(DataTime& Time, DataTime& EtalonTime, string msg)
{
	while (true)
	{
		try
		{
			cout << msg << endl;
			EnterDataTime(Time, EtalonTime);//����� ����� �������� ���������
			break;
		}
		catch (range_error& err)
		{
			cout << red << err.what() << " Try again" << white << endl;
		}
	}
}


void TimeTable::AddTrain()//���������� ������ � ����������
{
	string line(LINE, '-');
	cout << line << endl;

	Train NewTrain;//������ ����� �����

	string buff;//���������� ����� ��� �������� �����
	cout << "Enter number of train: ";
	cin >> buff;
	NewTrain.SetNuber(buff);//������������� ����� ������

	cout << "Enter the start station: ";
	cin >> buff;
	NewTrain.SetStartStation(buff);//������������� ����� �����������

	cout << "Enter the finish station: ";
	cin >> buff;
	NewTrain.SetFinishStation(buff);//������������� ����� ��������

	DataTime EtalonTime;//����� ��������� ����� ��� ������
						//����� ���������� �� 10 ��� � 1.1.2012-1.1.2022
	DataTime StartTime;//����� ����������� ������
	DataTime FinishTime;//����� ��������

	EnterData(StartTime, EtalonTime, "\nEnter the start data and the start time:");//try ... catch ���� ����� �����������
	EnterData(FinishTime, StartTime, "\nEnter the finish data and the finish time:");//try ... catch ���� ����� ��������

	NewTrain.SetStartTime(StartTime);//������������� ����� �������� ��� ������ ������
	NewTrain.SetFinishTime(FinishTime);//������������� ����� �������� ������ ������

	Stock.push_back(NewTrain);//��������� ����� � ����� ����������
}


void TimeTable::SearchShowTrain()//����� � ��������� ���������� � ������
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
		if (Stock[i].GetNuber() == NumberTrain)//������� ����������, ���� ����� ������
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


void TimeTable::ShowAll()//�������� ���������� � ���� �������
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

void TimeTable::operator()()//���������� ()
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
			AddTrain();//�������� ����� � ����������
			break;
		case SHOW:
			ShowAll();//�������� ��� ������ � ����������
			break;
		case SEARCH:
			SearchShowTrain();//����� ����� � ���������� �� ������
			break;
		case EXIT:
			cout << "Good bay!" << endl;
			exit(0);//����� � ���������
			break;
		}

		system("pause");
		system("cls");
	} while (true);
}