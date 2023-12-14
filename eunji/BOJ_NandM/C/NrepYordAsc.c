#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

int ans[10];
int vis[10] = {};

void backtracking(int N, int M, int curr, int st){
    if (curr == M){
        for (int i=0; i<M; i++){
            printf("%d ", ans[i]);
        }
        printf("\n");
        return;
    }
    for (int i=st; i<= N; i++){
        if (vis[i] == 0){
            vis[i] = 1;
            ans[curr] = i;
            backtracking(N, M, curr+1, i+1);
            vis[i] = 0;
        }
    }
}

int main(){
    int N, M;
    scanf("%d %d", &N, &M);
    backtracking(N, M, 0, 1); 
    return 0;
}