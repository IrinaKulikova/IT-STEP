#pragma once
#pragma once
#include "HeaderProject.h"

void CheckBorders(HWND hWnd);//определяем размеры рамок у приложения

void GetTrashRect();//определяем дескриптрок урны

BOOL CursorInStatic(POINTS &Cursor, HWND StaticObject, HWND hWnd);//фукция возвращает тру, если курсор находится в области статика

BOOL CheckPositionStatic(POINTS &Cursor, HWND Static, HWND hWnd);//функция проверяет не вышел ли статик за клиентскую область

void GetStaticRect(HWND hWnd);//определяем размеры статика

VOID CeateMyStatic(POINTS &PointCreateStaticStart, POINTS &PointCreateStaticEnd);//функция создания статика

//BOOL CursorInTrash(POINTS &Cursor, HWND hWnd);//проверка, находится ли курсор в области урны