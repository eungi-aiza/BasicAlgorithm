/*
leetcode problem - permutation 1
https://leetcode.com/problems/permutations/

when given array of nums, return all the possible permutations in any order
(identical permuation allowed)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        permuteRecur(nums, 0, result);
        return result;
    }

private:
    void permuteRecur(vector<int>& num, int start, vector<vector<int>>& result) {
        // if num has only one element or almost the end of the iteration
        if (start == num.size() - 1) {
            result.push_back(num);
            return;
        }
        for (int i = start; i < num.size(); i++) {
            swap(num[start], num[i]);
            permuteRecur(num, start + 1, result);
            swap(num[start], num[i]);
        }
    }
};