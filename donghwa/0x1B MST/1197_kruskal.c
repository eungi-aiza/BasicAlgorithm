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

#define MAX_NODES 10005
#define MAX_EDGES 100005

int parent[MAX_NODES];
typedef struct {
    int weight;
    int u, v;
} Edge;

Edge edges[MAX_EDGES];

int compare(const void* a, const void* b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

int find(int x) {
    if(parent[x] < 0) return x;
    return parent[x] = find(parent[x]);
}

bool is_diff_group(int u, int v) {
    u = find(u); 
    v = find(v);
    
    if(u == v) return false;
    if(parent[u] == parent[v]) parent[u]--;
    if(parent[u] < parent[v]) parent[v] = u;
    else parent[u] = v;
    return true;
}

int main(void) {
    int v, e;
    scanf("%d %d", &v, &e);

    for(int i = 0; i < MAX_NODES; i++) {
        parent[i] = -1;
    }

    for(int i = 0; i < e; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    qsort(edges, e, sizeof(Edge), compare);

    int cnt = 0;
    int ans = 0;
    for(int i = 0; i < e; i++) {
        if(!is_diff_group(edges[i].u, edges[i].v)) continue;
        ans += edges[i].weight;
        cnt++;
        if(cnt == v-1) break;    
    }

    printf("%d\n", ans);
    return 0;
}