#pragma once
#include "HeaderProject.h"

HWND hDlg = NULL;

int deltaLRB = 0;//толщина рамочки справа, слева и снизу
int deltaT = 0;//толщина рамочки сверху

int deltaInstanceL = 0;//расстояние приложения относительно левого края рабочего стола 
int deltaInstanсeT = 0;//расстояние приложения относительно верхнего края рабочего стола

HWND hStatic = NULL;//дескриптор статика
HWND hStaticTrash = NULL;//дескриптор урны

HBITMAP hMyBitmap = NULL;//дескриптор картинки закрытой урны
HBITMAP hMyBitmapOpenTrash = NULL;//дескриптор картинки открытой урны
HBITMAP hMyBitmapCloseTrash = NULL;//дескриптор картинки закрытой урны

int WidthStatic = 0;//ширина статика
int HeightStatic = 0;//высота статика

int WidthTrash = 0;//ширина статика урны
int HeightTrash = 0;//высота статика урны

RECT WindowInstance = { 0 };//размер окна приложения с рамочкой
RECT ClientInstance = { 0 };//размер клиентской области окна приложения
RECT CRect = { 0 };//струкнура размера статика
RECT RecTrash = { 0 };//область урны