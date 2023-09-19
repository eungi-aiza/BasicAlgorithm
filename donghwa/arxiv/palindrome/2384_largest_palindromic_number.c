/* 2384. Largest Palindromic Number

You are given a string num consisting of digits only.

Return the largest palindromic integer (in the form of a string) that can be formed using digits taken from num. It should not contain leading zeroes.

Notes:

You do not need to use all the digits of num, but you must use at least one digit.
The digits can be reordered.
 

Example 1:

Input: num = "444947137"
Output: "7449447"
Explanation: 
Use the digits "4449477" from "444947137" to form the palindromic integer "7449447".
It can be shown that "7449447" is the largest palindromic integer that can be formed.
Example 2:

Input: num = "00009"
Output: "9"
Explanation: 
It can be shown that "9" is the largest palindromic integer that can be formed.
Note that the integer returned should not contain leading zeroes.

*/#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* largestPalindromic(char* num) {
    int digits_count[10] = {0};
    char* lp = (char*)malloc((strlen(num) + 1) * sizeof(char));
    char* rp = (char*)malloc((strlen(num) + 1) * sizeof(char));
    int lp_len = 0, rp_len = 0;

    for (int i = 0; i < strlen(num); i++) {
        digits_count[num[i] - '0']++;
    }

    for (int i = 0; i < strlen(num); i++) {
        for (int j = 9; j >= 0; j--) {
            if (digits_count[j] > 1 && (j > 0 || lp_len > 0)) {
                lp[lp_len++] = '0' + j;
                rp[rp_len++] = '0' + j;
                digits_count[j] -= 2;
                break;
            }
        }
    }

    for (int i = 9; i >= 0; i--) {
        if (digits_count[i]) {
            lp[lp_len++] = '0' + i;
            break;
        }
    }

    for (int i = rp_len - 1; i >= 0; i--) {
        lp[lp_len++] = rp[i];
    }

    lp[lp_len] = '\0';
    free(rp);

    return lp;
}

int main() {
    char num1[] = "444947137";
    char* result1 = largestPalindromic(num1);
    printf("Example 1 Output: %s\n", result1);  // Output: "7449447"
    free(result1);

    char num2[] = "00009";
    char* result2 = largestPalindromic(num2);
    printf("Example 2 Output: %s\n", result2);  // Output: "9"
    free(result2);

    return 0;
}
