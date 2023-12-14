/*1318. Minimum Flips to Make a OR b Equal to c [Bitwise manipulation]
Medium

Given 3 positives numbers a, b and c. Return the minimum flips required in some bits of a and b to make ( a OR b == c ). (bitwise OR operation).
Flip operation consists of change any single bit 1 to 0 or change the bit 0 to 1 in their binary representation.

 

Example 1:



Input: a = 2, b = 6, c = 5
Output: 3
Explanation: After flips a = 1 , b = 4 , c = 5 such that (a OR b == c)

a 0010
b 0110
c 0101
1-th iteration
a >> 1 : 0001 &1
b >> 1 : 0011 &1 
c >> 1 : 0010 &1 
&1 : 비트가 1일 때만 1을 출력 


Example 2:

Input: a = 4, b = 2, c = 7
Output: 1
Example 3:

Input: a = 1, b = 2, c = 3
Output: 0
*/

// (seen bitwise) 0+1 is the same as 0|1. 
// The only difference is 1|1 (=1) vs. 1+1(=0b10), i.e. create a 0 and having overflow, affecting the bits to the left).
class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips = 0; // Counter to track the number of flips required
        for (int i = 0; i < 32; i++) {
            // Extract the i-th bit of a, b, and c
            int bitA = (a >> i) & 1;
            int bitB = (b >> i) & 1;
            int bitC = (c >> i) & 1;
            
            // Check if the i-th bit of (a OR b) is equal to the i-th bit of c
            if ((bitA | bitB) != bitC) {
                if (bitC == 1) {
                    flips++; // Flip required to make the i-th bit of (a OR b) equal to 1
                } else {
                    flips += (bitA == 1) + (bitB == 1); // Flips required to make both bits of a and b equal to 0
                }
            }
        }
        return flips;
    }
};

// 풀이 2: 자세한 설명
/*
 * 1318. Minimum Flips to Make a OR b Equal to c
 *
 * Given 3 positives numbers a, b and c. Return 
 * the minimum flips required in some bits of a 
 * and b to make ( a OR b == c ). (bitwise OR operation).
 * Flip operation consists of change any single bit 
 * 1 to 0 or change the bit 0 to 1 in their binary 
 * representation.
 *
 * 1 <= a <= 10^9
 * 1 <= b <= 10^9
 * 1 <= c <= 10^9
 */

int minFlips(int a, int b, int c){
    /*
     * Input:
     *  a, integer,
     *  b, integer,
     *  c, integer
     */
     
    int cnt = 0;
    
    for (; a | b | c; a >>= 1, b >>= 1, c >>= 1) {
        int bit_a = a & 0x01;
        int bit_b = b & 0x01;
        int bit_c = c & 0x01;
        
        /*
         * a b c
         * 1 1 0   <-- Special case, need to flip both a and b
         * 1 0 0
         * 0 1 0
         * 0 0 0
         * 0 0 1
         * 1 0 1
         * 0 1 1
         * 1 1 1
         */

        if (bit_a == 1 && bit_b == 1 && bit_c == 0) {
            cnt += 2;
        }
        else if ((bit_a | bit_b) != bit_c) {
            cnt++;
        }
    }
     
    /*
     * Output:
     *  Return the minimum flips required in some 
     *  bits of a and b to make ( a OR b == c )
     */
     
    return cnt;
}