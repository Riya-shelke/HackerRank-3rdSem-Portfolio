// Compare the Triplets (HackerRank) - Basic Implementation
// Time: O(1)  Space: O(1)   (always exactly 3 elements per triplet)

#include <stdio.h>
#include <stdlib.h>

// Approach: compare a[i] and b[i] for each of the 3 categories.
// The bigger rating earns its owner 1 point; a tie earns nobody a point.
int* compareTriplets(int a_count, int* a, int b_count, int* b, int* result_count) {
    int* result = calloc(2, sizeof(int));   // result[0] = Alice, result[1] = Bob
    for (int i = 0; i < a_count; i++) {
        if (a[i] > b[i]) result[0]++;
        else if (a[i] < b[i]) result[1]++;
    }
    *result_count = 2;
    return result;
}

// ---------- local tests (skip this part when pasting into HackerRank) ----------
static void check(int a[3], int b[3], int ea, int eb, const char* label) {
    int count;
    int* r = compareTriplets(3, a, 3, b, &count);
    printf("%s: %s (got %d %d)\n", label, (r[0] == ea && r[1] == eb) ? "PASS" : "FAIL", r[0], r[1]);
    free(r);
}

int main(void) {
    int a1[3] = {5, 6, 7}, b1[3] = {3, 6, 10};
    check(a1, b1, 1, 1, "Test 1 (sample)");
    int a2[3] = {4, 4, 4}, b2[3] = {4, 4, 4};
    check(a2, b2, 0, 0, "Test 2 (all ties)");
    int a3[3] = {10, 10, 10}, b3[3] = {1, 1, 1};
    check(a3, b3, 3, 0, "Test 3 (Alice wins every category)");
    return 0;
}
