#include "Header.h"
int menu1() {
	while(true){
		system("cls"); // очистка экрана
		cout << "Меню лабораторных работ\n\n";
		cout << "Выберите лабораторную работу:\n\n";
		cout << "1) Задание 2.1 Вычисления с выбором формул \n\n";
		cout << "2) Задание 2.2. Анализ данных и принятие решения\n\n";
		cout << "3) Задание 3.1 Обработка одномерных массивов (типовая)\n\n";
		cout << "4) Задание 3.2 Обработка одномерных массивов: с ветвлением алгоритма\n\n";
		cout << "5) Задание 4. Обработка матриц\n\n";
		cout << "0) Выход в главное меню \n\n";

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
			system("pause");
			break;
		}
		/*if (i != 0) {
			cout << endl << "Нажмите любую кнопку для продолжения";
			 
		}*/
	}
}
int menu2() {
	while (true) {
		system("cls"); // очистка экрана
		cout << "Выберите лабораторную работу:\n\n";
		cout << "1) Задание 5. Битовая маска\n\n" ;
		cout << "2) Задание 6. Лабиринт\n\n" ;
		cout << "0) Выход в главное меню\n\n";
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
			break;
		}
		/*if (i != 0) {
			cout << endl << "Нажмите любую кнопку для продолжения";
			_getch(); 
		}*/
	}
		
}