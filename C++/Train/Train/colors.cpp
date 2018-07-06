#include "stdafx.h"

ostream &grey(ostream &stream)
{
	HANDLE hConsole = hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 8);
	return stream;
}

ostream &green(ostream &stream)
{
	HANDLE hConsole = hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 10);
	return stream;
}

ostream &red(ostream &stream)
{
	HANDLE hConsole = hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 12);
	return stream;
}

ostream &white(ostream &stream)
{
	HANDLE hConsole = hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 15);
	return stream;
}

ostream &pink(ostream &stream)
{
	HANDLE hConsole = hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 13);
	return stream;
}

ostream &yellow(ostream &stream)
{
	HANDLE hConsole = hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 14);
	return stream;
}

ostream &blue(ostream &stream)
{
	HANDLE hConsole = hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 9);
	return stream;
}

ostream &cyan(ostream &stream)
{
	HANDLE hConsole = hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, 11);
	return stream;
}