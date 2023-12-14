/*58. Length of Last Word
Easy

Given a string s consisting of words and spaces, return the length of the last word in the string.

A word is a maximal 
substring
 consisting of non-space characters only.

 

Example 1:

Input: s = "Hello World"
Output: 5
Explanation: The last word is "World" with length 5.
Example 2:

Input: s = "   fly me   to   the moon  "
Output: 4
Explanation: The last word is "moon" with length 4.
Example 3:

Input: s = "luffy is still joyboy"
Output: 6
Explanation: The last word is "joyboy" with length 6.
*/

int lengthOfLastWord(char * s){
    int lastSize = 0;
    int i = strlen(s) - 1;
    
    if (s[i] == ' ') {
        while (i >= 0 && s[i] == ' ') {
            i--;
        }
    }

    while (i >= 0) {
        if (s[i] == ' ') {
            break;
        }
        if ((s[i] >= 97 && s[i] <= 122) || (s[i] >= 65 && s[i] <= 90)) {
            lastSize++;
        }
        i--;
    }

    return lastSize;
}