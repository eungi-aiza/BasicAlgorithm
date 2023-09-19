/* 1197. 최소 스패닝 트리

그래프가 주어졌을 때, 그 그래프의 최소 스패닝 트리를 구하는 프로그램을 작성하시오.
최소 스패닝 트리는, 주어진 그래프의 모든 정점들을 연결하는 부분 그래프 중에서 그 가중치의 합이 최소인 트리를 말한다.
- 입력 :
첫째 줄에 정점의 개수 V(1 ≤ V ≤ 10,000)와 간선의 개수 E(1 ≤ E ≤ 100,000)가 주어진다. 다음 E개의 줄에는 각 간선에 대한 정보를 나타내는 세 정수 A, B, C가 주어진다. 
이는 A번 정점과 B번 정점이 가중치 C인 간선으로 연결되어 있다는 의미이다. 
C는 음수일 수도 있으며, 절댓값이 1,000,000을 넘지 않는다.
그래프의 정점은 1번부터 V번까지 번호가 매겨져 있고, 임의의 두 정점 사이에 경로가 있다. 
최소 스패닝 트리의 가중치가 -2,147,483,648보다 크거나 같고, 2,147,483,647보다 작거나 같은 데이터만 입력으로 주어진다.

- 출력 :
첫째 줄에 최소 스패닝 트리의 가중치를 출력한다.

ex1. 
- 입력 :
3 3
1 2 1
2 3 2
1 3 3
- 출력 :
3
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_NODES 100005

typedef struct {
    int weight;
    int v;
    struct Node* next;
} Node;

typedef struct {
    int weight;
    int u, v;
} Edge;

typedef struct {
    Edge data[MAX_NODES];
    int size;
} PriorityQueue;

Node* adj[MAX_NODES];
bool chk[MAX_NODES];
PriorityQueue pq;

void addEdge(int u, int v, int w) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->weight = w;
    newNode->v = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

void push(PriorityQueue* pq, Edge e) {
    int idx = ++pq->size;
    while (idx > 1 && pq->data[idx/2].weight > e.weight) {
        pq->data[idx] = pq->data[idx/2];
        idx /= 2;
    }
    pq->data[idx] = e;
}

Edge pop(PriorityQueue* pq) {
    int parent, child;
    Edge item, temp;

    item = pq->data[1];
    temp = pq->data[pq->size--];

    parent = 1;
    child = 2;

    while (child <= pq->size) {
        if (child < pq->size && pq->data[child].weight > pq->data[child+1].weight) {
            child++;
        }
        if (temp.weight <= pq->data[child].weight) break;

        pq->data[parent] = pq->data[child];
        parent = child;
        child *= 2;
    }

    pq->data[parent] = temp;
    return item;
}

int main(void) {
    int v, e;
    scanf("%d %d", &v, &e);

    for (int i = 0; i < e; i++) {
        int a, b, cost;
        scanf("%d %d %d", &a, &b, &cost);

        addEdge(a, b, cost);
        addEdge(b, a, cost);
    }

    chk[1] = true;
    int cnt = 0;
    int ans = 0;

    for (Node* node = adj[1]; node != NULL; node = node->next) {
        push(&pq, (Edge){node->weight, 1, node->v});
    }

    while (cnt < v - 1) {
        Edge top = pop(&pq);
        if (chk[top.v]) continue;

        ans += top.weight;
        chk[top.v] = true;
        cnt++;

        for (Node* node = adj[top.v]; node != NULL; node = node->next) {
            if (!chk[node->v]) {
                push(&pq, (Edge){node->weight, top.v, node->v});
            }
        }
    }

    printf("%d\n", ans);

    // Cleanup
    for (int i = 1; i <= v; i++) {
        Node* node = adj[i];
        while (node) {
            Node* temp = node;
            node = node->next;
            free(temp);
        }
    }
    return 0;
}