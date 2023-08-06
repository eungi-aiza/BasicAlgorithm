/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void dfs(int start, int end, int **graph, int graphSize, int *graphColSize, int *returnSize, int *returnColumnSizes, int *currentPath, int currentPathSize, int **paths);

int** allPathsSourceTarget(int** graph, int graphSize, int* graphColSize, int* returnSize, int** returnColumnSizes)
{
    int maxPaths = pow(2, graphSize);
    int currentPathSize = 0;
    int *currentPath = malloc(sizeof(int) * graphSize);
    int **paths = malloc(sizeof(int *) * maxPaths);
    int *returnColSizes = malloc(sizeof(int) * maxPaths);
    *returnSize = 0;

    dfs(0, graphSize-1, graph, graphSize, graphColSize, returnSize, returnColSizes, currentPath, currentPathSize, paths);

    paths = realloc(paths, sizeof(int *) * (*returnSize));
    returnColSizes = realloc(returnColSizes, sizeof(int) * (*returnSize));

    *returnColumnSizes = returnColSizes;

    return paths;
}

void dfs(int start, int end, int **graph, int graphSize, int *graphColSize, int *returnSize, int *returnColumnSizes, int *currentPath, int currentPathSize, int **paths)
{
    currentPath[currentPathSize] = start;
    currentPathSize += 1;

    if(start == end)
    {
        paths[*returnSize] = malloc(sizeof(int) * currentPathSize);
        memcpy(paths[*returnSize], currentPath, sizeof(int) * currentPathSize);
        returnColumnSizes[*returnSize] = currentPathSize;
        *returnSize += 1;
        return;
    }

    int i;
    int nextNode;

    for(i = 0; i < graphColSize[start]; i++)
    {
        nextNode = graph[start][i];
        dfs(nextNode, end, graph, graphSize, graphColSize, returnSize, returnColumnSizes, currentPath, currentPathSize, paths);
    }
}
int main() {
    // Test case 1
    int graph1Size = 4;
    int graph1ColSizes[] = {2, 1, 1, 0};
    int* graph1[] = {(int[]){1, 2}, (int[]){3}, (int[]){3}, (int[]){}};
    int returnSize;
    int* returnColSizes;
    int** result1 = allPathsSourceTarget(graph1, graph1Size, graph1ColSizes, &returnSize, &returnColSizes);
    printf("Test case 1:\n");
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColSizes[i]; j++) {
            printf("%d ", result1[i][j]);
        }
        printf("\n");
        free(result1[i]);  // free each sub-array
    }
    free(result1);  // free main array
    free(returnColSizes);  // free column sizes array
    printf("\n");

    // Test case 2
    int graph2Size = 5;
    int graph2ColSizes[] = {3, 3, 1, 1, 0};
    int* graph2[] = {(int[]){4, 3, 1}, (int[]){3, 2, 4}, (int[]){3}, (int[]){4}, (int[]){}};
    int** result2 = allPathsSourceTarget(graph2, graph2Size, graph2ColSizes, &returnSize, &returnColSizes);
    printf("Test case 2:\n");
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColSizes[i]; j++) {
            printf("%d ", result2[i][j]);
        }
        printf("\n");
        free(result2[i]);  // free each sub-array
    }
    free(result2);  // free main array
    free(returnColSizes);  // free column sizes array
    printf("\n");

    // Remember to free the dynamically allocated memory after usage.

    return 0;
}
