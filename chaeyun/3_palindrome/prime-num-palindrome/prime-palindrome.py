"""
Given an integer n, return the smallest prime palindrome greater than or equal to n.

[input and output]
Example 1:

Input: n = 6
Output: 7
Example 2:

Input: n = 8
Output: 11
Example 3:

Input: n = 13
Output: 101

[description]

An integer is prime if it has exactly two divisors: 1 and itself. Note that 1 is not a prime number.

For example, 2, 3, 5, 7, 11, and 13 are all primes.
An integer is a palindrome if it reads the same from left to right as it does from right to left.

For example, 101 and 12321 are palindromes.
The test cases are generated so that the answer always exists and is in the range [2, 2 * 108].

"""
# 1>Check if n is a palindrome. If it is, check if it is a prime number. If it is, return n.
# 2>Otherwise, increment n by 1 and repeat step 1 until a palindrome prime is found.

class Solution:
    def primePalindrome(self, n: int) -> int:
#1 best 
        def is_palindrome(x):
            return str(x) == str(x)[::-1]
        
        def is_prime(x):
            if x < 2:
                return False
            for i in range(2, int(x ** 0.5) + 1):
                if x % i == 0:
                    return False
            return True
        
        while True:
            if is_palindrome(n) and is_prime(n):
                return n
            n += 1
            if 10**7 < n < 10**8:
                n = 10**8
        

        #2 TLE
        # def is_prime(number):
        #     if number > 1:
        #         for num in range(2, number):
        #             if number % num == 0:
        #                 return False
        #         return True
        #     return False

        # n_str = str(n)
        # l = len(n_str)        
        # for k in range(max(0, l//2-1), 5):
        #     for i in range(10**k, 10**(k+1)):                            # odd length
        #         i_str = str(i)
        #         if k > 0 and i_str[0] in ['2','4','5','6','8']: continue # pruning
        #         cur = i_str + i_str[-2::-1]
        #         cur_int = int(cur)
        #         if cur_int >= n and is_prime(cur_int): 
        #             return cur_int
                
        #     for i in range(10**k, 10**(k+1)):                            # even length
        #         i_str = str(i)
        #         if i_str[0] in ['2','4','5','6','8']: continue           # pruning
        #         cur = i_str + i_str[::-1]
        #         cur_int = int(cur)
        #         if cur_int >= n and is_prime(cur_int): 
        #             return cur_int
        # return -1


        # #3 TLE
        # if 8 <= n <= 11: return 11
        # for x in range(10 ** (len(str(n))// 2), 10**5):
        #     y = int(str(x) + str(x)[-2::-1])
        #     if y >= n and is_prime(y): return y