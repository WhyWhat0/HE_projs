#include "lab7.h"
stRecursion RecData;

double NextRec(double x, int n, double An, double nSum) {
	An = (n == 1) ? An * x * x / n : An * (n - 1) * x * x / n;
	nSum = nSum + An;
	RecData.setRec[n-1].IdSet = n;
	RecData.setRec[n-1].value1 = An;
	RecData.setRec[n-1].value2 = nSum;

	/*(RecData.setRec + n)->IdSet = n;
	(*(RecData.setRec + n)).IdSet = n;*/

	if (n < 20) return NextRec(x, n + 1, An, nSum);
	return nSum;
}
void lab7() {
	cout << "Расчет рекуррентного соотношения последоваельности\n";
	cout << "\tиз 20 членовб с последующим суммированием\n\n";

	double x;
	cout << "Введите начальное згачение x: "; cin >> x;
	RecData.SetCount(20);
	double y = NextRec(x, 1, 1, 0);

	printf("\nвывести конечные значения y=%f,\tпри x=%4f\n\n", y, x);
	cout << "Nпп\t  чден ряда\t накопленное значчение\n";
	for (int i = 0; i < RecData.count;i++) {
		cout << setw(4) << RecData.setRec[i].IdSet << setw(20) << RecData.setRec[i].value1
			<< setw(20) << RecData.setRec[i].value2 << endl;
	}
	cout << endl;
	_getch();
}