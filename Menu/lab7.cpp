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
		case '1': system("cls"); lab7(); break;
		case '2': system("cls"); lab7_graf(); break;
		case '0': return;
		default:
			system("cls");
			cout << "Ошибочный ввод. Нажмите любую кнопку для продолжения...";
			_getch();
		}
		
	} while (i != 27);
}

long double NextRec(double x, double n,double &An, double nSum) {
	An = pow(n, 3) + pow(An,1) / pow(n, 3);	
	nSum = nSum + An;
	RecData.setRec[(int)n-1].IdSet = (int)n;
	RecData.setRec[(int)n-1].value1 = An;
	RecData.setRec[(int)n-1].value2 = nSum;

	/*(RecData.setRec + n)->IdSet = n;
	(*(RecData.setRec + n)).IdSet = n;*/

	if (n < 20) return NextRec(x, n + 1, An, nSum);
	return nSum;
}



void lab7(bool pause) {
	cout << "Расчет рекуррентного соотношения последоваельности\n";
	cout << "\tиз 20 членов с последующим суммированием\n";

	double x = 1;
	cout << "\nначальное значение x = 1\n";
	RecData.SetCount(20);
	RecData.setRec[0].IdSet = 1;
	RecData.setRec[0].value1 = x;
	RecData.setRec[0].value2 = 0;
	double y = NextRec(x, 2, x, 0);
	printf("\nвывести конечные значения y=%f,\tпри x=%4f\n", y, x);
	cout << "\nNпп\t  чден ряда\t накопленное значчение\n";
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

	int indx = 120, indy = 60, gWidth = prect.Width - indx * 2, gHeight = prect.Height - indy * 2;
	stRect InRect(prect.Left + indx, prect.Top + indy, prect.Width - indx*2, prect.Height - indy*2);
	HWND hwnd = GetConsoleWindow();
	HDC hdc = GetDC(hwnd);
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(255, 258, 255)), //pink
		pen2 = CreatePen(PS_SOLID, 2, RGB(0, 255, 0)), //green
		pen3 = CreatePen(PS_SOLID, 2, RGB(255, 0, 0)), //red
		pen4 = CreatePen(PS_SOLID, 2, RGB(255, 255, 0)); //yellow
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
	char sTitle[45]{ "График значений рекурентного соотношения" };
	SIZE size;
	GetTextExtentPoint32A(hdc, sTitle, strlen(sTitle), &size);
	TextOutA(hdc, prect.Left + indx + (gWidth - size.cx)/2, prect.Top+2, sTitle, strlen(sTitle));
	DeleteObject(SelectObject(hdc, holdfont)); hfTitle = 0;
	SelectObject(hdc, pen);
	DrawAxisX(hdc, InRect, pRecData.count, pRecData);
	DrawAxisY(hdc, InRect, pRecData.count/2, pRecData);
	//рисовка графика
	double minx, maxx, miny, maxy, pxPerX = 0, pxPerY = 0;
	pair<double, double> res = pRecData.minimax(mod_X);
	minx = res.first; maxx = res.second;
	res = pRecData.minimax(mod_Y);
	miny = res.first; maxy = res.second;
	pxPerX = InRect.Width / (maxx - minx);
	pxPerY = InRect.Height / (maxy - miny);
	int limit = (pRecData.model == mod_n_An_Y) ? 2 : 1;
	for (int n = 0;n < limit;n++) {
		if(n==0) SelectObject(hdc, pen3); else 	SelectObject(hdc, pen4);
		for (int i = 0; i < pRecData.count; i++) {
			res = pRecData.Y(i);
			double value = (n) ? res.second : res.first;
			int dX = (int)((pRecData.X(i) - minx) * pxPerX),
				dY = (int)((value - miny) * pxPerY);
			int	coorx = InRect.Left + dX,
				coory = InRect.Bottom() - dY;
			if(i == 0) MoveToEx(hdc, coorx, coory, NULL); else LineTo(hdc, coorx, coory);
		}
	}
}

