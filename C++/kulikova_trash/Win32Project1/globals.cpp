#pragma once
#include "HeaderProject.h"

HWND hDlg = NULL;

int deltaLRB = 0;//������� ������� ������, ����� � �����
int deltaT = 0;//������� ������� ������

int deltaInstanceL = 0;//���������� ���������� ������������ ������ ���� �������� ����� 
int deltaInstan�eT = 0;//���������� ���������� ������������ �������� ���� �������� �����

HWND hStatic = NULL;//���������� �������
HWND hStaticTrash = NULL;//���������� ����

HBITMAP hMyBitmap = NULL;//���������� �������� �������� ����
HBITMAP hMyBitmapOpenTrash = NULL;//���������� �������� �������� ����
HBITMAP hMyBitmapCloseTrash = NULL;//���������� �������� �������� ����

int WidthStatic = 0;//������ �������
int HeightStatic = 0;//������ �������

int WidthTrash = 0;//������ ������� ����
int HeightTrash = 0;//������ ������� ����

RECT WindowInstance = { 0 };//������ ���� ���������� � ��������
RECT ClientInstance = { 0 };//������ ���������� ������� ���� ����������
RECT CRect = { 0 };//��������� ������� �������
RECT RecTrash = { 0 };//������� ����