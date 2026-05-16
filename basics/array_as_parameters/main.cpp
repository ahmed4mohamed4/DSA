#include <iostream>

using namespace std;

// void fun (int A [], int n) {
//     for (int i = 0; i < n; i++) {
//         cout << A [i] << ' ';
//     }
//     cout << '\n';
// }
// Also we can do this
//           ⬇️
void fun (int *A, int n) {
    for (int i = 0; i < n; i++) {
        cout << A [i] << ' ';
    }
    cout << '\n';
}

int* give_arr (int n) {

    int *A = new int [n];

    for (int i = 0; i < n; i++) {
        A [i] = i + 1;
    }

    return A; 

}

void PrintSeparator () {
    cout << "\n--------------------------------\n";
}

int main () {

    int A [] = {2, 4, 6, 8, 10};

    fun (A, 5); // Array can pass only by address.

    PrintSeparator ();

    int *B = give_arr (5);


    for (int i = 0; i < 5; i++) {
        cout << B [i] << ' ';
    }

    delete [] B;

    return 0;
}



