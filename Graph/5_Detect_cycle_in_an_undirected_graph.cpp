// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        
        vector<bool> visited(V, false);
     
        // Call For BFS Soln
            // for (int i = 0; i < V; i++)
            //     if (!visited[i] && isCyclicConntected(adj, i,V, visited))
            //         return true;
            // return false;
        
        
        
        for (int i = 0; i < V; i++)
            if (!visited[i] && dfs(adj, visited, i, -1))
                return true;
        return false;
    }
    
    
    // BFS Soln
        // bool isCyclicConntected(vector<int> adj[], int s, int V, vector<bool>& visited)
        // {
        //     vector<int> parent(V, -1);
         
        //     queue<int> q;
         
        //     visited[s] = true;
        //     q.push(s);
         
        //     while (!q.empty()) {
         
        //         int u = q.front();
        //         q.pop();
        //         for (auto v : adj[u]) {
        //             if (!visited[v]) {
        //                 visited[v] = true;
        //                 q.push(v);
        //                 parent[v] = u;
        //             }
        //             else if (parent[u] != v)
        //                 return true;
        //         }
        //     }
        //     return false;
        // }
        
        
        
    // DFS Soln
    bool dfs(vector<int> adj[], vector<bool> &vis, int currNode, int parent)
    {
        if(vis[currNode] == 0)
        {
            // cout<<"CurrNOde "<<currNode<<" is not visited so visiting now."<<endl;
            vis[currNode] = 1;
            
            for(int i=0; i<adj[currNode].size(); i++)
            {
                if(vis[adj[currNode][i]] == 1 && parent != adj[currNode][i])
                {
                    // cout<<"Cycle detected, as node "<<adj[currNode][i]<<" was visited and its not equal to parent "<<parent<<endl;
                    return true;
                }
                    
                if(vis[adj[currNode][i]] == 0)
                {
                    if(dfs(adj, vis, adj[currNode][i], currNode))
                    {
                        // cout<<"Cycle detected for node "<<adj[currNode][i]<<endl;
                        return true;
                    }
                }
                    
            }
        }
        
        // cout<<"No cycle was detected at node "<<currNode<<" having parent "<<parent<<endl;
        return false;
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
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}  // } Driver Code Ends
