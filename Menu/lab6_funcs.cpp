#include"lab6_funcs.h"

struct block {
	int x;
	int y;
};

void point(int x, int y) { // перемиститься на текущие координаты
	COORD position = { x*2,y }; //позиция x и y
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, position);
}

void SetColor(int pnColorBackground, int pnColorText) { // установить цвет фона и текста вывода
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)(((pnColorBackground & 0x000F) << 4) | (pnColorText & 0x000F)));
}

int log_2(uint a) { // логарифм числа типа "int"
	int k = 0;
	while (a != 1) {
		a /= 2;
		k++;
	}
	return k;
}


