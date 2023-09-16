#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define X first
#define Y second

// 프림 알고리즘

int main(){
  int v, e; // 정점의 수, 간선의 수
  vector<pair<int, int>> adj[10005]; // 그래프의 간선 정보
  bool chk[10005]; // 정점의 최소신장드리 포함 여부
  int cnt = 0; // 현재 선택된 간선의 수

  // 간선 정보를 저장할 우선순위 큐. 비용 순으로 정렬되며, {비용, 정점1, 정점2} 형태의 튜플을 저장
  priority_queue< tuple<int,int,int>, 
                  vector<tuple<int,int,int>>,
                  greater<tuple<int,int,int>> > pq; // minPQ
  
  // 입력 
  cin >> v >> e;
  for (int i = 0; i < e; i++) {
      int a, b, cost;
      cin >> a >> b >> cost;
      adj[a].push_back(make_pair(cost, b));
      adj[b].push_back(make_pair(cost, a)); // 무방향 그래프이므로 양쪽 간선 추가
      // adj[a].emplace_back(cost, b);
      // adj[b].emplace_back(cost, a); // 무방향 그래프이므로 양쪽 간선 추가
  }

  chk[1] = 1; // 시작 정점을 최소 신장 트리에 포함시킴
  for (auto nxt : adj[1]){ // 시작 정점과 연결된 간선들을 우선순위 큐에 추가
    pq.push({nxt.X, 1, nxt.Y}); // 비용, 정점1, 정점2를 큐에 추가
  }

  cout << "answer: " << '\n';
  while (cnt < v - 1){ // 최소 신장 트리에 정점이 v-1개 포함될 때까지 반복
    int cost, a, b;
    tie(cost, a, b) = pq.top(); // 우선순위 큐에서 최소 비용의 간선을 가져옴
    pq.pop();

    if (chk[b]) continue; // 이미 해당 정점이 최소 신장 트리에 포함되어 있다면 무시
    cout << cost << " " << a << " " << b << '\n'; // 선택된 간선 정보를 출력
    chk[b] = 1; // 해당 정점을 최소 신장 트리에 포함시킴
    cnt ++; // 선택된 간선의 수를 증가

    // 선택된 정점과 연결된 간선들 중에서 아직 최소 신장 트리에 포함되지 않은 정점들을 우선순위 큐에 추가
    for (auto nxt : adj[b]){
      if (!chk[nxt.Y]){
        pq.push({nxt.X, b, nxt.Y}); // 비용, 정점1, 정점2를 큐에 추가
      }
    }
  }

  return 0;
}
