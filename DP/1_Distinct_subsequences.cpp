class Solution {
public:
    int numDistinct(string b, string s) {
        
        if(s.length() > b.length())
            return 0;
          
        int sLen = s.length();
        int bLen = b.length();
        
        vector<vector<int>> memo(bLen, vector<int> (sLen, -1));
        
        return helper(b, s, bLen-1, sLen-1, memo);
    }
    
  // Memoization.
    int helper(string &bigger, string &smaller, int i, int j, vector<vector<int>> &memo)
    {
        if(j < 0)
            return 1;
        
        if(i < 0)
            return 0;
        
        if(memo[i][j] != -1)
            return memo[i][j];
        
        
        // If curr char in smaller string matched then two choices, 1. Decrement both index or only decrement in bigger string. Else only one choice, decrement in bigger string.
        if(bigger[i] == smaller[j])
            memo[i][j] = helper(bigger, smaller, i-1, j-1, memo) + helper(bigger, smaller, i-1, j, memo);
        else
            memo[i][j] = helper(bigger, smaller, i-1, j, memo);
        
        return memo[i][j];
    }
};
