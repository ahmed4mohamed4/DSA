#include <iostream>

using namespace std;


void display_array (int arr [], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr [i] << ' ';
    } cout << '\n';
}

void print_separator () { cout << "\n======================================\n";}

int main () {
    
    int arr [] = {10, 33, 2, 4};
    cout << "Display first element: " << arr [0] << '\n';

    print_separator ();
    
    display_array (arr, 4);
    
    for (const auto &x : arr) {
        cout << x << ' ';
    } cout << '\n';
    
    print_separator ();

    
    return 0;
}