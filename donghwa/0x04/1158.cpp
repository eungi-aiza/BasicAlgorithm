#include <bits/stdc++.h>
using namespace std;

const int MX = 5000;
int res[MX], prv[MX], nxt[MX], dat[MX];
int cursor = 0;

void move(int cnt){
    while (cnt != 0){
        cursor = nxt[cursor];
        cnt--;
    }
}
void dlt(){
    nxt[prv[cursor]] = nxt[cursor];
    prv[nxt[cursor]] = prv[cursor];
    cursor = nxt[cursor];
}


int main(void){
    fill(res, res+MX, -1);
    int N;
    cin >> N;

    for (int i=0; i<N; i++){
        dat[i] = i;
        if (i == 0){
            prv[i] = N-1;
            nxt[i] = i+1;
        } else if (i == N-1){
            prv[i] = N-2;
            nxt[i] = 0;
        } else {
            prv[i] = i-1;
            nxt[i] = i+1;
        }
    }
    int cnt;
    cin >> cnt;
    int idx = 0;
    int M = N;
    while (N != 0){
        move(cnt-1);
        res[idx] = cursor ;
        dlt();
        idx ++;
        N --;
    }
    idx = 0;
    cout << "<";
    while (res[idx] != -1){
        cout << res[idx]+1;
        if (idx != M-1) cout << ", ";
        idx++;
    }
    cout << ">";
}
