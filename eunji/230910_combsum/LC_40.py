from typing import List

class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        self.answers = []
        candidates.sort()
        vis = [0 for i in range(len(candidates))]
        if sum(candidates) < target: 
            return self.answers
        self.backtracking([], candidates, target, vis, 0, 0)        
        return self.answers
    
    def backtracking(self, ans, candidates, target, vis, curr, curr_sum):
        if curr_sum > target:
            return
        
        if (curr_sum == target):
            self.answers.append(ans[:])

        for i in range(curr, len(candidates)):  
            # candidates : 1, 1-, 2-, 5-, 6, 7, 10
            # 포문에서 내가 첫번쨰 요소가 아닌 경우에는, 반드시 이전 candidate값과 달라야된다
            if i > curr and candidates[i] == candidates[i - 1]: #### important
                continue

            if vis[i] == 0:
                vis[i] = 1
                ans.append(candidates[i])
                self.backtracking(ans, candidates, target, vis, i+1, curr_sum+candidates[i])
                vis[i] = 0
                ans.pop()


if __name__ == "__main__":
    sol = Solution()
    candidates = [10,1,2,7,6,1,5]; target = 8
    print(sol.combinationSum2(candidates, target))