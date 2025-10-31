
# Set Matrix Zeroes

## 🧩 Problem Statement
Given an `m x n` integer matrix `matrix`, if an element is `0`, set its entire row and column to `0`s.  
You must do it **in place**.

### Example 1:
**Input:**  
`matrix = [[1,1,1],[1,0,1],[1,1,1]]`  
**Output:**  
`[[1,0,1],[0,0,0],[1,0,1]]`

### Example 2:
**Input:**  
`matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]`  
**Output:**  
`[[0,0,0,0],[0,4,5,0],[0,3,1,0]]`

### Constraints:
- `m == matrix.length`  
- `n == matrix[0].length`  
- `1 <= m, n <= 200`  
- `-2^31 <= matrix[i][j] <= 2^31 - 1`

---

## 🧠 Brute Force Approach

### 🔹 Algorithm / Intuition
1. Traverse all cells of the matrix using two nested loops.  
2. If any cell `(i, j)` contains `0`, mark all cells in **row i** and **column j** with `-1` (except those already `0`).  
3. After traversal, replace all `-1` with `0`.

> Note: Assumes the matrix doesn’t contain negative numbers. Otherwise, another marker must be used.

### ⚙️ Code (Brute Force)
```cpp
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(matrix[i][j] == 0) {
                // mark row
                for(int k = 0; k < m; k++) {
                    if(matrix[i][k] != 0) matrix[i][k] = -1;
                }
                // mark column
                for(int k = 0; k < n; k++) {
                    if(matrix[k][j] != 0) matrix[k][j] = -1;
                }
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(matrix[i][j] == -1) matrix[i][j] = 0;
        }
    }
    return matrix;
}
```

### ⏱️ Time Complexity
- **O((N*M)*(N + M)) + O(N*M)**  
- Explanation: Traversing all elements and marking respective rows and columns.

### 💾 Space Complexity
- **O(1)** — no extra data structures used.

---

## 🚀 Better Approach (Using Row and Column Arrays)

### 🔹 Algorithm / Intuition
1. Create two arrays: `row[n]` and `col[m]`, initialized with `0`.
2. Traverse the matrix:
   - If a cell `(i, j)` is `0`, mark `row[i] = 1` and `col[j] = 1`.
3. Traverse again:
   - If `row[i]` or `col[j]` is `1`, set `matrix[i][j] = 0`.

### ⚙️ Code (Better)
```cpp
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> row(n, 0), col(m, 0);

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(matrix[i][j] == 0) {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(row[i] || col[j]) matrix[i][j] = 0;
        }
    }
    return matrix;
}
```

### ⏱️ Time Complexity
- **O(2*(N*M))** → Two passes through the matrix.

### 💾 Space Complexity
- **O(N + M)** → Extra space for `row` and `col` arrays.

---

## 🧮 Optimal Approach (Constant Space)

### 🔹 Algorithm / Intuition
1. Use the **first row** and **first column** of the matrix to store the zero markers.  
   - Keep an extra variable `col0` to handle the first column separately.
2. Traverse the matrix:
   - If `matrix[i][j] == 0`, mark `matrix[i][0] = 0` and `matrix[0][j] = 0`.
3. Modify the cells `(1,1)` to `(n-1,m-1)` based on these markers.
4. Finally, update the first row and first column using `matrix[0][0]` and `col0`.

### ⚙️ Code (Optimal)
```cpp
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    int col0 = 1;

    for(int i = 0; i < n; i++) {
        if(matrix[i][0] == 0) col0 = 0;
        for(int j = 1; j < m; j++) {
            if(matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for(int i = n - 1; i >= 0; i--) {
        for(int j = m - 1; j >= 1; j--) {
            if(matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        }
        if(col0 == 0) matrix[i][0] = 0;
    }
    return matrix;
}
```

### ⏱️ Time Complexity
- **O(2*(N*M))** — Two full traversals of the matrix.

### 💾 Space Complexity
- **O(1)** — In-place modification, no extra space used.

---

## ✅ Summary

| Approach | Time Complexity | Space Complexity | Extra Notes |
|-----------|----------------|------------------|--------------|
| Brute Force | O((N*M)*(N+M)) | O(1) | Marks cells with -1 |
| Better | O(2*N*M) | O(N+M) | Uses extra arrays |
| Optimal | O(2*N*M) | O(1) | In-place using first row & column |
