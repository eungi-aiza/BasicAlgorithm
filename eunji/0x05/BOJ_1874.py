N = int(input())
ans = []
stack = []

count = 1
flag = 1
for i in range(N):
    x = int(input())
    while (count <= x):
        stack.append(count)
        count += 1
        ans.append('+')
        
    if (stack[-1] == x):
        stack.pop()
        ans.append('-')
    else:
        flag = 0
        
if flag == 0: print("NO")
else:
    for i in range(len(ans)):
        print(ans[i])