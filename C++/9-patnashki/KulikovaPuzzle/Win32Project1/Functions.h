#pragma once
#include "stdafx.h"

VOID CreateVectorNumber();//�������� ������� ��� ������

VOID CreateButtons(HWND hWnd);//�������� ������

VOID DelPuzzle();//�������� ������

VOID NewGame();//�������������, �������� ����� ����

VOID CreateGame(HWND hWnd, int level, int height, int width);//���������� ����

VOID CheckToChangePuzzle(HWND hWnd, HWND ClickPuzzle);//����� �� ������ ������� ������

bool CheckPositions(int IndexFirst, int IndexSecond);

bool CheckWin();//�������� �� ������