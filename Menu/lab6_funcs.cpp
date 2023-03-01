#include"lab6_funcs.h"

struct block {
	int x;
	int y;
};

void point(int x, int y) {
	COORD position = { x*2,y }; //позиция x и y
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hConsole, position);
}

void SetColor(int pnColorBackground, int pnColorText) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)(((pnColorBackground & 0x000F) << 4) | (pnColorText & 0x000F)));
}
void move(int x, int y) {
	SetColor(0, 15);
	cout << "  "; point(x, y);
	SetColor(9, 9);
	cout << "@@"; point(x, y);

}bool edge(int x, int y, const int ex, const int ey) {
	if (x < 0 || x > ex - 1 || y < 0 || y > ey - 1) return true;
	return false;
}



int find_way(int nx, int ny, uint* visited, int *map, int col_ways, int nex, int ney, int i = 0) {
	uint Bit = 0b1000'0000'0000'0000'0000'0000'0000'0000;
	visited[i] |= (Bit >> nx); i++;
	if (nx == nex && ny == ney) {
		return 1;
	}
	else {

		//cout << "Доп. " << visited[i].x << " " << visited[i].y << "." << " " << i << " " << endl;
		if (!((Bit >> nx) & map[ny + 1]) && !(visited[ny + 1] & (Bit >> nx))) {
			if (find_way(nx, ny + 1, visited, map, col_ways, nex, ney, i)) return 1;
		}
		if (!((Bit >> nx) & map[ny - 1]) && !(visited[ny - 1] & (Bit >> nx))) {
			if (find_way(nx, ny - 1, visited, map, col_ways, nex, ney, i)) return 1;
		}
		if (!((Bit >> nx + 1) & map[ny]) && !(visited[ny] & (Bit >> nx+1))) {
			if (find_way(nx + 1, ny, visited, map, col_ways, nex, ney, i)) return 1;
		}
		if (!((Bit >> nx - 1) & map[ny]) && !(visited[ny] & (Bit >> nx-1))) {
			if(find_way(nx - 1, ny, visited, map, col_ways, nex, ney, i)) return 1;
		}
		
	}
	return 0;
}

void mark(uint* visited, int nex, int ney) {
	SetColor(2, 2);
	int x = 0, y = 0;
	while (!(x == nex && y == ney)) {
		x = log2(visited[y]);
		Sleep(10);
		point(x, y);
		cout << "  ";
		y++;
	}
	point(x, y);
	cout << "  ";
}