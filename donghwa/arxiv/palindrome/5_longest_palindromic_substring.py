def longestPalindrome(s):
    n = len(s)
    # Create a table to store whether a substring is a palindrome or not
    is_palindrome = [[False] * n for _ in range(n)]

    start = 0  # Starting index of the longest palindromic substring
    max_length = 1  # Length of the longest palindromic substring

    # All substrings of length 1 are palindromes
    for i in range(n):
        is_palindrome[i][i] = True

    # Check for palindromic substrings of length 2
    for i in range(n - 1):
        if s[i] == s[i + 1]:
            is_palindrome[i][i + 1] = True
            start = i
            max_length = 2

    # Check for palindromic substrings of length greater than 2
    for length in range(3, n + 1):
        for i in range(n - length + 1):
            j = i + length - 1  # Ending index of the current substring

            # Check if the current substring is a palindrome
            if is_palindrome[i + 1][j - 1] and s[i] == s[j]:
                is_palindrome[i][j] = True

                # Update the longest palindromic substring if needed
                if length > max_length:
                    start = i
                    max_length = length

    return s[start:start + max_length]

# Test cases
s1 = "babad"
print("Example 1 Output:", longestPalindrome(s1))  # Output: "bab" or "aba"

s2 = "cbbd"
print("Example 2 Output:", longestPalindrome(s2))  # Output: "bb"
