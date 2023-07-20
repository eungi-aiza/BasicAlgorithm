import sys

N = int(sys.stdin.readline().rstrip())
# def hanoi(k):
#     if (k==1) :
#         print(1, 3)
#         return 1
#     val = hanoi(k-1)
#     return 2*val +1

# print(hanoi(N))

# 함수를 정의할 때 원판 n개를 a번 기둥에서 b번 기둥으로 옮기는 방법을 출력하는 함수를 정의한다.
def hanoi(start, end, n):
    if (n==1):
        print(start, end)
        return
    # n-1개의 원판을 기둥 a에서 기둥 6-a-b로 옮긴다.
    hanoi(start, 6-start-end, n-1)
    # n번 원판을 기둥 a에서 기둥 b로 옮긴다.
    print(start, end)
    # n-1개의 원판을 기둥 6-a-b에서 기둥 b로 옮긴다.
    hanoi(6-start-end, end, n-1)
    
print(2**N-1)
hanoi(1,3, N)