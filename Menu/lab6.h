#include "Header.h"

void point(int x, int y); void move(int x, int y); 
void SetColor(int pnColorBackground, int pnColorText);
int find_way(int nx, int ny); 
int find_short_way(int nx, int ny, int pway = 0);
int log_2(uint a);
void paint();
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