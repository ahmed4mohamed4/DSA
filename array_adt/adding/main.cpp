#include <iostream>

using namespace std;

struct Array {
    int *a;
    int size;
    int length;
};


void display_array (int arr [], int length) {
    for (int i = 0; i < length; i++) {
        cout << arr [i] << ' ';
    } cout << '\n';
}

void append (Array &arr, int element) {
    /*
        - we can add new element at the end of the array if there is space available.
    */

    // Add element
    if (arr.length < arr.size) { // O(1)
        arr.a [arr.length] = element;
        arr.length++;
    } else {
        cout << "Array is full. Cannot add new element.\n";
    }
}

int main () {

    struct Array arr;
    arr.size = 20;
    arr.length = 3;
    arr.a = new int [arr.size] {1, 2, 3};

    display_array (arr.a, arr.length);

    append (arr, 99);

    display_array (arr.a, arr.length);

    delete [] arr.a;

    
    return 0;
}