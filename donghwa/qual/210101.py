
def func(arr):
    a = min(arr) # -1
    b = max(arr) # 7
    
    if a*b < 0 or a == 0:
        for i in range(1, b):
            if i not in arr : # 근데 이렇게 하면 list array의 갯수에 비례하진 않기 때문에 dictionary로 풀어야함!
                return i
        return b+1
    elif b <= 0 or a > 0 or b < 0:
        return 1
    

if __name__ == "__main__":
    arr = [4, 7, -1, 1, 2]
    print(func(arr))
    arr = [100, 101, 102] 
    print(func(arr))
    arr = [3, 2, 1, 0, -1] 
    print(func(arr))
    arr = [0, 0, 0, 0]
    print(func(arr))
    arr = [1,2,3,4]
    print(func(arr))
    arr = [-1,-2,0,1]
    print(func(arr))