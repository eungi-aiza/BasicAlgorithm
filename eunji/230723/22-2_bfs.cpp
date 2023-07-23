#include <iostream>
#include <vector>
#include <queue>
#include <deque>
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


vector<vector<GNode*>>  bfs(unordered_map<GNode*, vector<GNode*>>& G, GNode* s){
   vector<vector<GNode*>> ans;
//    vector<GNode*> temp;
   deque<GNode*> D;
   D.push_back({s});
   while (! D.empty()){
        GNode* curr;
        vector<GNode*> temp; // 
        curr = D.front();
        D.pop_front();
        // if (temp.empty()){
        //     ans.push_back(temp);
        //     temp = {};
        // }

        // ans.push_back(temp);

        for (GNode* v : G[curr]){
            if (v -> color == 'R') continue;
            v -> color = 'R';
            v -> distance = curr->distance + 1;
            D.push_back(curr);
            temp.push_back(curr);
        }

   }
   return ans;

}

vector<vector<GNode*>> level_partition(unordered_map<GNode*, vector<GNode*>>& G, GNode* s) {    
    // cout << G[s][0].color;
    return bfs(G, s);
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

    // cout << G[s].size();
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
    // delete r, s, t, u, v, w, x, y;

    return 0;
}