#pragma once
#include "HeaderProject.h"


BOOL CALLBACK ProcChild(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch (msg)
	{
	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
		case IDC_YES_MY://������������ ������� ��, ��������� �����
			FlagSave = true;
			EndDialog(hWnd, 0);//��������� ����
			break;
		case IDC_NO_MY://������������ ������� ���, �� ��������� �����
			FlagSave = false;
			EndDialog(hWnd, 0);//��������� ����
			break;
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


BOOL CALLBACK DlgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)//������� ��������� ��������� �������� ����������� ����
{
	switch (msg)
	{
	case WM_INITDIALOG:
	{
		HMENU hMenu = LoadMenu(GetModuleHandle(0), MAKEINTRESOURCE(IDR_MENU_NOTE));//�������� ���������� ����
		SetMenu(hWnd, hMenu);//������������� ����
	}
	return TRUE;

	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
		case ID_FILE_NEWFILE:
			SaveNotEmpty(hWnd);//���������� ������, ���� ���� EDIT �� ������
			break;

		case ID_FILE_OPEN:
			SaveNotEmpty(hWnd);//���������� ������, ���� ���� EDIT �� ������
			FileOpen(hWnd);//�������� ���� �������� �����
			ReadData(hWnd);//��������� � ����� ������
			break;

		case ID_FILE_SAVE:
			if (PathFile[0] == '\0')//���� ���� ��� �� ��������, ����������� ����
			{
				FileSave(hWnd);
			}
			WriteData(hWnd);//���������� � ���� �����
			break;

		case ID_FILE_SAVEAS:
			FileSave(hWnd);//��������� ���� ���������� �����
			WriteData(hWnd);//���������� ������ � ����
			break;

		case ID_FILE_EXIT:
			SendMessage(hWnd, WM_CLOSE, NULL, NULL);//���������� ��������� ������� ����
			break;
		}
	}
	return TRUE;

	case WM_CLOSE:
		PropositionSaveFile(hWnd);//���������� ������������ ��������� �����
		DestroyWindow(hWnd);
		PostQuitMessage(0);
		return TRUE;
	}

	return FALSE;
}

void PropositionSaveFile(HWND hWnd)
{
	DialogBox(GetModuleHandle(0), MAKEINTRESOURCE(IDD_DIALOG_SAVE), hWnd, ProcChild);
	if (FlagSave)
	{
		if (PathFile[0] == TEXT('\0'))//���� ���� ��� �� ��������, ����������� ����
		{
			FileSave(hDlg);
		}
		WriteData(hDlg);//��������� ������
	}
	PathFile[0] = TEXT('\0');//������� ����
}

void SaveNotEmpty(HWND hWnd)//���������� �����, ���� �� �� ������
{
	wchar_t buff[SIZESTRING];
	int	nLen = SendDlgItemMessage(hWnd, IDC_EDIT_TEXT, EM_LINELENGTH, 0, NULL);
	Edit_GetLine(GetDlgItem(hWnd, IDC_EDIT_TEXT), 0, buff, nLen);//��������� ������ � �����
	buff[nLen] = TEXT('\0');//���������� ����� ������
	if (!(buff[0] == TEXT('\0')))
	{
		PropositionSaveFile(hWnd);
		SetDlgItemText(hWnd, IDC_EDIT_TEXT, TEXT(""));
	}
}