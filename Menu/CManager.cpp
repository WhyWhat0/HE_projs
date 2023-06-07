#include "lab10.h"

CManager::CManager() : figures(NULL), ncount(0), ounions(0), nunion(0) {};
CManager::~CManager() {
	for (int i = 0; i < ncount; i++) delete figures[i];
	free(figures);
	free(ounions);
};

int CManager::AddFigure(CFigure* pFigure) {
	if (pFigure == NULL) return -1;

	figures = (CFigure**)realloc(figures, sizeof(CFigure*) * (++ncount));
	figures[ncount - 1] = pFigure;
	return ncount-1;
}
int CManager:: Count() { return ncount; }


CFigure* CManager :: GetFigure(int pid) {
	for (int i = 0; i < ncount; i++) {
		if (figures[i]->ID() == pid) return figures[i];
	}
	return NULL;
}
CFigure* CManager :: operator[](int index) {
	if (index < 0 || index >= ncount) return NULL;
	return figures[index];
}

CUnion CManager::GetUnion(int index) {
	if (index < 0 || index >= nunion) return 0;
	return ounions[index];
}
int CManager::AddUnion(CFigure* pf1, CFigure* pf2) {
	if (pf1 == NULL || pf2 == NULL) return -1;

	ounions = (CUnion*)realloc(ounions, sizeof(CUnion) * (++nunion));
	ounions[nunion - 1] = CUnion(pf1, pf2);
	return nunion - 1;
}

void CManager::Draw() {
	for (int i = 0;i < ncount;i++) figures[i]->Draw();

}
// отрисовка всех фигур
void CManager::Draw(int pid) {
	CFigure* gig = GetFigure(pid);
	if (gig != NULL) gig->Draw();
}
// отрисовка по ID
void  CManager::Draw(string pclass) {
	for (int i = 0;i < ncount;i++) if (figures[i]->GetName() == pclass) figures[i]->Draw();
}
	// отрисовка по классу
void CManager::DrawGraph(){
	for (int i = 0; i < nunion; i++){
		ounions[i].Draw(); Draw();
	}
}
//отрисовка соединенных фигур

void CManager::Load(string pfile) {
	ifstream fin;
	fin.open(pfile);
	if (!fin) return;

	string s;
	int id;
	while (getline(fin, s)) {
		switch (s[0]) {

		}
	}
}

void CManager::Save(string pfile) {
	ofstream fout;
	fout.open(pfile);
	if (!fout) return;

	for (int i = 0; i < ncount; i++) {
		CFigure* fig = figures[i];
		if (fig == NULL) continue;
		fout << fig->GetName() << endl;
		fout << "i=" << fig->GetId() << endl;
		fout << "x=" << fig->X() << endl;
		fout << "y=" << fig->Y() << endl;
		fout << "w=" << fig->Width() << endl;
		fout << "h=" << fig->Height() << endl;
		fout << "b=" << fig->BrushColor() << endl;
		fout << "p=" << fig->PenColor() << endl;
		fout << "end\n";
	}

	for (int i = 0; i < nunion; i++) {
		CUnion ounion = GetUnion(i);
		//fout << ounion.GetName() << endl;
		fout << "fig1=" << ounion.GetFigure1()->ID();
		fout << "fig2=" << ounion.GetFigure2()->ID();
		fout << "width=" << ounion.GetWidth() << endl;
		fout << "color=" << ounion.GetColor() << endl;
		fout << "end\n";
	}

	fout.close();
}