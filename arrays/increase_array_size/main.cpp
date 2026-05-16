#include <iostream>

using namespace std;

int main () {

    const int SIZE1 = 5, SIZE2 = 10;

    int *p = new int [SIZE1];
    p [0] = 33;
    p [1] = 44;
    p [2] = 55;
    p [3] = 66;
    p [4] = 77;
    int *q = new int [SIZE2]; // larger size

    for (int i = 0; i < SIZE1; i++) {
        q [i] = p [i];
    }

    delete [] p;
    p = q;
    q = nullptr;

    for (int i = 0; i < SIZE1; i++) {
        cout << p [i] << ' ';
    } cout << '\n';
    

    return 0;
}