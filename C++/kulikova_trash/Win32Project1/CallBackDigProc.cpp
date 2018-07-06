#pragma once
#include "HeaderProject.h"


BOOL CALLBACK DlgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	static BOOL flagCursorStatic = false;//флаг нажатия левой кнопки мыши на статике
	static BOOL flagOpenTrash = false;//флаг открытия урны
	static BOOL flagCursorTrash = false;//флаг нахождения курсора мыши в пределах урны
	static BOOL MoveStatic = false;//флаг перемещения статика
	static BOOL flagCreatStatic = false;//флаг создания статического окна
	static BOOL flagBorder = false;//флаг расположения картинки в рамки клиентской зоны окна приложения
	static HCURSOR hCursor = NULL;//дескриптор курсора

	static POINTS PointCreateStaticStart = { 0 };//точка начала создания объекта статик
	POINTS PointCreateStaticEnd = { 0 };//точка окончания построения статика
	static POINTS Cursor = { 0 };//координаты курсора

	switch (msg)
	{
	case WM_INITDIALOG:
	{
		hCursor = LoadCursor(NULL, MAKEINTRESOURCE(IDC_ARROW));
		CheckBorders(hWnd);//определяем местоположение на рабочем столе приложения
	}
	return TRUE;


	case WM_LBUTTONDOWN://нажатие левой кнопки мыши
		PointCreateStaticStart = MAKEPOINTS(lParam);
		flagCreatStatic = true;
		return TRUE;

	case WM_SETCURSOR:
		GetTrashRect();//определяем дескриптор и параметры урны
		SetCursor(hCursor);//устанавливаем курсор
		ShowCursor(TRUE);//отображаем курсор
		CheckBorders(hWnd);//считываем системные параметры

		if (MoveStatic)//если статик перемещаем
		{
			switch (HIWORD(lParam))
			{
			case WM_LBUTTONUP://отжатие левой кнопки мыши
				Cursor = MAKEPOINTS(lParam);//считываем координаты курсора
				flagCursorTrash = CursorInStatic(Cursor, hStaticTrash, hWnd);//оределяем где находится курсор, если в пределах статика урны, флаг меняется на true
				if (flagOpenTrash)//если курсор находится над урной, закрываем урну и удаляем статик
				{
					hMyBitmapCloseTrash = (HBITMAP)LoadImage(GetModuleHandle(0), MAKEINTRESOURCE(IDB_BITMAP4), IMAGE_BITMAP, 0, 0, LR_COPYFROMRESOURCE);
					SendMessage(hStaticTrash, (UINT)STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hMyBitmapCloseTrash);
					flagOpenTrash = FALSE;//закрываем урну
					DestroyWindow(hStatic);//разрущаем статик
					InvalidateRect(hDlg, NULL, TRUE);
				}
				MoveStatic = false;
				break;
			}
		}
		return TRUE;

	case WM_MOUSEMOVE:
		Cursor = MAKEPOINTS(lParam);//считываем координаты курсора
		if (MoveStatic)
		{
			flagBorder = CheckPositionStatic(Cursor, hStatic, hWnd);
			if (flagBorder)
			{
				GetStaticRect(hStatic);//получаем параметры статика
				MoveWindow(hStatic, Cursor.x - WidthStatic / 2, Cursor.y - HeightStatic / 2, WidthStatic, HeightStatic, TRUE);//перемещаем статик
				ShowWindow(hStatic, SW_NORMAL);//отображаем статик
				flagCursorTrash = CursorInStatic(Cursor, hStaticTrash, hWnd);//определяем, находится ли статик в пределах урны
				if (flagCursorTrash)//пеняем урне картинку
				{
					hMyBitmapOpenTrash = (HBITMAP)LoadImage(GetModuleHandle(0), MAKEINTRESOURCE(IDB_BITMAP2), IMAGE_BITMAP, 0, 0, LR_COPYFROMRESOURCE);
					SendMessage(hStaticTrash, (UINT)STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hMyBitmapOpenTrash);
					flagOpenTrash = TRUE;
					InvalidateRect(hDlg, NULL, TRUE);
					ShowWindow(hStaticTrash, SW_NORMAL);
				}
				else
				{
					hMyBitmapCloseTrash = (HBITMAP)LoadImage(GetModuleHandle(0), MAKEINTRESOURCE(IDB_BITMAP4), IMAGE_BITMAP, 0, 0, LR_COPYFROMRESOURCE);
					SendMessage(hStaticTrash, (UINT)STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hMyBitmapCloseTrash);
					flagOpenTrash = FALSE;
					InvalidateRect(hDlg, NULL, TRUE);
					ShowWindow(hStaticTrash, SW_NORMAL);
				}
			}
		}
		return TRUE;

	case WM_LBUTTONUP:
		if (flagCreatStatic)//флаг создания статика
		{
			PointCreateStaticEnd = MAKEPOINTS(lParam);//вторая точка
			CeateMyStatic(PointCreateStaticStart, PointCreateStaticEnd);//создаём статик
			ShowWindow(hStatic, SW_NORMAL);//отображаем статик
			flagCreatStatic = false;//меняем флаг
		}
		return TRUE;

	case WM_CONTEXTMENU:
	{
		hStatic = (HWND)(wParam);
		if (hStatic != hStaticTrash && hStatic != hDlg)
		{
			DestroyWindow(hStatic);//разрущаем статик
			InvalidateRect(hDlg, NULL, TRUE);
			hStatic = NULL;
		}
	}
	return TRUE;

	case WM_COMMAND:
		switch (HIWORD(wParam))
		{
		case STN_CLICKED:
			hStatic = (HWND)lParam;
			GetStaticRect(hStatic);
			MoveStatic = true;
			break;
		}
		return TRUE;

	case WM_CLOSE:
		DestroyWindow(hWnd);
		PostQuitMessage(0);
		return TRUE;
	}
	return FALSE;
}
