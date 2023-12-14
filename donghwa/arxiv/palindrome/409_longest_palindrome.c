/* Longest Palindrome

Given a string s which consists of lowercase or uppercase letters, return the length of the longest palindrome that can be built with those letters.

Letters are case sensitive, for example, "Aa" is not considered a palindrome here.

Example 1:

Input: s = "abccccdd"
Output: 7
Explanation: One longest palindrome that can be built is "dccaccd", whose length is 7.
Example 2:

Input: s = "a"
Output: 1
Explanation: The longest palindrome that can be built is "a", whose length is 1.
*/
#include <stdio.h>
#include <string.h>

int longestPalindrome(char* s) {
    // Create an array to store character frequencies
    int char_count[128] = {0};  // Assuming ASCII characters

    // Count the frequency of each character in the string
    for (int i = 0; s[i] != '\0'; i++) {
        char_count[s[i]]++;
    }

    int max_length = 0;
    int odd_count_used = 0;

    // Iterate through the character counts
    for (int i = 0; i < 128; i++) {
        int count = char_count[i];
        // If the count is even, it can be used as is
        if (count % 2 == 0) {
            max_length += count;
        } else {
            // If the count is odd, use it as even (count - 1) and mark that an odd count character is used
            max_length += count - 1;
            odd_count_used = 1;
        }
    }

    // If an odd count character was used, add 1 to the length
    if (odd_count_used) {
        max_length += 1;
    }

    return max_length;
}

int main() {
    char s1[] = "abccccdd";
    printf("Example 1 Output: %d\n", longestPalindrome(s1));  // Output: 7

    char s2[] = "a";
    printf("Example 2 Output: %d\n", longestPalindrome(s2));  // Output: 1

    return 0;
}
