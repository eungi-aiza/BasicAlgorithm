"""
Given an array nums of distinct integers, return all the possible permutations. 
You can return the answer in any order.
ex. 
Input : nums = [1,2,3]
Output : [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
"""

class Solution:

    def permute_help(self, nums, perm, res):
        if (len(nums)==0):
            if perm not in res :
                res.append(perm)

        for i in range(len(nums)):
            self.permute_help(nums[:i]+nums[i+1:], perm+[nums[i]], res)

    def permute(self, nums):
        result = []
        self.permute_help(nums, [], result)
        return result



