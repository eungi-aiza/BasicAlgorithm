import copy

class GNode:
    def __init__(self, id, color="W", d=-1, f=-1, p=None):
        self.id = id # id is a string 
        self.color = color # color (status) of node
        self.d = d
        self.f = f
        self.parent = p
        
    def __str__(self):
        return self.id


def backtracking(Graph, start, target, ans, fin):
    if (start == target):
        # temp = copy.deepcopy(ans)
        temp = [i for i in ans]
        fin.append(temp)
        return 
    
    for child in G[start]:
        if child.color == "W":
            child.color = "R"
            ans.append(child.id)
            backtracking(Graph, child, target, ans, fin)
            child.color = "W"
            ans.pop()
    
    
def SortGraph(Graph):
    for k, v in Graph.items():
        v.sort(key=lambda x: x.id, reverse=True)


def LexLargest(Graph, start, target):
    SortGraph(Graph)
    ans = []
    fin = []
    start.color = "R"
    ans.append(start.id)    
    backtracking(Graph, start, target, ans, fin)
    if fin: return fin[0]
    else: return []

    
if __name__ == '__main__':
    r, s, t, u = GNode('r'), GNode('s'), GNode('t'), GNode('u')
    v, w, x, y = GNode('v'), GNode('w'), GNode('x'), GNode('y')
    G = dict()
    G[r], G[w], G[t], G[u] = [w, v], [s, r, t], [s, x, w], [y]
    G[v], G[s], G[x], G[y] = [r], [w, t, x], [s, t], [u]
    print(LexLargest(G, t, v))
    print(LexLargest(G, u, u))
    print(LexLargest(G, w, y))
    print(LexLargest(G, s, x))