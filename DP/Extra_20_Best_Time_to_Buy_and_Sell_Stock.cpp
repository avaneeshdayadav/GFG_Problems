#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    // Write your code here.
    int profit = 0, mini = prices[0];
    
    for(int i=1;i<prices.size();i++)
    {
        mini = min(prices[i],mini);
        profit = max(profit, prices[i]-mini);
    }
    
    return profit;
}
