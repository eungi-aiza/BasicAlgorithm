"""
Given a collection of numbers, nums, that might contain duplicates, 
return all possible unique permutations in any order.
ex.
Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]

"""

class Solution:
    def permuteUnique_help(self, nums, perm, res):
        if (len(nums)==0):
            if perm not in res :
                res.append(perm)
        
        for i in range(len(nums)):
            self.permuteUnique_help(nums[:i]+nums[i+1:], perm+[nums[i]], res)

    def permuteUnique(self, nums):
        res = []
        self.permuteUnique_help(nums, [], res)
        return res
        

if __name__=="__main__":
    nums = [1,1,2]
    print(Solution().permuteUnique(nums))