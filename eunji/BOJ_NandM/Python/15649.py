# 중복없음 M개
def solution(N, M, ans):
    if len(ans) == M:
        print(' '.join(map(str, ans)))
        return
        
    for i in range(len(N)):
        if N[i] not in ans:
          solution(N, M, ans+[N[i]])

N, M = list(map(int, input().split()))
N_lst = [i+1 for i in range(N)]
solution(N_lst, M, ans=[])
