import sys

n = int(sys.stdin.readline().rstrip())

isused1 = [0]*40
isused2 = [0]*40
isused3 = [0]*40

cnt = 0

def func(cur):
    global n, cnt
    if (cur == n):
        cnt += 1
        return
    for i in range(n):
        if isused1[i] or isused2[cur+i] or isused3[cur-i+n-1] :
            continue
        isused1[i] = 1
        isused2[cur+i] = 1
        isused3[cur-i+n-1] = 1
        func(cur+1)
        isused1[i] = 0
        isused2[cur+i] = 0
        isused3[cur-i+n-1] = 0

func(0)
print(cnt)
        