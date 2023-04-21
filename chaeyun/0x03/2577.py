from collections import Counter
a, b, c = [int(input()) for _ in range(3)]
mul = list(str(a*b*c))
mul_dict = Counter(mul)
for i in range(10):
    print(mul_dict[str(i)])
