from typing import List
import copy

class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        self.answers = []
        ans = []
        vis = [0 for i in range(len(nums)+1)]
        self.backtracking(nums, vis, ans)
        return self.answers

    def backtracking(self, nums, vis, ans):
        if (len(ans) == len(nums)) and (ans not in self.answers):
            self.answers.append(copy.deepcopy(ans)) 
            # 1차원만 가능: ans.copy(), ans[:]
            return
        
        for i in range(len(nums)):
            if (vis[i] == 0):
                ans.append(nums[i])
                vis[i] = 1
                self.backtracking(nums, vis, ans)
                vis[i] = 0
                ans.pop()

if __name__ == "__main__":
    # l1 = [5,4,6,2]
    l1 = [1,1,2]
    sol = Solution()
    print(sol.permuteUnique(l1))