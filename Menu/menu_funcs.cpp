#include "Header.h"

int menu1() {
	while(true){
		system("cls"); // очистка экрана
		cout << "Выберите лабораторную работу:" << endl << endl;
		cout << "1) Задание 2.1 Вычисления с выбором формул" << endl << endl;
		cout << "2) Задание 2.2. Анализ данных и принятие решения" << endl << endl;
		cout << "3) Задание 3.1 Обработка одномерных массивов (типовая)" << endl << endl;
		cout << "4) Задание 3.2 Обработка одномерных массивов: с ветвлением алгоритма" << endl << endl;
		cout << "5) Задание 4. Обработка матриц" << endl << endl;
		cout << "0) Выход в главное меню" << endl;

		int i;
		cin >> i;
		system("cls");
		switch (i) {
		case 1:
			lab2_1(); break;
		case 2:
			lab2_2(); break;
		case 3:
			lab3_1(); break;
		case 4:
			lab3_2(); break;
		case 5:
			lab4(); break;
		case 0:
			return 0;
		default:
			cout << "Ошибочный ввод. Нажмите любую кнопку для продолжения...";
		}
		if (i != 0) {
			cout << endl << "Нажмите любую кнопку для продолжения";
			_getch(); //условие для возвращения в исходное меню
		}
	}
}
int menu2() {
	while (true) {
		system("cls"); // очистка экрана
		cout << "Выберите лабораторную работу:" << endl << endl;
		cout << "1) Задание 5. Битовая маска" << endl << endl;
		cout << "2) Задание 6. Лабиринт" << endl << endl;
		cout << "0) Выход в главное меню" << endl << endl;
		int i;
		cin >> i;
		system("cls");
		switch (i) {
		case 1:
			lab5(); break;
		case 2:
			lab6(); break;
		case 0:
			return 0;
		default:
			cout << "Ошибочный ввод. Нажмите любую кнопку для продолжения...";
		}
		if (i != 0) {
			cout << endl << "Нажмите любую кнопку для продолжения";
			_getch(); //условие для возвращения в исходное меню
		}
	}
		
}