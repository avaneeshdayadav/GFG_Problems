int helper(vector<int> &values, int n, int index, int buy, vector<vector<int>>  &memo)
{
    if(index >= n)
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
        int sell_It = values[index] + helper(values, n, index+2, !buy, memo);
        int dontSell = helper(values, n, index + 1, buy, memo);
        memo[index][buy] = max(sell_It, dontSell);
    }
    
    return memo[index][buy];
}


int stockProfit(vector<int> &prices){
    // Write your code here.
    
    int n = prices.size();
    vector<vector<int>> memo(n, vector<int> (2,-1));
    
    return helper(prices,n,0,1,memo);
    
}
