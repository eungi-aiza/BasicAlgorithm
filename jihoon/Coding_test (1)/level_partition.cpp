#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <string>
using namespace std;

class GNode {
public:
    string id;
    char color; // 'W', 'B'
    int distance;
    GNode* parent;

    GNode(string id, char color = 'W', int d = 0, GNode* p = nullptr)
        : id(id), color(color), distance(d), parent(p) {}
};

vector<vector<GNode*>> level_partition(unordered_map<GNode*, vector<GNode*>>& G, GNode* s) {
    // TO DO
    // The vector to store the results
    // result should contain a vector of GNodes in level order
    vector<vector<GNode*>> result;

    // Visited should be having N FALSES. But how...?
    unordered_map<GNode*, bool> visited;

    vector<GNode*> queue;

    vector<GNode*> level_queue;

    visited[s] = true;
    queue.push_back(s);
    
    while (!queue.empty()) {
        s = queue.front();
        queue.erase(queue.begin());
        vector<GNode*> s_vec;
        s_vec.push_back(s);
        result.push_back(s_vec);
        level_queue = G[s];
        for (auto adjacent : G[s]) {
            if (!visited[adjacent]) {
                visited[adjacent] = true;
                queue.push_back(adjacent);
            }
        }
    } 
}

int main() {
    GNode *r = new GNode("r"), *s = new GNode("s"), *t = new GNode("t"), 
          *u = new GNode("u"), *v = new GNode("v"), *w = new GNode("w"), 
          *x = new GNode("x"), *y = new GNode("y");

    unordered_map<GNode*, vector<GNode*>> G;
    G[r] = {s, v};
    G[s] = {r, w};
    G[t] = {w, x, u};
    G[u] = {t, x, y};
    G[v] = {r};
    G[w] = {s, t, x};
    G[x] = {w, t, u, y};
    G[y] = {x, u};

    auto result = level_partition(G, s);

    // Print the result
    // you should print : s / r w / v t x / u y
    for (auto& level : result) {
        for (auto node : level) {
            cout << node->id << " ";
        }
        cout << endl;
    }

    // Clean up memory
    delete r, s, t, u, v, w, x, y;

    return 0;
}
