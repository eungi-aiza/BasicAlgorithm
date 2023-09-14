#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

void backtracking(int* nums, int numsSize, int* returnSize, int** returnColumnSizes,
                  int* vis, int* ans, int curr, int*** answers){
    if (curr == numsSize){
        (*returnSize)++;
        (*answers) = realloc(*answers, (*returnSize) * sizeof(int*));
        (*answers)[(*returnSize)-1] = malloc(numsSize * sizeof(int));
        memcpy((*answers)[(*returnSize)-1], ans, numsSize * sizeof(int));
        (*returnColumnSizes)[(*returnSize)-1] = numsSize;
        return;
    }

    for (int i=0; i<numsSize; i++){
        if (vis[i] == 0){
            vis[i] = 1;
            ans[curr] = nums[i];
            backtracking(nums, numsSize, returnSize, returnColumnSizes, vis, ans, curr+1, answers);
            vis[i] = 0;
        }
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int* vis = calloc(numsSize, sizeof(int));
    int* ans = malloc(numsSize * sizeof(int));
    int** answers = NULL;
    *returnSize = 0;
    
    // Calculate factorial to determine maximum possible permutations
    int fact = 1;
    for(int i=1; i <= numsSize; i++) {
        fact *= i;
    }
    *returnColumnSizes = malloc(fact * sizeof(int));  // Allocate for maximum possible permutations

    backtracking(nums, numsSize, returnSize, returnColumnSizes, vis, ans, 0, &answers);
    free(ans);
    free(vis);
    return answers;
}


int main(){
    int numsSize = 3;
    int nums[3] = {1,2,3};
    int returnSize;
    int* returnColumnSizes = NULL;
    int** result = permute(nums, numsSize, &returnSize, &returnColumnSizes);
    
    for (int i = 0; i < returnSize; i++){
        for (int j = 0; j < returnColumnSizes[i]; j++){
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    free(result);
    free(returnColumnSizes);
    return 0;
}