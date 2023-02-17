#include <conio.h>
#include<stdio.h>
#include <iostream>
#include <iomanip>
#include <math.h>
#include<windows.h>
#include<tuple>
#include <fstream>

using namespace std;

int map[32] = {
	0b1111'1111'1111'0111'1111'1111'1111'1111,
	0b1111'1111'1111'0111'1111'1111'1111'1111,
	0b1111'1111'1111'0111'1111'1111'1111'1111,
	0b1111'1111'1111'0111'1111'1111'1111'1111,
	0b1111'1111'1111'0111'1111'1111'1111'1111,
	0b1111'1111'1111'0111'1111'1111'1111'1111,
	0b1111'1111'1111'0111'1111'1111'1111'1111,
	0b1111'1110'1111'0001'1111'1111'1111'1111,
	0b1111'1110'1111'1101'1111'1111'1111'1111,
	0b1111'1110'1110'0001'1111'1111'1111'1111,
	0b1111'1110'0000'1111'1111'1111'1111'1111,
	0b1111'1110'1111'1111'1111'1111'1111'1111,
	0b1111'1100'1111'1111'1111'1111'1111'1111,
	0b1111'1101'1111'1111'1111'1111'1111'1111,
	0b1111'1100'0000'0000'0000'0000'0000'0000,
	0b1111'1111'1011'1111'1111'1111'1111'1111,
	0b1111'1111'1011'1111'1111'1111'1111'1111,
	0b1111'1111'1011'1111'1111'1111'1111'1111,
	0b1111'1111'1011'1111'1111'1111'1111'1111,
	0b1111'1111'1000'0000'1111'1111'1111'1111,
	0b1111'1111'1011'1111'1111'1111'1111'1111,
	0b1111'1111'1000'0000'0000'1111'1111'1111,
	0b1111'1111'1111'1111'1111'1111'1111'1111,
	0b1111'1111'1111'1111'1111'1111'1111'1111,
	0b1111'1111'1111'1111'1111'1111'1111'1111,
	0b1111'1111'1111'1111'1111'1111'1111'1111,
	0b1111'1111'1111'1111'1111'1111'1111'1111,
	0b1111'1111'1111'1111'1111'1111'1111'1111,
	0b1111'1111'1111'1111'1111'1111'1111'1111,
	0b1111'1111'1111'1111'1111'1111'1111'1111,
	0b1111'1111'1111'1111'1111'1111'1111'1111,
	0b1111'1111'1111'1111'1111'1111'1111'1111
};
int c, curs, col_ways = 200, i = 0;
int nx, ny;
int nbx =  12, nby = 0, nex = 24, ney = 14;
unsigned int Bit = 0b1000'0000'0000'0000'0000'0000'0000'0000;

struct block {
	int x;
	int y;
};

block *visited = new block[col_ways];

bool stop(int nx, int ny) {
	if (nx > -1 && nx<32 && ny>-1 && ny < 32) return false;
	return true;
}

bool is_visited(int nx, int ny, block *visited, int col_ways) {
	for (i = 0;i < col_ways;i++) if (visited[i].x == nx && visited[i].y == ny) return true;
	return false;
}

void out_vis(block *visited, int col_ways){
	for (int i = 0; i< col_ways; i++) cout << i+1 << ") " << visited[i].x << " " << visited[i].y << ", ";
}

int find_way(int nx, int ny, block *visited, int i = 0) {
	cout << "основное: "<< i << " вызов (RLDU) " << !((Bit >> nx + 1) & map[ny]) << 
		!((Bit >> nx - 1) & map[ny]) << !((Bit >> nx) & map[ny + 1]) << 
		!((Bit >> nx) & map[ny - 1]) << "    " << nx << " " << ny << "   " << endl; //out_vis(visited, col_ways); cout << endl;

	//Sleep(500);
	if (!stop(nx, ny)) {
		visited[i].x = nx; visited[i].y = ny; 

		cout << "Доп. " <<visited[i].x << " " << visited[i].y << "." << " " << i << " " << endl;
		if (nx == nex && ny == ney) {
			return 1;
		}
		if (!((Bit >> nx + 1) & map[ny]) &&!is_visited(nx+1, ny, visited, col_ways)) {
			return find_way(nx + 1, ny, visited, i+1);
		}
		if (!((Bit >> nx - 1) & map[ny]) && !is_visited(nx-1, ny, visited, col_ways)) {
			return find_way(nx - 1, ny, visited, i+1);
		}
		if (!((Bit >> nx) & map[ny + 1]) && !is_visited(nx, ny+1, visited, col_ways)) {
			return find_way(nx, ny + 1, visited, i+1);
		}
		if (!((Bit >> nx) & map[ny - 1]) && !is_visited(nx, ny-1, visited, col_ways)) {
			return find_way(nx, ny - 1, visited, i+1);
		}
	}
	return 0;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	cout << find_way(nbx, nby, visited);
    return 0;
}