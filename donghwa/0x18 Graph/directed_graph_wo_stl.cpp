// STL 못 쓸 때 directed graph

#include <bits/stdc++.h>
using namespace std;

int main(){
    int edge[10][2];
    int deg[10]; // 각 노드의 outdegree, 즉 밖으로 연결된 edge의 개수
    int adj[10];
    int idx[10]; // adj[i]에서 새로운 노드를 추가할 때의 위치
    int v, e;
    cin >> v >> e;
    for (int i=0; i<e; i++){
        cin >> edge[i][0] >> edge[i][1];
        deg[edge[i][0]]++;
    }
    for (int i=1; i<=v; i++){
        adj[i] = new int[deg[i]];
    }
    for (int i=0; i<e; i++){
        int u = edge[i][0], v = edge[i][1];
        adj[u][idx[u]] = v;
        idx[u]++;
    }
}