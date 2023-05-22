from collections import deque
import sys

input = sys.stdin.readline
n = int(input().strip())

DQ = deque()

for _ in range(n):
    command = input().split()
    if command[0] == "push_front":
        val = int(command[1])
        DQ.appendleft(val)
        
    elif command[0] == "push_back":
        val = int(command[1])
        DQ.append(val)
        
    elif command[0] == "pop_front":
        if not DQ: print(-1)
        else: print(DQ.popleft())
            
    elif command[0] == "pop_back":
        if not DQ: print(-1)
        else: print(DQ.pop())
            
    elif command[0] == "size":
        print(len(DQ))
        
    elif command[0] == "empty":
        print(int(not DQ))
        
    elif command[0] == "front":
        if not DQ: print(-1)
        else: print(DQ[0])
            
    else :
        if not DQ: print(-1)
        else: print(DQ[-1])
