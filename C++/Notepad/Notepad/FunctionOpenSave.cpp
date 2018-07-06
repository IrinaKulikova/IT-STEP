#pragma once
#include "HeaderProject.h"


void FileSave(HWND hWnd)//открытие окна для сохранения файла
{
	OPENFILENAME ofn = { 0 };

	ofn.lStructSize = sizeof(ofn);
	ofn.hInstance = GetModuleHandle(0);
	ofn.hwndOwner = hWnd;
	PathFile[0] = '\0';
	ofn.lpstrFile = PathFile; // путь к файлу выбранного пользователем
	ofn.nMaxFile = sizeof(PathFile) / sizeof(wchar_t); // размер буфера для хранения пути к выбранному файлу												   
	ofn.lpstrFilter = L"Все файлы(*.*)\0*.*\0Текстовые файлы(*.txt)\0*.txt\0\0";// фильтр файлов
	ofn.nFilterIndex = 2;
	ofn.lpstrDefExt = TEXT("txt");
	ofn.Flags = 0;
	GetSaveFileName(&ofn);
}


void FileOpen(HWND hWnd)//открыте окна для сохранения файла
{
	OPENFILENAME ofn = { 0 };

	ofn.lStructSize = sizeof(ofn);
	ofn.hInstance = GetModuleHandle(0);
	ofn.hwndOwner = hWnd;
	PathFile[0] = '\0';
	ofn.lpstrFile = PathFile; // путь к файлу выбранного пользователем
	ofn.nMaxFile = sizeof(PathFile) / sizeof(wchar_t); // размер буфера для хранения пути к выбранному файлу
	ofn.lpstrFilter = L"Все файлы(*.*)\0*.*\0Текстовые файлы(*.txt)\0*.txt\0\0";// фильтр файлов
	ofn.nFilterIndex = NUMBERFILTER;
	ofn.lpstrDefExt = TEXT("txt");
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
	GetOpenFileName(&ofn);
}

