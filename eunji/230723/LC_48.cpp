#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <unordered_map>
#include <string>
using namespace std;

// constant vector<int>& nums = {1, 2, 3};

void backtrack(vector<int>& nums, int start, vector<vector<int>>& result){
    if (start == nums.size() - 1){
        if 
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

void nextPermutation(vector<int>& nums) {
        
    }

int main() {
    vector<int> input = {1, 2, 3};
    nextPermutation(input);

    for (auto a : input) {
        cout << a << " ";
    }

    return 0;
}