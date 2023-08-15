#include <stdio.h>
#include <stdlib.h>

void backtracking(
  int curr,
  int N,
  int* sth,
  int* wgth,
  int* ans
){
  if (curr == N){
    int temp = 0;
    for (int i=0; i<N; i++){
      if (sth[i] <= 0) temp ++;
    }
    if (temp > *ans) *ans = temp;
    return;
  }

  for (int i=0; i<N; i++){
    if ((sth[curr] <= 0) || (i==N-1 && curr==N-1)){ // 내구성이 0이하인 달걀 차례, 혹은 내구성 있는 마지막 달걀 차례인데 나머지 달걀의 내구성이 모두 0이하
      backtracking(curr+1, N, sth, wgth, ans);
    }
    else if (sth[curr] > 0 && i != curr && sth[i] > 0){
      sth[i] -= wgth[curr];
      sth[curr] -= wgth[i];
      backtracking(curr+1, N, sth, wgth, ans);
      sth[i] += wgth[curr];
      sth[curr] += wgth[i];
    }
  }

}


int main(){
  int N;
  scanf("%d", &N);
  int sth[10] = {};
  int wgth[10] = {};
  int* ans = (int*)malloc(sizeof(int));
  *ans = 0;
  for (int i=0; i<N; i++){
    scanf("%d %d", &sth[i], &wgth[i]);
  }
  backtracking(0, N, sth, wgth, ans);
  printf("%d", *ans);
  free(ans);

  return 0;
  
}