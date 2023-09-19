#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int* data;
    size_t size;
    size_t capacity;
} Vector;

void initialize(Vector* vec, size_t capacity) {
    vec->size = 0;
    vec->capacity = capacity;
    vec->data = (int*)malloc(sizeof(int) * vec->capacity);
}

void push_back(Vector* vec, int value) {
    if (vec->size == vec->capacity) {
        vec->capacity *= 2;
        vec->data = (int*)realloc(vec->data, sizeof(int) * vec->capacity);
    }
    vec->data[vec->size++] = value;
}

void push_front(Vector* vec, int value) {
    if (vec->size == vec->capacity) {
        vec->capacity *= 2;
        vec->data = (int*)realloc(vec->data, sizeof(int) * vec->capacity);
    }
    memmove(&vec->data[1], &vec->data[0], sizeof(int) * vec->size);
    vec->data[0] = value;
    vec->size++;
}

int front(Vector* vec) {
    return vec->size > 0 ? vec->data[0] : -1;
}

int back(Vector* vec) {
    return vec->size > 0 ? vec->data[vec->size - 1] : -1;
}

int* begin(Vector* vec) {
    return &vec->data[0];
}

int* end(Vector* vec) {
    return &vec->data[vec->size];
}

int at(Vector* vec, size_t index) {
    return (index < vec->size) ? vec->data[index] : -1;
}

void resize(Vector* vec, size_t newSize) {
    vec->data = (int*)realloc(vec->data, sizeof(int) * newSize);
    if (newSize > vec->size) {
        memset(&vec->data[vec->size], 0, sizeof(int) * (newSize - vec->size));
    }
    vec->capacity = newSize;
    vec->size = newSize;
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int reverse_compare(const void* a, const void* b) {
    return (*(int*)b - *(int*)a);
}

void sort(Vector* vec, int reverse) {
    if (reverse) {
        qsort(vec->data, vec->size, sizeof(int), reverse_compare);
    } else {
        qsort(vec->data, vec->size, sizeof(int), compare);
    }
}

void print(Vector* vec) {
    for (size_t i = 0; i < vec->size; i++) {
        printf("%d ", vec->data[i]);
    }
    printf("\n");
}

void destroy(Vector* vec) {
    free(vec->data);
    vec->size = 0;
    vec->capacity = 0;
}

int main() {
    Vector vec;
    initialize(&vec, 5);
    push_back(&vec, 10);
    push_back(&vec, 20);
    push_back(&vec, 5);
    push_front(&vec, 7);

    print(&vec); // Output: 7 10 20 5

    sort(&vec, 0);
    print(&vec); // Output: 5 10 20 7

    sort(&vec, 1);
    print(&vec); // Output: 20 10 7 5

    destroy(&vec);
    return 0;
}