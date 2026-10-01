## Problem: Sparse Arrays
**Link:** https://www.hackerrank.com/challenges/sparse-arrays/problem
**Topic:** Hash Maps / Strings

### Approach
Count every input string once in a hash table (djb2 hash, chained buckets), then answer each query with a single lookup. This avoids the naive O(N x Q) approach of comparing every query against every string.

### Complexity
- Time: O(N + Q) average
- Space: O(N)

### Notes
C has no built-in hash map, so I wrote a small chained one. A query that never appeared must return 0, not garbage.

### Submission
![Accepted](./accepted.png)
