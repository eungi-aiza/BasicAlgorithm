import sys

n, r, c = map(int, sys.stdin.readline().split())

# 시간 초과, board 사용하면 메모리 오류 -> 그냥 count만 하기!
# cnt = 0
# def Z(N, r, c):
#     global cnt, R, C
#     if (N==1):
#         for i in range(2):
#             for j in range(2):
#                 # board[r+i][c+j] = cnt
#                 if (r+i)==R and (c+j)==C :
#                     print(cnt)
#                 cnt += 1
#         return 
#     Z(N-1, r, c)
#     Z(N-1, r, c+2**(N-1))
#     Z(N-1, r+2**(N-1), c)
#     Z(N-1, r+2**(N-1), c+2**(N-1))
    
# if (R < 2**(N-1)) and (C < 2**(N-1)):
#     Z(N, 0, 0)
# elif (R < 2**(N-1)) and (C > 2**(N-1)):
#     cnt = 4**(N-1)
#     Z(N, 0, 2**(N-1))
# elif (R > 2**(N-1)) and (C < 2**(N-1)):
#     cnt = 2 * 4**(N-1)
#     Z(N, 2**(N-1), 0)
# else :
#     cnt = 3 * 4**(N-1)
#     Z(N, 2**(N-1), 2**(N-1))

# 2^n X 2^n 배열에서 (r,c)를 방문하는 순서를 반환하는 함수
def Z(n, r, c):
    half = 2**(n-1)
    if (n==0):
        return 0
    if (r < 2**(n-1)) and (c < 2**(n-1)):
        return Z(n-1, r, c)
    elif (r < 2**(n-1)) and (c >= 2**(n-1)):
        return half*half + Z(n-1, r, c-half)
    elif (r >= 2**(n-1)) and (c < 2**(n-1)):
        return 2*half*half + Z(n-1, r-half, c)
    else :
        return 3*half*half + Z(n-1, r-half, c-half)
    
print(Z(n, r, c))