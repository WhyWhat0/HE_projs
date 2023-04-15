#pragma once
#include "Header.h"

typedef enum {
	CL_BLACK,
	CL_BLUE,
	CL_GREEN,
	CL_CYAN,
	CL_RED,
	CL_PURPLE,
	CL_YELLOW,
	CL_WHITE,
	CL_LIGHT_BLACK,
	CL_LIGHT_BLUE,
	CL_LIGHT_GREEN,
	CL_LIGHT_CYAN,
	CL_LIGHT_RED,
	CL_LIGHT_PURPLE,
	CL_LIGHT_YELLOW,
	CL_LIGHT_WHITE,
	в╗пмши = 0,
	яхмхи,
	гек╗мши,
	цнксани,
	йпюямши,
	тхнкернбши,
	ф╗крши,
	аекши,
	яепши,
	яберкн_яхмхи,
	яберкн_гек╗мши,
	яберкн_цнксани,
	яберкн_йпюямши,
	яберкн_тхнкернбши,
	яберкн_ф╗крши,
	яберкн_аекши
} COLORS, жберю;

void ClearScreen();
void point(int x, int y);
void SetColor(int pnColorBackground = CL_BLACK, int pnColorText = CL_BLUE);
double mPow(double x, double l);