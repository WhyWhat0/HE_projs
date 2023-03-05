#include <iostream>
using namespace std;

void towerOfHanoi(int n, char from_rod, char to_rod,
    char aux_rod)
{
    cout << n << endl;

    if (n == 0) {
        return;
    }
    towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
    cout << "Move disk " << n << " from rod " << from_rod
        << " to rod " << to_rod << endl;
    towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
}

// Driver code
int main()
{
    int N = 5;

    // A, B and C are names of rods
    towerOfHanoi(N, '1', '3', '2');
    return 0;
}