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

void append (Array &arr, const int element) {
    /*
        - we can add new element at the end of the array if there is space available.
    */

    // Add element
    if (arr.length < arr.size) { // O(1)
        arr.A [arr.length] = element;
        arr.length++;
    } else {
        cout << "Array is full. Cannot add new element.\n";
    }
}

void insert (Array &arr, const int index, const int v) {
    /*
        - We can insert an element if the index is between 0 and the length of the array (inclusive).
        - We can insert an element if the length of the array is less than its size.
        - Best case (insert at the end): O(1)
        - Worst case: O(n)
    */

    if (
        index >= 0 &&
        index <= arr.length &&
        arr.length < arr.size
    ) {
       
        for (int i = arr.length; i > index; --i) {
            arr.A [i] = arr.A [i - 1];
        }

        arr.A [index] = v;
        arr.length++;

    } else {
        cout << "Insertion failed. Index is out of bounds or array is full." << endl;
    }
}

int main () {
    
    Array arr;
    arr.size = 10;
    arr.length = 3;
    arr.A = new int [arr.size] {43, 98, 13};

    if (arr.length > 0) {
        cout << "First element in the array: " << arr.A [0] << '\n';
    } else {
        cout << "Array is empty; there is no first element.\n";
    }

    cout << "Current array contents:\n";
    display (arr);


    cout << "Appending value 111 to the array.\n";
    append (arr, 111);
    display (arr);

    cout << "Inserting value 77 at index 1.\n";
    insert (arr, 1, 77);
    display (arr);

    delete [] arr.A;

    return 0;
}