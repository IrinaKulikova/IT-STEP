#pragma once
#include "stdafx.h"

bool CmpStr(char x)//наличие совпадения
{
	const int size_str_numders = 11;//длина статической строки с цифрами
	char numbers[size_str_numders] = "1234567890";//цифры
	for (int j = 0; j < size_str_numders - 1; j++)//перебираем строку с цифрами
	{
		if (x == numbers[j])//если в строке не цифры, меняем флаг на тру
		{
			return true;//совпадение найдено
		}
	}
	return false;//совпадение не найдено
}

bool CheckStr(char* str)//функция проверяет
{
	fgetc(stdin);//очищаем поток
	int size_str = strlen(str);//длина строки	
	for (int i = 0; i < size_str; i++)//перебираем считанную строку
	{
		if (!CmpStr(str[i]))//передаём каждый символ
		{
			return false;
		}
	}
	return true;//возвращаем флаг
}

int CheckInputs(char* str, int left)//проверка ввода
{
	int result = left - 1;//принимаем значение не входящее в интервал
	if (CheckStr(str))
	{
		result = atoi(str);//переводим строку в инт
	}
	return result;
}