#pragma once
#include "stdafx.h"

bool CmpStr(char x)//наличие совпадения
{
	const int size_str_numders = 16;//длина статической строки с цифрами
	char numbers[size_str_numders] = "1234567890*/-+.";//цифры и операции
	for (int j = 0; j < size_str_numders - 1; j++)//перебираем строку с выражением
	{
		if (x == numbers[j])//если в строке не цифры, меняем флаг на тру
		{
			return true;//совпадение найдено
		}
	}
	return false;//совпадение не найдено
}

bool CheckInputs(char* str)//функция проверяет
{
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