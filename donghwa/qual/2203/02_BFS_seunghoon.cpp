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

vector<vector<GNode*>> level_partition(unordered_map<GNode*, vector<GNode*>>& G, GNode* start_) {
    
   vector<vector<GNode*>> result; // 1-1. 그럼 output은 level들의 vector가 될 것.
   queue<GNode*> q;     // 0. 탐색해야 할 GNode*의 list를 만들고
   start_->color = 'B'; // 0. 일단 만나면 색을 B로 바꾸자.
   q.push(start_);      // 0. 우선 먼저 함수에 주어진 것부터 queue에 넣고 탐색 시작
   
   while (!q.empty()){
       vector<GNode*> level; // 1. 우선 level이라는 GNode pointer들의 vector를 만들자.
       int levelSize = q.size(); // 1-2. levelsize는 몇개 탐색해야 하지
       
       for (int i=0 ; i<levelSize ; ++i){
           GNode* u = q.front();
           q.pop();
           level.push_back(u);
           for (GNode* v : G[u]){
               if (v->color == 'W'){
                   v->color = 'B';
									 //v->distance = u->distance+1;
									 //v->parent = u;
                   q.push(v); // 2. child를 append해주자. 
               }
           }
       }
       result.push_back(level);
   }
   return result;
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