import sys
from collections import deque

M, N, K = list(map(int, sys.stdin.readline().split()))
K_idx  = [list(map(int, sys.stdin.readline().split())) for _ in range(K)]
board = [[1 for n in range(N)] for m in range(M)]
vis = [[0 for n in range(N)] for m in range(M)]
DX = [1,0,-1,0]
DY = [0,1,0,-1]
# print(K_idx)

## rectangles ## 
for k in range(K):
    y1, x1, y2, x2 = K_idx[k]
    for i in range(x1, x2):
        for j in range(y1, y2):
            board[i][j] = 0
# print(board)

## bfs
def bfs(x, y):
    size = 0
    D = deque([])
    D.append((x,y))
    while (len(D) != 0):
        size += 1
        curr = D.popleft()
        for dx, dy in zip(DX, DY):
            nx = curr[0] + dx
            ny = curr[1] + dy
            if (nx < 0 or ny < 0 or nx >= M or ny >= N): continue
            if (vis[nx][ny] == 1 or board[nx][ny] != 1): continue
            vis[nx][ny] = 1
            D.append((nx, ny))
    # print(size)
    return size


## get number of rec and their sizes
rec = 0
sizes = []
for i in range(M):
    for j in range(N):
        if (board[i][j] == 1 and vis[i][j] == 0):
            vis[i][j] = 1
            rec += 1
            size = bfs(i, j)
            sizes.append(size)
            
            
sizes.sort()
print(rec)
for i in range(len(sizes)):
    print(sizes[i], end = " ")

            
            
            