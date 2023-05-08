# from collections import deque
import sys

stack = []

N = int(sys.stdin.readline())
for i in range(N):
    orders = sys.stdin.readline().split()
    # print(orders)
    order = orders[0]
    if len(orders) == 2:
        tar = int(orders[1])
    if (order == "push"):
        stack.append(tar)
    elif (order == "pop"):
        if len(stack) > 0: print(stack.pop())
        else: print(-1)
    elif (order ==  "top"):
        if len(stack) > 0: print(stack[-1])
        else: print(-1)
    elif (order == "size"):
        print(len(stack))
    elif (order == "empty"):
        if len(stack) > 0: print(0)
        else: print(1)