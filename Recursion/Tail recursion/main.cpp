#include <iostream>

using namespace std;

// Tail recursion
void function (int n) { // T(n)
    if (n > 0) /* 1 unit of time */ {
        cout << "The number: " << n << '\n'; // 1 unit of time
        function (n - 1); // T(n - 1)
        /*
            The call is last statement in the function, so it is tail recursion.
        */
    }
}

/*
            = T(n - 1) + 2, n > 0. 2 for print and the if condition check and T(n - 1) for the function call
    - T(n)
            = 1 , n = 0. for the base case

    - Solving the recurrence relation:
            - replace any constant with 1, so we have T(n) = T(n - 1) + 1, n > 0
            * T(n) = T(n - 1) + 1
            * T(n - 1) = T(n - 2) + 1 replace this with T(n - 1) in the first equation.
            * T(n) = T(n - 2) + 1 + 1 = T(n - 2) + 2
            * T(n - 2) = T(n - 3) + 1 replace this with T(n - 2)
            * T(n) = T(n - 3) + 1 + 2 = T(n - 3) + 3
            * T(n) = T(n - k) + k replace this with T(n - k)
            * Assuming n - k = 0, -> k = n, so T(n) = T(0) + n = 1 + n = O(n)

*/

/*
    - Complexity: for n = 3: 1 + 1 + 1 = 3 units of time, for n: it is n units of time, O(n)
    - There are n + 1 activation records, O(n)
*/

int main () {

    int num = 3;
    function (num);

    return 0;
}