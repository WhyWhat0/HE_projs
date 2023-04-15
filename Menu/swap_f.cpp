#include "swap.h"

void lab_macros() {
	cout << "Демонстрация функций макросов SWAP, MIN, MAX\n";
	
	cout << "SWAP, LOW, HIGH - Введите A(int), B(short), C(long long)\n";

	int a;
	short b;
	long long int c;
	cin >> a >> b >> c;

	printf("A = %d\nB = %d\nC = %d\n\n", a, b, c);
	printf("A = %08x\nB = %04x\nC = %016x\n\n", a, b, c);
	printf("A (LOW) = %04x\nA (HIGH) = %x\n\n", low(a), high(a));

	a = swap_int(a);
	b = swap_sh(b);
	c = swap_long(c);
	cout << "После SWAPa:\n";
	printf("A = %d\nB = %d\n\C = %d\n\n", a, b, c);
	printf("A = %08x\nB = %04x\nC = %llu\n\n", a, b, c);

	cout << "MIN - Введите A и B (float):\n";
	float k, d;
	cin >> k >> d;
	printf("\nМинимальное - %f", min(k, d));

	cout << "\n\nMAX - Введите A и B (float):\n";
	cin >> k >> d;
	printf("\nМаксимальное - %f\n", max(k, d));

	system("pause");
}