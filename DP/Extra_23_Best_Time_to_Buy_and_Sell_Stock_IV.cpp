int maximumProfit(vector<int> &prices, int n, int k)
{
    // Space Optimized.
    vector<vector<int>> forw(2, vector<int> (k+1,0)), curr(2, vector<int> (k+1,0));
    
    for(int i=n-1;i>=0;i--)
    {
        for(int buy = 0; buy<2 ;buy++)
        {
            for(int tranc = k; tranc>0; tranc--)
            {
                if(buy)
                    curr[buy][tranc] = max(-prices[i] + forw[!buy][tranc], forw[buy][tranc]);
                else
                    curr[buy][tranc] = max(prices[i] + forw[!buy][tranc-1], forw[buy][tranc]);
            }
        }
        
        forw = curr;
    }
     
    return forw[1][k];
}
