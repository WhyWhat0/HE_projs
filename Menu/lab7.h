#pragma once
#include "Header.h"

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

	_stRecursion(): count(0), setRec(NULL){}
	_stRecursion(int pCount) { setRec = new stRecItem[count]; }

	int AddItem(int pID, double pValue1, double pValue2) { //добавить в конец новый набор данных
		count++;
		setRec = (pstRecItem)realloc(setRec, sizeof(stRecItem) * count); //создать новый набор данных

		setRec[count - 1].IdSet = pID;
		setRec[count - 1].value1 = pValue1;
		setRec[count - 1].value1 = pValue2;
		return count;
	}
}stRecursion, * pstRecursion;