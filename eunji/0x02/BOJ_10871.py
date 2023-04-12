N, X = map(int, input().split())
inputs = list(map(int, input().split()))

for i in range(len(inputs)):
    if inputs[i] < X:
        print(inputs[i], end=" ")
    