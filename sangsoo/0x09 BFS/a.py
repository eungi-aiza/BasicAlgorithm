import sys
from collections import deque

dx = [0,0,-1,1]
dy = [1, -1, 0,0]

N = int(sys.stdin.readline().rstrip())
pic = [list(item for item in sys.stdin.readline().rstrip()) for _ in range(N)]


def BFS(x, y, vis, rg=False):
    global pic, dx, dy
    if rg :
        for i in range(N):
            for j in range(N):
                if pic[i][j] == 'G':
                    pic[i][j] = 'R'

    c = pic[x][y]
    Q = deque([(x,y)])
    while(len(Q)>0):
        cx, cy = Q.popleft()
        for d in range(4):
            px = cx + dx[d]
            py = cy + dy[d]
            if px < 0 or px >= N or py < 0 or py >= N :
                continue
            if pic[py][py] != c or vis[px][py] == 1:
                continue

            vis[px][py] = 1
            Q.append((px, py))
    

cnt = 0
vis = [[0]*N for _ in range(N)]
for i in range(N):
    for j in range(N):
        if vis[i][j] == 0:
            BFS(i, j, vis) 
            cnt += 1     
print(cnt)

cnt = 0
vis = [[0]*N for _ in range(N)]
for i in range(N):
    for j in range(N):
        if vis[i][j] == 0:
            BFS(i, j, vis, True)
            cnt += 1
print(cnt)
