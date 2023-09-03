from collections import deque
import sys

N, M, R = list(map(int, sys.stdin.readline().split()))
graph = {n+1: [] for n in range(N)}
vis = [0 for n in range(N+1)]

for i in range(M):
    edge = list(map(int, sys.stdin.readline().split()))
    v, u = edge[0], edge[1]
    graph[v].append(u)
    graph[u].append(v)

for k, v in graph.items():
    v.sort()  
    
def bfs():
    global curr
    curr = 1
    vis[R] = curr
    que = deque([])
    que.append(R)
    while (len(que) != 0):
        popped = que.popleft()
        for nei in graph[popped]:
            if (vis[nei] == 0):
                curr += 1
                vis[nei] = curr
                que.append(nei)
    
bfs()
print(*vis[1:], sep="\n")


