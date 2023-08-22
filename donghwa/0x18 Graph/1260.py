import sys
from collections import deque

n,m, st = map(int, sys.stdin.readline().rstrip().split())
edges = [list(map(int,  sys.stdin.readline().split())) for _ in range(m)]
tmp = [[] for _ in range(1005)]

# undirected list
for edge in edges :
    u,v = edge
    tmp[u].append(v)
    tmp[v].append(u)

adj = [[]]
for i in range(1,n+1):
    adj.append(sorted(tmp[i]))
    
def bfs(cur):
    global adj
    vis = [0]*1005
    q = deque([])
    q.append(cur)
    while(len(q)>0):
        cur = q.popleft()
        if (vis[cur]) :
            continue
        print(cur, end=' ')
        vis[cur] = 1
        for nxt in adj[cur]:
            if vis[nxt] :
                continue
            q.append(nxt)
            
    print()
    
def dfs(cur, vis):
    global adj
    vis[cur] = 1
    print(cur, end=' ')
    for nxt in adj[cur]:
        if vis[nxt] :
            continue
        vis[nxt] = 1
        dfs(nxt, vis)

def dfs2(cur):
    s = []
    vis = [0] * 1005
    s.append(cur)
    while(len(s)>0):
        cur = s.pop()
        if vis[cur]:
            continue
        vis[cur] = 1
        print(cur, end=' ')
        for nxt in sorted(adj[cur], reverse=True):
            if vis[nxt] :
                continue
            s.append(nxt)
    print()
            
    
# vis_dfs = [0]*1005
# dfs(st, vis_dfs)       
dfs2(st)  
bfs(st)
# print()