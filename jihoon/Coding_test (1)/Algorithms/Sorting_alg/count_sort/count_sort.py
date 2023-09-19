def counting_sort(arr):
    # Find the maximum value in the input array
    max_val = max(arr)
    # Create a count array of size (max_val + 1) and initialize it to zeros
    count = [0] * (max_val + 1)
    
    # Populate the count array with the count of each element in the input array
    for num in arr:
        count[num] += 1
    
    # Reconstruct the sorted output from the count array
    sorted_index = 0
    for i, freq in enumerate(count):
        for _ in range(freq):
            arr[sorted_index] = i
            sorted_index += 1

    return arr

# Testing
arr = [4, 2, 2, 8, 3, 3, 1]
print("Original Array:", arr)
print("Sorted Array:", counting_sort(arr))