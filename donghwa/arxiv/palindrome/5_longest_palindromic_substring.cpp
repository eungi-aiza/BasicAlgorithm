#include <iostream>
#include <vector>

using namespace std;

string longestPalindrome(string s) {
    int n = s.length();
    
    // Create a table to store whether a substring is a palindrome or not
    vector<vector<int>> isPalindrome(n, vector<int>(n, 0));

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
    return s.substr(start, max_length);
}

int main() {
    string s1 = "babad";
    string result1 = longestPalindrome(s1);
    cout << "Example 1 Output: " << result1 << endl; // Output: "bab" or "aba"

    string s2 = "cbbd";
    string result2 = longestPalindrome(s2);
    cout << "Example 2 Output: " << result2 << endl; // Output: "bb"

    return 0;
}
