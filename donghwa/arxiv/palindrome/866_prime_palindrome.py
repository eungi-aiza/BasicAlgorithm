def is_prime(num):
    if num <= 1:
        return False
    if num <= 3:
        return True
    if num % 2 == 0 or num % 3 == 0:
        return False
    i = 5
    while i * i <= num:
        if num % i == 0 or num % (i + 2) == 0:
            return False
        i += 6
    return True

def is_palindrome(num):
    return str(num) == str(num)[::-1]

def primePalindrome(n):
    while True:
        if n == 1:
            n = 2
        if is_palindrome(n) and is_prime(n):
            return n
        n += 1

# Test cases
n1 = 6
print("Example 1 Output:", primePalindrome(n1))  # Output: 7

n2 = 8
print("Example 2 Output:", primePalindrome(n2))  # Output: 11

n3 = 13
print("Example 3 Output:", primePalindrome(n3))  # Output: 101
