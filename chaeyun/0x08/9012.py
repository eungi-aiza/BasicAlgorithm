from sys import stdin


n = int(input().strip())

for _ in range(n):
    input_str = stdin.readline().rstrip()
    stack = []
    is_balanced = True

    for x in input_str:
        if x == '(':
            stack.append(x)
        elif x == ')':
            if not stack:
                is_balanced = False
                break
            elif stack[-1] == '(':
                stack.pop()
            else:
                is_balanced = False
                break

    if stack:
        is_balanced = False

    if is_balanced:
        print("YES")
    else:
        print("NO")

