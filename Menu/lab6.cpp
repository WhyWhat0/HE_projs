#include"lab6.h"

int map[32] = {
	0b1111'1111'1111'0111'1111'1111'1111'1111,//0
	0b1111'1111'1111'0111'1111'1111'1111'1111,//1
	0b1111'1111'1111'0000'0000'0000'0000'1111,//2
	0b1111'1111'1111'1111'1111'1111'1110'1111,//3
	0b1111'1111'1111'1111'1111'1111'1110'1111,//4
	0b1111'1111'0000'0001'1111'1111'1110'1111,//5
	0b1111'1111'1111'1101'1111'1111'1110'1111,//6
	0b1111'1110'1111'1101'1111'0000'0000'1111,//7
	0b1111'1110'1111'1101'1111'1110'1110'1111,//8
	0b1111'1110'1110'0000'0000'0000'0000'1111,//9
	0b1000'0000'0000'1111'1110'1111'1111'1111,//10
	0b1111'1110'1111'1111'1110'1111'1111'1111,//11
	0b1111'1100'1111'1111'1110'1111'1111'1111,//12
	0b1111'1101'1111'1111'1110'1111'1111'1111,//13
	0b1000'0000'0000'0000'0000'0000'0000'0011,//14
	0b1111'1111'1011'1111'1111'1111'1111'1111,//15
	0b1111'1111'1011'1111'1111'1111'1111'1111,//16
	0b1111'0000'0011'1111'1111'1111'1111'1111,//17
	0b1111'1111'1011'1111'1111'1111'1111'1111,//18
	0b1111'1111'1000'0000'0000'0000'1111'1111,//19
	0b1111'1111'1011'1111'1111'1110'1111'1111,//20
	0b1111'1111'1000'0000'0000'1110'1111'1111,//21
	0b1111'1111'1101'1111'1111'1110'1111'1111,//22
	0b1111'0000'0000'0000'0000'0000'1111'1111,//23
	0b1111'0111'1111'1111'1110'1111'1111'1111,//24
	0b1111'0111'1111'1111'1110'1110'1111'1111,//25
	0b1111'0111'1111'1111'1110'1110'1111'1111,//26
	0b1111'0111'1111'1111'1110'0000'1111'1111,//27
	0b1111'0111'1111'1111'1111'1110'1111'1111,//28
	0b1111'0111'1111'1111'1111'1110'1111'1111,//29
	0b1111'0000'0001'1111'1111'1111'1111'1111,//30
	0b1111'1111'1101'1111'1111'1111'1111'1111 //31
};

ofstream f("inp.txt");
int c, i = 0;
int nx, ny;
const int nbx = 12, nby = 0, nex = 10, ney = 31;
uint Bit = 0b1000'0000'0000'0000'0000'0000'0000'0000;
const int Rows = 32, Cols = 32;
uint* visited; uint* shvisited;
int way = Rows*Cols;

void lab6() {
	system("cls");
	for (ny = 0; ny < Rows; ny++) {
		for (nx = 0; nx < Cols; nx++) {
			if ((Bit >> nx) & map[ny]) {
				SetColor(7, 7);
				cout << "WW";
			}	
			else if (nx == nex && ny == ney) {
				SetColor(4, 4);
				cout << "  ";
			} 
			else{
				SetColor(0, 15);
				cout << "  ";
			}
			 
			
		}
		cout << endl;
	}
	
	nx = nbx; ny = nby;

	do {
		move(nx, ny);
		c = _getch();
		if (c == 224) {
			c = _getch();
			switch (c) {
			case 72:
				if (((Bit >> nx) & map[ny - 1]) || ny - 1 <= 0) Beep(400, 100); else ny -= 1;
				break;
			case 80:
				if (((Bit >> nx) & map[ny + 1]) || ny + 1 >= Rows) Beep(400, 100); else ny += 1;
				break;
			case 75:
				if (((Bit >> nx - 1) & map[ny]) || nx - 1 <= 0) Beep(400, 100); else nx -= 1;
				break;
			case 77:
				if (((Bit >> nx + 1) & map[ny]) || nx + 1 >= Cols) Beep(400, 100); else nx += 1;
				break;
			}
		}
		else {
			switch (c) {
			case 63:
				visited = new uint[Rows];
				memset(visited, 0, sizeof(uint) * Rows);
				find_way(nx, ny);
				for (int i = 0;i < 32; i++) {
					f << bitset<32>(visited[i]) << endl;
				}
				f << endl;
				f.close();
				point(nx, ny);
				delete[] visited;
				break;
			case 64:
				visited = new uint[Rows];
				shvisited = new uint[Rows];
				memset(visited, 0, sizeof(uint) * Rows);
				find_short_way(nx, ny);
				for (int i = 0;i < 32; i++) {
					f << bitset<32>(shvisited[i]) << endl;
				}
				f << endl;
				f.close();
				point(nx, ny);
				delete[] visited;
				delete[] shvisited;
				break;
			case 119:
				if (((Bit >> nx) & map[ny - 1]) || ny - 1 <= 0) Beep(400, 100); else ny -= 1;
				break;
			case 115:
				if (((Bit >> nx) & map[ny + 1]) || ny + 1 >= Rows) Beep(400, 100); else ny += 1;
				break;
			case 97:
				if (((Bit >> nx - 1) & map[ny]) || nx - 1 <= 0) Beep(400, 100); else nx -= 1;
				break;
			case 100:
				if (((Bit >> nx + 1) & map[ny]) || nx + 1 >= Cols) Beep(400, 100); else nx += 1;
				break;
			default:
				Beep(400, 50); break;
			}
		}
		
	} while (c != 27 && !((nx == nex) && (ny == ney)));
	SetColor(0, 15);
	
    if (c == 27) {
		system("cls");
	}
	else {
		SetColor(5, 15);
		system("cls");
		cout << "Easy win!!!" << endl;
		SetColor(0, 15);
		_getch();
	}
}

