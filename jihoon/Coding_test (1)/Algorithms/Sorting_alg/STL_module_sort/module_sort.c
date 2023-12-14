#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Comparator functions
int ascending(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int descending(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int byLength(const void *a, const void *b) {
    return (strlen(*(char **)a) - strlen(*(char **)b));
}

// Comparator function for sorting pairs by the second element
int bySecondElement(const void *a, const void *b) {
    return ((const int *)a)[1] - ((const int *)b)[1];
}

// Comparator function for sorting pairs by the second element, then by the first element in descending order
int bySecondThenFirstDesc(const void *a, const void *b) {
    int diff = ((const int *)a)[1] - ((const int *)b)[1];
    if (diff == 0) {
        return ((const int *)b)[0] - ((const int *)a)[0];
    }
    return diff;
}

// Examples
void example1() {
    int arr[] = {5, 3, 8, 1, 2, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    qsort(arr, n, sizeof(int), ascending);
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

void example2() {
    int arr[] = {5, 3, 8, 1, 2, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    qsort(arr, n, sizeof(int), descending);
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

void example3() {
    char *words[] = {"apple", "banana", "kiwi", "grapes"};
    int n = sizeof(words) / sizeof(words[0]);
    qsort(words, n, sizeof(char *), byLength);
    for (int i = 0; i < n; i++) printf("%s ", words[i]);
    printf("\n");
}



// Example 4
void example4() {
    int pairs[][2] = {{1, 3}, {2, 2}, {3, 1}};
    int n = sizeof(pairs) / sizeof(pairs[0]);
    qsort(pairs, n, sizeof(pairs[0]), bySecondElement);
    for (int i = 0; i < n; i++) {
        printf("(%d, %d) ", pairs[i][0], pairs[i][1]);
    }
    printf("\n");
}

// Example 5
void example5() {
    int arr[] = {5, 3, 8, 1, 2, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    qsort(arr, n, sizeof(int), ascending);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Example 6
void example6() {
    int pairs[][2] = {{5, 3}, {2, 3}, {7, 3}, {3, 1}, {4, 2}, {1, 2}};
    int n = sizeof(pairs) / sizeof(pairs[0]);
    qsort(pairs, n, sizeof(pairs[0]), bySecondThenFirstDesc);
    for (int i = 0; i < n; i++) {
        printf("(%d, %d) ", pairs[i][0], pairs[i][1]);
    }
    printf("\n");
}

int main() {
    printf("Example 1:\n");
    example1();
    
    printf("Example 2:\n");
    example2();
    
    printf("Example 3:\n");
    example3();
    
    printf("Example 4:\n");
    example4();
    
    printf("Example 5:\n");
    example5();
    
    printf("Example 6:\n");
    example6();

    return 0;
}