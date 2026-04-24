
// Ahmed

#include <iostream>

using namespace std;

int func (int n) {
    if (n > 100) {
        return n - 10;
    }
    else {
        return func (func (n + 11));
    }
}

int main () {

    cout << "Result: " << func (95) << '\n';

    return 0;
}

