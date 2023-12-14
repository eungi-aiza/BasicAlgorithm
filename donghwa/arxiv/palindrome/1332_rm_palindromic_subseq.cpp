#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string s) {
    int left = 0;
    int right = s.length() - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            return false;
        }
        left++;
        right--;
    }

    return true;
}

int removePalindromeSub(string s) {
    if (s.empty()) {
        return 0;
    }

    if (isPalindrome(s)) {
        return 1;
    }

    // If not a palindrome, you can remove all 'a's in one step and all 'b's in another step
    return 2;
}

int main() {
    string s1 = "ababa";
    cout << "Example 1 Output: " << removePalindromeSub(s1) << endl;  // Output: 1

    string s2 = "abb";
    cout << "Example 2 Output: " << removePalindromeSub(s2) << endl;  // Output: 2

    string s3 = "baabb";
    cout << "Example 3 Output: " << removePalindromeSub(s3) << endl;  // Output: 2

    return 0;
}
