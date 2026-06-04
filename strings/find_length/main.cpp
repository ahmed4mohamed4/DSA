#include <iostream>

using namespace std;

int len_str (char s []) {
    
    int i;

    for (i = 0; s [i] != '\0'; i++) {}

    return i;

}

int main () {
    
    char s [10] = "Ahmed";

    cout << s << '\n';
    cout << len_str (s) << '\n';

    
    return 0;
}