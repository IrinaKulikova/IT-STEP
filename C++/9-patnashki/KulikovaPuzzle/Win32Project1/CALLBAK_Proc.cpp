#pragma once
#include "stdafx.h"

BOOL CALLBACK DlgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
		/*case WM_CREATE:
		{
			UINT style = GetClassLong(hWnd, GCL_STYLE);
			SetClassLong(hWnd, GCL_STYLE, style | CS_DBLCLKS);
			return TRUE;
		}*/
	case WM_INITDIALOG:
		CheckRadioButton(hWnd, IDC_3X3, IDC_5X5, IDC_4X4);
		CreateVectorNumber();//создание вектора имён кнопок
		CreateButtons(hWnd);//создаём кнопки	
		NewGame();
		InvalidateRect(hDlg, NULL, TRUE);//отрисовываем диалоговое окно
		return TRUE;

	case WM_COMMAND:
	{
		HWND ClickPuzzle = (HWND)lParam;

		switch (LOWORD(wParam))
		{

		case ENDGAME:
			DestroyWindow(hWnd);
			PostQuitMessage(0);
			return TRUE;
		case IDC_BUTTON_NEW_GAME:
			NewGame();//перемешиваем пазлы
			return TRUE;

		case FIRSTBUTTON:
			CheckToChangePuzzle(hWnd, ClickPuzzle);
			return TRUE;

		case IDC_3X3:
		{
			int state = IsDlgButtonChecked(hWnd, IDC_3X3);
			switch (state)
			{
			case BST_CHECKED://кнопка активна, генерируем новую игру
				CreateGame(hWnd, LIGHT, MINHEIGHT, MINWIDTH);
				break;
			}
		}

		case IDC_4X4:
		{
			int state = IsDlgButtonChecked(hWnd, IDC_4X4);
			switch (state)
			{
			case BST_CHECKED://кнопка активна генерируем новую игру
				CreateGame(hWnd, MIDLE, MDLHEIGHT, MDLWIDTH);
				break;
			}
		}

		case IDC_5X5:
		{
			int state = IsDlgButtonChecked(hWnd, IDC_5X5);
			switch (state)
			{
			case BST_CHECKED://кнопка активна генерируем новую игру
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
