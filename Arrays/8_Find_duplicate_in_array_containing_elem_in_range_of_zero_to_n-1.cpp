#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(int numRay[], int arr_size) {
        // code here
        vector<int> ans;
        for (int i = 0; i < arr_size; i++)
            numRay[numRay[i] % arr_size] = numRay[numRay[i] % arr_size] + arr_size;


        // for(int i=0;i<arr_size;i++)
        //     cout<<numRay[i]<<" ";
        // cout<<endl;
        
        
        // cout << "The repeating elements are : " << endl;
        for (int i = 0; i < arr_size; i++)
            if (numRay[i] >= arr_size * 2)
                ans.push_back(i);
        
        if(ans.size() == 0)
            ans.push_back(-1);
        return ans;
    }
};


// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends
