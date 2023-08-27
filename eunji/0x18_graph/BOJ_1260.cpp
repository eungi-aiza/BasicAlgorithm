#include <iostream>
#include <vector>
#include <deque>
using namespace std;

void printGraph(int v, vector<int> graph[1002]){
    for (int i=1; i<=v; i++){
        printf("Adjacency list of vertex %d: ", i);
        for (auto e: graph[i]){
            cout << e << " ";
        }
        cout << "\n";
    }
}

void directedGraph(int e, vector<int> graph[1002]){
    for (int i=0; i<e; i++){
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
    }

}

void dfs(int st, vector<int> graph[1002], int* visited, int* arr, int* curr, int target){
    if (*curr == target){
        for (int i=0; i<target; i++){
            cout << arr[i] << " ";
        }
        return;
    }

    for (auto c : graph[st]){
        if (visited[c] != 1){
            visited[c] = 1;
            arr[*curr] = c;
            (*curr) ++;
            dfs(c, graph, visited, arr, curr, target);
        }
    }

}

void bfs(int st, vector<int> graph[1002], int* visited, int* arr, int* curr){
    deque<int> D;
    D.push_back(st);
    visited[st] = 1;
    (*curr) = 0;
    while (! D.empty()){
        int temp = D.front();
        arr[*curr] = temp;
        (*curr) ++;
        D.pop_front();
        for (auto c : graph[temp]){
            if (visited[c] == 0){
                visited[c] = 1;
                D.push_back(c);
            }
        }
    }
}



int main(){
    int v_num, e_num, v_st;
    cin >> v_num >> e_num >> v_st;

    vector<int> graph[1002];
    int visited[1002] = {};
    directedGraph(e_num, graph);

    int arr[1002] = {};
    visited[v_st] = 1;
    arr[0] = v_st;
    int curr = 1;
    dfs(v_st, graph, visited, arr, &curr, v_num);
    cout << "\n";

    arr[1002] = {};
    visited[1002] = {};
    curr = 0;
    bfs(v_st, graph, visited, arr, &curr, v_num);

    return 0;
}