#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

string s;
vector<string> v;
int isused[100];

void str_perm(int cur, string ss){
    if (cur == s.length()){
        v.push_back(ss);
        return;
    }
    for (int i=0; i<s.length(); i++){
        if (!isused[i]){
            ss[cur] = s[i];
            isused[i] = 1;
            str_perm(cur+1, ss);
            isused[i] = 0;
        }
    }
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    str_perm(0, s);
	set<string> s;

	for (string x : v) {
		s.insert(x);
	}

	for (string x : s) {
		cout << x << '\n';
	}    

}