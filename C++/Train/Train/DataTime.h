#pragma once
#pragma once
#include "stdafx.h"

class DataTime//����� ���� � �����
{
private:
	int Year;//���
	MONTH Month;//�����
	int Day;//����� ������
	int Hours;//���� 
	int Minuts;//������
public:
	DataTime();//�����������
	virtual ~DataTime();//����������
	void SetYear(int Year);//������ ����
	void SetMonth(MONTH Month);//������ ������
	void SetDay(int Day);//������ ���
	void SetHours(int Hours);//������ ����
	void SetMinuts(int Minuts);	//������ �����
	int GetYear();//������ ����
	MONTH GetMonth();//������ ������
	int GetDay();//������ ���
	int GetHours();//������ �����
	int GetMinuts();//������ �����
	friend ostream& operator<<(ostream& stream, DataTime& data);//�������� ������
};