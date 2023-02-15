#include "Header.h" //Заголовки функций для лабораторных работ

int main(){
	int i; // для выбора пункта меню
	setlocale(LC_ALL, "Russian");
	while (true) {
		system("cls"); // очистка экрана
		cout << "Выполнил студент группы 1бИТС2 Долгов Семен Вадимович  \n\n";
		cout << "Выберите лабораторную работу:\n\n";
		cout << "1) 1 семестр\n\n";
		cout << "2) 2 семестр \n\n";
		cout << "0) Выход из программы \n\n";
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
			break;
		}		
	}
} 



