#include <stdio.h>
#include <stdlib.h>


void backtracking(int curr, int* arr, int* isused, int M, int N){
  if (curr == M){
    for (int i=0; i<M; i++){
      printf("%d ", arr[i]);
    }
    printf("\n");
  }

  for (int i=1; i<=N; i++){
    if (!isused[i]){
      isused[i] = 1;
      arr[curr] = i;
      backtracking(curr+1, arr, isused, M, N);
      isused[i] = 0;
    }
  }

}

int main(){
  int N;
  int M;

  scanf("%d %d", &N, &M);

  int arr[9] = {};
  int isused[9] = {};

  backtracking(0, arr, isused, M, N);
   
}