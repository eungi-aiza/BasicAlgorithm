#include <iostream>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int a, b, c;
    cin >> a >> b >> c;
    int max_, min_, mid;
    if (a < b) min_ = a, max_ = b;
    else if (b < a) min_= b, max_ = a;
    if (min_ > c) mid = min_, min_ = c;
    else if (max_ < c) mid = max_, max_ = c;
    else mid = c;
    cout << min_ << ' ' << mid <<  ' ' << max_;
    return 0;
}