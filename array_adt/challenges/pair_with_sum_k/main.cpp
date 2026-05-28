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

// Finding a Pair of Elements with sum K
void find_pair_with_sum_k (const Array &arr, int k) {
    for (int i = 0; i < arr.length - 1; ++i) {
        for (int j = i + 1; j < arr.length; j++) {
            if (arr.A [i] + arr.A [j] == k) {
                cout << arr.A [i] << " + " << arr.A [j] << " = " << k << '\n';
            }
        }
    }
}

// Finding a Pair of Elements with sum K using hashing
void find_pair_with_sum_k_using_hash (const Array &arr, int k) {
    int max_num = *max_element (arr.A, arr.A + arr.length);

    Array hash_array;
    hash_array.size = max_num + 1;
    hash_array.length = max_num + 1;
    hash_array.A = new int [max_num + 1] {};

    for (int i = 0; i < arr.length; i++) {
        int need = k - arr.A [i];
        if (need >= 0 && need <= max_num && hash_array.A [need] > 0) {
            cout << arr.A [i] << ' ' << need << '\n';
        }
        else {
            hash_array.A [arr.A [i]]++;
        }
    }

    delete [] hash_array.A;
    
}

// Finding a Pair of Elements with sum K in Sorted Array
void finding_pair_with_sum_k_sorted_array (const Array &arr, int k) {


    int i = 0, j = arr.length - 1;

    while (i < j) {
        int total = arr.A [i] + arr.A [j];

        if (total == k) {
            cout << arr.A [i] << " + " << arr.A [j] << '\n';
            i++;
            j--;
        }
        else if (total > k) {
            j--;
        }
        else {
            i++;
        }
    }
    
    cout << '\n';
}

int main () {
    
    Array arr;
    arr.size = 10;
    arr.length = 10;
    arr.A = new int [arr.size] {1, 3, 4, 5, 6, 8, 9, 10, 12, 14};

    display (arr);

    int k = 10;

    // find_pair_with_sum_k (arr, k);
    finding_pair_with_sum_k_sorted_array (arr, k);
    
    return 0;
}