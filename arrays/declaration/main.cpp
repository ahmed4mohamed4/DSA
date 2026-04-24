#include <iostream>

using namespace std;

void PrintSeparator () { cout << "\n---------------------------------------\n"; }

int main () {

    int arr [5] = {1, 2, 3, 4, 5};

    for (const auto &i : arr) {
        cout << i << " ";
    }
    cout << endl;

    PrintSeparator ();
    
    cout << 2 [arr] << '\n';
    
    for (int i = 0; i < 5; i++) {
        cout << i [arr] << " ";
    }
    cout << endl;

    PrintSeparator ();

    for (int i = 0; i < 5; i++) {
        cout << "Address: " << (arr + i) << " ";
        cout << "\nValue: " << *(arr + i) << " \n";
    }
    cout << endl;

    return 0;
}