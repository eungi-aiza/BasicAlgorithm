n = int(input())
numlist = list(map(int, input().split()))
tot = int(input())

count = 0
num_dict = {}

for i in range(n):
    complement = tot - numlist[i]
    if complement in num_dict:
        count += num_dict[complement]
    if numlist[i] in num_dict:
        num_dict[numlist[i]] += 1
    else:
        num_dict[numlist[i]] = 1

print(count)
