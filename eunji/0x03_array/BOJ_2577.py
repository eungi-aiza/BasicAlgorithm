A = int(input())
B = int(input())
C = int(input())
# print(A,B,C)

target = A*B*C
counter = {i:0 for i in range(10)}
# for i in range(10):
    # counter[i] = 0
    
while (target > 0):
    num = target % 10
    counter[num] += 1
    target = target // 10
    
for i in range(10):
    print(counter[i])