#pragma once
#include "stdafx.h"


/*�������� ���� "��������"
� ���� ����� �������� ������� ��������� ����� radiobutton.
���� ��� ������ ��������� : 3�3, 4�4 � 5�5
�� ��������� ����� ������������ ������� 4�4

������ �� 10 ������ : 1) �� ���� ��������� � ��������� �������
������������� ������(� ����������� �� ������ ���������)
2) ����� ������ ��������� �������� � ��������� ������ ����
������� �������*/


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cCmdLine, int nShowOpt)//����� �����
{
	srand(time(0));
	hDlg = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc);//������ ���������� ���� � �������� ��� ����������
	MoveWindow(hDlg,NULL, NULL, MDLHEIGHT, MDLWIDTH, TRUE);

	ShowWindow(hDlg, nShowOpt);//���������� ����

	MSG msg;//������ ��������� ���������

	while (GetMessage(&msg, NULL, NULL, NULL))//���� ��������� ���������
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}