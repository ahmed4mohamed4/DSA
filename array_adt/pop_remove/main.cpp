#include <iostream>
#include <algorithm>

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

void pop (Array &arr) { // O(1)
    if (arr.length > 0) {
        arr.length--;
    }
    else {
        cout << "It is empty!!\n";
    }
}

void remove_at (Array &arr, const int index) {

    // Best case: O(1) (removing the last element)
    // Worst case: O(n) 

    if (arr.length == 0) {
        cout << "It is empty!!!\n";
        return;
    }

    if (
        index >= 0 &&
        index < arr.length
    ) {
        for (int i = index; i < arr.length - 1; i++) { // O(n)
            arr.A [i] = arr.A [i + 1];
        }
        arr.length--;
    }
    else {
        cout << "Index out of range\n";
    }
}

int main () {
    
    Array arr;
    arr.size = 10;
    arr.length = 7;
    arr.A = new int [arr.size] {43, 98, 13, 20 ,11, 9384, 33};
    display (arr);

    cout << "Removing the last element from the array.\n";
    pop(arr);
    display(arr);

    cout << "Removing the element at index 2.\n";
    remove_at(arr, 2);
    display(arr);

    delete[] arr.A;

    return 0;
}