#pragma once
#pragma once
#include "HeaderProject.h"

void CheckBorders(HWND hWnd);//���������� ������� ����� � ����������

void GetTrashRect();//���������� ����������� ����

BOOL CursorInStatic(POINTS &Cursor, HWND StaticObject, HWND hWnd);//������ ���������� ���, ���� ������ ��������� � ������� �������

BOOL CheckPositionStatic(POINTS &Cursor, HWND Static, HWND hWnd);//������� ��������� �� ����� �� ������ �� ���������� �������

void GetStaticRect(HWND hWnd);//���������� ������� �������

VOID CeateMyStatic(POINTS &PointCreateStaticStart, POINTS &PointCreateStaticEnd);//������� �������� �������

//BOOL CursorInTrash(POINTS &Cursor, HWND hWnd);//��������, ��������� �� ������ � ������� ����