#include <iostream>

using namespace std;

/*
    - Factorial of a number n is the product of all positive integers less than or equal to n.
    => 3! = 3 * 2 * 1 = 6
    => 0! = 1 (by definition)
*/

int factorial (int n) {

    if (n < 0) {
        return -1; // Factorial is not defined for negative numbers
    }

    if (n == 0) {
        return 1;
    }
    return n * factorial (n - 1);
}

int main () {

    int n = 3;
    cout << "Factorial of " << n << " is " << factorial(n) << endl;

    return 0;
}