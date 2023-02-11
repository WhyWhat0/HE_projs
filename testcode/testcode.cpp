#include <conio.h>
#include<stdio.h>
#include <iostream>
#include <iomanip>
#include <math.h>
#include<windows.h>

using namespace std;

void move(int x, int y) {
	COORD position = { x,y }; //позиция x и y
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, position);
}
int main () {

	char key;
	const int UP = 72;
	do {
		key = _getch();
		switch (key) {
		case 72:
		case 119:
			cout << "000"; break;
		case 80:
		case 115:
			cout << "111"; break;
		case 75:
		case 97:
			cout << "222"; break;
		case 77:
		case 100:
			cout << "333"; break;
		default:
			Beep(400, 50); break;
		}
		cout << endl;
	} while (key != 27);
}