#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100

struct GNode {
    char id[10];
};

struct GNode* createNode(const char* id) {
    struct GNode* node = (struct GNode*)malloc(sizeof(struct GNode));
    strcpy(node->id, id);
    return node;
}

void freeNode(struct GNode* node) {
    free(node);
}

void dfs(struct GNode* G[MAX_NODES], int adjacencyList[MAX_NODES][MAX_NODES], int numberOfNodes, int* visited, struct GNode** path, int* pathSize, struct GNode* node, struct GNode* c) {
    visited[node->id[0] - 'a'] = 1;
    path[(*pathSize)++] = node;

    if (node == c) {
        printf("Path: ");
        for (int i = 0; i < *pathSize; i++) {
            printf("%s -> ", path[i]->id);
        }
        printf("end\n");
    } else {
        for (int i = 0; i < numberOfNodes; i++) {
            struct GNode* neighbor = G[i];
            if (!visited[neighbor->id[0] - 'a'] && adjacencyList[node->id[0] - 'a'][i]) {
                dfs(G, adjacencyList, numberOfNodes, visited, path, pathSize, neighbor, c);
            }
        }
    }

    visited[node->id[0] - 'a'] = 0;
    (*pathSize)--;
}

int main() {
    struct GNode* a = createNode("a");
    struct GNode* b = createNode("b");
    struct GNode* c = createNode("c");
    struct GNode* d = createNode("d");

    int numberOfNodes = 4;
    struct GNode* G[MAX_NODES] = {a, b, c, d};
    int adjacencyList[MAX_NODES][MAX_NODES] = {
        {0, 1, 1, 0},
        {0, 0, 0, 1},
        {0, 0, 0, 0},
        {0, 0, 1, 0}
    };

    int* visited = (int*)calloc(numberOfNodes, sizeof(int));
    struct GNode* path[MAX_NODES];
    int pathSize = 0;

    dfs(G, adjacencyList, numberOfNodes, visited, path, &pathSize, a, c);

    for (int i = 0; i < numberOfNodes; i++) {
        freeNode(G[i]);
    }

    free(visited);

    return 0;
}
