from typing import List


class Solution:
    def backtracking(self, curr, n2l, digits, ans):
        if (len(list(ans))) == len(digits):
            self.answers.append(ans)
            return
        
        for nei in n2l[digits[curr]]:
            ans += nei
            self.backtracking(curr+1, n2l, digits, ans)
            ans = ans[:-1]

    def letterCombinations(self, digits: str) -> List[str]:
        self.answers = []
        n2l = {"2": ['a','b','c'], "3": ['d','e','f'], "4": ['g','h','i'],
               "5": ['j', 'k','l'], "6": ['m','n','o'], "7":['p','q','r','s'],
                "8": ['t','u','v'], "9": ['w','x','y','z'] }
        digits = list(digits)
        if len(digits) != 0:
            self.backtracking(0, n2l, digits, "")
        return self.answers


if __name__ == "__main__":
    sol = Solution()
    digits = "23"
    print(sol.letterCombinations(digits))