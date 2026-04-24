#include <iostream>

using namespace std;

// int x = 0; // Global variable.

int function (int n) {
    static int x = 0; // This work the same as the global variable but it is only accessible inside the function and it is initialized only once, and it doesn't have copies for each activation record.
    if (n > 0) {
        x++;
        return function (n - 1) + x;
    }
    else {
        return 0;
    }
}

int main () {

    int num = 3;
    function (num);

    return 0;
}