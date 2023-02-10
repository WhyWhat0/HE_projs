#include "Header.h" //Заголовки функций для лабораторных работ

int main(){
	system("color F0");
	int i; // для выбора пункта меню
	setlocale(LC_ALL, "Russian");
	while (true) {
		system("cls"); // очистка экрана
		cout << "Выполнил студент группы 1бИТС2 Долгов Семен Вадимович" << endl << endl;
		cout << "Выберите лабораторную работу:" <<endl << endl;
		cout << "1) 1 семестр" << endl << endl;
		cout << "2) 2 семестр" << endl << endl;
		cout << "0) Выход из программы" << endl;
		cin >> i;
		system("cls");
		switch (i){ // управление выбором в меню
		case 1:
			menu1(); break;			
		case 2:
			menu2(); break;			
		case 0: 
			return 0;
		default:
			cout << "Ошибочный ввод. Нажмите любую кнопку для продолжения...";
		}		
	}
} 



