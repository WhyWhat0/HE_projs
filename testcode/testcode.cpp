#include <conio.h>
#include<stdio.h>
#include <iostream>
#include <iomanip>
#include <math.h>
#include<windows.h>
#include<tuple>
using namespace std;

void SetColor(int pnColorBackground, int pnColorText) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)(((pnColorBackground & 0x000F) << 4) | (pnColorText & 0x000F)));
}
void fun(int& a, int& b, int k) {
	a += 7;
	b /= 2;
	k *= 4;
}
int main()
{
	int c = 5, d = 8, f = 10;
	fun(c, d, f);
	cout << c << " " << d << " " << f;
    return 0;
}