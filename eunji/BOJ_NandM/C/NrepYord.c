#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int ans[10];
int vis[10] = {};

void backtracking(int N, int M, int curr){
    if (curr == M){
        for (int i=0; i<M; i++){
            printf("%d ", ans[i]);
        }
        printf("\n");
        return;
    }
    for (int i=1; i<= N; i++){
        if (vis[i] == 0){
            vis[i] = 1;
            ans[curr] = i;
            backtracking(N, M, curr+1);
            vis[i] = 0;
        }
    }
}

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    backtracking(N, M, 0); 
    return 0;
}