#include "Header.h"
void point(int x, int y); void move(int x, int y); void check_wall(int &x, int &y, int map[], int c); bool end(int x, int y, int ex, int ey); 
void SetColor(int pnColorBackground, int pnColorText); bool stop(int nx, int ny);
bool stop(int nx, int ny);bool is_visited(int nx, int ny, block* visited, int col_ways); bool stop(int nx, int ny);
int find_way(int nx, int ny, block* visited, int *map, int ways_col, int i = 0);
