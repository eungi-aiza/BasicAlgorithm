#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <unordered_map>
#include <string>
using namespace std;


void backtrack(vector<int>& nums, int start, vector<vector<int>>& result){
    if (start == nums.size() - 1){
        result.push_back(nums);
    }
    for (int i=start; i<nums.size(); i++){
        int temp = nums[start];
        nums[start] = nums[i];
        nums[i] = temp;
        backtrack(nums, start+1, result);
        int temp2 = nums[start];
        nums[start] = nums[i];
        nums[i] = temp2;        
    }

}

vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> result;
    backtrack(nums, 0, result);
    return result;    
}

int main() {
    vector<int> input = {1, 2, 3};
    vector<vector<int>> output = permute(input);

    for (auto a : output) {
        for (auto b : a) {
            cout << b << " ";
        }
        cout << endl;
    }

    return 0;
}