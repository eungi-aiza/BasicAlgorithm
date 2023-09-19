/* 680. Valid Palindrome II
Given a string s, return true if the s can be palindrome after deleting at most one character from it.

 

Example 1:

Input: s = "aba"
Output: true
Example 2:

Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.
Example 3:

Input: s = "abc"
Output: false
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(char* s) {
    // Helper function to check if a string is a palindrome
    bool palindrome(const char* str, int len) {
        for (int i = 0; i < len / 2; i++) {
            if (str[i] != str[len - i - 1]) {
                return false;
            }
        }
        return true;
    }

    int left = 0;
    int right = strlen(s) - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            // If characters at the current positions are different, check two possibilities:
            // 1. Remove the character at the left position and check the remaining substring
            // 2. Remove the character at the right position and check the remaining substring
            return palindrome(s + left, right - left) || palindrome(s + left + 1, right - left);
        }
        left++;
        right--;
    }

    return true;
}

int main() {
    char s1[] = "aba";
    printf("Example 1 Output: %s\n", isPalindrome(s1) ? "true" : "false");  // Output: true

    char s2[] = "abca";
    printf("Example 2 Output: %s\n", isPalindrome(s2) ? "true" : "false");  // Output: true

    char s3[] = "abc";
    printf("Example 3 Output: %s\n", isPalindrome(s3) ? "true" : "false");  // Output: false

    return 0;
}
