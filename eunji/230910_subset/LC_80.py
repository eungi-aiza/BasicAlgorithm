from typing import List

class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        vis = [0 for i in range(len(nums))]
        nums.sort()
        self.answers = []
        self.backtracking([], 0, vis, nums)
        return self.answers

    def backtracking(self, ans, curr, vis, nums):
        if ans not in self.answers:
            self.answers.append(ans[:])
            
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
    l1 = [4,4,4,1,4]
    print(sol.subsetsWithDup(l1))