#include "swap.h"

void lab_macros() {
	
	CLEAR;
	cout << "Демонстрация функций макросов SWAP, MIN, MAX\n\n";

	cout << "SWAP, LOW, HIGH - Введите A(int), B(short), C(long long)\n\n";

	int a = 0x14b2'3431;
	short b = 0x1c24;
	unsigned long long  c = 0x12a3'd445'56b7'7889;
	//cin >> a >> b >> c;
	printf("A = %d\nB = %d\nC = %lld\n\n", a, b, c);
	printf("A = %04x\nB = %02x\nC = %08llx\n\n", a, b, c);
	printf("A (LOW) = %04x\nA (HIGH) = %04x\n\n", low(a), high(a));
	printf("B (LOW) = %0hx\nB (HIGH) = %0hx\n\n", luw(b), high(b));
	printf("C (LOW) = %08llx\nC (HIGH) = %08llx\n\n", low(c), high(c));

	a = swap_int(a);
	b = swap_short(b);
	c = swap_long(c);

	cout << "\nПосле SWAPa:\n\n";
	printf("A = %d\nB = %d\n\C = %08.16llx\n\n", a, b, c);
	printf("A = %08x\nB = %04x\nC = %08.16llx\n\n", a, b, c);

	cout << "MIN - Введите A и B (float):\n";
	float k, d;
	cin >> k >> d;
	printf("\nМинимальное - %f", min(k, d));

	cout << "\n\nMAX - Введите A и B (float):\n";
	cin >> k >> d;
	printf("\nМаксимальное - %f\n", max(k, d));
	
	PAUSE;

}