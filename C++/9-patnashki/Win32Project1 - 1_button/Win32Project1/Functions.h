#pragma once
#include "stdafx.h"

VOID CreateVectorNumber();//�������� ������� ��� ������

VOID CreateButtons(HWND hWnd);//�������� ������

VOID DelPuzzle();//�������� ������

VOID NewGame();//�������������, �������� ����� ����

VOID CreateGame(HWND hWnd, int level, int height, int width);//���������� ����

VOID CheckToChangePuzzle(HWND first, HWND second);//����� �� ������ ������� ������

bool CheckPositions(int IndexFirst, int IndexSecond);