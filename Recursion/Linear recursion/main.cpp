#include <iostream>

using namespace std;

// Linear recursion -> This means the function makes only one recursive call.
void function (int n) {
    if (n > 0) {
        cout << "The number: " << n << '\n'; // At calling time -> We can call it as Ascending order
        function (n - 1);
        cout << "The number: " << n << '\n'; // At returning time -> We can call it as Descending order
    }
}


int main () {

    int num = 3;
    function (num);

    return 0;
}