#include "Header.h"

typedef enum enCording {
	CD_Cesar, //����������� ������� ������
	CD_Dinamic, //����� ������������� �����
	CD_Bit //����� ��������� �������� ������
}CODEMODEL;

void Cording();
void DinCording();
void BitCording(bool pvar = true);
void DeCording();