from collections import deque
M, N, K = map(int, input().split())  
board = [[1 for _ in range(N)] for _ in range(M)] # x: M, y: N
for _ in range(K):
    y1, x1, y2, x2 = map(int, input().split())
    for i in range(x1, x2):
        for j in range(y1, y2):
            board[i][j] = 0
# BFS
# 그림의 개수와 그림의 넓이 찾기
vis = [[0 for _ in range(N)] for _ in range(M)]
dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]
num = 0
arealist = []
for i in range(M):
    for j in range(N):
        if (board[i][j] == 0 or vis[i][j]): continue
        q = deque()
        num += 1
        area = 0
        q.append((i, j))
        vis[i][j] = 1
        while q:
            curx, cury = q.popleft()
            area += 1
            for dir in range(4): 
                nx = curx + dx[dir]
                ny = cury + dy[dir]
                if (nx < 0 or nx >= M or ny < 0 or ny >= N): continue
                if (board[nx][ny] == 0 or vis[nx][ny]): continue
                vis[nx][ny] = 1
                q.append((nx, ny))
        arealist.append(area)
print(num)
arealist.sort()
for i in range(len(arealist)):
    print(arealist[i], end = " ")
# print(arealist)