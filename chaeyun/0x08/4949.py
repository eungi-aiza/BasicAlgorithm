import sys

while True:
    input = sys.stdin.readline().rstrip()
    if input == ".": break
    ST = []
    flg = False

    for x in input:
        if x == '(' or x == '[':
            ST.append(x)
        elif x == ')' or x == ']':
            if not ST:
                flg = True
                break
            elif x == ')' and ST[-1] == '(':
                ST.pop()
            elif x == ']' and ST[-1] == '[':
                ST.pop()
            else:
                flg = True
                break
    if ST:
        flg = True
    
    if not flg:
        print("yes")
    else:
        print("no")