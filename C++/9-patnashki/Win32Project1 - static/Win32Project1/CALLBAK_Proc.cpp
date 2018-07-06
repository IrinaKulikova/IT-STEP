#pragma once
#include "stdafx.h"

BOOL CALLBACK DlgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_INITDIALOG:
		CheckRadioButton(hWnd, IDC_3X3, IDC_5X5, IDC_4X4);
		CreateVectorNumber();//�������� ������� ��� ������
		CreateButtons(hWnd);//������ ������	
		NewGame();
		InvalidateRect(hDlg, NULL, TRUE);//������������ ���������� ����
		return TRUE;

	case WM_COMMAND:
	{
		HWND ClickPuzzle = (HWND)lParam;

		switch (HIWORD(wParam))
		{
		case STN_CLICKED:
			CheckToChangePuzzle(hWnd, ClickPuzzle);
			break;
		}
		return TRUE;

		switch (LOWORD(wParam))
		{
		case IDC_BUTTON_NEW_GAME:
			NewGame();//������������ �����
			return TRUE;

		case IDC_3X3:
		{
			int state = IsDlgButtonChecked(hWnd, IDC_3X3);
			switch (state)
			{
			case BST_CHECKED://������ �������, ���������� ����� ����
				CreateGame(hWnd, LIGHT, MINHEIGHT, MINWIDTH);
				break;
			}
		}

		case IDC_4X4:
		{
			int state = IsDlgButtonChecked(hWnd, IDC_4X4);
			switch (state)
			{
			case BST_CHECKED://������ ������� ���������� ����� ����
				CreateGame(hWnd, MIDLE, MDLHEIGHT, MDLWIDTH);
				break;
			}
		}

		case IDC_5X5:
		{
			int state = IsDlgButtonChecked(hWnd, IDC_5X5);
			switch (state)
			{
			case BST_CHECKED://������ ������� ���������� ����� ����
				CreateGame(hWnd, HARD, MAXHEIGHT, MAXWIDTH);
				break;
			}
		}
		}
	}
	return TRUE;

	case WM_CLOSE:
		DestroyWindow(hWnd);
		PostQuitMessage(0);
		return TRUE;
	}
	return FALSE;
}
