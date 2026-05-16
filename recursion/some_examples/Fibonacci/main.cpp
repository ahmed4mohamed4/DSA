#include <iostream>

using namespace std;

int fibonacci (int n) {

    if (n <= 1) {
        return n; // Fibonacci of 0 is 0, Fibonacci of 1 is 1
    }

    return fibonacci (n - 1) + fibonacci (n - 2);
}

int fibonacciIterative (int n) {

    if (n <= 1) {
        return n; // Fibonacci of 0 is 0, Fibonacci of 1 is 1
    }

    int a = 0, b = 1, c;

    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }

    return c;
}


int main () {

    int n = 7;
    cout << "Fibonacci of " << n << " is " << fibonacci (n) << endl;
    cout << "Fibonacci of " << n << " is " << fibonacciIterative (n) << endl;

    

    return 0;
}