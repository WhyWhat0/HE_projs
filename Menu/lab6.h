#include "Header.h"

void point(int x, int y); void move(int x, int y); void check_wall(int &x, int &y, int map[], int c); 
void SetColor(int pnColorBackground, int pnColorText);
bool edge(int x, int y, const int ex, const int ey);
int find_way(int nx, int ny); 
