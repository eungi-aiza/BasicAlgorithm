# 중복 M개 (비내림차순, N_list 주어짐)
N, M = list(map(int, input().split()))
N_lst = list(sorted(set(list(map(int, input().split())))))
N = len(N_lst)
ans = []

def solution(lastSameAns):
    if len(ans) == M:
        print(*ans)
        return

    lastSameIndex = 0
    for i in range(N):
        if N_lst[i] >= lastSameAns:
          lastSameIndex = N_lst[i]
          lastSameAns = N_lst[i]
          ans.append(N_lst[i])
          solution(lastSameAns)
          ans.pop()

solution(0)