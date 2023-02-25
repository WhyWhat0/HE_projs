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

void move(int x, int y) {
	SetColor(0, 15);
	cout << "  "; point(x, y);
	SetColor(9, 9);
	cout << "@@"; point(x, y);
}
void check_wall(int &x, int &y, int map[], int c) {
	unsigned int Bit = 0b1000'0000'0000'0000'0000'0000'0000'0000;
	if ((Bit >> x) & map[y] || x == -1 || y == -1) {
		Beep(400, 100);
		switch (c) {
		case 72:
		case 119:
			y += 1; break;
		case 115:
		case 80:
			y -= 1; break;
		case 97:
		case 75:
			x += 1; break;
		case 100:
		case 77:
			x -= 1; break;
		}
	}	
}
bool end(int x, int y, int ex, int ey) {
	if ((x == ex) and (y = ey)) {
		SetColor(5, 15);
		system("cls");		
		cout << "Easy win!!!" << endl;
		SetColor(0, 15);
		_getch();
		return true;
	}
	return false;
}

void SetColor(int pnColorBackground, int pnColorText) {
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, (WORD)(((pnColorBackground & 0x000F) << 4) | (pnColorText & 0x000F)));
}


bool is_visited(int nx, int ny, block* visited, int col_ways) {
	for (int i = 0;i < col_ways;i++) if (visited[i].x == nx && visited[i].y == ny) return true;
	return false;
}

int find_way(int nx, int ny, block* visited, int *map, int col_ways, int nex, int ney, int i = 0) {
	visited[i].x = nx; visited[i].y = ny; i++;
	unsigned int Bit = 0b1000'0000'0000'0000'0000'0000'0000'0000;
	/*cout << "основное: " << i << " вызов (RLDU) " << !((Bit >> nx + 1) & map[ny]) <<
		!((Bit >> nx - 1) & map[ny]) << !((Bit >> nx) & map[ny + 1]) <<
		!((Bit >> nx) & map[ny - 1]) << "    " << nx << " " << ny << "   " << stop(nx, ny) << endl;*/ //out_vis(visited, col_ways); cout << endl;
	//Sleep(500);
	if (nx == nex && ny == ney) {
		return 1;
	}
	else {

		//cout << "Доп. " << visited[i].x << " " << visited[i].y << "." << " " << i << " " << endl;
		
		if (!((Bit >> nx + 1) & map[ny]) && !is_visited(nx + 1, ny, visited, col_ways)) {
			if (find_way(nx + 1, ny, visited, map, col_ways, nex, ney, i)) return 1;
		}
		if (!((Bit >> nx - 1) & map[ny]) && !is_visited(nx - 1, ny, visited, col_ways)) {
			if(find_way(nx - 1, ny, visited, map, col_ways, nex, ney, i)) return 1;
		}
		if (!((Bit >> nx) & map[ny + 1]) && !is_visited(nx, ny + 1, visited, col_ways)) {
			if(find_way(nx, ny + 1, visited, map, col_ways, nex, ney, i)) return 1;
		}
		if (!((Bit >> nx) & map[ny - 1]) && !is_visited(nx, ny - 1, visited, col_ways)) {
			if(find_way(nx, ny - 1, visited, map, col_ways, nex, ney, i)) return 1;
		}
	}
	
	return 0;
}
void mark(block* visited, int nex, int ney) {
	SetColor(2, 2);
	int i = 0;
	while (!(visited[i].x == nex && visited[i].y == ney)) {
		Sleep(50);
		point(visited[i].x, visited[i].y);
		cout << "  ";
		i++;
	}
	point(visited[i].x, visited[i].y);
	cout << "  ";
}