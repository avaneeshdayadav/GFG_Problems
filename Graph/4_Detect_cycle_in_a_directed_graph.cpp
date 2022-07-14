#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        
        vector<int> vis(V,0);
        vector<int> reccStack(V,0);
        
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
                if(dfs(adj,vis,reccStack,i))
                    return true;
        }
        
        return false;
    }
    
    bool dfs(vector<int> adj[], vector<int> &vis, vector<int> &reccStack, int node)
    {
        vis[node] = 1;
        reccStack[node] = 1;
        for(int i=0;i<adj[node].size();i++)
        {
            if(!vis[adj[node][i]])
            {
                if(dfs(adj,vis,reccStack,adj[node][i]))
                    return true;
            }
            else if(reccStack[adj[node][i]]==1)
                return true;
        }
    
        reccStack[node] = 0;
        return false;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}
  // } Driver Code Ends
