# 중복 M개
def solution(N_lst, M, ans):
    if len(ans) == M:
        print(' '.join(map(str,ans)))
        return

    for i in range(len(N_lst)):
        solution(N_lst, M, ans+[N_lst[i]])

N, M = list(map(int, input().split()))
N_lst = [i+1 for i in range(N)]
solution(N_lst, M, ans=[])
