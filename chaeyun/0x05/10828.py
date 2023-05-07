import sys

n = int(sys.stdin.readline())
S = []

# push X, pop, size, top, empty
for i in range(n):
    c = sys.stdin.readline().split()
    if c[0] == 'push':
        x = int(c[1])
        S.append(x)
    elif c[0] == 'pop':
        if len(S) == 0:
            print(-1)
        else:
            print(S[-1])
            S.pop()
    elif c[0] == 'size':
        print(len(S))
    elif c[0] == 'empty':
        if len(S) == 0:
            print(1)
        else:
            print(0)
    elif c[0] == 'top':
        if len(S) == 0:
            print(-1)
        else:
            print(S[-1])
