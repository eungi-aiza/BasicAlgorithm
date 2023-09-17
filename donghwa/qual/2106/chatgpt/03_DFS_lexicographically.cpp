#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

class GNode {
public:
    std::string id;
    char color; // 'W', 'B'
    int d;
    int f;
    GNode* parent;

    GNode(std::string id, char color = 'W', int d = -1, int f = -1, GNode* p = nullptr)
        : id(id), color(color), d(d), f(f), parent(p) {}
};

void DFS(std::unordered_map<GNode*, std::vector<GNode*>>& G, GNode* u, GNode* v, std::vector<std::string>& path, std::vector<std::string>& result) {
    u->color = 'B';
    path.push_back(u->id);

    if (u == v) {
        if (result.empty() || std::lexicographical_compare(path.begin(), path.end(), result.begin(), result.end())) {
            result = path;
        }
    } else {
        for (GNode* neighbor : G[u]) {
            if (neighbor->color == 'W') {
                DFS(G, neighbor, v, path, result);
            }
        }
    }

    u->color = 'W';
    path.pop_back();
}


std::vector<std::string> LexSmallest(std::unordered_map<GNode*, std::vector<GNode*>>& G, GNode* u, GNode* v) {
    std::vector<std::string> result;
    std::vector<std::string> path;
    
    // Perform DFS from node u
    DFS(G, u, v, path, result);

    return result;
}


int main() {
    GNode *r = new GNode("r"), *s = new GNode("s"), *t = new GNode("t"), *u = new GNode("u");
    GNode *v = new GNode("v"), *w = new GNode("w"), *x = new GNode("x"), *y = new GNode("y");

    std::unordered_map<GNode*, std::vector<GNode*>> G;
    G[r] = {w, v};
    G[s] = {w, t, x};
    G[t] = {s, x, w};
    G[u] = {y};
    G[v] = {r};
    G[w] = {r, s, t};
    G[x] = {t, s};
    G[y] = {u};

    std::vector<std::string> smallestPath = LexSmallest(G, t, v);

    // Print the lexicographically smallest path
    for (const std::string& node : smallestPath) {
        std::cout << node << " ";
    }
    std::cout << std::endl;

    // Clean up memory
    delete r;
    delete s;
    delete t;
    delete u;
    delete v;
    delete w;
    delete x;
    delete y;

    return 0;
}
