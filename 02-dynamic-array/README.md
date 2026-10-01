## Problem: Dynamic Array
**Link:** https://www.hackerrank.com/challenges/dynamic-array/problem
**Topic:** Data Structures / 2D nested sequences

### Approach
Keep n growable arrays (pointer, size, capacity). For every query the index is (x XOR lastAnswer) % n. Type 1 appends y to that sequence; type 2 reads element y % size and stores it as the new lastAnswer. Arrays double in capacity when full so appends stay O(1) amortised.

### Complexity
- Time: O(N + Q)
- Space: O(N + Q)

### Notes
The trick is that lastAnswer changes the target sequence on the next query, so it must be updated only on type-2 queries. Forgetting realloc growth is the easiest bug in C.

### Submission
![Accepted](./accepted.png)
