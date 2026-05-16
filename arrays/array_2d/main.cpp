#include <iostream>

using namespace std;


void PrintSeparator () { cout << "\n---------------------------------------\n"; }

int main () {

    // way 1 to do 2D array

    const int ROW = 3, COL = 3;

    int arr [ROW][COL] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    for (int i = 0; i < ROW; ++i) {
        for (int j = 0; j < COL; j++) {
            cout << arr [i][j] << ' ';
        } cout << '\n';
    }

    PrintSeparator ();

    
    // way 2 to do 2D array

    int *a [3]; // 3 pointers
    // each one point to array

    a [0] = new int [3];
    a [0][0] = 1;
    a [0][1] = 2;
    a [0][2] = 3;

    a [1] = new int [3];
    a [1][0] = 4;
    a [1][1] = 5;
    a [1][2] = 6;

    a [2] = new int [3];
    a [2][0] = 7;
    a [2][1] = 8;
    a [2][2] = 9;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << a [i][j] << ' ';
        } cout << '\n';
    }
    for (int i = 0; i < 3; i++)
        delete [] a[i];
    PrintSeparator ();
    
    // way 3 to do 2D array
    
    int **ar;
    
    ar = new int * [3];
    
    ar [0] = new int [3];
    ar [1] = new int [3];
    ar [2] = new int [3];

    // assign values
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            ar [i][j] = i * 3 + j + 1;
        }
    }
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << ar [i][j] << ' ';
        } cout << '\n';
    }

    for (int i = 0; i < 3; i++)
        delete[] ar[i];


    delete[] ar;

    return 0;
}