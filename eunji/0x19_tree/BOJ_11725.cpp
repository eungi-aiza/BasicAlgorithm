#include <iostream>
#include <vector>
using namespace std;

void dfs(int curr, vector<int> arr[], int par[], int vis[]){ // int* N
    // for (auto nei: *arr[curr]){
    for (int i=0; i<arr[curr].size(); i++){
        int nei = arr[curr][i];
        if (vis[nei] != 1){
            vis[nei] = 1;
            par[nei] = curr;
            dfs(nei, arr, par, vis);
        }
    }
}

int main(){
    int N;
    cin >> N;
    vector<int> arr[100002];
    for (int i=0; i<N-1; i++){
        int n;
        int v;
        cin >> n >> v;
        arr[n].push_back(v);
        arr[v].push_back(n);
    }
    int par[100002];
    int vis[100002];
    dfs(1, arr, par, vis); // &N
    for (int i=2; i<=N; i++){
        cout << par[i] << '\n';
    }
    return 0;
}