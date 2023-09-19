class Solution:
 def maxSubArray(self, nums: List[int]) -> int:
  len_n = len(nums)
  if len_n == 1:
   return nums[0]
 
  max_sum = nums[0]
 
  for i in range(len_n — 1):
   curr_sum = nums[i]
 
  for j in range(i + 1, len_n):
   curr_sum += nums[j]
   max_sum = max(max_sum, curr_sum, nums[j])
 
  return max_sum