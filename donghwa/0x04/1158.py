
def move(cnt):
    global cursor, nxt
    while (cnt != 0) :
        cursor = nxt[cursor]
        cnt -= 1        
    
def dlt() :
    global nxt, prv, cursor
    nxt[prv[cursor]] = nxt[cursor]
    prv[nxt[cursor]] = prv[cursor]
    cursor = nxt[cursor]

if __name__ == "__main__":
    
    N, cnt = list(map(int, input().split()))
    dat = list(range(N))
    prv = dat.copy()
    prv.insert(0,prv.pop(-1))
    nxt = dat.copy()
    nxt.insert(N-1,nxt.pop(0))
    cursor = 0
    res = []
    while (N != 0) :
        while (cnt != 0) :
            cursor = nxt[cursor]
            cnt -= 1     
        
        res.append(cursor+1)
        
        nxt[prv[cursor]] = nxt[cursor]
        prv[nxt[cursor]] = prv[cursor]
        cursor = nxt[cursor]
        N -= 1
    
    prt = "<"
    for idx, item in enumerate(res) :
        if idx != len(res)-1 :
            prt += str(item) + ", "
    prt += str(res[-1]) + ">" 
    print(prt)

