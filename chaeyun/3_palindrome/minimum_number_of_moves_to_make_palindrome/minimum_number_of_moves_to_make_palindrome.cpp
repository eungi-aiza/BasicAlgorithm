/*2193. Minimum Number of Moves to Make Palindrome
Hard
889
68
Companies
You are given a string s consisting only of lowercase English letters.

In one move, you can select any two adjacent characters of s and swap them.

Return the minimum number of moves needed to make s a palindrome.

Note that the input will be generated such that s can always be converted to a palindrome.

 

Example 1:

Input: s = "aabb"
Output: 2
Explanation:
We can obtain two palindromes from s, "abba" and "baab". 
- We can obtain "abba" from s in 2 moves: "aabb" -> "abab" -> "abba".
- We can obtain "baab" from s in 2 moves: "aabb" -> "abab" -> "baab".
Thus, the minimum number of moves needed to make s a palindrome is 2.
Example 2:

Input: s = "letelt"
Output: 2
Explanation:
One of the palindromes we can obtain from s in 2 moves is "lettel".
One of the ways we can obtain it is "letelt" -> "letetl" -> "lettel".
Other palindromes such as "tleelt" can also be obtained in 2 moves.
It can be shown that it is not possible to obtain a palindrome in less than 2 moves.*/


class Solution {
public:
    int minMovesToMakePalindrome(string s) {
        int i = 0, j = s.length()-1,k,ans=0;
        while(i<j){
            if(s[i]==s[j]){
                i++;j--;
            }else{
                k = j;
                while(k>=i && s[k] != s[i]){
                    k--;
                }
                if(k==i){
                    ans++;
                    swap(s[i],s[i+1]);
                }else{
                    while(k<j){
                        swap(s[k],s[k+1]);
                        k++;
                        ans++;
                    }
                    i++;j--;
                }
            }
        }
        return ans;
    }
};