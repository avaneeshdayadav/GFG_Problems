// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//Complete this function

class Solution
{
    public:
    //Function to find the minimum number of coins to make the change 
    //for value using the coins of given denominations.
    
    long long minimumNumberOfCoins(int coins[],int numberOfCoins,int value)
    {
        // your code here
        vector<vector<int>> memo(numberOfCoins, vector<int> (value + 1,-1));
        int ans = helper(coins, 0, value, memo, numberOfCoins);
        
        if(ans >= 1e9)
            return -1;
        return ans;
    }
    
    int helper(int num[], int index, int target, vector<vector<int>> &memo, int n)
    {
        if(target < 0)
            return 1e9;
        
        if(target == 0)
            return 0;
        
        if(index >= n)
            return 1e9;
        
        if(memo[index][target] != -1)
            return memo[index][target];
        
        int take = 1 + helper(num, index, target - num[index], memo, n);
        int notTake = helper(num, index + 1, target, memo, n);
        
        memo[index][target] = min(take, notTake);
        return memo[index][target];
    }
};

// { Driver Code Starts.



int main() {
	
	//taking total count of testcases
	int testcases;
	cin>>testcases;
	while(testcases--)
	{
	    //taking value
	    int value;
	    cin>>value;
	    
	    //taking number of coins
	    int numberOfCoins;
	    cin>>numberOfCoins;
	    int coins[numberOfCoins];
	    
	    //taking value of each coin
	    for(int i=0;i<numberOfCoins;i++)
	    cin>>coins[i];
	    Solution obj;
	    //calling function minimumNumberOfCoins()
	    int answer=obj.minimumNumberOfCoins(coins,numberOfCoins,value);
	    
	    //printing "Not Possible" if answer is -1
	    //else printing answer
	    if(answer==-1)
	    cout<<"Not Possible"<<endl;
	    else
	    cout<<answer<<endl;
	    
	}
	return 0;
}  // } Driver Code Ends
