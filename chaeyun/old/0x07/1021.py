from collections import deque

n, m = map(int, input().split(' '))
arr = list(map(int, input().split(' ')))

DQ = deque(range(1, n+1))

cnt = 0

for i in arr:
    if i == DQ[0]:
        DQ.popleft()
        continue
    q_idx = DQ.index(i)
    if q_idx <= len(DQ)//2:
        DQ.rotate(-q_idx)
        cnt += q_idx
    else:
        DQ.rotate(len(DQ)-q_idx)
        cnt += len(DQ)-q_idx
    DQ.popleft()
print(cnt)
