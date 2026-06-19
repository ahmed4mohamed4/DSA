#include <iostream>

using namespace std;

// find duplicate chars using hash array
void find_duplicate_chars_hash_array (const string &s) {
    
    int SIZE = 26;
    
    int hash_array [SIZE] = {};

    for (char c : s) {
        if (c >= 'A' && c <= 'Z') {
            c += ('a' - 'A');
        }

        if (c >= 'a' && c <= 'z') {
            hash_array [c - 'a']++;
        }
    }


    for (int i = 0; i < SIZE; i++) {
        if (hash_array [i] > 1) {
            cout << char (i + 'a') << ' ';
        }
    } cout << '\n';
    
}

// Find duplicate chars using Bitwise
void find_duplicate_chars_bitwise (const string &s) {
    int h = 0;

    for (char c : s) {
        if (c >= 'A' && c <= 'Z') {
            c += ('a' - 'A');
        }

        if (c < 'a' || c > 'z') continue;

        int mask = 1 << (c - 'a');

        if (h & mask) {
            cout << c << ' ';
        } else {
            h |= mask;
        }
    }
    cout << '\n';
}

void print_separator (const int &n) {
    cout << '\n';
    for (int i = 1; i <= n; i++) {
        cout << '-';
    } cout << '\n';
}

int main () {
    
    string s = "aa bb cc";

    find_duplicate_chars_hash_array (s);
    
    print_separator (10);

    find_duplicate_chars_bitwise (s);


    return 0;
}