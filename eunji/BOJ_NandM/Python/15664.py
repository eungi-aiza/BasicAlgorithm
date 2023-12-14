# 중복없이 M개 (비내림차순, N_lst 주어짐, N_lst에 중복있음)
N, M = list(map(int, input().split()))
N_lst = sorted(list(map(int, input().split())))
ans = []
visited = [0]*N

def solution(lastSameAns):
    if len(ans) == M:
        print(*ans)
        return

    lastSameIndex = 0
    for i in range(N):
        if (visited[i] == 0) and (lastSameAns <= N_lst[i]) and (lastSameIndex != N_lst[i]):
            visited[i] = 1
            ans.append(N_lst[i])
            lastSameIndex = N_lst[i]
            lastSameAns = N_lst[i]
            solution(lastSameAns)
            visited[i] = 0
            ans.pop()

solution(0)