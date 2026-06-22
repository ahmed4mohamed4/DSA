# Diagonal matrix

Only the elements on the main diagonal may be non-zero. All off-diagonal elements are zero.

Example:

```matlab
4 0 0
0 3 0
0 0 7
```

Property:

- M [i, j] = 0, for all i != j

- **0s take more space and it useless in operations like adding and multiplication. So we just use single dimensional array**