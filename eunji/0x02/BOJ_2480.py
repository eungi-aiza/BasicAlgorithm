from collections import Counter

inputs = list(map(int, input().split()))
inputs_count = Counter(inputs)
inputs_count = sorted(inputs_count, key=inputs_count.get, reverse=True)

# print(inputs_count)
if (len(inputs_count) == 3):
    prize = 100 * max(inputs_count)
    print(prize)
elif (len(inputs_count) == 2):
    prize = 1000 + (inputs_count[0] * 100)
    print(prize)
elif (len(inputs_count) == 1):
    prize = 10000 + (inputs_count[0] * 1000)
    print(prize)