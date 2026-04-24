#include <iostream>

using namespace std;

void PrintSeparator () { cout << "\n---------------------------------------\n"; }

int main () {

    const int SIZE = 5;

    int arr [SIZE] = {};

    for (int i = 0; i < SIZE; i++) {
        cout << arr [i] << ' ';
    } cout << '\n';

    for (const int &x : arr) {
        cout << x << ' ';
    } cout << '\n';
    
    PrintSeparator ();
    
    int *ptr;
    
    ptr = new int [5];
    
    ptr [0] = 3;
    
    for (int i = 0; i < SIZE; i++) {
        cout << ptr [i] << ' ';
    } cout << '\n';  

    delete [] ptr;

    return 0;
}