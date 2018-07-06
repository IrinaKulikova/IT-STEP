#pragma once
#include "stdafx.h"

class TimeTable//����� ������
{
private:
	deque<Train> Stock;//������ �������
	void EnterYear(DataTime& Time, DataTime& EtalonTime);//���� ����
	void EnterMonth(DataTime& Time, DataTime& EtalonTime);//���� ������
	void EnterDay(DataTime& Time, DataTime& EtalonTime);//���� ���
	void EnterHours(DataTime& Time, DataTime& EtalonTime);//���� �����
	void EnterMinuts(DataTime& Time, DataTime& EtalonTime);//���� �����
	void EnterDataTime(DataTime& Time, DataTime& DefaultTime);//������ ����
	void EnterData(DataTime& Time, DataTime& EtalonTime, string msg);
	void AddTrain();//�������� �����
	void SearchShowTrain();//����� � �������� ���������� � ������
	void ShowAll();//�������� ���������� � ���� �������
public:
	TimeTable();//�����������
	virtual ~TimeTable();//����������
	void operator()();//������������� ()
};