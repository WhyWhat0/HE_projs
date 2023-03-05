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

}bool edge(int x, int y, const int ex, const int ey) {
	if (x < 0 || x > ex - 1 || y < 0 || y > ey - 1) return true;
	return false;
}



