#include <iostream>
#include <map>
#include <vector>
using namespace std;
map<int, vector<int>> graph;
vector<bool> visited;

int main() {
    int N;
    int M;
    int R;
    map<int, vector<int>> graph;
    cin >> N >> M >> R;
    
    int u;
    int v;
    for (int i = 0; i < M; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
}