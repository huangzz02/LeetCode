#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool isPalindromeExtended(int start, int end, char data[]) {
    while (start < end) {
        if (data[start] != data[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}

char* longestPalindrome(char* s) {
    int length = strlen(s);
    char extent_s[2 * length + 4];
    int j = 0;

    extent_s[j++] = '^';
    for (int i = 0; i < length; i++) {
        extent_s[j++] = '#';
        extent_s[j++] = s[i];
    }
    extent_s[j++] = '#';
    extent_s[j++] = '$';
    extent_s[j] = '\0';

    //           [0]       [1]       [2]       [3]
    //            a         b         c         d
    //  ^    #    a    #    b    #    c    #    d    #    $
    // [0]  [1]  [2]  [3]  [4]  [5]  [6]  [7]  [8]  [9]  [10]

    int new_length = j;
    int P[new_length];
    memset(P, 0, sizeof(P));

    int C = 0, R = 0;
    for (int i = 1; i < new_length - 1; i++) {
        int mirror = 2 * C - i;
        if (i < R) {
            P[i] = (R - i < P[mirror]) ? (R - i) : P[mirror];
        }

        while (extent_s[i + 1 + P[i]] == extent_s[i - 1 - P[i]]) {
            P[i]++;
        }

        if (i + P[i] > R) {
            C = i;
            R = i + P[i];
        }
    }

    int max_len = 0;
    int center_index = 0;
    for (int i = 1; i < new_length - 1; i++) {
        if (P[i] > max_len) {
            max_len = P[i];
            center_index = i;
        }
    }

    int start = (center_index - max_len) / 2;
    int end = start + max_len - 1;

    char* result = (char*)malloc((max_len + 1) * sizeof(char));
    strncpy(result, s + start, max_len);
    result[max_len] = '\0';

    return result;
}

// * For the test *
int main() {
    char s[1000];
    scanf("%999s", s);

    char* result = longestPalindrome(s);
    printf("%s\n", result);
    free(result);
    return 0;
}