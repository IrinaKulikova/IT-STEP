#pragma once
#include "HeaderProject.h"


void FileSave(HWND hWnd)//�������� ���� ��� ���������� �����
{
	OPENFILENAME ofn = { 0 };

	ofn.lStructSize = sizeof(ofn);
	ofn.hInstance = GetModuleHandle(0);
	ofn.hwndOwner = hWnd;
	PathFile[0] = '\0';
	ofn.lpstrFile = PathFile; // ���� � ����� ���������� �������������
	ofn.nMaxFile = sizeof(PathFile) / sizeof(wchar_t); // ������ ������ ��� �������� ���� � ���������� �����												   
	ofn.lpstrFilter = L"��� �����(*.*)\0*.*\0��������� �����(*.txt)\0*.txt\0\0";// ������ ������
	ofn.nFilterIndex = 2;
	ofn.lpstrDefExt = TEXT("txt");
	ofn.Flags = 0;
	GetSaveFileName(&ofn);
}


void FileOpen(HWND hWnd)//������� ���� ��� ���������� �����
{
	OPENFILENAME ofn = { 0 };

	ofn.lStructSize = sizeof(ofn);
	ofn.hInstance = GetModuleHandle(0);
	ofn.hwndOwner = hWnd;
	PathFile[0] = '\0';
	ofn.lpstrFile = PathFile; // ���� � ����� ���������� �������������
	ofn.nMaxFile = sizeof(PathFile) / sizeof(wchar_t); // ������ ������ ��� �������� ���� � ���������� �����
	ofn.lpstrFilter = L"��� �����(*.*)\0*.*\0��������� �����(*.txt)\0*.txt\0\0";// ������ ������
	ofn.nFilterIndex = NUMBERFILTER;
	ofn.lpstrDefExt = TEXT("txt");
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
	GetOpenFileName(&ofn);
}

