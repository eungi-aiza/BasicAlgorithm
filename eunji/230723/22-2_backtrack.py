def str_perm(s):
    s = list(s)
    def bt(s, n):
        result = []

        if n == 0:
            return [[]]

        for i, elem in enumerate(s): 
            for next in bt(s[:i] + s[i+1:], n-1):
                result += [[elem]+next]
                
        return result
    
    ans = []
    perm = bt(s, 3)
    for i in range(len(perm)):
        temp = ""
        for j in perm[i]:
            temp += j
        ans.append(temp)
    ans = sorted(list(set(ans)))
    return ans
        
        
    
    