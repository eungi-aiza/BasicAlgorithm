#include <iostream>
#include <list>
using namespace std;


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string sent; 
    cin >> sent;
    list<char> sent_linked;
    for (auto c : sent) sent_linked.push_back(c);
    auto curr = sent_linked.end();

    int order_num;
    cin >> order_num;    

    for (int i=0; i<order_num; i++){
        char ord;
        cin >> ord;
        if ((ord == 'L') && (curr != sent_linked.begin())){
            curr --;
        }
        else if ((ord == 'D') && (curr != sent_linked.end())){
            curr ++;
        }
        else if ((ord == 'B') && (curr != sent_linked.begin())){
            curr --;
            curr = sent_linked.erase(curr);
        }
        else if (ord == 'P'){
            char target;
            cin >> target;
            sent_linked.insert(curr, target);
        }
    }

    for (auto c : sent_linked) cout << c;    
}