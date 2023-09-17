def str_perms(s:str)->list:
    tmp = ""
    out = []
    isused = [False for _ in range(len(s))]
    def backtrack(k, tmp): # k번째 알파벳을 입력.
        if (k == len(s)):
            out.append(tmp)
            return
        for i in range(len(s)):
            if(not isused[i]):
                isused[i] = 1
                tmp += s[i]
                backtrack(k+1, tmp)
                isused[i] = 0
                tmp = tmp[:-1]
    backtrack(0, tmp)
    out = list(set(out))
    out.sort()
    return out

print(str_perms("abc"))
print(str_perms("abb"))
print(str_perms("abcd"))