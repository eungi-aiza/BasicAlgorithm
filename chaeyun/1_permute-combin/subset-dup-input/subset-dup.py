class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        ans = []
        res = set()
        ds = []
        nums.sort() 
        self.fun(nums, 0, ds, res)

        for subset in res:
            ans.append(list(subset))

        return ans

    def fun(self, nums, index, ds, res):
        if index == len(nums):
            sorted_ds = tuple(sorted(ds))
            res.add(sorted_ds)
            return

        ds.append(nums[index])
        self.fun(nums, index + 1, ds, res)
        ds.pop()
        self.fun(nums, index + 1, ds, res)
