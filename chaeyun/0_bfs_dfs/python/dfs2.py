
"""
이렇게 풀면 메모리 초과됨~
"""
def dfs(t):
    global cnt
    visited[t][t] = True
    for i in range(1, N+1):
        if visited[t][i] == 1 and visited[i][i] == 0:  # if there's an edge from t to i and i is not visited
            cnt += 1
            dfs(i)

import sys
input = sys.stdin.readline
sys.setrecursionlimit(150000)

N, M, R = map(int, input().split())
visited = [[0] * (N+1) for _ in range(N+1)]
cnt = 1
for _ in range(M):
    a, b = map(int, input().split())
    visited[a][b] = 1  # edge from a to b
    visited[b][a] = 1  # edge from b to a

dfs(R)
for i in range(1, N+1):
    print(visited[i][i])
