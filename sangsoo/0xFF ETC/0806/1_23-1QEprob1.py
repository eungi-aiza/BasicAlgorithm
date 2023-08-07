def str_perm(s)->list:
    n = len(s)
    isused = [False for _ in range(n)]
    out = []
    def backtrack(k:int, tmp: str) -> None:
        if (k == n):
            out.append(tmp)
            return
        for i in range(n):
            if (not isused[i]):
                isused[i] = True
                tmp += s[i]
                backtrack(k+1, tmp)
                isused[i] = False
                tmp = tmp[:-1]
    backtrack(0, "")
    return out

def make_dict(s: str)->dict:
    d = {}
    # make a dict with sets(value)
    for i in range(len(s)):
        d[s[i]] = set()
    for i in range(len(s)):
        if i == 0:
            d[s[i]].add(s[i+1])
        elif i == len(s) - 1:
            d[s[i]].add(s[i-1])
        else:
            d[s[i]].add(s[i+1])
            d[s[i]].add(s[i-1])
    return d

def check(l:list, d: dict)->list:
    out = []
    for st in l:
        valid = True
        for i in range(len(st)):
            if i == 0:
                if st[i] in d[st[i+1]]:
                    valid = False
                    break
            elif i == len(st) - 1:
                if st[i] in d[st[i-1]]:
                    valid = False
                    break
            else:
                if st[i] in d[st[i+1]]:
                    valid = False
                    break
                if st[i] in d[st[i-1]]:
                    valid = False
                    break
        if valid:
            out.append(st)
    return out


def foo(s: str) -> str:
    d = make_dict(s)
    l = str_perm(s)
    return check(l, d)[0] if check(l, d) else ""

def dedupl(s: str)-> str:
    out = ""
    for i in range(len(s)):
        if s[i] not in out:
            out+=s[i]
    return out

def bar(s: str) -> str:
    d = make_dict(s)
    s = dedupl(s)
    l = str_perm(s)
    return check(l, d)[0] if check(l, d) else ""


if __name__ == '__main__':
    s1 = "abccde"
    s2 = "abc"
    s3 = ""
    s4 = "abcdec"
    slist = [s1, s2, s3, s4]
    for i in range(len(slist)):
        print(i, foo(slist[i]))
    for i in range(len(slist)):
        print(i, bar(slist[i]))