import sys
from collections import deque

n = int(sys.stdin.readline())
q = deque()

for _ in range(n):
    c = sys.stdin.readline().split()
    if c[0] == 'push':
        x = int(c[1])
        q.append(x)
    elif c[0] == 'pop':
        if not q:
            print(-1)
        else:
            print(q.popleft())
    elif c[0] == 'size':
        print(len(q))
    elif c[0] == 'empty':
        print(int(not q))
    elif c[0] == 'front':
        if not q:
            print(-1)
        else:
            print(q[0])
    elif c[0] == 'back':
        if not q:
            print(-1)
        else:
            print(q[-1])
