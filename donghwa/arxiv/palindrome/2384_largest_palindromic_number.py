
def largestPalindrome(num: str) -> str:

    ans = []
    b = [str(x) for x in range(9, -1, -1)]
    from collections import defaultdict

    a = defaultdict(int)

    for x in num:
        a[x] += 1

    for x in b:
        n = len(ans)
        if n % 2 == 0:
            if a[x] > 0:
                ans = ans[:n // 2] + [x] * a[x] + ans[n // 2:]
        else:
            if x == '0':
                if len(ans) != 1:
                    ans = ans[:n // 2] + [x] * (a[x] // 2) + [ans[n // 2]] + [x] * (a[x] // 2) + ans[n // 2 + 1:]
            else:
                if a[x] >= 2:
                    ans = ans[:n // 2] + [x] * (a[x] // 2) + [ans[n // 2]] + [x] * (a[x] // 2) + ans[n // 2 + 1:]

    res = "".join(ans)
    return str(int(res))

# Test cases
num1 = "444947137"
print("Example 1 Output:", largestPalindrome(num1))  # Output: "7449447"

num2 = "00009"
print("Example 2 Output:", largestPalindrome(num2))  # Output: "9"
