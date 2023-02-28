#include<iostream>
#include<cmath>
#include<algorithm>
#include<string>

using namespace std;

void task_1(double A, double B) {
    double N1, N2, N3;
    N1 = (A - B) / pow(A + B, 2);
    cout << N1 << endl;
    N2 = pow(pow(A, 2) + pow(B, 2), 0.5)/(1.5*A*B);
    cout << N2 << endl;
    N3 = sin(N1) + N2;
    cout << N3 << endl;
}

void task_2(double a1, double a2, double c) {
    double b = a1 > a2 ? (a1 + a2) / c : (a2 - a1) / 2;
    double d = a1 > a2 ? (a1 + a2) * c : (a2 - 1) * 2;
    double N = a1 > a2 ? 1 : 2;
    cout << b << " " << d << " " << N << endl;

}

void task_3(string a, string b, string c) {
    char w[] = { 'A', 'E', 'Y', 'U', 'I', 'O' };
    for (auto word : w) {
        if (a[0] == word) cout << "first \n";
        if (b[0] == word) cout << "second \n";
        if (c[0] == word) cout << "third \n";
    }
}

double* task_4(double K[]) {
    double num = 0, C[10]{ 0 };
    for (int i = 0; i < 10; i++) num = num + K[i];
    //cout << pow(abs(K[i]), 0.5) << endl;
    for (int i = 0; i < 10; i++) {
        C[i] = num / pow(abs(K[i]), 0.5);
        cout << C[i] << " ";
    }
    return C;
}
int main()
{
    double k[10] = { 1,2,3,4,5,6,7,8,9,10 };
    double *p = task_4(k);
    for (int i = 0; i < 10; i++) cout << p[i] << endl;
    return 0;
}

