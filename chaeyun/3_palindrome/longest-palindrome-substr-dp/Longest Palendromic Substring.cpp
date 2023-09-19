#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public: 
    string longestPalindrome(string s) {
        int n = s.size();
        if (n == 0) return "";

        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int start = 0;
        int maxLength = 1; 

        // length 1 palindromes
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        // length two palindrome 
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                start = i;
                maxLength = 2;
            }
        }

        // palindrome with more than length=3 (diff=2)
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i < n - len + 1; i++) {
                int j = i + len - 1; // Ending index of the current substring
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    if (len > maxLength) {
                        start = i;
                        maxLength = len;
                    }
                }
            }
        }
        return s.substr(start, maxLength);
    }
};
