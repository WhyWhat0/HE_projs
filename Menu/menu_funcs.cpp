#include "Header.h"
int menu1() {
	while(true){
		system("cls"); // ������� ������
		cout << "���� ������������ �����\n\n";
		cout << "�������� ������������ ������:\n\n";
		cout << "1) ������� 2.1 ���������� � ������� ������ \n\n";
		cout << "2) ������� 2.2. ������ ������ � �������� �������\n\n";
		cout << "3) ������� 3.1 ��������� ���������� �������� (�������)\n\n";
		cout << "4) ������� 3.2 ��������� ���������� ��������: � ���������� ���������\n\n";
		cout << "5) ������� 4. ��������� ������\n\n";
		cout << "0) ����� � ������� ���� \n\n";

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
			cout << "��������� ����. ������� ����� ������ ��� �����������...";
			system("pause");
			break;
		}
		/*if (i != 0) {
			cout << endl << "������� ����� ������ ��� �����������";
			 
		}*/
	}
}
int menu2() {
	while (true) {
		system("cls"); // ������� ������
		cout << "�������� ������������ ������:\n\n";
		cout << "1) ������� 5. ������� �����\n\n" ;
		cout << "2) ������� 6. ��������\n\n" ;
		cout << "0) ����� � ������� ����\n\n";
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
			cout << "��������� ����. ������� ����� ������ ��� �����������...";
			break;
		}
		/*if (i != 0) {
			cout << endl << "������� ����� ������ ��� �����������";
			_getch(); 
		}*/
	}
		
}