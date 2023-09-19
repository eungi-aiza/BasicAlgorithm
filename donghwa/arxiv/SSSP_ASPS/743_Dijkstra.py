import heapq
from typing import List

class Solution:
    def networkDelayTime(self, times: List[List[int]], N: int, K: int) -> int:
        # Create an adjacency list
        adj = [[] for _ in range(N)]
        for u, v, w in times:
            adj[u - 1].append((v - 1, w))

        # Initialize distances
        dist = [-1] * N
        dist[K - 1] = 0

        # Priority queue for Dijkstra's algorithm
        min_heap = [(0, K - 1)]

        while min_heap:
            curr_dist, curr = heapq.heappop(min_heap)

            if dist[curr] != -1 and dist[curr] < curr_dist:
                continue

            for next_node, weight in adj[curr]:
                d = curr_dist + weight
                if dist[next_node] == -1 or dist[next_node] > d:
                    dist[next_node] = d
                    heapq.heappush(min_heap, (d, next_node))

        max_wait = max(dist)
        return -1 if -1 in dist else max_wait

# Test cases
solution = Solution()

times1 = [[2, 1, 1], [2, 3, 1], [3, 4, 1]]
N1, K1 = 4, 2
print("Test case 1:", solution.networkDelayTime(times1, N1, K1))  # Output: 2

times2 = [[1, 2, 1]]
N2, K2 = 2, 1
print("Test case 2:", solution.networkDelayTime(times2, N2, K2))  # Output: 1

times3 = [[1, 2, 1]]
N3, K3 = 2, 2
print("Test case 3:", solution.networkDelayTime(times3, N3, K3))  # Output: -1
