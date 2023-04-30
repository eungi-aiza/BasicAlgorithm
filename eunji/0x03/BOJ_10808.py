import sys
inputs = sys.stdin.readline().rstrip()
# print(inputs)
# print(len(inputs))

alps = [0 for i in range(26)]
for i in inputs:
    # print(ord('a'))
    alps[ord(i)-ord('a')] += 1
    
for i in range(26):
    print(alps[i])
    
    