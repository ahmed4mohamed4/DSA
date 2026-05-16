#include <iostream>

using namespace std;

/*
    - Power of a number n raised to the power of p is the product of n multiplied by itself p times.
    => 3^4 = 3 * 3 * 3 * 3 = 81
    => n^0 = 1 (by definition)
*/

int power (int n, int p) {

    if (p < 0) {
        return -1; // Power is not defined for negative exponents
    }

    if (p == 0) {
        return 1;
    }
    
    return n * power (n, p - 1);
}

int pow (int m, int n) {
    if (n < 0) {
        return -1;
    }

    if (n == 0) {
        return 1;
    }

    if (n % 2 == 0) {
        return pow (m * m, n / 2);
    }
    else {
        return m * pow (m * m, (n - 1) / 2);
    }
}

int main () {

    int n = 2, p = 3;
    cout << "Power of " << n << " raised to the power of " << p << " is " << power (n, p) << endl;

    int m = 2, q = 3;
    cout << "Power of " << m << " raised to the power of " << q << " is " << pow (m, q) << endl;

    return 0;
}