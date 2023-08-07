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
    '''
    [INPUT] 
    A : 'abc'
    combs : [['a', 'b', 'c'], ['a', 'c', 'b'], ['b', 'a', 'c'], ['b', 'c', 'a'], ['c', 'a', 'b'], ['c', 'b', 'a']]

    [OUTPUT]
    any string among combs in which no adjacent letter locate beside.
    If there's no such as return ''
    '''
    for comb in combs:
        is_valid = True
        for j in range(len(comb)-1):
            # Get the indices in the original string
            index1 = A.index(comb[j])
            index2 = A.index(comb[j+1])

            # If the difference is 1, they are adjacent in the original string
            if abs(index1 - index2) == 1:
                is_valid = False
                break

        if is_valid:
            # Convert list of characters back to a string
            return ''.join(comb)
    return ""
   
   
def foo(A):   
    combs = combs_make(A)
    ans = filter(combs, A)
    print(ans)
        
                
A = 'abcdef'
combs = combs_make(A)
foo(A)
# print(combs)