def removePalindromeSub(s):
    def is_palindrome(s):
        return s == s[::-1]

    if not s:
        return 0

    if is_palindrome(s):
        return 1

    # If not a palindrome, you can remove all 'a's in one step and all 'b's in another step
    return 2

# Test cases
s1 = "ababa"
print("Example 1 Output:", removePalindromeSub(s1))  # Output: 1

s2 = "abb"
print("Example 2 Output:", removePalindromeSub(s2))  # Output: 2

s3 = "baabb"
print("Example 3 Output:", removePalindromeSub(s3))  # Output: 2
