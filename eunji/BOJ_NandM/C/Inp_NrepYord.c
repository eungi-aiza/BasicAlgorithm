#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// #define INF INT_MAX
// #define INF (0x3f3f3f3f)

int ans[10];
int input[10];
int vis[10];

int ascending(const void *a, const void *b) {
    int num1 = *(int *)a;
    int num2 = *(int *)b;
    if (num1 < num2) return -1;
    if (num1 > num2) return 1;
    return 0;
}

void backtracking(int N, int M, int curr){
    if (curr == M){
        for (int i=0; i<M; i++){
            printf("%d ", ans[i]);
        }
        printf("\n");
        return;
    }
    for (int i=0; i<N; i++){
        int temp = input[i];
        if (vis[i] == 0){
            vis[i] = 1;
            ans[curr] = temp;
            backtracking(N, M, curr+1);
            vis[i] = 0;
        }
    }
}

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    for (int i=0; i<N; i++){
        scanf("%d", &input[i]);
    }
    qsort(input, N, sizeof(int), ascending);
    backtracking(N, M, 0); 
    return 0;
}