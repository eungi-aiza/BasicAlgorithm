// leetcode : https://leetcode.com/problems/pascals-triangle/
// boj : https://www.acmicpc.net/problem/16395

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 재귀로 푸니까 돌아는 가는데 leetcode boj 모두 timeout 뜸

int combination(int n, int r){
    if(n == r || r == 0) 
        return 1; 
    else 
        return combination(n - 1, r - 1) + combination(n - 1, r);
}

vector<vector <int>> getPascal(int &n)
{    
    vector<vector<int>> v(n);  
    int cb;
    for (int i=0; i < n; i++){
        // Initialize the vector at index i with size i+1
        v[i].resize(i+1);
        for(int j=0; j < i+1; j++){
            cb = combination(i, j);
            v[i][j] = cb;
        }
    }
    return v;
}

void printPascal(vector<vector <int>> &p){
    for (int k = 0; k < p.size(); k++) {
        for (int l = 0; l < k+1; l++) {
            cout << p[k][l] << " ";
        }
        cout << endl;
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int numRow;
    cin >> numRow;
    vector<vector <int>> pascal;
    
    pascal = getPascal(numRow);
    printPascal(pascal);

    return 0;
} 
