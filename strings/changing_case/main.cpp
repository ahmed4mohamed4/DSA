#include <iostream>

using namespace std;

// Convert all the str to lower case
string lower_case (string &s) {
    
    for (char &c : s) {
        c += 'a' - 'A';
        // c += 32;
    }

    return s;
}

// Convert all the str to upper case
string upper_case (string &s) {
    
    for (char &c : s) {
        c -= 'a' - 'A';
        // c -= 32;
    }

    return s;
}

// Change the case:
// - lower => upper
// - upper => lower
string change_case (string &s) {
    
    for (char &c : s) {
        if (c >= 'a' && c <= 'z') {
            c -= 32;
        }
        else if (c >= 'A' && c <= 'Z') {
            c += 32;
        }
    }
    
    return s;
}



int main () {
    
    
    // A ==> 65
    // a ==> 97
    
    // cout << 'a' - 'A' << '\n'; // 32 in ASCII code

    string name = "AHMED";

    cout << "lower case: " << lower_case (name) << '\n';
    
    cout << "Upeer case: " << upper_case (name) << '\n';

    name = "Ahmed";

    cout << "Change the case: " << change_case (name) << '\n';
    
    return 0;
}