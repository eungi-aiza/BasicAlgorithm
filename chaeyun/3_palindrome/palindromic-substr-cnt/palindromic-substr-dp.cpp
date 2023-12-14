class Solution {
public:
    int countSubstrings(string s) {
        int c=0,n=s.size();
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int diff=0;diff<n;diff++)
        {
            for(int i=0,j=i+diff; j<n; i++,j++)
            {
                if(diff==0)
                    dp[i][j]=1;
                 else if(diff==1)
                   {
                       dp[i][j]=(s[i]==s[j])?2:0;
                   }    
                else 
                {
                    if(s[i]==s[j] && dp[i+1][j-1])
                        dp[i][j]=dp[i+1][j-1]+2;

                }
                if(dp[i][j])
                    c++;
            }
        }
        return c;
    }
};