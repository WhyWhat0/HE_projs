#include "swap.h"

void lab_macros() {
	cout << "������������ ������� �������� SWAP, MIN, MAX\n";
	
	cout << "SWAP, LOW, HIGH - ������� A(int), B(short)";

	int a;
	short b;
	cin >> a >> b;

	printf("A = %d\nB = %d\n\n", a, b);
	printf("A = %08x\nB = %04x\n\n", a, b);
	printf("A (LOW) = %04x\nA (HIGH) = %04x\n\n", low(a), high(a));

	a = swap(a);
	b = swap(b);

	cout << "����� SWAPa:\n";
	printf("A = %d\nB = %d\n\n", a, b);
	printf("A = %08x\nB = %04x\n\n", a, b);

	cout << "MIN - ������� A � B (float):\n";
	float c, d;
	cin >> c >> d;
	printf("\n����������� - %f", min(c, d));

	cout << "\n\nMAX - ������� A � B (float):\n";
	cin >> c >> d;
	printf("\n������������ - %f\n", max(c, d));

	system("pause");
}