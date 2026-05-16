#include <iostream>

using namespace std;

// Head recursion
void function (int n) {
    if (n > 0) {
        function (n - 1); // No thing before this statement, so it is head recursion.
        cout << "The number: " << n << '\n'; // This line is executed at return call time.
        int t = 1;
        int w = 1;
        int e = 1;
        int r = 1;
    }
}

int main () {

    int num = 3;
    function (num);

    return 0;
}