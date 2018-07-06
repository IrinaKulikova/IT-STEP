#pragma once
#include "stdafx.h"

int SizePuzzle = 4;
INT WidthPuzzle = 500;//ширина поля
INT HeightPuzzle = 400;//высота поля
std::vector<HWND> ButtonsHWND;//вектор кнопок
std::vector<wstring>Buttons;//вектор текста кнопок
HWND hDlg = NULL;//дескиптор окна
HWND EmptyPuzzle=NULL;//дескриптор пустой кнопки
int IndexEmptyPuzzle = 0;//индекс пустой кнопки
HWND ClickPuzzle = NULL;//дескриптор нажатой кнопки