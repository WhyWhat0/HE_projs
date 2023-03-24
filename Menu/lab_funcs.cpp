#include"Header.h"


void point(int x, int y) { // ������������� �� ������� ����������
	COORD position = { x * 2,y }; //������� x � y
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, position);
}

void SetColor(int pnColorBackground, int pnColorText) { // ���������� ���� ���� � ������ ������
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)(((pnColorBackground & 0x000F) << 4) | (pnColorText & 0x000F)));
}

void ClearScreen()
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };



	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;



	SetConsoleCursorPosition(hStdOut, homeCoords);



	/*�������� ���������� ����� � ������� ������ */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X * csbi.dwSize.Y;



	/*��������� ���� ����� ���������*/
	if (!FillConsoleOutputCharacterA(hStdOut, ' ', cellCount, homeCoords, &count)) return;



	/* ��������� ���� ����� �������� ������� � ���������� */
	if (!FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, cellCount, homeCoords, &count)) return;



	/* ����������� ������ ����� */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}

