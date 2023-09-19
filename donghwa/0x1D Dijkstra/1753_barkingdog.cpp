/*
방향그래프가 주어지면 주어진 시작점에서 다른 모든 정점으로의 최단 경로를 구하는 프로그램을 작성하시오. 단, 모든 간선의 가중치는 10 이하의 자연수이다.

- 입력 :
첫째 줄에 정점의 개수 V와 간선의 개수 E가 주어진다. (1 ≤ V ≤ 20,000, 1 ≤ E ≤ 300,000) 모든 정점에는 1부터 V까지 번호가 매겨져 있다고 가정한다. 둘째 줄에는 시작 정점의 번호 K(1 ≤ K ≤ V)가 주어진다. 셋째 줄부터 E개의 줄에 걸쳐 각 간선을 나타내는 세 개의 정수 (u, v, w)가 순서대로 주어진다. 이는 u에서 v로 가는 가중치 w인 간선이 존재한다는 뜻이다. u와 v는 서로 다르며 w는 10 이하의 자연수이다. 서로 다른 두 정점 사이에 여러 개의 간선이 존재할 수도 있음에 유의한다.
- 출력 :
첫째 줄부터 V개의 줄에 걸쳐, i번째 줄에 i번 정점으로의 최단 경로의 경로값을 출력한다. 시작점 자신은 0으로 출력하고, 경로가 존재하지 않는 경우에는 INF를 출력하면 된다.

ex1.
5 6
1
5 1 1
1 2 2
1 3 3
2 3 4
2 4 5
3 4 6

ex2. 
0
2
3
7
INF
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

#define X first
#define Y second

using namespace std;

int v, e, st;
// {비용, 정점 번호}
vector<pair<int, int>> adj[20005];
const int INF = 0x3f3f3f3f;
int d[20005]; // 최단 거리 테이블

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> v >> e >> st;
    fill(d, d+v+1, INF); 
    while(e--){
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({w, b}); 
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq; // 최소힙
    d[st] = 0; // 시작지점 거리 0
    pq.push({d[st], st}); // 우선순위 큐에 (0, 시작지점)추가 
    while(!pq.empty()){
        auto cur = pq.top(); pq.pop(); // {비용, 정점 번호}
        // 거리가 d에 있는 값과 다를 경우 넘어감 -> 최소가 아니라는 뜻
        if(d[cur.Y] != cur.X) continue;
        for(auto nxt: adj[cur.Y]){
            if(d[nxt.Y] <= d[cur.Y] + nxt.X) continue;
            // cur를 거쳐가는 것이 더 작은 값을 가질 경우
            // d[nxt.Y]을 갱신하고 우선순위 큐에 (거리, nxt.Y)를 추가
            d[nxt.Y] = d[cur.Y] + nxt.X;
            pq.push({d[nxt.Y], nxt.Y});
        }
    }
    for(int i = 1; i <= v; i++){
        if(d[i] == INF) cout << "INF\n";
        else cout << d[i] << '\n';
    }
}