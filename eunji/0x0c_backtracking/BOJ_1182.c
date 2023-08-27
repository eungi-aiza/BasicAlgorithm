#include <stdio.h>
#include <stdlib.h>


void backtracking(
  int curr,
  int* input,
  int* isused,
  int* S_curr,
  int* ans,
  int N,
  int S
){
  (*S_curr) += input[curr];
  isused[curr] = 1;

  if ((*S_curr) == S){
    (*ans) ++;
  }

  for (int i=curr+1; i<N; i++){
    if (!isused[i]){
      backtracking(i, input, isused, S_curr, ans, N, S);
      isused[i] = 0;
      (*S_curr) -= input[i];
    }
  }

}

int main(){
  int N;
  int S;
  scanf("%d", &N);
  scanf("%d", &S);

  int isused[25] = {};
  int input[25] = {};
  for (int i=0; i<N; i++){
    int temp;
    scanf("%d", &temp);
    input[i] = temp;
  }

  int ans = 0;
  int S_curr = 0;
  for (int i=0; i<N; i++){
    backtracking(i, input, isused, &S_curr, &ans, N, S);
    isused[i] = 0;
    S_curr = 0;
  }
  printf("%d", ans);
  return 0;
}