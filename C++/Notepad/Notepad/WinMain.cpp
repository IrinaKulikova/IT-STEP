#include "HeaderProject.h"
#pragma warning (disable:4996)

/*������� ��������� �������� �������� ������������ ��������� �������.
� ���������� ������ �������������� ����� �� ����, ��� � � ��������.
����������� ������ ���� ����->�������, ����->�������..., ����->���������,
����->��������� ���... � ����->�����.*/


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR cCmdLine, int nShowOpt)//����� �����
{
	wcscpy(PathFile, TEXT(""));
	hDlg = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_DIALOG_NOTE), NULL, DlgProc);//������ ���������� ���� � �������� ��� ����������
	
	ShowWindow(hDlg, nShowOpt);//���������� ����

	MSG msg;//������ ��������� ���������

	while (GetMessage(&msg, NULL, NULL, NULL))//���� ��������� ���������
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}
