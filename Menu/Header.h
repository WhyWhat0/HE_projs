#include <conio.h>
#include <iostream>
#include <iomanip>
#include <cmath>
#include<windows.h>
#include <fstream>
#include<string>
#include <bitset>

#define uint unsigned int

using namespace std;



void lab2_1(); void lab2_2(); void lab3_1(); void lab3_2(); void lab4(); void lab5(); void lab6(); void lab7(); int menu1(); int menu2();

typedef enum {
	CL_BLACK,
	CL_BLUE,
	CL_GREEN,
	CL_CYAN,
	CL_RED,
	CL_PURPLE,
	CL_YELLOW,
	CL_WHITE,
	CL_LIGHT_BLACK,
	CL_LIGHT_BLUE,
	CL_LIGHT_GREEN,
	CL_LIGHT_CYAN,
	CL_LIGHT_RED,
	CL_LIGHT_PURPLE,
	CL_LIGHT_YELLOW,
	CL_LIGHT_WHITE,
	ר���� = 0,
	�����,
	��˨���,
	�������,
	�������,
	����������,
	ƨ����,
	�����,
	�����,
	������_�����,
	������_��˨���,
	������_�������,
	������_�������,
	������_����������,
	������_ƨ����,
	������_�����
} COLORS, �����;