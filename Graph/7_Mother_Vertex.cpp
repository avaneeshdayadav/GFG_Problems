// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int V, vector<int>adj[])
	{
	    // Kosaraju concept.
	    // To keep track of last finished index after DFS call.
	    // If there exist mother vertex (or vertices), then one of the mother vertices is the last finished vertex in DFS.
	    int lastFinishedVertex;
	    vector<int> vis(V,0);
	    
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i])
	        {
	            DFS(adj,vis,i);
	            lastFinishedVertex = i;
	        }
	        
	    }
	    
	    // Reinitialize vis vector.
	    fill(vis.begin(),vis.end(),0);
	    
	    // Traverse DFS starting from last finished vertex.
	    DFS(adj,vis,lastFinishedVertex);

	    for(int i=0;i<V;i++)
	    {
	        // If any of the vertex was not reachable then return -1
	        if(vis[i] == 0)
	            return -1;
	    }
	    
	    // Else all the vertexes were reachable from this last finished vertex. So return it.
	    return lastFinishedVertex;
	}
	
	void DFS(vector<int> adj[], vector<int> &vis, int node)
	{
	    vis[node] = 1;
	    
	    for(auto it : adj[node])
	    {
	        if(!vis[it])
	            DFS(adj,vis,it);
	    }
	}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
