#include <stdio.h>
#include <stdlib.h>

void backtracking(int curr, int target, int* iu1, int* iu2, int* iu3, int* ans){
  if (curr == target){
    (*ans) ++;
    return;
  }

  for (int i=0; i<target; i++){
    if (iu1[i] == 1 || iu2[curr+i] == 1 || iu3[curr-i+target-1] == 1){
      continue;
    }
    iu1[i] = 1;
    iu2[curr+i] = 1;
    iu3[curr-i+target-1] = 1;
    backtracking(curr+1, target, iu1, iu2, iu3, ans);
    iu1[i] = 0;
    iu2[curr+i] = 0;
    iu3[curr-i+target-1] = 0;
  }
}

int main(){
  int N;
  scanf("%d", &N);
  int ans = 0;
  int iu1[30] = {};
  int iu2[30] = {};
  int iu3[30] = {};
  backtracking(0, N, iu1, iu2, iu3, &ans);
  printf("%d", ans);
}