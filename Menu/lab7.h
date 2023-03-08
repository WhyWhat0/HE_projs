#pragma once
#include "Header.h"

typedef struct _stRecItem{
	int IdSet; // ������ ������ ������
	double value1, //�������� 1
		value2; // �������� 2

	_stRecItem() : IdSet(0), value1(0), value2(0) {}
	_stRecItem(int pID, double pValue1, double pValue2) : IdSet(pID), value1(pValue1), value2(pValue2) {}

}stRecItem, *pstRecItem;

typedef struct _stRecursion {
	int count;	//��������� ��������� �������� � ������ ������
	pstRecItem setRec; // ������ ��������

	_stRecursion(): count(0), setRec(NULL){}
	_stRecursion(int pCount) { setRec = new stRecItem[count]; }

	int AddItem(int pID, double pValue1, double pValue2) { //�������� � ����� ����� ����� ������
		count++;
		setRec = (pstRecItem)realloc(setRec, sizeof(stRecItem) * count); //������� ����� ����� ������

		setRec[count - 1].IdSet = pID;
		setRec[count - 1].value1 = pValue1;
		setRec[count - 1].value1 = pValue2;
		return count;
	}
}stRecursion, * pstRecursion;