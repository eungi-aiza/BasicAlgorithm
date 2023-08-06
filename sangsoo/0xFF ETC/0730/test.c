#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void dfs(int st, int en, int** graph, int graphSize, int* graphColSize, int* returnSize, int* returnColumnSizes, int* currentPath, int currentPathSize, int** paths);


int** allPathsSourceTarget(int** graph, int graphSize, int* graphColSize, int* returnSize, int** returnColumnSizes) {
    int maxPaths = pow(2, graphSize); // path의 최대 개수 각노드로부터 시작하는 path가 있냐 없냐.
    int currentPathSize = 0;
    int* currentPath = malloc(sizeof(int)*graphSize);
    int** paths = malloc(sizeof(int*)*maxPaths);
    int* returnColSizes = malloc(sizeof(int)*maxPaths);
    *returnSize = 0;
    dfs(0, graphSize-1, graph, graphSize, graphColSize, returnSize, returnColSizes, currentPath, currentPathSize, paths);

    paths = realloc(paths, sizeof(int*)*(*returnSize));
    returnColSizes = realloc(returnColSizes, sizeof(int)*(*returnSize));
    *returnColumnSizes = returnColSizes;

    return paths;

}

void dfs(int st, int en, int **graph, int graphSize, int *graphColSize, int *returnSize, int *returnColumnSizes, int *currentPath, int currentPathSize, int **paths){
    currentPath[currentPathSize] = st;
    currentPathSize++;
    if(st == en){
        paths[*returnSize] = malloc(sizeof(int)*currentPathSize);
        memcpy(paths[*returnSize], currentPath, sizeof(int)*currentPathSize);
        returnColumnSizes[*returnSize] = currentPathSize;
        *returnSize += 1;
        return;
    }
    int i;
    int nextNode;

    for(i = 0; i < graphColSize[st]; i++){
        nextNode = graph[st][i];
        dfs(nextNode, en, graph, graphSize, graphColSize, returnSize, returnColumnSizes, currentPath, currentPathSize, paths);
    }

}