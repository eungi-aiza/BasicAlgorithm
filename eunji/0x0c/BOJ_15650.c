#include <stdio.h>
#include <stdlib.h>

void backtracking(
  int start,
  int* isused,
  int* arr,
  int N,
  int M,
  int curr
){
  isused[start] = 1;
  arr[curr] = start;
  if (curr == M){
    for (int i=1; i<=M; i++){
      printf("%d ", arr[i]);
    }
    printf("\n");
    return;
  }

  for (int i=start+1; i<=N; i++){
    if (!isused[i]){
      backtracking(i, isused, arr, N, M, curr+1);
      isused[i] = 0;
    }
  }

}

int main(){
  int N;
  int M;
  scanf("%d", &N);
  scanf("%d", &M);
  int isused[9] = {};
  int arr[9] = {};

  for (int i=1; i<=N; i++){
    backtracking(i, isused, arr, N, M, 1);
  }


  return 0;
}