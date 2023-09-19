#include <iostream>
#include <algorithm>
using namespace std;

int arr[100002];

int binarysearch(int x, int n){
    int st = 0; int en = n-1;
    while(st <= en){
        int mid = st + (en-st)/2;
        if(arr[mid] == x) return 1;
        else if (arr[mid] > x) en = mid-1;
        else st = mid + 1;
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    sort(arr, arr+n);
    cin >> m;
    for(int i = 0; i < m; i++){
        int x; cin >> x;
        cout << binarysearch(x, n) << '\n';
    }
}