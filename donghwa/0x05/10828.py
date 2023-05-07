import sys

N = int(sys.stdin.readline().rstrip())
cmds = [sys.stdin.readline().rstrip() for _ in range(N)]
stack = []
for cmd in cmds :
    if cmd[:4] == "push" :
        x = cmd.split()[1]
        stack.append(x)
    elif cmd == "pop" :
        if len(stack) > 0:
            print(stack.pop())
        else :
            print(-1)
    elif cmd == "size":
        print(len(stack))
    elif cmd == "empty":
        if len(stack) > 0 :
            print(0)
        else :
            print(1)
    elif cmd == "top":
        if len(stack) > 0 :
            print(stack[-1])
        else :
            print(-1)