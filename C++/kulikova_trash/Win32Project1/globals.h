#pragma once
#include <Windows.h>

extern HWND hDlg;//дескриптор диалогового окна

extern int deltaLRB;//толщина рамочки справа, слева и снизу
extern int deltaT;//толщина рамочки сверху

extern int deltaInstanceL;//расстояние приложения относительно левого края рабочего стола 
extern int deltaInstanceT;//расстояние приложения относительно верхнего края рабочего стола

extern HWND hStatic;//дескриптор создаваемого статика
extern HWND hStaticTrash;//дескриптор урны

extern HBITMAP hMyBitmap;//дескриптор картинки мусора
extern HBITMAP hMyBitmapOpenTrash;//дескриптор картинки открытой урны
extern HBITMAP hMyBitmapCloseTrash;//дескриптор картинки закрытой урны

extern int WidthStatic;//ширина статика мусор
extern int HeightStatic;//высота статика мусора

extern int WidthTrash;//ширина статика урны
extern int HeightTrash;//высота статика урны

extern RECT WindowInstance;//размер окна приложения с рамочкой
extern RECT ClientInstance;//размер клиентской области окна приложения
extern RECT CRect;//размер статика
extern RECT RecTrash;//область урны