#include <iostream>

using namespace std;

void PrintSeparator () { cout << "\n----------------------------\n"; }

int main () {

    /* 
        - Reference ---> a nickname given to variable or alias given to a variable.
    */

    int a = 10;
    int &r = a;

    cout << "a: " << a << "\nr: " << r << '\n'; // has two names for the same value inside the memory.
    
    r++;
    
    PrintSeparator ();

    cout << "a: " << a << "\nr: " << r << '\n';

    /*
        -> This is useful in parameters passing.
        -> writing small functions so we use references instead of pointers.
    */

    return 0;
}

