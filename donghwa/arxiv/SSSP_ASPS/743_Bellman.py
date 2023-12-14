import sys

def networkDelayTime(times, N, K):
    dist = [float('inf')] * (N + 1)
    dist[K] = 0

    for _ in range(N - 1):
        for u, v, w in times:
            if dist[u] != float('inf') and dist[v] > dist[u] + w:
                dist[v] = dist[u] + w

    maxWait = max(dist[1:])
    return -1 if maxWait == float('inf') else maxWait

# Test cases
times1 = [[2, 1, 1], [2, 3, 1], [3, 4, 1]]
N1 = 4
K1 = 2
print("Test case 1:", networkDelayTime(times1, N1, K1))  # Output: 2

times2 = [[1, 2, 1]]
N2 = 2
K2 = 1
print("Test case 2:", networkDelayTime(times2, N2, K2))  # Output: 1

times3 = [[1, 2, 1]]
N3 = 2
K3 = 2
print("Test case 3:", networkDelayTime(times3, N3, K3))  # Output: -1
