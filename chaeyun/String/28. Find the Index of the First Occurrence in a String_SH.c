/*28. Find the Index of the First Occurrence in a String
Easy

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 

Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.
Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.
*/

// 풀이 1
int strStr(char * haystack, char * needle){
    char *occurence = strstr(haystack, needle);
    if (occurence) return occurence - haystack;
    else return -1;
}

// 풀이 2
int strStr(char * haystack, char * needle){
    for(int l = 0, r = strlen(needle); r <= strlen(haystack); l++, r++){
        char temp = haystack[r];
        haystack[r] = '\0';
        if (strstr( haystack+l, needle )){
            return l;
        }
        haystack[r] = temp;
    }
    return -1;
}