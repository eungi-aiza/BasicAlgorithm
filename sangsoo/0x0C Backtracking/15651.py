N, M = map(int, input().split())
arr = [0 for _ in range(M)]
isused = [0 for _ in range(N)]

def func(k:int)->None:
    if(k == M):
        for i in range(M):
            print(arr[i], end = ' ')
        print("")
        return
    for i in range(N):
        arr[k] = i+1
        func(k+1)

func(0)