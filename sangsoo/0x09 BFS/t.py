import sys
from collections import deque
n = int(sys.stdin.readline())
board = [[0 for _ in range(n)] for _ in range(n)]
vis = [[0 for _ in range(n)] for _ in range(n)]
for i in range(n):
    board[i] = list(sys.stdin.readline())[:-1]
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

num = 0
def bfs(board, vis, blind):
    num = 0 
    vis = [[0 for _ in range(n)] for _ in range(n)]
    if (blind):
        for i in range(n):
            for j in range(n):
                if (board[i][j] == "R"):
                    board[i][j] = "G"
    for i in range(n):
        for j in range(n):
            q = deque()
            if (vis[i][j]): continue
            q.append((i, j)); vis[i][j] = 1
            cc = board[i][j] # current color
            num += 1
            while q:
                curx, cury = q.popleft()
                for dir in range(4):
                    nx = curx + dx[dir]
                    ny = cury + dy[dir]
                    if (nx < 0 or nx >= n or ny < 0 or ny >= n): continue
                    if (board[nx][ny] != cc or vis[nx][ny]): continue
                    vis[nx][ny] = 1
                    q.append((nx,ny))
    return num

print(bfs(board, vis, 0), bfs(board, vis, 1))