import sys
global visited
global order

def dfs(graph, start):
    stack = [start]
    dfs_path = []
    i = 1
    while stack:
        curr_node = stack.pop()
        visited[curr_node] = True
        dfs_path.append(curr_node)
        # Save the order in order list
        order[curr_node] = i
        graph[curr_node].sort(reverse=True) # Ascending order
        for neighbor in graph[curr_node]:
            if not visited[neighbor] and (neighbor not in stack):
                stack.append(neighbor)
        i += 1
    return dfs_path


if __name__ == '__main__':
    N, M, R = map(int, sys.stdin.readline().split())
    visited = [False]*(N+1)  
    order = [0]*(N+1)
    graph = {}
    for _ in range(M):
        u, v = map(int, sys.stdin.readline().split())

        # Create a graph
        if u not in graph:
            graph[u] = []
        if v not in graph:
            graph[v] = []
        graph[u].append(v)
        graph[v].append(u)

    # Run dfs
    dfs_path = dfs(graph, R)
    print(dfs_path)
    for i in range(1, N+1):
        print(order[i])
            
