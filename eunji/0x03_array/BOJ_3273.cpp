#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    int arr[N];
    for (int i=0; i<N; i++){
        cin >> arr[i];
    }
    int X;
    cin >> X;

    sort(arr, arr+N);

    int ans = 0;
    int st = 0; int ed = N-1;
    while (st < ed){
        if (arr[st]+arr[ed] == X){
            ans ++;
            st ++;
            ed --;
        }
        else if (arr[st]+arr[ed] < X){
            st ++;
            // cout << st << ed << '2' << '\n';
        }
        else if (arr[st]+arr[ed] > X){
            ed --;
            // cout << st << ed << '3'<< '\n';
        }
    }
    cout << ans;

}