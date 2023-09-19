from sys import stdin
input(); t = []
for num in map(int, stdin):
    t.append(num) if num else t.pop()
print(sum(t))
