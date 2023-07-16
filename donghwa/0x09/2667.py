import sys
from collections import deque

N = int(sys.stdin.readline())
map = [[int(item) for item in sys.stdin.readline().rstrip()] for _ in range(N)]
vis = [[0]*N for _ in range(N)]

dx = [0,1,0,-1]
dy = [1,0,-1,0]

cnt = 0
Q = deque([])
areas = []
for i in range(N):
    for j in range(N):
        if map[i][j] == 1 and vis[i][j] == 0:
            cnt += 1
            vis[i][j] = 1
            Q.append((i,j))
            area = 1
            while (len(Q) >0):
                cx, cy = Q.popleft()
                for dir in range(4):
                    px = cx + dx[dir]
                    py = cy + dy[dir]
                    if px < 0 or px >= N or py < 0 or py >= N: 
                        continue
                    if map[px][py] == 0 or vis[px][py] == 1:
                        continue
                    vis[px][py] = 1
                    area += 1
                    Q.append((px, py))
            areas.append(area)

print(cnt)
for area in sorted(areas) :
    print(area)
