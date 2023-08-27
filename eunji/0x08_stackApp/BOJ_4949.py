from collections import deque
import sys

def check(input):
    if (input == '(' or input == '['):
        S.append(input)
    elif (input == ')'):
        if (len(S) == 0): return "no"
        elif (S[-1] == '('): S.pop(); return
        else: return "no"
    elif (input == ']'):
        if (len(S) == 0): return "no"
        elif (S[-1] == '['): S.pop(); return
        else: return "no"
    else: return
    
ans = "yes"
S = deque([])
while True:
    input = sys.stdin.readline()[:-1]
    if (input == "."): break
    for c in input:
        if (ans == "yes") and check(c):
            ans = check(c)
        if (c == "."):
            if (len(S) == 0 and ans == "yes"): 
                print("yes")
            else: print("no")
            ans = "yes"
            S = deque([])