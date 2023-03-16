#include "lab7.h"

stRecursion RecData;

long double NextRec(double x, long double n,long double An, long double nSum) {
	An = pow(n, 3) - pow(An, 2) / pow(n, 2);	
	nSum = nSum + An;
	RecData.setRec[(int)n-1].IdSet = (int)n;
	RecData.setRec[(int)n-1].value1 = An;
	RecData.setRec[(int)n-1].value2 = nSum;

	/*(RecData.setRec + n)->IdSet = n;
	(*(RecData.setRec + n)).IdSet = n;*/

	if (n < 10) return NextRec(x, n + 1, An, nSum);
	return nSum;
}

void lab7() {
	cout << "������ ������������� ����������� �����������������\n";
	cout << "\t�� 20 ������� � ����������� �������������\n\n";

	double x = 1;
	cout << "��������� �������� x = 1";
	RecData.SetCount(10);
	RecData.setRec[0].IdSet = 1;
	RecData.setRec[0].value1 = x;
	RecData.setRec[0].value2 = 0;
	long double y = NextRec(x, 2, x, 0);
	printf("\n������� �������� �������� y=%f,\t��� x=%4f\n\n", y, x);
	cout << "N��\t  ���� ����\t ����������� ���������\n";
	for (int i = 0; i < RecData.count;i++) {
		cout << setw(4) << RecData.setRec[i].IdSet << setw(20) << RecData.setRec[i].value1
			<< setw(20) << RecData.setRec[i].value2 << endl;
	}
	cout << endl;
	system("pause");
}