import sys
from collections import deque

paren = sys.stdin.readline()
ans = 0
flag = 0
D = deque([])

for c in paren:
    if c == '(':
        ans += 1
        D.append(c)
        flag = 1
    elif (c == ')') and (flag == 1):
        ans -= 1
        if (len(D) != 1):
            ans += len(D) - 1
        flag = 0
        D.pop()
    elif (c == ')') and (flag == 0):
        D.pop()
        
print(ans)
