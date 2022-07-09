// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;
// int maxArea(int A[], int len);

 // } Driver Code Ends
//User function template for C++

long long maxArea(long long arr[], int len)
{
    // Your code goes here
    
    int l = 0, r = len-1;
    long long maxArea = 0;
    while(l<r)
    {
        long long newArea = (r-l) * min(arr[l],arr[r]);
        
        maxArea = max(maxArea, newArea);
        
        if(arr[l] < arr[r])
            l++;
        else
            r--;
    }
    
    return maxArea;
}

// { Driver Code Starts.

// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cout<<maxArea(arr,n)<<endl;
    }
return 0;
}
  // } Driver Code Ends
