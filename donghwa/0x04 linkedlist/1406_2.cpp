#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
char dat[MX];
int prv[MX], nxt[MX];
int unused = 1;
int cursor = 0;

void traverse(){
    int cur = nxt[0];
    while (cur != -1){
        cout << dat[cur];
        cur = nxt[cur];
    }
    cout << "\n";
}


void move_left(){
    if (prv[cursor] != -1){
        cursor = prv[cursor];
    }
}

void move_right(){
    if (nxt[cursor] != -1){
        cursor = nxt[cursor];
    }
}

void delete_left(){
    if (prv[cursor] != -1){
        nxt[prv[cursor]] = nxt[cursor];
        if (nxt[cursor] != -1) prv[nxt[cursor]] = prv[cursor];
        cursor = prv[cursor];
    }
}

void insert_left(char c){
    dat[unused] = c;
    prv[unused] = cursor;
    nxt[unused] = nxt[cursor];

    if (nxt[cursor] != -1){
        prv[nxt[cursor]] = unused;
    }
    nxt[cursor] = unused;
    unused++;
    cursor = nxt[cursor];
}

int main(){
    fill(prv, prv+MX, -1);
    fill(nxt, nxt+MX, -1);
    
    string s;
    cin >> s;

    for (auto c : s){
        insert_left(c);
    }
    int num;
    cin >> num;
    while(num--){
        char cmd;
        cin >> cmd;
        if (cmd == 'L'){
            move_left();
        } else if (cmd == 'D'){
            move_right();
        } else if (cmd == 'B'){
            delete_left();
        } else if (cmd == 'P'){
            char add;
            cin >> add;
            insert_left(add);
        }
    }
    traverse();

}
