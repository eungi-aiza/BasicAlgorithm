N, M = map(int, input().split())
arr = [0 for _ in range(M)]
isused = [0 for _ in range(N)]
def func(k:int)->None:
    if (k == M):
        for i in range(M):
            print(arr[i], end = ' ')
        print("")
        return # return 안 넣어주면 에러
    for i in range(N):
        if(not isused[i]):
            isused[i] = 1
            arr[k] = i+1
            func(k+1)
            isused[i] = 0
func(0)