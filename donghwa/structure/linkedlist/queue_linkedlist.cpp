#include <bits/stdc++.h>
#include <string>
#include "queue_linkedlist.h"

using namespace std;

// front()
// back()
// empty()
// size()
// push()
// pop()



int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    LinkedList ll;
    // ll.push(0);
    // cout << ll.front() << '\n';
    // cout << ll.back() << '\n';
    // cout << ll.size() << '\n';

    // q.push(1);
    // cout << "after push 1" << endl;
    // q.push(2);
    // cout << "after push" << endl;
    // cout << q.front() << endl;
    // cout << q.back() << endl;
    // cout << q.size() << endl;
    // cout << q.empty() << endl;
    // q.pop();

    // cout << q.size() << endl;
    // q.pop();
    // q.pop();
    // cout << q.size() << endl;
    // cout << q.empty() << endl;
    // q.pop();
    // q.push(3);
    // cout << q.empty() << endl;
    // cout << q.front() << endl;

    int total;
    cin >> total;
    while(total--){
        string cmd;
        cin >> cmd;
        if (cmd == "push"){
            int num;
            cin >> num;
            ll.push(num);
        } else if (cmd == "pop"){
            if (ll.empty()){
                cout << "-1\n";
            } else {
                cout << ll.front() << '\n';
                ll.pop();
            }
        } else if (cmd == "size"){
            cout << ll.size() << '\n';
        } else if (cmd == "empty"){
            cout << ll.empty() << '\n';
        } else if (cmd == "front"){
            if (ll.empty()) cout << "-1\n";
            else cout << ll.front() << '\n';
        } else if (cmd == "back"){
            if (ll.empty()) cout << "-1\n";
            else cout << ll.back() << '\n';
        } 
    }
}