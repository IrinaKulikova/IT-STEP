#include "HeaderProject.h"
#pragma warning (disable:4996)

/*Создать текстовый редактор подобный стандартному редактору Блокнот.
В приложении должно присутствовать такое же меню, как и в Блокноте.
Реализовать пункты меню Файл->Создать, Файл->Открыть..., Файл->Сохранить,
Файл->Сохранить как... и Файл->Выйти.*/


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cCmdLine, int nShowOpt)//точка входа
{
	wcscpy(PathFile, TEXT(""));
	hDlg = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_DIALOG_NOTE), NULL, DlgProc);//создам диалоговое окно и получаем его дескриптор
	
	ShowWindow(hDlg, nShowOpt);//отображаем окно

	MSG msg;//создаём структура сообщения

	while (GetMessage(&msg, NULL, NULL, NULL))//цикл обработки сообщение
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}
