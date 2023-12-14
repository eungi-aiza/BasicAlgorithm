#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> path;
        
        backtrack(nums, 0, path, result);
        
        return result;
    }
    
    void backtrack(std::vector<int>& nums, int start, std::vector<int>& path, std::vector<std::vector<int>>& result) {
        // Add the current path to the result
        result.push_back(path);
        
        // Iterate through the remaining elements in the vector
        for (int i = start; i < nums.size(); ++i) {
            // Include the current element in the subset
            path.push_back(nums[i]);
            // Recursively find subsets starting from the current element
            backtrack(nums, i + 1, path, result);
            // Remove the current element from the path to explore other options
            path.pop_back();
        }
    }
};


// class Solution {
// public:
//     // Recursive helper function to generate subsets of integers
//     void helper(vector<vector<int>>& ans, vector<int>& nums, int n, vector<int>& temp, int i) {
//         // Base case: if all elements have been considered
//         if (n == i) {
//             ans.push_back(temp);  // Add the current subset to the answer
//             return;
//         }
        
//         temp.push_back(nums[i]);   // Include the current element in the subset
//         helper(ans, nums, n, temp, i + 1);   // Recurse to include next element
//         temp.pop_back();            // Backtrack: remove the last added element
        
//         helper(ans, nums, n, temp, i + 1);   // Recurse to exclude the current element
//     }
    
//     // Main function to generate all subsets of given integers
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>> ans;   // To store the generated subsets
//         vector<int> temp;           // Temporary vector to build subsets
        
//         helper(ans, nums, nums.size(), temp, 0);  // Call the helper function
//         return ans;   // Return the generated subsets
//     }
// };