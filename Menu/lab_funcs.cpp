#include"lab_fucs.h"


void point(int x, int y) { // ������������� �� ������� ����������
	COORD position = { x * 2,y }; //������� x � y
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, position);
}

void SetColor(int pnColorBackground, int pnColorText) { // ���������� ���� ���� � ������ ������
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)(((pnColorBackground & 0x000F) << 4) | (pnColorText & 0x000F)));
}



