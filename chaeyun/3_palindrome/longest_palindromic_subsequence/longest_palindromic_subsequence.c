int longestPalindromeSubseq(string s) {
        int i = 0, j = 0, n = s.size();
        if (n < 2) return n;
        vector<int> dp(n, 0), dp2(n, 0);

        for (i = n-1; i >= 0; --i)
        {
            dp[i] = 1;
            for (j = i + 1; j < n; ++j)
            {
                dp[j] = s[i] == s[j] ? dp2[j-1] + 2 : max(dp2[j], dp[j-1]);
            }
            dp2.swap(dp);
            dp.clear();
        }
        return dp2[n-1];
    }


    // Solution 2
        int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<int> v0(n), v1(n,1), v(n), *i_2=&v0, *i_1=&v1, *i_=&v;
        for(int i=2;i<=n;i++) {//length
            for(int j=0;j<n-i+1;j++)//start index
                i_->at(j) = s[j]==s[i+j-1]?2+i_2->at(j+1):max(i_1->at(j),i_1->at(j+1));
            swap(i_1,i_2);    
            swap(i_1,i_); //rotate i_2, i_1, i_
        }
        return i_1->at(0); 
    }