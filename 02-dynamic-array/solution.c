// Dynamic Array (HackerRank) - Data Structures / 2D nested sequences
// Time: O(N + Q)  Space: O(N + Q)

#include <stdio.h>
#include <stdlib.h>

// Approach: keep n growable arrays (data pointer + size + capacity).
// For each query: idx = (x ^ lastAnswer) % n.
//   type 1 -> append y to seq[idx]
//   type 2 -> lastAnswer = seq[idx][y % size(seq[idx])], record it
int* dynamicArray(int n, int queries_rows, int queries_columns, int** queries, int* result_count) {
    int** seq = calloc(n, sizeof(int*));
    int*  size = calloc(n, sizeof(int));
    int*  cap  = calloc(n, sizeof(int));
    int*  result = malloc(queries_rows * sizeof(int));
    int lastAnswer = 0;
    *result_count = 0;

    for (int q = 0; q < queries_rows; q++) {
        int type = queries[q][0], x = queries[q][1], y = queries[q][2];
        int idx = (x ^ lastAnswer) % n;

        if (type == 1) {
            if (size[idx] == cap[idx]) {                 // grow when full
                cap[idx] = cap[idx] ? cap[idx] * 2 : 4;
                seq[idx] = realloc(seq[idx], cap[idx] * sizeof(int));
            }
            seq[idx][size[idx]++] = y;
        } else {
            lastAnswer = seq[idx][y % size[idx]];
            result[(*result_count)++] = lastAnswer;
        }
    }

    for (int i = 0; i < n; i++) free(seq[i]);
    free(seq); free(size); free(cap);
    return result;
}

// ---------- local tests (skip this part when pasting into HackerRank) ----------
static void check(int n, int q[][3], int qn, int* expected, int en, const char* label) {
    int** queries = malloc(qn * sizeof(int*));
    for (int i = 0; i < qn; i++) {
        queries[i] = malloc(3 * sizeof(int));
        for (int j = 0; j < 3; j++) queries[i][j] = q[i][j];
    }
    int count;
    int* res = dynamicArray(n, qn, 3, queries, &count);
    int ok = (count == en);
    for (int i = 0; ok && i < en; i++) if (res[i] != expected[i]) ok = 0;
    printf("%s: %s (got %d answers)\n", label, ok ? "PASS" : "FAIL", count);
    free(res);
    for (int i = 0; i < qn; i++) free(queries[i]);
    free(queries);
}

int main(void) {
    // Sample: n=2, expected outputs 7 then 3
    int q1[5][3] = {{1,0,5},{1,1,7},{1,0,3},{2,1,0},{2,1,1}};
    int e1[] = {7, 3};
    check(2, q1, 5, e1, 2, "Test 1 (sample)");

    // Edge: single sequence (n=1), lastAnswer changes but idx always 0
    int q2[3][3] = {{1,0,9},{1,0,4},{2,0,1}};
    int e2[] = {4};
    check(1, q2, 3, e2, 1, "Test 2 (n = 1)");

    // Edge: no type-2 query -> empty output
    int q3[2][3] = {{1,0,1},{1,1,2}};
    check(2, q3, 2, NULL, 0, "Test 3 (no type-2 queries)");
    return 0;
}
