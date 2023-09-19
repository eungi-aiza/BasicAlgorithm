// Given a directed acyclic graph (DAG) of n nodes labeled from 0 to n - 1, find all possible paths from node 0 to node n - 1 and return them in any order.

// The graph is given as follows: graph[i] is a list of all nodes you can visit from node i (i.e., there is a directed edge from node i to node graph[i][j]).

// Input: graph = [[1,2],[3],[3],[]]
// Output: [[0,1,3],[0,2,3]]
// Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.

// Input: graph = [[4,3,1],[3,2,4],[3],[4],[]]
// Output: [[0,4],[0,3,4],[0,1,3,4],[0,1,2,3,4],[0,1,4]]


#include <vector>
#include <iostream>
using namespace std;

class Solution {

void solve(vector<vector<int>>& graph, int source, int target, vector<vector<int>>& ans, vector<int> ds)
{
    if(source == target){
        ds.push_back(source);        // it is the condition where we have found our right path 
        ans.push_back(ds) ;             // hence storing it to the ans 
    }

    ds.push_back(source) ;              // it may be a part of right path

    for(auto it: graph[source]){
        solve(graph, it, target, ans, ds) ;       // call dfs for every neighbour 
    }
}

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) 
    {
        vector<vector<int>> ans;   // for storing the ans;
        vector<int> ds;             // for storing perticular path;

        int target = graph.size() ;     // the last node is the target node where we have to reach
        solve(graph, 0, target-1, ans, ds) ;         //dfs

        return ans;                // returning ans; 
    }
};

int main() {
    Solution s = Solution();
    vector<vector<int>> graph = {{1, 2}, {3}, {3}, {}};
    vector<vector<int>> ans = s.allPathsSourceTarget(graph);
    for (const std::vector<int>& innerVector : ans) {
        for (int element : innerVector) {
            std::cout << element << " ";
        }
        std::cout << std::endl;
    }
}