from typing import List

class Solution:
    def allPathsSourceTarget(self, graph: List[List[int]]) -> List[List[int]]:
        self.answers = []
        vis = [0 for i in range(len(graph))]
        self.backtracking(0, vis, graph, len(graph)-1, [0])
        return self.answers


    def backtracking(self, curr, vis, graph, target, ans):
        if curr == target:
            self.answers.append(ans[:])
            
        for nei in graph[curr]:
            if vis[nei] == 0:
                vis[nei] = 1
                ans.append(nei)
                self.backtracking(nei, vis, graph, target, ans)
                vis[nei] = 0
                ans.pop()

if __name__ == "__main__":
    sol = Solution()
    graph = [[4,3,1],[3,2,4],[3],[4],[]]
    print(sol.allPathsSourceTarget(graph))