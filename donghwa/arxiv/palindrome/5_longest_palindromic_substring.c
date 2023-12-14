/* 5. Longest Panlindromic Substring

Given a string s, return the longest 
palindromic
 
substring
 in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* longestPalindrome(char* s) {
    int n = strlen(s);
    
    // Create a table to store whether a substring is a palindrome or not
    int** isPalindrome = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        isPalindrome[i] = (int*)malloc(n * sizeof(int));
        memset(isPalindrome[i], 0, n * sizeof(int));
    }

    int start = 0; // Starting index of the longest palindromic substring
    int max_length = 1; // Length of the longest palindromic substring

    // All substrings of length 1 are palindromes
    for (int i = 0; i < n; i++) {
        isPalindrome[i][i] = 1;
    }

    // Check for palindromic substrings of length 2
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            isPalindrome[i][i + 1] = 1;
            start = i;
            max_length = 2;
        }
    }

    // Check for palindromic substrings of length greater than 2
    for (int length = 3; length <= n; length++) {
        for (int i = 0; i < n - length + 1; i++) {
            int j = i + length - 1; // Ending index of the current substring

            // Check if the current substring is a palindrome
            if (isPalindrome[i + 1][j - 1] && s[i] == s[j]) {
                isPalindrome[i][j] = 1;

                // Update the longest palindromic substring if needed
                if (length > max_length) {
                    start = i;
                    max_length = length;
                }
            }
        }
    }

    // Extract the longest palindromic substring
    char* result = (char*)malloc((max_length + 1) * sizeof(char));
    strncpy(result, s + start, max_length);
    result[max_length] = '\0';

    // Free memory
    for (int i = 0; i < n; i++) {
        free(isPalindrome[i]);
    }
    free(isPalindrome);

    return result;
}

int main() {
    char s1[] = "babad";
    char* result1 = longestPalindrome(s1);
    printf("Example 1 Output: %s\n", result1); // Output: "bab" or "aba"
    free(result1);

    char s2[] = "cbbd";
    char* result2 = longestPalindrome(s2);
    printf("Example 2 Output: %s\n", result2); // Output: "bb"
    free(result2);

    return 0;
}
