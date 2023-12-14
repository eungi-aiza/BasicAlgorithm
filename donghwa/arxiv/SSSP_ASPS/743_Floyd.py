class Solution:
    def networkDelayTime(self, times, N, K):
        MAX = float('inf')
        dist = [[MAX] * N for _ in range(N)]

        for i in range(N):
            dist[i][i] = 0

        for e in times:
            dist[e[0] - 1][e[1] - 1] = e[2]

        for k in range(N):
            for i in range(N):
                for j in range(N):
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

        maxwait = 0
        for i in range(N):
            maxwait = max(maxwait, dist[K - 1][i])

        return -1 if maxwait == MAX else maxwait

# Test cases
solution = Solution()

# Test case 1
times1 = [[2, 1, 1], [2, 3, 1], [3, 4, 1]]
N1 = 4
K1 = 2
print("Test case 1:", solution.networkDelayTime(times1, N1, K1))  # Output: 2

# Test case 2
times2 = [[1, 2, 1]]
N2 = 2
K2 = 1
print("Test case 2:", solution.networkDelayTime(times2, N2, K2))  # Output: 1

# Test case 3
times3 = [[1, 2, 1]]
N3 = 2
K3 = 2
print("Test case 3:", solution.networkDelayTime(times3, N3, K3))  # Output: -1
