#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 100

struct GNode {
    char id[10];
    char color; // 'W', 'B'
    int d;
    int f;
    struct GNode* parent;
};

struct GNode* createNode(const char* id) {
    struct GNode* node = (struct GNode*)malloc(sizeof(struct GNode));
    strcpy(node->id, id);
    node->color = 'W';
    node->d = -1;
    node->f = -1;
    node->parent = NULL;
    return node;
}

struct GNode* stack[MAX_NODES];
int top = -1;

void push(struct GNode* node) {
    stack[++top] = node;
}

struct GNode* pop() {
    return stack[top--];
}

int isEmpty() {
    return top == -1;
}

struct GNode* graph[MAX_NODES];
int graphSize = 0;

void addEdge(struct GNode* u, struct GNode* v) {
    u->color = 'W';
    v->color = 'W';
    
    if (u->d > v->d) {
        u->parent = v;
    } else {
        v->parent = u;
    }
}

void DFS(struct GNode* u, struct GNode* v, char** path, char** result, int* resultSize) {
    u->color = 'B';
    strcpy(path[u->d], u->id);

    if (u == v) {
        if (*resultSize == 0 || strcmp(path[u->d], result[0]) < 0) {
            for (int i = 0; i <= u->d; i++) {
                strcpy(result[i], path[i]);
            }
            *resultSize = u->d + 1;
        }
    } else {
        for (int i = 0; i < graphSize; i++) {
            struct GNode* neighbor = graph[i];
            if (neighbor->color == 'W') {
                addEdge(u, neighbor);
                DFS(neighbor, v, path, result, resultSize);
            }
        }
    }

    u->color = 'W';
    u->d = -1;
    u->f = -1;
    u->parent = NULL;
}

char** LexSmallest(struct GNode* u, struct GNode* v, int* resultSize) {
    char** path = (char**)malloc(MAX_NODES * sizeof(char*));
    for (int i = 0; i < MAX_NODES; i++) {
        path[i] = (char*)malloc(10 * sizeof(char));
    }

    char** result = (char**)malloc(MAX_NODES * sizeof(char*));
    for (int i = 0; i < MAX_NODES; i++) {
        result[i] = (char*)malloc(10 * sizeof(char));
    }

    *resultSize = 0;
    DFS(u, v, path, result, resultSize);

    return result;
}

int main() {
    struct GNode* r = createNode("r");
    struct GNode* s = createNode("s");
    struct GNode* t = createNode("t");
    struct GNode* u = createNode("u");
    struct GNode* v = createNode("v");
    struct GNode* w = createNode("w");
    struct GNode* x = createNode("x");
    struct GNode* y = createNode("y");

    graph[graphSize++] = r;
    graph[graphSize++] = s;
    graph[graphSize++] = t;
    graph[graphSize++] = u;
    graph[graphSize++] = v;
    graph[graphSize++] = w;
    graph[graphSize++] = x;
    graph[graphSize++] = y;

    addEdge(r, w);
    addEdge(r, v);
    addEdge(s, w);
    addEdge(s, t);
    addEdge(s, x);
    addEdge(t, x);
    addEdge(t, w);
    addEdge(u, y);
    addEdge(v, r);
    addEdge(w, r);
    addEdge(w, s);
    addEdge(w, t);
    addEdge(x, t);
    addEdge(x, s);
    addEdge(y, u);

    int resultSize;
    char** path = LexSmallest(t, v, &resultSize);

    if (resultSize > 0) {
        printf("Lexicographically Smallest Path:\n");
        for (int i = 0; i < resultSize; i++) {
            printf("%s ", path[i]);
        }
        printf("\n");
    } else {
        printf("No path found.\n");
    }

    for (int i = 0; i < MAX_NODES; i++) {
        free(path[i]);
        free(result[i]);
    }
    free(path);
    free(result);

    return 0;
}
