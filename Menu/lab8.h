#include "Header.h"

typedef enum enCording {
	CD_Cesar, //кодирование методом ÷езар€
	CD_Dinamic, //метод динамического ключа
	CD_Bit //метод бинарного смещени€ текста
}CODEMODEL;

void Cording();
void DinCording();
void BitCording(bool pvar = true);
void DeCording();