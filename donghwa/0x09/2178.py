import sys 
from collections import deque

px = [1, 0, -1, 0]
py = [0, 1, 0, -1]

n, m = map(int, sys.stdin.readline().split())
board = [[int(c) for c in sys.stdin.readline().strip()] for _ in range(n)]
dist = [[-1]*m for _ in range(n)]
# print(board)
Q = deque([])
dist[0][0] += 1
Q.append((0,0))
while (len(Q)>0) :
    cx, cy = Q.popleft()
    for dir in range(4) :
        dx = cx + px[dir]
        dy = cy + py[dir]
        if (dx < 0 or dx >= n or dy < 0 or dy >= m) :
            continue
        if (dist[dx][dy] >= 0 or board[dx][dy] != 1) :
            continue
        dist[dx][dy] = dist[cx][cy]+1
        Q.append((dx,dy))

# print()        
# for line in dist:
#     print(line)
print(dist[n-1][m-1]+1)       

