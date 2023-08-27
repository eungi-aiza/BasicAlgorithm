#include <iostream>
using namespace std;

void backtracking(
  int curr,
  int* life,
  int* wth,
  int N,
  int* ans
){
  if (curr == N){
    int temp = 0;
    for (int i=0; i<N; i++){
      if (life[i] <= 0) temp ++;
    }
    if (temp > *ans) *ans = temp;
    return;
  }

  for (int i=0; i<N; i++){
    if (life[curr] < 0 || (i == N-1  && curr==N-1)){ 
      backtracking(curr+1, life, wth, N, ans);
    }
    else if (i != curr && life[i] > 0 && life[curr] > 0){
      life[curr] -= wth[i];
      life[i] -= wth[curr];
      backtracking(curr+1, life, wth, N, ans);
      life[curr] += wth[i];
      life[i] += wth[curr];
    }
  }
}


int main(){
  int N;
  cin >> N;

  int life[10] = {};
  int wth[10] = {};
  for (int i=0; i<N; i++){
    cin >> life[i] >> wth[i];
  }

  int ans = 0;
  backtracking(0, life, wth, N, &ans);
  cout << ans; 

  return 0;
}