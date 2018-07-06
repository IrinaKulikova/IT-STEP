#pragma once
#include "HeaderProject.h"


BOOL CALLBACK DlgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	static BOOL flagCursorStatic = false;//���� ������� ����� ������ ���� �� �������
	static BOOL flagOpenTrash = false;//���� �������� ����
	static BOOL flagCursorTrash = false;//���� ���������� ������� ���� � �������� ����
	static BOOL MoveStatic = false;//���� ����������� �������
	static BOOL flagCreatStatic = false;//���� �������� ������������ ����
	static BOOL flagBorder = false;//���� ������������ �������� � ����� ���������� ���� ���� ����������
	static HCURSOR hCursor = NULL;//���������� �������

	static POINTS PointCreateStaticStart = { 0 };//����� ������ �������� ������� ������
	POINTS PointCreateStaticEnd = { 0 };//����� ��������� ���������� �������
	static POINTS Cursor = { 0 };//���������� �������

	switch (msg)
	{
	case WM_INITDIALOG:
	{
		hCursor = LoadCursor(NULL, MAKEINTRESOURCE(IDC_ARROW));
		CheckBorders(hWnd);//���������� �������������� �� ������� ����� ����������
	}
	return TRUE;


	case WM_LBUTTONDOWN://������� ����� ������ ����
		PointCreateStaticStart = MAKEPOINTS(lParam);
		flagCreatStatic = true;
		return TRUE;

	case WM_SETCURSOR:
		GetTrashRect();//���������� ���������� � ��������� ����
		SetCursor(hCursor);//������������� ������
		ShowCursor(TRUE);//���������� ������
		CheckBorders(hWnd);//��������� ��������� ���������

		if (MoveStatic)//���� ������ ����������
		{
			switch (HIWORD(lParam))
			{
			case WM_LBUTTONUP://������� ����� ������ ����
				Cursor = MAKEPOINTS(lParam);//��������� ���������� �������
				flagCursorTrash = CursorInStatic(Cursor, hStaticTrash, hWnd);//��������� ��� ��������� ������, ���� � �������� ������� ����, ���� �������� �� true
				if (flagOpenTrash)//���� ������ ��������� ��� �����, ��������� ���� � ������� ������
				{
					hMyBitmapCloseTrash = (HBITMAP)LoadImage(GetModuleHandle(0), MAKEINTRESOURCE(IDB_BITMAP4), IMAGE_BITMAP, 0, 0, LR_COPYFROMRESOURCE);
					SendMessage(hStaticTrash, (UINT)STM_SETIMAGE, (WPARAM)IMAGE_BITMAP, (LPARAM)hMyBitmapCloseTrash);
					flagOpenTrash = FALSE;//��������� ����
					DestroyWindow(hStatic);//��������� ������
					InvalidateRect(hDlg, NULL, TRUE);
				}
				MoveStatic = false;
				break;
			}
		}
		return TRUE;

	case WM_MOUSEMOVE:
		Cursor = MAKEPOINTS(lParam);//��������� ���������� �������
		if (MoveStatic)
		{
			flagBorder = CheckPositionStatic(Cursor, hStatic, hWnd);
			if (flagBorder)
			{
				GetStaticRect(hStatic);//�������� ��������� �������
				MoveWindow(hStatic, Cursor.x - WidthStatic / 2, Cursor.y - HeightStatic / 2, WidthStatic, HeightStatic, TRUE);//���������� ������
				ShowWindow(hStatic, SW_NORMAL);//���������� ������
				flagCursorTrash = CursorInStatic(Cursor, hStaticTrash, hWnd);//����������, ��������� �� ������ � �������� ����
				if (flagCursorTrash)//������ ���� ��������
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
		if (flagCreatStatic)//���� �������� �������
		{
			PointCreateStaticEnd = MAKEPOINTS(lParam);//������ �����
			CeateMyStatic(PointCreateStaticStart, PointCreateStaticEnd);//������ ������
			ShowWindow(hStatic, SW_NORMAL);//���������� ������
			flagCreatStatic = false;//������ ����
		}
		return TRUE;

	case WM_CONTEXTMENU:
	{
		hStatic = (HWND)(wParam);
		if (hStatic != hStaticTrash && hStatic != hDlg)
		{
			DestroyWindow(hStatic);//��������� ������
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
