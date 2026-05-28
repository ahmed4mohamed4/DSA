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

// Finding Max and Min in a single Scan
void finding_max_min (const Array &arr) {
    int min_num = arr.A [0];
    int max_num = arr.A [0];

    for (int i = 1; i < arr.length; i++) {
        min_num = min (min_num, arr.A [i]);
        max_num = max (max_num, arr.A [i]);
    }

    cout << "Min: " << min_num << '\n';
    cout << "Max: " << max_num << '\n';
}

int main () {
    
    Array arr;
    arr.size = 5;
    arr.length = 5;
    arr.A = new int [arr.size] {3, 2, -1, 10, 1};


    finding_max_min (arr);


    return 0;
}