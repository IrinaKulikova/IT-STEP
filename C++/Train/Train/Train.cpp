#pragma once
#include "stdafx.h"

Train::Train()//конструктор
{
	this->Number = "No number";
	this->StartStation = "No Start Station";
	this->FinishStation = "No Finish Station";
}

Train::~Train()//деструктор
{}


void Train::SetStartTime(DataTime StartTime)//сеттер времени отправления
{
	this->StartTime = StartTime;
}


void Train::SetFinishTime(DataTime FinishTime)//сеттер времени прибытия
{
	this->FinishTime = FinishTime;
}


void Train::SetNuber(string Number)//сеттер номера поезда
{
	this->Number = Number;
}


void Train::SetStartStation(string StartStation)//сеттер станции отправления
{
	this->StartStation = StartStation;
}


void Train::SetFinishStation(string FinishStation)//сеттер станции прибытия
{
	this->FinishStation = FinishStation;
}

DataTime Train::GetStartTime()//геттер времени отправления
{
	return StartTime;
}


DataTime Train::GetFinishTime()//геттер времени прибытия
{
	return FinishTime;
}


string Train::GetNuber()//геттер номера поезда
{
	return Number;
}


string Train::GetStartStation()//геттер станции отправления
{
	return StartStation;
}


string Train::GetFinishStation()//геттер станции прибытия
{
	return FinishStation;
}