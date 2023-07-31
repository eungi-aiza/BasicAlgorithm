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
   /*  
   
    to do
   
   */
   vector<vector<GNode *>> res;
   queue<GNode *> Q;
   s->color = "B";
   Q.push(s);

   while (!Q.empty()){
    vector<GNode *> level;
    int intLevel = Q.size();

    for (int i=0; i<intLevel; i++){
        GNode * q = Q.front();
        Q.pop();
        level.push_back(q);

        for(GNode *v : G[u]){
            
        }



    }

    GNode * cNode = Q.front(); Q.pop();
    // vector<GNode *> tmp = {};
    // tmp.push_back(cNode);
    for (auto nn : G[cNode]){
        // if (Q.empty()){
        //     res.push_back(tmp);                
        // }
        Q.push(nn);
    }
   }
   
    return res;
      
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