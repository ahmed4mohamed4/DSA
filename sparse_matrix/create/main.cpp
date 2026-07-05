#include <iostream>

using namespace std;

struct Element {
    int i; // row
    int j; // column
    int x; // value
};

struct Sparse {
    int m; // Number of rows
    int n; // Number of columns
    int num; // Number of non-zero element
    struct Element *a; // For elements
};

// Create COO from Sparse matrix
Sparse createCoordinate () {
    Sparse sparse;

    cout << "Enter number of rows: "; // rows
    cin >> sparse.m;

    cout << "Enter number of columns: "; // columns
    cin >> sparse.n;

    cout << "Enter number of non-zero elements: "; // number of non-zero elements
    cin >> sparse.num;

    sparse.a = new Element [sparse.num];
    cout << "Enter non-zero elements (row, column, value):" << endl; // Input non-zero elements
    for (int i = 0; i < sparse.num; i++) {
        cin >> sparse.a[i].i >> sparse.a[i].j >> sparse.a[i].x;
    }

    return sparse;
}

void display (const Sparse &sparse) { // Display the whole sparse matrix
    cout << "Sparse Matrix: " << endl;
    int k = 0;
    for (int i = 0; i < sparse.m; i++) {
        for (int j = 0; j < sparse.n; j++) {
            if (k < sparse.num && sparse.a [k].i == i && sparse.a [k].j == j) {
                cout << sparse.a [k++].x << " ";
            }
            else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

int main () {
    
    Sparse s = createCoordinate ();
    display (s);

    /*
        1 0 0 0 0 
        1 0 0 0 0 
        1 0 0 0 0 
        1 0 0 0 0 
        1 0 0 0 0
    */

    return 0;
}