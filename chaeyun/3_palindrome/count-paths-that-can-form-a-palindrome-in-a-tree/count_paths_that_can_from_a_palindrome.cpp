/*2791. Count Paths That Can Form a Palindrome in a Tree
Hard
314
4
Companies
You are given a tree (i.e. a connected, undirected graph that has no cycles) rooted at node 0 consisting of n nodes numbered from 0 to n - 1. The tree is represented by a 0-indexed array parent of size n, where parent[i] is the parent of node i. Since node 0 is the root, parent[0] == -1.

You are also given a string s of length n, where s[i] is the character assigned to the edge between i and parent[i]. s[0] can be ignored.

Return the number of pairs of nodes (u, v) such that u < v and the characters assigned to edges on the path from u to v can be rearranged to form a palindrome.

A string is a palindrome when it reads the same backwards as forwards.

 
s
Example 1:



Input: parent = [-1,0,0,1,1,2], s = "acaabc"
Output: 8
Explanation: The valid pairs are:
- All the pairs (0,1), (0,2), (1,3), (1,4) and (2,5) result in one character which is always a palindrome.
- The pair (2,3) result in the string "aca" which is a palindrome.
- The pair (1,5) result in the string "cac" which is a palindrome.
- The pair (3,5) result in the string "acac" which can be rearranged into the palindrome "acca".
Example 2:

Input: parent = [-1,0,0,0,0], s = "aaaaa"
Output: 10
Explanation: Any pair of nodes (u,v) where u < v is valid.*/


class Solution {
public:
    void dfs(int node, vector<int> &root_path, vector<int> &vis, vector<vector<pair<int, char>>> &adj)
    {
        vis[node]=1;
        for(auto i: adj[node])
        {
            if(!vis[i.first])
            {
                root_path[i.first]=(root_path[node]^(1<<(i.second-'a')));
                // cout << node << ' ' << root_path[node] << ' ' << (1<<(i.second-'a')) << endl;
                dfs(i.first, root_path, vis, adj);
            }
        }
    }
    long long countPalindromePaths(vector<int>& parent, string s) {
        int n=parent.size();
        // n--;
        vector<vector<pair<int, char>>> adj(n);
        for(int i=1;i<n;i++)
        {
            adj[parent[i]].push_back({i, s[i]});
        }
        vector<int> root_path(n, 0);
        vector<int> vis(n, 0);
        dfs(0, root_path, vis, adj);
        // for(auto i: root_path)
        //     cout << i << ' ';
        // cout << '\n';
        long long ans=0;
        map<int, int> full;
        for(int i=0;i<n;i++)
        {
            if(full.find(root_path[i])!=full.end())
                ans+=full[root_path[i]];
            for(int j=0;j<26;j++)
            {
                int new_path=root_path[i]^(1<<j);
                if(full.find(new_path)!=full.end())
                    ans+=full[new_path];
            }
            full[root_path[i]]++;
        }
        return ans;
    }
};