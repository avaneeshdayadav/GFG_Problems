// { Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

 // } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    public:
    //Function to find the length of longest common subsequence in two strings.
    int lcs(int x, int y, string s1, string s2)
    {
        // your code here
        vector<vector<int> > dp(x + 1, vector<int>(y + 1));
        
        // Memoization call
        // return helper(s1,s2,x,y,dp);
        
        
        // Tabulation
        for(int i=0;i<=x;i++)
        {
            for(int j=0;j<=y;j++)
            {
                if(i == 0 || j == 0)
                    dp[i][j] = 0;
                else
                {
                    if(s1[i-1] == s2[j-1])
                        dp[i][j] = 1+dp[i-1][j-1];
                    else
                        dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[x][y];
    }
    
    int helper(string &X, string &Y, int m, int n, vector<vector<int> >& dp)
    {
        if (m == 0 || n == 0)
            return 0;
        if (X[m - 1] == Y[n - 1])
            return dp[m][n] = 1 + helper(X, Y, m - 1, n - 1, dp);
    
        if (dp[m][n] != -1) {
            return dp[m][n];
        }
        return dp[m][n] = max(helper(X, Y, m, n - 1, dp),helper(X, Y, m - 1, n, dp));
    }

};


// { Driver Code Starts.
int main()
{
    int t,n,k,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(x, y, s1, s2) << endl;
    }
    return 0;
}
  // } Driver Code Ends
