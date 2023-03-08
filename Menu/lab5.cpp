#include"Header.h" 

void lab5()
{
	srand(time(NULL));
	unsigned short l = 100, // минимальый размер числа в битах
		r = 32500, // максимальный размер числа в битах
		arr[20], // массив случайных чисел
		mask; // маска 
	cout << "”словие задачи: вывести на экран все элементы массива, удовлетвор€ющие битовой маске" << endl;
	cout << "—генерированный массив: " << endl;
	for (int i = 0;i < 20;i++) { // заполнение массива случайными числами
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