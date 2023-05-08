# -*- coding: utf-8 -*-

K = int(input())
stack = [0]

for k in range(K):
    num = int(input())
    if num == 0:
        stack.pop()
    else:
       # stack[k] = num #인덱스 이상해짐
       stack.append(num)
        
print(sum(stack))