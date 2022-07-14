#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	   // DFS SOLN
	   // vector<int> vis(V,0);
	   // stack<int> st;
	    
	   // for(int i=0;i<V;i++)
	   // {
	   //     if(vis[i] == 0)
	   //         dfs(adj,vis,st,i);
	   // }
	    
	   // vector<int> ans;
	   // while(!st.empty())
	   // {
	   //     ans.push_back(st.top());
	   //     st.pop();
	   // }
	    
	   // return ans;
	   
	   // BFS SOLN
	   
	   vector<int> ans;
	   vector<int> inDeg(V,0);
	   queue<int> q;
	   
	   for(int i=0;i<V;i++)
	   {
	       for(int j=0;j<adj[i].size();j++)
	       {
	           inDeg[adj[i][j]]++;
	       }
	   }
	   
	   for(int i=0;i<inDeg.size();i++)
	   {
	       if(inDeg[i] == 0)
	       {
	           //cout<<i<<endl;
	           q.push(i);
	       }
	           
	   }
	   
	   //cout<<q.front()<<endl;
	   
	   while(!q.empty())
	   {
	       int front = q.front();
	       //cout<<"Node "<<front<<" was popped out"<<endl;
	       q.pop();
	       ans.push_back(front);
	       
	       for(int i=0;i<adj[front].size();i++)
	       {
	           inDeg[adj[front][i]]--;
	           if(inDeg[adj[front][i]] == 0)
	            q.push(adj[front][i]);
	       }
	   }
	   
	   return ans;
	}
	
// 	void dfs(vector<int> adj[], vector<int> &vis, stack<int> &st, int node)
// 	{
// 	    vis[node] = 1;
	    
// 	    for(auto i : adj[node])
// 	        if(vis[i] == 0)
// 	            dfs(adj,vis,st,i);
	    
// 	    st.push(node);
// 	}
};

// { Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  // } Driver Code Ends
