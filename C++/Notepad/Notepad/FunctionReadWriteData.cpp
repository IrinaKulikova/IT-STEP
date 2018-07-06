#pragma once
#include "HeaderProject.h"
#pragma warning(disable:4996)


void WriteData(HWND hWnd)//запись данных в фаил
{
	int nLines = Edit_GetLineCount(GetDlgItem(hWnd, IDC_EDIT_TEXT));//определяем сколько строк в Edit Control
	wchar_t buff[SIZESTRING];//выделяем буфер для считывания

	ofstream out(PathFile, ios::out | ios::trunc);//открываем файловый поток на запись в фаил данных

	int nLen = 0;//длина строки
	int nSymbol = 0;//номер первого символа в строке, где находится каретка
	for (int i = 0; i < nLines; i++)
	{
		nLen = SendDlgItemMessage(hWnd, IDC_EDIT_TEXT, EM_LINELENGTH, nSymbol, NULL);
		Edit_GetLine(GetDlgItem(hWnd, IDC_EDIT_TEXT), i, buff, nLen);//считываем строку в буфер
		buff[nLen] = '\0';//обозначаем конец строки
		string lpszText(nLen, 0);//создаём строку ANSI
		lpszText[nLen] = '\0';//выставляем в конце строки \0
		WideCharToMultiByte(CP_ACP, 0, &buff[0], nLen, &lpszText[0], nLen, NULL, NULL);//конвертируеи текст UNICODE и сохраняем в ANSI строку
		out << lpszText;//отправляем строку в файловый поток
		if (i != nLines - 1)//в конце строк отправляем разделитель
		{
			out << endl;
		}
		nSymbol += nLen + ENDLINESYMBOL;//считаем следующий номер вервого символа в строке, добавляем длину строки + \r\n
	}
	out.close();//закрываем файловый поток
}



void ReadData(HWND hWnd)//чтение данных из файла
{
	ifstream in(PathFile);//открываем поток на чтение
	wstringstream FileData;//строковый поток дафнных из файла

	if (in.is_open())//если фаил открыт
	{
		while (!in.eof())//идём до конца файла
		{
			string line;//создам строку ANSI
			getline(in, line);//считываем в эту строку данные из файла
			wchar_t* lpwzLine = new wchar_t[line.length() + 1];//создаём NICODE строку
			lpwzLine[line.length()] = L'\0';//выставляем в конце строки 0
			MultiByteToWideChar(CP_ACP, 0, line.c_str(), -1, lpwzLine, (int)line.length());//преобразовываем строку и записываем результат в строку UNICODE
																						   //Lines.push_back(lpwzLine);//добавляем строку в вектор
			FileData << lpwzLine << TEXT("\r\n");
		}
		in.close();//закрываем фаил
		SetDlgItemText(hWnd, IDC_EDIT_TEXT, FileData.str().data());
		InvalidateRect(hWnd, 0, TRUE);
	}
}