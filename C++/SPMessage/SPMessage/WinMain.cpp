#include "HeaderProject.h"

/*������� ���������� �� ���� ���������� ����������� ����.
�������� ������ ������.
����������� ������� ����� �� ������� �� ���������� ��������� :
1. ��������� ���������� ���������(PostMessage) �������� ���� WM_QUIT
2. ��������� ����������� ���������(SendMessage) �������� ���� WM_QUIT
3. ��������� ���������� ��������� �������� ���� WM_DESTROY
4. ��������� ����������� ��������� �������� ���� WM_DESTROY

��������� ����������.� Spy++ ���������������� ��������� ������� ������������
��� ������� ������ ������.
������� ����� � ��������� ��������� ��� �������� ���������� � �����������
���������.*/

HWND hDlg = NULL;//����������� ����������� ����

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cCmdLine, int nShowOpt)//����� �����
{
	hDlg = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc);//������ ���������� ���� � �������� ��� ����������

	ShowWindow(hDlg, nShowOpt);//���������� ����

	MSG msg;//������ ��������� ���������

	while (GetMessage(&msg, NULL, NULL, NULL))//���� ��������� ���������
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}