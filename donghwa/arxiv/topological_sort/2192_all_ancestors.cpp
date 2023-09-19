/* 2192. All Ancestors of a Node in a Directed Acyclic Graph

You are given a positive integer n representing the number of nodes of a Directed Acyclic Graph (DAG). The nodes are numbered from 0 to n - 1 (inclusive).

You are also given a 2D integer array edges, where edges[i] = [fromi, toi] denotes that there is a unidirectional edge from fromi to toi in the graph.

Return a list answer, where answer[i] is the list of ancestors of the ith node, sorted in ascending order.

A node u is an ancestor of another node v if u can reach v via a set of edges.

 

Example 1:


Input: n = 8, edgeList = [[0,3],[0,4],[1,3],[2,4],[2,7],[3,5],[3,6],[3,7],[4,6]]
Output: [[],[],[],[0,1],[0,2],[0,1,3],[0,1,2,3,4],[0,1,2,3]]
Explanation:
The above diagram represents the input graph.
- Nodes 0, 1, and 2 do not have any ancestors.
- Node 3 has two ancestors 0 and 1.
- Node 4 has two ancestors 0 and 2.
- Node 5 has three ancestors 0, 1, and 3.
- Node 6 has five ancestors 0, 1, 2, 3, and 4.
- Node 7 has four ancestors 0, 1, 2, and 3.
Example 2:


Input: n = 5, edgeList = [[0,1],[0,2],[0,3],[0,4],[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Output: [[],[0],[0,1],[0,1,2],[0,1,2,3]]
Explanation:
The above diagram represents the input graph.
- Node 0 does not have any ancestor.
- Node 1 has one ancestor 0.
- Node 2 has two ancestors 0 and 1.
- Node 3 has three ancestors 0, 1, and 2.
- Node 4 has four ancestors 0, 1, 2, and 3.
 
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <map>
using namespace std;


class Solution {
public:
    map<int,vector<int>>mp;
    void fill(vector<vector<int>>& edges){
        for(auto i:edges){
            int u=i[0],v=i[1];
            mp[v].push_back(u);
        }
        return;
    }
    void dfs(int node,vector<bool>&vis,set<int>&ans){
        int kk=node;
        if(mp.find(node)==mp.end()){
            ans.insert(node);
            return;
        }
        vis[node]=true;
        ans.insert(node);

        for(auto i:mp[node]){
            if(!vis[i]) dfs(i,vis,ans);
        }
        return;
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        mp.clear();
        fill(edges);
        
        vector<vector<int>>ans;

        for(int i=0;i<n;i++){
            if(mp.find(i)==mp.end()){
                ans.push_back({});
                continue;
            }
            vector<bool>vis(n+1,false);
            set<int>res;

            dfs(i,vis,res);

            if(res.find(i)!=res.end()) res.erase(i);

            vector<int>temp(res.begin(),res.end());
            
            ans.push_back(temp);
        }
        return ans;
    }
};

int main(){

    vector<vector<int>> edges = {{0,3},{0,4},{1,3},{2,4},{2,7},{3,5},{3,6},{3,7},{4,6}};

    Solution solution;
    int n = 8;
    vector<vector<int>> result1 = solution.getAncestors(n, edges);
    for (const vector<int>& ancestors : result1) {
        for (int ancestor : ancestors) {
            cout << ancestor << " ";
        }
        cout << endl;
    }



}
