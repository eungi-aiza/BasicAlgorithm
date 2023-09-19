import sys
input = sys.stdin.readline
from collections import defaultdict,deque
n, m, r = map(int, input().split())
adj = defaultdict(list)
vis = [0 for _ in range(100001)]
cnt = 1
for i in range(m):
    a, b = map(int, input().split())
    adj[a].append(b)
    adj[b].append(a)

def bfs(v:int)->None:
    global cnt
    vis[v] = cnt; cnt += 1
    q = deque()
    q.append(v)
    while q:
        cur = q.popleft()
        for nxt in adj[cur]:
            if(vis[nxt] == 0):
                vis[nxt] = cnt; cnt+=1
                q.append(nxt)

for i in range(1, n+1):
    adj[i].sort()
bfs(r)
for i in range(1, n+1):
    print(vis[i])