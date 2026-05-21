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

int linear_search (Array &arr, const int key) {
    // Best case: O(1) (if the key is at the first position)
    // Worst case: O(n)
    /*
        Average case: 
            1 + 2 + 3 + 4 + ... + n / n
            (n (n + 1) / 2) / n
            (n + 1) / 2
            O((n + 1) / 2)
    */
    for (int i = 0; i < arr.length; i++) {
        if (arr.A [i] == key) return i;
    }
    return -1;
}

void swap (int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

int improve_linear_search_transposition (Array &arr, const int key) {
    for (int i = 0; i < arr.length; i++) {
        if (arr.A [i] == key) {
            if (i > 0) {
                swap (arr.A [i], arr.A [i - 1]); // Transposition
                return i - 1;
            }
            return i;
        }
    }
    return -1;
}

int improve_linear_search_move_to_front (Array &arr, const int key) {
    for (int i = 0; i < arr.length; i++) {
        if (arr.A [i] == key) {
            swap (arr.A [i], arr.A [0]); // Move to front
            return 0;
        }
    }
    return -1;
}

int binary_search (Array &arr, const int key) { // O(log(n + 1)) => O(log n)
    int low = 0;
    int high = arr.length - 1;
    int mid = 0;

    while (low <= high) {
        mid = (low + high) / 2;

        int num = arr.A [mid];

        if (num == key) {
            return mid;
        }
        else if (num < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return -1;
}

int binary_search_using_recursion (Array &arr, const int key, int low, int high) {
    int mid = (low + high) / 2;

    if (low <= high) {
        if (arr.A [mid] == key) {
            return mid;
        }
        else if (arr.A [mid] > key) {
            return binary_search_using_recursion (arr, key, low, mid - 1);
        }
        else {
            return binary_search_using_recursion (arr, key, mid + 1, high);
        }
    }

    return -1;
}

int main () {
    
    Array arr;
    arr.size = 10;
    arr.length = 3;
    arr.A = new int [arr.size] {43, 98, 13};

    cout << "Linear search for value 13:\n";
    int the_search = linear_search (arr, 13);
    if (the_search == -1) {
        cout << "Value 13 not found.\n";
    } else {
        cout << "Value 13 found at index " << the_search << ".\n";
    }

    cout << "Improved linear search (transposition) for value 13:\n";
    int the_search2 = improve_linear_search_transposition(arr, 13);
    if (the_search2 == -1) {
        cout << "Value 13 not found.\n";
    } else {
        cout << "Value 13 found at index " << the_search2 << ".\n";
    }

    cout << "Improved linear search (move to front) for value 13:\n";
    int the_search3 = improve_linear_search_move_to_front(arr, 13);
    if (the_search3 == -1) {
        cout << "Value 13 not found.\n";
    } else {
        cout << "Value 13 found at index " << the_search3 << ".\n";
    }

    struct Array ar;
    ar.size = 10;
    ar.length = 3;
    ar.A = new int[ar.size]{12, 27, 32};

    cout << "Binary search for value 27:\n";
    int x = binary_search(ar, 27);
    if (x == -1) {
        cout << "Value 27 not found.\n";
    } else {
        cout << "Value 27 found at index " << x << ".\n";
    }

    cout << "Binary search using recursion for value 32:\n";
    int y = binary_search_using_recursion(ar, 32, 0, ar.length - 1);
    if (y == -1) {
        cout << "Value 32 not found.\n";
    } else {
        cout << "Value 32 found at index " << y << ".\n";
    }

    delete[] arr.A;
    delete[] ar.A;

    return 0;
}