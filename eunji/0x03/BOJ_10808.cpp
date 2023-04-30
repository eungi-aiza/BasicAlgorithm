#include <iostream>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    int alps[26] = {};
    for (auto c: s){
        // cout << c;
        // cout << ;
        alps[c-'a'] += 1;   
    }
    for (int i=0; i<26; i++){
        cout << alps[i] << " ";
    } 
    return 0;
}