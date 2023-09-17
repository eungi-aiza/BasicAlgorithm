
def str_perm_help(s, perm, res):
    if (len(s)==0):
        if perm not in res :
            res.append(perm)
        return 
    for i in range(len(s)):
        str_perm_help(s[:i]+s[i+1:], perm+s[i], res)


def str_perm(s):
    result = []
    str_perm_help(s, "", result)
    return result

if __name__== "__main__":
    s = input().rstrip()
    res = str_perm(s)
    print(sorted(res))