#include"Header.h" 

void lab5()
{
	srand(time(NULL));
	unsigned short l = 100, r = 32500, arr[20], mask;
	cout << "”словие задачи: вывести на экран все элементы массива, удовлетвор€ющие битовой маске" << endl;
	cout << "—генерированный массив: " << endl;
	for (int i = 0;i < 20;i++) {
		arr[i] = l + rand() % (r - l + 1);
		cout << arr[i] << " ";
	}
	cout << endl << "¬ведите маску" << endl;

	cin >> mask;
	cout << "Ёлементы массива, удовлетворющие условию: " << endl;

	for (int i = 0; i < 20; i++) {
		unsigned short col = arr[i] & mask;
		if (col == mask || col == arr[i]) cout << arr[i] << " ";
	}
	_getch();
}