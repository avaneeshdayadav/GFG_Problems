// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        // Your code here
        
        int maxSum = arr[0];
        
        int tempSum = arr[0];
        
        for(int i=1;i<n;i++)
        {
            if(tempSum + arr[i] < 0)
            {
                tempSum = arr[i];
            }
            else
            {
                tempSum = max(arr[i], tempSum+arr[i]);
            }
            maxSum = max(maxSum, tempSum);
        }
        
        // cout<<tempSum<<endl;
        return max(maxSum, tempSum);
    }
};

// { Driver Code Starts.

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
            
        Solution ob;
        
        cout << ob.maxSubarraySum(a, n) << endl;
    }
}
  // } Driver Code Ends
