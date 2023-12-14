/* 2217. Find Palindrome With Fixed Length
Given an integer array queries and a positive integer intLength, return an array answer where answer[i] is either the queries[i]th smallest positive palindrome of length intLength or -1 if no such palindrome exists.

A palindrome is a number that reads the same backwards and forwards. Palindromes cannot have leading zeros.

 

Example 1:

Input: queries = [1,2,3,4,5,90], intLength = 3
Output: [101,111,121,131,141,999]
Explanation:
The first few palindromes of length 3 are:
101, 111, 121, 131, 141, 151, 161, 171, 181, 191, 202, ...
The 90th palindrome of length 3 is 999.
Example 2:

Input: queries = [2,4,6], intLength = 4
Output: [1111,1331,1551]
Explanation:
The first six palindromes of length 4 are:
1001, 1111, 1221, 1331, 1441, and 1551.


*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool is_prime(int num) {
    if (num <= 1) {
        return false;
    }
    if (num <= 3) {
        return true;
    }
    if (num % 2 == 0 || num % 3 == 0) {
        return false;
    }
    int i = 5;
    while (i * i <= num) {
        if (num % i == 0 || num % (i + 2) == 0) {
            return false;
        }
        i += 6;
    }
    return true;
}

bool is_palindrome(int num) {
    char str[15]; // Sufficient for 2 * 10^8
    sprintf(str, "%d", num);
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            return false;
        }
    }
    return true;
}

int primePalindrome(int n) {
    while (1) {
        if (n == 1) {
            n = 2;
        }
        if (is_palindrome(n) && is_prime(n)) {
            return n;
        }
        n++;
    }
}

int main() {
    int n1 = 6;
    printf("Example 1 Output: %d\n", primePalindrome(n1)); // Output: 7

    int n2 = 8;
    printf("Example 2 Output: %d\n", primePalindrome(n2)); // Output: 11

    int n3 = 13;
    printf("Example 3 Output: %d\n", primePalindrome(n3)); // Output: 101

    return 0;
}
