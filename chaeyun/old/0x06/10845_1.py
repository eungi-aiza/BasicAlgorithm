from sys import stdin

N = int(stdin.readline())
Que = []
for i in range(N) :
    C = stdin.readline().split()

    if C[0] == 'push' : Que.append(C[1])
    elif C[0] == 'pop' : 
        if Que : print(Que.pop(0))
        else : print(-1)
    elif C[0] == 'size' : print(len(Que))
    elif C[0] == 'empty' :
        if len(Que) == 0 : print(1)
        else : print(0)
    elif C[0] == 'front' :
        if len(Que) == 0 : print(-1)
        else : print(Que[0])
    elif C[0] == 'back' :
        if len(Que) == 0 : print(-1)
        else : print(Que[-1])
