from collections import deque
import sys
import copy

D = deque([])
N, M = map(int, sys.stdin.readline().split())
ans  = 0


def first2last(D, x):
    ans = 0
    while (D[0] != x):
        temp = D.popleft()
        D.append(temp)
        ans += 1
    return ans

def last2first(D, x):
    ans = 0
    while (D[0] != x):
        temp = D.pop()
        D.appendleft(temp)
        ans += 1
    return ans

for i in range(N):
    D.append(i+1)

targets = list(map(int, sys.stdin.readline().split()))

for i in range(M):
    tar = targets[i] 
    if D[0] == tar: D.popleft()
    else:
        D_temp_f = copy.deepcopy(D)
        D_temp_b = copy.deepcopy(D)
        step_f = first2last(D_temp_f, tar)
        step_b = last2first(D_temp_b, tar)
        if (step_f >= step_b):
            ans += last2first(D, tar)
            D.popleft()
        else:
            ans += first2last(D, tar)
            D.popleft()
            
print(ans)
    