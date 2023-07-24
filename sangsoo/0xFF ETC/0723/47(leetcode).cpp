#include <vector>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> vv;
        vector<int> v;
        int n = nums.size();
        v.resize(n);
        int* isused = (int*)malloc(sizeof(int)*(n+1));
        memset(isused, 0, sizeof(int)*(n+1));
        backtrack(0, vv, v, isused, n, nums);
        sort(vv.begin(), vv.end());
        vv.erase(unique(vv.begin(), vv.end()), vv.end()); // list(set(arr))
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
    v.push_back(2);
    vv = sol.permuteUnique(v);
    for(auto v : vv){
        for (auto n : v){
            cout << n << " ";
        }
        cout << endl;
    }
}
