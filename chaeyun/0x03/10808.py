from collections import Counter
char = Counter(input())
for i in range(97, 123):
    print(char[chr(i)], end=' ')
