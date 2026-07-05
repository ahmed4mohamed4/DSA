#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

const int ROWS = 8;
const int COLS = 9;

// ---------------- Print the original dense matrix ----------------
void printMatrix(int mat[ROWS][COLS]) {
    cout << "===== Original Sparse Matrix (" << ROWS << " x " << COLS << ") =====\n";
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++)
            cout << setw(3) << mat[i][j];
        cout << "\n";
    }
    cout << "\n";
}

// ---------------- Coordinate List (COO) Representation ----------------
// Stores (row, col, value) for every non-zero element.
// By convention, the first line stores (numRows, numCols, numNonZero) as metadata.
void convertToCOO(int mat[ROWS][COLS]) {
    vector<int> rowIdx, colIdx, values;

    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            if (mat[i][j] != 0) {
                rowIdx.push_back(i + 1);  // 1-indexed row (matches matrix labeling)
                colIdx.push_back(j + 1);  // 1-indexed column
                values.push_back(mat[i][j]);
            }

    int nnz = values.size();  // number of non-zero elements

    cout << "===== COO (Coordinate List) Representation =====\n";
    cout << "Row\tCol\tValue\n";
    cout << ROWS << "\t" << COLS << "\t" << nnz << "\t<-- size + non-zero count\n";
    for (int k = 0; k < nnz; k++)
        cout << rowIdx[k] << "\t" << colIdx[k] << "\t" << values[k] << "\n";
    cout << "\n";
}

// ---------------- Compressed Sparse Row (CSR) Representation ----------------
// A  = non-zero values, row by row
// JA = column index of each value in A (1-indexed)
// IA = starting position of each row inside A/JA, size = ROWS + 1
//      IA[i+1] - IA[i] = number of non-zero elements in row i
void convertToCSR(int mat[ROWS][COLS]) {
    vector<int> A, JA, IA;

    IA.push_back(0);  // row 1 always starts at index 0

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (mat[i][j] != 0) {
                A.push_back(mat[i][j]);
                JA.push_back(j + 1);      // 1-indexed column
            }
        }
        IA.push_back(A.size());  // running total of non-zeros after finishing row i
    }

    cout << "===== CSR (Compressed Sparse Row) Representation =====\n";

    cout << "A  (values)         : [ ";
    for (int v : A) cout << v << " ";
    cout << "]\n";

    cout << "IA (row pointers)   : [ ";
    for (int v : IA) cout << v << " ";
    cout << "]\n";

    cout << "JA (column indices) : [ ";
    for (int v : JA) cout << v << " ";
    cout << "]\n\n";

    cout << "Non-zero count per row  (IA[i+1] - IA[i]):\n";
    for (int i = 0; i < ROWS; i++)
        cout << "  Row " << i + 1 << ": " << IA[i + 1] - IA[i] << " element(s)\n";
    cout << "\n";
}

int main() {
    int mat[ROWS][COLS] = {
        {0, 0, 0, 0, 0,  0, 0, 3, 0},
        {0, 0, 8, 0, 0, 10, 0, 0, 0},
        {0, 0, 0, 0, 0,  0, 0, 0, 0},
        {4, 0, 0, 0, 0,  0, 0, 0, 0},
        {0, 0, 0, 0, 0,  0, 0, 0, 0},
        {0, 0, 2, 0, 0,  0, 0, 0, 0},
        {0, 0, 0, 6, 0,  0, 0, 0, 0},
        {0, 9, 0, 0, 5,  0, 0, 0, 0}
    };

    printMatrix(mat);
    convertToCOO(mat);
    convertToCSR(mat);

    return 0;
}