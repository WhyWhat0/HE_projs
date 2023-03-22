#include "lab7.h"

stRecursion RecData;

void RecMenu() {
	uchar i = 0;
	do {
		system("cls");

		cout << "���� ��������\n\n";
		cout << "1) �������� � ��������\n\n";
		cout << "2) �������� � ��������\n\n";
		cout << "0) �����\n\n";

		i = _getch();
		switch (i) {
		case '1': lab7(); break;
		case '2': lab7_graf(); break;
		case '0': return;
		default:
			system("cls");
			cout << "��������� ����. ������� ����� ������ ��� �����������...";
			_getch();
		}
		
	} while (i != 27);
}

long double NextRec(double x, long double n,long double An, long double nSum) {
	An = pow(n, 3) - pow(An, 2) / pow(n, 2);	
	nSum = nSum + An;
	RecData.setRec[(int)n-1].IdSet = (int)n;
	RecData.setRec[(int)n-1].value1 = An;
	RecData.setRec[(int)n-1].value2 = nSum;

	/*(RecData.setRec + n)->IdSet = n;
	(*(RecData.setRec + n)).IdSet = n;*/

	if (n < 10) return NextRec(x, n + 1, An, nSum);
	return nSum;
}



void lab7(bool pause) {
	cout << "������ ������������� ����������� �����������������\n";
	cout << "\t�� 20 ������� � ����������� �������������\n\n";

	double x = 1;
	cout << "��������� �������� x = 1";
	RecData.SetCount(10);
	RecData.setRec[0].IdSet = 1;
	RecData.setRec[0].value1 = x;
	RecData.setRec[0].value2 = 0;
	long double y = NextRec(x, 2, x, 0);
	printf("\n������� �������� �������� y=%f,\t��� x=%4f\n\n", y, x);
	cout << "N��\t  ���� ����\t ����������� ���������\n";
	for (int i = 0; i < RecData.count;i++) {
		cout << setw(4) << RecData.setRec[i].IdSet << setw(20) << RecData.setRec[i].value1
			<< setw(20) << RecData.setRec[i].value2 << endl;
	}
	cout << endl;
	if (pause) system("pause");
}

void lab7_graf() {
	RecData.Clear();
	lab7(false);

	stRECT Rect(0, 600, 800, 300);
	cout << "������\n\n";
	DrawGraf(Rect, RecData);
	_getch();
}

void DrawGraf(stRect prect, stRecursion& pRecData) {
	if (pRecData.count == 0) { cout << "���������� ������� ����������!\n"; return; }

	int indx = 15, indy = 15;
	stRect InRect(prect.Left + indx, prect.Top + indy, prect.Width - indx - 10, prect.Height - indy - 25);
	HWND hwnd = GetConsoleWindow();
	HDC hdc = GetDC(hwnd);
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(255, 2585, 255));
	LOGBRUSH Igbr{ PS_SOLID, RGB(78, 78, 78), 0 };
	HBRUSH brush = CreateBrushIndirect(&Igbr);
	(SelectObject(hdc, pen));
	(SelectObject(hdc, brush));
	Rectangle(hdc, prect.Left, prect.Top, prect.Right(), prect.Bottom());
	DrawAxisX(hdc, InRect, pRecData.count/2);
	DrawAxisY(hdc, InRect, 5);
}

void DrawAxisX(HDC phdc, stRect pInRect, int psec) {
	MoveToEx(phdc, pInRect.Left, pInRect.Bottom(), NULL);
	LineTo(phdc, pInRect.Right(), pInRect.Bottom());

	float PxSec = pInRect.Width / psec;
	for (int i = 0; i < psec; i++) {
		if (i > 0) {
			MoveToEx(phdc, pInRect.Left + i * PxSec, pInRect.Top, NULL);
			LineTo(phdc, pInRect.Right(), pInRect.Bottom());

		}
	}
}
void DrawAxisY(HDC phdc, stRect pInRect, int psec) {
	MoveToEx(phdc, pInRect.Left, pInRect.Top, NULL);
	LineTo(phdc, pInRect.Left, pInRect.Bottom());
}
