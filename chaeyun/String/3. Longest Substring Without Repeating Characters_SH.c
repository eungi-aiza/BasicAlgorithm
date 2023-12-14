/*3. Longest Substring Without Repeating Characters
Medium

Given a string s, find the length of the longest 
substring
 without repeating characters.

 

Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

int lengthOfLongestSubstring(char * s){
    int arr[128] = {0}, left = 0, max = 0;
    for(int right = 0; s[right] != '\0'; right++){
        if( arr[s[right]] != 0 && arr[s[right]] > left ){
            left = arr[s[right]];
        }
        arr[s[right]] = right + 1;
        if ( right - left + 1 > max ) max = right - left + 1;
    }
    return max;
}