/*344. Reverse String
Easy

Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.

 

Example 1:

Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]
*/

void reverseString(char* s, int sSize){
    char *b, *e, ch;
    b=s;
    e=s;
    for(int i=0;i<sSize-1;i++) e++;
    for(int i=0;i<sSize/2;i++){
        ch=*e;
        *e=*b;
        *b=ch;
        b++;
        e--;
    }
}

// 풀이 2
class Solution {
    public void reverseString(char[] s) {
        int n = s.length;
        int mid = n/2;
        
        int i=0;
        while(i<mid){
            char temp = s[i];
            s[i]  = s[n-1-i];
            s[n-1-i] = temp;
            i++;
        }
        
    }
}