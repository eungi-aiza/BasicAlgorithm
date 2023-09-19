import sys
input = sys.stdin.readline

def binarysearch(x:int, n : int)->int:
    st= 0; en = n-1
    while(st<=en):
        mid = st + (en-st)//2
        if(arr[mid] == x): return 1
        elif (arr[mid] > x): en = mid-1
        else: st = mid + 1
    return 0


n = int(input())
arr = list(map(int, input().split()))
arr.sort()
m = int(input())
test = list(map(int, input().split()))
for i in range(m):
    print(binarysearch(test[i], n))