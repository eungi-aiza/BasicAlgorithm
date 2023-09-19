class UnionFind:
    def __init__(self, n):
        self.parent = list(range(n))
    
    def find(self, x):
        if self.parent[x] != x:
            self.parent[x] = self.find(self.parent[x])
        return self.parent[x]
    
    def union(self, x, y):
        root_x = self.find(x)
        root_y = self.find(y)
        if root_x != root_y:
            self.parent[root_x] = root_y

def minCostConnectPoints(points):
    n = len(points)
    edges = []  # Store edges in the format (cost, point1, point2)
    
    for i in range(n):
        for j in range(i + 1, n):
            manhattan_dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])
            edges.append((manhattan_dist, i, j))
    
    # Sort edges by their cost
    edges.sort()
    
    uf = UnionFind(n)
    min_cost = 0
    edges_added = 0
    
    for edge in edges:
        cost, u, v = edge
        if uf.find(u) != uf.find(v):
            uf.union(u, v)
            min_cost += cost
            edges_added += 1
            if edges_added == n - 1:
                break  # Minimum spanning tree is complete
    
    return min_cost

# Test the function with the given example
points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
print(minCostConnectPoints(points))  # Output should be 20
