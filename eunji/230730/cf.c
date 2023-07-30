#include <stdio.h>
#include <stdlib.h>

void backtracking(
    int** graph, 
    int* graphColSize, 
    int* returnSize, 
    int** returnColumnSizes,    
    int start,
    int end, 
    int* isused,
    int* arr,
    int** result){
    
    if (start == end){
        result[*returnSize] = (int*)malloc((*returnColumnSizes)[*returnSize] * sizeof(int));
        for (int i = 0; i < (*returnColumnSizes)[*returnSize]; i++) {
            result[*returnSize][i] = arr[i];
        }
        (*returnSize)++; // Increment returnSize after finding a path
        return; 
    }

    for(int i = 0; i < graphColSize[start]; i++){
        int curr = graph[start][i];
        if (!isused[curr]){
            (*returnColumnSizes)[*returnSize]++; // Increment the size of the current path
            arr[(*returnColumnSizes)[*returnSize] - 1] = curr;
            isused[curr] = 1;

            backtracking(
                graph, 
                graphColSize, 
                returnSize, 
                returnColumnSizes,
                curr,
                end, 
                isused,
                arr,
                result
            );
            isused[curr] = 0;
            (*returnColumnSizes)[*returnSize]--; // Decrement the size of the current path for the next iteration
        }
    }
}

int** allPathsSourceTarget(
    int** graph, 
    int graphSize, 
    int* graphColSize, 
    int* returnSize, 
    int** returnColumnSizes){

    int* isused = (int*)malloc(graphSize * sizeof(int));
    int** result = (int**)malloc(graphSize * sizeof(int*));
    *returnSize = 0; // Initialize returnSize to 0

    // Allocate and initialize returnColumnSizes
    *returnColumnSizes = (int*)malloc(graphSize * sizeof(int));
    for (int i = 0; i < graphSize; i++) {
        (*returnColumnSizes)[i] = 1; // Start with 1 since each path starts with the source node
    }

    int* arr = (int*)malloc(graphSize * sizeof(int));
    arr[0] = 0; // Starting node is always 0
    isused[0] = 1; // Mark the starting node as used

    backtracking(
        graph, 
        graphColSize, 
        returnSize, 
        returnColumnSizes,
        0,
        graphSize - 1, 
        isused, 
        arr,
        result
    );

    free(arr);
    free(isused);

    return result;
}

int main() {
    int graphSize = 4;
    int* graph[] = {
        (int[]){1, 2},
        (int[]){3},
        (int[]){3},
        (int[]){},
    };
    int graphColSize[] = {2, 1, 1, 0};

    int returnSize;
    int* returnColumnSizes;

    int** result = allPathsSourceTarget(
        graph, 
        graphSize, 
        graphColSize, 
        &returnSize, 
        &returnColumnSizes
    );

    printf("Output: \n");
    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d", result[i][j]);
            if (j != returnColumnSizes[i] - 1) {
                printf(", ");
            }
        }
        printf("]\n");
        free(result[i]);
    }

    free(result);
    free(returnColumnSizes);

    return 0;
}
