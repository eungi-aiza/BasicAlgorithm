N = int(input())

counter = {i:0 for i in range(10)}
while (N > 0):
    temp = N % 10
    counter[temp] += 1
    N //= 10
    
sixnine = counter[9] + counter[6]
sum = sixnine / 2 + 1 if (sixnine % 2 > 0) else sixnine /2

answer = 0
for i in range(10):
    if (counter[i] > answer) and (i!=6) and (i!=9):
        answer = counter[i]
        
print(int(max(sum, answer)))