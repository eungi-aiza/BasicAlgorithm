def backtracking(start, arr, isused, input, curr, combs):
    isused[start] = 1
    arr.append(input[start])
    if (curr == len(input)-1):
        combs.append(arr[:]) ### why??????
        # combs.append(arr)
        return
    
    for i in range(0, len(input)):
        if isused[i] != 1:
            backtracking(i, arr, isused, input, curr+1, combs)
            isused[i] = 0
            arr.pop()


def combs_make(s):
    combs = []
    length = len(s)
    isused = [0 for i in range(length)]
    input = [s[i] for i in range(length)]
    arr =  []
    for i in range(length):
        backtracking(i, arr, isused, input, 0, combs)
        isused[i] = 0
        arr.pop()
    return combs


def filter(combs, A):
    for i in combs:
        for j in range(len(i)):
            if ((j+1 < len(i)) and 
                    ((i[j+1] == A[A.index(i[j])+1]) or 
                    (i[j+1] == A[A.index(i[j])-1]))):
                continue
            if (j-1 >= 0) and ((i[j-1] == A[A.index(i[j])+1]) or (i[j-1] == A[A.index(i[j])-1])):
                continue
            # print(i)
            return ''.join(i)
   
   
def foo(A):   
    combs = combs_make(A)
    ans = filter(combs, A)
    print(ans)
        
                
A = 'abc'
combs = combs_make(A)
# foo(A)
print(combs)