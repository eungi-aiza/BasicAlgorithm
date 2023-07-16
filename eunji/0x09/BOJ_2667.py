import sys
from collections import deque

DX = [1, 0, -1, 0]
DY = [0, 1, 0, -1]
N = int(sys.stdin.readline())
board = [[int(t) for t in sys.stdin.readline().rstrip()] for i in range(N)]
visit = [[0 for j in range(N)] for i in range(N)]
# print(board)

# bfs
def bfs(x, y):
    s = 0
    D = deque([])
    D.append((x, y))
    while (len(D) != 0):
        curr = D.popleft()
        s += 1
        for nx, ny in zip(DX, DY):
            cx = curr[0] + nx
            cy = curr[1] + ny
            if (cx < 0 or cy < 0 or cx >= N or cy >= N): continue
            if (visit[cx][cy] == 1 or board[cx][cy] != 1): continue
            visit[cx][cy] = 1
            D.append((cx,cy))
            # s += 1
    return s
    

# count town and bfs the towns
town = 0
size = []
for i in range(N):
    for j in range(N):
        if board[i][j] == 1 and visit[i][j] != 1:
            visit[i][j] = 1
            town += 1
            s = bfs(i, j)
            size.append(s)
            
           
print(town) 
size.sort()
for i in size:
    print(i)
