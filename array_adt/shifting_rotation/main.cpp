#include <iostream>

using namespace std;

struct Array {
    int *A;
    int length;
    int size;
};

void display (const Array &arr) {
    cout << "array: ";
    if (arr.length) {
        for (int i = 0; i < arr.length; i++) {
            cout << arr.A [i] << ' ';
        } cout << '\n';
    }
    else {
        cout << "Empty!\n";
    }
}

void shift_left (Array &arr) {
    if (arr.length > 0) {
        for (int i = 0; i < arr.length - 1; i++) {
            arr.A [i] = arr.A [i + 1];
        }
        arr.A [arr.length - 1] = 0;
    }
}

void left_rotation (Array &arr) {
    // 2 3 4 5 6 7 8 9
    // 3 4 5 6 7 8 9 2

    if (arr.length > 1) {
        int temp = arr.A [0];
        for (int i = 0; i < arr.length - 1; i++) {
            arr.A [i] = arr.A [i + 1];
        }
        arr.A [arr.length - 1] = temp;
    }
}

void shift_right (Array &arr) {
    if (arr.length > 0) {
        for (int i = arr.length - 1; i >= 1; i--) {
            arr.A [i] = arr.A [i - 1];
        }
        arr.A [0] = 0;
    }
}

void right_rotation (Array &arr) {
    if (arr.length > 0) {
        int temp = arr.A [arr.length - 1];
        for (int i = arr.length - 1; i >= 1; i--) {
            arr.A [i] = arr.A [i - 1];
        }
        arr.A [0] = temp;
    }
}

int main () {

    Array arr;
    arr.size = 10;
    arr.length = 5;
    arr.A = new int [arr.size] {1, 2, 3, 4, 5};

    display (arr);

    // shift_left (arr);
    // left_rotation (arr);
    // shift_right (arr);
    right_rotation (arr);
    
    display (arr);

    delete [] arr.A;
    
    return 0;
}