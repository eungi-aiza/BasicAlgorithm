from collections import deque

def eventualSafeNodes(graph):
    n = len(graph)
    out_degree = [0] * n
    in_neighbors = [[] for _ in range(n)]
    
    for i, neighbors in enumerate(graph):
        out_degree[i] = len(neighbors)
        for neighbor in neighbors:
            in_neighbors[neighbor].append(i)
    
    queue = deque()
    for i in range(n):
        if out_degree[i] == 0:
            queue.append(i)
    
    safe_nodes = []
    while queue:
        node = queue.popleft()
        safe_nodes.append(node)
        for neighbor in in_neighbors[node]:
            out_degree[neighbor] -= 1
            if out_degree[neighbor] == 0:
                queue.append(neighbor)
    
    return sorted(safe_nodes)

# Test cases

graph1 = [[1, 2], [2, 3], [5], [0], [5], [], []]
result1 = eventualSafeNodes(graph1)
print(result1)
# assert result1 == [2, 4, 5, 6], f"Expected [2, 4, 5, 6] but got {result1}"

graph2 = [[1, 2, 3, 4], [1, 2], [3, 4], [0, 4], []]
result2 = eventualSafeNodes(graph2)
print(result2)
# assert result2 == [4], f"Expected [4] but got {result2}"
