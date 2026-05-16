#include <iostream>

using namespace std;

int sum (int n) {
    if (n > 0) {
        return sum (n - 1) + n; // "+ n" will be executed at return time.
    }
    else {
        return 0;
    }
} // ===> O(n) time complexity, O(n) space complexity. --> Recursion <--

/*
    - Magic from Mathematics: The sum of the first n natural numbers is given by the formula: n * (n + 1) / 2.
*/

int sum_formula (int n) {
    return n * (n + 1) / 2;
} // ===> O(1) time complexity, O(1) space complexity. --> Mathematics <-- 🫡

int sum_iterative (int n) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    return sum;
} // ===> O(n) time complexity, O(1) space complexity. --> Iteration <--

void PrintSeparator () {
    cout << "-----------------------------\n";
}   

int main () {

    int num = 3;
    cout << "The sum: " << sum (num) << '\n';

    PrintSeparator ();

    // Testing the formula:
    cout << "The sum using the formula: " << sum_formula (num) << '\n';

    PrintSeparator ();

    // Testing the iterative approach:
    cout << "The sum using the iterative approach: " << sum_iterative (num) << '\n';

    return 0;
}



