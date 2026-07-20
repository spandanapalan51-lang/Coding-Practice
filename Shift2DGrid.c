/*
Problem: Shift 2D Grid

Given a 2D grid of size m x n and an integer k, shift the grid k times.

In one shift operation:

* grid[i][j] moves to grid[i][j + 1].
* The last element of a row moves to the first position of the next row.
* The bottom-right element moves to the top-left position.

Return the 2D grid after applying k shift operations.

Example:
Input:
grid = [[1,2,3],
[4,5,6],
[7,8,9]]
k = 1

Output:
[[9,1,2],
[3,4,5],
[6,7,8]]

Constraints:
1 <= m, n <= 50
0 <= k <= 100

Time Complexity: O(m * n)
Space Complexity: O(m * n)
*/




#include <stdlib.h>

int** shiftGrid(
    int** grid,
    int gridSize,
    int* gridColSize,
    int k,
    int* returnSize,
    int** returnColumnSizes
) {
    int m = gridSize;
    int n = gridColSize[0];

    int total = m * n;

    k = k % total;

    // Allocate result grid
    int** result = (int**)malloc(m * sizeof(int*));

    *returnColumnSizes =
        (int*)malloc(m * sizeof(int));

    for (int i = 0; i < m; i++) {
        result[i] =
            (int*)malloc(n * sizeof(int));

        (*returnColumnSizes)[i] = n;
    }

    // Move every element to its new position
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {

            int oldIndex = i * n + j;

            int newIndex =
                (oldIndex + k) % total;

            int newRow = newIndex / n;
            int newCol = newIndex % n;

            result[newRow][newCol] =
                grid[i][j];
        }
    }

    *returnSize = m;

    return result;
}
