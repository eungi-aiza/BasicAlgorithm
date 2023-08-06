import sys

s = sys.stdin.readline().rstrip()
n = len(s)
isused = [0]*n
s_new = [0]*n
isadj = {s[0]:[s[1]], s[-1]:[s[-2]]}
isadj.update({s[i]:[s[i-1], s[i+1]] for i in range(1, n-1)})
res = []

def foo(cnt):
    global n, s, s_new, isused, isadj, res
    if cnt == n:
        res.append("".join(s_new))
        return
    for i in range(n):
        if isused[i]:
            continue
        if cnt > 0 :
            if s[i] in isadj[s_new[cnt-1]]:
                continue
        isused[i] = 1
        s_new[cnt] = s[i]
        foo(cnt+1)
        isused[i] = 0

foo(0)
print(res)






