import sys

n, s = list(map(int, sys.stdin.readline().split()))
arr = list(map(int, sys.stdin.readline().split()))
cnt = 0

def func(cur, tot):
    global n, arr, cnt, s
    if (cur == n):
        if (tot == s) :
            cnt += 1
        return

    func(cur+1, tot)
    func(cur+1, tot+arr[cur])

func(0,0)
if (s==0) :
    cnt -= 1
print(cnt)