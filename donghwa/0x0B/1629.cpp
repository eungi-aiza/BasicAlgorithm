#include <bits/stdc++.h>
using namespace std;

using ll = long long;
// 절차적 사고를 버리고 귀납적 사고로 접근하기 = base case + k를 알면, 2k와 2k+1을 알 수 있다!

ll POW(ll a, ll b, ll m){
    if (b==1) return a%m;
    ll val = POW(a, b/2, m);
    val = val * val %m;
    if (b% 2 ==0) return val;
    return val * a%m;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll a,b,c;
    cin >> a >> b >> c;
    cout << POW(a, b,c);
}