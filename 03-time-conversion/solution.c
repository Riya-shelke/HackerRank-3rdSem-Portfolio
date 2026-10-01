// Time Conversion (HackerRank) - Strings & Logic
// Time: O(1)  Space: O(1)   (input is always 10 characters: hh:mm:ssAM/PM)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Approach: read the hour, then adjust it.
//   12 AM -> 00,  12 PM -> 12,  other PM -> hour + 12,  other AM -> unchanged.
// Then rebuild the string without the AM/PM suffix.
char* timeConversion(char* s) {
    char* out = malloc(9);              // "hh:mm:ss" + '\0'
    int hour = (s[0] - '0') * 10 + (s[1] - '0');
    char period = s[8];                 // 'A' or 'P'

    if (period == 'A' && hour == 12) hour = 0;
    else if (period == 'P' && hour != 12) hour += 12;

    snprintf(out, 9, "%02d:%c%c:%c%c", hour, s[3], s[4], s[6], s[7]);
    return out;
}

// ---------- local tests (skip this part when pasting into HackerRank) ----------
static void check(const char* in, const char* expected, const char* label) {
    char* got = timeConversion((char*)in);
    printf("%s: %s (got %s)\n", label, strcmp(got, expected) == 0 ? "PASS" : "FAIL", got);
    free(got);
}

int main(void) {
    check("07:05:45PM", "19:05:45", "Test 1 (typical PM)");
    check("12:00:00AM", "00:00:00", "Test 2 (midnight edge)");
    check("12:45:54PM", "12:45:54", "Test 3 (noon edge)");
    check("06:40:03AM", "06:40:03", "Test 4 (typical AM)");
    return 0;
}
