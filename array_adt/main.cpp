#include <iostream>

using namespace std;

struct Array {
    int *A;
    int size;
    int length;
};

void display (Array &arr) {
    for (int i = 0; i < arr.length; i++) { // O(n)
        cout << arr.A [i] << " ";
    }
    cout << endl;
}

void append (Array &arr, int element) {
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

void pop (Array &arr) { // O(1)
    if (arr.length > 0) {
        arr.length--;
    }
    else {
        cout << "It is empty!!\n";
    }
}

void remove_at (Array &arr, int index) {

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

int linear_search (Array &arr, int key) {
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

int improve_linear_seach_transposition (Array &arr, int key) {
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

int improve_linear_seach_move_to_front (Array &arr, int key) {
    for (int i = 0; i < arr.length; i++) {
        if (arr.A [i] == key) {
            swap (arr.A [i], arr.A [0]); // Move to front
            return 0;
        }
    }
    return -1;
}

void print_separator () { cout << "\n===========================\n";}

int main () {
    
    Array arr;
    arr.size = 10;
    arr.length = 3;
    arr.A = new int [arr.size] {43, 98, 13};

    if (arr.length > 0) {
        cout << "Display first element: " << arr.A [0] << '\n';
    } else {
        cout << "It is empty so there is no first element\n";
    }

    print_separator ();
    
    display (arr);
    
    print_separator ();
    
    append (arr, 111);  
    
    display (arr);
    
    print_separator ();
    
    insert (arr, 1, 77);
    
    display (arr);

    print_separator ();

    pop (arr);

    display (arr);

    print_separator ();
    
    remove_at (arr, 2);

    display (arr);

    print_separator ();

    int the_search = linear_search (arr, 13);

    if (the_search == -1) {
        cout << "Not Found\n";
    }
    else {
        cout << "At the index: " << the_search << '\n';
    }

    print_separator ();

    int the_search2 = improve_linear_seach_transposition (arr, 13);

    if (the_search2 == -1) {
        cout << "Not Found\n";
    }
    else {
        cout << "At the index: " << the_search2 << '\n';
    }

    print_separator ();


    int the_search3 = improve_linear_seach_move_to_front (arr, 13);

    if (the_search3 == -1) {
        cout << "Not Found\n";
    }
    else {
        cout << "At the index: " << the_search3 << '\n';
    }

    print_separator ();

    delete [] arr.A;

    return 0;
}