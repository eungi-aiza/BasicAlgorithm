def longestPalindrome(s):
    # Create a dictionary to store character frequencies
    char_count = {}

    # Count the frequency of each character in the string
    for char in s:
        char_count[char] = char_count.get(char, 0) + 1

    # Initialize variables for the length of the longest palindrome and whether an odd count character is used
    max_length = 0
    odd_count_used = False

    # Iterate through the character counts
    for count in char_count.values():
        # If the count is even, it can be used as is
        if count % 2 == 0:
            max_length += count
        # If the count is odd, use it as even (count - 1) and mark that an odd count character is used
        else:
            max_length += count - 1
            odd_count_used = True

    # If an odd count character was used, add 1 to the length
    if odd_count_used:
        max_length += 1

    return max_length

# Test cases
s1 = "abccccdd"
print("Example 1 Output:", longestPalindrome(s1))  # Output: 7

s2 = "a"
print("Example 2 Output:", longestPalindrome(s2))  # Output: 1
