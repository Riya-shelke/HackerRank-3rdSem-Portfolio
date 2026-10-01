// Diagonal Difference (HackerRank) - 2D Arrays / Matrices
// Time: O(N)  Space: O(1)   (N = number of rows/columns of the square matrix)

#include <stdio.h>
#include <stdlib.h>

// Approach: walk the matrix once. Row i contributes arr[i][i] to the
// primary diagonal and arr[i][n-1-i] to the secondary diagonal.
// Answer is the absolute difference of the two sums.
int diagonalDifference(int arr_rows, int arr_columns, int** arr) {
    int primary = 0, secondary = 0;
    for (int i = 0; i < arr_rows; i++) {
        primary   += arr[i][i];
        secondary += arr[i][arr_columns - 1 - i];
    }
    return abs(primary - secondary);
}

// ---------- local tests (skip this part when pasting into HackerRank) ----------
static int check(int n, int data[][4], int expected, const char* label) {
    int** arr = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        arr[i] = malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) arr[i][j] = data[i][j];
    }
    int got = diagonalDifference(n, n, arr);
    printf("%s: %s (got %d)\n", label, got == expected ? "PASS" : "FAIL", got);
    for (int i = 0; i < n; i++) free(arr[i]);
    free(arr);
    return got == expected;
}

int main(void) {
    int t1[4][4] = {{11, 2, 4}, {4, 5, 6}, {10, 8, -12}};
    check(3, t1, 15, "Test 1 (sample, 3x3)");
    int t2[4][4] = {{7}};
    check(1, t2, 0, "Test 2 (1x1 matrix)");
    int t3[4][4] = {{1, 2}, {3, 4}};
    check(2, t3, 0, "Test 3 (2x2, equal diagonals)");
    return 0;
}
