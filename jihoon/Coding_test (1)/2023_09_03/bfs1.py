import sys
global visited
global order

def bfs(graph, start):
    # 사실 list가 아니라 collections.deque를 쓰는게 더 빠르다.
    queue = [start]
    dfs_path = []
    i = 1
    while queue:
        curr_node = queue.pop(0)
        visited[curr_node] = True
        dfs_path.append(curr_node)
        # Save the order in order list
        order[curr_node] = i
        graph[curr_node].sort() # Ascending order
        for neighbor in graph[curr_node]:
            if not visited[neighbor] and (neighbor not in queue):
                queue.append(neighbor)
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
    bfs_path = bfs(graph, 1)
    print(bfs_path)
    for i in range(1, N+1):
        print(order[i])
            