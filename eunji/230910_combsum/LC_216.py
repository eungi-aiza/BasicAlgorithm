from typing import List

class Solution:
    def combinationSum3(self, k: int, n: int) -> List[List[int]]:
        self.answers = []
        vis = [0 for i in range(0,10)]
        self.backtracking([], k, n, vis, 1, 0)        
        return self.answers
    
    def backtracking(self, ans, k, target, vis, curr, curr_sum):
        if curr_sum > target:
            return        
        
        if (curr_sum == target) and len(ans) == k:
            self.answers.append(ans[:])

        for i in range(curr, 10): 
            if vis[i] == 0:
                vis[i] = 1
                ans.append(i)
                self.backtracking(ans, k, target, vis, i+1, curr_sum+i)
                vis[i] = 0
                ans.pop()


if __name__ == "__main__":
    sol = Solution()
    k = 4; n = 1
    print(sol.combinationSum3(k, n))