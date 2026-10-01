## Problem: Diagonal Difference
**Link:** https://www.hackerrank.com/challenges/diagonal-difference/problem
**Topic:** 2D Arrays / Matrices

### Approach
Walk the square matrix once. Row i adds arr[i][i] to the primary diagonal sum and arr[i][n-1-i] to the secondary diagonal sum, then return the absolute difference. No extra storage is needed.

### Complexity
- Time: O(N) (N = matrix dimension)
- Space: O(1)

### Notes
A 1x1 matrix is a good edge case: both diagonals are the same element, so the answer is 0. Negative numbers are why abs() is needed.

### Submission
![Accepted](./accepted.png)
