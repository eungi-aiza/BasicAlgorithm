import sys
from collections import deque

n,m = map(int, sys.stdin.readline().split())
board = [list(map(int, sys.stdin.readline().split())) for _ in range(n)]
vis = [[0]*m for _ in range(n)]

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]
cnt = 0
Q = deque([])
sizes = []
for i in range(n):
    for j in range(m):
        if (board[i][j] == 1 and vis[i][j] == 0):
            cnt += 1
            vis[i][j] = 1
            Q.append((i,j))
            size = 1
            while (len(Q)) :
                cx, cy = Q.pop()
                for dir in range(len(dx)):
                    nx = cx + dx[dir]
                    ny = cy + dy[dir]
                    if (nx < 0 or nx >= n or ny < 0 or ny >= m) : 
                        continue
                    if (vis[nx][ny] == 1 or board[nx][ny] == 0):
                        continue
                    vis[nx][ny] = 1
                    size += 1
                    Q.append((nx,ny))
            sizes.append(size)    
            
print(cnt)
if (len(sizes) == 0) :
    print(0)
else :
    print(max(sizes))