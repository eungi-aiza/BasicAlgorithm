import sys

A, B, C = map(int, sys.stdin.readline().split())

# 이렇게 하면 B가 21억까지 가기 때문에 시간 초과 
# val = 1
# while(B>0) :
#     val *= A
#     if (val > A):
#         val %= C 
#     B -= 1


def pow(a, b, c):
    if (b==1) :
        return a%c
    val = pow(a, b//2, c)
    val = val * val % c
    if (b%2 == 0) :
        return val
    else :
        return val * a % c     

print(pow(A,B,C))