#include <stdio.h>
#include <stdlib.h>

void merge(int a[], int first, int mid, int last){
    int i = first, j = mid+1, k = 0;
    int size = last - first + 1;
    int *tmp = (int*) malloc(sizeof(int) * size);

    while (i <= mid && j <= last){
        if(a[i] <= a[j])
            tmp[k++] = a[i++];
        else
            tmp[k++] = a[j++];
    } 
    while (i <= mid) tmp[k++] = a[i++];
    while (j <= last) tmp[k++] = a[j++];

    // Copy tmp array back to a
    for(i = 0; i < size; i++) {
        a[first + i] = tmp[i];
    }
    free(tmp);
}

void mergeSortHelp(int a[], int first, int last){
    if (first < last) {
        int mid = first + (last - first) / 2;
        mergeSortHelp(a, first, mid);
        mergeSortHelp(a, mid + 1, last);
        merge(a, first, mid, last);
    }
}

// void mergeSort(int a[], int size){
//     mergeSortHelp(a, 0, size - 1);
// }

int main(){
    int a[]= {1, 3, 2, 4, 5, 6, 7, 8};
    int b[]  = {5, 3, 2, 1, 4, 0, 6, 7};
    int size_a = sizeof(a)/sizeof(int);
    int size_b = sizeof(b)/sizeof(int);
    // mergeSort(a, size_a);
    // mergeSort(b, size_b);
    mergeSortHelp(a, 0, size_a-1);
    mergeSortHelp(b, 0, size_b-1);
    for(int i = 0; i < size_a; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    for (int i = 0; i < size_b; i++){
        printf("%d ", b[i]);
    }
    printf("\n");
}