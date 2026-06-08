#include <iostream>

using namespace std;

bool is_valid (const string &s) {
    
    for (const char &c : s) {
        if (
            !(c >= 'a' && c <= 'z') &&
            !(c >= 'A' && c <= 'Z') &&
            !(c >= '0' && c <= '9')
        ) {
            return false;
        }
    }

    return true;
}

int main () {
    
    char s [] = "Ahmed!123"; // invalid


    cout << (is_valid (s) ? "Valid" : "invalid") << '\n';
    
    return 0;
}