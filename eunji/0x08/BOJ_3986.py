from collections import deque
import sys

def check(func):
    D = deque([])
    A_flag = 0; B_flag = 0
    for i in func:
        if i == 'A':
            if (A_flag > 0 and D[-1] == 'A'):
                D.pop()
                A_flag -= 1
            else:
                D.append('A')
                A_flag += 1
        elif i == 'B':
            if (B_flag > 0 and D[-1] == 'B'):
                D.pop()
                B_flag -= 1
            else:
                D.append('B')
                B_flag += 1
                
    if len(D) == 0: return 1
    else: return 0
    

N = int(sys.stdin.readline())
ans = 0
for i in range(N):
    func = sys.stdin.readline()[:-1]
    ans += check(func)
print(ans)