#pragma once
#include "HeaderProject.h"

void SaveNotEmpty(HWND hWnd);//проверка пуст ли Edit

void PropositionSaveFile(HWND hWnd);//предложение сохранить фаил

BOOL CALLBACK ProcChild(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);//функция обработки дочернего диалогового окна

BOOL CALLBACK DlgProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);//функция обратного вызова