
#include <iostream>


using namespace std;

int main () {


    const int ROW = 5;
    const int COL = 5;
    
    int diagonal_matrix [ROW][COL] = {
        {1, 0, 0, 0, 0},
        {0, 7, 0, 0, 0},
        {0, 0, 4, 0, 0},
        {0, 0, 0, 9, 0},
        {0, 0, 0, 0, 2},
    };

    const int SIZE = min (ROW, COL);

    int arr [SIZE] = {}; // All 0s

    for (int i = 0; i < SIZE; i++) {
        arr [i] = diagonal_matrix [i][i];
    }

    for (const int &x : arr) {
        cout << x << ' ';
    }

    cout << '\n';

    return 0;
}