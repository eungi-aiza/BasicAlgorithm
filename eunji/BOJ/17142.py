from itertools import combinations
from collections import deque
import sys

sys.stdout = open('stdout.txt', 'w')
sys.stdin = open("input.txt", "r")

def bfs(alives_virus, lab, space, N):
    q = deque([(i,j,0) for (i,j) in alives_virus])
    visited = set()
    visited_skip = set((i,j) for (i,j) in alives_virus)
    last_depth = 0
    dir = [(0,1), (-1,0), (1,0), (0,-1)]
        
    while q:
        r, c, depth = q.popleft()
        if len(visited) == space:
            break
        for mr, mc in dir:     
            nr = r + mr
            nc = c + mc
            if nr<0 or nc<0 or nr>=N or nc>=N: 
                continue
            elif (nr,nc) not in visited_skip:
                visited_skip.add((nr,nc))
                if (lab[nr][nc] == 0) or (lab[nr][nc] == 2):
                    q.append((nr,nc,depth+1))
                    if (lab[nr][nc] == 0):
                        visited.add((nr,nc))          
        last_depth = depth+1
    if space == 0:
        return 0
    elif len(visited) == space:
        return last_depth
    else:
        return -1

N, M = list(map(int, input().split()))
lab_def = [list(map(int, input().split())) for i in range(N)]

viruslist= []
space = 0
for i in range(N):
    for j in range(N):
        if lab_def[i][j] == 2:
            viruslist.append((i,j))
        elif lab_def[i][j] == 0:
            space += 1

combs = list(combinations(viruslist, M))

ans_list = []
for i in combs:
    time = bfs(i, lab_def, space, N)
    if time >= 0: ans_list.append(time)
    
if ans_list:
    print(min(ans_list))
else:
    print(-1)

sys.stdout.close()