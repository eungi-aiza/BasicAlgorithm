#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char edge[10][2];
int deg[10];
int* adj[10];
int idx[10];
char* ans[100];
int ans_num;
int vis[10];

void printGraph(int v) {
    for (int i = 1; i <= v; i++) {
        printf("Adjacency list of vertex %c: ", 'a' + i - 1);
        for (int j = 0; j < idx[i]; j++) {
            printf("%c ", 'a' + adj[i][j] - 1);
        }
        printf("\n");
    }
}

void dfs(int** adj, char st, char ed, char* path, int pathLen) {
    path[pathLen] = st;
    pathLen++;

    if (st == ed) {
        char* newPath = (char*)malloc(pathLen * sizeof(char));
        memcpy(newPath, path, pathLen * sizeof(char));
        newPath[pathLen - 1] = '\0'; // Null-terminate the path
        ans[ans_num] = newPath;
        ans_num ++;
        return;
    }

    for (int i = 0; i < idx[st - 'a' + 1]; i++) {
        char next = adj[st - 'a' + 1][i] + 'a' - 1;
        if (vis[adj[st - 'a' + 1][i]] == 0){
            vis[adj[st - 'a' + 1][i]] = 1;
            dfs(adj, next, ed, path, pathLen);
            vis[adj[st - 'a' + 1][i]] = 0;
        }        
        // if (strchr(path, next) == NULL) {
        //     dfs(adj, next, ed, path, pathLen);
        // }
    }

    pathLen--;
}

char** paths(int** adj, char st, char ed) {
    char path[100]; // Temporary array to store the current path
    dfs(adj, st, ed, path, 0);
    return ans;
}

int main() {
    int v, e;
    v = 4;
    e = 4;

    edge[0][0] = 'a'; edge[0][1] = 'b';
    deg[edge[0][0] - 'a' + 1]++;
    edge[1][0] = 'a'; edge[1][1] = 'c';
    deg[edge[1][0] - 'a' + 1]++;
    edge[2][0] = 'b'; edge[2][1] = 'd';
    deg[edge[2][0] - 'a' + 1]++;
    edge[3][0] = 'd'; edge[3][1] = 'c';
    deg[edge[3][0] - 'a' + 1]++;

    for (int i = 1; i <= v; i++) {
        adj[i] = (int*)malloc(deg[i] * sizeof(int));
    }
    for (int i = 0; i < e; i++) {
        int u = edge[i][0] - 'a' + 1;
        int v = edge[i][1] - 'a' + 1;
        adj[u][idx[u]] = v;
        idx[u]++;
    }

    printGraph(v);

    vis[0] = 1;
    char** ans_print = paths(adj, 'a', 'c');

    // Print all paths
    for (int i = 0; ans_print[i] != NULL; i++) {
        printf("Path %d: %sc\n", i + 1, ans_print[i]);
        // printf("%c", 'c');
        free(ans_print[i]); // Free memory used for paths
    }

    for (int i = 1; i <= v; i++) {
        free(adj[i]);
    }
    
    return 0;
}
