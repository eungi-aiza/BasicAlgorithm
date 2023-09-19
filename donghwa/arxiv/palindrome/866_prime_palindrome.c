/*
Given an integer n, return the smallest prime palindrome greater than or equal to n.

An integer is prime if it has exactly two divisors: 1 and itself. Note that 1 is not a prime number.

For example, 2, 3, 5, 7, 11, and 13 are all primes.
An integer is a palindrome if it reads the same from left to right as it does from right to left.

For example, 101 and 12321 are palindromes.
The test cases are generated so that the answer always exists and is in the range [2, 2 * 108].
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
