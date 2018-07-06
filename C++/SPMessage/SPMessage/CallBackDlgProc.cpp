#pragma once
#include "HeaderProject.h"


BOOL CALLBACK DlgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	std::wstring Result = TEXT("��� �������� ��������� ����� �������� ��������� ��������� Windows, ������� ������������� ����� ���������� ��������� (��� ����� ��������� ��� ������� ������ PostMessage WM_QUIT). ��� �������� ������������ ���������(SendMessage WM_QUIT) ������� �������� ����� ���������� �� ���������, ��� ��� �� ������������ �������������� ������� � ��������� ��������� ��������� ������������ �������! ��� �������� ��������� � �������� ����������� ����(WM_CLOSE), �� ��������� ��� ������� ��������� �������������� ��� ������ ���� ���������(SendMessage � PostMessage)");
	switch (msg)
	{
	case WM_INITDIALOG:
	{
		HWND hStatic = GetDlgItem(hWnd, IDC_MY_STATIC);
		SetWindowText(hStatic, Result.data());
	}
	return TRUE;
	case WM_COMMAND:
	{
		int wmId = LOWORD(wParam);
		switch (wmId)
		{
		case IDC_PM_WM_QUIT:
			PostMessage(hWnd, WM_QUIT, (WPARAM)wParam, (LPARAM)lParam);
			return TRUE;
		case IDC_SM_WM_QUIT:
			SendMessage(hWnd, WM_QUIT, (WPARAM)wParam, (LPARAM)lParam);
			return TRUE;
		case IDC_PM_WM_CLOSE:
			PostMessage(hWnd, WM_CLOSE, (WPARAM)wParam, (LPARAM)lParam);
			return TRUE;
		case IDC_SM_WM_CLOSE:
			SendMessage(hWnd, WM_CLOSE, (WPARAM)wParam, (LPARAM)lParam);
			return TRUE;
		}
	}
	case WM_CLOSE:
		DestroyWindow(hWnd);
		PostQuitMessage(0);
		return TRUE;
	}
	return FALSE;
}