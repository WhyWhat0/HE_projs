#include"lab6_funcs.h"


void point(int x, int y) {
	COORD position = { x,y }; //позиция x и y
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, position);
}

void move(int x, int y) {
	SetColor(0, 15);
	cout << " "; point(x, y);
	SetColor(9, 9);
	cout << "@"; point(x, y);
}
bool wall(int x, int y, int map[]) {
	unsigned int Bit = 0b1000'0000'0000'0000'0000'0000'0000'0000;
	if ((Bit >> x/2) & map[y]) {
		Beep(400, 100);
		return true;
	}
	return false;
}
bool end(int x, int y, int ex, int ey) {
	if ((x == ex) and (y = ey)) {
		system("cls");
		cout << "Easy win!!!";
		return true;
	}
	return false;
}

void SetColor(int pnColorBackground, int pnColorText) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)(((pnColorBackground & 0x000F) << 4) | (pnColorText & 0x000F)));
}