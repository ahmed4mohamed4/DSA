
/* 
    Author: Ahmed Rabie 
*/
// We just focus on the time complexity of the code, not what the code does or what the functions do.
// Sorry if there are any bugs in the code. we just need to learn the time complexity. 🙂

# include <iostream>

using namespace std;

void swap (int x, int y) {
    int t;
    t = x; // 1
    x = y; // 1
    y = t; // 1
    // f (n) = 3
    // We care about the power of n, not the constant, so we can ignore the constant and say that the time complexity of this function is O (1).
    // → o(1)
}

int sum (int arr [], int n) {
    int s = 0; // 1
    for (int i = 0; /* ← (1) */ i < n; /* ← (n + 1) */ ++i /* ← (n) */) { // → (1) + (n + 1) + (n) = 2n + 2 = 2 (n + 1)
        s += arr [i]; // n
    }
    return s; // 1
} // Total = 2n + 2 + n + 1 = 3n + 3 = 3 (n + 1) => o(n)

void add (int a [][5], int b [][5], int c [][5], int n) {
    for (int i = 0; i < n; i++) { // 1 + (n + 1) + n
        for (int j = 0; j < n; ++j) { // 1 + (n + 1) + n
            c [i][j] = a [i][j] + b [i][j]; // n * n = n ^ 2
        }
    }
} // Total = 1 + (n + 1) + n + 1 + (n + 1) + n + n * n => o(n ^ 2)

void func2 (int n) {
    for (int i = 0; i < n; i++) { // n
        printf ("Ahmed"); // n
    }
    // n ==> O(n)
}

void fun1 (int n) {
    func2 (n); // n
    /*
        o(n) because func2 has loop 🙂
    */
}

void func3 (int n) {
    while (n > 1) {
        n = n / 2;
        cout << n << ' ';
    }
    cout << '\n';
    // o(log n) because we are dividing n by 2.
}

void func4 (int n) {
    for (int i = 0; i < n; i += 2) { // n/2 => o(n)
        cout << i << ' ';
    }
        cout << '\n';
        // o(n) because we are iterating through n/2 elements, but we ignore the constant and say that it is o(n).
}

void func5 (int n) {
    for (int i = 1; i < n; i *= 2) { // log n => o(log n)
        cout << i << ' ';
    }
    cout << '\n';
    // o(log n) because we are multiplying i by 2.
}

void func6 (int n) {
    int i = 1;
    while (i < n) {
        int j = 1;
        while (j < n) {
            cout << i << ' ' << j << '\n';
            j *= 2;
        }
        i *= 2;
    }
} // o(log n * log n) because we have two nested loops, each of which is o(log n).

void func7 (int n) {
    while (n > 1) {
        n /= 3;
        cout << n << ' ';
    }
    cout << '\n';
} // log3​n => o(log n) 


int main () {}