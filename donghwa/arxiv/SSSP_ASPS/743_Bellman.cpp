/* 743. Network Delay Time

You are given a network of n nodes, labeled from 1 to n. 
You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), 
where ui is the source node, 
vi is the target node,
 and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. 
Return the minimum time it takes for all the n nodes to receive the signal.
If it is impossible for all the n nodes to receive the signal, return -1.

ex1.
Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2

ex2. 
Input: times = [[1,2,1]], n = 2, k = 1
Output: 1

ex3. 
Input: times = [[1,2,1]], n = 2, k = 2
Output: -1
*/

#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Define a structure to represent edges
struct Edge {
    int src, dest, weight;
    Edge(int _src, int _dest, int _weight) : src(_src), dest(_dest), weight(_weight) {}
};

int networkDelayTime(vector<vector<int>>& times, int N, int K) {
    vector<int> dist(N + 1, INT_MAX);
    dist[K] = 0;

    for (int i = 1; i < N; i++) {
        for (const vector<int>& e : times) {
            int u = e[0], v = e[1], w = e[2];
            if (dist[u] != INT_MAX && dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
            }
        }
    }

    int maxWait = 0;
    for (int i = 1; i <= N; i++) {
        maxWait = max(maxWait, dist[i]);
    }

    return maxWait == INT_MAX ? -1 : maxWait;
}

int main() {
    // Test cases
    vector<vector<int>> times1 = {{2, 1, 1}, {2, 3, 1}, {3, 4, 1}};
    int N1 = 4, K1 = 2;
    cout << "Test case 1: " << networkDelayTime(times1, N1, K1) << endl;  // Output: 2

    vector<vector<int>> times2 = {{1, 2, 1}};
    int N2 = 2, K2 = 1;
    cout << "Test case 2: " << networkDelayTime(times2, N2, K2) << endl;  // Output: 1

    vector<vector<int>> times3 = {{1, 2, 1}};
    int N3 = 2, K3 = 2;
    cout << "Test case 3: " << networkDelayTime(times3, N3, K3) << endl;  // Output: -1

    return 0;
}
