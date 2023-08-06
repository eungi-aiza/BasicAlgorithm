#include <stdio.h>
#include <stdlib.h>
/**
 *  Input: graph = [[1,2],[3],[3],[]]
    Output: [[0,1,3],[0,2,3]]
    Explanation: There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 **/
void backtracking(
    int** graph, 
    int* graphColSize, 
    int* returnSize, 
    int** returnColumnSizes,    
    int start,
    int end, 
    int* isused,
    int* arr,
    int** result,
    int arrLen){

    // printf("f");
    arrLen ++;
    // printf("%d\n", graphColSize[start]);
    if (start == end){
        result[*returnSize] = (int*)malloc(arrLen * sizeof(int));
        for (int i = 0; i < arrLen ; i++) {
            result[*returnSize][i] = arr[i];
        }
        (*returnColumnSizes)[*returnSize] = arrLen;
        (*returnSize) ++;
        return; 
    }

    for(int i=0; i<graphColSize[start]; i++){
        int curr = graph[start][i];
        if (!isused[curr]){
            // (*returnColumnSizes)[*returnSize]++; // Increment the size of the current path
            arr[arrLen] = curr;
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
                result,
                arrLen
                );

            isused[curr] = 0;
        
        }
    }
    arrLen --;

}

int** allPathsSourceTarget(
    int** graph, 
    int graphSize, 
    int* graphColSize, 
    int* returnSize, 
    int** returnColumnSizes){

    int* isused = (int*) malloc(graphSize * sizeof(int)); // 0으로 채워짐
    int** result = (int**)malloc(graphSize * sizeof(int*));  
    *returnSize = 0;
    
    // Allocate and initialize returnColumnSizes
    // *returnColumnSizes = (int*)malloc(1 * sizeof(int));
    // (*returnColumnSizes)[0] = 1;

    int* arr = (int*)malloc(graphSize* sizeof(int)); // 
    arr[0] = 0; // 
    isused[0] = 1 ; // 0으로 채워짐
    backtracking(
        graph, 
        graphColSize, 
        returnSize, 
        returnColumnSizes,
        0,
        graphSize-1, 
        isused, 
        arr,
        result,
        0
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
