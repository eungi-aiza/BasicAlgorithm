"""
1. Sort the vector(non-decreasing).
2. First remove all the duplicates from vector.
3. Then use recursion and backtracking to solve 
   the problem.
   (A) If at any time sub-problem sum == 0 then 
       add that vector to the result (vector of 
       vectors).
   (B) Else if sum is negative then ignore that 
       sub-problem.
   (C) Else insert the present index in that 
       vector to the current vector and call 
       the function with sum = sum-ar[index] and
       index = index, then pop that element from 
       current index (backtrack) and call the 
       function with sum = sum and index = index+1       
"""
class Solution:
    def combinationSum(self, nums, target) :
        res=[]
        
        def recursion(tar,lis,ind):
            if (tar==target):
                res.append(lis.copy())
                return
            
            if (tar>target):
                return
            for i in range(ind,len(nums)):
                lis.append(nums[i])
                recursion(tar+nums[i],lis,i)
                lis.pop()
        recursion(0,[],0)
        return res
    
# class Solution:
#     def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
#         ans = []
#         helper = []
#         self.findAns(0, target, candidates, ans, helper)
#         return ans
    
#     def findAns(self, index, target, arr, ans, helper):
#         if index == len(arr):
#             if target == 0:
#                 ans.append(helper[:])
#             return
        
#         if arr[index] <= target:
#             helper.append(arr[index])
#             self.findAns(index, target - arr[index], arr, ans, helper)
#             helper.pop()
        
#         self.findAns(index + 1, target, arr, ans, helper)