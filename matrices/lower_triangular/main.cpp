#include <iostream>
#include <array>

using namespace std;

// i and j start from 1
class lowerTriangular {
private:
    int size; // 1D arr size
    int *A; // 1D arr
    int n; // Size of matrix
public:

    lowerTriangular (const int &n_) {
        this->n = n_;
        this->size = n_ * (n_ + 1) / 2;
        A = new int [size] {};
    }

    void set (int i, int j, const int &value) {
        if (i >= 1 && j >= 1 && i <= n && j <= n && i >= j) {
            int index = i * (i - 1) / 2 + j - 1;
            A [index] = value;
        }
    }

    int get (int i, int j) {
        if (i >= 1 && j >= 1 && i <= n && j <= n && i >= j) {
            int index = i * (i - 1) / 2 + j - 1;
            return A [index];
        }
        return 0;
    }

    // void display () {
    //     for (int i = 0; i < this->size; i++) {
    //         cout << A [i] << ' ';
    //     } cout << "\n";
    // }

    // Display the whole matrix [include 0s]
    void display () { 
        const int END = this->n;
        for (int i = 1; i <= END; i++){
            for (int j = 1; j <= END; j++) {
                cout << (i < j ? 0 : get (i, j)) << ' ';
            }
            cout << '\n';
        }
    }

    ~lowerTriangular () {
        delete [] A;
    }

};

int main () {

    const int N = 5;
    
    int lower_triangular [N][N] = {
        {1, 0, 0, 0, 0},
        {7, 2, 0, 0, 0},
        {3, 4, 8, 0, 0},
        {2, 5, 3, 5, 0},
        {1, 1, 9, 3, 6}
    }; // 5 x 5 matrix

    const int SIZE = N * (N + 1) / 2;

    array <int, SIZE> arr {};

    // Row major order
    int k = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j <= i; j++) {
            arr [k++] = lower_triangular [i][j];
        }
    }

    // Display
    cout << "Row major: ";
    for (const int x : arr) {
        cout << x << ' ';
    } cout << '\n';
    
    arr = {}; // 0s
    k = 0;

    // Column major order
    for (int i = 0; i < N; i++) {
        for (int j = i; j < N; j++) {
            arr [k++] = lower_triangular [j][i];
        }
    }

    // Display
    cout << "Column major: ";
    for (const int x : arr) {
        cout << x << ' ';
    } cout << '\n';


    // Using class
    lowerTriangular lt (5);

    lt.set (1,1,1);

    lt.set (2,1,7);
    lt.set (2,2,2);

    lt.set (3,1,3);
    lt.set (3,2,4);
    lt.set (3,3,8);

    lt.set (4,1,2);
    lt.set (4,2,5);
    lt.set (4,3,3);
    lt.set (4,4,5);

    lt.set (5,1,1);
    lt.set (5,2,1);
    lt.set (5,3,9);
    lt.set (5,4,3);
    lt.set (5,5,6); 

    cout << "Using Class:\n";
    lt.display ();

    return 0;
}