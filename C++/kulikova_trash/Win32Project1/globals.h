#pragma once
#include <Windows.h>

extern HWND hDlg;//���������� ����������� ����

extern int deltaLRB;//������� ������� ������, ����� � �����
extern int deltaT;//������� ������� ������

extern int deltaInstanceL;//���������� ���������� ������������ ������ ���� �������� ����� 
extern int deltaInstanceT;//���������� ���������� ������������ �������� ���� �������� �����

extern HWND hStatic;//���������� ������������ �������
extern HWND hStaticTrash;//���������� ����

extern HBITMAP hMyBitmap;//���������� �������� ������
extern HBITMAP hMyBitmapOpenTrash;//���������� �������� �������� ����
extern HBITMAP hMyBitmapCloseTrash;//���������� �������� �������� ����

extern int WidthStatic;//������ ������� �����
extern int HeightStatic;//������ ������� ������

extern int WidthTrash;//������ ������� ����
extern int HeightTrash;//������ ������� ����

extern RECT WindowInstance;//������ ���� ���������� � ��������
extern RECT ClientInstance;//������ ���������� ������� ���� ����������
extern RECT CRect;//������ �������
extern RECT RecTrash;//������� ����