from collections import deque
import sys

def print_deq(D, flag):
    if (flag == -1): print("error")
    elif (len(D) == 0): print("[]")
    elif (flag == 0): 
        print('[', end='')
        for i in range(len(D)-1):
            print(str(D[i])+',', end='')
        print(str(D[len(D)-1])+']')
    else:
        print('[',end='')
        for i in range(len(D)-1,0,-1):
            print(str(D[i]), end=',')
        print(str(D[0])+']')

def make_deq(D, size, ns):
    if size == 0:
        return
    ns = ns[1:-2].split(',') 
    for i in ns:
        if i == ',': continue
        D.append(int(i))   
        
testcase = int(sys.stdin.readline())
for i in range(testcase):
    reverse_flag = 0
    func = sys.stdin.readline()
    size = int(sys.stdin.readline())
    ns = sys.stdin.readline()
    D = deque([])
    make_deq(D, size, ns)
    for f in func:
        if (f == 'R'):
            if (reverse_flag == 0): reverse_flag = 1
            else: reverse_flag = 0
        elif (f == 'D'):
            if (len(D) == 0):
                reverse_flag = -1
                break
            elif (reverse_flag == 0): D.popleft()
            elif (reverse_flag == 1): D.pop()
            
    print_deq(D, reverse_flag)