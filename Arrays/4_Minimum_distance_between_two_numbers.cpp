#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
  public:
    int minDist(int arr[], int n, int x, int y) {
        // code here
        
        int o = -1,t = -1, dist = INT_MAX;
        
        for(int i=0;i<n;i++)
        {
            if(arr[i] == x)
            {
                o = i;
                if(t != -1)
                    dist = min(dist,abs(o - t));
            }
            
            if(arr[i] == y)
            {
                t = i;
                if(o != -1)
                    dist = min(dist,abs(o - t));
            }
        }
        
        if(dist == INT_MAX)
        return -1;
        return dist;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int x, y;
        cin >> x >> y;
        Solution obj;
        cout << obj.minDist(a, n, x, y) << endl;
    }
    return 0;
}
  // } Driver Code Ends
