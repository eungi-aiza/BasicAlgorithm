#include <bits/stdc++.h>
#include <vector>
using namespace std;

/*
Given an array nums of distinct integers, return all the possible permutations. 
You can return the answer in any order.
ex. 
Input : nums = [1,2,3]
Output : [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
*/

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        permute_help(nums, path, res);
        return res;
    }

    void permute_help(vector<int>& nums, vector<int>& path, vector<vector<int>> & res){
        if (nums.size()==0){
            res.push_back(path);
            return;
        }
        for (int i=0; i<nums.size(); i++){
            vector<int> path_new(path);
            path_new.push_back(nums[i]);
            vector<int> nums_new(nums);
            nums_new.erase(nums_new.begin()+i);
            permute_help(nums_new, path_new, res);
        }
    };

};