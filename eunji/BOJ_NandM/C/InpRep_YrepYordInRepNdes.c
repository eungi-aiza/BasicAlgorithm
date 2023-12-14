#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// #define INF INT_MAX
// #define INF (0x3f3f3f3f)

int N, M;
int ans[10];
int input[10];

int ascending(const void *a, const void *b) {
    int num1 = *(int *)a;
    int num2 = *(int *)b;
    if (num1 < num2) return -1;
    if (num1 > num2) return 1;
    return 0;
}

void backtracking(int curr, int st){
    if (curr == M){
      for (int i=0; i<M; i++){
        printf("%d ", ans[i]);
      }
      printf("\n");
      return;
    }
    
    int prev = 0; // 중요
    for (int i=st; i<N; i++){
      if (input[i] == prev) continue;
      ans[curr] = input[i];
      prev = ans[curr]; // 중요
      backtracking(curr+1, i);
    }
}

int main(){
  scanf("%d %d", &N, &M);
  for (int i=0; i<N; i++){
    scanf("%d", &input[i]);
  }
  qsort(input, N, sizeof(int), ascending);
  backtracking(0, 0);

}