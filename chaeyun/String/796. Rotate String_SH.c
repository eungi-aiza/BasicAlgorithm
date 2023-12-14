/*796. Rotate String
Easy

Given two strings s and goal, return true if and only if s can become goal after some number of shifts on s.

A shift on s consists of moving the leftmost character of s to the rightmost position.

For example, if s = "abcde", then it will be "bcdea" after one shift.
 

Example 1:

Input: s = "abcde", goal = "cdeab"
Output: true
Example 2:

Input: s = "abcde", goal = "abced"
Output: false
 
*/

bool rotateString(char * s, char * goal){
    char x[strlen(s)*2+1];
    strcpy(x,s);
    strcat(x,s);
    int y=strstr(x,goal);
    if(strlen(s)!=strlen(goal)|| (goal==s))
    return false;
    if(y)
    return true;
    else
    return false;
}