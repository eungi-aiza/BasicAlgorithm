import sys
from collections import deque

n,m = map(int, sys.stdin.readline().rstrip().split())

edges = [list(map(int, sys.stdin.readline().split())) for _ in range(m)]

# undirected list
tmp = [[] for _ in range(1005)]

for edge in edges :
    u,v = edge
    tmp[u].append(v)
    tmp[v].append(u)

adj = [[]]
for i in range(1,n+1):
    adj.append(tmp[i])
    
q = deque([])
cnt = 0
vis =[0] * 1005
for i in range(1, n+1):
    if (vis[i]) :
        continue
    cnt += 1
    q.append(i)
    vis[i] = 1
    while(len(q)>0):
        cur = q.popleft()
        for j in adj[cur]:
            if (vis[j]) :
                continue
            q.append(j)
            vis[j] = 1
            

print(cnt)
        
        
        
    