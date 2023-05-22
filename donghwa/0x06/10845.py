import sys
N = int(sys.stdin.readline().strip())
cmds = [sys.stdin.readline().strip() for _ in range(N)]
queue = []
for cmd in cmds :
    if cmd[:4] == "push":
        queue.append(cmd.split()[-1])
    elif cmd == "pop":
        if len(queue) > 0 :
            print(queue.pop(0))
        else :
            print(-1)
    elif cmd == "size":
        print(len(queue))
    elif cmd == "empty":
        if len(queue) == 0:
            print(1)
        else :
            print(0)
    elif cmd == "front":
        if len(queue) > 0 :
            print(queue[0])
        else :
            print(-1)
    elif cmd == "back":
        if len(queue) > 0 :
            print(queue[-1])
        else :
            print(-1)
    N -= 1