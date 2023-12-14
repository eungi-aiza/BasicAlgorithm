# 중복없음 (오름차순, N_lst 주어짐)
def solution(N_lst, M, ans):
    if len(ans) == M:
        print(' '.join(map(str, ans)))
        return
    
    for i in range(len(N_lst)):
        if not ans:
            solution(N_lst, M, ans+[N_lst[i]])
        elif (N_lst[i] not in ans) and (N_lst[i] > ans[-1]):
            solution(N_lst, M, ans+[N_lst[i]])

N, M = list(map(int, input().split()))
N_lst = sorted(list(map(int, input().split())))
solution(N_lst, M, ans=[])