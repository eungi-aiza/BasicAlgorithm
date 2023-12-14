
def smallest_pos_int(l):
    hash = dict()
    for element in l:
        if element < 0:
            continue
        if element not in hash:
            hash[element] = element+1

    smallest = 1
    for element in l:
        if smallest not in hash:
            return smallest
        else:
            smallest = hash[smallest]

    return smallest


if __name__ == "__main__":
    array1 = [4, 7, -1, 1, 2]
    array2 = [100, 101, 102]
    array3 = [3, 2, 1, 0, -1]
    ans1 = smallest_pos_int(array1)
    ans2 = smallest_pos_int(array2)
    ans3 = smallest_pos_int(array3)
    print(ans1)
    print(ans2)
    print(ans3)