#include <stdio.h>
#include <stdlib.h>

void backtracking(
  int curr, 
  int* arr,
  int N,
  int M
){
  if (curr == M){
    for (int i=0; i<M; i++){
      printf("%d ", arr[i]);
    }
    printf("\n");
    return;
  }

  for (int i=1; i<=N; i++){
    if (curr!=0){
      if (arr[curr-1] > i){
      continue;
      }
    }
    arr[curr] = i;
    backtracking(curr+1, arr, N, M);
  }

}

int main(){
  int N;
  int M;
  scanf("%d %d", &N, &M);
  int arr[10] = {};
  backtracking(0, arr, N, M);
}