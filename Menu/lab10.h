#pragma once
#pragma once
#include "Header.h"

class CID {
	int nid;	//идентификатор объекта
protected:
	string sname;	//имя класса
public:
	CID() : nid(0), sname("CID") {}
	CID(int pid, string pname = "CID") : nid(pid), sname(pname) {}
	int ID() { return nid; }

	int GetId() { return nid; }
	void SetId(int pid) { nid = pid; }
	virtual string GetName() { return sname; }
	virtual void SetName(string pname) { sname = pname; }
};

class CFigure : public CID {
	int nx, //координата левого верхнего угла прямоугольника по оси x
		ny,  //координата левого верхнего угла прямоугольника по оси y
		nWidth, //ширина прямоугольника
		nHeight; // высота прямугольника
	int brushcolor, //цвет заливки
		pencolor; //цвет котура

public:
	CFigure();
	CFigure(int pnx, int pny, int pnWidth, int pnHeight);
	CFigure(int pnx, int pny, int pnWidth, int pnHeight, int pbrushcolor, int ppencolor);



	int X() { return nx; }
	void X(int px) { nx = px; }
	int Y() { return ny; }
	void Y(int py) { ny = py; }

	int Width() { return nWidth; }
	void Width(int pWidth) { nWidth = pWidth; }
	int Height() { return nHeight; }
	void Height(int pHeight) { nHeight = pHeight; }

	int BrushColor() { return brushcolor; }
	void BrushColor(int pbrushcolor) { brushcolor = pbrushcolor; }
	int PenColor() { return pencolor; }
	void PenColor(int ppencolor) { pencolor = ppencolor; }

	int Left() { return nx; }
	int Top() { return ny; }
	int Right() { return nx + nWidth; }
	int Bottom() { return ny + nHeight; }

	int MiddleX() { return nx + nWidth / 2; }
	int MiddleY() { return ny + nHeight / 2; }

	virtual void Draw() { cout << " да."; };
};

class CRectangle : public CFigure {	
public:
	CRectangle();
	CRectangle(int pnx, int pny, int pnWidth, int pnHeight);
	CRectangle(int pnx, int pny, int pnWidth, int pnHeight, int pbrushcolor, int ppencolor);

	virtual void Draw();
};

class CTriangle : public CFigure {
	

public:
	CTriangle();
	CTriangle(int pnx, int pny, int pnWidth, int pnHeight);
	CTriangle(int pnx, int pny, int pnWidth, int pnHeight, int pbrushcolor, int ppencolor);

	virtual void Draw();
};
 
class CEllipse : public CFigure {
	
public:
	CEllipse();
	CEllipse(int pnx, int pny, int pnWidth, int pnHeight);
	CEllipse(int pnx, int pny, int pnWidth, int pnHeight, int pbrushcolor, int ppencolor);

	virtual void Draw();
};

class CUnion { //соединитель объектов
	CFigure* fig1, *fig2; //фигура первая и вторая
	int color,
		width;
public:
	CUnion(CFigure* pfig1 = NULL, CFigure* pfig2 = NULL);
	~CUnion();

	void SetFigure1(CFigure* pfig);
	void SetFigure2(CFigure* pfig);
	void SetColor(int pcolor);
	void SetWidth(int pwid);
	CFigure* GetFigure1();
	CFigure* GetFigure2();
	int GetColor();
	int GetWidth();

	void Draw();

};
class CManager {
private:
	CFigure** figures;		// это динамический массив объектов: прямоугольников, треугольников и овалов
	int ncount;				// количесво объектов в figures
	CUnion* ounions;		// динамический массив объектов CUnion
	int nunion;			//кол-во соединений

public:
	CManager();
	~CManager();

	CFigure* operator[](int index);
	int AddFigure(CFigure* pFigure);
	int Count();
	CFigure* GetFigure(int pid);


	CUnion GetUnion(int index);
	int AddUnion(CFigure* pf1 = NULL, CFigure* pf2 = NULL);

	void Draw();
	void Draw(int pid); // отрисовка по ID
	void Draw(string pclass); // отрисовка по классу
	void DrawGraph(); // отрисовка фигур и линий соединения
};

void lab10();
void ParamMenu(CManager& manager);