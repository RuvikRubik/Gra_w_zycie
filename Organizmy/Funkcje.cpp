#include"Funkcje.h"

void gotoxy(int x, int y)
{
	COORD c;
	c.X = x - 1;
	c.Y = y - 1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

bool porownywanie2(int i1, int i2) {
	return (i1 > i2);
}

