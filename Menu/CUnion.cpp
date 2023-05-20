#include "lab10.h"



//class CUnion { //соединитель объектов
//	CFigure* fig1, * fig2; //фигура первая и вторая
//	int color,
//		width;
//public:
CUnion::CUnion(CFigure* pfig1, CFigure* pfig2) :fig1(pfig1), fig2(pfig2), color(RGB(255, 255, 255)), width(3) {}
CUnion :: ~CUnion() { fig1 = 0, fig2 = 0; }

void CUnion::SetFigure1(CFigure* pfig) { fig1 = pfig; }
void CUnion::SetFigure2(CFigure* pfig) { fig2 = pfig; }
void CUnion::SetColor(int pcolor) { color = pcolor; }
void CUnion::SetWidth(int pwid) { width = pwid; }
CFigure* CUnion::GetFigure1() { return fig1; }
CFigure* CUnion::GetFigure2() { return fig2; }
int CUnion::GetColor() { return color; }
int CUnion::GetWidth() { return width; }

void CUnion::Draw() {
	if (fig1 == 0 || fig2 == 0) return;

	HDC hdc = GetDC(GetConsoleWindow());
	HPEN pen = CreatePen(PS_SOLID, width, color);
	SelectObject(hdc, pen);
	MoveToEx(hdc, fig1->MiddleX(), fig1->MiddleY(), NULL);
	LineTo(hdc, fig2->MiddleX(), fig2->MiddleY());

	DeleteObject(pen);
}


