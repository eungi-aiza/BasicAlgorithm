"""
The visited list enqueues #th visiting order
"""

from collections import deque

def bfs(start):
    global cnt
    queue = deque([start])
    visited[start] = cnt
    
    while queue:
        v = queue.popleft()
        for nei in graph[v]:
            if visited[nei] == 0:  # Check if the node is unvisited
                queue.append(nei)
                cnt += 1
                visited[nei] = cnt

N, M, R = map(int, input().split())
graph = [[] for _ in range(N+1)]
visited = [0] * (N+1)  # Initialize with zeroes
cnt = 1
for _ in range(M):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)

for i in range(N+1): 
    graph[i].sort()

bfs(R)
print(*visited[1:], sep='\n')