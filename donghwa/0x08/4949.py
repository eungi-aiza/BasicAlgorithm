from collections import deque
import sys


while(1) :
    line = sys.stdin.readline().rstrip()
    if line == "." :
        break
    S = deque([])
    check = True
    for c in line:
        if (c=='(' or c=='[') :
            S.append(c)
        elif (c == ')') :
            if (len(S)==0 or S[-1] != '('):
                check = False
                break
            S.pop()
        elif (c == ']') :
            if (len(S)==0 or S[-1] != '['):
                check = False
                break
            S.pop()
    if (len(S)>0) :
        check=False
    if (check) :
        print("yes")
    else :
        print("no")