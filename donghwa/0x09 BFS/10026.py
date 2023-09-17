""" 적록색약
적록색약은 빨간색과 초록색의 차이를 거의 느끼지 못한다. 따라서, 적록색약인 사람이 보는 그림은 아닌 사람이 보는 그림과는 좀 다를 수 있다.

크기가 N×N인 그리드의 각 칸에 R(빨강), G(초록), B(파랑) 중 하나를 색칠한 그림이 있다. 그림은 몇 개의 구역으로 나뉘어져 있는데, 구역은 같은 색으로 이루어져 있다. 또, 같은 색상이 상하좌우로 인접해 있는 경우에 두 글자는 같은 구역에 속한다. (색상의 차이를 거의 느끼지 못하는 경우도 같은 색상이라 한다)

예를 들어, 그림이 아래와 같은 경우에

RRRBB
GGBBB
BBBRR
BBRRR
RRRRR
적록색약이 아닌 사람이 봤을 때 구역의 수는 총 4개이다. (빨강 2, 파랑 1, 초록 1) 하지만, 적록색약인 사람은 구역을 3개 볼 수 있다. (빨강-초록 2, 파랑 1)

그림이 입력으로 주어졌을 때, 적록색약인 사람이 봤을 때와 아닌 사람이 봤을 때 구역의 수를 구하는 프로그램을 작성하시오.

- 입력 :
첫째 줄에 N이 주어진다. (1 ≤ N ≤ 100)

둘째 줄부터 N개 줄에는 그림이 주어진다.
- 출력 :
적록색약이 아닌 사람이 봤을 때의 구역의 개수와 적록색약인 사람이 봤을 때의 구역의 수를 공백으로 구분해 출력한다.

ex1.
- 입력 :
5
RRRBB
GGBBB
BBBRR
BBRRR
RRRRR
- 출력 :
4 3

"""
import sys
from collections import deque

dx = [0,0,-1,1]
dy = [1, -1, 0,0]

N = int(sys.stdin.readline().rstrip())
pic = [list(item for item in sys.stdin.readline().rstrip()) for _ in range(N)]

def BFS(x, y, vis, rg=False):
    global pic, dx, dy
    if rg :
        for i in range(N):
            for j in range(N):
                if pic[i][j] == 'G':
                    pic[i][j] = 'R'

    c = pic[x][y]
    Q = deque([(x,y)])
    while(len(Q)>0):
        cx, cy = Q.popleft()
        for d in range(4):
            px = cx + dx[d]
            py = cy + dy[d]
            if px < 0 or px >= N or py < 0 or py >= N :
                continue
            if pic[px][py] != c or vis[px][py] == 1:
                continue

            vis[px][py] = 1
            Q.append((px, py))
    

cnt = 0
vis = [[0]*N for _ in range(N)]
for i in range(N):
    for j in range(N):
        if vis[i][j] == 0:
            BFS(i, j, vis) 
            cnt += 1     
print(cnt)

cnt = 0
vis = [[0]*N for _ in range(N)]
for i in range(N):
    for j in range(N):
        if vis[i][j] == 0:
            BFS(i, j, vis, True)
            cnt += 1
print(cnt)
