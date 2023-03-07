#include"lab6_funcs.h"

struct block {
	int x;
	int y;
};

void point(int x, int y) {
	COORD position = { x*2,y }; //позиция x и y
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, position);
}

void SetColor(int pnColorBackground, int pnColorText) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)(((pnColorBackground & 0x000F) << 4) | (pnColorText & 0x000F)));
}

void move(int x, int y) {
	SetColor(0, 15);
	cout << "  "; point(x, y);
	SetColor(9, 9);
	cout << "@@"; point(x, y);
}

int log_2(uint a) {
	int k = 0;
	while (a != 1) {
		a /= 2;
		k++;
	}
	return k;
}


