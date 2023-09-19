#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s) {
    // Helper function to check if a string is a palindrome
    bool palindrome(const string& str, int start, int end) {
        while (start < end) {
            if (str[start] != str[end]) {
                return false;
            }
            start++;
            end--;
        }
        return true;
    }

    int left = 0;
    int right = s.length() - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            // If characters at the current positions are different, check two possibilities:
            // 1. Remove the character at the left position and check the remaining substring
            // 2. Remove the character at the right position and check the remaining substring
            return palindrome(s, left, right - 1) || palindrome(s, left + 1, right);
        }
        left++;
        right--;
    }

    return true;
}

int main() {
    string s1 = "aba";
    cout << "Example 1 Output: " << (isPalindrome(s1) ? "true" : "false") << endl;  // Output: true

    string s2 = "abca";
    cout << "Example 2 Output: " << (isPalindrome(s2) ? "true" : "false") << endl;  // Output: true

    string s3 = "abc";
    cout << "Example 3 Output: " << (isPalindrome(s3) ? "true" : "false") << endl;  // Output: false

    return 0;
}
