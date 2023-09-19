#include <stdio.h>
#define MAX_SIZE 100002

int n;
int heap[MAX_SIZE];
int sz = 0; // heap�� ���� ������ ��

void swap(int *x, int *y){
    int z = *x;
    *x = *y;
    *y = z;
}

void push(int x){
    heap[++sz] = x;
    int idx = sz;
    while (idx != 1){
        int par = idx/2;
        if(heap[par] <= heap[idx]) break;
        swap(&heap[par], &heap[idx]);
        idx = par;
    }
}

int top(){
    return heap[1];
}

void heapify(int idx){
    int lc = 2*idx, rc = 2*idx + 1;
    int min_child = lc; // ���ڽ��� ���� index�� ��´�.
    if (rc <= sz && heap[rc] < heap[lc]) // rc �� sz���� �۰ų� ���ٴ� ����  rc�� �������� �ǹ�
        min_child = rc;
    if (heap[idx] > heap[min_child]) {
        swap(&heap[idx], &heap[min_child]);
        heapify(min_child); // Recursively heapify the affected subtree
    }
}

void pop(){
    heap[1] = heap[sz--]; // �� �������� �ִ� ���� ������.
    if (sz > 0) {
        heapify(1); // Start heapifying from the root
    }
}

int main(){
    scanf("%d", &n);
    while(n--){
        int x;
        scanf("%d", &x);
        if(x == 0){
            if (sz > 0){
                printf("%d\n", top());
                pop();
            }
            else printf("0\n");
        }
        else{
            push(x);
        }
    }
}