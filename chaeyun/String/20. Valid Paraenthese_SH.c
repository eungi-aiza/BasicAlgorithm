/*20. Valid Parentheses
Easy

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:

Input: s = "()"
Output: true
Example 2:

Input: s = "()[]{}"
Output: true
Example 3:

Input: s = "(]"
Output: false
*/
/*The most obvious solution would be pushing every opening parentheses ( '(', '{', '[' ) 
into a stack which follows LIFO (Last In First Out) sequence. This will help us to check that the last open parentheses is followed 
by the matching closing parentheses ( ')', '}', ']' ).
*/
/*스택 쓰는 문제라 그런지 C 풀이가 없당*/

class Solution {
public:
    bool isValid(string s) {
        
        stack<char> stck;
        stck.push(' ');
        
        for(int i=0; i<s.size(); i++){
            if(s[i]=='(') stck.push(')');
            else if(s[i]=='[') stck.push(']');
            else if(s[i]=='{') stck.push('}');
            
            else if(stck.top()!=s[i]) return false;
            else stck.pop();
        }
        if(stck.size()>1){
            return false;
        }
        return true;
    }
};