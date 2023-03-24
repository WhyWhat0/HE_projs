#pragma once
#include "Header.h"

typedef enum  enModel{
	mod_n_An_Y,   //данные n - номер метки, An - член ряда, Y - текущая сумма
	mod_n_An,
	mod_n_Y,
	mod_An_Y,
	mod_X,
	mod_Y,
	mod_X_Y = mod_An_Y
}MODEL, * PMODEL;

typedef struct _stRecItem{
	int IdSet; // индекс набора данных
	double value1, //значение 1
		value2; // значение 2

	_stRecItem() : IdSet(0), value1(0), value2(0) {}
	_stRecItem(int pID, double pValue1, double pValue2) : IdSet(pID), value1(pValue1), value2(pValue2) {}

}stRecItem, *pstRecItem;

typedef struct _stRecursion {
	int count;	//количесво элементов структур в наборе данных
	pstRecItem setRec; // массив структур
	enModel model = mod_n_An_Y; //модель данных
	_stRecursion(): count(0), setRec(NULL){}
	_stRecursion(int pCount) { setRec = new stRecItem[count]; }
	~_stRecursion() { delete[] setRec; }

	int AddItem(int pID, double pValue1, double pValue2) { //добавить в конец новый набор данных
		count++;
		setRec = (pstRecItem)realloc(setRec, sizeof(stRecItem) * count); //создать новый набор данных

		setRec[count - 1].IdSet = pID;
		setRec[count - 1].value1 = pValue1;
		setRec[count - 1].value2 = pValue2;
		return count;
	}
	void Clear() {
		count = 0;
		if (setRec != NULL) { free(setRec); setRec = NULL; }
	}

	double X(int pIndex) {
		if (count == 0 || pIndex >= count) return 0;

		switch (model) {
			case mod_An_Y: {
				return setRec[pIndex].value1;
			}break;

			default: {
				return setRec[pIndex].IdSet;
			}
		}
		return 0;
	}

	pair <double, double> Y(int pIndex) {
		if (count == 0 || pIndex >= count) return pair<double,double>(0,0);

		switch (model) {
		case mod_n_An_Y: {
			return pair<double, double> (setRec[pIndex].value1, setRec[pIndex].value2);
		} break;  //данные n - номер метки, An - член ряда, Y - текущая сумма
		case mod_n_An: break;
		case mod_n_Y: break;
		case mod_An_Y: break;
			
		}
			return 0;
	}

	int SetCount(int pCount) {
		Clear();
		count = pCount;
		setRec = new stRecItem[pCount];
		return count;
	}

}stRecursion, *pstRecursion;

typedef struct stRect {
	uint Left,
		Top,
		Width,
		Height;
	stRect() : Left(0), Top(0), Width(0), Height(0) {}
	stRect(uint pLeft, uint pTop) : Width(0), Height(0), Left(pLeft), Top(pTop) {}
	stRect(uint pLeft, uint pTop, uint pWidth, uint pHeight) :
		Left(pLeft), Top(pTop), Width(pWidth), Height(pHeight) {}
	uint Bottom() { return Top + Height; }
	uint Right() { return Left + Width; }

}stRECT, *pstRECT;
void lab7(bool pause = true);
void lab7_graf();
void DrawGraf(stRect prect, stRecursion& pRecData);

void DrawAxisX(HDC phdc, stRect pInRect, int psec, char* ptext = NULL); 
void DrawAxisY(HDC phdc, stRect pInRect, int psec, char* ptext = NULL);