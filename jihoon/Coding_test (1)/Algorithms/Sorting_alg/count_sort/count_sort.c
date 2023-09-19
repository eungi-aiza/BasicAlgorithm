#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum value in the array
int findMax(int arr[], int n) {
    int maxVal = arr[0];
    for(int i = 1; i < n; i++) {
        if(arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

void countingSort(int arr[], int n) {
    int i, j;

    // Find maximum value in the array
    int maxVal = findMax(arr, n);

    // Initialize the count array
    int* count = (int*)calloc(maxVal + 1, sizeof(int));

    // Store the frequency of each number in the count array
    for(i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Rebuild the original array using the count array
    int idx = 0;
    for(i = 0; i <= maxVal; i++) {
        for(j = 0; j < count[i]; j++) {
            arr[idx++] = i;
        }
    }

    free(count);
}

int main() {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    countingSort(arr, n);

    printf("Sorted array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}