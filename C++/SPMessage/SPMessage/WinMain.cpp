#include "HeaderProject.h"

/*Создать приложение на базе модального диалогового окна.
Добавить четыре кнопки.
Реализовать события клика по кнопкам по следующему алгоритму :
1. Отрпавить синхронное сообщение(PostMessage) текущему окну WM_QUIT
2. Отрпавить асинхронное сообщение(SendMessage) текущему окну WM_QUIT
3. Отрпавить синхронное сообщение текущему окну WM_DESTROY
4. Отрпавить асинхронное сообщение текущему окну WM_DESTROY

Запустить приложение.В Spy++ проанализировать сообщения которые генерируются
при нажатии каждой кнопки.
Сделать вывод о поведении программы при отрпавке синхронных и асинхронных
сообщений.*/

HWND hDlg = NULL;//дескрипторр диалогового окна

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cCmdLine, int nShowOpt)//точка входа
{
	hDlg = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc);//создам диалоговое окно и получаем его дескриптор

	ShowWindow(hDlg, nShowOpt);//отображаем окно

	MSG msg;//создаём структура сообщения

	while (GetMessage(&msg, NULL, NULL, NULL))//цикл обработки сообщение
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}