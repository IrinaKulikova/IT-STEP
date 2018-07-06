#pragma once
#include "stdafx.h"

bool CmpStr(char x)//������� ����������
{
	const int size_str_numders = 16;//����� ����������� ������ � �������
	char numbers[size_str_numders] = "1234567890*/-+.";//����� � ��������
	for (int j = 0; j < size_str_numders - 1; j++)//���������� ������ � ����������
	{
		if (x == numbers[j])//���� � ������ �� �����, ������ ���� �� ���
		{
			return true;//���������� �������
		}
	}
	return false;//���������� �� �������
}

bool CheckInputs(char* str)//������� ���������
{
	int size_str = strlen(str);//����� ������	
	for (int i = 0; i < size_str; i++)//���������� ��������� ������
	{
		if (!CmpStr(str[i]))//������� ������ ������
		{
			return false;
		}
	}
	return true;//���������� ����
}