"""
dp[i][j] to indicate whether the substring from index i to index j is a palindrome or not

Approach : 
dp[i][j] = (s[i] == s[j]) and dp[i+1][j-1]
"""

class Solution:
    def countSubstrings(self, s: str) -> int:
        n = len(s)
        dp = [[False] * n for _ in range(n)]
        count = 0
        
        # base cases
        for i in range(n):
            dp[i][i] = True
            count += 1
        
        for i in range(n-1):
            dp[i][i+1] = (s[i] == s[i+1])
            count += dp[i][i+1]
        
        # recurrence relation
        for l in range(3, n+1):
            for i in range(n-l+1):
                j = i + l - 1
                dp[i][j] = (s[i] == s[j]) and dp[i+1][j-1]
                count += dp[i][j]
        
        return count

