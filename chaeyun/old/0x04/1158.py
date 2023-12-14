m, n = map(int, input().split())
ls = [i+1 for i in range(m)]
ans = []
while len(ls) > 0:
    idx = (n-1) % len(ls)
    itm = ls.pop(idx)
    ans.append(itm)
    ls = ls[idx:] + ls[:idx]

print("<" + ", ".join(str(x) for x in ans) + ">")
