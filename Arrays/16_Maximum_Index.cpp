// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int arr[], int n) 
    { 
        // Your code here
        
        vector<int> rightMaxElm(n), leftMinElm(n);
        
        // Update rightMaxElm array from right to left storing max elm to the right of elm including curr elm.
        rightMaxElm[n-1] = arr[n-1];
        for(int i=n-2;i>=0;i--)
        {
            if(rightMaxElm[i+1] > arr[i])
                rightMaxElm[i] = rightMaxElm[i+1];
            else
                rightMaxElm[i] = arr[i];
        }
        
        leftMinElm[0] = arr[0];
        for(int i=1;i<n;i++)
        {
            if(leftMinElm[i-1] < arr[i])
                leftMinElm[i] = leftMinElm[i-1];
            else
                leftMinElm[i] = arr[i];
        }
        
        int i = 0, j = 0;
        int maxIndxDiff = 0;
        
        while(j < n && i < n)
        {
            if(rightMaxElm[j] < leftMinElm[i])
            {
                i++;
            }
            else
            {
                maxIndxDiff = max(maxIndxDiff, j-i);
                j++;
            }
            
        }
        
        return maxIndxDiff;
    }
};

// { Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
}   // } Driver Code Ends
