#include <iostream>
using namespace std;


void backtracking(int curr, int* ans, int target, int* iu1, int* iu2, int* iu3){
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
    backtracking(curr+1, ans, target, iu1, iu2, iu3);
    iu1[i] = 0;
    iu2[curr+i] = 0;
    iu3[curr-i+target-1] = 0;
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  int isused1[30] = {};
  int isused2[30] = {};
  int isused3[30] = {};
  int ans = 0;
  backtracking(0, &ans, N, isused1, isused2, isused3);
  cout << ans;

}