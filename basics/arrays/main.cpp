#include <iostream>

using namespace std;

void PrintSeparator () { cout << "\n---------------------------------------\n";}

int main () {

    int A [] = {1, 2, 3, 4, 5};

    cout << sizeof (A) << '\n'; // Integer 4 Bytes and the array contain 5 elements so the size = 5 * 4 = 20
    for (const int &x : A) {
        cout << x << ' ';
    }

    PrintSeparator ();

    int B [10] = {1, 2, 3, 4, 5, 6, 7, 8};
    printf ("Value in index 8: %d | Value in index 9: %d\n", B [8], B [9]);

    PrintSeparator ();

    int C [3];
    printf ("Value in the index 1: %d\n", C [1]); // Garbage values

    PrintSeparator ();

    int D [4] = {};
    for (const int n : D) {
        cout << n << ' ';
    }

    PrintSeparator ();

    // Dynamic arrays
    int *pointer = new int [3];
    pointer [0] = 10; pointer [1] = 11; pointer [2] = 12;
    for (int i = 0; i < 3; ++i) {
        cout << pointer [i] << ' ';
    }

    delete [] pointer; // Free the memory allocated for the dynamic array

    return 0;
}