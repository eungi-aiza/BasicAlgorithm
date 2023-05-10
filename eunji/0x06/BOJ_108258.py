from collections import deque
import sys

def push(Q, tar):
    Q.append(tar)
    
def size(Q):
    print(len(Q))

def pop(Q):
    if len(Q): print(Q.popleft())
    else: print(-1)
    
def empty(Q):
    if len(Q): print(0)
    else: print(1)

def front(Q):
    if len(Q): print(Q[0])
    else: print(-1)    

def back(Q):
    if len(Q): print(Q[-1])
    else: print(-1)
    

Q = deque([])
N = int(sys.stdin.readline())
for i in range(N):
    orders = (sys.stdin.readline().split())
    if (orders[0] == "push"): push(Q, orders[1])
    elif (orders[0] == "pop"): pop(Q)
    elif (orders[0] == "size"): size(Q)
    elif (orders[0] == "empty"): empty(Q)
    elif (orders[0] == "front"): front(Q)
    elif (orders[0] == "back"): back(Q)
    