from collections import deque

def bfs(lab_org, wall, virus, max_virus):
    R = len(lab_org)
    C = len(lab_org[0])
    lab = [[lab_org[r][c] for c in range(C)] for r in range(R)]
    for wr, wc in wall:
        lab[wr][wc] = 5
    dr = [1, 0, -1, 0]
    dc = [0, 1, 0, -1]
    q = deque([])
    for vr, vc in virus:
        q.append((vr, vc))
    num_virus = len(virus)
    while q:
        r, c = q.popleft()
        for mr, mc in zip(dr, dc):
            nr = r + mr
            nc = c + mc
            if nr < 0 or nc < 0 or nr >= R or nc >= C:
                continue
            if lab[nr][nc] == 0:
                lab[nr][nc] = 2
                q.append((nr, nc))
                num_virus += 1
                if max_virus <= num_virus:
                    return num_virus
    return num_virus

R, C = map(int, input().split())
lab = [list(map(int, input().split())) for _ in range(R)]
virus = []
empty = []
for r in range(R):
    for c in range(C):
        if lab[r][c] == 2:
            virus.append((r, c))
        elif lab[r][c] == 0:
            empty.append((r, c))

num_empty = len(empty)
min_virus = len(virus) + num_empty - 3
debug = 1
for i in range(num_empty):
    for j in range(i + 1, num_empty):
        for k in range(j + 1, num_empty):
            num_virus = bfs(lab, [empty[i], empty[j], empty[k]], virus, min_virus)
            min_virus = min(num_virus, min_virus)
print(num_empty - 3 - (min_virus - len(virus)))
