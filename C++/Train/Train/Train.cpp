#pragma once
#include "stdafx.h"

Train::Train()//�����������
{
	this->Number = "No number";
	this->StartStation = "No Start Station";
	this->FinishStation = "No Finish Station";
}

Train::~Train()//����������
{}


void Train::SetStartTime(DataTime StartTime)//������ ������� �����������
{
	this->StartTime = StartTime;
}


void Train::SetFinishTime(DataTime FinishTime)//������ ������� ��������
{
	this->FinishTime = FinishTime;
}


void Train::SetNuber(string Number)//������ ������ ������
{
	this->Number = Number;
}


void Train::SetStartStation(string StartStation)//������ ������� �����������
{
	this->StartStation = StartStation;
}


void Train::SetFinishStation(string FinishStation)//������ ������� ��������
{
	this->FinishStation = FinishStation;
}

DataTime Train::GetStartTime()//������ ������� �����������
{
	return StartTime;
}


DataTime Train::GetFinishTime()//������ ������� ��������
{
	return FinishTime;
}


string Train::GetNuber()//������ ������ ������
{
	return Number;
}


string Train::GetStartStation()//������ ������� �����������
{
	return StartStation;
}


string Train::GetFinishStation()//������ ������� ��������
{
	return FinishStation;
}