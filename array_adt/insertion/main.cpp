#include <iostream>

using namespace std;

struct Array {
    int *A;
    int size;
    int length;
};

void display (Array &arr) {
    for (int i = 0; i < arr.length; i++) {
        cout << arr.A [i] << " ";
    }
    cout << endl;
}

void insert (Array &arr, int index, int v) {
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
    arr.A = new int [arr.size] {4, 2, 7};

    display (arr);
    
    insert (arr, 2, 111);
    
    display (arr);
    
    return 0;
}