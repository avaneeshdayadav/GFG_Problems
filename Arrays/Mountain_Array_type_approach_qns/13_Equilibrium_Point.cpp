// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends
class Solution{
    public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long arr[], int n) {
    
        // O(n) time & O(n) space
        
            // int leftSum =0, rightSum = 0, left[n], right[n];
            
            // left[0] = right[n-1] = 0;
            
            // for(int i=1;i<n;i++)
            // {
            //     left[i] = leftSum + arr[i-1];
            //     leftSum += arr[i-1];
            // }
            
            
            // for(int i=n-2;i>=0;i--)
            // {
            //     right[i] = rightSum + arr[i+1];
            //     rightSum += arr[i+1];
            // }
            
            
            // for(int i = 0;i<n;i++)
            //     if(left[i] == right[i])
            //         return (i+1);
                    
            // return -1;
        
        
        // O(n) time and O(1) space soln.
        
            int tillNowSum = arr[0];
            int totalSum = 0;
            
            if(n == 1)
                return 1;
                
            for(int i=0;i<n;i++)
                totalSum += arr[i];
    
            
            for(int i=1;i<n-1;i++)
            {
                if(tillNowSum == totalSum - (tillNowSum+arr[i]))
                    return i+1;
                else
                {
                    tillNowSum += arr[i];
                }
            }
            
            return -1;
    }

};

// { Driver Code Starts.


int main() {

    long long t;
    
    //taking testcases
    cin >> t;

    while (t--) {
        long long n;
        
        //taking input n
        cin >> n;
        long long a[n];

        //adding elements to the array
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        Solution ob;

        //calling equilibriumPoint() function
        cout << ob.equilibriumPoint(a, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends
