#pragma once
#include "stdafx.h"


/*Ќаписать игру "ѕ€тнашки"
¬ игре можно задавать уровень сложности через radiobutton.
≈сть три уровн€ сложности : 3х3, 4х4 и 5х5
ѕо умолчанию стоит классический вариант 4х4

ќценка до 10 баллов : 1) на поле наход€тс€ в случайном пор€дке
расположенные кнопки(в зависимости от уровн€ сложности)
2) смена уровн€ сложности приводит к по€влению нового пол€
нужного размера*/


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cCmdLine, int nShowOpt)//точка входа
{
	srand(time(0));
	hDlg = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc);//создам диалоговое окно и получаем его дескриптор
	MoveWindow(hDlg,NULL, NULL, MDLHEIGHT, MDLWIDTH, TRUE);

	ShowWindow(hDlg, nShowOpt);//отображаем окно

	MSG msg;//создаЄм структура сообщени€

	while (GetMessage(&msg, NULL, NULL, NULL))//цикл обработки сообщение
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}