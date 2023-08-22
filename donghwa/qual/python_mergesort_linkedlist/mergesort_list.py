def merge(L, start, mid, end):
    
    k = start
    sub1 = L[start:mid+1]
    sub2 = L[mid+1:end+1]
    i = j = 0
    while i<len(sub1) and j<len(sub2):
        if sub1[i] <= sub2[j] :
            L[k] = sub1[i]
            i += 1
        else :
            L[k] = sub2[j]
            j += 1
        k += 1
        
    # 위의 while 문이 and이기 때문에 하나라도 조건이 False면은 나오게 된다. 
    # 그 경우는 L을 다 채우지 못했다는 이야기이기 때문에 이를 채워주기 위해서 아래의 과정을 수행한다.
    if i<len(sub1):
        for h in range(k, end+1):
            L[h]= sub1[i]
            i += 1
    elif j < len(sub2):
        for h in range(k, end+1):
            L[h] = sub2[j]
            j += 1

def mergesortHelp(L:list, start:int, end:int):
#     start, end = 0, len(L)-1
    if start == end :
        return
    else :    
        mid = start + (end - start)//2
        mergesortHelp(L, start, mid)
        mergesortHelp(L, mid+1, end)
        merge(L, start, mid, end)
    return L
        

mergesortHelp([4,2,1,3], 0, 3)        