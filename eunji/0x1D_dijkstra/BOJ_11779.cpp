#include <iostream>
#include <vector>
#include <utility>
using namespace std;

#define X first // ed
#define Y second // wei
#define INF (0x3f3f3f3f)

int main(){
    int N, M;
    cin >> N >> M;
    vector<pair<int,int>> adj[1002];
    vector<int> pass[1002];
    int dist[1002];
    int fix[1002] = {};
    for (int i=0; i<M; i++){
        int st, ed, wei;
        cin >> st >> ed >> wei;
        adj[st].push_back(make_pair(ed, wei));
    }

    int sce, dest;
    cin >> sce >> dest;
    fill(dist, dist+N+1, INF);

    dist[sce] = 0;
    while (1){
        int idx = -1;
        for (int i=1; i<=N; i++){
            if (fix[i] == 1) continue;
            if (idx == -1) idx = i;
            if (dist[idx] > dist[i]) idx = i;
        }
        if ((idx == -1) || (dist[idx] == INF)){
            for (int i=1; i<=N; i++){
                pass[i].push_back(i);
            }
            break;
        }
            
        fix[idx] = 1;

        for (int i=0; i<adj[idx].size(); i++){
            int nei = adj[idx][i].X;
            int cost = adj[idx][i].Y;
            if (dist[idx]+cost <= dist[nei]){
                dist[nei] = dist[idx]+cost;
                pass[nei] = pass[idx];
                pass[nei].push_back(idx);
            }
        }
    }

    cout << dist[dest] << '\n';
    cout << pass[dest].size() << '\n';
    for (int i=0; i<pass[dest].size(); i++){
        cout << pass[dest][i] << " ";
    }
    
}