
def print_dat():
    global dat, nxt
    cur = nxt[0]
    while(cur != -1):
        print(dat[cur], end="")
        cur = nxt[cur]
    print()
        
def insert(add):
    global dat, prv, nxt, unused, cursor
    dat[unused] = add
    prv[unused] = cursor
    nxt[unused] = nxt[cursor]
    
    if (nxt[cursor] != -1):
        prv[nxt[cursor]] = unused
    nxt[cursor] = unused
    unused += 1
    cursor = nxt[cursor]
    
def delete():
    global dat, prv, nxt, unused, cursor
    if (prv[cursor] != -1) :
        nxt[prv[cursor]] = nxt[cursor]
        prv[nxt[cursor]] = prv[cursor]
        cursor = prv[cursor]
        
    

if __name__ == "__main__":
    global dat, prv, nxt, unused, cursor
    
    MX = 1000005
    dat = [0]*MX
    prv,nxt = [-1]*MX, [-1]*MX
    unused = 1
    cursor = 0

    init = input()
    num = int(input())
    # ops = [input() for i in range(num)]
    
    for i, c in enumerate(init, start=1) :
        insert(c)
    
    while (num != 0) :
        op = input()
        if op.startswith("P") :
            add = op.split()[-1]
            insert(add)
        elif op.startswith("L") :
            if (prv[cursor] != -1) :
                cursor = prv[cursor]
        elif op.startswith("D"):
            if (nxt[cursor] != -1) :
                cursor = nxt[cursor]
        elif op.startswith("B"):
            if (prv[cursor] != -1) :
                delete()
        num -= 1
    print_dat()    