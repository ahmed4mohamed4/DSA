# Sparse Matrix
It is a matrix in which most of the elements are zero.

Example:

```matlab
0 0 0 0 0 0 0 3 0
0 0 8 0 0 10 0 0 0
0 0 0 0 0 0 0 0 0
4 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 2 0 0 0 0 0 0
0 0 0 6 0 0 0 0 0
0 9 0 0 5 0 0 0 0
```

<image src="./images/sparse_matrix.png" alt="Sparse Matrix" width="400"/>

## Sparse Matrix Representation
- Coordinate List (COO) or 3-column representation
- Compressed Sparse Row (CSR)

### Coordinate List (COO) - 3-column representation
we store **(row, column, value)** for each non-zero element in the matrix.:

#### Just first row contains size of the matrix and number of non-zero elements

| Row | Column | Value |
|-----|--------|-------|
| 8 | 9 | 8 |
| 1 | 8 | 3 |
| 2 | 3 | 8 |
| 2 | 6 | 10 |
| 4 | 1 | 4 |
| 6 | 3 | 2 |
| 7 | 4 | 6 |
| 8 | 2 | 9 |
| 8 | 5 | 5 |

<image src="./images/coo.png" alt="COO Representation" width="400"/>


### Compressed Sparse Row (CSR)
- we store the non-zero values of the matrix in a 1D array.
- We store the starting index of each row in a 1D array. Its size is m + 1 (m = number of rows). The difference IA[i+1] - IA[i] tells us how many non-zero elements exist in row i.
- we store the column indices of the non-zero elements in a 1D array.

<image src="./images/csr.png" alt="CSR Representation" width="400"/>