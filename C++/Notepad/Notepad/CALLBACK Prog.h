#pragma once
#include "HeaderProject.h"

void SaveNotEmpty(HWND hWnd);//�������� ���� �� Edit

void PropositionSaveFile(HWND hWnd);//����������� ��������� ����

BOOL CALLBACK ProcChild(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);//������� ��������� ��������� ����������� ����

BOOL CALLBACK DlgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);//������� ��������� ������