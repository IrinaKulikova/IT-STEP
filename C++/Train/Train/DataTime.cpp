#pragma once
#include "stdafx.h"

DataTime::DataTime()//�����������
{
	Year = MINYEAR;
	Month = JANUARY;
	Day = FIRSTDAYMONTH;
	Hours = MINHOUR;
	Minuts = MINMINUTS;
}

DataTime::~DataTime()//����������
{}


void DataTime::SetYear(int Year)//c����� ����
{
	this->Year = Year;
}


void DataTime::SetMonth(MONTH Month)
{
	this->Month = Month;
}


void DataTime::SetDay(int Day)
{
	this->Day = Day;
}


void DataTime::SetHours(int Hours)
{
	this->Hours = Hours;
}


void DataTime::SetMinuts(int Minuts)
{
	this->Minuts = Minuts;
}


int DataTime::GetYear()
{
	return Year;
}


MONTH DataTime::GetMonth()
{
	return Month;
}


int DataTime::GetDay()
{
	return Day;
}


int DataTime::GetHours()
{
	return Hours;
}


int DataTime::GetMinuts()
{
	return Minuts;
}