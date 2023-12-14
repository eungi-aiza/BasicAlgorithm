from itertools import combinations
import copy

N, M = list(map(int, input().split()))
lab_default = []
for i in range(N):
    lab_default.append(list(map(int, input().split())))

def reset_lab():    
    lab = copy.deepcopy(lab_default)
    # lab = [[lab_default[i][j] for j in range(M)] for i in range(N)]
    return lab

def virus(ch, cw):  
    for d in dir:
        nh = ch + d[0]
        nw = cw + d[1]
        if (0 <= nh < N) and (0 <= nw < M) and (lab[nh][nw] == 0) and (visited[nh][nw] != 1):
            visited[nh][nw] = 1
            lab[nh][nw] = 2
            virus(nh, nw)

def safe():
    count = 0
    for i in range(N):
        for j in range(M):
            if lab[i][j] == 0:
                count += 1
    return count

answer_possible = []
dir = [(1,0), (0,1), (-1,0), (0,-1)]
wall_possible = []
answer = 0

for i in range(N):
    for j in range(M):
        if lab_default[i][j] == 0:
            wall_possible.append([i,j])
            
            
for x,y,z in list(combinations(wall_possible, 3)):
    lab = reset_lab()
    visited = []
    for i in range(N):
        visited.append([0 for i in range(M)])
    lab[x[0]][x[1]] = 1
    lab[y[0]][y[1]] = 1
    lab[z[0]][z[1]] = 1
    for i in range(N):
        for j in range(M):
            if lab[i][j] == 2:
                virus(i, j)
    answer = safe()
    answer_possible.append(answer)
    lab[x[0]][x[1]] = 0
    lab[y[0]][y[1]] = 0
    lab[z[0]][z[1]] = 0
    
    
print(max(answer_possible))
            
            
            