#include <iostream>
using namespace std;


void backtracking(
  int curr,
  int* input,
  int* isused,
  int S_curr,
  int* ans,
  int N,
  int S
){
  S_curr += input[curr];
  isused[curr] = 1;

  if (S_curr == S){
    (*ans) ++;
  }

  for (int i=curr+1; i<N; i++){
    if (!isused[i]){
      backtracking(i, input, isused, S_curr, ans, N, S);
      isused[i] = 0;
    }
  }

}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  int S;
  cin >> N >> S;

  int isused[21] = {};
  int input[21] = {};
  for (int i=0; i<N; i++){
    int temp;
    cin >> temp;
    input[i] = temp;
  }

  int ans = 0;
  for (int i=0; i<N; i++){
    backtracking(i, input, isused, 0, &ans, N, S);
    isused[i] = 0;
  }
  cout << ans;
  return 0;
}