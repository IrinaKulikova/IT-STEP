#pragma once
#include "HeaderProject.h"
#pragma warning(disable:4996)


void WriteData(HWND hWnd)//������ ������ � ����
{
	int nLines = Edit_GetLineCount(GetDlgItem(hWnd, IDC_EDIT_TEXT));//���������� ������� ����� � Edit Control
	wchar_t buff[SIZESTRING];//�������� ����� ��� ����������

	ofstream out(PathFile, ios::out | ios::trunc);//��������� �������� ����� �� ������ � ���� ������

	int nLen = 0;//����� ������
	int nSymbol = 0;//����� ������� ������� � ������, ��� ��������� �������
	for (int i = 0; i < nLines; i++)
	{
		nLen = SendDlgItemMessage(hWnd, IDC_EDIT_TEXT, EM_LINELENGTH, nSymbol, NULL);
		Edit_GetLine(GetDlgItem(hWnd, IDC_EDIT_TEXT), i, buff, nLen);//��������� ������ � �����
		buff[nLen] = '\0';//���������� ����� ������
		string lpszText(nLen, 0);//������ ������ ANSI
		lpszText[nLen] = '\0';//���������� � ����� ������ \0
		WideCharToMultiByte(CP_ACP, 0, &buff[0], nLen, &lpszText[0], nLen, NULL, NULL);//������������ ����� UNICODE � ��������� � ANSI ������
		out << lpszText;//���������� ������ � �������� �����
		if (i != nLines - 1)//� ����� ����� ���������� �����������
		{
			out << endl;
		}
		nSymbol += nLen + ENDLINESYMBOL;//������� ��������� ����� ������� ������� � ������, ��������� ����� ������ + \r\n
	}
	out.close();//��������� �������� �����
}



void ReadData(HWND hWnd)//������ ������ �� �����
{
	ifstream in(PathFile);//��������� ����� �� ������
	wstringstream FileData;//��������� ����� ������� �� �����

	if (in.is_open())//���� ���� ������
	{
		while (!in.eof())//��� �� ����� �����
		{
			string line;//������ ������ ANSI
			getline(in, line);//��������� � ��� ������ ������ �� �����
			wchar_t* lpwzLine = new wchar_t[line.length() + 1];//������ NICODE ������
			lpwzLine[line.length()] = L'\0';//���������� � ����� ������ 0
			MultiByteToWideChar(CP_ACP, 0, line.c_str(), -1, lpwzLine, (int)line.length());//��������������� ������ � ���������� ��������� � ������ UNICODE
																						   //Lines.push_back(lpwzLine);//��������� ������ � ������
			FileData << lpwzLine << TEXT("\r\n");
		}
		in.close();//��������� ����
		SetDlgItemText(hWnd, IDC_EDIT_TEXT, FileData.str().data());
		InvalidateRect(hWnd, 0, TRUE);
	}
}