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

// A - B
struct Array difference_not_sorted_arrays (const Array &arr1, const Array &arr2) {

    /*
        O(n^2)
    */
    int k = 0;
    int n = arr1.length, m = arr2.length;

    Array arr3;
    arr3.size = arr1.size;
    arr3.length = k;
    arr3.A = new int [arr3.size];

    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < m; j++) {
                if (arr1.A [i] == arr2.A [j]) {
                    found = true;
                    break;
                }
        }
        if (!found) {
            arr3.A [k++] = arr1.A [i];
        }
    }

    arr3.length = k;

    return arr3;
}

// A - B
struct Array difference_sorted_arrays (const Array &arr1, const Array &arr2) {

    // O(m + n)
    // O(n)

    int i = 0, j = 0, k = 0;
    int n = arr1.length, m = arr2.length;

    Array arr3;
    arr3.size = arr1.size;
    arr3.length = k;
    arr3.A = new int [arr3.size];

    while (i < n && j < m) {

        if (arr1.A [i] == arr2.A [j]) {
            i++, ++j;
        }
        else if (arr1.A [i] < arr2.A [j]) {
            arr3.A [k++] = arr1.A [i++];
        }
        else {
            j++;
        }
    }
    while (i < n) {
        arr3.A [k++] = arr1.A [i++];
    }
    arr3.length = k;
    return arr3;
}
 
int main () {
    
    Array arr1 {new int [5] {3, 5, 10, 4, 6}, 5, 5};
    Array arr2 {new int [5] {12, 4, 7, 2, 5}, 5, 5};
    Array arr3 {new int [5] {}, 5, 0};

    arr3 = difference_not_sorted_arrays (arr1, arr2);

    display (arr3);

    cout << "\n---------------------------------\n";

    Array arr4 {new int [5] {3, 4, 5, 6, 10}, 5, 5};
    Array arr5 {new int [5] {2, 4, 5, 7, 12}, 5, 5};
    Array arr6 {new int [5] {}, 5, 0};

    arr6 = difference_sorted_arrays (arr4, arr5);

    display (arr6);

    delete [] arr1.A;
    delete [] arr2.A;
    delete [] arr3.A; 
    
    return 0;
}