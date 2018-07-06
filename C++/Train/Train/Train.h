#pragma once
#include "stdafx.h"

class Train//����� �����
{
private:
	string Number;//����� ������
	string StartStation;//����� �����������
	string FinishStation;//����� ����������
	DataTime StartTime;//����� �����������
	DataTime FinishTime;//����� ��������
public:
	Train();//�����������
	virtual ~Train();//����������
	void SetStartTime(DataTime StartTime);//������ ������� �����������
	void SetFinishTime(DataTime FinishTime);//������ ������� ��������
	void SetNuber(string Number);//������ ������ ������
	void SetStartStation(string StartStation);//������ ������� �����������
	void SetFinishStation(string FinishStation);//������ ������� ��������
	DataTime GetStartTime();//������ ������� �����������
	DataTime GetFinishTime();//������ ������� ��������
	string GetNuber();//������ ������ ������
	string GetStartStation();//������ ������� �����������
	string GetFinishStation();//������ ������� ��������
	friend ostream& operator<<(ostream& stream, Train& train);//���������� ��������� ������
};