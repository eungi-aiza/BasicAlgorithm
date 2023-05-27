import sys

n = int(sys.stdin.readline())

cnt = 0
for i in range(n):
    input_str = sys.stdin.readline().strip()
    stack = []

    for x in input_str:
        if not stack:
            stack.append(x)
        else:
            if x == stack[-1]: stack.pop()
            else: stack.append(x)
    if not stack:
        cnt += 1
print(cnt)