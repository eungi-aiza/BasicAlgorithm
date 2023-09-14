from typing import List
import copy

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        self.answers = []
        ans = []
        vis = [0 for i in range(len(nums)+1)]
        ## 여기서 포문 도는 것의 의미 : 연결되어 있지 않은 경우
        self.backtracking(nums, vis, ans) 
        return self.answers

    def backtracking(self, nums, vis, ans):
        if len(ans) == len(nums):
            self.answers.append(copy.deepcopy(ans))
            return
        
        ## 여기서 포문의 start점의 의미 : (2,1) != (1,2) 
        for i in range(len(nums)): 
            if (vis[i] == 0):
                ans.append(nums[i])
                vis[i] = 1
                self.backtracking(nums, vis, ans)
                vis[i] = 0
                ans.pop()

if __name__ == "__main__":
    # l1 = [5,4,6,2]
    l1 = [1,2,3]
    sol = Solution()
    print(sol.permute(l1))