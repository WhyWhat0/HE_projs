#include "swap.h"

void lab_macros() {
	uchar c;
	do {
		CLEAR;
		c = _getch();
		cout << "������������ ������� �������� SWAP, MIN, MAX\n";

		cout << "SWAP, LOW, HIGH - ������� A(int), B(short), C(long long)\n";

		int a;
		short b;
		long long c;
		cin >> a >> b >> c;

		printf("A = %d\nB = %d\nC = %d\n\n", a, b, c);
		printf("A = %08x\nB = %04x\nC = %016x\n\n", a, b, c);
		printf("A (LOW) = %4x\nA (HIGH) = %4x\n\n", low(a), high(a));

		a = swap(a);
		b = swap(b);
		c = swap(c);
		cout << "����� SWAPa:\n";
		printf("A = %d\nB = %d\n\C = %d\n\n", a, b, c);
		printf("A = %08x\nB = %04x\nC = %016x\n\n", a, b, c);

		cout << "MIN - ������� A � B (float):\n";
		float k, d;
		cin >> k >> d;
		printf("\n����������� - %f", min(k, d));

		cout << "\n\nMAX - ������� A � B (float):\n";
		cin >> k >> d;
		printf("\n������������ - %f\n", max(k, d));
	} while (c != 27);
		PAUSE;

}