void DrawAxisX(HDC phdc, stRect pInRect, int psec, stRecursion& pRecData, char* ptext) {
	MoveToEx(phdc, pInRect.Left, pInRect.Bottom(), NULL);
	LineTo(phdc, pInRect.Right(), pInRect.Bottom());

	//if (psec > pRecData.count) psec = pRecData.count;
	HPEN pen = CreatePen(PS_DOT, 1, RGB(200, 200,200)),
	penold = (HPEN)SelectObject(phdc, pen);
	HFONT hold, haixes = CreateFontA(14, 0, 0, 0, FW_NORMAL, false, false, false, RUSSIAN_CHARSET,
		OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS,
		CLEARTYPE_QUALITY, VARIABLE_PITCH, "Times New Roman");
	hold = (HFONT)SelectObject(phdc, haixes);

	pair<double, double> res = pRecData.minimax(mod_X);
	double min = res.first, max = res.second;

	//float PxSec = pInRect.Width / psec;
	float PxSec = (max - min) / (psec-1);

	char text[25]{ 0 }; 
	
	double PxStep = pInRect.Width/(psec);
	SIZE sizex;
	for (int i = 0; i < psec; i++) {
		if (i > 0) {
			MoveToEx(phdc, pInRect.Left + i * PxStep, pInRect.Bottom() + 2, NULL);
			LineTo(phdc, pInRect.Left + i * PxStep, pInRect.Top);
		}
		double PXS = min + (PxSec * i);
		switch (pRecData.model) {
		case mod_An_Y: sprintf_s(text, "%4.1f", pRecData.X(i)); break;
		default: sprintf_s(text, "%4.1f", PXS);
		}
		GetTextExtentPoint32A(phdc, text, strlen(text), &sizex);
		TextOutA(phdc, pInRect.Left + (int)(i * PxStep - sizex.cx/2), pInRect.Bottom()+2, text, strlen(text));
	}
	pen= (HPEN)SelectObject(phdc, penold);
	DeleteObject(pen); penold = 0;
	// Работа с текстом заголовки и метки
	HFONT haixtitle = CreateFontA(28, 18, 0, 0, FW_NORMAL, false, false, false, RUSSIAN_CHARSET,
		OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS,
		CLEARTYPE_QUALITY, VARIABLE_PITCH, "Times New Roman");
		
	hold = (HFONT)SelectObject(phdc, haixtitle);
	if (ptext == NULL) ptext = (char*)" ось x ";
	SIZE size;
	GetTextExtentPoint32A(phdc, ptext, strlen(ptext), &size);
	SetTextColor(phdc, RGB(255, 0, 255));
	TextOutA(phdc, pInRect.Left + pInRect.Width/2 - size.cx/2, pInRect.Bottom() + 30, ptext, strlen(ptext));
}

////////////////////////////////////////////////////////////////////////////////////

void DrawAxisY(HDC phdc, stRect pInRect, int psec, stRecursion& pRecData, char* ptext) {
	MoveToEx(phdc, pInRect.Left, pInRect.Top, NULL);
	LineTo(phdc, pInRect.Left, pInRect.Bottom());

	//if (psec < pRecData.count) psec = pRecData.count;


	HPEN pen = CreatePen(PS_DOT, 1, RGB(200, 200, 200)),
		penold = (HPEN)SelectObject(phdc, pen);

	float PxSec = pInRect.Height / psec;

	char text[25]{ 0 };
	SIZE sizey;
	pair<double, double> res = pRecData.minimax(mod_Y);
	double min = res.first, max = res.second;
	double PxStep = pInRect.Height / (psec);
	double Dlty = (max - min) / (psec-1);
	HFONT hold, haixes = CreateFontA(14, 0, 0, 0, FW_NORMAL, false, false, false, RUSSIAN_CHARSET,
		OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS,
		CLEARTYPE_QUALITY, VARIABLE_PITCH, "Times New Roman");
	hold = (HFONT)SelectObject(phdc, haixes);
	SetTextColor(phdc, RGB(0, 0, 255));
	for (int i = 0; i < psec; i++) {
		if (i > 0) {
			MoveToEx(phdc, pInRect.Left-2, pInRect.Bottom() - i * PxSec, NULL);
			LineTo(phdc, pInRect.Right(), pInRect.Bottom()  - i * PxSec);
		}
		/////
		double value = min + Dlty * i;
		sprintf_s(text, "%4.2f", value);
		GetTextExtentPoint32A(phdc, text, strlen(text), &sizey);
		if (i < pRecData.count) TextOutA(phdc, pInRect.Left - 55, pInRect.Bottom() - (int)(i * PxStep + sizey.cy/2), text, strlen(text));
		/////

	}
	pen = (HPEN)SelectObject(phdc, penold);
	DeleteObject(pen);
	//Работа с текстом заголовки и метки
	HFONT haixtitles = CreateFontA(28, 18, 900, 0, FW_NORMAL, false, false, false, RUSSIAN_CHARSET,
		OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS,
		CLEARTYPE_QUALITY, VARIABLE_PITCH, "Times New Roman"),
		/*haixes = CreateFontA(14, 0, 0, 0, FW_NORMAL, false, false, false, RUSSIAN_CHARSET,
			OUT_OUTLINE_PRECIS, CLIP_DEFAULT_PRECIS,
			CLEARTYPE_QUALITY, VARIABLE_PITCH, "Times New Roman");*/
	holds = (HFONT)SelectObject(phdc, haixtitles);
	if (ptext == NULL) ptext = (char*)" ось y ";
	SetTextColor(phdc, RGB(255, 0, 255));
	GetTextExtentPoint32A(phdc, ptext, strlen(ptext), &sizey);

	TextOutA(phdc, pInRect.Left-100, pInRect.Bottom() - pInRect.Height/2 + sizey.cx/2, ptext, strlen(ptext));
}
