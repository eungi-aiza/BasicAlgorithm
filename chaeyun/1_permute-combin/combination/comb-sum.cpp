class Solution {
public:
    void findAns(int index, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& helper) {
        if(index == arr.size()) {
            if(target == 0) ans.push_back(helper);
            return;
        }
        if(arr[index] <= target) {
            helper.push_back(arr[index]);
            findAns(index, target-arr[index], arr, ans, helper);
            helper.pop_back();
        }
        findAns(index+1, target, arr, ans, helper);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> helper;
        findAns(0, target, candidates, ans, helper);
        return ans;
    }
};