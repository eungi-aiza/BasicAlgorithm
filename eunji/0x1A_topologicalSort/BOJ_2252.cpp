#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
  int N;
  int M;
  int deg[32002] = {};
  vector<int> adj[32002];
  queue<int> qq;
  vector<int> result;
  cin >> N >> M;
  for (int i=0; i<M; i++){
    int st;
    int ed;
    cin >> st >> ed;
    adj[st].push_back(ed);
    deg[ed] ++;
  }
  for (int i=1; i<=N; i++){
    if (deg[i] == 0) qq.push(i);
  }
  while (! qq.empty()){
    int curr = qq.front();
    qq.pop();
    result.push_back(curr);
    for (int i=0; i<adj[curr].size(); i++){
      int nei = adj[curr][i];
      deg[nei] --;
      if (deg[nei] == 0) qq.push(nei);
    }
  }
  for (int i=0; i<N; i++){
    cout << result[i] << " ";
  }

  return 0;
}