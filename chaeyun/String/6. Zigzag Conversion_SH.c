/*6. Zigzag Conversion
Medium

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:

string convert(string s, int numRows);
 

Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"
Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I
Example 3:

Input: s = "A", numRows = 1
Output: "A"
*/


char * convert(char * s, int numRows){
    if (numRows==1) return s;
    size_t n = strlen(s);
    char * out = malloc((n+1)*sizeof(char));
    size_t i = 0;// Index being written on out;
    
    // First row;
    for (size_t j = 0 ; j<n ; j+= 2*numRows-2) {
        out[i++] = s[j];
    }

    // Middle rows
    for (size_t row_number = 1 ; row_number<numRows-1 ; row_number++) {
        for (size_t j = row_number ; j<n ; ) {
            out[i++] = s[j];    // j "going down"
            j += 2*(numRows - 1 - row_number);
            // Find the next j "going up"
            if (j>=n) break;
            out[i++] = s[j];

            j+= 2*row_number;   // Find the next j "going down"
        }
    }

    // Last row;
    for (size_t j = numRows-1 ; j<n ; j+= 2*numRows-2) {
        out[i++] = s[j];
    }
    out[i]=0;
    return out;

}