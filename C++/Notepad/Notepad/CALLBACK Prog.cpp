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
		case IDC_YES_MY://пользователь ответил да, сохраняем текст
			FlagSave = true;
			EndDialog(hWnd, 0);//закрываем окно
			break;
		case IDC_NO_MY://пользователь ответил нет, не сохраняем текст
			FlagSave = false;
			EndDialog(hWnd, 0);//закрываем окно
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


BOOL CALLBACK DlgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)//функция обработки сообщений гнавного диалогового окна
{
	switch (msg)
	{
	case WM_INITDIALOG:
	{
		HMENU hMenu = LoadMenu(GetModuleHandle(0), MAKEINTRESOURCE(IDR_MENU_NOTE));//получаем дескриптор меню
		SetMenu(hWnd, hMenu);//устанавливаем меню
	}
	return TRUE;

	case WM_COMMAND:
	{
		switch (LOWORD(wParam))
		{
		case ID_FILE_NEWFILE:
			SaveNotEmpty(hWnd);//сохранение данных, если поле EDIT не пустое
			break;

		case ID_FILE_OPEN:
			SaveNotEmpty(hWnd);//сохранение данных, если поле EDIT не пустое
			FileOpen(hWnd);//окрываем окно открытия файла
			ReadData(hWnd);//считываем с файла данные
			break;

		case ID_FILE_SAVE:
			if (PathFile[0] == '\0')//если путь ещё не известен, запрашиваем путь
			{
				FileSave(hWnd);
			}
			WriteData(hWnd);//записываем в фаил данне
			break;

		case ID_FILE_SAVEAS:
			FileSave(hWnd);//открываем окно сохранения файла
			WriteData(hWnd);//записываем данные в фаил
			break;

		case ID_FILE_EXIT:
			SendMessage(hWnd, WM_CLOSE, NULL, NULL);//отправляем сообщение закрыть окно
			break;
		}
	}
	return TRUE;

	case WM_CLOSE:
		PropositionSaveFile(hWnd);//предлагаем пользователю сохранить данне
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
		if (PathFile[0] == TEXT('\0'))//если путь ещё не известен, запрашиваем путь
		{
			FileSave(hDlg);
		}
		WriteData(hDlg);//сохраняем данные
	}
	PathFile[0] = TEXT('\0');//стираем путь
}

void SaveNotEmpty(HWND hWnd)//сохранение файла, если он не пустой
{
	wchar_t buff[SIZESTRING];
	int	nLen = SendDlgItemMessage(hWnd, IDC_EDIT_TEXT, EM_LINELENGTH, 0, NULL);
	Edit_GetLine(GetDlgItem(hWnd, IDC_EDIT_TEXT), 0, buff, nLen);//считываем строку в буфер
	buff[nLen] = TEXT('\0');//обозначаем конец строки
	if (!(buff[0] == TEXT('\0')))
	{
		PropositionSaveFile(hWnd);
		SetDlgItemText(hWnd, IDC_EDIT_TEXT, TEXT(""));
	}
}