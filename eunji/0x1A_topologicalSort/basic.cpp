#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main(){
  vector<int> adj[10];
  int deg[10] = {};
  int n;

  queue<int> q;
  vector<int> result;

  // Cycle //
  n = 7;
  adj[1].push_back(2);
  adj[3].push_back(2);
  adj[3].push_back(4);
  adj[4].push_back(2);
  adj[4].push_back(5);
  adj[5].push_back(6);
  adj[7].push_back(5);
  //

  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < adj[i].size(); j++) {
      int neighbor = adj[i][j];
      deg[neighbor]++;
    }
  }

  for (int i=1; i<=n; i++){
    if (deg[i] == 0) q.push(i);
  }

  while (!q.empty()){
    int curr = q.front();
    q.pop();
    result.push_back(curr);
    for (int i=0; i<adj[curr].size(); i++){
      int neighbor = adj[curr][i];
      deg[neighbor] --;
      if (deg[neighbor] == 0) q.push(neighbor);
    }
  } 
  if (result.size() != n){
    cout << "cycle exists";
  }
  else{
    cout << "Topological Sorting Order: ";
    for (int i=0; i<n; i++){
      cout << result[i] << " ";
    }
  }
  return 0;
}