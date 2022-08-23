// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template in C++


class Solution
{
    public:
    //Function to check whether a set of numbers can be partitioned into 
    //two subsets such that the sum of elements in both subsets is same.
    bool findPartition(int nums[], int n)
    {
        int sum = 0;
        
        for(int i=0;i<n;i++)
            sum += nums[i];

        
        if(sum % 2 != 0)
            return false;
        
        int target = sum / 2;
        vector<vector<int>> memo(n,vector<int>(target+1,-1));
        
        // cout<<target<<endl;
        return helper(nums, n, target, 0, memo);
    }
    
    bool helper(int arr[], int n, int target, int indx, vector<vector<int>> &memo)
    {
        if(target < 0 || indx >= n)
            return false;
        
        if(target == 0)
        {
            // cout<<indx<<endl;
            return true;
        }
            
        
        if(memo[indx][target] != -1)
            return memo[indx][target];
        
        memo[indx][target] = helper(arr, n, target-arr[indx], indx+1, memo) || helper(arr, n, target, indx+1, memo);
        return memo[indx][target];
    }
};

// { Driver Code Starts.
int main() {
    
    //taking total testcases
    int tc;
    cin >> tc;
    while (tc--) {
        
        //taking size of array
        int n, i;
        cin >> n;
        int a[n];
        
        //inserting elements in the array
        for (i = 0; i < n; i++) cin >> a[i];
        Solution ob;
        //calling findPartition() function and
        //printing "YES", if it returns true
        //else "NO"
        if (ob.findPartition(a, n))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
  // } Driver Code Ends
