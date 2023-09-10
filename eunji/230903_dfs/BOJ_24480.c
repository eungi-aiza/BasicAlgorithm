#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int deg[100002];
int* adj[100002];
int idx[100002];
int vis[100002] = {};


void dfs(
    int* adj[100002],
    int start,
    int* curr,
    int* vis
){
    vis[start] = *curr;
    (*curr) ++;

    for (int i=0; i<idx[start]; i++){
        int nei = adj[start][i];
        if (vis[nei] == 0){
            dfs(adj, nei, curr, vis);
        }
    }
}

void printGraph(int v){
    for (int i = 1; i <= v; i++) {
        printf("Adjacency list of vertex %d: ", i);
        for (int j = 0; j < idx[i]; j++) {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
}

int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main(){
    int N, M, R;
    scanf("%d %d %d", &N, &M, &R);
    for(int i = 0 ; i < M; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        idx[a]++; idx[b]++;
        adj[a] = (int*)realloc(adj[a], idx[a]*sizeof(int)); // realloc 주의
        adj[b] = (int*)realloc(adj[b], idx[b]*sizeof(int));
        adj[a][idx[a]-1] = b;
        adj[b][idx[b]-1] = a;
    }

    for (int i = 1; i <= N; i++) {
        int n = idx[i]; 
        qsort(adj[i], n, sizeof(adj[i][0]), compare);
    }

    int curr = 1;
    dfs(adj, R, &curr, vis);

    for (int i = 1; i <= N; i++) {
        free(adj[i]);
    }
    for (int i=1; i<=N; i++){
        printf("%d\n", vis[i]);
    }

    return 0;

}


