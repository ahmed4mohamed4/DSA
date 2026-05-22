#include <iostream>

using namespace std;

struct Array {
    int *A;
    int size;
    int length;
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

// (arr1, arr2) -> need to merge
struct Array merge (const Array &arr1, const Array &arr2) {
    int i = 0, j = 0, k = 0;
    int n = arr1.length, m = arr2.length;
    
    Array arr3;
    arr3.size = arr1.length + arr2.length;
    arr3.length = n + m;
    arr3.A = new int [arr3.size];

    while (i < n && j < m) {
        if (arr1.A [i] <= arr2.A [j]) {
            arr3.A [k++] = arr1.A [i++];
        }
        else {
            arr3.A [k++] = arr2.A [j++];
        }
    }

    for (; i < n; i++) {
        arr3.A [k++] = arr1.A [i];
    }
    for (; j < m; j++) {
        arr3.A [k++] = arr2.A [j];
    }

    return arr3;
}

int main () {
    
    Array arr1;
    arr1.size = 5;
    arr1.length = 3;
    arr1.A = new int [arr1.size] {1, 2, 3};
    
    Array arr2;
    arr2.size = 5;
    arr2.length = 3;
    arr2.A = new int [arr2.size] {4, 5, 6};

    Array arr3;
    arr3.size = 10;
    arr3.length = 6;

    arr3 = merge (arr1, arr2);

    display (arr3);

    return 0;
}