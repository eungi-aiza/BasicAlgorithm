from collections import deque
import sys

D = deque([])
N = int(sys.stdin.readline())
for i in range(N):
    orders = (sys.stdin.readline().split())
    order = orders[0]
    if len(orders) > 1:
        tar = orders[1]
    if (order == "push_back"):
        D.append(tar)
    elif (order == "push_front"):
        D.appendleft(tar)
    elif (order == "pop_front"): 
        if len(D) == 0: print(-1)
        else: print(D.popleft()) 
    elif (order == "pop_back"): 
        if len(D) == 0: print(-1)
        else: print(D.pop())
    elif (order == "size"): print(len(D)) 
    elif (order == "empty"): 
        if len(D) == 0: print(1)
        else: print(0)
    elif (order == "front"): 
        if len(D) == 0: print(-1)
        else: print(D[0])
    elif (order == "back"): 
        if len(D) == 0: print(-1)
        else: print(D[-1])