from typing import List


class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        paren = ["(", ")"]
        self.answers = []
        self.backtracking(paren, "", n, [], 0)
        return self.answers
    
    def backtracking(self, paren, ans, n, check, check2):
        if len(check) == 0 and len(list(ans)) == n*2:
            self.answers.append(ans)
            return
        
        for p in paren:
            if (check2 <= n and 
                ((len(check) == 0 and p == "(") or 
                (len(check) != 0 and check[-1] == "(" and p == "("))):
                ans += p
                check.append(p)
                check2 += 1
                self.backtracking(paren, ans, n, check, check2)
                ans = ans[:-1]
                check.pop()
                check2 -= 1
            elif len(check) != 0 and check[-1] == "(" and p == ")":
                ans += p
                check.pop()
                self.backtracking(paren, ans, n, check, check2)
                ans = ans[:-1]
                check.append("(")


if __name__ == "__main__":
    sol = Solution()
    n = 3
    print(sol.generateParenthesis(n))