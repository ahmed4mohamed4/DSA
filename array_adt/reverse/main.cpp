#include <iostream>
#include <algorithm>

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

void reverse_array (Array &arr) { // O(2n) => O(n)
    Array a;
    a.size = arr.size;
    a.length = arr.length;
    a.A = new int [a.size];

    for (
        int i = arr.length - 1, j = 0;
        i >= 0;
        i--, j++
    ) {
        a.A [j] = arr.A [i];
    }

    for (int i = 0; i < arr.length; i++) {
        arr.A [i] = a.A [i];
    }
}

void reverse_array_with_direct_swap (Array &arr) { // O(n)

    for (
        int i = 0, j = arr.length - 1;
        i < j;
        i++, j--
    ) {
        swap (arr.A [i], arr.A [j]);
    }

}

int main () {
    struct Array ar;
    ar.size = 10;
    ar.length = 3;
    ar.A = new int[ar.size]{12, 27, 32};

    display (ar);

    reverse_array (ar);

    display (ar);


    cout << "Testing reverse_array_with_direct_swap function:\n";
    reverse_array_with_direct_swap (ar);
    display (ar);

    delete[] ar.A;

    return 0;
}