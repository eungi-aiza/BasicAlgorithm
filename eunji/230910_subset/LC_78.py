from typing import List

class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        vis = [0 for i in range(len(nums))]
        self.answers = []
        self.backtracking([], 0, vis, nums)
        return self.answers

    def backtracking(self, ans, curr, vis, nums):
        self.answers.append(ans[:]) 
        # [[], [1], [1,2], [1,2,3], [1,3], [2], [2,3], [3]]

        if curr == len(nums):
            return

        for i in range(curr, len(nums)):
            if vis[i] == 0:
                vis[i] = 1
                ans.append(nums[i])
                self.backtracking(ans, i+1, vis, nums)
                vis[i] = 0
                ans.pop()

if __name__ == "__main__":
    sol = Solution()
    l1 = [1,2,3]
    print(sol.subsets(l1))