class GNode:
    def __init__(self, id, color="W", d=-1, f=-1, p=None):
        self.id = id # id is a string
        self.color = color # color (status) of node
        self.d = d # discover time of node
        self.f = f # finish time of node
        self.parent = p # predecessor time of node
        
    def __str__(self):
        return self.id

from collections import deque 
  

def LexSmallest(G, start, end):
    Q = deque([])
    Q.append(start)
    if start == end :
        return [start.id]
    
    vis = dict()
    for k,v in G.items() :
        vis[k] = False
    vis[start] = True
    
    path = []
    path.append(start.id)
    for node in sorted(G[start], key=lambda x : x.id, reverse=True): 
        Q.append(node)
        while len(Q)>0:
            u = Q.popleft()
            if vis[u] != True :
                path.append(u.id)
                vis[u] = True
                if u == end:
                    return path
                for item in sorted(G[u], key=lambda x : x.id, reverse=True):
                    if not vis[item]:
                        Q.append(item)
    return []    
    
if __name__ == "__main__":
    r, s, t, u = GNode('r'), GNode('s'), GNode('t'), GNode('u')
    v, w, x, y = GNode('v'), GNode('w'), GNode('x'), GNode('y')
    G = dict()
    G[r], G[w], G[t], G[u] = [w, v], [s, r, t], [s, x, w], [y]
    G[v], G[s], G[x], G[y] = [r], [w, t, x], [s, t], [u]
    
    # print(LexSmallest(G, t, v))
    # print(LexSmallest(G, t, t))
    # print(LexSmallest(G, w, y))
    # print(LexSmallest(G, v, x))
    print(LexSmallest(G, s, x))
    
     