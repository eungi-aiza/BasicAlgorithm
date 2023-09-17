class GNode:
    def __init__(self, id):
        self.id = id
    def __str__(self):
        return self.id

def paths(G, a, c):
    def dfs(node, path):
        if node == c:
            ret.append(path)
            return
        
        for nn in G[node]:
            if v[nn]:
                continue
            v[nn] = True
            dfs(nn, path + [str(nn)])
            v[nn] = False

    ret = []
    v = {k: False for k in G.keys()}
    v[a] = True
    dfs(a, [str(a)])
    return ret