A = int(input())
B = int(input())
C = int(input())

mult = str(A * B * C)

cnt = [0] * 10

for i in range(len(mult)):
    cnt[int(mult[i])] += 1

for i in range(10):
    print(cnt[i])