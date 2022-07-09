// { Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        
        int left[n], right[n];
        long long sum = 0;
        
        left[0] = right[n-1] = 0;
        
        int leftMax = arr[0], rightMax = arr[n-1];
        
        for(int i=1;i<n;i++)
        {
            left[i] = max(arr[i-1], leftMax);
            leftMax = max(arr[i],leftMax);
        }
        
        for(int i=n-2;i>=0;i--)
        {
            right[i] = max(arr[i+1], rightMax);
            rightMax = max(arr[i],rightMax);
        }
        
        
        // for(int i=0;i<n;i++)
        //     cout<<left[i]<<" ";
        // cout<<endl;
        
        // for(int i=0;i<n;i++)
        //     cout<<right[i]<<" ";
        // cout<<endl;
        
        for(int i=1;i<n-1;i++)
        {
            int val = min(left[i],right[i]) - arr[i];
            if(val >=0)
                sum += val;
        }
        
        
        return sum;
        
    }
};

// { Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}  // } Driver Code Ends
