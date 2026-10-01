## Problem: Time Conversion
**Link:** https://www.hackerrank.com/challenges/time-conversion/problem
**Topic:** Strings & Logic

### Approach
Parse the hour from the first two characters and look at the AM/PM letter. 12 AM becomes 00, 12 PM stays 12, any other PM hour gets +12, other AM hours are unchanged. Rebuild the string as hh:mm:ss with snprintf, dropping the suffix.

### Complexity
- Time: O(1)
- Space: O(1)

### Notes
The two 12 o'clock cases are the only tricky part: 12:00:00AM is 00:00:00 but 12:45:54PM stays 12:45:54.

### Submission
![Accepted](./accepted.png)
