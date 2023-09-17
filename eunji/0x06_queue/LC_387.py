from collections import deque
import sys

class Solution:
    def firstUniqChar(self, s: str) -> int:
        qq = deque([])
        cnt = {i:0 for i in range(30)}
        length = 0
        
        while (len(s) > length):
            if (cnt[ord(s[length])-ord('a')] == 0):
                qq.append((s[length], length))
            cnt[ord(s[length])-ord('a')] += 1
            length += 1
            
        while (1):
            if (len(qq) == 0): break
            curr, idx = qq[0]
            if (cnt[ord(curr)-ord('a')] > 1):
                qq.popleft()
            elif (cnt[ord(curr)-ord('a')]==1):
                return idx
        return -1 
            

s1 = "loveleetcode"
s2 = "aabb"
sol = Solution()
print(sol.firstUniqChar(s1))
print(sol.firstUniqChar(s2))