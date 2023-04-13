#include <iostream>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int a, b, c, prize;
    cin >> a >> b >> c;
    if ((a != b) && (b != c) && (a != c)){
        prize = max(max(a, b), c);
        prize = prize * 100;
        cout << prize;
    }
    else if (((a != b) && (b == c)) || ((a == b) && (b != c)) || ((a == c) && (c != b))){
        int same;
        if (b==c) same = b;
        else if (a==b || a==c) same = a;
        prize = 1000 + (same)*100;
        cout << prize;
    }
    else{
        prize = 10000 + (a*1000);
        cout << prize;
    }
}