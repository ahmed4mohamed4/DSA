#include <iostream>

using namespace std;

void print_separator (const int &n) {
    cout << '\n';
    for (int i = 1; i <= n; i++) {
        cout << '-';
    } cout << '\n';
}

int main () {
    
    cout << "Left shift\n";
    for (int i = 1; i <= 4; i++) { // left shift
        cout << 1 << " << " << i << " = " << (1 << i) << '\n';
    }

    print_separator (20);

    cout << "Right shift\n";
    for (int i = 1; i <= 4; i++) { // right shift
        cout << 16 << " >> " << i << " = " << (16 >> i) << '\n';
    }

    print_separator (20);
    
    /* AND */
    cout << "AND\n";
    cout << 0 << " & " << 0 << " = " << (0 & 0) << '\n';
    cout << 0 << " & " << 1 << " = " << (0 & 1) << '\n';
    cout << 1 << " & " << 0 << " = " << (1 & 0) << '\n';
    cout << 1 << " & " << 1 << " = " << (1 & 1) << '\n';

    print_separator (20);

    /* OR */
    cout << "OR\n";
    cout << 0 << " | " << 0 << " = " << (0 | 0) << '\n';
    cout << 0 << " | " << 1 << " = " << (0 | 1) << '\n';
    cout << 1 << " | " << 0 << " = " << (1 | 0) << '\n';
    cout << 1 << " | " << 1 << " = " << (1 | 1) << '\n';

    print_separator (20);

    /* NOT */
    cout << "NOT\n";
    cout << 0 << " = " << !(0) << '\n';
    cout << 1 << " = " << !(1) << '\n';

    print_separator (20);

    /* masking */
    cout << "Masking\n"; // Check bit 2 if it is 1 or not
    int x = 13;
    cout << ((x & (1 << 2)) != 0) << '\n';

    print_separator (20);

    /* merging */
    cout << "Merging\n";
    int n1 = 8;
    int n2 = 5;
    cout << (n1 | n2) << '\n';


    return 0;
}