import sys
from collections import deque


DX = [1,0,-1,0]
DY = [0,1,0,-1]

def get_input():
    N = int(sys.stdin.readline().rstrip())
    pic  = [list(sys.stdin.readline().rstrip()) for _ in range(N)]
    # print(pic)
    return N, pic

N, PIC = get_input()
VIS = [[0 for i in range(N)] for m in range(N)]


def bfs(x, y, c='R'):
    dq = deque([])
    dq.append((x,y))
    while (len(dq) != 0):
        curr = dq.popleft()
        for cx, cy in zip(DX, DY):
            mx = curr[0] + cx
            my = curr[1] + cy
            if (mx < 0) or (my < 0) or (mx >= N) or (my >= N): 
                continue
            if (VIS[mx][my] == 1) or (PIC[mx][my] != c):
                continue
            VIS[mx][my] = 1
            # print(VIS)
            dq.append((mx,my))
            # print((mx,my))
            

A = 0
B = 0
for i in range(N):
    for j in range(N):
        if (PIC[i][j] == 'R') and (VIS[i][j] == 0):
            VIS[i][j] = 1
            A += 1
            bfs(i, j, 'R')
        elif (PIC[i][j] == 'G') and (VIS[i][j] == 0):
            VIS[i][j] = 1
            A += 1
            bfs(i, j, 'G')
        elif (PIC[i][j] == 'B') and (VIS[i][j] == 0):
            VIS[i][j] = 1
            A += 1
            B += 1
            bfs(i, j, 'B')
       

VIS = [[0 for i in range(N)] for m in range(N)]
for i in range(N):
    for j in range(N):       
        if (PIC[i][j] == 'G') or (PIC[i][j] == 'R'):
            # print('hey')
            PIC[i][j] = 'K'
# print(PIC)
for i in range(N):
    for j in range(N):           
        if (PIC[i][j] == 'K') and (VIS[i][j] == 0):
            VIS[i][j] = 1
            B += 1
            bfs(i, j, 'K')

print(A, B)
            