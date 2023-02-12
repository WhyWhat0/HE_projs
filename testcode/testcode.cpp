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
int f(int x, int y, int map[]) {
	return x * y * map[2];
}
int main () {
	unsigned int Bit = 0b0000'0000'0000'0000'0000'0000'0000'0010;
	int map[] = { 1,2,3,4,5 };
	cout << f(1, 2, map);
	return 0;
}