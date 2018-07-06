#pragma once
#include "stdafx.h"

class ButtonPuzzle//����� ������ ������
{
private:
	int index;//������ ������ � �������
	HWND hPuzzle;//���������� ������
public:
	ButtonPuzzle(int index, HWND handler);
	void SetIndex(int index);
	void SetHandler(HWND handler);
	int GetIndex();
	HWND GetHandler();
	virtual ~ButtonPuzzle();
};