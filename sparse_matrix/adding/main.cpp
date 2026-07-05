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

// Add two sparse matrices
Sparse addTwoSparsematrix (const Sparse &sparse_1, const Sparse &sparse_2) {
    if (sparse_1.m != sparse_2.m || sparse_1.n != sparse_2.n) {
        cout << "Matrix dimensions do not match for addition!" << endl;
        Sparse emptySparse = {0, 0, 0, nullptr};
        return emptySparse;
    }
    
    Sparse sparse;
    sparse.m = sparse_1.m;
    sparse.n = sparse_1.n;
    sparse.num = 0;
    sparse.a = new Element [sparse_1.num + sparse_2.num];

    int i = 0;
    int j = 0;
    int k = 0;

    while (
        i < sparse_1.num &&
        j < sparse_2.num
    ) {
        if (sparse_1.a [i].i < sparse_2.a [j].i) {
            sparse.a [k].i = sparse_1.a [i].i;
            sparse.a [k].j = sparse_1.a [i].j;
            sparse.a [k++].x = sparse_1.a [i++].x;
        }
        else if (sparse_1.a [i].i > sparse_2.a [j].i) {
            sparse.a [k].i = sparse_2.a [j].i;
            sparse.a [k].j = sparse_2.a [j].j;
            sparse.a [k++].x = sparse_2.a [j++].x;
        }
        else { // Columns
            if (sparse_1.a [i].j < sparse_2.a [j].j) {
                sparse.a [k].i = sparse_1.a [i].i;
                sparse.a [k].j = sparse_1.a [i].j;
                sparse.a [k++].x = sparse_1.a [i++].x;
            }
            else if (sparse_1.a [i].j > sparse_2.a [j].j) {
                sparse.a [k].i = sparse_2.a [j].i;
                sparse.a [k].j = sparse_2.a [j].j;
                sparse.a [k++].x = sparse_2.a [j++].x;
            }
            else {
                sparse.a [k].i = sparse_1.a [i].i;
                sparse.a [k].j = sparse_1.a [i].j;
                sparse.a [k++].x = sparse_1.a [i++].x + sparse_2.a [j++].x;
            }
        }
    }

    while (i < sparse_1.num) {
        sparse.a [k].i = sparse_1.a [i].i;
        sparse.a [k].j = sparse_1.a [i].j;
        sparse.a [k++].x = sparse_1.a [i++].x;
    }

    while (j < sparse_2.num) {
        sparse.a [k].i = sparse_2.a [j].i;
        sparse.a [k].j = sparse_2.a [j].j;
        sparse.a [k++].x = sparse_2.a [j++].x;
    }

    sparse.num = k;

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
    
    Sparse s1 = createCoordinate ();
    display (s1);

    Sparse s2 = createCoordinate ();
    display (s2);

    cout << "Adding two sparse matrices..." << endl;
    Sparse s3 = addTwoSparsematrix (s1, s2);
    display (s3);

    return 0;
}