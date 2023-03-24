#include "lab7.h"

stRecursion RecData;

void RecMenu() {
	uchar i = 0;
	do {
		system("cls");

		cout << "Меню рекурсии\n\n";
		cout << "1) Рекурсия с таблицей\n\n";
		cout << "2) Рекурсия с графиком\n\n";
		cout << "0) Выход\n\n";

		i = _getch();
		switch (i) {
		case '1': lab7(); break;
		case '2': lab7_graf(); break;
		case '0': return;
		default:
			system("cls");
			cout << "Ошибочный ввод. Нажмите любую кнопку для продолжения...";
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
	cout << "Расчет рекуррентного соотношения последоваельности\n";
	cout << "\tиз 20 членовб с последующим суммированием\n\n";

	double x = 1;
	cout << "начальное значение x = 1";
	RecData.SetCount(10);
	RecData.setRec[0].IdSet = 1;
	RecData.setRec[0].value1 = x;
	RecData.setRec[0].value2 = 0;
	long double y = NextRec(x, 2, x, 0);
	printf("\nвывести конечные значения y=%f,\tпри x=%4f\n\n", y, x);
	cout << "Nпп\t  чден ряда\t накопленное значчение\n";
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

	stRECT Rect(500, 300, 800, 400);
	cout << "График\n\n";
	DrawGraf(Rect, RecData);
	_getch();
	CLRSCR;

}

void DrawGraf(stRect prect, stRecursion& pRecData) {
	if (pRecData.count == 0) { cout << "Построение графика невозможно!\n"; return; }

	int indx = 50, indy = 50, gWidth = prect.Width - indx * 2, gHeight = prect.Height - indy * 2;
	stRect InRect(prect.Left + indx, prect.Top + indy, prect.Width - indx*2, prect.Height - indy*2);
	HWND hwnd = GetConsoleWindow();
	HDC hdc = GetDC(hwnd);
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(255, 258, 255)), 
		pen2 = CreatePen(PS_SOLID, 2, RGB(0, 255, 0)), //green
		pen3 = CreatePen(PS_SOLID, 2, RGB(255, 0, 0)); //red
	LOGBRUSH Igbr{ PS_SOLID, RGB(78, 78, 78), 0 };
	HBRUSH brush = CreateBrushIndirect(&Igbr);
	SelectObject(hdc, pen2);
	SelectObject(hdc, brush);
	Rectangle(hdc, prect.Left, prect.Top, prect.Right(), prect.Bottom());

	HFONT holdfont = 0, hfTitle = CreateFontA(32, 0, 0, 0, FW_NORMAL, false, false, false, RUSSIAN_CHARSET,
		OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS,
		CLEARTYPE_QUALITY, VARIABLE_PITCH, "Times New Roman");

	SetTextColor(hdc, RGB(0, 0, 255));
	SetBkColor(hdc, RGB(78, 78, 78));

	holdfont = (HFONT)SelectObject(hdc, hfTitle);
	char sTitle[45]{ "График значений рекурентного стоотношения" };
	SIZE size;
	GetTextExtentPoint32A(hdc, sTitle, strlen(sTitle), &size);
	TextOutA(hdc, prect.Left + indx + (gWidth - size.cx)/2, prect.Top+2, sTitle, strlen(sTitle));
	DeleteObject(SelectObject(hdc, holdfont)); hfTitle = 0;
	SelectObject(hdc, pen);
	DrawAxisX(hdc, InRect, pRecData.count*2);
	DrawAxisY(hdc, InRect, pRecData.count);

}

void DrawAxisX(HDC phdc, stRect pInRect, int psec, char* ptext) {
	MoveToEx(phdc, pInRect.Left, pInRect.Bottom(), NULL);
	LineTo(phdc, pInRect.Right(), pInRect.Bottom());

	HPEN pen = CreatePen(PS_DOT, 1, RGB(200, 200,200)),
	penold = (HPEN)SelectObject(phdc, pen);

	float PxSec = pInRect.Width / psec;
	for (int i = 0; i < psec + 1; i++) {
		if (i > 0) {
			MoveToEx(phdc, pInRect.Left + i * PxSec, pInRect.Bottom() + 2, NULL);
			LineTo(phdc, pInRect.Left + i * PxSec, pInRect.Top);

		}
	}
	pen= (HPEN)SelectObject(phdc, penold);
	DeleteObject(pen);
	// Работа с текстом заголовки и метки

	HFONT hold, haix = CreateFontA(24, 18, 0, 0, FW_NORMAL, false, false, false, RUSSIAN_CHARSET,
		OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS,
		CLEARTYPE_QUALITY, VARIABLE_PITCH, "Times New Roman"),
		haixes = CreateFontA(14, 0, 0, 0, FW_NORMAL, false, false, false, RUSSIAN_CHARSET,
			OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS,
			CLEARTYPE_QUALITY, VARIABLE_PITCH, "Times New Roman");
	hold = (HFONT)SelectObject(phdc, haix);
	if (ptext == NULL) ptext = (char*)" Название оси x ";
	SetTextColor(phdc, RGB(255, 0, 255));
	SIZE size;
	GetTextExtentPoint32A(phdc, ptext, strlen(ptext), &size);

	TextOutA(phdc, pInRect.Left + pInRect.Width/2 - size.cx/2, pInRect.Bottom() + 18, ptext, strlen(ptext));
}
void DrawAxisY(HDC phdc, stRect pInRect, int psec, char* ptext) {
	MoveToEx(phdc, pInRect.Left, pInRect.Top, NULL);
	LineTo(phdc, pInRect.Left, pInRect.Bottom());

	HPEN pen = CreatePen(PS_DOT, 1, RGB(200, 200, 200)),
		penold = (HPEN)SelectObject(phdc, pen);

	float PySec = pInRect.Height / psec;
	for (int i = 0; i < psec + 1; i++) {
		if (i > 0) {
			MoveToEx(phdc, pInRect.Left, pInRect.Bottom() - i * PySec, NULL);
			LineTo(phdc, pInRect.Right(), pInRect.Bottom()  - i * PySec);
		}
	}
	pen = (HPEN)SelectObject(phdc, penold);
	DeleteObject(pen);

	// Работа с текстом заголовки и метки

	HFONT hold, haix = CreateFontA(24, 18, 900, 0, FW_NORMAL, false, false, false, RUSSIAN_CHARSET,
		OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS,
		CLEARTYPE_QUALITY, VARIABLE_PITCH, "Times New Roman"),
		haixes = CreateFontA(14, 0, 0, 0, FW_NORMAL, false, false, false, RUSSIAN_CHARSET,
			OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS,
			CLEARTYPE_QUALITY, VARIABLE_PITCH, "Times New Roman");
	hold = (HFONT)SelectObject(phdc, haix);
	if (ptext == NULL) ptext = (char*)" Название оси y ";
	SetTextColor(phdc, RGB(255, 0, 255));
	SIZE size;
	GetTextExtentPoint32A(phdc, ptext, strlen(ptext), &size);

	TextOutA(phdc, pInRect.Left-40, pInRect.Bottom() + 18, ptext, strlen(ptext));
}
