#include <iostream>

using namespace std;

struct Array {
    int *a;
    int size;
    int length;
};

void display_array (struct Array arr) {
    cout << "Array: ";
    for (int i = 0; i < arr.length; i++) {
        cout << arr.a [i] << ' ';
    } cout << '\n';
} 


int main () {

    struct Array arr;

    cout << "Size of the arr: "; 
    cin >> arr.size;

    arr.a = new int [arr.size];
    arr.length = 0;

    int n;
    cout << "Enter number of numbers (Length): ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cout << "Number " << i + 1 << ": ";
        cin >> arr.a [i];
    }

    arr.length = n;

    display_array (arr);


    int temp [] = {2, 4, 1};

    struct Array arr2 = {temp, 10, 3};
    display_array (arr2);

    return 0;
}