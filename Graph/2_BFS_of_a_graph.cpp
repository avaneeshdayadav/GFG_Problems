// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        
        vector<int> vis(V,0), ans;
        queue<int> q;
        q.push(0);
        
        // Conceptually wrong approach.
        
            // while(!q.empty())
            // {
            //     int t = q.front();
            //     q.pop();
                
            //     if(visited[t] == false)
            //     {
            //         ans.push_back(t);
            //         visited[t] = true;
            //         for(auto it:adj[t])
            //             q.push(it);
            //     }
                    
            // }
            
        
        // Right approach.
            vis[0] = 1;
            ans.push_back(0);
            
            while(!q.empty())
            {
                int front = q.front();
                q.pop();
                
                for(int i=0;i<adj[front].size();i++)
                {
                    if(vis[adj[front][i]] == 0)
                    {
                        vis[adj[front][i]] = 1;
                        ans.push_back(adj[front][i]);
                        q.push(adj[front][i]);
                    }
                }
            }
            
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
