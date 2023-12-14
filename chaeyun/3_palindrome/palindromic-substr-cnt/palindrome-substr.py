"""
Given a string s, return the number of palindromic substrings in it.
A string is a palindrome when it reads the same backward as forward.
A substring is a contiguous sequence of characters within the string.


Example 1:

Input: s = "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
Example 2:

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

"""
class Solution:
    def countSubstrings(self, s: str) -> int:
        sub = []
        for indi, i in enumerate(s):
            for indj, j in enumerate(s[indi:], start=indi):
                if i == j and s[indi:indj+1] == s[indi:indj+1][::-1]:
                    sub.append(s[indi:indj+1])
        return len(sub)