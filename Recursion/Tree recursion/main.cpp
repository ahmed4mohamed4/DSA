#include <iostream>

using namespace std;


// Tree recursion -> This means the function makes more than one recursive call.
void function (int n) {
    if (n > 0) {
        cout << "The number: " << n << '\n';
        function (n - 1); 
        function (n - 1);
    }
}

int main () {

    int num = 3;
    function (num);

    return 0;
}