from typing import List
import copy

class Solution:
    def combine(self, n: int, k: int) -> List[List[int]]:
        self.answers = []
        vis = [0 for i in range(n+1)]
        ## 여기서 포문 도는 것의 의미 : 연결되어 있지 않은 경우
        self.backtracking(1, n, k, vis, [])
        return self.answers

    def backtracking(self, start, nums, k, vis, ans):
        if (k == len(ans)):
            self.answers.append(ans[:])
            return
        
        ## 여기서 포문의 start점의 의미 : (2,1) == (1,2)
        for i in range(start, nums+1):
            if (vis[i] == 0):
                ans.append(i)
                vis[i] = 1
                self.backtracking(i+1, nums, k, vis, ans)
                vis[i] = 0
                ans.pop()
            # self.backtracking(i+1, nums, k, ans+[i])

if __name__ == "__main__":
    sol = Solution()
    print(sol.combine(4, 2))