# 중복없음 M개 (sorted만)
def solution(N_lst, M, ans):
    if (len(ans) == M) and (sorted(ans) == ans):
        print(' '.join(map(str,ans)))
        return

    for i in range(len(N_lst)):
        if N_lst[i] not in ans:
          solution(N_lst, M, ans+[N_lst[i]])

N, M = list(map(int, input().split()))
N_lst = [i+1 for i in range(N)]
solution(N_lst, M, ans=[])