class Solution {
public:
    void fun(vector<int>& nums, int index, vector<int>ds, set<vector<int>>& res) {
        if(index == nums.size()) {
            res.insert(ds);
            return;
        }
        ds.push_back(nums[index]);
        fun(nums, index+1, ds, res);
        ds.pop_back();
        fun(nums, index+1, ds, res);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        set<vector<int>> res;
        vector<int> ds;
        fun(nums, 0, ds, res);
        for(auto it = res.begin(); it!= res.end(); it++) {
            ans.push_back(*it);
        }  
        return ans;
    }
};