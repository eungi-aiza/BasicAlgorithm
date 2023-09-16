#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <utility> // Include the utility header for pair
using namespace std;

#define X first
#define Y second

int main() {
  int V;
  int E;
  int chk[10005] = {0};
  vector<pair<int, int>> adj[10005]; // (wei, ed)
  priority_queue<tuple<int, int, int>, // (st, wei, ed)
                 vector<tuple<int, int, int>>,
                 greater<tuple<int, int, int>>> pq;
  int cnt = 0;

  cin >> V >> E;
  for (int i = 0; i < E; i++) {
    int st, ed, wei;
    cin >> st >> ed >> wei;
    adj[st].push_back(make_pair(wei, ed));
    adj[ed].push_back(make_pair(wei, st));
  }
  
  // 임의의 정점을 선택해 최소신장트리에 추가
  int start = 1;
  chk[start] = 1;
  // 추가된 정점과 다른 정점을 연결한 간선 확인
  for (int i = 0; i < adj[start].size(); i++) {
    int wei = adj[start][i].X;
    int nei = adj[start][i].Y;
    pq.push({wei, start, nei});
  }

  int answer = 0;
  while (cnt < V - 1) {
    // 최소신장트리에 포함된 정점과 포함되지 않은 정점을 연결한 간선 중
    // 비용이 가장 작은 것을 최소신장 트리에 추가
    int wei, st, ed;
    tie(wei, st, ed) = pq.top();
    pq.pop();
    if (chk[ed] == 1) continue;
    chk[ed] = 1;
    cnt++;
    answer += wei;
    // cout << st << '-' << wei << '-' << ed << " \n";

    // 새로 추가된 정점과 포함되지 않은 정점을 연결한 간선 확인
    for (int i = 0; i < adj[ed].size(); i++) {
      int w = adj[ed][i].X;
      int nei = adj[ed][i].Y;
      if (chk[nei] == 1) continue;
      pq.push({w, ed, nei});
    }

  }
  cout << answer;
  return 0;
}
