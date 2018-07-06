#pragma once
#include "HeaderProject.h"


void CheckBorders(HWND hWnd)//определяем размеры рамок у приложения
{
	GetWindowRect(hWnd, &WindowInstance);
	GetClientRect(hWnd, &ClientInstance);

	deltaLRB = ((WindowInstance.right - WindowInstance.left) - (ClientInstance.right - ClientInstance.left)) / 2;//толщена рамочки справа, слева и снизу
	deltaT = (WindowInstance.bottom - WindowInstance.top) - (ClientInstance.bottom - ClientInstance.top) - deltaLRB;//толшина рамочки сверху
}


void GetTrashRect()
{
	if (!hStaticTrash)//получаем параметры урны
	{
		hStaticTrash = GetDlgItem(hDlg, IDC_STATIC_TRASH);//дескриптор
		GetWindowRect(hStaticTrash, &RecTrash);//размер

		WidthTrash = RecTrash.right - RecTrash.left;//ширина
		HeightTrash = RecTrash.bottom - RecTrash.top;//высота
	}
}


BOOL CursorInStatic(POINTS &Cursor, HWND StaticObject, HWND hWnd)//фукция возвращает тру, если курсор находится в области статика
{
	GetWindowRect(hWnd, &WindowInstance);//определяем местоположение приложения
	
	RECT Object = { 0 };//пределяем размер объекта
	GetWindowRect(StaticObject, &Object);

	return Cursor.x + WindowInstance.left < Object.right - deltaLRB && Cursor.x + WindowInstance.left > Object.left - deltaLRB
		&& Cursor.y + WindowInstance.top > Object.top - deltaT  && Cursor.y + WindowInstance.top < Object.bottom - deltaT;
}

BOOL CheckPositionStatic(POINTS &Cursor, HWND StaticObject, HWND hWnd)//функция проверяет не вышел ли статик за клиентскую область
{
	GetWindowRect(hWnd, &WindowInstance);

	return Cursor.x - WidthStatic / 2 + WindowInstance.left > WindowInstance.left&& Cursor.x + WidthStatic / 2 + WindowInstance.left < WindowInstance.right - 2 * deltaLRB
		&& Cursor.y - HeightStatic / 2 + WindowInstance.top> WindowInstance.top && Cursor.y + HeightStatic / 2 + WindowInstance.top < WindowInstance.bottom - deltaLRB - deltaT;
}

void GetStaticRect(HWND hWnd)//определяем размеры статика
{
	CheckBorders(hWnd);
	GetWindowRect(hStatic, &CRect);

	WidthStatic = CRect.right - CRect.left;//ширина объекта
	HeightStatic = CRect.bottom - CRect.top;//высота объекта
}


VOID CeateMyStatic(POINTS &PointCreateStaticStart, POINTS &PointCreateStaticEnd)//функция создания статика
{
	int WidthStatic = PointCreateStaticEnd.x - PointCreateStaticStart.x;//ширина статика
	int HeightStatic = PointCreateStaticEnd.y - PointCreateStaticStart.y;//высота статика

	if (WidthStatic < 0 && HeightStatic>0)//ширина отрицательная, высота положительная
	{
		WidthStatic = (abs(WidthStatic) < MINSIZESTATIC) ? MINSIZESTATIC : abs(WidthStatic);
		HeightStatic = (HeightStatic < MINSIZESTATIC) ? MINSIZESTATIC : HeightStatic;
		PointCreateStaticStart.x -= WidthStatic;
	}
	else if (WidthStatic > 0 && HeightStatic < 0)//ширина положительная, высота отрицательная
	{
		WidthStatic = (WidthStatic < MINSIZESTATIC) ? MINSIZESTATIC : WidthStatic;
		HeightStatic = (abs(HeightStatic) < MINSIZESTATIC) ? MINSIZESTATIC : abs(HeightStatic);
		PointCreateStaticStart.y -= HeightStatic;
	}
	else if (WidthStatic < 0 && HeightStatic < 0)//ширина отрицательная, высота отрицательная
	{
		WidthStatic = (abs(WidthStatic) < MINSIZESTATIC) ? MINSIZESTATIC : abs(WidthStatic);
		PointCreateStaticStart.x -= WidthStatic;
		HeightStatic = (abs(HeightStatic) < MINSIZESTATIC) ? MINSIZESTATIC : abs(HeightStatic);
		PointCreateStaticStart.y -= HeightStatic;
	}

	hStatic = CreateWindow(TEXT("STATIC"), TEXT("MySt"), WS_CHILD | WS_BORDER | WS_VISIBLE | SS_NOTIFY | SS_BITMAP | SS_CENTERIMAGE,
		PointCreateStaticStart.x, PointCreateStaticStart.y, WidthStatic, HeightStatic, hDlg, NULL, GetModuleHandle(0), NULL);
	hMyBitmap = (HBITMAP)LoadImage(GetModuleHandle(0), MAKEINTRESOURCE(IDB_BITMAP1), IMAGE_BITMAP, WidthStatic, HeightStatic, LR_COPYFROMRESOURCE);
	SendMessage(hStatic, (UINT)STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hMyBitmap);
}