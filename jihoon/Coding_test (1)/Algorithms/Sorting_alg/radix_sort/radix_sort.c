#include <stdio.h>
#include <stdlib.h>

// Utility function to get the maximum value in the array
int getMax(int arr[], int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

// Counting sort based on significant position
void countingSort(int arr[], int n, int position) {
    int output[n];
    int count[10] = {0};

    // Calculate the count of occurrences
    for (int i = 0; i < n; i++)
        count[(arr[i] / position) % 10]++;

    // Adjust the count array
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array using stable counting sort
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / position) % 10] - 1] = arr[i];
        count[(arr[i] / position) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Radix Sort
void radixSort(int arr[], int n) {
    int max = getMax(arr, n);

    // Apply counting sort for every digit
    for (int position = 1; max / position > 0; position *= 10)
        countingSort(arr, n, position);
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    radixSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}