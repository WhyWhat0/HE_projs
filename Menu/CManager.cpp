#include "lab10.h"

int CManager::AddFigure(CFigure* pFigure) {
	if (pFigure == NULL) return -1;

	figures = (CFigure**)realloc(figures, sizeof(CFigure*) * (++ncount));
	figures[ncount - 1] = pFigure;
	return ncount-1;
}

