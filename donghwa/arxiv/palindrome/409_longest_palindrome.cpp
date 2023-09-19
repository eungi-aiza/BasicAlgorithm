
#include <iostream>
#include <unordered_map>

using namespace std;

int longestPalindrome(string s) {
    // Create an unordered_map to store character frequencies
    unordered_map<char, int> char_count;

    // Count the frequency of each character in the string
    for (char c : s) {
        char_count[c]++;
    }

    int max_length = 0;
    bool odd_count_used = false;

    // Iterate through the character counts
    for (const auto& pair : char_count) {
        int count = pair.second;
        // If the count is even, it can be used as is
        if (count % 2 == 0) {
            max_length += count;
        } else {
            // If the count is odd, use it as even (count - 1) and mark that an odd count character is used
            max_length += count - 1;
            odd_count_used = true;
        }
    }

    // If an odd count character was used, add 1 to the length
    if (odd_count_used) {
        max_length += 1;
    }

    return max_length;
}

int main() {
    string s1 = "abccccdd";
    cout << "Example 1 Output: " << longestPalindrome(s1) << endl;  // Output: 7

    string s2 = "a";
    cout << "Example 2 Output: " << longestPalindrome(s2) << endl;  // Output: 1

    return 0;
}
