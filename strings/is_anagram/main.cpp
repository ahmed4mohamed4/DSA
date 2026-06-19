#include <iostream>

using namespace std;

// lower cases
bool is_anagram (const string &s1, const string &s2) { // O(n)
    
    if (s1.size () != s2.size ()) return false;
    
    int hash_array [26] = {};

    for (char c : s1) {

        if (c >= 'A' && c <= 'Z') c += ('a' - 'A');

        if (c < 'a' || c > 'z') return false;
        
        hash_array [c - 'a']++;

    }

    for (char c : s2) {
        if (c >= 'A' && c <= 'Z') c += ('a' - 'A');


        if (c < 'a' || c > 'z') return false;
        
        hash_array [c - 'a']--;
    }

    for (int x : hash_array) {
        if (x != 0) {
            return false;
        }
    }

    return true;

}

int main () {
    
    string s1 = "aab";
    string s2 = "aba";

    cout << (is_anagram (s1, s2)? "Anagram" : "It is not") << '\n';
    
    
    return 0;
}