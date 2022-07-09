// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums, int n) {
       
        //code here
        
        vector<long long int> ans(n);
        vector<long long int> leftProd(n), rightProd(n);
        leftProd[0] = rightProd[n-1] = 1;
        
        
        for(int i=1;i<n;i++)
        {
            leftProd[i] = leftProd[i-1]*nums[i-1];
            // cout<<nums[i]<<" ";
        }
        
        for(int i=n-2;i>=0;i--)
        {
            rightProd[i] = rightProd[i+1]*nums[i+1];
        }
        
        
        for(int i=0;i<n;i++)
        {
            ans[i] = leftProd[i]*rightProd[i];
        }
        
        return ans;
    }
};


// { Driver Code Starts.
int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}  // } Driver Code Ends
