def find_smallest_positive(arr):
    n = len(arr)
    
    # Separate positive and non-positive numbers
    pos_nums = [x for x in arr if x > 0]
    
    # Create a boolean array to mark the presence of positive numbers
    present = [False] * (n + 1)
    
    # Mark the presence of positive numbers in the array
    for num in pos_nums:
        if 1 <= num <= n:
            present[num] = True

    # Find the smallest positive integer that is not in the array
    for i in range(1, n + 2):
        if not present[i]:
            return i

    return 1

# Example usage:
arr1 = [4, 7, -1, 1, 2]
print("Example 1:", find_smallest_positive(arr1))

arr2 = [100, 101, 102]
print("Example 2:", find_smallest_positive(arr2))

arr3 = [3, 2, 1, 0, -1]
print("Example 3:", find_smallest_positive(arr3))
