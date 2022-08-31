#include<bits/stdc++.h>

// Memoization Function.
int helper(vector<int> &prices, int n, int index, int buy, int no_of_tranc, vector<vector<vector<int>>> &memo)
{
    if(index >= n)
        return 0;
    
    if(no_of_tranc == 0)
        return 0;
    
    if(memo[index][buy][no_of_tranc] != -1)
        return memo[index][buy][no_of_tranc];
    
    int profit = 0;
    
    if(buy)
    {
        int buyIt = -prices[index] + helper(prices, n, index+1, !buy, no_of_tranc, memo);
        int dontBuy = helper(prices, n, index+1, buy, no_of_tranc, memo);
        profit = max(buyIt, dontBuy);
    }
    else
    {
        int sell_it = prices[index] + helper(prices, n, index+1, !buy, no_of_tranc - 1, memo);
        int dontSell = helper(prices, n, index+1, buy, no_of_tranc, memo);
        profit = max(sell_it, dontSell);
    }
    
    memo[index][buy][no_of_tranc] = profit;
    return profit;
}

int maxProfit(vector<int>& prices, int n)
{
    // Memo for memoized method.
        // vector<vector<vector<int>>> memo(n, vector<vector<int>> (2, vector<int> (3,-1)));
    
    // Call to memoized method.
        // return helper(prices, n, 0, 1, 2, memo);
    
    
    // Tabulation.
//         vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (2, vector<int> (3)));
//         // Base case filling.
//         for(int i=n;i>=0;i--)
//         {
//             for(int buy = 0;buy<2;buy++)
//             {
//                 for(int tranc = 0;tranc < 3;tranc++)
//                 {
//                     if(tranc == 0 || i == n)
//                         dp[i][buy][tranc] = 0;
//                 }
//             }
//         }
    
//         // Dp filling.
//         for(int i=n-1; i >= 0; i--)
//         {
//             for(int buy = 0; buy < 2; buy++)
//             {
//                 for(int tranc = 2; tranc > 0; tranc--)
//                 {
//                     if(buy)
//                         dp[i][buy][tranc] = max(-prices[i]+dp[i+1][!buy][tranc], dp[i+1][buy][tranc]);
//                     else
//                         dp[i][buy][tranc] = max(prices[i]+dp[i+1][!buy][tranc-1], dp[i+1][buy][tranc]);
//                 }
//             }
//         }

//         return dp[0][1][2];
    
    
    // Space Optimized.
    vector<vector<int>> forw(2, vector<int> (3,0)), curr(2, vector<int> (3,0));
    
    for(int i=n-1;i>=0;i--)
    {
        for(int buy = 0; buy<2 ;buy++)
        {
            for(int tranc = 2; tranc>0; tranc--)
            {
                if(buy)
                    curr[buy][tranc] = max(-prices[i] + forw[!buy][tranc], forw[buy][tranc]);
                else
                    curr[buy][tranc] = max(prices[i] + forw[!buy][tranc-1], forw[buy][tranc]);
            }
        }
        
        forw = curr;
    }
     
    return forw[1][2];
}
