#include"Header.h" 

void lab5()
{
	srand(time(NULL));
	unsigned short l = 100, r = 32500, arr[20], mask;
	cout << "������� ������: ������� �� ����� ��� �������� �������, ��������������� ������� �����" << endl;
	cout << "��������������� ������: " << endl;
	for (int i = 0;i < 20;i++) {
		arr[i] = l + rand() % (r - l + 1);
		cout << arr[i] << " ";
	}
	cout << endl << "������� �����" << endl;

	cin >> mask;
	cout << "�������� �������, �������������� �������: " << endl;

	for (int i = 0; i < 20; i++) {
		unsigned short col = arr[i] & mask;
		if (col == mask || col == arr[i]) cout << arr[i] << " ";
	}
	_getch();
}