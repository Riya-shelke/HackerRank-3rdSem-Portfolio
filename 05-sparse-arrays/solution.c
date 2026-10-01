// Sparse Arrays (HackerRank) - Hash Maps / Strings
// Time: O(N + Q)  Space: O(N)   (average case, fixed-length strings)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUCKETS 2048

typedef struct Node {
    char* key;
    int count;
    struct Node* next;
} Node;

// djb2 string hash
static unsigned long hashStr(const char* s) {
    unsigned long h = 5381;
    while (*s) h = h * 33 + (unsigned char)*s++;
    return h % BUCKETS;
}

static Node* findNode(Node** table, const char* key) {
    for (Node* n = table[hashStr(key)]; n; n = n->next)
        if (strcmp(n->key, key) == 0) return n;
    return NULL;
}

// Approach: count every input string once in a hash table (chained buckets),
// then answer each query with a single average-O(1) lookup.
// This avoids the naive O(N * Q) "compare every query to every string" loop.
int* matchingStrings(int strings_count, char** strings, int queries_count, char** queries, int* result_count) {
    Node** table = calloc(BUCKETS, sizeof(Node*));

    for (int i = 0; i < strings_count; i++) {
        Node* n = findNode(table, strings[i]);
        if (n) { n->count++; continue; }
        n = malloc(sizeof(Node));
        n->key = strings[i];                 // no copy needed, strings outlive the table
        n->count = 1;
        unsigned long h = hashStr(strings[i]);
        n->next = table[h];
        table[h] = n;
    }

    int* result = malloc(queries_count * sizeof(int));
    for (int i = 0; i < queries_count; i++) {
        Node* n = findNode(table, queries[i]);
        result[i] = n ? n->count : 0;
    }
    *result_count = queries_count;

    for (int b = 0; b < BUCKETS; b++) {      // free the table
        Node* n = table[b];
        while (n) { Node* next = n->next; free(n); n = next; }
    }
    free(table);
    return result;
}

// ---------- local tests (skip this part when pasting into HackerRank) ----------
static void check(char** s, int sn, char** q, int qn, int* expected, const char* label) {
    int count;
    int* r = matchingStrings(sn, s, qn, q, &count);
    int ok = (count == qn);
    for (int i = 0; ok && i < qn; i++) if (r[i] != expected[i]) ok = 0;
    printf("%s: %s (got", label, ok ? "PASS" : "FAIL");
    for (int i = 0; i < count; i++) printf(" %d", r[i]);
    printf(")\n");
    free(r);
}

int main(void) {
    char* s1[] = {"aba", "baba", "aba", "xzxb"};
    char* q1[] = {"aba", "xzxb", "ab"};
    int e1[] = {2, 1, 0};
    check(s1, 4, q1, 3, e1, "Test 1 (sample)");

    char* s2[] = {"a"};
    char* q2[] = {"a", "b"};
    int e2[] = {1, 0};
    check(s2, 1, q2, 2, e2, "Test 2 (single string, missing query)");

    char* s3[] = {"x", "x", "x", "x"};
    char* q3[] = {"x"};
    int e3[] = {4};
    check(s3, 4, q3, 1, e3, "Test 3 (all duplicates)");
    return 0;
}
