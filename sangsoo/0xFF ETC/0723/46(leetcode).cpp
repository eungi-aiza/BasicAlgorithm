#include <vector>
#include <iostream>
#include <string.h>

/*
1. nested funcion 안된다.
2. vector resize 하는 것 알아야.. (python의 [0 for _ in range(n)] 같은것)
3. isused resize ... malloc
4. memset -> 초기화
5. class에서 다른 함수 불러올 수 있음.
*/

using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> vv;
        vector<int> v;
        int n = nums.size();
        v.resize(n); // v = [0 for _ in range(n)]
        int* isused = (int*)malloc(sizeof(int)*(n+1));  // isused = [0 for _ in range(n)]
        memset(isused, 0, sizeof(int)*(n+1)); // initialized..
        backtrack(0, vv, v, isused, n, nums);
        return vv;
    }
    void backtrack(int k, vector<vector<int>>& vv, vector<int>& v, int* isused, int n, vector<int>& nums){
        if (k == n){
            vv.push_back(v);
        }
        for(int i = 0; i < n; i++){
            if(!isused[i]){
                isused[i] = 1;
                v[k] = nums[i];
                backtrack(k+1, vv, v, isused, n, nums);
                isused[i] = 0;
            }
        }
    }
};

int main(){
    Solution sol;
    vector<int> v;
    vector<vector<int>> vv;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    vv = sol.permute(v);
    for(auto v : vv){
        for (auto n : v){
            cout << n << " ";
        }
        cout << endl;
    }
}
