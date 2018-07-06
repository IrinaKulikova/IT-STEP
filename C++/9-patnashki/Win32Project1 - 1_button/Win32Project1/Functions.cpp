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
	random_shuffle(Buttons.begin(), Buttons.end());
}

VOID CreateButtons(HWND hWnd)//�������� ������
{
	int StartDrawX = 50;//������ ��������� ������ �� ��� �
	int StartDrawY = 10;//������ ��������� ������ �� ��� Y
	int SizeButton = 50;//������ ������
	int Step = 10;//���������� ����� ��������
	HWND hBut = NULL;//���������� ��������� ������

	for (int j = 0; j < SizePuzzle; j++)//���������� �� ��������
	{
		for (int i = 0; i < SizePuzzle; i++)//���������� �� ��������
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
	InvalidateRect(hDlg, 0, TRUE);//������������ ���������� ����
}

VOID CreateGame(HWND hWnd, int level, int height, int width)//���������� ����
{
	DelPuzzle();//������� �����, ����������� ������
	SizePuzzle = level;//������������� ������� ���������
	MoveWindow(hDlg, 0, 0, height, width, TRUE);//������������� ������ ����
	CreateVectorNumber();//�������� ������� ��� ������
	CreateButtons(hWnd);//������ ������
	InvalidateRect(hDlg, 0, TRUE);//������������ ���������� ����
}

VOID CheckToChangePuzzle(HWND first, HWND second)//�������� � ����� �������
{
	if (first != EmptyPuzzle && second != EmptyPuzzle)//���� ��� ������ �� ������, �� ������ �������
	{
		return;
	}
	int IndexFirst;//������ ������ ������ � ������� 
	int IndexSecond;//������ ������ ������ � ������� 
	for (int i = 0; i < SizePuzzle*SizePuzzle; i++)
	{
		if (first == ButtonsHWND[i])
		{
			IndexFirst = i;
		}
		if (second == ButtonsHWND[i])
		{
			IndexSecond = i;
		}
	}

	if (CheckPositions(IndexFirst, IndexSecond))//���� ������ ����� �����, �� ����� ������
	{
		wchar_t FirstString[SIZESTRING];
		wchar_t SecondString[SIZESTRING];

		GetWindowText(first, FirstString, SIZESTRING - 1);
		GetWindowText(second, SecondString, SIZESTRING - 1);

		SetWindowText(first, SecondString);
		SetWindowText(second, FirstString);
	}
	ClickPuzzle = NULL;
}

bool CheckPositions(int IndexFirst, int IndexSecond)
{
	if (((IndexFirst == IndexSecond - SizePuzzle || IndexFirst == IndexSecond + SizePuzzle) && IndexFirst%SizePuzzle))
	{
		return true;
	}
	if ((IndexFirst == IndexSecond - 1) || (IndexFirst == IndexSecond + 1) && IndexFirst%SizePuzzle)
	{
		return true;
	}
	return false;
}