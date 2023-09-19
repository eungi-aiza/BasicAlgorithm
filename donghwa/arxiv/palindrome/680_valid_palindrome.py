def isPalindrome(s):
    # Helper function to check if a string is a palindrome
    def palindrome(s):
        return s == s[::-1]

    left, right = 0, len(s) - 1

    while left < right:
        if s[left] != s[right]:
            # If characters at the current positions are different, check two possibilities:
            # 1. Remove the character at the left position and check the remaining substring
            # 2. Remove the character at the right position and check the remaining substring
            return palindrome(s[left:right]) or palindrome(s[left + 1:right + 1])
        left += 1
        right -= 1

    return True

# Test cases
s1 = "aba"
print("Example 1 Output:", isPalindrome(s1))  # Output: True

s2 = "abca"
print("Example 2 Output:", isPalindrome(s2))  # Output: True

s3 = "abc"
print("Example 3 Output:", isPalindrome(s3))  # Output: False
