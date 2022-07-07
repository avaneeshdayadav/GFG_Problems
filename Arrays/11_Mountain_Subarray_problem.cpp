#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends

// Problem Link : https://practice.geeksforgeeks.org/problems/mountain-subarray-problem/0/?track=amazon-arrays&batchId=192
class Solution{
  public:
    vector<bool> processQueries(int arr[], int n, vector<pair<int, int>> &queries,
                                int q) {
        // code here
        vector<bool> ans;
        int left[n], right[n];
        preprocess(arr,n,left,right);
        
        
        for(int i=0;i<queries.size();i++)
        {
            if(right[queries[i].first] >= left[queries[i].second])
                ans.push_back(true);
            else
                ans.push_back(false);
        }
        return ans;
            
    }
    
    
    void preprocess(int arr[], int N, int left[], int right[])
    {
        left[0] = 0;
        int lastIncr = 0;
     
        for (int i = 1; i < N; i++)
        {
            // if current value is greater than previous,
            // update last increasing
            if (arr[i] > arr[i - 1])
                lastIncr = i;
            left[i] = lastIncr;
        }
     
        // Initialize last right index as that index only
        right[N - 1] = N - 1;
        int firstDecr = N - 1;
     
        for (int i = N - 2; i >= 0; i--)
        {
            // if current value is greater than next,
            // update first decreasing
            if (arr[i] > arr[i + 1])
                firstDecr = i;
            right[i] = firstDecr;
        }
    }
};

// { Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, i, q;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cin >> q;
        vector<pair<int, int>> queries(q);
        for (i = 0; i < q; i++) {
            cin >> queries[i].first >> queries[i].second;
        }
        Solution obj;
        auto v = obj.processQueries(a, n, queries, q);
        for (bool u : v) {
            cout << (u ? "Yes\n" : "No\n");
        }
    }
    return 0;
}  // } Driver Code Ends
