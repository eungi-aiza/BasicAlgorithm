#include <iostream>
#include <string>
#include <math.h>

using namespace std;

// class Solution {
//     bool isPrime(int val){
//         if(val == 1 ) 
//             return false ;
//         if(val == 2)
//             return true ;
//         int limit = sqrt(val) ;
//         for(int i = 2; i <= limit; i++){
//             if(val % i == 0)
//                 return false ;
//         }
//         return true ;
//     }
// public:
//     int primePalindrome(int n) {
//         if(n >= 8  && n <= 11)
//             return 11 ;
//         for(int i = 1; i <= 1e5; i++){
//             string s = to_string(i) ;
//             string t(s.rbegin(), s.rend()) ;
//             int val = stoi(s + t.substr(1)) ;
//             if(val >= n && isPrime(val))
//                 return val ;
//         }
//         return -1 ;
//     }
// };


bool isprime(int n)
{
    if(n==1)
        return false;
    for(int i=2;i*i<=n;i++)
        if(n%i==0)
            return false;
    return true;
}
bool ispalindrom(int n)
{
    int n1=n;
    int n2=0;
    while(n1>0){
        int a=n1%10;
        n2=n2*10+a;
        n1/=10;
    }
    if(n2==n)
        return true;
    return false;
}
int smallestno(int n)
{
    if(ispalindrom(n))
        if(isprime(n))
            return n;
    return smallestno(n+1);
}

int primePalindrome(int n) {
    
    if (1e7 <= n && n <= 1e8)
        return 100030001;
    int a=smallestno(n);
    return a;
    
}