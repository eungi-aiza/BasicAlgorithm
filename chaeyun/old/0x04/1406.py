## 일단 timeout 뜨는데 추후 수정 예정..

import sys

init = sys.stdin.readline().strip()
L = list(init)
cursor = len(L)
n = int(sys.stdin.readline())

for i in range(n):
    s = sys.stdin.readline().strip()
    if s[0] == 'L':
        if cursor > 0:
            cursor -= 1
    elif s[0] == 'D':
        if cursor < len(L):
            cursor += 1
    elif s[0] == 'B':
        if cursor > 0:
            L = L[:cursor-1] + L[cursor:]
            cursor -= 1
    else :
        L.append(s[1])
        cursor += 1

print(''.join(L))
