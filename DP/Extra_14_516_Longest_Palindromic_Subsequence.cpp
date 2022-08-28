class Solution {
public:
    
    // Memoization
    int helper(string s1, string s2, int i, int j, vector<vector<int>> &memo)
    {
        if(i >= s1.length() || j >= s2.length())
            return 0;
        
        if(memo[i][j] != -1)
            return memo[i][j];
        
        if(s1[i] == s2[j])
            return 1 + helper(s1,s2,i+1,j+1,memo);
        
        memo[i][j] = max(helper(s1,s2,i+1,j,memo), helper(s1,s2,i,j+1,memo));
        return memo[i][j];
    }
    
    
    int longestPalindromeSubseq(string s) {
        
        string temp = s;
        reverse(s.begin(),s.end());
        
        // Same as longest common subsequence just s1, rev(s1) are two strings in which we need to find LCS.
        int n = s.length();
        vector<vector<int>> dp(n+1,vector<int> (n+1));
        
        // Tabulation
        for(int i=n-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(s[i] == temp[j])
                    dp[i][j] = 1 + dp[i+1][j+1];
                else
                    dp[i][j] = max(dp[i][j+1] , dp[i+1][j]);
            }
        }
        
        return dp[0][0];
        
    }
};
