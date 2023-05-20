#include"lab10.h"

CTriangle::CTriangle() : CFigure() {
	BrushColor(RGB(255, 255, 0)); //цвет заливки
	SetName("CTriangle");
}

CTriangle::CTriangle(int pnx, int pny, int pnWidth, int pnHeight) : CFigure(pnx, pny, pnWidth, pnHeight){
	BrushColor(RGB(255, 255, 0)); //цвет заливки
	SetName("CTriangle");
}
CTriangle::CTriangle(int pnx, int pny, int pnWidth, int pnHeight, int pbrushcolor, int ppencolor)
	:CFigure(pnx, pny, pnWidth, pnHeight, pbrushcolor, ppencolor) {
	SetName("CTriangle");
}
void CTriangle::Draw() {

	LOGBRUSH lpBrush;
	lpBrush.lbStyle = BS_SOLID;
	lpBrush.lbColor = BrushColor();


	HDC hdc = GetDC(GetConsoleWindow());

	HBRUSH hbrush = CreateBrushIndirect(&lpBrush);
	SelectObject(hdc, hbrush);

	HPEN hpen = CreatePen(PS_SOLID, 2, PenColor());
	SelectObject(hdc, hpen);


	POINT pt[4];
	pt[0].x = MiddleX();	pt[0].y = Top();
	pt[1].x = Right();		pt[1].y = Bottom();
	pt[2].x = Left();		pt[2].y = Bottom();
	pt[3].x = pt[0].x;		pt[3].y = pt[0].y;
	Polygon(hdc, pt, 4);

	string text = to_string(ID());
	TextOutA(hdc, MiddleX(), MiddleY(), text.c_str(), text.length());
	DeleteObject(hbrush);
	DeleteObject(hpen);
	ReleaseDC(GetConsoleWindow(), hdc);
}
