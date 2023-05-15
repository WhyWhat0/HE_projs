#include"lab_fucs.h"


void point(int x, int y) { // перемиститьс€ на текущие координаты
	COORD position = { x * 2,y }; //позици€ x и y
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, position);
}

void SetColor(int pnColorBackground, int pnColorText) { // установить цвет фона и текста вывода
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)(((pnColorBackground & 0x000F) << 4) | (pnColorText & 0x000F)));
}

double mPow(double x, double l) {
	if (l>=1) for (int i = 1; i < l;i++) {
		x = x * x;
	}
	return x;
}
void ClearScreen() {

	HANDLE hStdOut;

	CONSOLE_SCREEN_BUFFER_INFO csbi;

	DWORD count;

	DWORD cellCount;

	COORD homeCoords = { 0,0 };



	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	if (hStdOut == INVALID_HANDLE_VALUE) return;



	SetConsoleCursorPosition(hStdOut, homeCoords);



	// получить количество €чеек в текущем буфекре 

	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;

	cellCount = csbi.dwSize.X * csbi.dwSize.Y;



	//заполн€ем весь буфер пробелами

	if (!FillConsoleOutputCharacterA(hStdOut, ' ', cellCount, homeCoords, &count)) return;



	//заполн€ем весь буфер текущими цветами и атрибутами 

	if (!FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, cellCount, homeCoords, &count)) return;



	//перемещаем курсор бек ту зе хоум

	SetConsoleCursorPosition(hStdOut, homeCoords);

}


