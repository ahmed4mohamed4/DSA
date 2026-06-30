#include <iostream>
#include <array>

using namespace std;

// i and j start from 1
class upperTriangular {
private:
    int size; // 1D arr size
    int  *A;
    int n; // matrix size
public:

    // Constructor
    upperTriangular (const int &n_) {
        this->n = n_;
        this->size = n_ * (n_ + 1) / 2;
        this->A = new int [this->size] {};
    }

    void set (const int &i, const int &j, const int &value) {
        if (i >= 1 && j >= 1 && i <= n && j <= n && i <= j) {
            const int index = (n * (i - 1) - (i - 2) * (i - 1) / 2) + (j - i);
            this->A [index] = value;
        }
    }

    int get (const int &i, const int &j) {
        if (i >= 1 && j >= 1 && i <= n && j <= n && i <= j) {
            const int index = (n * (i - 1) - (i - 2) * (i - 1) / 2) + (j - i);
            return this->A [index];
        }
        else {
            return 0;
        }
    }

    void display () { 
        const int END = this->n;
        for (int i = 1; i <= END; i++){
            for (int j = 1; j <= END; j++) {
                cout << (i > j ? 0 : get (i, j)) << ' ';
            }
            cout << '\n';
        }
    }

    // Detractor
    ~upperTriangular () {
        delete [] this->A;
    }

};

int main () {
    
 const int N = 5;
    
    int upper_triangular [N][N] = {
        {1, 7, 3, 2, 1},
        {0, 2, 4, 5, 1},
        {0, 0, 8, 3, 9},
        {0, 0, 0, 5, 3},
        {0, 0, 0, 0, 6}
    }; // 5 x 5 matrix (upper triangular)

    const int SIZE = N * (N + 1) / 2;

    array <int, SIZE> arr {};

    // Row major order for upper triangular
    int k = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            arr [k++] = upper_triangular [i][j];
        }
    }

    // Display
    cout << "Row major: ";
    for (const int x : arr) {
        cout << x << ' ';
    } cout << '\n';
    
    arr = {}; // 0s
    k = 0;

    // Column major order for upper triangular
    for (int j = 0; j < N; j++) {
        for (int i = 0; i <= j; i++) {
            arr [k++] = upper_triangular [i][j];
        }
    }

    // Display
    cout << "Column major: ";
    for (const int x : arr) {
        cout << x << ' ';
    } cout << '\n';


    // Using class for upper triangular
    upperTriangular ut (5);

    ut.set (1,1,1);
    ut.set (1,2,7);
    ut.set (1,3,3);
    ut.set (1,4,2);
    ut.set (1,5,1);

    ut.set (2,2,2);
    ut.set (2,3,4);
    ut.set (2,4,5);
    ut.set (2,5,1);

    ut.set (3,3,8);
    ut.set (3,4,3);
    ut.set (3,5,9);

    ut.set (4,4,5);
    ut.set (4,5,3);

    ut.set (5,5,6);

    cout << "Using Class:\n";
    ut.display ();

    return 0;
}