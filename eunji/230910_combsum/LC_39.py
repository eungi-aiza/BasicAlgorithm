from typing import List

class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        self.answers = []
        self.backtracking([], candidates, target)        
        return self.answers
    
    def backtracking(self, ans, candidates, target):
        remain = target-sum(ans)
        if remain < 0:
            return
        
        if sum(ans) == target:
            self.answers.append(ans[:])

        for c in candidates:
            if len(ans) == 0:
                ans.append(c)
                self.backtracking(ans, candidates, target)
                ans.pop()
            elif c >= ans[-1]: # 2 3 2
                ans.append(c)
                self.backtracking(ans, candidates, target)
                ans.pop()


if __name__ == "__main__":
    sol = Solution()
    candidates = [2,3,6,7]; target = 7
    print(sol.combinationSum(candidates, target))