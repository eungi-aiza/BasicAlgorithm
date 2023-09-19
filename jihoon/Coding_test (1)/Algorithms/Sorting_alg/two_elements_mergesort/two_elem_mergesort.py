def compare_tuples(t1, t2):
    """Custom comparison function for tuples"""
    if t1[1] < t2[1]:  # compare second element
        return -1
    elif t1[1] > t2[1]:
        return 1
    else:  # If second elements are equal, compare the first elements
        if t1[0] < t2[0]:
            return -1
        elif t1[0] > t2[0]:
            return 1
        else:
            return 0

def merge(L, first, mid, last):
    k = first
    sub1 = L[first:mid+1]
    sub2 = L[mid+1:last+1]
    i = j = 0
    while i < len(sub1) and j < len(sub2):
        if compare_tuples(sub1[i], sub2[j]) <= 0:
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

def mergeSortHelp(L, first, last):
    if first == last:
        return
    else:
        mid = first + (last - first) // 2
        mergeSortHelp(L, first, mid)
        mergeSortHelp(L, mid+1, last)
        merge(L, first, mid, last)

def mergeSort(L):
    mergeSortHelp(L, 0, len(L)-1)

if __name__ == '__main__':
    a = [(2, 3), (1, 3), (1, 2), (4, 2), (5, 6), (3, 6)]
    mergeSort(a)
    print(a)