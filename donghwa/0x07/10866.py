import sys
from collections import deque

N = int(sys.stdin.readline().strip())
cmds = [sys.stdin.readline().strip() for _ in range(N)]
DQ = deque([])
for cmd in cmds:
    if cmd[:10] == "push_front":
        DQ.appendleft(int(cmd.split()[-1]))
    elif cmd[:9] == "push_back":
        DQ.append(int(cmd.split()[-1]))
    elif cmd == "pop_front":
        if (len(DQ)>0) :
            print(DQ.popleft())
        else : print(-1)
    elif cmd == "pop_back":
        if (len(DQ)>0) :
            print(DQ.pop())
        else : print(-1)
    elif cmd == "size":
        print(len(DQ))
    elif cmd == "empty":
        if (len(DQ) > 0) :
            print(0)
        else :
            print(1)
    elif cmd == "front":
        if (len(DQ) > 0) :
            print(DQ[0])
        else : print(-1)
    elif cmd == "back":
        if (len(DQ) > 0) :
            print(DQ[-1])
        else : print(-1)
    