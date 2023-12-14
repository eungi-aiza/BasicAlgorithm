# 중복 M개 (N_list 주어짐)
N, M = list(map(int, input().split()))
N_lst = sorted(list(set(list(map(int, input().split())))))
N = len(N_lst)
ans = []

def solution():
    if len(ans) == M:
        print(*ans)
        return
    
    lastSameIndex = 0
    for i in range(N):
        if lastSameIndex != N_lst[i]:
            ans.append(N_lst[i])
            lastSameIndex = N_lst[i]
            solution()
            ans.pop()
        
solution()