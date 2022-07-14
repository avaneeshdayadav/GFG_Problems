#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
// Problem Link : https://practice.geeksforgeeks.org/problems/possible-paths-between-2-vertices-1587115620/0/?track=amazon-graphs&batchId=192#
  public:
    // Function to count paths between two vertices in a directed graph.
    int countPaths(int V, vector<int> adj[], int src, int dst) {

        int pathCnt = 0;
        vector<bool> vis(V, false);
        helper(adj, src, dst, pathCnt, vis);
        return pathCnt;
    }
    
    void helper(vector<int> adj[], int src, int dst, int &pathCnt, vector<bool> vis)
    {
        vis[src] = true;
        if(src == dst)
            pathCnt++;
        else
        {
            for(auto it : adj[src])
                if(!vis[it])
                    helper(adj,it,dst,pathCnt,vis);
        }
        
        vis[src] = 0;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // adj[v].push_back(u);
        }
        int source, destination;
        cin >> source >> destination;
        Solution obj;
        cout << obj.countPaths(V, adj, source, destination) << endl;
    }
    return 0;
}  // } Driver Code Ends
