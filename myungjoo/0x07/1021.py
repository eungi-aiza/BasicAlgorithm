from collections import deque
import sys
input = sys.stdin.readline

N, M = map(int, input().split())
idx = list(map(int, input().split()))

Q = deque([n for n in range(1,N+1)])

cnt = 0

for i in idx:
    while True:
        if Q[0] == i:
            Q.popleft()
            break
        else:
            if Q.index(i) < len(Q)/2:
                while Q[0] != i:
                    Q.append(Q.popleft())
                    cnt +=1
            else:
                while Q[0] != i:
                    Q.appendleft(Q.pop())
                    cnt +=1
            
print(cnt)