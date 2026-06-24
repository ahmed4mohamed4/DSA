#include <iostream>
#include <array>

using namespace std;

int main () {

    const int N = 5;
    
    int lower_triangular [N][N] = {
        {1, 0, 0, 0, 0},
        {7, 2, 0, 0, 0},
        {3, 4, 8, 0, 0},
        {2, 5, 3, 5, 0},
        {1, 1, 9, 3, 6}
    }; // 5 x 5 matrix

    const int SIZE = N * (N + 1) / 2;

    array <int, SIZE> arr {};

    // Row major order
    int k = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            arr [k++] = lower_triangular [i][j];
        }
    }

    // Display
    for (const int x : arr) {
        cout << x << ' ';
    } cout << '\n';
    
    arr = {}; // 0s
    k = 0;

    // Column major order
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            arr [k++] = lower_triangular [j][i];
        }
    }

    
    // Display
    for (const int x : arr) {
        cout << x << ' ';
    } cout << '\n';

    return 0;
}