#include <iostream>

using namespace std;

// Convert all the str to lower case
void lower_case (string &s) {

    for (char &c : s) {
        if (c >= 'A' && c <= 'Z') {
            c += 'a' - 'A';
            // c += 32;
        }
    }
}

// Convert all the str to upper case
void upper_case (string &s) {
    
    for (char &c : s) {
        if (c >= 'a' && c <= 'z') {
            c -= 'a' - 'A';
            // c -= 32;
        }
    }
}

// Change the case:
// - lower => upper
// - upper => lower
void change_case (string &s) {
    
    for (char &c : s) {
        if (c >= 'a' && c <= 'z') {
            c -= ('a' - 'A');
        }
        else if (c >= 'A' && c <= 'Z') {
            c += ('a' - 'A');
        }
    }
    
}

int count_vowels (const string &s) {
    int counter = 0;

    for (char c : s) {
        if (c >= 'A' && c <= 'Z') { // all to lower
            c += ('a' - 'A');
        }
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
            counter++;
        }
    }

    return counter;
}

int main () {
 
    // A ==> 65
    // a ==> 97

    // cout << 'a' - 'A' << '\n'; // 32 in ASCII code

    string name = "AHMED";

    lower_case (name);

    cout << "lower case: " << name << '\n';

    upper_case (name);
    
    cout << "Upper case: " << name << '\n';

    name = "Ahmed";

    change_case (name);

    cout << "Change the case: " << name << '\n';

    cout << "Number of vowels: " << count_vowels (name) << '\n';
    
    return 0;
}

