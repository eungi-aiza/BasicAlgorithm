def merge(L, first, mid, last):
    k = first
    sub1 = L[first:mid+1]
    sub2 = L[mid+1:last+1]
    i = j = 0
    while i < len(sub1) and j < len(sub2):
        if sub1[i] <= sub2[j]:
            L[k] = sub1[i]
            i = i + 1
        else:
            L[k] = sub2[j]
            j = j + 1
        k = k + 1
    if i < len(sub1):
        L[k:last+1] = sub1[i:]
    elif j < len(sub2):
        L[k:last+1] = sub2[j:]


def merge_sort_help(L, first, last):
    if first == last:
        return
    else:
        mid = first + (last - first) // 2
        merge_sort_help(L, first, mid)
        merge_sort_help(L, mid+1, last)
        merge(L, first, mid, last)
        
def merge_sort(L):
    merge_sort_help(L, 0, len(L)-1)
    
    
def smallest_pos_int(array):
    merge_sort(array)
    ans = 1
    for i in array:
        if i == ans:
            ans += 1
        elif i < ans:
            continue
        elif i > ans:
            break
    return ans
    

if __name__ == '__main__':
    a = [3, 2, 1, 0, -1] # 4
    b = [4, 7, -1, 1, 2] # 3
    c = [100, 101, 102] # 1
    print(smallest_pos_int(a))
    print(smallest_pos_int(b))
    print(smallest_pos_int(c))
