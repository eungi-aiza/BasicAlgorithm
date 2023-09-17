def palindrome(s):
    return s == s[-1::-1] # 뒤집기 = s[::-1]

def substring(s, t):
    return t in s

def max_palindromes(s):
    ret = []
    sidx = 0
    for sidx in range(len(s)):
        pd = s[sidx]
        for eidx in range(sidx + 1, len(s) + 1):
            if palindrome(s[sidx:eidx]):
                pd = s[sidx:eidx]
        for prev in ret:
            if substring(prev, pd):
                pd = None
                break
        if pd:
            ret.append(pd)
    return ret