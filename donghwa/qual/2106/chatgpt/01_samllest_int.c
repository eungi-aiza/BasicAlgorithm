#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int findSmallestPositive(int arr[], int size) {
    // Create an auxiliary boolean array to mark the presence of numbers
    bool* present = (bool*)calloc(size + 1, sizeof(bool));
    
    // Mark the presence of positive numbers in the array
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0 && arr[i] <= size) {
            present[arr[i]] = true;
        }
    }

    // Find the smallest positive integer that is not in the array
    for (int i = 1; i <= size; i++) {
        if (!present[i]) {
            free(present);
            return i;
        }
    }

    free(present);
    return size + 1; // If all positive integers from 1 to size are in the array
}

int main() {
    int arr1[] = {4, 7, -1, 1, 2};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    printf("Example 1: %d\n", findSmallestPositive(arr1, size1));

    int arr2[] = {100, 101, 102};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    printf("Example 2: %d\n", findSmallestPositive(arr2, size2));

    int arr3[] = {3, 2, 1, 0, -1};
    int size3 = sizeof(arr3) / sizeof(arr3[0]);
    printf("Example 3: %d\n", findSmallestPositive(arr3, size3));

    return 0;
}
