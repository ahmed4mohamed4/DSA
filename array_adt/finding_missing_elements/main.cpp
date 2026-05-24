#include <iostream>
#include <algorithm>

using namespace std;

struct Array {
    int *A;
    int size;
    int length;
};

void display (const Array &arr) {
    cout << "Array: ";

    if (arr.length > 0) {

        for (int i = 0; i < arr.length; ++i) {
            cout << arr.A [i] << ' ';
        } cout << '\n';

    }
    else {
        cout << "Empty!\n";
    }
}

// Find the missing number in sorted array (1 -> n)
int find_missing_element_from_1_to_n (const Array &arr) {
    int calc_sum = 0;
    
    for (int i = 0; i < arr.length; ++i) {
        calc_sum += arr.A [i];
    }
    
    int n = arr.length + 1; // Missing one element so +1
    int actual_sum = n * (n + 1) / 2;

    return actual_sum - calc_sum;
}

// Find the missing number in sorted array start from n (n -> m)
int find_missing_element_from_n_to_m (const Array &arr) { // O(n)
    int diff = arr.A [0] - 0;

    for (int i = 0; i < arr.length; ++i) {
        if (arr.A [i] - i != diff) {
            return i + diff;
        }
    }

    return -1; // No missing element
}

// Find the missing numbers in sorted array start from n (n -> m)
void find_missing_elements_from_n_to_m (const Array &arr) { // O(n)
    int diff = arr.A [0] - 0;

    cout << "Missing elements: ";
    for (int i = 0; i < arr.length; ++i) { // O(n)
        if (arr.A [i] - i != diff) {
            while (diff < arr.A [i] - i) {
                cout << i + diff << ' ';
                diff++;
            }
        }
    }
    cout << '\n';
}

// Find the missing numbers in unsorted array
void find_missing_elements_unsorted_array (const Array &arr) {
    int low = *min_element (arr.A, arr.A + arr.length);
    int high = *max_element (arr.A, arr.A + arr.length);

    Array ar;
    ar.size = high + 1;
    ar.length = high + 1;
    ar.A = new int [ar.size] {};

    for (int i = 0; i < arr.length; ++i) {
        ar.A [arr.A [i]]++;
    }

    cout << "Missing elements: ";
    for (int i = low; i <= high; i++) {
        if (ar.A [i] == 0) {
            cout << i << ' ';
        }
    } cout << '\n';

    delete ar.A;
}

int main () {
    
    Array arr;
    arr.size = 11;
    arr.length = 11;
    arr.A = new int [arr.size] {1, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12}; // missing 2

    display (arr);

    cout << find_missing_element_from_1_to_n (arr) << '\n';

    cout << "\n---------------------\n";

    Array arr2;
    arr2.size = 11;
    arr2.length = 11;
    arr2.A = new int [arr2.size] {6, 7, 8, 9, 10, 11, 13, 14, 15, 16, 17}; // missing 12

    display (arr2);
    cout << find_missing_element_from_n_to_m (arr2) << '\n';

    cout << "\n---------------------\n";
    
    Array arr3;
    arr3.size = 11;
    arr3.length = 11;
    arr3.A = new int [arr3.size] {6, 7, 8, 9, 11, 12, 15, 16, 17, 18, 19}; // missing 10, 13, 14
    
    display (arr3);
    find_missing_elements_from_n_to_m (arr3);
    
    cout << "\n---------------------\n";

    Array ar;
    ar.size = 10;
    ar.length = 10;
    ar.A = new int [ar.size] {3, 7, 4, 9, 12, 6, 1, 11, 2, 10};

    display (ar);
    find_missing_elements_unsorted_array (ar);

    delete [] arr.A;
    delete [] arr2.A;
    delete [] arr3.A;
    delete [] ar.A;

    return 0;
}