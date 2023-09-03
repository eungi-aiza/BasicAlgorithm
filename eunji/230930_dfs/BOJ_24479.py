import sys
sys.setrecursionlimit(10 ** 6)

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

# print(graph)
curr = 1
def dfs(start):
    global curr
    vis[start] = curr
    curr += 1
    for nei in graph[start]:
        if vis[nei] == 0:
            dfs(nei)
    
dfs(R)
# print(*vis[1:], sep='\n')
for i in range(1, N+1):
    print(vis[i])
