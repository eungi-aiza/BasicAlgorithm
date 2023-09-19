from operator import attrgetter

class GNode:
    def __init__(self, id, color="W", d=-1, f=-1, p=None):
        self.id = id # id is a string
        self.color = color # color (status) of node
        self.d = d # discover time of node
        self.f = f # finish time of node
        self.parent = p # predecessor time of node

    def __str__(self):
        return self.id

 
def dfs(G, u, v, visited, path):
    if u.id == v.id:
        visited.add(u.id)
        path.append(u.id)
        return
    else:
        if u.id not in visited:
            visited.add(u.id)
            path.append(u.id)
            G[u].sort(key=attrgetter('id'), reverse=True)
            for neighbor in G[u]:
                dfs(G, neighbor, v, visited, path)

def lexLargest(G, u, v):
    visited = set()
    path = []
    dfs(G, u, v, visited, path)
    if v.id not in visited:
        path = []

    i = 0
    for id in path:
        if v.id == id:
            break
        i += 1
    path = path[0:i+1]
    return path

if __name__ == "__main__":
    r, s, t, u = GNode('r'), GNode('s'), GNode('t'), GNode('u')
    v, w, x, y = GNode('v'), GNode('w'), GNode('x'), GNode('y')
    G = dict()
    G[r], G[w], G[t], G[u] = [w, v], [s, r, t], [s, x, w], [y]
    G[v], G[s], G[x], G[y] = [r], [w, t, x], [s, t], [u]
    print(lexLargest(G, t, v))
    print(lexLargest(G, u, u))
    print(lexLargest(G, w, y))
    print(lexLargest(G, y, u))
    print(lexLargest(G, x, u))
    print(lexLargest(G, s, x))