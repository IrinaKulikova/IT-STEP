#pragma once
#include "stdafx.h"

extern INT SizePuzzle;//размер поля
extern INT WidthPuzzle;//ширина поля
extern INT HeightPuzzle;//высота поля
extern std::vector<HWND> ButtonsHWND;//вектор кнопок
extern std::vector<std::wstring> Buttons;//вектор кнопок
extern HWND hDlg;//дескиптор окна
extern HWND EmptyPuzzle;//дескриптор пустой кнопки
extern int IndexEmptyPuzzle;//индекс пустой кнопки
//extern HWND ClickPuzzle;//дескриптор нажатой кнопки