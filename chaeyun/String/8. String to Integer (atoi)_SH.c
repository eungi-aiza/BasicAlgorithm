/*8. String to Integer (atoi)
Medium

Implement the myAtoi(string s) function, which converts a string to a 32-bit signed integer (similar to C/C++'s atoi function).

The algorithm for myAtoi(string s) is as follows:

Read in and ignore any leading whitespace.
Check if the next character (if not already at the end of the string) is '-' or '+'. Read this character in if it is either. This determines if the final result is negative or positive respectively. Assume the result is positive if neither is present.
Read in next the characters until the next non-digit character or the end of the input is reached. The rest of the string is ignored.
Convert these digits into an integer (i.e. "123" -> 123, "0032" -> 32). If no digits were read, then the integer is 0. Change the sign as necessary (from step 2).
If the integer is out of the 32-bit signed integer range [-231, 231 - 1], then clamp the integer so that it remains in the range. Specifically, integers less than -231 should be clamped to -231, and integers greater than 231 - 1 should be clamped to 231 - 1.
Return the integer as the final result.
Note:

Only the space character ' ' is considered a whitespace character.
Do not ignore any characters other than the leading whitespace or the rest of the string after the digits.
 

Example 1:

Input: s = "42"
Output: 42
Explanation: The underlined characters are what is read in, the caret is the current reader position.
Step 1: "42" (no characters read because there is no leading whitespace)
         ^
Step 2: "42" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "42" ("42" is read in)
           ^
The parsed integer is 42.
Since 42 is in the range [-231, 231 - 1], the final result is 42.
Example 2:

Input: s = "   -42"
Output: -42
Explanation:
Step 1: "   -42" (leading whitespace is read and ignored)
            ^
Step 2: "   -42" ('-' is read, so the result should be negative)
             ^
Step 3: "   -42" ("42" is read in)
               ^
The parsed integer is -42.
Since -42 is in the range [-231, 231 - 1], the final result is -42.
Example 3:

Input: s = "4193 with words"
Output: 4193
Explanation:
Step 1: "4193 with words" (no characters read because there is no leading whitespace)
         ^
Step 2: "4193 with words" (no characters read because there is neither a '-' nor '+')
         ^
Step 3: "4193 with words" ("4193" is read in; reading stops because the next character is a non-digit)
             ^
The parsed integer is 4193.
Since 4193 is in the range [-231, 231 - 1], the final result is 4193.
*/

// 풀이 1
int myAtoi(char * s){
    printf("%ld",strtol(s,NULL,10));
    if(strtol(s,NULL,10)>2147483647){
        return(2147483647);
    }
    else if(strtol(s,NULL,10)<=-2147483648){
        printf("Thiss is the case");
        return(-2147483648);
    }
    else{
        return(strtol(s,NULL,10));
    }
}

// 풀이 2
/*Approach
Skip space symbols \t \n \v \f \r and space itself
Determine sign if (*nptr == '-')
Making a number
while (*nptr >= '0' && *nptr <= '9' && num <= INT_MAX)
num = num * 10 + *nptr++ - '0';
Working with exclusions
    if (num > INT_MAX)
        return (INT_MAX);
    if (num < INT_MIN)
        return (INT_MIN);*/
int myAtoi(const char *nptr) {
	long long	num = 0;
	int		    sign = 1;

	while (*nptr == '\t' || *nptr == '\n' || *nptr == '\v'
		|| *nptr == '\f' || *nptr == '\r' || *nptr == ' ')
		nptr++;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9' && num <= INT_MAX)
		num = num * 10 + *nptr++ - '0';
	num *= sign;
    if (num > INT_MAX)
        return (INT_MAX);
    if (num < INT_MIN)
        return (INT_MIN);
    return (num);
}


// 풀이 3
int myAtoi(char * s){
    int i, sign, rangeFlag = false;
    long int n;
    for (i = 0; isspace(s[i]); i++) /* skip white space */
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-') /* skip sign */
        i++;
    for (n = 0; isdigit(s[i]); i++) {
    	n = 10 * n + (s[i] - '0');
    	if( (sign * n) < INT_MIN ) 
    		return INT_MIN;
    	if( (sign * n) > INT_MAX ) 
    		return INT_MAX;
    }
    return sign * n;
}