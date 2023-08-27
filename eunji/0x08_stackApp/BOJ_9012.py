from collections import deque
import sys

def check(paren):
    D = deque([])
    for c in paren:
        if len(D) == 0: D.append(c)
        elif c == ')':
            if D[-1] == '(': D.pop()
            else: D.append(c)
        else: D.append(c)
    if len(D) != 0: return "NO"
    else: return "YES"


N = int(sys.stdin.readline())
for i in range(N):
    paren = sys.stdin.readline()[:-1]
    print(check(paren))
