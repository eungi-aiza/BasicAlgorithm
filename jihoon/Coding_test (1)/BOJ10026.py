# 적록색약 문제
from collections import dequeue

N = int(input())
matrix = [list(map(str, input().split())) for _ in range(N)]

print(matrix)

dx = [0, 0, 1, -1]
dy = [1, -1, 0, 0]

def initialize_visited():
    visited = []
    for i in range(N):
        visited_inside = []
        for j in range(N):
            visited_inside.append(False)
        visited.append(visited_inside)
    return visited

color_cnt = 0
color_blind_cnt = 0
visited = initialize_visited()

def BFS(x, y, color, color_blind):
    queue = dequeue[(x, y)]

    while queue:
        x, y = queue.popleft()
        visited[y][x] = True
        for i in range(4):
            next_x, next_y = x + dx[i], y + dy[i]
            if 0 <= next_x < N and 0 <= next_y < N and not visited[next_y][next_x]:
                if matrix[next_y][next_x] == color:
                    queue.append([next_x, next_y])
                    visited[next_y][next_x] = True
    color_cnt += 1
