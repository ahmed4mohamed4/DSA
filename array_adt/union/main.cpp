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

// Union two not sorted array
struct Array union_not_sorted_arrays (const Array &arr1, const Array &arr2) {
    /*
        - Time complexity:
            m + (m * n)
            n + (n * n)
            n + n ^ 2
            O (n ^ 2)
    */
    int k = 0;
    int m = arr1.length, n = arr2.length;

    Array arr3;
    arr3.size = m + n;
    arr3.length = 0;
    arr3.length = k;
    arr3.A = new int [arr3.size];

    for (int i = 0; i < m; i++) {
        arr3.A [k++] = arr1.A [i];
    }

    for (int i = 0; i < n; i++) {
        bool found = false;

        for (int p = 0; p < k; p++) {
            if (arr2.A [i] == arr3.A [p]) {
                found = true;
                break;
            }
        }

        if (!found) {
            arr3.A [k++] = arr2.A [i];
        }
    }

    arr3.length = k;
    return arr3;
}

// Union two sorted array
struct Array union_sorted_arrays (const Array &arr1, const Array &arr2) {
    /*
        - Time complexity:
            O(m + n)
            O(n + n)
            O(2n)
            O(n)
    */
    int i = 0, j = 0, k = 0;
    int n = arr1.length, m = arr2.length;
    Array arr3;
    arr3.size = n + m;
    arr3.length = k;
    arr3.A = new int [arr3.size];

    while (i < n && j < m) {
        if (arr1.A [i] < arr2.A [j]) {
            arr3.A [k++] = arr1.A [i++];
        }
        else if (arr1.A [i] > arr2.A [j]) {
            arr3.A [k++] = arr2.A [j++]; 
        }
        else {
            arr3.A [k++] = arr2.A [j++];
            i++;
        }
    }

    for (; i < n; i++) {
        arr3.A [k++] = arr1.A [i];
    }

    for (; j < m; j++) {
        arr3.A [k++] = arr2.A [j];
    }

    arr3.length = k;
    return arr3;
}

int main () {
    
    Array arr1, arr2, arr3;
    arr1.size = 5;
    arr1.length = 5;
    arr1.A = new int [arr1.size] {3, 5, 10, 4, 6};
    
    arr2.size = 5;
    arr2.length = 5;
    arr2.A = new int [arr2.size] {12, 4, 7, 2, 5};
    
    arr3.size = 10;
    arr3.length = 10;
    arr3.A = new int [arr3.size];

    arr3 = union_not_sorted_arrays (arr1, arr2);

    display (arr3);


    cout << "\n========================================\n";

    Array arr4, arr5, arr6;
    arr4.size = 5;
    arr4.length = 5;
    arr4.A = new int [arr4.size] {3, 4, 5, 6, 10};
    
    arr5.size = 5;
    arr5.length = 5;
    arr5.A = new int [arr5.size] {2, 4, 5, 7, 12};
    
    arr6.size = 10;
    arr6.length = 10;
    arr6.A = new int [arr6.size];

    arr6 = union_sorted_arrays (arr4, arr5);

    display (arr6);

    delete [] arr1.A;
    delete [] arr2.A;
    delete [] arr3.A;

    delete [] arr4.A;
    delete [] arr5.A;
    delete [] arr6.A;

    return 0;
}