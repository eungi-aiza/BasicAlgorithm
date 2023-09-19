#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Graph {
    int V; // Number of vertices
    vector<vector<int>> adj; // Adjacency list

    void topologicalSortUtil(int v, vector<bool>& visited, stack<int>& st);

public:
    Graph(int V);
    void addEdge(int u, int v);
    void topologicalSort();
};

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int u, int v) {
    adj[u].push_back(v);
}

void Graph::topologicalSortUtil(int v, vector<bool>& visited, stack<int>& st) {
    visited[v] = true;

    for (const int& neighbor : adj[v]) {
        if (!visited[neighbor]) {
            topologicalSortUtil(neighbor, visited, st);
        }
    }

    st.push(v);
}

void Graph::topologicalSort() {
    vector<bool> visited(V, false);
    stack<int> st;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            topologicalSortUtil(i, visited, st);
        }
    }

    cout << "Topological Sort:" << endl;

    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }

    cout << endl;
}

int main() {
    int V = 6; // Number of vertices
    Graph g(V);

    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    g.topologicalSort();

    return 0;
}
