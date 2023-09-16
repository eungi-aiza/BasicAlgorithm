from collections import deque

def topologicalSort(graph):
    nodes = len(graph)
    inDegree = [0] * nodes
    result = []

    # Calculate in-degrees
    for i in range(nodes):
        for j in range(nodes):
            if graph[i][j] == 1:
                inDegree[j] += 1

    # Initialize a queue with nodes having in-degree 0
    queue = deque()
    for i in range(nodes):
        if inDegree[i] == 0:
            queue.append(i)

    # Perform topological sorting
    while queue:
        current = queue.popleft()
        result.append(current)

        for i in range(nodes):
            if graph[current][i] == 1:
                inDegree[i] -= 1
                if inDegree[i] == 0:
                    queue.append(i)

    # Check for a cycle (if result size is less than the number of nodes)
    if len(result) < nodes:
        print("Cycle exists")
    else:
        print("Topological Sorting Order:", result)

if __name__ == "__main__":
    nodes = 6
    graph = [
        [0, 1, 1, 0, 0, 0],
        [0, 0, 0, 1, 0, 0],
        [0, 0, 0, 1, 0, 0],
        [0, 0, 0, 0, 1, 1],
        [0, 0, 0, 0, 0, 1],
        [0, 0, 0, 0, 0, 0]
    ]

    print("Topological Sorting Order: ", end="")
    topologicalSort(graph)
