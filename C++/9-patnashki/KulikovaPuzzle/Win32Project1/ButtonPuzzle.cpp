#include "stdafx.h"


ButtonPuzzle::ButtonPuzzle(int index, HWND handler)
{
	this->index - index;
	this->hPuzzle = handler;
}

int ButtonPuzzle::GetIndex()
{
	return index;
}

HWND ButtonPuzzle::GetHandler()
{
	return hPuzzle;
}


void ButtonPuzzle::SetIndex(int index)
{
	this->index = index;
}


void ButtonPuzzle::SetHandler(HWND handler)
{
	this->hPuzzle = handler;
}


ButtonPuzzle::~ButtonPuzzle()
{}
