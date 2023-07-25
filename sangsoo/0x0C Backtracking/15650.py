# N과 M(2) Combination
N, M = map(int, input().split())
arr = [0 for _ in range(M)]
isused = [0 for _ in range(N)]

def func(k: int, st: int)->None:
    if (k == M):
        for i in range(M):
            print(arr[i], end = ' ')
        print("")
        return
    for i in range(st, N):
        if (not isused[i]):
            isused[i] = 1
            arr[k] = i+1
            func(k+1, i+1) # 다음번 숫자부터 돌도록. i+1을 넣어줌
            isused[i] = 0
func(0, 0)