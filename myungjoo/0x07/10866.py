import sys
from collections import deque

N = int(input())
Q = deque()

for _ in range(N):
    command = sys.stdin.readline().split()
    
    if command[0] == "push_front":
        Q.appendleft(command[1])
    if command[0] == "push_back":
        Q.append(command[1])
    if command[0] == "pop_front":
        if Q:
            num = Q.popleft()
            print(num)
        else:
            print(-1)
    if command[0] == "pop_back":
        if Q:
            num = Q.pop()
            print(num)
        else:
            print(-1)
    if command[0] == "size":
        print(len(Q))
    if command[0] == "empty":
        if Q:
            print(0)
        else:
            print(1)
    if command[0] =="front":
        if Q:
            print(Q[0])
        else:
            print(-1)
    if command[0] =="back":
        if Q:
            print(Q[-1])
        else:
            print(-1)
            
        
    
        