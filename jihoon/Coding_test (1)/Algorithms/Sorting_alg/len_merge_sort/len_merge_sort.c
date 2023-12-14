#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Merging arrays based on string lengths
void merge(char* a[], int first, int mid, int last){
    int i = first, j = mid + 1, k = 0;
    int size = last - first + 1;
    char** tmp = (char**) malloc(sizeof(char*) * size);

    while (i <= mid && j <= last){
        if(strlen(a[i]) >= strlen(a[j])) {
            tmp[k++] = a[i++];
        } else {
            tmp[k++] = a[j++];
        }
    }

    while (i <= mid) {
        tmp[k++] = a[i++];
    }
    while (j <= last) {
        tmp[k++] = a[j++];
    }

    for(i = 0; i < size; i++) {
        a[first + i] = tmp[i];
    }
    free(tmp);
}

void mergeSortHelp(char* a[], int first, int last){
    if (first < last) {
        int mid = first + (last - first) / 2;
        mergeSortHelp(a, first, mid);
        mergeSortHelp(a, mid + 1, last);
        merge(a, first, mid, last);
    }
}

int main(){
    char* strings1[] = {"apple", "banana", "kiwi", "grapes", "fruit"};
    char* strings2[] = {"dog", "crocodile", "cat", "fish"};
    int size1 = sizeof(strings1) / sizeof(strings1[0]);
    int size2 = sizeof(strings2) / sizeof(strings2[0]);
    
    mergeSortHelp(strings1, 0, size1-1);
    mergeSortHelp(strings2, 0, size2-1);

    for(int i = 0; i < size1; i++){
        printf("%s ", strings1[i]);
    }
    printf("\n");
    
    for(int i = 0; i < size2; i++){
        printf("%s ", strings2[i]);
    }
    printf("\n");

    return 0;
}