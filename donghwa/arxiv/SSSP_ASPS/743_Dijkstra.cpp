#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        // Create an adjacency list
        vector<vector<pair<int, int>>> adj(N);
        for (const vector<int>& t : times) {
            adj[t[0] - 1].emplace_back(t[1] - 1, t[2]);
        }

        // Initialize distances
        vector<int> dist(N, -1);
        dist[K - 1] = 0;

        // Priority queue for Dijkstra's algorithm
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, K - 1});

        while (!minHeap.empty()) {
            int curr_dist = minHeap.top().first;
            int curr = minHeap.top().second;
            minHeap.pop();

            if (dist[curr] != -1 && dist[curr] < curr_dist) {
                continue;
            }

            for (const pair<int, int>& edge : adj[curr]) {
                int next = edge.first;
                int weight = edge.second;
                int d = curr_dist + weight;
                if (dist[next] == -1 || dist[next] > d) {
                    dist[next] = d;
                    minHeap.push({d, next});
                }
            }
        }

        int max_wait = -1;
        for (int i = 0; i < N; i++) {
            if (dist[i] == -1) {
                return -1;
            }
            max_wait = max(max_wait, dist[i]);
        }

        return max_wait;
    }
};

int main() {
    // Test cases
    Solution solution;

    vector<vector<int>> times1 = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    int N1 = 4, K1 = 2;
    cout << "Test case 1: " << solution.networkDelayTime(times1, N1, K1) << endl;  // Output: 2

    vector<vector<int>> times2 = {{1, 2, 1}};
    int N2 = 2, K2 = 1;
    cout << "Test case 2: " << solution.networkDelayTime(times2, N2, K2) << endl;  // Output: 1

    vector<vector<int>> times3 = {{1, 2, 1}};
    int N3 = 2, K3 = 2;
    cout << "Test case 3: " << solution.networkDelayTime(times3, N3, K3) << endl;  // Output: -1

    return 0;
}
