def counting_sort(arr, position):
    n = len(arr)
    output = [-1] * n
    count = [0] * 10  # Since the decimal system has 10 digits (0-9)

    # Count occurrences of each digit at current position
    for i in range(n):
        index = (arr[i] // position) % 10
        count[index] += 1

    # Change count[i] so that it contains the actual position
    # of the next occurrence of this digit in output[]
    for i in range(1, 10):
        count[i] += count[i - 1]

    # Build the output array
    i = n - 1
    while i >= 0:
        index = (arr[i] // position) % 10
        output[count[index] - 1] = arr[i]
        count[index] -= 1
        i -= 1

    # Copy the sorted elements back to the original array
    for i in range(n):
        arr[i] = output[i]

def radix_sort(arr):
    # Find the maximum number to determine the number of digits
    max_num = max(arr)
    position = 1  # We start with the least significant digit

    # For every digit in the maximum number
    while max_num // position > 0:
        # Sort numbers based on the current position
        counting_sort(arr, position)
        position *= 10  # Move to the next significant digit

    return arr

if __name__ == "__main__":
    # Testing
    arr = [170, 45, 75, 90, 802, 24, 2, 66]
    print("Original Array:", arr)
    print("Sorted Array:", radix_sort(arr))