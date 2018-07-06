#pragma once
#include "stdafx.h"

class ButtonPuzzle//класс данных кнопки
{
private:
	int index;//индекс кнопки в векторе
	HWND hPuzzle;//дескриптор кнопки
public:
	ButtonPuzzle(int index, HWND handler);
	void SetIndex(int index);
	void SetHandler(HWND handler);
	int GetIndex();
	HWND GetHandler();
	virtual ~ButtonPuzzle();
};