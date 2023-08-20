def smallest_pos_int(array):
    n = len(array)
    
    # Step 1: Move all non-positive elements to the left side of the array
    j = 0
    for i in range(n):
        if array[i] <= 0:
            array[i], array[j] = array[j], array[i]
            j += 1
    
    # Step 2: Separate the positive elements and use them to index the array
    for i in range(j, n):
        index = abs(array[i]) - 1  # Adjust index to 0-based
        if index < n - j:
            array[j + index] = -abs(array[j + index])
    
    # Step 3: Find the first positive element and return the smallest missing integer
    for i in range(j, n):
        if array[i] > 0:
            return i - j + 1
    
    return n - j + 1  # If all positive integers are present, return the next
    
if __name__ == '__main__':
    a = [3, 2, 1, 0, -1]
    b = [4, 7, -1, 1, 2]
    c = [100, 101, 102]
    print(smallest_pos_int(a))  # Output: 4
    print(smallest_pos_int(b))  # Output: 3
    print(smallest_pos_int(c))  # Output: 1
