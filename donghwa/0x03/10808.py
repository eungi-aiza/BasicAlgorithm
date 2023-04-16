s = input()
freq = dict()
for c in list('abcdefghijklmnopqrstuvwxyz'):
    freq[c] = 0
for c in s:
    freq[c] += 1

for k,v in freq.items():
    print(v, end=' ')