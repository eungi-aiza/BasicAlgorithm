"""
The Visited list encodes #th visited order
"""
def dfs(t):
    global cnt
    visited[t] = cnt
    graph[t].sort()
    for i in graph[t]:
        if visited[i] == 0:
            cnt += 1
            dfs(i)

import sys
input = sys.stdin.readline
sys.setrecursionlimit(150000)

N, M, R = map(int, input().split())
graph = [[] for _ in range(N+1)]

visited = [0] *(N+1)
cnt = 1

for _ in range(M):
    a, b = map(int, input().split())
    graph[a].append(b)  # �� ���� ����
    graph[b].append(a)  # �� ���� ����

dfs(R)
for i in range(1, N+1):
    print(visited[i])
