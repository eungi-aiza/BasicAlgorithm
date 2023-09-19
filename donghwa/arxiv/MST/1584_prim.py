
import heapq

def minCostConnectPoints(points):
    n = len(points)
    if n <= 1:
        return 0

    def manhattan_dist(p1, p2):
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1])

    visited = [False] * n
    min_heap = [(0, 0)]  # (cost, vertex)
    min_cost = 0

    while min_heap:
        cost, vertex = heapq.heappop(min_heap)
        if visited[vertex]:
            continue

        visited[vertex] = True
        min_cost += cost

        for i in range(n):
            if not visited[i]:
                heapq.heappush(min_heap, (manhattan_dist(points[vertex], points[i]), i))

    return min_cost

# Test the function with the given example
points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
print(minCostConnectPoints(points))  # Output should be 20
