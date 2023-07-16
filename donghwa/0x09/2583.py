import sys
from collections import deque

M, N, K = map(int, sys.stdin.readline().split())
recs = [list(map(int, sys.stdin.readline().split())) for _ in range(K)]

board = [[0]*N for _ in range(M)]
vis = [[0]*N for _ in range(M)]
for rec in recs :
    x1, y1, x2, y2 = rec
    for i in range(M-y2, M-y1):
        for j in range(x1, x2):
            board[i][j] = 1

dx = [0, 1, 0, -1]
dy = [1, 0, -1, 0]
cnt = 0
Q = deque([])
areas = []

for i in range(M):
    for j in range(N):
        if board[i][j] == 0 and vis[i][j] == 0:
            vis[i][j] = 1
            cnt += 1
            Q.append((i,j))
            area = 1
            while (len(Q) > 0):
                cx, cy = Q.popleft()
                for d in range(len(dx)):
                    px = cx + dx[d]
                    py = cy + dy[d]
                    if px < 0 or px >= M or py < 0 or py >= N :
                        continue
                    if board[px][py] == 1 or vis[px][py] == 1:
                        continue
                    
                    vis[px][py] = 1
                    area += 1
                    Q.append((px,py))
            areas.append(area)

print(cnt)
for area in sorted(areas):
    print(area, end=' ')
print()