from collections import deque

# Node definition.
class GNode:
    def __init__(self, id, color="W", d=0, p=None):
        self.id = id # id is a string
        self.color = color # color (status) of node 
        self.distance = d
        self.parent = p
        
    def __str__(self):
        return self.id

def bfs(G, s):
    ret = []
    q = deque([s])
    v = [s]
    while q:
        cn = q.popleft()
        if len(ret) <= cn.distance:
            ret.append([cn.id])
        else:
            ret[cn.distance].append(cn.id)
        for nn in G[cn]:
            if nn in v:
                continue
            q.append(nn)
            v.append(nn)
            nn.distance = cn.distance + 1
    return ret

def level_partition(G, s):
    return bfs(G, s)