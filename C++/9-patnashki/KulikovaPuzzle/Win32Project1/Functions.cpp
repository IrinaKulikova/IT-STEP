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
			hBut = CreateWindow(TEXT("BUTTON"), Buttons[(i + 1) + SizePuzzle*j - 1].data(),
				BS_CENTER | BS_NOTIFY | WS_CHILD | WS_VISIBLE, StartDrawX + SizeButton + Step,
				StartDrawY, SizeButton, SizeButton, hWnd, (HMENU)FIRSTBUTTON, GetModuleHandle(0), NULL);
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
	//random_shuffle(Buttons.begin(), Buttons.end());
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
	NewGame();
}


bool CheckPositions(int IndexClickPuzzle, int IndexEmptyPuzzle)
{
	if (IndexClickPuzzle == IndexEmptyPuzzle - SizePuzzle || IndexClickPuzzle == IndexEmptyPuzzle + SizePuzzle)
	{
		return true;
	}

	if (IndexClickPuzzle == IndexEmptyPuzzle - 1)
	{
		if (IndexEmptyPuzzle%SizePuzzle)
		{
			return true;
		}
	}

	if (IndexClickPuzzle == IndexEmptyPuzzle + 1)
	{
		if (IndexClickPuzzle%SizePuzzle)
		{
			return true;
		}
	}
	return false;
}


VOID CheckToChangePuzzle(HWND hWnd, HWND ClickPuzzle)//�������� � ����� �������
{
	int IndexClicked;//������ ������ ������
	int IndexEmptyPuzzle;//������ ������ ������ 
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

	if (CheckPositions(IndexClicked, IndexEmptyPuzzle))//���� ������ ����� �����, �� ����� ������
	{
		wchar_t FirstString[SIZESTRING];
		wchar_t SecondString[SIZESTRING];

		GetWindowText(ClickPuzzle, FirstString, SIZESTRING - 1);
		GetWindowText(EmptyPuzzle, SecondString, SIZESTRING - 1);

		SetWindowText(ClickPuzzle, SecondString);
		SetWindowText(EmptyPuzzle, FirstString);

		EmptyPuzzle = ClickPuzzle;
		InvalidateRect(hWnd, NULL, TRUE);
		if (CheckWin())//�������� �� ������
		{
			int Step = 50;
			DelPuzzle();
			RECT RectDlg;
			GetWindowRect(hDlg, &RectDlg);

			HBITMAP hMyBitmap = (HBITMAP)LoadImage(GetModuleHandle(0), MAKEINTRESOURCE(IDB_BITMAP1), IMAGE_BITMAP, RectDlg.right - RectDlg.left, RectDlg.bottom - RectDlg.top, LR_COPYFROMRESOURCE);
			HWND hStatic = CreateWindow(TEXT("STATIC"), TEXT("MySt"), WS_CHILD | WS_VISIBLE | SS_BITMAP | SS_CENTERIMAGE,
				0, 0, RectDlg.right - RectDlg.left, RectDlg.bottom - RectDlg.top, hDlg, NULL, GetModuleHandle(0), NULL);
			SendMessage(hStatic, (UINT)STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hMyBitmap);

			EnableWindow(GetDlgItem(hDlg, IDC_3X3), false);
			EnableWindow(GetDlgItem(hDlg, IDC_4X4), false);
			EnableWindow(GetDlgItem(hDlg, IDC_5X5), false);
			EnableWindow(GetDlgItem(hDlg, IDC_BUTTON_NEW_GAME), false);

			HWND End = CreateWindow(TEXT("BUTTON"), TEXT("������!!!"),
				BS_CENTER | BS_NOTIFY | WS_CHILD | WS_VISIBLE, (RectDlg.right - RectDlg.left) - 2.5 * Step,
				(RectDlg.bottom - RectDlg.top) - 1.75 * Step, Step * 2, Step*0.75, hWnd, (HMENU)ENDGAME, GetModuleHandle(0), NULL);

			InvalidateRect(hDlg, NULL, TRUE);
		}
	}
}


bool CheckWin()//�������� �� ������
{
	wchar_t first[SIZESTRING];
	wchar_t second[SIZESTRING];
	wchar_t* buff;

	for (int i = 0; i < SizePuzzle*SizePuzzle - 2; i++)
	{
		GetWindowText(ButtonsHWND[i], first, SIZESTRING - 1);
		GetWindowText(ButtonsHWND[i + 1], second, SIZESTRING - 1);

		int NumberFirst = wcstol(first, &buff, DEC);
		int NumberSecond = wcstol(second, &buff, DEC);

		if (NumberSecond < NumberFirst)
		{
			return false;
		}
	}
	return true;
}