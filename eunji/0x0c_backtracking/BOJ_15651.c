#include <stdio.h>
#include <stdlib.h>

void backtracking(
  int start,
  int* arr,
  int curr,
  int N,
  int M){ 
    if (curr == M){
      for (int i=0; i<M; i++){
        printf("%d ", arr[i]);
      }
      printf("\n");
      return;
    }
    

    for (int i=1; i<=N; i++){  
      arr[curr] = i; 
      backtracking(i, arr, curr+1, N, M);
    }
}


int main(){
  int N;
  int M;
  scanf("%d %d", &N, &M);

  int arr[10] = {};

  for (int i=1; i<=N; i++){
    arr[0] = i;
    backtracking(i, arr, 1, N, M);
  }

  return 0;
}