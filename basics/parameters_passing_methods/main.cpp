#include <bits/stdc++.h>

using namespace std;

void swap_two_nums_by_value (int x, int y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
}


void swap_two_nums_by_address (int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

void swap_two_nums_by_ref (int &x, int &y) {
    int temp;
    temp = x;
    x = y;
    y = temp;
}


void PrintSeparator () { cout << "\n-------------------------------------\n"; }

int main () {

    int a = 10, b = 20;

    // passing by value
    swap_two_nums_by_value (a, b);
    cout << "A: " << a << "\nB: " << b << '\n'; // Not change
    
    PrintSeparator ();
    
    // Passing by address
    swap_two_nums_by_address (&a, &b);
    cout << "A: " << a << "\nB: " << b << '\n'; // Change
    
    PrintSeparator ();
    
    // Called by references
    
    swap_two_nums_by_ref (a, b);
    cout << "A: " << a << "\nB: " << b << '\n'; // Change

    return 0;
}