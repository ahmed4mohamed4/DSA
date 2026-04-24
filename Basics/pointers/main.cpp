/*
    - The pointer ---> address variable that is meant for storing address of data not the data itself.
    
    - Why we use?
        > Accessing Heap
        > Accessing Resources
        > Parameter passing
*/


#include <iostream>
#include <stdlib.h>

using namespace std;

void PrintSeparator () { cout << "\n---------------------------------------\n";}

struct Rectangle {
    int l, w;
};


int main () {

    int a = 20; // data variable
    int *ptr = &a; // address variable

    cout << "Value: " << a << '\n';
    cout << "Value: " << *ptr << '\n';
    cout << "Address: " << ptr << '\n';
    cout << "Address: " << &a << '\n';

    PrintSeparator ();

    int A [5] = {1, 2, 3, 4, 5};
    int *pointer = A;
    for (int i = 0; i < 5; ++i) {
        cout << pointer [i] << ' ';
    }

    PrintSeparator ();
    
    int *pointer_2 = (int *) malloc (5 * sizeof (int));
    pointer_2 [0] = 10; pointer_2 [1] = 11; pointer_2 [2] = 12; pointer_2 [3] = 13; pointer_2 [4] = 14;
    for (int i = 0; i < 5; i++) {
        cout << pointer_2 [i] << ' ';
    }
    
    PrintSeparator ();
    
    int *pointer_3 = new int [5];
    pointer_3 [0] = 10; pointer_3 [1] = 11; pointer_3 [2] = 12; pointer_3 [3] = 13; pointer_3 [4] = 14;
    for (int i = 0; i < 5; ++i) {
        cout << pointer_3 [i] << ' ';
    }

    delete [] pointer_3;
    free (pointer_2);

    PrintSeparator ();

    int *p1;
    char *p2;
    float *p3;
    double *p4;
    string *p5;
    Rectangle *p6;


    // Look at this ===> Pointer address take 8 Bytes 🫣
    cout << sizeof (p1) << '\n';
    cout << sizeof (p2) << '\n';
    cout << sizeof (p3) << '\n';
    cout << sizeof (p4) << '\n';
    cout << sizeof (p5) << '\n';
    cout << sizeof (p6) << '\n';


    return 0;
}