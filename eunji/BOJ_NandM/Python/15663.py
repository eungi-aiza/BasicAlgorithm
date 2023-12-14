# 중복허용 M개 (N_lst 주어짐, N_lst에 중복있음)
def solution(N_lst, M, ans, visited):
    if (len(ans) == M):
        print(*ans)
        return
    
    last = 0
    for i in range(len(N_lst)): # 1 1 2 2 # 
        if not visited[i] and last != N_lst[i]: # 위치를 넣을때만 고려
            visited[i] = 1
            ans.append(N_lst[i])
            last = N_lst[i]
            solution(N_lst, M, ans, visited)
            visited[i] = 0
            ans.pop()
        
N, M = list(map(int, input().split()))
N_lst = sorted((list(map(int, input().split()))))
solution(N_lst, M, ans=[], visited=[0]*N)