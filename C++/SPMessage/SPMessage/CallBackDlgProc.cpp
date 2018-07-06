#pragma once
#include "HeaderProject.h"


BOOL CALLBACK DlgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	std::wstring Result = TEXT("ѕри отправки сообщени€ через диспечер обработки сообщений Windows, событие гарантировано будет обработано корректно (что можно наблюдать при начатии кнопки PostMessage WM_QUIT). ѕри отправки асинхронного сообщени€(SendMessage WM_QUIT) событие возможно будет обработано не корректно, так как не генерируютс€ дополнительные событи€ в диспечере обработки сообщений операционной системы! ѕри отправки сообщени€ о закрытие диалогового окна(WM_CLOSE), мы наблюдает что событие корректно обрабатываетс€ дл€ любого типа сообщени€(SendMessage и PostMessage)");
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