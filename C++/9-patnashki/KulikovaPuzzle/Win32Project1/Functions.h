#pragma once
#include "stdafx.h"

VOID CreateVectorNumber();//создание вектора имён кнопок

VOID CreateButtons(HWND hWnd);//создание кнопок

VOID DelPuzzle();//удаление кнопок

VOID NewGame();//перемешивание, создание новой игры

VOID CreateGame(HWND hWnd, int level, int height, int width);//генерируем игру

VOID CheckToChangePuzzle(HWND hWnd, HWND ClickPuzzle);//можно ли менять местами кнопки

bool CheckPositions(int IndexFirst, int IndexSecond);

bool CheckWin();//проверка на победу