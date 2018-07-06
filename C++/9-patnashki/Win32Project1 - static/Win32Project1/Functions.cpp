#pragma once
#include "stdafx.h"

VOID CreateVectorNumber()
{
	for (int i = 0; i < SizePuzzle*SizePuzzle - 1; i++)
	{
		wstringstream buff;
		buff << (i + 1) << '\0';
		Buttons.push_back(buff.str());
	}
	Buttons.push_back(TEXT(""));
	//random_shuffle(Buttons.begin(), Buttons.end());
}

VOID CreateButtons(HWND hWnd)//создание кнопок
{
	int StartDrawX = 50;//начало отрисовки кнопок по оси Х
	int StartDrawY = 10;//начало отрисовки кнопок по оси Y
	int SizeButton = 50;//размер кнопки
	int Step = 10;//расстояние между кнопками
	HWND hBut = NULL;//дескриптор созданной кнопки

	for (int j = 0; j < SizePuzzle; j++)//перебираем по строками
	{
		for (int i = 0; i < SizePuzzle; i++)//перебираем по столбцам
		{
			/*hBut = CreateWindow(TEXT("BUTTON"), Buttons[(i + 1) + SizePuzzle*j - 1].data(),
				BS_CENTER | BS_NOTIFY | WS_CHILD | WS_VISIBLE, StartDrawX + SizeButton + Step,
				StartDrawY, SizeButton, SizeButton, hWnd, (HMENU)MENU_BUTTON, GetModuleHandle(0), NULL);
		*/
			hBut = CreateWindow(TEXT("STATIC"), Buttons[(i + 1) + SizePuzzle*j - 1].data(),
				SS_CENTER | SS_NOTIFY | WS_BORDER | WS_CHILD | WS_VISIBLE, StartDrawX + SizeButton + Step,
				StartDrawY, SizeButton, SizeButton, hWnd, (HMENU)MENU_BUTTON, GetModuleHandle(0), NULL);

			ShowWindow(hBut, SW_SHOW);
			StartDrawX = StartDrawX + SizeButton + Step;
			ButtonsHWND.push_back(hBut);
		}
		StartDrawX = 50;
		StartDrawY = StartDrawY + SizeButton + Step;
	}
}

VOID DelPuzzle()
{
	if (!ButtonsHWND.empty())
	{
		for (int i = 0; i < SizePuzzle*SizePuzzle; i++)
		{
			DestroyWindow(ButtonsHWND[i]);
		}
	}
	ButtonsHWND.clear();
	Buttons.clear();
}

VOID NewGame()
{
	random_shuffle(Buttons.begin(), Buttons.end());
	for (int i = 0; i < SizePuzzle*SizePuzzle; i++)
	{
		SetWindowText(ButtonsHWND[i], Buttons[i].data());
		if (Buttons[i] == TEXT(""))
		{
			EmptyPuzzle = ButtonsHWND[i];
			IndexEmptyPuzzle = i;
		}
	}
	InvalidateRect(hDlg, 0, TRUE);//отрисовываем диалоговое окно
}

VOID CreateGame(HWND hWnd, int level, int height, int width)//генерируем игру
{
	DelPuzzle();//удаляем копки, совобождаем вектор
	SizePuzzle = level;//устанавливаем уровень сложности
	MoveWindow(hDlg, 0, 0, height, width, TRUE);//устанавливаем размер окна
	CreateVectorNumber();//создание вектора имён кнопок
	CreateButtons(hWnd);//создаём кнопки
	InvalidateRect(hDlg, 0, TRUE);//отрисовываем диалоговое окно
	NewGame();
}


bool CheckPositions(int IndexClickPuzzle, int IndexEmptyPuzzle)
{
	if (IndexClickPuzzle == IndexEmptyPuzzle - SizePuzzle || IndexClickPuzzle == IndexEmptyPuzzle + SizePuzzle)
	{
		if (IndexClickPuzzle % SizePuzzle)
		{
			return true;
		}
	}

	if (IndexEmptyPuzzle == IndexClickPuzzle - SizePuzzle || IndexEmptyPuzzle == IndexClickPuzzle + SizePuzzle)
	{
		if (IndexEmptyPuzzle % SizePuzzle)
		{
			return true;
		}
	}

	if (IndexClickPuzzle == IndexEmptyPuzzle - 1)
	{
		if (IndexEmptyPuzzle%SizePuzzle == 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}


	if (IndexClickPuzzle == IndexEmptyPuzzle + 1)
	{
		if (IndexClickPuzzle%SizePuzzle == 0)
		{
			return false;
		}
		else
		{
			return true;
		}
	}

	if (IndexEmptyPuzzle == IndexClickPuzzle - 1 || IndexEmptyPuzzle == IndexClickPuzzle + 1)
	{
		if (IndexEmptyPuzzle%SizePuzzle)
		{
			return true;
		}
	}
	return false;
}


VOID CheckToChangePuzzle(HWND hWnd, HWND ClickPuzzle)//проверка и смена позиций
{
	int IndexClicked;//индекс первой кнопки
	int IndexEmptyPuzzle;//индекс второй кнопки 
	for (int i = 0; i < SizePuzzle*SizePuzzle; i++)
	{
		if (ClickPuzzle == ButtonsHWND[i])
		{
			IndexClicked = i;
		}
		if (EmptyPuzzle == ButtonsHWND[i])
		{
			IndexEmptyPuzzle = i;
		}
	}

	if (CheckPositions(IndexClicked, IndexEmptyPuzzle))//если кнопки стоят рядом, их можно менять
	{
		wchar_t FirstString[SIZESTRING];
		wchar_t SecondString[SIZESTRING];

		GetWindowText(ClickPuzzle, FirstString, SIZESTRING - 1);
		GetWindowText(EmptyPuzzle, SecondString, SIZESTRING - 1);

		SetWindowText(EmptyPuzzle, SecondString);
		SetWindowText(ClickPuzzle, FirstString);
	}

	InvalidateRect(EmptyPuzzle, NULL, TRUE);
	InvalidateRect(ClickPuzzle, NULL, TRUE);
	EmptyPuzzle = ClickPuzzle;
	InvalidateRect(hWnd, NULL, TRUE);
}