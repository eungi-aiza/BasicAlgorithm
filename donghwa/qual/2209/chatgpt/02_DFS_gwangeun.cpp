#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

class GNode {
public:
    std::string id;
    
    GNode(std::string id) : id(id) {}
    
    std::string str() {
        return id;
    }
};

void dfs(std::unordered_map<GNode*, std::vector<GNode*>>& G, GNode* node, GNode* c, std::vector<std::string>& path, std::vector<std::vector<std::string>>& ret, std::unordered_map<GNode*, bool>& v) {
    if (node == c) {
        ret.push_back(path);
        return;
    }
    
    for (GNode* nn : G[node]) {
        if (!v[nn]) {
            v[nn] = true;
            path.push_back(nn->str());
            dfs(G, nn, c, path, ret, v);
            path.pop_back();
            v[nn] = false;
        }
    }
}

std::vector<std::vector<std::string>> paths(std::unordered_map<GNode*, std::vector<GNode*>>& G, GNode* a, GNode* c) {
    std::vector<std::vector<std::string>> ret;
    
    std::unordered_map<GNode*, bool> v;
    for (auto& entry : G) {
        v[entry.first] = false;
    }
    
    v[a] = true;
    
    std::vector<std::string> path;
    path.push_back(a->str());
    
    dfs(G, a, c, path, ret, v);
    
    return ret;
}


int main() {
    GNode *a = new GNode("a");
    GNode *b = new GNode("b");
    GNode *c = new GNode("c");
    GNode *d = new GNode("d");
    
    std::unordered_map<GNode*, std::vector<GNode*>> G;
    G[a] = {b, c};
    G[b] = {d};
    G[d] = {c};
    
    std::vector<std::vector<std::string>> allPaths = paths(G, a, c);
    
    std::cout << "All possible paths from a to c:" << std::endl;
    for (const std::vector<std::string>& path : allPaths) {
        for (const std::string& node : path) {
            std::cout << node << " -> ";
        }
        std::cout << "end" << std::endl;
    }
    
    delete a;
    delete b;
    delete c;
    
    return 0;
}
