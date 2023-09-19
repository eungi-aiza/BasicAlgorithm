#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int first;
    int second;
} Pair;

bool compare_pairs(const Pair p1, const Pair p2) {
    if (p1.second < p2.second) {
        return true;
    } else if (p1.second == p2.second) {
        return p1.first < p2.first;
    } else {
        return false;
    }
}

void merge(Pair* v, int first, int mid, int last) {
    int i = first, j = mid + 1, k = 0;
    Pair temp[last - first + 1];

    while (i <= mid && j <= last) {
        if (compare_pairs(v[i], v[j])) {
            temp[k++] = v[i++];
        } else {
            temp[k++] = v[j++];
        }
    }
    
    while (i <= mid) {
        temp[k++] = v[i++];
    }
    
    while (j <= last) {
        temp[k++] = v[j++];
    }
    
    for (i = first, k = 0; i <= last; ++i, ++k) {
        v[i] = temp[k];
    }
}

void mergeSortHelper(Pair* v, int first, int last) {
    if (first < last) {
        int mid = first + (last - first) / 2;
        mergeSortHelper(v, first, mid);
        mergeSortHelper(v, mid + 1, last);
        merge(v, first, mid, last);
    }
}

void mergeSort(Pair* v, int size) {
    mergeSortHelper(v, 0, size - 1);
}

int main() {
    Pair a[] = {{2, 3}, {1, 3}, {1, 2}, {4, 2}, {5, 6}, {3, 6}};
    int size = sizeof(a) / sizeof(a[0]);
    
    mergeSort(a, size);

    for (int i = 0; i < size; i++) {
        printf("(%d, %d) ", a[i].first, a[i].second);
    }
    printf("\n");

    return 0;
}