def merge(L:list, first:int, mid:int, last:int, reverse: bool) -> None:
    k = first
    sub1 = L[first:mid+1]
    sub2 = L[mid+1:last+1]
    i = j = 0
    while i < len(sub1) and j < len(sub2):
        # Compare the lengths of the elements
        if reverse:
            condition = len(sub1[i]) >= len(sub2[j])
        else:
            condition = len(sub1[i]) <= len(sub2[j])
        
        if condition:
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

def mergeSortHelp(L:list, first: int, last: int, reverse: bool)->None:
    if first == last:
        return
    else:
        mid = first + (last - first) // 2
        mergeSortHelp(L, first, mid, reverse)
        mergeSortHelp(L, mid+1, last, reverse)
        merge(L, first, mid, last, reverse)

def mergeSort(L:list, reverse=False)->None:
    mergeSortHelp(L, 0, len(L)-1, reverse)

if __name__ == '__main__':
    a = ['apple', 'banana', 'kiwi', 'grapes', 'mango', 'pear']
    b = ['lion', 'elephant', 'cat', 'tiger', 'monkey']
    mergeSort(a)  # Sort in ascending order of lengths
    mergeSort(b, reverse=True)  # Sort in descending order of lengths
    print(a)
    print(b)