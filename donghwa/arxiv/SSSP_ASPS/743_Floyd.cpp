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

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        const int MAX = 1000000;
        vector<vector<int>> dist(N, vector<int>(N, MAX));

        for (int i = 0; i < N; i++) {
            dist[i][i] = 0;
        }

        for (const vector<int>& e : times) {
            dist[e[0] - 1][e[1] - 1] = e[2];
        }

        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        int maxwait = 0;
        for (int i = 0; i < N; i++) {
            maxwait = max(maxwait, dist[K - 1][i]);
        }

        return (maxwait == MAX) ? -1 : maxwait;
    }
};

int main() {
    Solution solution;

    // Test cases
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
