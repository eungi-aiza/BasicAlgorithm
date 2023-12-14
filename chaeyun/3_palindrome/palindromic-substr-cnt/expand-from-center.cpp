/*
Initialize a count variable to keep track of the number of palindromic substrings.
Iterate through each character in the string.
For each character, consider it as the center of a potential palindrome and expand around it.
Expand around the center character by moving left and right pointers outward while the characters at the pointers are equal.
Increment the count for each valid palindrome found.
Repeat the expansion process for both odd-length and even-length palindromes.
Return the count of palindromic substrings.
*/

class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        int n = s.size();
        
        for (int i = 0; i < n; i++) {
            // Expand around center for odd-length palindromes
            int left = i;
            int right = i;
            while (left >= 0 && right < n && s[left] == s[right]) {
                count++;
                left--;
                right++;
            }
            
            // Expand around center for even-length palindromes
            left = i;
            right = i + 1;
            while (left >= 0 && right < n && s[left] == s[right]) {
                count++;
                left--;
                right++;
            }
        }
        
        return count;
    }
};


/* another code for expand from center
int countSubstrings(string s) {
	int n = size(s), cnt = n; // cnt = n, since each single letter is palindrome in itself.
	// For odd length palindromes
	for(int i = 1, l = 0, r = 2; i < n; i++, l = i - 1, r = i + 1)
		while(l >= 0 && r < n && s[l] == s[r]) l--, r++, cnt++;                    
	// For even length palindromes
	for(int i = 1, l = 0, r = 1; i < n; i++, l = i - 1, r = i)
		while(l >= 0 && r < n && s[l] == s[r]) l--, r++, cnt++;            
	return cnt;
}

*/