// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>> memo(n,vector<int>(W+1,-1));
       return helper(wt, val, 0, W, n, memo);
    }
    
    int helper(int wt[], int val[], int indx, int capLeft, int n, vector<vector<int>> &memo)
    {
        if(indx >= n || capLeft == 0)
            return 0;
        
        if(memo[indx][capLeft] != -1)
            return memo[indx][capLeft];
        
        
        // If i can take , try both take & not take possibility.
        int take, notTake;
        if(wt[indx] <= capLeft)
        {
            take = val[indx] + helper(wt,val,indx+1,capLeft-wt[indx],n, memo);
            notTake = helper(wt,val,indx+1,capLeft,n, memo);
            
            memo[indx][capLeft] = max(take, notTake);
            return memo[indx][capLeft];
        }
        
        // Else not take
        memo[indx][capLeft] = helper(wt,val,indx+1,capLeft,n,memo);
        return memo[indx][capLeft];
    }
};

// { Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}  // } Driver Code Ends
