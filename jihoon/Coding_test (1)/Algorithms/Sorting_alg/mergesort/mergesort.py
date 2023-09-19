def merge(L:list, first:int, mid:int, last:int) -> None:
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


def mergeSortHelp(L:list, first: int, last: int)->None:
    if first == last:
        return
    else:
        mid = first + (last - first) // 2
        mergeSortHelp(L, first, mid)
        mergeSortHelp(L, mid+1, last)
        merge(L, first, mid, last)

def mergeSort(L:list)->None:
    mergeSortHelp(L, 0, len(L)-1)

if __name__ == '__main__':
    a = [1, 3, 2, 4, 5, 6, 7, 8]
    b = [5, 3, 2, 1, 4, 0, 6, 7]
    mergeSort(a)
    mergeSort(b)
    print(a)
    print(b)