from collections import defaultdict

class Solution:
    def findAncestors(self, n, edges) :

        ans = [[] for _ in range(n)]

        g = defaultdict(list)

        for u, v in edges:
            g[v].append(u)
        
        def dfs(node, curr):
            for v in g[curr]:
                if v not in ans[node]:
                    dfs(node, v)
                    ans[node].append(v)  
        
        for i in range(n):
            dfs(i,i)

        for k in ans:
            k.sort()
            
        return ans 
# Test Cases
sol = Solution()
print(sol.findAncestors(8, [[0,3],[0,4],[1,3],[2,4],[2,7],[3,5],[3,6],[3,7],[4,6]]))
# Output: [[], [], [], [0, 1], [0, 2], [0, 1, 3], [0, 1, 2, 3, 4], [0, 1, 2, 3]]

print(sol.findAncestors(5, [[0,1],[0,2],[0,3],[0,4],[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]))
# Output: [[], [0], [0, 1], [0, 1, 2], [0, 1, 2, 3]]
