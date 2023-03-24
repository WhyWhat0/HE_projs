#include"Header.h"


void point(int x, int y) { // перемиститься на текущие координаты
	COORD position = { x * 2,y }; //позиция x и y
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, position);
}

void SetColor(int pnColorBackground, int pnColorText) { // установить цвет фона и текста вывода
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



	/*Получить количество ячеек в текущем буфере */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X * csbi.dwSize.Y;



	/*Заполните весь буфер пробелами*/
	if (!FillConsoleOutputCharacterA(hStdOut, ' ', cellCount, homeCoords, &count)) return;



	/* Заполните весь буфер текущими цветами и атрибутами */
	if (!FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, cellCount, homeCoords, &count)) return;



	/* Переместите курсор домой */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}

