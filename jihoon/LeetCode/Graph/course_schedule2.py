class Solution:
    def findOrder(self, numCourses: int, prerequisites: List[List[int]]) -> List[int]:
        pre = [[] for _ in range(numCourses)]
        nums = [0 for _ in range(numCourses)]
        ans, q = [], []
        
        for prerequisite in prerequisites:
            pre[prerequisite[1]].append(prerequisite[0])
            nums[prerequisite[0]] += 1
        
        for n in range(numCourses):
            if nums[n] == 0:
                q.append(n)
                
        while q:
            temp = q.pop()
            ans.append(temp)
            for req in pre[temp]:
                nums[req] -= 1
                if nums[req] == 0:
                    q.append(req)

        if len(ans) == numCourses:
            return ans
        else:
            return []