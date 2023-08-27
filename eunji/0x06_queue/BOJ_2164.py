from collections import deque

N = int(input())
Q = deque([])
for i in range(N):
    Q.append(i+1)

flag = 1
while (len(Q) != 1):
    if flag == 1: Q.popleft()
    elif flag == -1:
        temp = Q.popleft()
        Q.append(temp)
    flag *= -1

print(Q[0])