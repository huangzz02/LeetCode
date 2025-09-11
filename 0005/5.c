#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool isPalindrome(int start, int end, char data[]) {
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
    //  ^    #    a    #    b    #    c    #    d    #    ^
    // [0]  [1]  [2]  [3]  [4]  [5]  [6]  [7]  [8]  [9]  [10]
    
    int new_length = j;
    int P[new_length];
    P[0] = 0; P[new_length - 1] = 0;
    int C = 1, R = 1;
    int start, end;
    for (int i = 1; i < new_length - 1; i++) {
        P[i] = 0;
        if (i > R) {
            start = i;
            end = i;
        } else {
            P[i] += P[C - (i - C)];
            if (P[i] + i < R) {
                continue;
            } else if (P[i] + i >= R) {
                P[i] = R - i;
                start = i - (R - i);
                end = R;
            }
        }

        if (start - 1 < 0 || end + 1 >= new_length) continue;
        start--;
        end++;

        while (isPalindrome(start, end, extent_s)) {
            P[i]++;
            if (end > R) {
                C = i;
                R = end;
            }
            if (start - 1 < 0 || end + 1 >= new_length) break;
            start--;
            end++;
        }
    }

    int max = -1, max_i = -1;
    for (int i = 0; i < new_length; i++) {
        if (P[i] > max) {
            max = P[i];
            max_i = i;
        }
    }
    int ans_L = (max_i - max - 1) / 2;
    int ans_R = (max_i + max - 3) / 2;
    int result_length = ans_R - ans_L + 1;

    char* ans = (char*)malloc((result_length + 1) * sizeof(char));
    for (int i = 0; i < result_length; i++) {
        ans[i] = s[ans_L + i];
    }
    ans[result_length] = '\0';

    return ans;
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