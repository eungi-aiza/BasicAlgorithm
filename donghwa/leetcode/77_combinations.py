"""
Given two integers n and k, 
return all possible combinations of k numbers chosen from the range [1, n].

You may return the answer in any order
ex. 
Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Explanation: There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.

Result : Time Limit Exceeded
"""

class Solution:
    def combine_help(self, n, k, cur, isused, res):
        if (cur == k):
            res.append([i+1 for i, val in enumerate(isused) if val==1])

        for i in range(n):
            if isused[i]:
                continue
            isused[i] = 1
            self.combine_help(n, k, cur+1, isused, res)
            isused[i] = 0

    def combine(self, n: int, k: int):
        isused = [0]*n
        res = []
        self.combine_help(n, k, 0, isused, res)
        res_new = []
        for item in res :
            set_item = set(item)
            if set_item not in res_new:
                res_new.append(set_item)
             
        return [list(item) for item in res_new]
        
if __name__ == "__main__":
    n = 13
    k = 13
    print(Solution().combine(n, k))