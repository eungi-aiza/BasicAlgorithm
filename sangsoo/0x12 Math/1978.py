import math
n = int(input())
def isprime(x: int)->int:
    if (x == 1): return False
    for i in range(2, int(math.sqrt(x))+1): # python 에서는 마지막 숫자가 포함되지 않으므로 +1 해야한다.
        if (x % i == 0):
            return False
    return True

cnt = 0
arr = list(map(int, input().split()))

for i in range(n):
    if(isprime(arr[i])): cnt+= 1

print(cnt)