int find_way(int nx, int ny) {
	
	SetColor(2, 2);
	point(nx, ny);
	cout << "  ";
	visited[ny] |= Bit >> nx;
	if (nx == nex && ny == ney) {
		return 1;
	}
	if (nx + 1 <= Cols) {
		if (!((Bit >> nx + 1) & map[ny]) && !(visited[ny] & (Bit >> nx + 1))) {
			if (find_way(nx + 1, ny)) return 1;
		}
	}
	if (ny + 1 <= Rows) {
		if (!((Bit >> nx) & map[ny + 1]) && !(visited[ny + 1] & (Bit >> nx))) {
			if (find_way(nx, ny + 1)) return 1;
		}
	}
	if (ny - 1 >= 0) {
		if (!((Bit >> nx) & map[ny - 1]) && !(visited[ny - 1] & (Bit >> nx))) {
			if (find_way(nx, ny - 1)) return 1;
		}
	}
	
	if (nx - 1 >= 0) {
		if (!((Bit >> nx - 1) & map[ny]) && !(visited[ny] & (Bit >> nx - 1))) {
			if (find_way(nx - 1, ny)) return 1;
		}
	}
	SetColor(0, 15);
	point(nx, ny);
	cout << "  ";
	
	return 0;
}

int find_short_way(int nx, int ny, int pway) {
	int k = 0;
	visited[ny] |= Bit >> nx;
	if (nx == nex && ny == ney) {
		if (pway < way) {
			way = pway;
			delete[] shvisited;
			shvisited = new uint[Rows];
			for (i = 0; i < Rows; i++) {
				shvisited[i] = visited[i];
				if (shvisited[i] != 0) {
					for (int j = 0;j < Cols; j++) {					
						if ((Cols - log_2(shvisited[i]) + 1) & (Bit >> j)) {
							SetColor(2, 2);
							point((Cols - log_2(shvisited[i]) + 1) & (Bit >> j), i);
							cout << "  ";
						}
					}
				}
			}
		}
		visited[ney] -= Bit >> nex;
		return 1;
	}

	if (nx + 1 <= Cols) {
		if (!((Bit >> nx + 1) & map[ny]) && !(visited[ny] & (Bit >> nx + 1))) {
			if (find_short_way(nx + 1, ny, pway + 1)) k = 1;
		}
	}
	if (ny + 1 <= Rows) {
		if (!((Bit >> nx) & map[ny + 1]) && !(visited[ny + 1] & (Bit >> nx))) {
			if (find_short_way(nx, ny + 1, pway + 1)) k = 1;
		}
	}
	if (ny - 1 >= 0) {
		if (!((Bit >> nx) & map[ny - 1]) && !(visited[ny - 1] & (Bit >> nx))) {
			if (find_short_way(nx, ny - 1, pway + 1)) k = 1;
		}
	}
	
	if (nx - 1 >= 0) {
		if (!((Bit >> nx - 1) & map[ny]) && !(visited[ny] & (Bit >> nx - 1))) {
			if (find_short_way(nx - 1, ny, pway + 1)) k = 1;
		}
	}
	visited[ny] -= Bit >> nx;
	SetColor(0, 15);
	point(nx, ny);
	cout << "  ";
	return k;
}
