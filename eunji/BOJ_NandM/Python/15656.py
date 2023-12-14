# 중복 M개 (오름차순, N_lst 주어짐)
def solution(N_lst, M, ans):
    if len(ans) == M:
        print(' '.join(map(str, ans)))
        return

    for i in range(len(N_lst)):
        solution(N_lst, M, ans+[N_lst[i]])

N, M = list(map(int, input().split()))
N_lst = sorted(list(map(int, input().split())))
solution(N_lst, M, ans=[])