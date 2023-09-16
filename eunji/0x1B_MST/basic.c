#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define V 5 // 그래프의 정점 수

// 주어진 키 배열(key) 중에서 최솟값을 가지는 정점을 찾는 함수
int minKey(int key[], bool mstSet[]) {
    int min = INT_MAX, min_index;
    for (int v = 0; v < V; v++) {
        if (!mstSet[v] && key[v] < min) {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// 최소 신장 트리(MST)를 출력하는 함수
void printMST(int parent[], int graph[V][V]) {
    printf("Edge \tWeight\n");
    for (int i = 1; i < V; i++) {
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}

// 프림 알고리즘을 이용하여 최소 신장 트리(MST)를 찾는 함수
void primMST(int graph[V][V]) {
    int parent[V]; // MST에서 각 정점의 부모 정점
    int key[V];    // MST에 속한 정점과 아직 속하지 않은 정점 사이의 가중치
    bool mstSet[V]; // MST에 이미 포함된 정점

    // 모든 정점의 키 값을 무한대(INF)로 초기화, MST 집합에는 아무 정점도 포함되지 않음을 표시
    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;     // 시작 정점의 키 값을 0으로 설정
    parent[0] = -1; // 시작 정점은 부모 정점이 없음을 나타냄

    // MST에 V-1개의 간선이 선택될 때까지 반복
    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet); // 키 배열 중에서 최솟값을 가지는 정점 u를 찾음
        mstSet[u] = true; // 정점 u를 MST 집합에 포함시킴

        // 정점 u와 아직 MST에 포함되지 않은 정점들과의 간선을 검사하여 키 값을 업데이트
        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v]) {
                parent[v] = u; // 정점 v의 부모를 u로 설정
                key[v] = graph[u][v]; // 키 값을 업데이트
            }
        }
    }

    printMST(parent, graph); 
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph);

    return 0;
}
