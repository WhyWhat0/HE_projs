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
void check_wall(int &x, int &y, int map[], int c) {
	unsigned int Bit = 0b1000'0000'0000'0000'0000'0000'0000'0000;
	if ((Bit >> x / 2) & map[y]){
		Beep(400, 100);
		switch (c) {
		case 72:
		case 119:
			y += 1; break;
		case 115:
		case 80:
			y -= 1; break;
		case 97:
		case 75:
			x += 1; break;
		case 100:
		case 77:
			x -= 1; break;
		}
	}	
}
bool end(int x, int y, int ex, int ey) {
	if ((x == ex) and (y = ey)) {
		point(64, 14);
		SetColor(5, 15);
		system("cls");		
		cout << "Easy win!!!" << endl;
		system("pause");

		return true;
	}
	return false;
}
void SetColor(int pnColorBackground, int pnColorText) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)(((pnColorBackground & 0x000F) << 4) | (pnColorText & 0x000F)));
}