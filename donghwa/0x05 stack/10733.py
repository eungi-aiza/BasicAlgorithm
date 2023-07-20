import sys
N = int(sys.stdin.readline().rstrip())
nums = [int(sys.stdin.readline().rstrip()) for _ in range(N)]
stack = []
for num in nums :
    if num == 0 and len(stack) > 0:
        stack.pop()
    else :
        stack.append(num)
print(sum(stack))