

long helper(long values[], int n, int index, int buy, long memo[][2])
{
    if(index == n)
        return 0;
    
    if(memo[index][buy] != -1)
        return memo[index][buy];
    
    // If u have option of buying.
    if(buy == 1)
    {
        int buyIt = -values[index] + helper(values, n, index+1, !buy, memo);
        int dontBuy = helper(values, n, index+1, buy, memo); 
        memo[index][buy] = max(buyIt, dontBuy);
    }
    else
    {
        int sell_It = values[index] + helper(values, n, index+1, !buy, memo);
        int dontSell = helper(values, n, index + 1, buy, memo);
        memo[index][buy] = max(sell_It, dontSell);
    }
    
    return memo[index][buy];
}

long getMaximumProfit(long *prices, int n)
{
    
    // 0th index of both the array shows profit by selling & 1st index shows profit by buying.
    long *forw = new long[2];
    long *curr = new long[2];
    
    forw[0] = forw[1] = 0;
    
    for(int i=n-1;i>=0;i--)
    {
        long *ptr = forw;
        long profit = 0;
        for(int buy=0;buy<2;buy++)
        {
            if(buy)
                profit = max(-prices[i] + forw[!buy], forw[buy]);
            else
                profit = max(prices[i] + forw[!buy], forw[buy]);
            
            curr[buy] = profit;
        }
        
        forw = curr;
        curr = ptr;
    }
    
    return forw[1];
}
