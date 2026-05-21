#include <iostream>

using namespace std;

struct Array {
    int *A;
    int length;
    int size;
};

void display (Array &arr) {
    cout << "Array: ";
    if (arr.length) {
        for (int i = 0; i < arr.length; i++) {
            cout << arr.A [i] << ' ';
        } cout << '\n';
    }
    else {
        cout << "Empty!\n";
    }
}

void insertSort (Array &arr, const int v) {

    if (arr.length == arr.size) {
        cout << "Full array\n";
        return;
    }

    int i = arr.length - 1;

    while (i >= 0 && arr.A [i] > v) {
        arr.A [i + 1] = arr.A [i];
        i--;
    }

    arr.A [i + 1] = v;
    arr.length++;
}

bool is_sorted (const Array &arr, bool ascending= true) {
    if (arr.length <= 1) return true;
    if (ascending) {
        for (int i = 1; i < arr.length; i++) {
            if (arr.A [i] < arr.A [i - 1]) {
                return false;
            }
        }
        return true;
    }
    else {
        for (int i = 0; i < arr.length - 1; i++) {
            if (arr.A [i] < arr.A [i + 1]) {
                return false;
            }
        }
        return true;
    }
}

void negative_left_positive_right (Array &arr) {

    int i = 0, j = arr.length - 1;

    while (i < j) {

        while (i < arr.length && arr.A [i] < 0) {
            i++;
        }

        while (j >= 0 && arr.A [j] >= 0 && j >= 0) {
            j--;
        }

        if (i < j) {
            swap (arr.A [i], arr.A [j]);
        }

    }

}

int main () {

    Array arr;
    arr.size = 10;
    arr.length = 7;
    arr.A = new int [arr.size] {-1, 2, 3, 4, -1, -2, 1};

    display (arr);
    
    negative_left_positive_right (arr);
    
    display (arr);
    
    return 0;
}