#include <iostream>

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

// Find duplicates elemets in sorted array 
void find_duplicates (const Array &arr) {
    int last_duplicates = -1;
    
    cout << "Duplicate numbers: ";
    for (int i = 1; i < arr.length; ++i) {
        if (arr.A [i] == arr.A [i - 1] && arr.A [i] != last_duplicates) {
            cout << arr.A [i] << ' ';
            last_duplicates = arr.A [i];
        }
    }
    cout << '\n';
}

// count duplicates elemets in sorted array
int count_duplicates (const Array &arr) {
    int counter = 0;

    for (int i = 0; i < arr.length - 1; ++i) {
        if (arr.A [i] == arr.A [i + 1]) {
            int j = i + 1;
            while (arr.A [j] == arr.A [i]) {  
                j++;
            }
            counter += (j - i);
            i = j - 1;
        }
    }
    return counter;
}

// Finding Duplicates in Sorted Array using Hashing
void find_duplicates_using_hash (const Array &arr) {
    Array hash_array;
    hash_array.size = arr.A [arr.length - 1] + 1;
    hash_array.length = arr.A [arr.length - 1] + 1;
    hash_array.A = new int [hash_array.size] {};

    for (int i = 0; i < arr.length; ++i) {
        hash_array.A [arr.A [i]]++;
    }
    cout << "Duplicate numbers: ";
    for (int i = 0; i < hash_array.length; i++) {
        if (hash_array.A [i] > 1) {
            cout << i << ' ';
        }
    } cout << '\n';
    
    delete [] hash_array.A;
}

// Find duplicates elemets in Unsorted array
void find_duplicates_unsorted_array (Array arr) {

    Array temp;
    temp.size = arr.size;
    temp.length = arr.length;
    temp.A = new int [temp.size];
    for (int i = 0; i < arr.length; ++i) {
        temp.A [i] = arr.A [i];
    }

    cout << "Duplicate numbers: ";
    for (int i = 0; i < temp.length - 1; i++) {
        if (temp.A [i] != -1) {
            int last_duplicate = -1;
            for (int j = i + 1; j < temp.length; ++j) {
                if (temp.A [i] == temp.A [j]) {
                    cout << temp.A [i] << ' ';
                    last_duplicate = temp.A [i];
                    temp.A [j] = -1;
                }
            }
        }
    } cout << '\n';

    delete [] temp.A;
}

int main () {
    
    Array arr;
    arr.size = 10;
    arr.length = 10;
    arr.A = new int [arr.size] {8, 3, 6, 4, 6, 5, 6, 8, 2, 7};
    
    display (arr);
    
    find_duplicates_unsorted_array (arr);
    
    display (arr);

    delete [] arr.A;
    
    return 0;
}


