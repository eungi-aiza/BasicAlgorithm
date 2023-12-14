def makePalindrome(s):
    def isPalindrome(s):
        return s == s[::-1]

    s = list(s)
    operations = 0
    left, right = 0, len(s) - 1

    while left <= right:
        if s[left] != s[right]:
            s[left] = min(s[left], s[right])
            s[right] = s[left]
            operations += 1
        left += 1
        right -= 1

    # If there are still more than one operations needed, repeat the process
    if operations > 1:
        return makePalindrome("".join(s))

    return "".join(s)

# Test cases
s1 = "egcfe"
print("Example 1 Output:", makePalindrome(s1))  # Output: "efcfe"

s2 = "abcd"
print("Example 2 Output:", makePalindrome(s2))  # Output: "abba"

s3 = "seven"
print("Example 3 Output:", makePalindrome(s3))  # Output: "neven"
