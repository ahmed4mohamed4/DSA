#include <iostream>
#include <algorithm>

using namespace std;

class symmetricMatrix {
private:
    int size; // size of 1D arr
    int n; // size of the matrix
    int *a; // 1D arr
public:

    
    symmetricMatrix (const int &n_) { // Constructor
        this->n = n_;
        this->size = n_ * (n_ + 1) / 2;
        this->a = new int [this->size] {};
    }

    void set (int i, int j, int value) {
        if (i < 1 || j < 1 || i > n || j > n) {
            return;
        }

        if (i < j) {
            swap (i, j);
        }
            
        int index = i * (i - 1) / 2 + j - 1;
        a [index] = value;
    }

    int get (int i, int j) const {
        if (i < 1 || j < 1 || i > n || j > n) {
            return 0;
        }

        if (i < j) {
            swap (i, j);
        }
            
        int index = i * (i - 1) / 2 + j - 1;
        return a [index];
    }

    void display () const { // display : the whole matrix
        for (int i = 1; i <= this->n; i++) {
            for (int j = 1; j <= this->n; j++) {
                cout << get (i, j) << ' ';
            } cout << '\n';
        } 
    }

    ~symmetricMatrix () { // destructor
        delete [] a;
    }
};

int main () {
    symmetricMatrix sm (4);

    // Set some values
    sm.set (1, 1, 1);
    sm.set (2, 1, 2);
    sm.set (2, 2, 3);
    sm.set (3, 1, 4);
    sm.set (3, 2, 5);
    sm.set (3, 3, 6);
    sm.set (4, 1, 7);
    sm.set (4, 2, 8);
    sm.set (4, 3, 9);
    sm.set (4, 4, 10);

    cout << "Matrix:\n";
    sm.display();

    cout << "get(4,2) = " << sm.get (4,2) << '\n';
    cout << "get(2,4) = " << sm.get (2,4) << '\n'; // Should also be 8
    cout << "get(3,1) = " << sm.get (3,1) << '\n';
    cout << "get(1,3) = " << sm.get (1,3) << '\n'; // Should also be 4
    cout << "get(5,1) = " << sm.get (5,1) << '\n'; // Out of bounds

    return 0;
}