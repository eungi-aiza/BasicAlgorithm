                       
N, K = map(int, input().split())
check = [0] * 5002
cur = K
print("<{}".format(cur), end="")
check[cur] = 1

for i in range(N-1):
    for j in range(K):
        while True:
            cur += 1
            if cur > N:
                cur = 1
            if check[cur] == 0:
                break
    print(", {}".format(cur), end="")
    check[cur] = 1

print(">")
