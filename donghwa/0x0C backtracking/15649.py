import sys

n,m = map(int, sys.stdin.readline().split())
arr = [0]*10
isused = [0]*10

def func(k):
    global n,m, arr, isused
    if (k==m):
        for item in arr :
            if item == 0  :
                break
            print(item, end=' ')
        print()
        return
    for i in range(1,n+1):
        if not isused[i-1]:
            isused[i-1] = 1
            arr[k] = i
            func(k+1)
            isused[i-1] = 0

func(0)
        