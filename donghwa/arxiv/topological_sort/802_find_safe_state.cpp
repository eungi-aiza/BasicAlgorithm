/* 802. Find Eventual Safe States

There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].

A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).

Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

 

Example 1:

Illustration of graph
Input: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
Output: [2,4,5,6]
Explanation: The given graph is shown above.
Nodes 5 and 6 are terminal nodes as there are no outgoing edges from either of them.
Every path starting at nodes 2, 4, 5, and 6 all lead to either node 5 or 6.
Example 2:

Input: graph = [[1,2,3,4],[1,2],[3,4],[0,4],[]]
Output: [4]
Explanation:
Only node 4 is a terminal node, and every path starting at node 4 leads to node 4.


*/
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n = graph.size();
    vector<int> out_degree(n, 0);
    vector<vector<int>> in_neighbors(n);

    for (int i = 0; i < n; ++i) {
        out_degree[i] = graph[i].size();
        for (int neighbor : graph[i]) {
            in_neighbors[neighbor].push_back(i);
        }
    }

    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (out_degree[i] == 0) {
            q.push(i);
        }
    }

    vector<int> safe_nodes;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        safe_nodes.push_back(node);
        for (int neighbor : in_neighbors[node]) {
            out_degree[neighbor]--;
            if (out_degree[neighbor] == 0) {
                q.push(neighbor);
            }
        }
    }

    sort(safe_nodes.begin(), safe_nodes.end());
    return safe_nodes;
}


