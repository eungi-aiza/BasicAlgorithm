N = int(input())
arr = list(map(int, input().split()))
X = int(input())

arr.sort()

ans = 0
st = 0; ed = N-1

while (st < ed):
    if (arr[st]+arr[ed] == X): ans += 1; st+= 1; ed -=1
    elif (arr[st]+arr[ed] < X): st+= 1
    elif (arr[st]+arr[ed] > X): ed-= 1
    
print(ans)