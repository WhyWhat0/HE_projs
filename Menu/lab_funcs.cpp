#include "Header.h"

int _max(int a, int b, int c, int& k) { //функция вычисления максимального значения из трех переменных
	int m;
	if (a > b) {
		m = a;k = 1;
	}
	else {
		m = b;k = 2;
	}
	if (c > m) {
		m = c;k = 3;
	}
	return m;
}
int _min(int a, int b, int c, int& k) { //функция вычисления минимального значения из трех переменных
	int m;
	if (a < b) {
		m = a;k = 1;
	}
	else {
		m = b;k = 2;
	}
	if (c < m) {
		m = c;k = 3;
	}
	return m;
}
float f(float a, float x, float k) { //функция вычисления значения Y
	if (x < k * a) {
		return -pow(abs(16 * pow(a, 2) + 4 * pow(a, 2) \
			* pow(x + a, 2)), 0.5) - pow(x + a, 2) - pow(a, 2);
	}
	return pow(abs(pow(a, 2) - (x + pow(a, 2))), 0.5) - 2 * a;
}

void lab2_1()
{
	float b1 = 0, b2 = 0, b3 = 0;
	int i1 = 0, i2 = 0, a = 1; //индексы переменных
	cout << "Развлетвленный алгоритм с выбором формул" << endl;
	cout << "Введите данные в виде трех целых чисел:" << endl;
	cin >> b1 >> b2 >> b3;
	if (b1 == b2 && b2 == b3) {
		cout << "Нет решения";
		exit(1);
	}
	//вывод ответа 
	cout << "Ответ:" << endl;
	float bmin = _min(b1, b2, b3, i1);
	cout << "bmin = " << bmin << ", index = " << i1 << endl;
	float bmax = _max(b1, b2, b3, i2);
	cout << "bmax = " << bmax << ", index = " << i2 << endl;
	float bmid = (b1 + b2 + b3) / 3;
	cout << "bсреднее = " << round(bmid * 100) / 100 << endl;
	float d = bmax - bmin;
	float d1 = abs(b1 - bmid); float d1_c = d1 / (bmax - bmin) * 100;
	cout << "Отклонение и соотношение b1: " << round(d1 * 100) / 100 << ", " << round(d1_c * 100) / 100 << "%" << endl;
	float d2 = abs(b2 - bmid); float d2_c = d2 / (bmax - bmin) * 100;
	cout << "Отклонение и соотношение b2: " << round(d2 * 100) / 100 << ", " << round(d2_c * 100) / 100 << "%" << endl;
	float d3 = abs(b3 - bmid); float d3_c = d3 / (bmax - bmin) * 100;
	cout << "Отклонение и соотношение b3: " << round(d3 * 100) / 100 << ", " << round(d3_c * 100) / 100 << "%" << endl;

}
void lab2_2()
{
	int C, F, H;
	int a = 1; // проверка состояния программы
	cout << "Развлетвленный алгоритм с анализом исходных данных и принтием решения" << endl;
	while (a == 1) { // цикл повтора запуска программы
		cout << "Введите данные в виде трех целых чисел:" << endl;
		cin >> C >> F >> H;
		if (C == F && F == H) {
			cout << "Нет вариантов" << endl;
		}
		//вывод ответа в зависимости от условия
		else if (C == pow(F - H, 2)) {
			cout << "Ответом является число " << C << endl;
		}
		else if (F == pow(C - H, 2)) {
			cout << "Ответом является число " << F << endl;
		}
		else if (H == pow(C - F, 2)) {
			cout << "Ответом является число " << H << endl;
		}
		else {
			cout << "Нет вариантов" << endl;
		}
		cout << endl << "Хотите продолжить?" << endl << "Да: введите 1" << endl << "Нет: введите 0" << endl;
		cin >> a;
		if (a == 0) cout << endl << "Программа завершила работу.";
	}
}
void lab3_1()
{
	cout << "Циклический алгоритм с несколькими параметрами и проверкой условий" << endl;
	cout << "Введите числа N, A, K:" << endl;
	float a, k;
	unsigned int n;
	cin >> n >> a >> k;
	// вычисление начальных значений
	float x = a * (-2.2);
	float dx = 0.4;
	//вывод ответа
	cout << right << "N" << setw(10) << "X" << setw(10) << "Y" << endl;
	for (int i = 0; i < 27; i++) {
		cout << "_";
		if (i == 26) cout << endl;
	}
	for (int i = 0;i < n;i++) {
		cout << left << setw(10) << i + 1 << setw(10) << round(x * 10) / 10 \
			<< setw(10) << round(f(a, x, k) * 1000) / 1000 << endl;
		x += dx;
	}
}
void lab3_2()
{
	int  i = 0;
	float sum = 0, A, y[12], F[sizeof(y)];
	cout << "Циклический алгоритм обработки одномерного массива" << endl;
	cout << "Введите данные массива  в виде целых чисел: " << endl;
	sum = 0;
	for (i = 0;i < 12;i++) {
		do { //проверка на равенство значения нулю
			cout << "Введите ненулевое значение" << i + 1 << "/12 число" << endl;
			cin >> y[i];
		} while (y[i] == 0);
		sum += (1 - y[i]) / pow(y[i], 2); // сумма элементов массива y      
	}
	sum = round(sum * 100) / 100;
	for (i = 0; i < 12; i++) {// вычисление нового массива
		A = y[i] > 2 ? 3 : 2;
		F[i] = sum + A * y[i];
	}
	int Fmin = F[0], Fmax = F[0];
	for (i = 1;i < 12;i++) { // вычисление максимального и минимального значения в массиве
		Fmin = Fmin < F[i] ? Fmin : F[i];
		Fmax = Fmax > F[i] ? Fmax : F[i];
	}
	cout << "Новый массив F: ";
	for (i = 0;i < 12;i++) { //вывод массива F
		cout << F[i] << " ";
	}
	unsigned int l = 0; //размер массива F включая условия
	cout << endl << "Включая условия: ";
	for (i = 0;i < 12;i++) { //вывод массива F включая условия
		if (F[i] <= (Fmin + Fmax) / 2) {
			l++;
			cout << F[i] << " ";
		}
	}
	cout << endl << "Количество чисел, подчиняющиеся условиям: " << l;
}
void lab4()
{
	const int ROW = 6, COL = 6;
	cout << "Циклический алагоритм обработки матрицы" << endl;
	float x[ROW][COL]; //исходная матрица
	bool ch[COL]; //массив для хранения номеров измененных столбцов
	int i, j, count, prod;
	cout << "Заполните матрицу размером " << ROW << "x" << COL << endl;
	for (j = 0;j < COL;j++) {
		ch[j] = false;
	}
	//ввод матрицы
	for (i = 0;i < ROW;i++) {
		for (j = 0;j < COL;j++) {
			cin >> x[i][j];
		}
	}
	//вывод исходной матрицы
	cout << endl << "Результаты" << endl << endl;
	cout << "Исходная матрица" << endl;
	for (i = 0;i < ROW;i++) {	// вывод изначальной матрицы
		for (j = 0;j < COL;j++) {
			cout << right << setw(6) << x[i][j];
		}
		cout << endl;
	}
	cout << endl;
	//вычисление значений
	for (j = 1;j < COL;j += 2) {
		prod = 1; count = 0;
		for (i = 0;i < ROW;i++) {
			if (x[i][j] < 0) {
				count++;
				prod *= x[i][j];
			}
		}

		cout << "Произведение и количество отрицательных чисел столбца " << j + 1 << ": " << prod << " " << count << endl << endl;
		if (prod < 0) ch[j] = true;
	}
	//вывод измененных столбцов
	cout << "Матрица на выходе -> номера измененных столбцов: "; //вывод номеров измененных столбцов
	for (j = 0;j < COL;j++) {
		if (ch[j]) cout << j + 1 << " ";
	}
	cout << endl;
	//вывод конечной матрицы
	for (i = 0;i < ROW;i++) {
		for (j = 0;j < COL;j++) {
			if (ch[j]) x[i][j] = 0;
			cout << right << setw(6) << x[i][j];
		}
		cout << endl;
	}
}


