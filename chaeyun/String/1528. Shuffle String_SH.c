/*1528. Shuffle String
Easy

You are given a string s and an integer array indices of the same length. The string s will be shuffled such that the character at the ith position moves to indices[i] in the shuffled string.

Return the shuffled string.

 

Example 1:


Input: s = "codeleet", indices = [4,5,6,7,0,2,1,3]
Output: "leetcode"
Explanation: As shown, "codeleet" becomes "leetcode" after shuffling.
Example 2:

Input: s = "abc", indices = [0,1,2]
Output: "abc"
Explanation: After shuffling, each character remains in its position.
 
*/

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        int n=s.size();
        string ans;
        priority_queue<pair<int,char>>maxh;
        for(int i=0;i<n;i++)
        {
            maxh.push({indices[i],s[i]});
        }
        while(maxh.size()!=0)
        {
            ans+=maxh.top().second;
            maxh.pop();
        }
        int k=ans.length();
        for(int i=0;i<k/2;i++)
        {
            swap(ans[i],ans[k-i-1]);
        }
        return ans;
    }
};