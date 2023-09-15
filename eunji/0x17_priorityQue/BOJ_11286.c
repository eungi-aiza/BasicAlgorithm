#include <stdio.h>

int heap[100005];
int sz = 0; // heap size

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int abs(int a) {
    if (a > 0) return a;
    return a * -1;
}

int compare(int a, int b) {
    // a가 target인지 여부를 판단하는 함수 1이면 True임
    // 최소힙
//    if (a < b) return 1;
//    return 0;
    if (abs(a)==abs(b) && a < b) return 1;
    else if (abs(a)!=abs(b) && (abs(a)<abs(b))) return 1;
    return 0;
}

void push(int x) {
    heap[++sz] = x; // heap의 가장 마지막에 x 삽입
    int idx = sz; // 그 자리에서 시작. 부모로 올라가면서 바꿔주기
    while (idx != 1) { // 루트까지 올라가!
        int parent = idx / 2;
        // if (heap[parent] <= heap[idx]) break; // 최소힙이기 때문에 부모가 더 작으면 멈춘다
        if (compare(heap[parent], heap[idx])) break; // 일반화된 버전
        swap(&heap[parent], &heap[idx]); // 부모가 더 크면 바꾼다
        idx = parent; // 부모 자리로 올라간다
    }
}

int top() {
    return heap[1];
}

void pop() {
    heap[1] = heap[sz--]; // 제일 위로 올리고 사이즈를 줄인다
    int idx = 1;
    while (2 * idx <= sz) { // 밑으로 계속 내려간다. 자식 하나라도! 있으면 내려간다.
        int left = 2 * idx;
        int right = 2 * idx + 1;
//        int min_child = left;
//        if (right <= sz && heap[right] < heap[left]) // 오른쪽 자식이 있고 더 작으면
//            min_child = right;
//        if (heap[idx] <= heap[min_child]) break; // 안 바꿔도 되면 그만한다
        int select_child = left;
        if (right <= sz && compare(heap[right], heap[left]))
            select_child = right;
        if (compare(heap[idx], heap[select_child])) break; // 안 바꿔도 되면 그만한다
        swap(&heap[idx], &heap[select_child]);
        idx = select_child;
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; ++i) {
        int num;
        scanf("%d", &num);
        if (num == 0) {
            if (sz == 0) {
                printf("0\n");
            } else {
                printf("%d\n", top());
                pop();
            }
        } else {
            push(num);
        }
    }
    return 0;
}